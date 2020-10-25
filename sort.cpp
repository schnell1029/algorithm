#include <iostream>
#include <vector>

void swap(int *a, int *b);
void bubbleSort(std::vector<int> *a);
void insertSort(std::vector<int> *a);


int main(){
    int a[10] = {3,1,4,1,5,9,2,6,5,3};
    std::vector<int> v(10,0);
    for(int i = 0; i < 10; i++){
        v.at(i) = a[i];
        std::cout << v.at(i) << " ";
    }

    std::cout << std::endl;
    insertSort(&v);
    for(int i = 0; i < 10; i++){
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void bubbleSort(std::vector<int> *a){
    int size = a->size();
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(a->at(i) > a->at(j)){
                swap(&a->at(i), &a->at(j));
            }
        }
    }
}

void insertSort(std::vector<int> *a){
    int size = a->size();
    for (int i = 1; i < size; i++){
        // numを挿入する場所jを探索する
        int num = a->at(i);
        int j = i;
        for(; j > 0; j--){
            if(a->at(j-1) > num){
                a->at(j) = a->at(j-1);
            }
            else break;
        }
    a->at(j) = num;
    }
}