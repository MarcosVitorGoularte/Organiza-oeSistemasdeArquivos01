#ifndef GERENCIADORARQUIVO_HPP
#define GERENCIADORARQUIVO_HPP

#include <vector>
#include "Aluno.hpp"
#include <string>

class GerenciadorArquivo
{
public:
    GerenciadorArquivo() = delete;
    static std::vector<Aluno> lerCSV(const std::string& caminho);
    static bool salvarFixo(const std::string&, std::vector<Aluno> al);
    static bool salvarDelimitado(const std::string& arq, std::vector<Aluno> al);
    // static bool salvarIndicador(const std::string& arq, std::vector<Aluno> al);
    static std::vector<Aluno> lerFixo(const std::string& arq);
    static std::vector<Aluno> lerDelimitado(const std::string& arq);
    // static std::vector<Aluno> lerIndicador(const std::string& arq);
    static bool lerPorRRN(const std::string& arq, int rrn, Aluno& out);
    static long long obterTamanhoArquivo(const std::string& arq);
};

#endif