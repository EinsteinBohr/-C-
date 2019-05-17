#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T>
int partition(vector<T> &a,int left,int right){
    int pivot = left + rand()%(right - left + 1);
    int temp = a[pivot];
    int lo = left,ro = right;
    while(lo<ro){
        while(lo<ro && a[lo]<temp)lo++;
        while(lo<ro && a[ro]>temp)ro--;
        swap(a[lo++],a[ro--]);
        //移动指针，使可以继续进行，否则会死循环
    }
    return ro;
}

template<class T>
void quick_sort(vector<T> &a, int left, int right) 
{
    if(left<right){
        int mi = partition(a,left,right);
        quick_sort(a, left,mi);
        quick_sort(a, mi + 1, right);
    }
}

template<class T>
void swap(T &a,T &b)
{
    auto t = move(a);
    a = move(b);
    b = move(t);
}

int main() 
{
    srand(time(NULL));
    vector<int> a;
    for(int i = 0;i<10;i++){
        a.emplace_back(rand()%100);
    }
    // for(int i = 0;i<10;i++){
    //     cout<<a[i]<<endl;
    // }
    cout<<endl;
    clock_t t = clock();
    quick_sort(a,0,a.size() - 1);
    cout<<clock() - t<<endl;
    // for(int i = 0;i<10;i++){
    //     cout<<a[i]<<endl;
    // }
    system("pause");
    return 0;
}
