#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <locale.h>

#define TAM_NOMES 10
#define TAMANHO 3
#define N_ESTRUTURAS 3

char can_nomes[TAM_NOMES];
int vetor_votos[TAMANHO];
int cores[TAMANHO];
int cand_numeros[TAMANHO];

typedef struct{
	char *nomes;
	int *votos;
	int *cor;
	int *numeros;
}Estruturas;

void candidatos(int numero);
void verificarEmpate(int cheque, Estruturas can[]);
void verificarEmpate_1(int cheque, Estruturas can[]);
void segundoTurno(int turno, int excluido, Estruturas cande[], int cand1, int cand2);
void carregando();
void carregando2();
int espetor2(int num, int excluido);
void Grafico(Estruturas card[], float ppc);
void limparBuffer();


void candidatos(int numero){
	if(numero == 10){
		printf("\n  \033[44m      #####      \033[0m  Se voce esta desempregado,\n");
          printf("  \033[44m    ##     ##    \033[0m  eh porque esta em um\n");
          printf("  \033[44m   #         #   \033[0m  momento sabatico. Aproveita,\n");
          printf("  \033[44m  #   #   #   #  \033[0m  o Brasil tambem esta\n");
          printf("  \033[44m  #           #  \033[0m  esperando por min.\n");
          printf("  \033[44m   #         #   \033[0m\n");
          printf("  \033[44m    ##     ##    \033[0m\n");
          printf("  \033[44m      #####      \033[0m\n");
          printf("  \033[44m     #######     \033[0m\n");
          printf("  \033[44m   ###########   \033[0m\n");
          printf("  \033[4;44m  #############  \033[0m\n\n");
          printf("  \033[4;44m  MESSI      10  \033[0m  \n\n");
	}
	else if(numero == 7){
		printf("\n  \033[45m      #####      \033[0m  Todo cidadao agora\n");
          printf("  \033[45m    ##     ##    \033[0m  paga imposto ate no\n");
          printf("  \033[45m   #         #   \033[0m  cafezinho. Porque, claro,\n");
          printf("  \033[45m  #   #   #   #  \033[0m  a gente precisa financiar\n");
          printf("  \033[45m  #           #  \033[0m  a incompetencia.\n");
          printf("  \033[45m   #         #   \033[0m\n");
          printf("  \033[45m    ##     ##    \033[0m  Mas comigo isso nao \n");
          printf("  \033[45m      #####      \033[0m  sera um realidade \n");
          printf("  \033[45m     #######     \033[0m  EU SOU O MILHOR \n");
          printf("  \033[45m   ###########   \033[0m\n");
          printf("  \033[4;45m  #############  \033[0m\n\n");
          printf("  \033[4;45m  CRISTIANO   7  \033[0m  \n\n");
	}
	else if(numero == 11){
		printf("\n  \033[41m      #####      \033[0m  Vamos resolver o \n");
          printf("  \033[41m    ##     ##    \033[0m  aquecimento global com\n");
          printf("  \033[41m   #         #   \033[0m  mais impostos sobre o\n");
          printf("  \033[41m  #   #   #   #  \033[0m  ar-condicionado. Se voce\n");
          printf("  \033[41m  #           #  \033[0m  esta quente a solucao eh \n");
          printf("  \033[41m   #         #   \033[0m  pagar mais\n");
          printf("  \033[41m    ##     ##    \033[0m\n");
          printf("  \033[41m      #####      \033[0m  Voce nunca esteve mais \n");
          printf("  \033[41m     #######     \033[0m  certo, quando decidiu\n");
          printf("  \033[41m   ###########   \033[0m  confiar em min\n");
          printf("  \033[4;41m  #############  \033[0m\n\n");
          printf("  \033[4;41m  NEYMAR     11  \033[0m  \n\n");
	}
}

