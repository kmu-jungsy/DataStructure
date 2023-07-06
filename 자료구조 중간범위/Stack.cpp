#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class Stack{
    char stack[MAX];
    int top;
    public:
    void init();
    int is_full();
    int is_empty();
    void push(char c);
    char pop();
    char peek();
    int check(string s);
    int postfix(string s);
    string convert(string s);
};

void Stack::init(){
    top = -1;
}

int Stack::is_full(){
    return top == MAX - 1;
}

int Stack::is_empty(){
    return top == -1;
}

void Stack::push(char c){
    if(!is_full())
        stack[++top] = c;
}

char Stack::pop(){
    if(!is_empty())
        return stack[top--];
}

char Stack::peek(){
    if(is_empty()){
        return 0;
    }
    else{
        return stack[top];
    }
}

int Stack::check(string s){
    int len = s.length();
    char c;
    for(int i=0;i<len;i++){
        c = s[i];
        switch(c){
            case '(':
            case '{':
            case '[':
                push(c);
                break;
            case ')':
                if(peek() == '(')
                    pop();
                else    
                    return 0;
                break;
            case '}':
                if(peek() == '{')
                    pop();
                else    
                    return 0;
                break;
            case ']':
                if(peek() == '[')
                    pop();
                else    
                    return 0;
                break;
            default:
                continue;
        }
    }
    if(is_empty())
        return 1;
    else    
        return 0;
}

int Stack::postfix(string s){
    int len = s.length();
    int n1, n2;
    char c;

    for(int i=0;i<len;i++){
        c = s[i];
        switch(c){
            case '+':
                n1 = pop() - '0';
                n2 = pop() - '0';
                push((n1+n2) + '0');
                break;
            case '-':
                n1 = pop() - '0';
                n2 = pop() - '0';
                push((n2-n1) + '0');
                break;
            case '*':
                n1 = pop() - '0';
                n2 = pop() - '0';
                push((n1*n2) + '0');
                break;
            case '/':
                n1 = pop() - '0';
                n2 = pop() - '0';
                push((n2/n1) + '0');
                break;
            default:
                push(c);
                break;
        }
    }
    n1 = pop() - '0';
    return n1;
}

int prec(char c){
    if(c=='(' || c==')')
        return 0;
    else if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    return -1;
}

string Stack::convert(string s){
    string s2 = "", s3;
    int len;
    char c, a;
    len = s.length();
    for(int i=0;i<len;i++){
        c = s[i];
        switch(c){
            case '(':
                push(c);
                break;
            case ')':
                while(peek() != '('){
                    a = pop();
                    s3 = a;
                    s2.append(s3);
                }
                pop();
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while(prec(c) <= prec(peek())){
                    a = pop();
                    s3 = a;
                    s2.append(s3);
                }
                push(c);
                break;
            default:
                s3 = c;
                s2.append(s3);
                break;
        }
    }
    while(!is_empty()){
        c = pop();
        s3 = c;
        s2.append(s3);
    }
    return s2;
}

int main(){
    Stack S;
    string s, s2;
    S.init();
    cin >> s;
    s2 = S.convert(s);
    cout << s2;
}