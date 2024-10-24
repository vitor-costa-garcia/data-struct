#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size; i++){              // O segundo for loop não precisa ser até o tamanho do array, visto que cada iteração do primeiro loop o maior
        for(int j = 0; j < size - i - 1; j++){  // número vai pro final do array, portanto não é necessário verificá-lo. O -1 é necessário pois é verificado o atual e o seu sucessor.
            if(arr[j] > arr[j+1]){
                int temp = arr[j];  // Se o elemento da esquerda for maior que o da direita
                arr[j] = arr[j+1];  // Troque-os de posição
                arr[j+1] = temp;
            }
        }
    }
};  

int main(){
    srand(time(0));      //Seed para a geração de valores aleatórios

    int nums[20];                  //Gerando array com 20 números aleatórios de 0 a 200
    for(int i = 0; i < 20; i++){
        nums[i] = rand() % 200;
    }

    bubbleSort(nums, 20);          //Executando algoritmo de ordenação

    for(int i = 0; i < 20; i++){
        cout << nums[i] << ' ';  //Exibindo o resultado
    }

}