int turnos = 1;
void verificarEmpate(int cheque, Estruturas can[]){ //VERIFICAR SE AH EMPATE
	
	if(cheque == 0){
		
		int i, j, cont = 0, Dfora;
		char simounao;
		turnos++;
		
		for(i = 0; i < 3 && cont == 0; i++){
			for(j = i + 1; j < 3; j++){
				if(can[i].votos[i] == can[j].votos[j]){
					
					printf("\n  Empate entre %s e %s \n", can[i].nomes, can[j].nomes);
					
					printf("\n  Deseja um segundo turno (s/n)? ");
					
					while(1){
						scanf(" %c", &simounao);
						
						if(simounao == 's'){
							
							if(i == 0 && j == 1 || i == 1 && j == 0){
								Dfora=2;
							}
							else if(i == 2 && j == 0 || i == 0 && j == 2){
								Dfora=1;
							}
							else{
								Dfora=0;
							}
							
							system("cls");
							segundoTurno(turnos, can[Dfora].numeros[Dfora], can, i, j);
							break;
							
						}else if(simounao == 'n'){
							
							printf("\n  Obrigado, continuara empate entao\n");
							break;
							
						}else{
							printf("\n  s ou n, tente novamente: ");
						}
				     }
					
					cont = 1;
				}
			}
		}
		
	}
}

void verificarEmpate_1(int cheque, Estruturas can[]) { // VERIFICAR SE HÁ EMPATE
     
	if (cheque == 0) {
          int i, j, cont = 0, Dfora;
          char simounao;
          turnos++;
        
        // Verifica se há exatamente dois candidatos empatados
          int empateDois = 0;
          int idx1 = -1, idx2 = -1;
        
          for (i = 0; i < 3; i++) {
               for (j = i + 1; j < 3; j++) {
                    if (can[i].votos[i] == can[j].votos[j]) {
                         if (empateDois == 0) {
                              idx1 = i;
                              idx2 = j;
                              empateDois = 1;
                         } else {
                        // Se já havia um empate registrado, significa que há mais de dois empatados
                        empateDois = 0;
                        break;
                        }
                    }
               }
               if (empateDois == 0) {
                    break;
               }
          }
        
          if (empateDois == 1) {
               printf("\n  Empate entre %s e %s \n", can[idx1].nomes, can[idx2].nomes);
               printf("\n  Deseja um segundo turno (s/n)? ");
            
               while (1) {
                    scanf(" %c", &simounao);
                    int k;
                    if (simounao == 's') {
                         for (k = 0; k < 3; k++) {
                              if (k != idx1 && k != idx2) {
                              Dfora = k;
                              break;
                              }
                         }
                    
                         system("cls");
                         segundoTurno(turnos, can[Dfora].numeros[Dfora], can, idx1, idx2);
                         break;
                    
                    } else if (simounao == 'n') {
                         printf("\n  Obrigado, continuará empate então\n");
                         break;
                    } else {
                         printf("\n  s ou n, tente novamente: ");
                    }
               }  
          }
     }
}

void apagarLinhasAcima(int linhas) {//           <FUNCAO AUXILIAR PARA O CARREGAMENTO (APAGA AS LINHAS)>
	int i;
     for (i = 0; i < linhas; i++) {
          printf("\033[F\033[K");
     }
}

void limparBuffer() {
     int c;
     while ((c = getchar()) != '\n' && c != EOF);
}

