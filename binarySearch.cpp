#include <iostream>

using namespace std;

int binarySearch(int myarr[], int size, int num){
    int l = 0;
    int r = size-1;
    int mid;

    while(l <= r){
        mid = (l+r)/2;
        if(myarr[mid] == num){
            return mid;
        } else if (myarr[mid] < num){
            l = mid + 1; // +1 para deconsiderar o ponto MID anterior, já que não houve match
        } else if (myarr[mid] > num){
            r = mid - 1; // -1 para deconsiderar o ponto MID anterior, já que não houve match
        }
    }

    return -1;
}

int main(){
    srand(time(0));      //Seed para a geração de valores aleatórios.

    int nums[20];
    int n;
    int result;

    cout << "[ ";
    for(int i = 0; i < 20; i++){
        nums[i] = (rand() % 20) + (i * 20);  //Gerando array com 20 números aleatórios de 0 a 400 de forma crescente e imprimindo-o.
        cout << nums[i] << ' ';
    }
    cout << ']' << endl;

    cin >> n;  // Escolher um número para teste

    result = binarySearch(nums, 20, n);  //Salva o índice de n na variável result e exibe-o se for encontrado.
    result == -1 ? cout << "Nao foi encontrado." : cout << result;

}