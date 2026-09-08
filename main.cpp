#include <iostream>
#include <vector>
#include "Aluno.hpp"
#include "GerenciadorArquivo.hpp"

using namespace std;

int main(){
    string arquivoBinario = "alunos_delimitado.bin";
    string arquivoCSV = "alunos_1k.csv";
    vector<Aluno> alunos = GerenciadorArquivo::lerCSV(arquivoCSV);
    GerenciadorArquivo::salvarDelimitado(arquivoBinario, alunos);
    vector<Aluno> alunosLidos = GerenciadorArquivo::lerDelimitado(arquivoBinario);
    for(Aluno& al : alunosLidos){
        al.imprimir();
    }
    cout << "Tamanho do vetor de alunos lidos: " << alunosLidos.size() << endl;
    long long tam = GerenciadorArquivo::obterTamanhoArquivo(arquivoBinario);
    cout << tam << " Bytes" << endl;

    return 0;
}