void Grafico(Estruturas card[], float ppc){
	
	char cor1_0[20]="\033[4;33;44m";
	char cor2_0[20]="\033[4;33;45m";
	char cor3_0[20]="\033[4;33;41m";
	char cor0[20]="\033[4;33;43m";
	char cor0_0[20]="\033[4;43m";
	
	char cor1[20]="\033[44m";
	char cor2[20]="\033[45m";
	char cor3[20]="\033[41m";
	
	int Neymar = ppc*card[2].votos[2];
	int Cristi = ppc*card[1].votos[1];
	int Messi = ppc*card[0].votos[0];
	
	printf("\n");
	
	printf("  \033[4;30;43m Grafico em %%:             \033[0m\n");
	printf("  \033[43m                           \033[0m\n");
	
	
	printf("  \033[43m 100_  \033[4m                 \033[0m\033[43m   \033[0m\n");
	
	printf("  \033[43m  90_  \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m\033[43m   \033[0m\n", Messi >= 100 ? cor1 : cor0_0, Cristi >= 100 ? cor2 : cor0_0, Neymar >= 100 ? cor3 : cor0_0);
	printf("  \033[43m  80_  \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m\033[43m   \033[0m\n", Messi >= 90 ? cor1 : cor0_0, Cristi >= 90 ? cor2 : cor0_0, Neymar >= 90 ? cor3 : cor0_0);
	printf("  \033[43m  70_  \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m\033[43m   \033[0m\n", Messi >= 80 ? cor1 : cor0_0, Cristi >= 80 ? cor2 : cor0_0, Neymar >= 80 ? cor3 : cor0_0);
	printf("  \033[43m  60_  \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m\033[43m   \033[0m\n", Messi >= 70 ? cor1 : cor0_0, Cristi >= 70 ? cor2 : cor0_0, Neymar >= 70 ? cor3 : cor0_0);
	printf("  \033[43m  50_  \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m\033[43m   \033[0m\n", Messi >= 60 ? cor1 : cor0_0, Cristi >= 60 ? cor2 : cor0_0, Neymar >= 60 ? cor3 : cor0_0);
	printf("  \033[43m  40_  \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m\033[43m   \033[0m\n", Messi >= 50 ? cor1 : cor0_0, Cristi >= 50 ? cor2 : cor0_0, Neymar >= 50 ? cor3 : cor0_0);
	printf("  \033[43m  30_  \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m\033[43m   \033[0m\n", Messi >= 40 ? cor1 : cor0_0, Cristi >= 40 ? cor2 : cor0_0, Neymar >= 40 ? cor3 : cor0_0);
	printf("  \033[43m  20_  \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m\033[43m   \033[0m\n", Messi >= 30 ? cor1 : cor0_0, Cristi >= 30 ? cor2 : cor0_0, Neymar >= 30 ? cor3 : cor0_0);
	printf("  \033[43m  10_  \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m%s   \033[0m\033[4;43m  \033[0m\033[43m   \033[0m\n", Messi >= 20 ? cor1 : cor0_0, Cristi >= 20 ? cor2 : cor0_0, Neymar >= 20 ? cor3 : cor0_0);
	
	printf("  \033[43m         \033[0m%s M \033[0m\033[43m  \033[0m%s C \033[0m\033[43m  \033[0m%s N \033[0m\033[43m     \033[0m\n", Messi >= 10 ? cor1_0 : cor0, Cristi >= 10 ? cor2_0 : cor0, Neymar >= 10 ? cor3_0 : cor0);
}

void tocarMusicaComemoracao() {
	
     Beep(880, 150);  
     Beep(988, 150);  
     Beep(1046, 150); 
     Beep(880, 150);  
     Beep(659, 150);  
     Beep(784, 150);  
     Beep(659, 150);  
     Beep(523, 150); 

     Beep(988, 200);  
     Beep(1175, 250); 
     Beep(1318, 300);  
}

void musicaEncerramento() {  

     Beep(784, 300); 
     Beep(880, 400);   
     Beep(1046, 500); 
}


void tocarMusicaIntroducao() {
    
     Beep(392, 300); 
	Sleep(50); 
     Beep(523, 300);
	Sleep(50);  
     Beep(659, 400);  
     Sleep(50);
     Beep(784, 500);
	Sleep(250);  
	
     Beep(880, 300); 
	Sleep(50); 
     Beep(784, 300);
	Sleep(50);  
     Beep(659, 300);  
     Sleep(50);
     Beep(523, 500);  
     Sleep(50);

    
     Beep(659, 300); 
	Sleep(50); 
     Beep(784, 300);
	Sleep(50);  
     Beep(988, 400); 
	Sleep(50); 
     Beep(1046, 700); 
     Sleep(50);
}

