#include "GerenciadorArquivo.hpp"
#include "Aluno.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>
#include <filesystem>

std::vector<Aluno> GerenciadorArquivo::lerCSV(std::string caminho){
    std::vector<Aluno> alunos;

    std::ifstream arquivo(caminho);

    if(!arquivo.is_open()){
        std::cout << "Erro ao abrir o arquivo CSV: " << caminho << std::endl;
        return alunos;
    }

    std::string linha;
    std::getline(arquivo, linha);
    if(linha.back() == '\r'){
        linha.pop_back();
    }

    while(std::getline(arquivo, linha)){
        if(linha.back() == '\r'){
            linha.pop_back();
        }
        std::vector<std::string> campos;
        std::string campoAtual;
        std::stringstream ss(linha);
        while(std::getline(ss, campoAtual, ',')){
            campos.push_back(campoAtual);
        }
        int matricula = std::stoi(campos[0]);
        std::string& nome = campos[1];
        int idade = std::stoi(campos[2]);
        std::string& curso = campos[3];
        std::string& cidade = campos[4];
        std::string& uf = campos[5];
        float cra = std::stof(campos[6]);
        alunos.emplace_back(matricula, nome, idade, curso, cidade, uf, cra);
    }
    arquivo.close();
    return alunos;

}

bool GerenciadorArquivo::salvarFixo(std::string arq, std::vector<Aluno> al){
    std::fstream arquivo(arq, std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
    if(!arquivo.is_open()){
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return false;
    }

    char buffer[Aluno::TAMANHO_REGISTRO];
    for(Aluno& aluno : al){
        std::memset(buffer, 0, Aluno::TAMANHO_REGISTRO);
        int pos = aluno.packFixo(buffer);
        arquivo.write(reinterpret_cast<char*>(buffer), pos);
    }
    bool sucesso = !arquivo.fail();
    arquivo.close();
    return sucesso;

}

bool GerenciadorArquivo::salvarDelimitado(std::string arq, std::vector<Aluno> al){
    std::fstream arquivo(arq, std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
    if(!arquivo.is_open()){
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return false;
    }
    for(Aluno& aluno : al){
        std::string buffer = aluno.packDelimitado();
        arquivo.write(reinterpret_cast<char*>(buffer.data()), buffer.size());
    }
    bool sucesso = !arquivo.fail();
    arquivo.close();
    return sucesso;
}

bool GerenciadorArquivo::salvarIndicador(std::string arq, std::vector<Aluno> al){
    std::fstream arquivo(arq, std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
    if(!arquivo.is_open()){
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return false;
    }

    
    for(Aluno& aluno : al){
        int tam = aluno.obterTamanhoRegistroIndicador();
        char* buffer = new char[tam];
        int pos = aluno.packIndicador(buffer);
        arquivo.write(reinterpret_cast<char*>(buffer), pos);
        delete[] buffer;
    }
    
    bool sucesso = !arquivo.fail();
    arquivo.close();
    return sucesso;
}

std::vector<Aluno> GerenciadorArquivo::lerFixo(std::string arq){
    
    std::vector<Aluno> alunos;
    std::ifstream arquivo(arq , std::ios::binary);
    
    if(!arquivo.is_open()){
        std::cout << "Erro ao abrir o arquivo: " << arq << std::endl;
        return alunos;
    }

    char buffer[Aluno::TAMANHO_REGISTRO];
    while(arquivo.read(reinterpret_cast<char*>(buffer), Aluno::TAMANHO_REGISTRO)){
        Aluno aluno;
        aluno.unpackFixo(buffer);
        alunos.push_back(aluno);
    }
    arquivo.close();
    return alunos;


}
std::vector<Aluno> GerenciadorArquivo::lerDelimitado(std::string arq){
    std::vector<Aluno> alunos;
    std::ifstream arquivo(arq, std::ios::binary);
    if(!arquivo.is_open()){
        std::cout << "Erro ao abrir o arquivo: " << arq << std::endl;
        return alunos;
    }
    std::string buffer;
    while(std::getline(arquivo, buffer, '|')){
        Aluno aluno;
        aluno.unpackDelimitado(buffer);
        alunos.push_back(aluno);
    }
    arquivo.close();
    return alunos;
}

std::vector<Aluno> GerenciadorArquivo::lerIndicador(std::string arq){
    std::vector<Aluno> alunos;
    std::ifstream arquivo(arq , std::ios::binary);
    
    if(!arquivo.is_open()){
        std::cout << "Erro ao abrir o arquivo: " << arq << std::endl;
        return alunos;
    }

    unsigned short tamRegistro;
    while(arquivo.read(reinterpret_cast<char*>(&tamRegistro), sizeof(tamRegistro))){
        char* buffer = new char[tamRegistro];
        arquivo.read(buffer, tamRegistro);
        Aluno aluno;
        aluno.unpackIndicador(buffer);
        alunos.push_back(aluno);
        delete[] buffer;
    }
    arquivo.close();
    return alunos;
}

bool GerenciadorArquivo::lerPorRRN(std::string arq, int rrn, Aluno& out){
    if(rrn < 0){
        std::cout << "RRN nao pode ser negativo!" << std::endl;
        return false;
    }

    std::ifstream arquivo(arq, std::ios::binary);
    if(!arquivo.is_open()){
        std::cout << "Erro ao abrir o arquivo: " << arq << std::endl;
        return false;       
    }

    int offset = rrn * Aluno::TAMANHO_REGISTRO;
    arquivo.seekg(offset, std::ios::beg);

    if(!arquivo.good()){
        std::cout << "Erro ao tentar encontrar registro!" <<std::endl;
        arquivo.close();
        return false;
    }

    char buffer[Aluno::TAMANHO_REGISTRO];
    arquivo.read(buffer, Aluno::TAMANHO_REGISTRO);

    if(arquivo.gcount() != Aluno::TAMANHO_REGISTRO){
        std::cout << "Erro ao ler registro do arquivo! Ultrapassa os RRNs salvos!" << std::endl;
        return false;       
    }

    out.unpackFixo(buffer);

    arquivo.close();
    return true;

}
long long GerenciadorArquivo::obterTamanhoArquivo(std::string arq){
    
    std::filesystem::path caminho(arq);
    long long tamanho = 0;
    if(std::filesystem::exists(caminho)){
        tamanho = std::filesystem::file_size(caminho);
        return tamanho;
    }
    return tamanho;
}
