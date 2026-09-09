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
    this->matricula = matricula;
}

void Aluno::setNome(const std::string& nome){
    this->nome = nome;
}

void Aluno::setIdade(int idade){
    this->idade = idade;
}

void Aluno::setCurso(const std::string& curso){
    this->curso = curso;
}

void Aluno::setCidade(const std::string& cidade){
    this->cidade = cidade;
}

void Aluno::setUF(const std::string& uf){
    this->uf = uf;
}

void Aluno::setCra(float cra){
    this->cra = cra;
}

int Aluno::packFixo(char *buffer)
{
    int pos = 0;
    std::memcpy(buffer, &matricula, sizeof(matricula));
    pos+=sizeof(matricula);

    std::memset(buffer + pos, 0, TAMANHO_NOME);
    std::memcpy(buffer + pos, nome.data(), std::min(nome.size(), static_cast<size_t>(TAMANHO_NOME-1)));
    pos+=TAMANHO_NOME;

    std::memcpy(buffer + pos, &idade, sizeof(idade));
    pos+=sizeof(idade);

    std::memset(buffer + pos, 0, TAMANHO_CURSO);
    std::memcpy(buffer + pos, curso.data(), std::min(curso.size(), static_cast<size_t>(TAMANHO_CURSO-1)));
    pos+=TAMANHO_CURSO;

    std::memset(buffer + pos, 0, TAMANHO_CIDADE);
    std::memcpy(buffer + pos, cidade.data(), std::min(cidade.size(), static_cast<size_t>(TAMANHO_CIDADE-1)));
    pos+=TAMANHO_CIDADE;

    std::memset(buffer + pos, 0, TAMANHO_UF);
    std::memcpy(buffer + pos, uf.data(), std::min(uf.size(), static_cast<size_t>(TAMANHO_UF-1)));
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

int Aluno::obterTamanhoRegistroIndicador(){
    unsigned char tamNome = nome.size();
    unsigned char tamCurso = curso.size();
    unsigned char tamCidade = cidade.size();
    unsigned char tamUF = uf.size();

    unsigned short tam = sizeof(matricula) + sizeof(tamNome) + tamNome + sizeof(idade) + sizeof(tamCurso) + tamCurso + + sizeof(tamCidade) + tamCidade + tamUF + sizeof(tamUF) + sizeof(cra);

    return tam + sizeof(tam);
}

int Aluno::packIndicador(char *buffer)
{
    unsigned char tamNome = nome.size();
    unsigned char tamCurso = curso.size();
    unsigned char tamCidade = cidade.size();
    unsigned char tamUF = uf.size();

    unsigned short tam = sizeof(matricula) + sizeof(tamNome) + tamNome + sizeof(idade) + sizeof(tamCurso) + tamCurso + + sizeof(tamCidade) + tamCidade + tamUF + sizeof(tamUF) + sizeof(cra);
    int pos = 0;

    std::memcpy(buffer + pos, &tam, sizeof(tam));
    pos += sizeof(tam);

    std::memcpy(buffer + pos, &matricula, sizeof(matricula));
    pos+=sizeof(matricula);

    std::memcpy(buffer + pos, &tamNome, sizeof(tamNome));
    pos+=sizeof(tamNome);

    std::memcpy(buffer + pos, nome.data(), nome.size());
    pos+=tamNome;

    std::memcpy(buffer + pos, &idade, sizeof(idade));
    pos+=sizeof(idade);

    std::memcpy(buffer + pos, &tamCurso, sizeof(tamCurso));
    pos+=sizeof(tamCurso);

    std::memcpy(buffer + pos, curso.data(), curso.size());
    pos+=tamCurso;
    
    std::memcpy(buffer + pos, &tamCidade, sizeof(tamCidade));
    pos+=sizeof(tamCidade);

    std::memcpy(buffer + pos, cidade.data(), cidade.size());
    pos+=tamCidade;
    
    std::memcpy(buffer + pos, &tamUF, sizeof(tamUF));
    pos+=sizeof(tamUF);

    std::memcpy(buffer + pos, uf.data(), uf.size());
    pos+=tamUF;

    std::memcpy(buffer + pos, &cra, sizeof(cra));
    pos+=sizeof(cra);

    return pos;
}

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

void Aluno::unpackIndicador(const char *buffer)
{
    int pos = 0;
    std::memcpy(&matricula, buffer + pos, sizeof(matricula));
    pos += sizeof(matricula);

    unsigned char tamNome;
    std::memcpy(&tamNome, buffer+pos, sizeof(tamNome));
    pos+=sizeof(tamNome);

    nome = std::string(buffer + pos, tamNome);
    pos += tamNome;
    
    std::memcpy(&idade, buffer + pos, sizeof(idade));
    pos += sizeof(idade);

    unsigned char tamCurso;
    std::memcpy(&tamCurso, buffer+pos, sizeof(tamCurso));
    pos+=sizeof(tamCurso);

    curso = std::string(buffer + pos, tamCurso);
    pos += tamCurso;

    unsigned char tamCidade;
    std::memcpy(&tamCidade, buffer+pos, sizeof(tamCidade));
    pos+=sizeof(tamCidade);
    
    cidade = std::string(buffer + pos, tamCidade);
    pos += tamCidade;

    unsigned char tamUF;
    std::memcpy(&tamUF, buffer+pos, sizeof(tamUF));
    pos+=sizeof(tamUF);

    uf = std::string(buffer + pos, tamUF);
    pos += tamUF;

    std::memcpy(&cra, buffer + pos, sizeof(cra));
    pos += sizeof(cra);
}
// int Aluno::getBytesUteis()
// {
// =}

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