void tocarMusicaSegundoTurno() {
	
     Beep(392, 300); 
     Sleep(50); 
     Beep(523, 300);
     Sleep(50);  
     Beep(784, 400);  
     Sleep(50);
     Beep(988, 500);
     Sleep(250);  
    
     Beep(1046, 600);  
     Sleep(50);
}

void carregando() { //SIMBOLO DE CARREGANDO 1 TURNO
     
	int i;
     for(i = 0; i < 4; i++) {
        
          printf("\033[22;0H");
          printf("  \033[4mCARREGANDO.  \033[0m");
          Sleep(300);
        
          printf("\033[1K");  
          fflush(stdout);

          printf("\033[22;0H"); 
          printf("  \033[4mCARREGANDO.. \033[0m");
          Sleep(300);
        
          printf("\033[1K");
          fflush(stdout);
        
          printf("\033[22;0H");
          printf("  \033[4mCARREGANDO...\033[0m");
          Sleep(300);
        
          printf("\033[1K");
          fflush(stdout);
     }
}

void carregando2() { // SIMBOLO DE CARREGANDO: TRUNOS SEGUINTES
     
	int i;
     for(i = 0; i < 4; i++) {
        
          printf("\033[11;0H");
          printf("  \033[4mCARREGANDO.  \033[0m");
          Sleep(300);
        
          printf("\033[1K");  
          fflush(stdout);

          printf("\033[11;0H"); 
          printf("  \033[4mCARREGANDO.. \033[0m");
          Sleep(300);
        
          printf("\033[1K");
          fflush(stdout);
        
          printf("\033[11;0H");
          printf("  \033[4mCARREGANDO...\033[0m");
          Sleep(300);
        
          printf("\033[1K");
          fflush(stdout);
     }
}

int espetor2(int num, int excluido){ //EXPETOR: VERIFICAR SE O NUMERO E DE ALGUM CANDIDATO
	
	system("cls");
	int ept = 0;
	limparBuffer();
	
	Beep(1050, 200);
	
	if(num != excluido){
		
		if(num == 7 && num != excluido){
			printf("\n  \033[4;30;47m  SEU CANDIDATO  \033[0m\n");
			candidatos(num);
			ept = 1;
		}
		else if(num == 10 && num != excluido){
			printf("\n  \033[4;30;47m  SEU CANDIDATO  \033[0m\n");
			candidatos(num);
			ept = 1;
		}
		else if(num == 11 && num != excluido){
			printf("\n  \033[4;30;47m  SEU CANDIDATO  \033[0m\n");
			candidatos(num);
			ept = 1;
		}
	     else{
		     printf("  \033[4;40m                                                                                   \033[0m");
		     printf("\n  \033[4;41m Numero digitado incorreto, verifique os numeros dos candidatos e tente novamente. \033[0m\n  ");
		     Sleep(4000);
		     system("cls");
		     Beep(1050, 200);
	     }
	}
	else{
		printf("  \033[4;40m                                                                                   \033[0m");
		printf("\n  \033[4;41m Numero digitado incorreto, verifique os numeros dos candidatos e tente novamente. \033[0m\n  ");
		Sleep(4000);
		system("cls");
		Beep(1050, 200);
	}
	
	return ept;
}

void segundoTurno(int turno, int excluido, Estruturas cande[], int cand1, int cand2);

