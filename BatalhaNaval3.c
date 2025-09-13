#include <stdio.h>

int main() {

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.


    
    //Tabuleiro 5x5  //TabuleiroA para não conflitar com TabuleiroB do nivel aventureiro e não gerar confusão ao rever o código
    int tabuleiroA[5][5] = {0}; // iniciliazindo com 0 para representar água

    //navio na vertical
    int linhaVert = 1;  // linha na qual começará o navio
    int colunaVert = 2; // coluna fixa devido a orientação do navio
    int TamanhoNavio = 3;   // tamanho 3 para os navios, baseado nos exemplos das aulas

    for (int i = 0; i < TamanhoNavio; i++) {
        tabuleiroA[linhaVert + i][colunaVert] = 1; // marca o navio
    }

    //navio horizontal 
    int linhaHori = 4;  // linha fixa fixa devido a orientação do navio
    int colunaHori = 0; // coluna onde começa o navio
    for (int j = 0; j < TamanhoNavio; j++) { //navio tamanho 3
        tabuleiroA[linhaHori][colunaHori + j] = 1; // marca o navio
    }


    //para alterar posições dos navios:
    //linha_vert = 1, coluna_vert = 3:  navio vertical começando na linha 1, coluna 3
    //linha_hor = 2, coluna_hor = 0: navio horizontal começando na linha 2, coluna 0
    //basta alterar os numeros levando em consideração a matriz de tamanho 5x5

    printf("\nBatalha Naval - Nível Novato\n");

    //Coordenadas do navio na vertical
    printf("Coordenadas do navio vertical:\n"); //impressão para usuário
    
    for (int i = 0; i < 5; i++) {        // for (inicialização, condição, incremento) i=linhas+incremento
        for (int j = 0; j < 5; j++) {    // J= colunas+ incremeto
            if (tabuleiroA[i][j] == 1 && j == colunaVert && i >= linhaVert && i < linhaVert + TamanhoNavio) { //tabuleiroA[i][j] == 1: verifica se há navio no local, 
                printf("(%d,%d)\n", i, j); //j == colunaVert: coluna do navio na vertical  //i >= linhaVert && i < linhaVert + TamanhoNavio: para garantir estar dentro das linhas ocupadas pelo navio
        }
    }
    }

    // Coordenadas do navio na horizontal
    printf("\nCoordenadas do navio horizontal:\n"); //impressão
    for (int i = 0; i < 5; i++) {        // percorre linhas
        for (int j = 0; j < 5; j++) {    // percorre colunas
            if (tabuleiroA[i][j] == 1 && i == linhaHori && j >= colunaHori && j < colunaHori + TamanhoNavio) { //equivalente ao anterior, porem mudando os paramatros
                printf("(%d,%d)\n", i, j);
            }
        }
    }
    
    printf("\n"); //espaçamento na impressão (estética + claridade)

    //print extra para ilustrar o nível novato
    //Não requerido pelo nivel novato

    printf("Tabuleiro 5x5 (0 - Representa Água, 1 - Representa Navio):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", tabuleiroA[i][j]);
        }
        printf("\n");
    }
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.


    printf("\nBatalha Naval - Nível Aventureiro\n");
    printf("\nCampo Naval:\n");

    int tabuleiroB[10][10] = {0}; // Matriz 10x10 //inicializando com zero = água
    

    //Área preenchida com 0=água
    //I e J =Linhas, Colunas
    //navios com tamanho 3, baseado nas aulas
   
    for (int i = 0; i < 10; i++) { //loop externo, condição, incremento 
        for (int j = 0; j < 10; j++) {//interno
            tabuleiroB[i][j] = 0;
        }
    }

    // Navio na vertical
    for (int i = 7; i < 10; i++) {  //i=0 para inicio da linha, usar de 0-9 e garantir que o menor seja levando em conta Ex: 0 < 3 ou  3 < 6
        tabuleiroB[i][3] = 3; //usar 0-9 para mudar a coluna onde começa.
    }
    // Navio na horizontal
    for (int j = 2; j < 5; j++) {  //0= inicio 
        tabuleiroB[5][j] = 3; //0= inicio
    }

    // Navio na diagonal: Topo - esquerda para direita - 
    for (int x = 0; x < 3; x++) { //0 inicio linha
        tabuleiroB[x][x] = 3; //0 = inico coluna
    }

    //Navio diagonal: - direita para esquerda
    for (int x = 1; x < 4; x++) { //0 inicio linha
       tabuleiroB[x][9 - x] = 3;  //0 inicio coluna
    }

    // Print da batalha/tabuleiro
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiroB[i][j]); //imprime a linhas e colunas da matriz
        }
       printf("\n"); //espaçamento
    }

  //Habilidades Especiais // Nomes de armas talvez? Tactical Nuke, Air-burst, Minas, Misseis de cruzeiro, Drones?  
    
    printf("\nBatalha Naval - Nível Mestre");
    printf("\nDemonstração da Área de Ataque das Habilidades Especiais\n");

    // Especial Cone //bom e velho sinalizador do transito
    //representação com Numero 1 para diferenciar dos navios
    printf("\nCone:\n");
    int cone[3][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1}
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n"); //se não adicionar impressão ficará em apenas uma linha
    }

    //Especial Octaedro  // um poliedro com 8 faces e que pode ser regular, sendo um dos Sólidos de Platão, ou irregular
    //lembra 2 piramides coladas pelas bases //basicamente um balão de festa junina
    printf("\nOctaedro:\n");
    int octaedro[3][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", octaedro[i][j]);
        }
        printf("\n"); //se não adicionar impressão ficará em apenas uma linha
    }

    //Especial Cruz //Audentes Fortuna Iuvate
    printf("\nCruz:\n");
    int cruz[3][5] = {
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0}
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", cruz[i][j]);
        }
        printf("\n"); //se não adicionar impressão ficará em apenas uma linha
    }
        printf("\n");//espaçamento na finalização do programa //não ficar junto ao user após finalizar a run

    return 0;

}
