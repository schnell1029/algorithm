#include <iostream>
#include <vector>

void printVec(std::vector<int> a);
void swap(int *a, int *b);
void bubbleSort(std::vector<int> *a);
void insertSort(std::vector<int> *a);
void pushdown(std::vector<int> *a, int first, int last);
void heapSort(std::vector<int> *a);


int main(){
    int a[10] = {3,1,4,1,5,9,2,6,5,3};
    std::vector<int> v(10,0);
    for(int i = 0; i < 10; i++){
        v.at(i) = a[i];
        std::cout << v.at(i) << " ";
    }

    std::cout << std::endl;
    heapSort(&v);
    printVec(v);
    return 0;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}


void printVec(std::vector<int> a){
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << a.at(i) << " ";
    }
    std::cout << std::endl;
    
}

void pushdown(std::vector<int> *a, int first, int last){ //トップダウン式にヒープを作成する
    int parent = first; //親
    int child = 2 * parent + 1; //左の子
    while(child < last){
        if((child < last-1) && (a->at(child) < a->at(child+1))){
            child++;
        }
        if(a->at(child) <= a->at(parent)){
            break;
        }
        else{
            swap(&a->at(child), &a->at(parent));
            parent = child;
            child = 2 * parent + 1;
        }
    }
}

void heapSort(std::vector<int> *a){
    int size = a->size();
    for( int i = (size-1)/2; i >= 0; i--){
        pushdown(a, i, size);

    }
    for( int i = size-1; i>= 2; i--){
        swap(&a->at(0), &a->at(i));
        pushdown(a, 0, i);
    }
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