void main(){ //FUNÇÃO PRINCIPAL URNA 1
	
	int i = 0;
	
	Estruturas Candidatos[N_ESTRUTURAS];
	
	for(i = 0; i < N_ESTRUTURAS; i++){
		Candidatos[i].cor = cores;
		Candidatos[i].nomes = can_nomes;
		Candidatos[i].votos = vetor_votos;
		Candidatos[i].numeros = cand_numeros;
	}
	
	Candidatos[0].numeros[0] = 10;
	Candidatos[1].numeros[1] = 7;
	Candidatos[2].numeros[2] = 11;
	
	Candidatos[0].cor[0] = 44;
	Candidatos[1].cor[1] = 45;
	Candidatos[2].cor[2] = 41;
	
	Candidatos[0].nomes = "Messi";
	Candidatos[1].nomes = "Cristiano";
	Candidatos[2].nomes = "Neymar";
	
	int numero, espetor = 0, espetor3 = 0;
	int numero_de_votos = 0;
	char chave;
	float per;
	int j = 1, de_olho = 1;
	i = 0;
	
	do{ 
		
		inicio:
		system("cls");
			
		printf("  \033[4;40m                                                       \033[0m\n");
          printf("  \033[4;30;43m           BEM VINDO A URNA ELEITORAL FEDERAL          \033[0m\n");
          printf("  \033[40m                                                       \033[0m\n");
    
          if(j == 1){
          	tocarMusicaIntroducao();
          	j=0;
		}
    
          printf("  \033[4mCANDIDATOS:\033[0m\n\n");
          printf("  \033[44m      #####      \033[0m  \033[45m      #####      \033[0m  \033[41m      #####      \033[0m\n");
          printf("  \033[44m    ##     ##    \033[0m  \033[45m    ##     ##    \033[0m  \033[41m    ##     ##    \033[0m\n");
          printf("  \033[44m   #         #   \033[0m  \033[45m   #         #   \033[0m  \033[41m   #         #   \033[0m\n");
          printf("  \033[44m  #   #   #   #  \033[0m  \033[45m  #   #   #   #  \033[0m  \033[41m  #   #   #   #  \033[0m\n");
          printf("  \033[44m  #           #  \033[0m  \033[45m  #           #  \033[0m  \033[41m  #           #  \033[0m\n");
          printf("  \033[44m   #         #   \033[0m  \033[45m   #         #   \033[0m  \033[41m   #         #   \033[0m\n");
          printf("  \033[44m    ##     ##    \033[0m  \033[45m    ##     ##    \033[0m  \033[41m    ##     ##    \033[0m\n");
          printf("  \033[44m      #####      \033[0m  \033[45m      #####      \033[0m  \033[41m      #####      \033[0m\n");
          printf("  \033[44m     #######     \033[0m  \033[45m     #######     \033[0m  \033[41m     #######     \033[0m\n");
          printf("  \033[44m   ###########   \033[0m  \033[45m   ###########   \033[0m  \033[41m   ###########   \033[0m\n");
          printf("  \033[4;44m  #############  \033[0m  \033[4;45m  #############  \033[0m  \033[4;41m  #############  \033[0m\n\n");
          printf("  \033[4;44m  MESSI      10  \033[0m  \033[4;45m  CRISTIANO   7  \033[0m  \033[4;41m  NEYMAR     11  \033[0m\n\n");
          
          while(espetor == 0){
          	
			printf("  \033[4;30;47mNUMERO:");
          	scanf("%d", &numero);
          	printf("\033[0m");
          	Beep(1050, 200);
          	
          	if(numero == 2012 && numero_de_votos > 0){ //EXIBINDO RESULTADOS
          	
          	     /*
				votos:
				Neymar 11 = votos[2]
				
				Cristiano 7 = votos[1]
				
				Messi 10 = votos[0]
				*/
          		
				i=1;
			    	system("cls");                                                
			  	
			    	if(Candidatos[2].votos[2] > Candidatos[0].votos[0] && Candidatos[2].votos[2] > Candidatos[1].votos[1]){
			    		
	                	printf("\n  \033[4;30;47m     VENCEDOR    \033[0m\n");
	                	candidatos(11);
	                	tocarMusicaComemoracao();
				}
				else if(Candidatos[0].votos[0] > Candidatos[2].votos[2] && Candidatos[0].votos[0] > Candidatos[1].votos[1]){
					
	                	printf("\n  \033[4;30;47m     VENCEDOR    \033[0m\n");
	                	candidatos(10);
	                	tocarMusicaComemoracao();
				}
				else if(Candidatos[1].votos[1] > Candidatos[0].votos[0] && Candidatos[1].votos[1] > Candidatos[2].votos[2]){
					
	                	printf("\n  \033[4;30;47m     VENCEDOR    \033[0m\n");
	                	candidatos(7);
	                	tocarMusicaComemoracao();
				}else{
					de_olho = 0;
				}
				
				per = 100 / numero_de_votos;
				
				printf("\n");
				printf("  \033[4;30;43m  CANDIDATOS   |  VOTOS  |   %%   \033[0m\n");
				printf("  \033[4;30;43m  Messi        |    %d    |   %.0f   \033[0m\n", Candidatos[0].votos[0], per*Candidatos[0].votos[0]);
				printf("  \033[4;30;43m  Cristiano    |    %d    |   %.0f   \033[0m\n", Candidatos[1].votos[1], per*Candidatos[1].votos[1]);
				printf("  \033[4;30;43m  Neymar       |    %d    |   %.0f   \033[0m\n\n", Candidatos[2].votos[2], per*Candidatos[2].votos[2]);
				
				printf("  \033[4;30;47m  TOTAIS DE VOTOS: %d  \033[0m\n", numero_de_votos);
				
				//CHAMANDO GRAFICO DAS PORCENTAGENS:
				Grafico(Candidatos, per);
				
				//CHAMANDO A FUNÇAO PARA VERIFICAR SE HA EMPATE
				verificarEmpate_1(de_olho, Candidatos);
				break;
			}
          	
          	carregando();
          	
          	espetor = espetor2(numero, 1);
          	 
          	if(espetor != 1){ //VERIFICAR NUMERO DIGITADO
          		goto inicio;
			}else{
				while(1){
					
				     printf("  \033[4;30;47mDIGITE C PARA CONFIRMAR, N PARA CANCELAR: ");
				     
				     scanf(" %c", &chave);
          	          printf("\033[0m");
          	          Beep(1050, 200);
          	     
          	          if(chave == 'c' || chave == 'C'){ //CONTAGEM DE VOTO E CONFIRMACAO
          	          	
          	          	numero_de_votos++;
          	          	
          	          	if(numero == 11){
          	          		Candidatos[2].votos[2]++;
						}
					 	else if(numero == 10){
							Candidatos[2].votos[0]++;
						}
						else{
							Candidatos[1].votos[1]++;
						}
						printf("\n  \033[30;42m                 FINALIZADO                \033[0m");
						Sleep(2000);
						musicaEncerramento();
						break;
					}
					else if(chave == 'n' || chave == 'N'){
						limparBuffer();
						goto inicio;
					}
					else{
						printf("  \033[31m!ERRO! tente novamente\033[0m\n");
						limparBuffer();
					}
				}
			}
		}espetor=0;
          
	}while(i == 0);	
}

