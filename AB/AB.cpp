// Дани два масиви: А[M] і B[N] (M і N вводяться з клавіатури).Необхідно створити третій масив мінімально можливого розміру, у якому потрібно зібрати
//елементи масиву A, які не включаються до масиву B, без повторень.

#include <iostream>
#include<ctime>
using namespace std;
void inputArr(int* arr, int size) {//фукція заповення рандомними значеннями  динамiчного масиву 
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 20;

    }
}
void printArr(int* arr, int size) {//функція виводу масивів 
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
}
void SortAnoB(int* A, int m, int* B, int n, int*& C, int& NM) {//функція збору елементів в масив С з масиву А яких нема в масиві В 
    int ii = 0;//лічильник
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i] == B[j]) {//перевірка чи значеня масиву А є в масиві В
                break;
            }
            else if (j == n - 1) {//перевірка чи перевірені всі значення
                C[ii] = A[i];//запис в масив С елемента з масиву А
                ii++;
               

            }
        }
    }
     NM = ii;//розмір нового масиву С
}
void arr_uniq(int* C, int& NM)//функція вилучення повторювальних значень із 3-го масиву
{
    for (int i = 0; i < NM; i++)
    {
        for (int j = 0; j < NM; j++)
        {
            if (i != j)//перевірка чи ми не порівнюємо значення масиву під одним індексом 
            {
                if (C[i] == C[j])//перевірка чи знайшлись подібні едементи 
                {
                    swap(C[NM - 1], C[j]);//стираємо подібний елемент
                    NM--;//зменшуємо розмір масиву оскільки видалили повторюваний елемент
                }
            }
        }
    }
}
int main()
{
    srand(time(NULL));
    setlocale(0, "");
    int n = 1, m = 1;
    cout << "Введіть розмір масиву А, m = " ;
    cin >> m ;
    cout << "Введіть розмір масиву B, n = " ;
    cin >> n;
    int NM = m;
    int* A = new int[m]; //виділення динамічної пам'яті
    int* B = new int[n];
    int* C = new int[NM];
    
    inputArr(A, m);//фукція заповення рандомними значеннями  динамiчного масиву 
    cout << "\t\t\t\tПерший масив\n "<<endl;
    printArr(A, m);//функція виводу масивів 
    cout << endl;
    inputArr(B, n);//фукція заповення рандомними значеннями  динамiчного масиву
    cout << "\t\t\t\tДругий масив\n " << endl;
    printArr(B, n);//функція виводу масивів 
    SortAnoB(A, m, B, n, C, NM);//функція збору елементів в масив С з масиву А яких нема в масиві В 
    arr_uniq(C, NM);//функція вилучення повторювальних значень із 3-го масиву
    cout << endl;
    cout <<"\t\t\t\tТретій масив\n " << endl;
    printArr(C, NM);//функція виводу масивів 
    delete[] A;//видалення дин.масиву
    delete[] B;
    delete[] C;
}



