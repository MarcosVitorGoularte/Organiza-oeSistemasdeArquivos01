#ifndef ALUNO_HPP
#define ALUNO_HPP
#include <string>



class Aluno
{
private:
    int matricula;
    std::string nome;
    int idade;
    std::string curso;
    std::string cidade;
    std::string uf;
    float cra;
public:

    static constexpr int TAMANHO_NOME = 40;
    static constexpr int TAMANHO_CURSO = 35;
    static constexpr int TAMANHO_CIDADE = 30;
    static constexpr int TAMANHO_UF = 3;
    //Esperado 120
    static constexpr int TAMANHO_REGISTRO = TAMANHO_CIDADE + TAMANHO_NOME + TAMANHO_CURSO + TAMANHO_UF + sizeof(int) + sizeof(float) + sizeof(int);

    Aluno(int matricula, const std::string& nome, int idade, const std::string& curso, const std::string& cidade, const std::string& uf, float cra);

    Aluno();

    int getMatricula()const;
    std::string getNome()const;
    int getIdade()const;
    std::string getCurso()const;
    std::string getCidade()const;
    std::string getUF()const;
    float getCra()const;

    void setMatricula(int matricula);
    void setNome(const std::string& nome);
    void setIdade(int idade);
    void setCurso(const std::string& curso);
    void setCidade(const std::string& cidade);
    void setUF(const std::string& uf);
    void setCra(float cra);

    int packFixo(char* buffer);
    std::string packDelimitado();
    int packIndicador(char* buffer);
    void unpackFixo(const char* buffer);
    void unpackDelimitado(const std::string& buffer);
    void unpackIndicador(const char* buffer);

    int obterTamanhoRegistroIndicador();
    // int getBytesUteis();
    void imprimir();
};

#endif
