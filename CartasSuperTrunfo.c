#include <stdio.h>
/*
Olá Professor, Fazia muitos anos que não programava em C
então aproveitei esse primeiro projeto para relembrar alguns pontos que havia esquecido
fui um pouco além do que foi requisitado mas vou deixar documentado cada parte do código
*/

//Estrutura de uma carta de Super trunfo
//Definição da estutura de cidade
typedef struct  
{
    int Populacao;
    double Area;
    double PIB;
    int PontosTuristicos;
} CartasCidade; 
//Definição da estutura de Estado
typedef struct 
{
    CartasCidade Cartas[4];
} CartasEstados;

//Definição da estutura de Das cartas
typedef struct 
{
    CartasEstados Estados[8];
} CartasSuperTrunfo;

//Definição do constantes do enumerador de estado
const char Estados[8] = {'A', 'B', 'C', 'D','E', 'F','G','H'};
//Indeces de cadastro
int IndexCidade = 0;
int IndexEstado = 0;
//Variavel global de cartas
CartasSuperTrunfo cartas;

//Função de impressão de cabeçalho
void Imprimircabecalho(){
    printf("******************************\n");
    printf("*****Super Trunfo Cidades*****\n");
    printf("******************************\n");
    printf("Digite uma opção: \n");
    printf("Cadastrar Cartas: 1\n");
    printf("Comparar Cartas: 2 \n");
    printf("Imprimir todas as cartas: 3 \n");
    printf("Sair: 4 \n");
    printf("Selecionar opção: ");
}

//Função de impressão de todas as cartas
void ImprimirCartas(){
    for (int Estado = 0; Estado <= 7; Estado++){
        for (int Cidade = 0; Cidade <= 3; Cidade++){
            if (cartas.Estados[Estado].Cartas[Cidade].Populacao > 0)
                ImprimirCarta(Cidade, Estado);
        }
    }   
}

//Atualização de indices conforme requisitos
void AtualizarIndices(){
    if (IndexCidade < 3){
        IndexCidade++;
    }
    else{
        IndexCidade = 0;
        IndexEstado++;
    }
}

//Função de cadastro de carta
void CadastrarCarta()
{
    printf("Bem vindo ao cadastro de Cartas Favor digitar os dados:\n");
    printf("Digite a população: ");
    scanf("%d", &cartas.Estados[IndexEstado].Cartas[IndexCidade].Populacao);
    printf("Digite a Área: ");
    scanf("%lf", &cartas.Estados[IndexEstado].Cartas[IndexCidade].Area);
    printf("Digite a PIB: ");
    scanf("%lf", &cartas.Estados[IndexEstado].Cartas[IndexCidade].PIB);
    printf("Digite a Quantidade de pontos turisticos: ");
    scanf("%d", &cartas.Estados[IndexEstado].Cartas[IndexCidade].PontosTuristicos);

    printf("Cadastro concluido!\n");

    //Apos o cadastro imprime os dados da carta
    ImprimirCarta(IndexCidade, IndexEstado);
    //Atualiza indices para cadastro das cartas;
    AtualizarIndices();
    return;
}

//Função de impressão de cartas
void ImprimirCarta(int _IndexCidade, int _IndexEstado){
    printf("******************************\n");
    printf("Dados Carta: \n");
    printf("Código da carta %c%d\n",Estados[_IndexEstado], _IndexCidade);
    printf("Estado: %c \n",Estados[_IndexEstado]);
    printf("Cidade: %d \n", _IndexCidade);
    printf("população: %d \n",cartas.Estados[_IndexEstado].Cartas[_IndexCidade].Populacao);
    printf("Área: %.2lf \n",cartas.Estados[_IndexEstado].Cartas[_IndexCidade].Area);
    printf("PIB: %.2lf \n",cartas.Estados[_IndexEstado].Cartas[_IndexCidade].PIB);
    printf("pontos turisticos: %d \n",cartas.Estados[_IndexEstado].Cartas[_IndexCidade].PontosTuristicos);      
}

void CompararCarta(){
    return;
    //Já deixei a função declarada para desenvolver no intermediario
}


int main() {
    //Variavel de controle de menu
    int ControleMenu = -1;

    //Loop do menu
    while (ControleMenu != 4)
    {
        Imprimircabecalho();
        scanf("%d",&ControleMenu);
        if (ControleMenu == 1)
            CadastrarCarta();
        else if (ControleMenu == 2)
            CompararCarta();
        else if (ControleMenu == 3)
            ImprimirCartas();
    }
    return 0;
}
