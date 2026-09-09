#include "Aluno.hpp"
#include "GerenciadorArquivo.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    
    //Teste do Fixo
    
    // string arquivoBinario = "alunos_fixo.bin";
    // string arquivoCSV = "alunos_1k.csv";
    // vector<Aluno> alunos = GerenciadorArquivo::lerCSV(arquivoCSV);
    // GerenciadorArquivo::salvarFixo(arquivoBinario, alunos);
    // vector<Aluno> alunosLidos = GerenciadorArquivo::lerFixo(arquivoBinario);
    // int tamUtil = 0;
    // for(Aluno& a : alunosLidos){
    //     a.imprimir();
    //     tamUtil += a.getBytesUteis();
    // }
    // cout << "Tamanho do vetor de alunos lidos: " << alunosLidos.size() << endl;
    // long long tam = GerenciadorArquivo::obterTamanhoArquivo(arquivoBinario);
    // cout << "Tamanho Total: " << tam << " Bytes" << "\nTamanho Util: " << tamUtil << " Bytes" << endl;

    //Teste do Delimitado

    // string arquivoBinario = "alunos_delimitado.bin";
    // string arquivoCSV = "alunos_1k.csv";
    // vector<Aluno> alunos = GerenciadorArquivo::lerCSV(arquivoCSV);
    // GerenciadorArquivo::salvarDelimitado(arquivoBinario, alunos);
    // vector<Aluno> alunosLidos = GerenciadorArquivo::lerDelimitado(arquivoBinario);
    // int tamUtil = 0;
    // for(Aluno& a : alunosLidos){
    //     a.imprimir();
    //     tamUtil += a.getBytesUteis();
    // }
    // cout << "Tamanho do vetor de alunos lidos: " << alunosLidos.size() << endl;
    // long long tam = GerenciadorArquivo::obterTamanhoArquivo(arquivoBinario);
    // cout << "Tamanho Total: " << tam << " Bytes" << "\nTamanho Util: " << tamUtil << " Bytes" << endl;

    //Teste do Indicador

    // string arquivoBinario = "alunos_indicador.bin";
    // string arquivoCSV = "alunos_1k.csv";
    // vector<Aluno> alunos = GerenciadorArquivo::lerCSV(arquivoCSV);
    // GerenciadorArquivo::salvarIndicador(arquivoBinario, alunos);
    // vector<Aluno> alunosLidos = GerenciadorArquivo::lerIndicador(arquivoBinario);
    // int tamUtil = 0;
    // for(Aluno& a : alunosLidos){
    //     a.imprimir();
    //     tamUtil += a.getBytesUteis();
    // }
    // cout << "Tamanho do vetor de alunos lidos: " << alunosLidos.size() << endl;
    // long long tam = GerenciadorArquivo::obterTamanhoArquivo(arquivoBinario);
    // cout << "Tamanho Total: " << tam << " Bytes" << "\nTamanho Util: " << tamUtil << " Bytes" << endl;

    return 0;
}
