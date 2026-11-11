#include <stdio.h>

int binary_calculator(int array_function[],int size_function,int target_number_function){
     int low = 0; 
     int high = size_function - 1;
     int mid = 0, guess = 0;
     int looping = 0;

    printf("\nFora do loop:\nLow -> %d (indice)\nHigh -> %d (indice)\nMid -> %d (indice)\nGuess -> %d (valor do elemento)\n",low,high,mid,guess);

    while(low <= high){
    mid = (low + high) / 2; 
    guess = array_function[mid];
    looping =  looping + 1;
    printf("\nLooping %d:\n",looping);
    printf("Mid -> %d (indice)\nGuess -> %d (valor do elemento)\n",mid,guess);

    if(guess == target_number_function){
    return mid;
    }
        if(guess < target_number_function){
        low = mid + 1;
        }
            if(guess > target_number_function){
            high = mid - 1;
                }

    printf("Low -> %d (indice)\nHigh -> %d (indice)\n",low,high);
        }

    return -1;
}

int main(){
    int size = 0;
    int target_number = 0;

    printf("Escolha o tamanho de seu array:\n");
    scanf("%d",&size);
    int array[size];

    for(int i = 0; i < size;i++){
        array[i] = i + 1;
    }

    printf("Escolha o seu target_number:\n");
    scanf("%d",&target_number);

    int resultado = binary_calculator(array,size,target_number);

    printf("\n");

    if (resultado == target_number - 1){
    printf("O número foi encontrado na lista\n");

    }
        else if (resultado == -1){
        printf("O número não foi encontrado na lista\n");
        }
        else{printf("seu código tá podre\n");}
}