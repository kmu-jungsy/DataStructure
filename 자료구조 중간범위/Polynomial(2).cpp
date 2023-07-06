#include <iostream>
using namespace std;

char compare(int a, int b){
    if(a>b)
        return '>';
    else if(a<b)
        return '<';
    else
        return '=';
}

int main(){
    int coef[100];
    int expon[100];
    int avail = 6;
    int As = 0, Ae = 2, Bs = 3, Be = 5, Cs = avail, Ce;

    coef[0] = 8; coef[1] = 7; coef[2] = 1;
    coef[3] = 10; coef[4] = 3; coef[5] = 1;
    expon[0] = 3; expon[1] = 1; expon[2] = 0;
    expon[3] = 3; expon[4] = 2; expon[5] = 0;

    while(As <= Ae && Bs <= Be){
        if(compare(expon[As], expon[Bs]) == '>'){
            coef[avail] = coef[As];
            expon[avail++] = expon[As++];
        }
        else if(compare(expon[As], expon[Bs]) == '<'){
            coef[avail] = coef[Bs];
            expon[avail++] = expon[Bs++];
        }
        else{
            coef[avail] = coef[As] + coef[Bs++];
            expon[avail++] = expon[As++];
        }
    }

    for(; As <= Ae; As++){
        coef[avail] = coef[As];
        expon[avail++] = expon[As++];
    }
    for(; Bs <= Be; Bs++){
        coef[avail] = coef[Bs];
        expon[avail++] = expon[Bs++];
    }

    Ce = avail - 1;
    for(int i=Cs;i<Ce;i++){
        cout << coef[i] << "x^" << expon[i] << " + ";
    }
    cout << coef[Ce] << "x^" << expon[Ce];
}