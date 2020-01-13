#include "include/corretor.h"
#include <stdio.h>
#include <stdlib.h>
#include "include/file.h"

void corrigirProva(int numeroArquivo)
{
    FILE *arquivo;
    // cria o arquivo passado com o número passado pelo parametro
    char nomeArquivo[40];
    sprintf(nomeArquivo, "%s/prova-%i", DIRNAME, numeroArquivo);
    arquivo = fopen(nomeArquivo, "w");


    // Variaveis 

    // 
    float acertoTotal = 0;
    float mediaTotal = 0;
    // guarda a quantidade de acertos de cada questão
    // a posição do total de acertos é igual a posição das questões
    float acertosPorQuestao[qtdQuestoes];

    // inicialização do vetor
    for (int i = 0; i < qtdQuestoes; i++)
    {
        acertosPorQuestao[i] = 0;
    }
    

    // Estrutura de repetição que percorre os alunos
    for (int PercAlunos = 0; PercAlunos < qtdAlunos; PercAlunos++)
    {
        //Variaveis de acerto e erro
        int acertos = 0;
        int erros = 0;

        fprintf(arquivo, "\n");
        fprintf(arquivo, "Nome %d° aluno(a): %s \n", PercAlunos+1, nomeAlunos[PercAlunos]);
        // Estrutura que percorre as alternativas
        for (int PercAlter = 0; PercAlter < qtdQuestoes; PercAlter++)
        {
            // Compara a alternativas dos alunos com gabarito
            if (respostasAlunos[PercAlter][PercAlunos] == gabarito[PercAlter])
            {
                fprintf(arquivo, "Questão: %d° Resposta Correta: %c \n", PercAlter +1, gabarito[PercAlter]);
                // conta quantidade de acertos do aluno
                acertos++;
                // conta quantidade de erros do aluno
                acertoTotal++;
                // conta a quantidade de acertos da questão
                acertosPorQuestao[PercAlter]++;
            }
            else
            {
                fprintf(arquivo, "Questão: %d° Resposta Errada \n", PercAlter +1);
                // conta a quantidade de erros do aluno
                erros++;
            }
        }
        // Exibe o total de acertos e de erros do aluno
        fprintf(arquivo, "Total de Acertos do aluno(a): %d \n", acertos);
        fprintf(arquivo, "Total de Erros do aluno(a): %d \n", erros);
        
    }
    // calcula a media de acertos dos alunos
    mediaTotal = acertoTotal/qtdAlunos;
    fprintf(arquivo, "\n \n");
    fprintf(arquivo, "-------------------------------------------\n");
    fprintf(arquivo, "A MÉDIA de acertos da turma é: %.2f/%d \n", mediaTotal, qtdQuestoes);

    
    fprintf(arquivo, "\n");
    fprintf(arquivo, "-------------------------------------------\n");    
    fprintf(arquivo, "Taxa de Acerto de cada questão: \n");
    // laço para calcular a taxa de acerto de cada questão
    for (int i = 0; i < qtdQuestoes; i++)
    {
        // calcula a taxa de acerto da questão
        acertosPorQuestao[i] = (acertosPorQuestao[i]/qtdAlunos)*100;
        fprintf(arquivo, "%d° Questão: %.0f\% \n", i+1, acertosPorQuestao[i]);
    }

    fclose(arquivo);
    
}