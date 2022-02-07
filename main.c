#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
	
	int i, j;    
	int x, y;
	int det;                 
	double sis[2][3], solucao[2],temp[2][3], coef_10; 
	
	printf("Entre com os coeficientes do sistema de 2 incognitas: \n");
	printf("Ex.: Ax + By = C \n");
	printf("     [0,0]= A; [0,1]= B, [0,2]= C \n\n");
	
	for (i = 0; i < 2; i++) {
  		for (j = 0; j < 3; j++) {
    		printf(" [%d:%d] = ", i, j);
    		scanf("%lf", &sis[i][j]);
  		}
	}
	
	if(sis[0][0] == 0){
		temp[0][0] = sis[1][0];	sis[1][0] = sis[0][0]; sis[0][0] = temp[0][0];
		temp[0][1] = sis[1][1];	sis[1][1] = sis[0][1]; sis[0][1] = temp[0][1];
		temp[0][2] = sis[1][2];	sis[1][2] = sis[0][2]; sis[0][2] = temp[0][2];
	}
	
	printf("\n Matriz aumentada:\n");
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
   			printf(" %5.2lf ", sis[i][j]);
		}
 	printf("\n");
	}
	
	printf("\n");
	
	det = (sis[0][0] * sis[1][1]) - (sis[0][1] * sis[1][0]);
	
	if(det != 0){
				
		coef_10 = -1.0 * sis[1][0] / sis[0][0];
		printf("Coeficiente:  %5.2lf ", coef_10 );
		printf("\n");
		
		for (j = 0; j < 4; j++) {
  				sis[1][j] += coef_10 * sis[0][j];
			}
	
		printf("\n");
		printf(" Matriz resultante:\n");
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 3; j++) {
   				printf(" %5.2lf ", sis[i][j]);
			}
 		printf("\n");
		}
	
		solucao[1] = (sis[1][2]) / sis[1][1];
		solucao[0] = (sis[0][2] - (solucao[1] * sis[0][1])) / sis[0][0];
		
		printf("\n Resulados do sistema (x,y): \n");
		printf(" {(%5.2lf %5.2lf)}", solucao[0], solucao[1]);
		
	} else if (det == 0){
		printf("\n O Sistema eh SPI ou SI. Nao foi possivel resolver o Sistema.");		
	}	
	
	return 0;
}
