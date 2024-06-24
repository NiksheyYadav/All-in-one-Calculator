#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdint.h>
#include<gmp.h>
#include<math.h>
#define size 2





struct normalCalculator{
    int count;
    float numbers[100];
    float sum, subt, prod, divi, avg;
    char o;
};

int main(){
    int i, j, k, n;
    int A[size][size];
    int B[size][size];
    int C[size][size];
    char o;
    char c;
    
    
    
    struct normalCalculator calc;
    
    
    printf("Which calculator you want to use Normal calculator or Matrix calculator?\n");
    printf("u = Normal calculator\nt = Matrix calculator\n");
    scanf("%c", &c);
    
    if (c == 'u'){
            
            printf("Enter the number of values: ");
            scanf("%d", &calc.count);
            
            printf("Enter the values: \n");
            for (i = 0; i < calc.count; i++){
                scanf("%f", &calc.numbers[i]);
            }
            
            printf("Enter the operation (+, -, *, /, a (average), e (tetration)): ");
            scanf(" %c", &calc.o);
            
            if (calc.o == '+') {
                calc.sum = 0;
                    
                for (i = 0; i < calc.count; i++ ) {
                    calc.sum += calc.numbers[i];
                }
                printf("The sum is: %0.2f", calc.sum);
            }
                
            else if (calc.o == '-') {
                calc.subt = calc.numbers[0];
                for (i = 0; i < calc.count; i++){
                    calc.subt -= calc.numbers[i];
                }
                printf("The sum is: %0.2f", calc.subt);
            }        
            if (calc.o == '*'){
                calc.prod = 1;
                for (i = 0; i < calc.count; i++){
                    calc.prod *= calc.numbers[i];
                }
                printf("The product is: %0.2f", calc.prod);
            }
            
            else if(calc.o == '/'){
                    if (calc.count >= 2) {
                        calc.divi = calc.numbers[0];
                        for (i = 1; i < calc.count; i++) {
                            if (calc.numbers[i] == 0) { 
                                printf("Error: Division by zero\n");
                                return 1; 
                            }
                            calc.divi /= calc.numbers[i];
                        }
                        printf("The division is: %.2f\n", calc.divi);
                    } else {
                        printf("Error: Not enough operands for division\n");
                    }
            }
            else if(calc.o == 'a'){
                calc.sum = 0;
                for (i = 0; i < calc.count; i++) {
                    calc.sum += calc.numbers[i];
                }
                calc.avg = calc.sum / calc.count;
                printf("The average is: %.2f\n", calc.avg);
            }
            else{
                printf("Invalid operation!!!\n");
            }
            
    }
    
    else if (c == 't'){
        
        printf("Enter an operation (+, -, *): ");
        scanf(" %c", &o);
        
        printf("\nEnter the values for the matrix A: \n");
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                scanf("%d", &A[i][j]);
            }
        }
        printf("Enter the values for the matrix B: \n");
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                scanf("%d", &B[i][j]);
            }
        }
            
            
            
            //ADDTION
        if ( o == '+'){
            printf("Performing addtion of matrices...\n");
                
            //OUTPUT Matrix C.
            
            for (i = 0; i < size; i++){
                for (j = 0; j < size; j++){
                    C[i][j] = A[i][j] + B[i][j];
                    printf("%d ", C[i][j]);
                }
                printf("\n");
            }
            
        }   //SUBTRACTION
            
        else if(o == '-'){
            printf("Performing subtraction of matrices...\n");
            
            //OUTPUT Matrix C.
            
            for (i = 0; i < size; i++){
                for (j = 0; j < size; j++){
                    C[i][j] = A[i][j] - B[i][j];
                    printf("%d ", C[i][j]);
                }
                printf("\n");
            }
        }
        
        //MULTIPLICATION
        else if ( o == '*'){
                printf("Performing multiplication of matrices...\n");
                for (i = 0; i < size; i++){
                    for (j = 0; j < size; j++){
                        C[i][j] = 0;
                        for (k = 0; k < size; k++){
                            C[i][j] += A[i][k] * B[k][j];
                        }
                        printf("%d ", C[i][j]);
                    }
                    printf("\n");
                }
                
        }

        //tetration
        else if ( o == 'e')
        {
            printf("Performing tetration: \n");

            long long int Tetration(int base, int po){
                signed long long int te;
                if ( po == 0){
                    return 1;
                }   else {
                    
                    te = base;
                    
                    for (int i = 1; i < po; i++){
                        te = pow(base, te);
                    }
            }
            
            return te;
            }

            int main(){
                signed long long int te;
                int base;
                int po;
                
                printf(
                    "Tetration is denoted in this program by the following format, i.e, base^^po. Where base is the number, '^^' denotes tetration, & po is the power by which the number is to be tetrated.\n"
                );
                
                printf("Enter the number(base): \n");
                scanf("%d", &base);
                
                printf("Enter the power: \n");
                scanf("%d", &po);
                
                te = Tetration(base, po);
                
                printf("%d^^%d =  %lld", base, po, te);
                
                return 0;
            }
        } 
        
        else{
            printf("Invalid operation!!!\n");
        }
    }
    
    else{
        printf("Invalid calculator choice!!!\n");
    }
    
    return 0;
}