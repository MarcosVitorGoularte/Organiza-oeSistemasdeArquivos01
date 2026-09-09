#include "Aluno.hpp"
#include "GerenciadorArquivo.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    
    //Teste do Fixo
    
    /*string arquivoBinario = "alunos_fixo.bin";
    string arquivoCSV = "alunos_1k.csv";
    vector<Aluno> alunos = GerenciadorArquivo::lerCSV(arquivoCSV);
    GerenciadorArquivo::salvarFixo(arquivoBinario, alunos);
    vector<Aluno> alunosLidos = GerenciadorArquivo::lerFixo(arquivoBinario);
    cout << "Tamanho do vetor de alunos lidos: " << alunosLidos.size() << endl;
    for(Aluno& a : alunosLidos){
        a.imprimir();
    }*/

    //Teste do Delimitado

    /*string arquivoBinario = "alunos_delimitado.bin";
    string arquivoCSV = "alunos_1k.csv";
    vector<Aluno> alunos = GerenciadorArquivo::lerCSV(arquivoCSV);
    GerenciadorArquivo::salvarDelimitado(arquivoBinario, alunos);
    vector<Aluno> alunosLidos = GerenciadorArquivo::lerDelimitado(arquivoBinario);
    cout << "Tamanho do vetor de alunos lidos: " << alunosLidos.size() << endl;
    for(Aluno& a : alunosLidos){
        a.imprimir();
    }*/

    //Teste do Indicador

    /*string arquivoBinario = "alunos_indicador.bin";
    string arquivoCSV = "alunos_1k.csv";
    vector<Aluno> alunos = GerenciadorArquivo::lerCSV(arquivoCSV);
    GerenciadorArquivo::salvarIndicador(arquivoBinario, alunos);
    cout << "Salvo" << endl;
    vector<Aluno> alunosLidos = GerenciadorArquivo::lerIndicador(arquivoBinario);
    cout << "Tamanho do vetor de alunos lidos: " << alunosLidos.size() << endl;
    GerenciadorArquivo::salvarIndicador(arquivoBinario, alunos);
    alunosLidos = GerenciadorArquivo::lerIndicador(arquivoBinario);
    for(Aluno& a : alunosLidos){
        a.imprimir();
    }
    cout << "Tamanho do vetor de alunos lidos: " << alunosLidos.size() << endl;


    long long tam = GerenciadorArquivo::obterTamanhoArquivo(arquivoBinario);
    cout << tam << " Bytes" << endl;*/

    return 0;
}
