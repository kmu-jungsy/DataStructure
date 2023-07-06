#include <iostream>
#define N 10
typedef char element;
using namespace std;

class ArrayList{
    element data[N];
    int size;
    public:
    void init();
    int is_empty();
    int is_full();
    element get_array(int pos);
    void print_array();
    void insert(int pos, element e);
    element delete_array(int pos);
};

void ArrayList::init(){
    size = 0;
}

int ArrayList::is_empty(){
    return size == 0;
}

int ArrayList::is_full(){
    return size == N;
}

element ArrayList::get_array(int pos){
    if(pos < 0 || pos > size){
        cout << "Wrong range";
        return 0;
    }
    else{
        return data[pos - 1];
    }
}

void ArrayList::print_array(){
    for(int i=0;i<size;i++)
        cout << data[i] << " ";
    cout << endl;
}

void ArrayList::insert(int pos, element e){
    if(pos < 0 || pos > size){
        cout << "Wrong range";
    }
    else{
        for(int i=size-1;i>=pos;i--){
            data[i+1] = data[i];
        }
        data[pos] = e;
        size++;
    }
}

element ArrayList::delete_array(int pos){
    if(pos < 0 || pos > size){
        cout << "Wrong range";
    }
    else{
        element e;
        e = data[pos - 1];
        for(int i = pos - 1; i < size - 1;i++){
            data[i] = data[i + 1];
        }
        size--;
        return e;
    }
}

int main(){
    ArrayList A;
    A.init();
    A.insert(0,'A'); A.insert(0,'B');
    A.insert(0,'C'); A.insert(1,'D');
    A.print_array();

    cout << "first data : " << A.get_array(1) << endl;;

    cout << A.delete_array(1) << " is deleted." << endl;
    A.print_array();
}