void segundoTurno(int turno, int excluido, Estruturas cande[], int cand1, int cand2){ //SEGUNDO TURNO

	int i;
	
	for(i = 0; i < N_ESTRUTURAS; i++){
		cande[i].votos[i] = 0;
	}
	
	int espetor = 0, espetor1 = 0,numero, numero_de_votos = 0, votos1 = 0, votos2 = 0;
	char chave;
	float per;
	int j = 0, de_olho = 1;
	i = 0;
	
	do{  inicio:
		espetor = 0;
		while(espetor == 0){
			
			system("cls");
			
			setlocale(LC_ALL, "");
	
	          printf("  \033[4;40m                                                       \033[0m\n");
               printf("  \033[4;30;43m           BEM VINDO A URNA ELEITORAL FEDERAL          \033[0m\n");
               printf("  \033[30;43m                       %d° TURNO                        \033[0m\n", turno);
               printf("  \033[40m                                                       \033[0m\n");
               
               if(j == 0){
				tocarMusicaSegundoTurno();
				j = 1;
			}
			
			printf("  \033[4mCANDIDATOS:\033[0m\n\n");
	
	          printf("  \033[4;%dm  %s     %d  \033[0m  \033[4;%dm  %s     %d  \033[0m\n\n", 
			cande[cand1].cor[cand1], cande[cand1].nomes, cande[cand1].numeros[cand1], 
			cande[cand2].cor[cand2], cande[cand2].nomes, cande[cand2].numeros[cand2]);
			
	          
	          printf("  \033[4;30;47mNUMERO:");
          	scanf(" %d", &numero);
               printf("\033[0m");
         	     Beep(1050, 200);
         	     
         	     if(numero == 2012 && numero_de_votos > 0){ //EXIBINDO RESULTADOS
          	
          	     /*
				votos:
				Neymar 11 = votos[2]
				
				Cristiano 7 = votos[1]
				
				Messi 10 = votos[0]
				*/
          		
				i=1;
			    	system("cls");                                                
			  	
			    	if(cande[cand1].votos[cand1] > cande[cand2].votos[cand2]){
			    		
	                	printf("\n  \033[4;30;47m     VENCEDOR    \033[0m\n");
	                	candidatos(cande[cand1].numeros[cand1]);
	                	tocarMusicaComemoracao();
				}
				else if(cande[cand2].votos[cand2] > cande[cand1].votos[cand1]){
					
	                	printf("\n  \033[4;30;47m     VENCEDOR    \033[0m\n");
	                	candidatos(cande[cand2].numeros[cand2]);
	                	tocarMusicaComemoracao();
				}
				else{
					de_olho = 0;
				}
				
				per = 100 / numero_de_votos;
				
				printf("\n");
				printf("  \033[4;30;43m  CANDIDATOS   |  VOTOS  |   %%   \033[0m\n");
				printf("  \033[4;30;43m  %s      |    %d    |   %.0f   \033[0m\n", cande[cand1].nomes, cande[cand1].votos[cand1], per*cande[cand1].votos[cand1]);
				printf("  \033[4;30;43m  %s      |    %d    |   %.0f   \033[0m\n\n", cande[cand2].nomes, cande[cand2].votos[cand2], per*cande[cand2].votos[cand2]);
				
				printf("  \033[4;30;47m  TOTAIS DE VOTOS: %d  \033[0m\n", numero_de_votos);
				
				Grafico(cande, per);
				
				verificarEmpate(de_olho, cande);
				break;
			}
          	     
         	     carregando2();
          	     
          	espetor = espetor2(numero, excluido);
          	
          	if(espetor == 0){
          		break;
			}
          	
          	while(1){
					
				printf("  \033[4;30;47mDIGITE C PARA CONFIRMAR, N PARA CANCELAR: ");
				     
				scanf(" %c", &chave);
          	     printf("\033[0m");
          	     Beep(1050, 200);
          	     
          	     if(chave == 'c' || chave == 'C'){ //CONTAGEM DE VOTO E CONFIRMACAO
          	          	
          	          numero_de_votos++;
          	          	
          	          if(numero == cande[cand1].numeros[cand1]){
          	          	cande[cand1].votos[cand1]++;
					}
					else{
						cande[cand2].votos[cand2]++;
					}
					printf("\n  \033[30;42m                 FINALIZADO                \033[0m");
					Sleep(2000);
					musicaEncerramento();
					break;
				}
				else if(chave == 'n' || chave == 'N'){
					limparBuffer();
					goto inicio;
				}
				else{
					printf("  \033[31m!ERRO! tente novamente\033[0m\n");
					limparBuffer();
				}
			}
			
		}
		
	}while(i == 0);
}

