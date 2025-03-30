#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

#define MAX_FURIA 5
#define MAX_TURNOS_FURIA 3



typedef struct {
    int furia;
    int ativa;
} Gousma;
void atacar(Gousma *atacante, Gousma *defensor) {
    if (!atacante->ativa || !defensor->ativa) {
        printf("Ataque invalido!\n");
        return;
    }
    defensor->furia += atacante->furia;
    atacante->furia = 0;
    printf("Ataque realizado!\n");
    if (defensor->furia >= MAX_FURIA) {
        defensor->ativa = 0;
        printf("Uma Gousma desintegrou!\n");
    }
}

void dividirGousma(Gousma *g1, Gousma *g2) {
    if (!g1->ativa || g1->furia < 2 || g2->ativa) {
        printf("Nao e possivel dividir a Gousma!\n");
        return;
    }
    int metade = g1->furia / 2;
    g1->furia -= metade;
    g2->furia = metade;
    g2->ativa = 1;
    printf("Gousma dividida com sucesso!\n");
}

void adicionarFuria(Gousma *g1, Gousma *g2) {
    if (g1->ativa) {
        g1->furia++;
        if (g1->furia >= MAX_FURIA) {
            g1->ativa = 0;
            printf("Uma Gousma desintegrou por excesso de fúria!\n");
        }
    } else if (g2->ativa) {
        g2->furia++;
        if (g2->furia >= MAX_FURIA) {
            g2->ativa = 0;
            printf("Uma Gousma desintegrou por excesso de fúria!\n");
        }
    }
}

void imprimirStatus(Gousma *g1, Gousma *g2, int numeroJogador) {
    printf("\nStatus do Jogador %d:\n", numeroJogador);
    printf("Gousma 1 - Furia: %d (%s)\n", g1->furia, g1->ativa ? "Ativa" : "Desintegrada");
    printf("Gousma 2 - Furia: %d (%s)\n", g2->furia, g2->ativa ? "Ativa" : "Desintegrada");
}


