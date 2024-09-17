#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/*
Olá Professor, Fazia muitos anos que não programava em C
então aproveitei esse primeiro projeto para relembrar alguns pontos que havia esquecido
fui um pouco além do que foi requisitado mas vou deixar documentado cada parte do código
*/

//Estrutura de uma carta de Super trunfo
//Definição da estutura de cidade
typedef struct  
{
    char Cidade[30];
    unsigned long int Populacao;
    float Area;
    float PIB;
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
int IndexCidade = 1;
int IndexEstado = 0;
//Variavel global de cartas
CartasSuperTrunfo cartas;
//Variavel global carta selecionada
char primeiracartaselecionada[3];
char segundacartaselecionada[3];


//Função de impressão de cartas

//Funcao retorna dencidade populacional
float RetornaDencidadePopulacional(int _IndexEstado, int _IndexCidade){
    return cartas.Estados[_IndexEstado].Cartas[_IndexCidade].Populacao / 
        cartas.Estados[_IndexEstado].Cartas[_IndexCidade].Area;

}

//Funcao retorna dencidade populacional invertida para calculo do super
float RetornaDencidadePopulacionalInvertida(int _IndexEstado, int _IndexCidade){
    return cartas.Estados[_IndexEstado].Cartas[_IndexCidade].Area / 
        cartas.Estados[_IndexEstado].Cartas[_IndexCidade].Populacao;

}

//Funcao retorna renda per capita
float RetornaRendaPerCapita(int _IndexEstado, int _IndexCidade){
    return cartas.Estados[_IndexEstado].Cartas[_IndexCidade].PIB  /
        cartas.Estados[_IndexEstado].Cartas[_IndexCidade].Populacao;
}


void ImprimirCarta(int _IndexCidade, int _IndexEstado){
    printf("******************************\n");
    printf("Dados Carta: \n");
    printf("Código da carta %c0%d\n",Estados[_IndexEstado], _IndexCidade);
    printf("Estado: %c \n",Estados[_IndexEstado]);
    printf("Cidade: %s \n", cartas.Estados[_IndexEstado].Cartas[_IndexCidade].Cidade);
    printf("população: %ld \n",cartas.Estados[_IndexEstado].Cartas[_IndexCidade].Populacao);
    printf("Área: %.2lf \n",cartas.Estados[_IndexEstado].Cartas[_IndexCidade].Area);
    printf("Densidade Populacional: %.2f \n", RetornaDencidadePopulacional(_IndexEstado, _IndexCidade));
    printf("PIB: %.2lf \n",cartas.Estados[_IndexEstado].Cartas[_IndexCidade].PIB);
    printf("PIB per Capita: %.2f \n", RetornaRendaPerCapita(_IndexEstado, _IndexCidade));
    printf("pontos turisticos: %d \n",cartas.Estados[_IndexEstado].Cartas[_IndexCidade].PontosTuristicos);      
}

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
    if (IndexCidade < 4){
        IndexCidade++;
    }
    else{
        IndexCidade = 1;
        IndexEstado++;
    }
}

//Retorna o index do Estado()
int RetornaIndiceEstado(char Estado){
    for (int I=0;I<7;I++){
        if (Estados[I] == Estado)
            return I;
    }
}


//Função de cadastro de carta
void CadastrarCarta()
{
    printf("Bem vindo ao cadastro de Cartas Favor digitar os dados:\n");
    printf("Digite o nome da cidade: ");
    scanf("%s", &cartas.Estados[IndexEstado].Cartas[IndexCidade].Cidade);
    printf("Digite a população: ");
    scanf("%ld", &cartas.Estados[IndexEstado].Cartas[IndexCidade].Populacao);
    printf("Digite a Área: ");
    scanf("%f", &cartas.Estados[IndexEstado].Cartas[IndexCidade].Area);
    printf("Digite a PIB: ");
    scanf("%f", &cartas.Estados[IndexEstado].Cartas[IndexCidade].PIB);
    printf("Digite a Quantidade de pontos turisticos: ");
    scanf("%d", &cartas.Estados[IndexEstado].Cartas[IndexCidade].PontosTuristicos);

    printf("Cadastro concluido!\n");

    //Apos o cadastro imprime os dados da carta
    ImprimirCarta(IndexCidade, IndexEstado);
    //Atualiza indices para cadastro das cartas;
    AtualizarIndices();
    return;
}


//Fazendo a chamada para seleção da carta
void FazerCartaSelecionada(int NumeroCarta){    
    char selecao[3];
    printf("Digite o código da carta: \n");
    scanf("%s",&selecao);
    ImprimirCarta((int) selecao[2], RetornaIndiceEstado(selecao[0]));
    if (NumeroCarta == 0)
        strcpy(primeiracartaselecionada, selecao);
    else    
        strcpy(segundacartaselecionada, selecao);
} 

