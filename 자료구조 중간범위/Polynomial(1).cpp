#include <iostream>
#include <algorithm>
#define N 10
using namespace std;

class polynomial {
    private:
    int degree;
    int coef[N];
    public:
    polynomial(int _degree, int _coef[]){
        degree = _degree;
        for(int i=0;i<=degree;i++)
            coef[i] = _coef[i];
    }
    polynomial(polynomial* a, polynomial* b){
        int apos=0, bpos=0, cpos=0;
        int a_degree = a->degree;
        int b_degree = b->degree;
        this->degree = max(a->degree, b->degree);
        while(apos <= a->degree && bpos <= b->degree){
            if(a_degree > b_degree){
                coef[cpos++] = a->coef[apos++];
                a_degree--;
            }
            else if(a_degree < b_degree){
                coef[cpos++] = b->coef[bpos++];
                b_degree--;
            }
            else{
                coef[cpos++] = a->coef[apos++] + b->coef[bpos++];
                a_degree--; b_degree--;
            }
        }
    }
    void print_ploy(){
        for(int i=this->degree;i>0;i--)
            cout << this->coef[this->degree - i] << "x^" << i << " + ";
        cout << this->coef[degree] << endl;
    }
};

int main(){
    int a_coef[] = {3,6,0,0,0,10};
    int b_coef[] = {7,0,5,0,1};
    polynomial a(5, a_coef);
    polynomial b(4, b_coef);
    a.print_ploy();
    b.print_ploy();
    polynomial c(&a,&b);
    c.print_ploy();
}