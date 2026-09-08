#include "Aluno.hpp"
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>
#include <sstream>

Aluno::Aluno()
{
    matricula = 0;
    nome="";
    idade = 0;
    curso="";
    cidade="";
    uf="";
    cra = 0.0;
}

Aluno::Aluno(int matricula, const std::string& nome, int idade, const std::string& curso, const std::string& cidade, const std::string& uf, float cra)
{
    setMatricula(matricula);
    setNome(nome);
    setIdade(idade);
    setCurso(curso);
    setCidade(cidade);
    setUF(uf);
    setCra(cra);
}

int Aluno::getMatricula() const
{
    return matricula;
}

std::string Aluno::getNome() const
{
    return nome;
}

int Aluno::getIdade() const
{
    return idade;
}

std::string Aluno::getCurso() const
{
    return curso;
}

std::string Aluno::getCidade() const
{
    return cidade;
}

std::string Aluno::getUF() const
{
    return uf;
}

float Aluno::getCra() const
{
    return cra;
}


void Aluno::setMatricula(int matricula){
    if(matricula < 0){
        throw std::invalid_argument("Matricula nao pode ser negativa");
    }
    this->matricula = matricula;
}

void Aluno::setNome(const std::string& nome){
    if(nome.empty()){
        throw std::invalid_argument("Nome nulo.");
    }
    if(nome.size() > TAMANHO_NOME){
        throw std::invalid_argument("Nome maior que 40 bytes.");
    }
    this->nome = nome;
}

void Aluno::setIdade(int idade){
    if(idade < 0 || idade > 130){
        throw std::invalid_argument("Idade nao pode ser negativa ou maior que 130 anos");
    }
    this->idade = idade;
}

void Aluno::setCurso(const std::string& curso){
    if(curso.empty()){
        throw std::invalid_argument("Curso nulo.");
    }
    if(curso.size() > TAMANHO_CURSO){
        throw std::invalid_argument("Curso maior que 35 bytes.");
    }
    this->curso = curso;
}

void Aluno::setCidade(const std::string& cidade){
    if(cidade.empty()){
        throw std::invalid_argument("Cidade nula.");
    }
    if(cidade.size() > TAMANHO_CIDADE){
        throw std::invalid_argument("Cidade maior que 30 bytes.");
    }
    this->cidade = cidade;
}

void Aluno::setUF(const std::string& uf){
    if(uf.empty()){
        throw std::invalid_argument("UF nulo.");
    }
    if(uf.size() > TAMANHO_UF){
        throw std::invalid_argument("UF maior que 3 bytes.");
    }
    this->uf = uf;
}

void Aluno::setCra(float cra){
    if(cra < 0.0 || cra > 10.0){
        throw std::invalid_argument("CRA invalido!(0-10)");
    }
    this->cra = cra;
}

int Aluno::packFixo(char *buffer)
{
    int pos = 0;
    std::memcpy(buffer, &matricula, sizeof(matricula));
    pos+=sizeof(matricula);

    std::memset(buffer + pos, 0, TAMANHO_NOME);
    std::memcpy(buffer + pos, nome.data(), nome.size());
    pos+=TAMANHO_NOME;

    std::memcpy(buffer + pos, &idade, sizeof(idade));
    pos+=sizeof(idade);

    std::memset(buffer + pos, 0, TAMANHO_CURSO);
    std::memcpy(buffer + pos, curso.data(), curso.size());
    pos+=TAMANHO_CURSO;

    std::memset(buffer + pos, 0, TAMANHO_CIDADE);
    std::memcpy(buffer + pos, cidade.data(), cidade.size());
    pos+=TAMANHO_CIDADE;

    std::memset(buffer + pos, 0, TAMANHO_UF);
    std::memcpy(buffer + pos, uf.data(), uf.size());
    pos+=TAMANHO_UF;

    std::memcpy(buffer + pos, &cra, sizeof(cra));
    pos+=sizeof(cra);

    return pos;
}

std::string Aluno::packDelimitado()
{
    std::stringstream stri;
    stri << matricula << '#' << nome.data() << '#' << idade << '#' <<
    curso.data() << '#' << cidade.data() << '#' << uf.data() << '#' << cra << '|';
    std::string buffer = stri.str();
    return buffer;
}

// int Aluno::packIndicador(char *buffer)
// {
// }

void Aluno::unpackFixo(const char *buffer)
{
    int pos = 0;

    std::memcpy(&matricula, buffer, sizeof(matricula));
    pos += sizeof(matricula);

    nome = std::string(buffer + pos);
    pos += TAMANHO_NOME;

    std::memcpy(&idade, buffer + pos, sizeof(idade));
    pos += sizeof(idade);

    curso = std::string(buffer + pos);
    pos += TAMANHO_CURSO;

    cidade = std::string(buffer + pos);
    pos += TAMANHO_CIDADE;

    uf = std::string(buffer + pos);
    pos += TAMANHO_UF;

    std::memcpy(&cra, buffer + pos, sizeof(cra));
    pos += sizeof(cra);

}

void Aluno::unpackDelimitado(const std::string &buffer)
{
    std::stringstream stream(buffer);
    std::string campo;
    if(std::getline(stream, campo, '#')){
        matricula = std::stoi(campo);
    }

    std::getline(stream, nome, '#');

    if(std::getline(stream, campo, '#')){
        idade = std::stoi(campo);
    }

    std::getline(stream, curso, '#');
    std::getline(stream, cidade, '#');
    std::getline(stream, uf, '#');

    if(std::getline(stream, campo)){
        cra = std::stof(campo);
    }
}
// void Aluno::unpackIndicador(const char *buffer)
// {
// }
// int Aluno::getBytesUteis()
// {
// }

void Aluno::imprimir()
{
    std::cout << "Matricula: " << std::right << std::setw(10) << getMatricula() <<
    " | Nome: " << std::left << std::setw(40) << getNome() <<
    " | Idade: " << std::right << std::setw(3) << getIdade() <<
    " | Curso: " << std::left << std::setw(35) << getCurso() <<
    " | Cidade: " << std::setw(30) << getCidade() <<
    " | UF: " << std::setw(3) << getUF() <<
    " | CRA: " << std::fixed << std::setprecision(2) << getCra() << std::endl;
}