int main (){

    // configurando linguagens \/
    setlocale(LC_ALL,"pt_BR.UTF-8"); // configura a linguagem do programa em si para a região especificada, no caso, português do Brasil
    SetConsoleOutputCP(65001); //configura o console em que o programa vai rodar, o 65001 é para especificar o uso do utf-8, ou seja, o unicode
    SetConsoleCP(65001);// configura que a entrada de onfirmações aceite utf-8

    int menu = 0;  
    int perguntas_menu,perguntas2,perguntas3 = 0;
    int cobra_menu,cobra1,cobra_escolha1,cobra_escolha2,cobra5 = 0;
    const char* cobra_nome1;
    const char*cobra_nome2;
    int gousmas_menu,gousmas1,gousmas2 = 0;
    //wchar_t nome[50];
    
    //printf("Antes de começarmos, me diga seu primeiro nome!\n");
    //fgetws(nome, 50, stdin);
    //clear();
    printf("Bem-vindo");    
    printf("Vamos jogar algo! tenho 3 jogos disponíveis para você!\n");   
    
        while (menu!=4)
    {
            printf("Digite o número correspondente ao jogo para iniciarmos ele!\n");
            printf("(1) Perguntas e respostas\n");
            printf("(2) Jogo da cobra na caixa\n");      
            printf("(3) Gousmas war\n");
            printf("(4) Sair do Programa\n");
            scanf("%d",&menu);
        
            if (menu == 1)
        {
            printf("Você escolheu o jogo de perguntas e respostas!\n");
            
            perguntas_menu = 0;
            perguntas2 = 0;
            perguntas3 = 0;

            while(menu == 1 && perguntas_menu != 3)
            {
                printf("Escolha uma das seguintes opções, digitando seu número correspondente!\n");
                printf("(1) Iniciar jogo!\n");
                printf("(2) Regras do jogo\n");
                printf("(3) Voltar para a escolha de jogos\n");
                scanf("%d", &perguntas_menu);

                if (perguntas_menu == 1)
                {
                        printf("Vamos começar com a primeira pergunta!\n");

                        printf("Qual é o maior planeta do sistema solar?\n");

                        printf("(1) Júpiter\n");
                        printf("(2) Saturno\n"); 
                        printf("(3) Urano\n");
                        printf("(4) Netuno\n");
                        scanf("%d", &perguntas2);
                    
                    if (perguntas2 == 1)
                    {
                        printf("Resposta correta!\n");
                        perguntas3++;
                    }
                    else
                    {
                        printf("A resposta correta é Júpiter!\n");
                    }
                    {
                        printf("Qual é o menor planeta do sistema solar?\n");

                        printf("(1) Mercúrio\n");
                        printf("(2) Marte\n");
                        printf("(3) Vênus\n");
                        printf("(4) Terra\n");
                        scanf("%d", &perguntas2);

                        if (perguntas2 == 1)
                    {
                            printf("Resposta correta!\n");
                            perguntas3++;
                    }
                        else
                    {
                            printf("A resposta correta é Mercúrio!\n");
                    }
                        printf("Qual é o planeta mais próximo do sol?\n");

                        printf("(1) Mercúrio\n");
                        printf("(2) Marte\n");
                        printf("(3) Vênus\n");
                        printf("(4) Terra\n");
                        scanf("%d", &perguntas2);

                        if (perguntas2 == 1)
                    {
                            printf("Resposta correta!\n");
                            perguntas3++;
                    }
                        else
                    {
                            printf("A resposta correta é Mercúrio (De novo)!\n");
                    }
                        printf("Qual é o planeta mais distante do sol?\n");

                        printf("(1) Mercúrio\n");
                        printf("(2) Marte\n");
                        printf("(3) Vênus\n");
                        printf("(4) Netuno\n");
                        scanf("%d", &perguntas2);

                        if (perguntas2 == 4)
                    {
                            printf("Resposta correta!\n");
                            perguntas3++;
                    }
                        else
                    {
                            printf("A resposta correta é Netuno!\n");
                    }
                        printf("Qual é o planeta que possui anéis?\n");

                        printf("(1) Júpiter\n");
                        printf("(2) Saturno\n");
                        printf("(3) Urano\n");
                        printf("(4) Netuno\n");
                        scanf("%d", &perguntas2);

                        if (perguntas2 == 2)
                    {
                            printf("Resposta correta!\n");
                            perguntas3++;
                    }
                        else
                    {
                            printf("A resposta correta é Saturno!\n");
                    }
                }
                        printf("Fim do jogo de perguntas e respostas!\n");
                        printf("Você acertou %d perguntas!\n", perguntas3);
                        printf("Deseja jogar novamente?\n");
                        perguntas2 = 0;

                    while (perguntas2 !=1)
                    {
                            printf("(1) Não\n");
                            printf("(2) Sim\n");
                            scanf("%d", &perguntas2);
                        if (perguntas2 == 1)
                    {
                            perguntas_menu = 3;
                            printf("Que pena! Até a próxima!\n");
                    }
                        else if (perguntas2 == 2)
                    {
                            perguntas3 = 0;
                            perguntas2 = 1;
                            printf("Que bom! Vamos voltar para o menu do jogo de perguntas e respostas!\n");
                    }
                        else
                    {
                            printf("Opção inválida, tente novamente!\n");
                    }
                    }
                }
                else if (perguntas_menu == 2)
                {
                    printf("No jogo de perguntas e respostas você terá que responder perguntas de conhecimentos gerais\nA cada pergunta respondida corretamente você ganhará um ponto!\nTente acertar todas as perguntas!\n");
                }
                else if (perguntas_menu == 3)
                {
                    printf("Voltando para a escolha de jogos!\n");
                }
                else 
                {
                    printf("Opção inválida, tente novamente!\n");
                }

            }
        }
            else if (menu == 2)
        {
            printf("Você escolheu o jogo da cobra na caixa!\n");

            cobra_menu=0,cobra1=0,cobra_escolha1=0,cobra_escolha2=0,cobra5=0;
            
            while (menu == 2 && cobra_menu != 4)
            {
                printf("Escolha uma das seguintes opções, digitando seu número correspondente!\n");
                printf("(1) Iniciar jogo!\n");
                printf("(2) Regras do jogo\n");
                printf("(3) História do jogo\n");
                printf("(4) Voltar para a escolha de jogos\n");
                scanf("%d", &cobra_menu);

                if (cobra_menu == 1)
                {
                    
                    //Escolha dos nomes

                    const char* cobra_lista_nomes[] = {"Guilherme","Gabriel","Pedro","Arthur","Caroline","Juliana","Carol"};// lista de nomes, const é usado p/ variaves que nao podem ser alteradas depois de declaradas
                    int nomes_livres[7] = {1,1,1,1,1,1,1}; // lista de ponteiros, queu usarei para a lista cobra_lista_nomes
                    
                    printf("Jogador 1, escolha um personagem para você\n");
                    //escolha personagem 1
                    while (1)
                    {
                        for (int i = 0; i < 7; i++)
                           {
                            printf("(%i) %s\n", i + 1, cobra_lista_nomes[i]);
                           }
                        scanf("%d", &cobra_escolha1);      
                        if (cobra_escolha1>=1 && cobra_escolha1<=7)
                        {
                            break;
                        }
                        else
                        {
                            printf("Escolha inválida, escolha novamente, e corretamente dessa vez");
                        }
                        
                    }
                    nomes_livres[cobra_escolha1-1] = 0;
                    printf("Você escolheu %s\n", cobra_lista_nomes[cobra_escolha1-1]);
                    cobra_nome1 = cobra_lista_nomes[cobra_escolha1-1];
                    
                    printf("Jogador 2, escolha seu nome!\n");
                   //escolha personagem 2
                    while (1)
                    {
                        for (int i = 0; i < 7; i++)
                           {
                            if (nomes_livres[i] == 1)
                            {
                                printf("(%i) %s\n", i + 1, cobra_lista_nomes[i]);
                            }
                            
                           }
                           
                        scanf("%d", &cobra_escolha2);
                           
                        if(cobra_escolha2 >= 1 && cobra_escolha2 <= 7 && nomes_livres[cobra_escolha2 - 1] == 1)
                           
                            {
                                break;
                            }
                        else
                            {
                                printf("Escolha outro!\n");
                            }
    
                        nomes_livres[cobra_escolha2-1] = 0;
                    }
                    
                    
                    printf("Você escolheu %s\n", cobra_lista_nomes[cobra_escolha2-1]);
                    cobra_nome2 = cobra_lista_nomes[cobra_escolha2-1];
                    printf("Vamos começar o jogo da cobra na caixa!\n");
                    
                    
                    //jogo de fato a partir daqui
                    
                    
                    srand(time(NULL));
                    const char* jogadores[] = {cobra_nome1,cobra_nome2};
                    int caixas[5] = {1,1,1,1,1};
                    
                    //quem é o jogador inicial
                    int jogador_inicial = rand() % 2; 
                    
                    //pra contar quem vai jogar dps
                    int cont_jogador;
                    cont_jogador = 0;
                    
                    //onde a cobra está
                    int cobra_caixa = rand();
                    cobra_caixa %= 5;
                    
                    //onde o botão está
                    int botao;
                    if (cobra_caixa==4)
                    {
                        botao = cobra_caixa-1;
                    }
                    else if (cobra_caixa==0)
                    {
                        botao = cobra_caixa+1;
                    }
                    else
                    {
                        botao = cobra_caixa+1;
                    }

                    //int jogo_rodar = 0;
                    
                    
                    printf("O jogador %s começa!\n", jogadores[jogador_inicial]);
                    
                    while (1)
                    {                       
                        int caixas_valor_total = 0;
                        //quantas caixas faltam
                        for (int k=0; k<5; k++)
                        {
                            caixas_valor_total=caixas_valor_total+caixas[k];
                        }  
                        
                        //quem está jogando
                        jogador_inicial++;
                        jogador_inicial %= 2;
                        if (jogador_inicial == 0)
                        {
                            printf("%s, há %d caixas dispostas na sua frente.\nEscolha sabiamente...\n\n", cobra_nome1,caixas_valor_total);
                        }
                        else
                        {
                            printf("%s, há %d caixas dispostas na sua frente.\nEscolha sabiamente...\n\n", cobra_nome2,caixas_valor_total);
                        }
                        
                        //enumeração das caixas disponiveis
                        for (int j = 0; j < 5; j++)
                        {
                            if (caixas[j] == 1)
                            {
                                printf("(%i) Caixa %i\n", j + 1, j + 1);
                            }
                        }
                        

                        scanf("%d", &cobra1);
                        while(cobra1<1 || cobra1>5 || caixas[cobra1-1] == 0)
                        {
                            printf("Escolha uma opção válida\n");
                            scanf("%d", &cobra1);
                        }
                        if(cobra1 == cobra_caixa)
                        {
                            printf("Você abre a caixa....e se depara com.....a cobra!\n");
                            break;
                        }
                        else if (cobra1 == botao)
                        {
                            printf("Você abre a caixa....e encontra o botão! a saída está logo ali! Você ganhou!\n");
                            break;
                        }
                        else
                        {
                            printf("A caixa está vazia.... você precisa procurar mais...\n");
                        }
                        
                        cont_jogador=cont_jogador+1;
                        caixas[cobra1-1] = 0;
                    }
                   
                   printf("Deseja jogar novamente?\n");
                   
                   while (cobra5!=1)
                    {
                        printf("(1) Não\n");
                        printf("(2) Sim\n");
                        scanf("%d", &cobra5);
                        if (cobra5 == 1)
                        {
                            cobra_menu = 4;
                            printf("Que pena! Até a próxima!\n");
                        }
                        else if (cobra5 == 2)
                        {
                            cobra_menu = 1;
                            printf("Que bom! Vamos voltar para o menu do jogo da cobra na caixa!\n");
                        }     
                        else
                        {
                            printf("Opção inválida, tente novamente!\n");
                        }
                    }
                   
                        
                }
                else if (cobra_menu == 2)
                {
                    printf("No jogo da cobra na caixa, dois jogadores jogam um contra o outro, cada um escolhendo um nome predefinido.\nHaverão 5 caixas a serem escolhidas, uma conterá um botão, que o levará para sua segurança, e outra, haverá uma cobra, que te morderá.\nEscolherei um jogador, aleatoriamente para começar, e ele escolherá uma caixa, e assim por diante, até que um jogador encontre a cobra, ou o botão.\n\nResumindo, jogador que encontrar a cobra perde, e o que encontrar o botão ganha!\n\n");
                }
                else if(cobra_menu == 3)
                {
                    printf("Você e seu amigo são exploradores de tumbas antigas, e, ao receber uma dica importante de um conhecido em comum, decidem ir para o Vale dos Reis, um famoso túmulo de reis egípcios.\nVocês passam por diversas dificuldades, mas conseguem entrar na tumba de Amenófis I, entretanto, vocês acabam preso dentro de uma das salas e, curiosamente, no centro dela há 5 caixas, e areia começa a encher o local...\n");
                }
                else if (cobra_menu == 4)
                {
                    printf("Voltando para a escolha de jogos!\n");
                }
                else
                {
                    printf("Opção inválida, tente novamente!\n");
                }

            }
            
        }
            else if (menu == 3)
        {
            printf("Você escolheu o Gousmas war!\n");

            gousmas_menu=0, gousmas1=0, gousmas2=0;

            while (menu == 3 && gousmas_menu !=3)
            {
                printf("Escolha uma das seguintes opções, digitando seu numero correspondente!\n");
                printf("(1) Iniciar jogo!\n");
                printf("(2) Regras do jogo\n");
                printf("(3) Voltar para a escolha de jogos\n");
                scanf("%d",&gousmas_menu);

                if (gousmas_menu==1)
                {
                    Gousma p1_g1 = {1, 1}, p1_g2 = {1, 1};
                    Gousma p2_g1 = {1, 1}, p2_g2 = {1, 1};
                    int escolha, g1, g2;

                    while (1) {
                        system("cls");
                        imprimirStatus(&p1_g1, &p1_g2, 1);
                        imprimirStatus(&p2_g1, &p2_g2, 2);
                        printf("\nJogador 1, escolha sua acao:\n1. Atacar\n2. Dividir Gousma\n");
                        scanf("%d", &escolha);
                        if (escolha == 1) 
                        {
                            printf("Escolha sua Gousma e a do oponente para atacar (1-2): ");
                            scanf("%d %d", &g1, &g2);
                            atacar(g1 == 1 ? &p1_g1 : &p1_g2, g2 == 1 ? &p2_g1 : &p2_g2);
                        } else if (escolha == 2) 
                        {
                            dividirGousma(&p1_g1, &p1_g2);
                        }
                        adicionarFuria(&p1_g1, &p1_g2);
                        if (!p2_g1.ativa && !p2_g2.ativa) 
                        {
                            printf("Jogador 1 venceu!\n");
                            break;
                        }
                        
                        system("cls");
                        imprimirStatus(&p1_g1, &p1_g2, 1);
                        imprimirStatus(&p2_g1, &p2_g2, 2);
                        printf("\nJogador 2, escolha sua acao:\n1. Atacar\n2. Dividir Gousma\n");
                        
                        scanf("%d", &escolha);
                        if (escolha == 1) 
                        {
                            printf("Escolha sua Gousma e a do oponente para atacar (1-2): ");
                            scanf("%d %d", &g1, &g2);
                            atacar(g1 == 1 ? &p2_g1 : &p2_g2, g2 == 1 ? &p1_g1 : &p1_g2);
                        } else if (escolha == 2) 
                        {
                            dividirGousma(&p2_g1, &p2_g2);
                        }
                        adicionarFuria(&p2_g1, &p2_g2);
                        if (!p1_g1.ativa && !p1_g2.ativa) 
                        {
                            printf("Jogador 2 venceu!\n");
                            break;
                        }
                    }
                    
                    int gousmas_denovo = 0;
                    printf("Fim do jogo Gousmas Wars!\n");
                    printf("Deseja jogar novamente?\n");
                    

                    while (gousmas_denovo!=1)
                    {
                        printf("(1) Não\n");
                        printf("(2) Sim\n");
                        scanf("%d", &gousmas_denovo);
                        if (gousmas_denovo == 1)
                        {
                            gousmas_menu = 3;
                            printf("Que pena! Até a próxima!\n");
                        }
                        else if (gousmas_denovo == 2)
                        {
                            gousmas_menu = 0;
                            gousmas_denovo = 1;
                            printf("Que bom! Vamos voltar para o menu do jogo de Gousmas Wars!\n");
                        }
                        else
                        {
                            printf("Opção inválida, tente novamente!\n");
                        }
                    }
                    
                }
                if (gousmas_menu==2)
                {
                    printf("As regras são complicadas, mas aqui vão elas!\nCada jogador inicia com duas Gousmas, cada uma com nível de fúria 1\nSe uma Gousma atingir um nível de fúria maior que 5, ela se desintegra\nQuando uma Gousma ataca outra, transfere todo o seu nível de fúria para a Gousma atacada\nNo final de cada rodada, um nível de fúria é adicionada para todas as Gousmas\nO jogador pode optar por dividir uma Gousma, transferindo uma parte da fúria para uma nova Gousma (respeitando o limite de duas Gousmas por jogador)\nO jogador que perder todas as suas Gousmas será derrotado;");
                }
                if (gousmas_menu==3)
                {
                    printf("Voltando para o menu de jogos....\n");
                }
                else
                {
                    printf("Opção inválida!\n");
                }
            }
        }
            else if (menu == 4)
        {
        }
            else
        {
            menu = 0;
            printf("Opção inválida, tente novamente!\n");
        }    
    }
    printf("Até a próxima!\n");
    return 0;
} 