//Chamada para selecionar o trunfo
int RetornaTrunfoSelecionado(){     
    int selecao;
    printf("******************************\n");
    printf("Digite o trunfo que deseja selecionar: \n");
    printf("População: 1 \n");
    printf("Área: 2 \n");
    printf("PIB: 3 \n");
    printf("Número de pontos turísticos : 4 \n");
    printf("Densidade populacional: 5 \n");
    printf("PIB per capita: 6 \n");
    printf("Super Poder: 7 \n");
    scanf("%d",&selecao);
    return selecao;
} 


float RetornaSuperPoder(int _IndexEstado, int _IndexCidade){
    return cartas.Estados[_IndexEstado].Cartas[_IndexCidade].Populacao +
            cartas.Estados[_IndexEstado].Cartas[_IndexCidade].Area +
            cartas.Estados[_IndexEstado].Cartas[_IndexCidade].PIB +
            cartas.Estados[_IndexEstado].Cartas[_IndexCidade].PontosTuristicos +
            RetornaDencidadePopulacionalInvertida(_IndexEstado, _IndexCidade) +
            RetornaRendaPerCapita(_IndexEstado, _IndexCidade);             
}

int CompararCarta(){
    int trunfo;
    FazerCartaSelecionada(0);
    FazerCartaSelecionada(1);
    trunfo = RetornaTrunfoSelecionado();
    if (trunfo == 1){
        if (cartas.Estados[RetornaIndiceEstado(primeiracartaselecionada[0])].Cartas[(int) primeiracartaselecionada[2]].Populacao >
            cartas.Estados[RetornaIndiceEstado(segundacartaselecionada[0])].Cartas[(int) segundacartaselecionada[2]].Populacao)
            return 0;
        else
            return 1;
    }
    if (trunfo == 2){
        if (cartas.Estados[RetornaIndiceEstado(primeiracartaselecionada[0])].Cartas[(int) primeiracartaselecionada[2]].Area >
            cartas.Estados[RetornaIndiceEstado(segundacartaselecionada[0])].Cartas[(int) segundacartaselecionada[2]].Area)
            return 0;
        else
            return 1;
    }
    if (trunfo == 4){
        if (cartas.Estados[RetornaIndiceEstado(primeiracartaselecionada[0])].Cartas[(int) primeiracartaselecionada[2]].PontosTuristicos >
            cartas.Estados[RetornaIndiceEstado(segundacartaselecionada[0])].Cartas[(int) segundacartaselecionada[2]].PontosTuristicos)
            return 0;
        else
            return 1;
    }
    if (trunfo == 5){        
        if (RetornaDencidadePopulacional(primeiracartaselecionada[0], (int) primeiracartaselecionada[2]) < 
            RetornaDencidadePopulacional(segundacartaselecionada[0], (int) segundacartaselecionada[2]))
            return 0;
        else
            return 1;
    }
    if (trunfo == 6){        
        if (RetornaRendaPerCapita(primeiracartaselecionada[0], (int) primeiracartaselecionada[2]) < 
            RetornaRendaPerCapita(segundacartaselecionada[0], (int) segundacartaselecionada[2]))
            return 0;
        else
            return 1;
    }
    if (trunfo == 7){
        if (RetornaSuperPoder(primeiracartaselecionada[0], (int) primeiracartaselecionada[2]) > 
            RetornaSuperPoder(segundacartaselecionada[0], (int) segundacartaselecionada[2]))
            return 0;
        else
            return 1;
    }    
}

//Valida se pode cadastrar carta se o indice for menor que H então pode cadastrar mas se for igual valida se o indice da cidade é menor que 5
bool ValidaCadastrarCarta(){
    if (IndexEstado < 7)
        return true;
    else 
        return (IndexCidade < 4); 
}

int main() {
    //Variavel de controle de menu
    int ControleMenu = -1;

    //Loop do menu
    while (ControleMenu != 4)
    {
        Imprimircabecalho();
        scanf("%d",&ControleMenu);
        if (ControleMenu == 1){
            if (ValidaCadastrarCarta())
                CadastrarCarta();
            else    
                printf("Limite de cartas atingido!");
        }
        else if (ControleMenu == 2){
            if (CompararCarta() == 0)
                printf("Primeira Carta Ganhou!!!!");
            else
                printf("Segunda Carta Ganhou!!!!");
        }
        else if (ControleMenu == 3)
            ImprimirCartas();
    }
    return 0;
}
