#include <iostream>
#include <vector>
#include "Aluno.hpp"
#include "GerenciadorArquivo.hpp"

using namespace std;

int main(){
    string arquivoBinario = "alunos_fixo.bin";
    string arquivoCSV = "alunos_1k.csv";
    vector<Aluno> alunos = GerenciadorArquivo::lerCSV(arquivoCSV);
    GerenciadorArquivo::salvarFixo(arquivoBinario, alunos);
    vector<Aluno> alunosLidos = GerenciadorArquivo::lerFixo(arquivoBinario);
    for(Aluno& al : alunosLidos){
        al.imprimir();
    }

    return 0;
}
