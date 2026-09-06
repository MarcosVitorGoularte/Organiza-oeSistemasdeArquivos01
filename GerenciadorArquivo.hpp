#ifndef GERENCIADORARQUIVO_HPP
#define GERENCIADORARQUIVO_HPP

#include <vector>
#include "Aluno.hpp"
#include <string>

class GerenciadorArquivo
{
public:
    GerenciadorArquivo() = delete;
    static std::vector<Aluno> lerCSV(std::string caminho);
    static bool salvarFixo(std::string arq, std::vector<Aluno> al);
    // static bool salvarDelimitado(std::string arq, std::vector<Aluno> al);
    // static bool salvarIndicador(std::string arq, std::vector<Aluno> al);
    static std::vector<Aluno> lerFixo(std::string arq);
    // static std::vector<Aluno> lerDelimitado(std::string arq);
    // static std::vector<Aluno> lerIndicador(std::string arq);
    // static bool lerPorRRN(std::string arq, int rrn, Aluno& out);
    // static long long obterTamanhoArquivo(std::string arq);
};

#endif