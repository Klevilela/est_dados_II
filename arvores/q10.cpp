#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "./pilhaIncompleta.h"
#include <iostream>
using namespace std;


int prio(char o){
    switch (o)
    {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*': 
        case '/': return 2;
    
    }
    return -1;
}

char *posfixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);

    for (int i = 0; e[i]; i++) {
        if (e[i] == '(') {
            empilha('(', P);
        } else if (isdigit(e[i]) || e[i] == '.'){
            s[j++] = e[i];
            if(e[i] == '.'){
                while (isdigit(e[i + 1])) {
                    s[j++] = e[++i];
                }
            }
        } 
        else if(strchr("+*-/", e[i])){
            s[j++] = ' ';
            while (!vaziap(P) && prio(P->item[P->topo]) >= prio(e[i])) {
                s[j++] = desempilha(P);
            }
            empilha(e[i], P);
        
        } else if (e[i] == ')') {
            while (P->item[P->topo] !='('){
                s[j++] = desempilha(P);
                desempilha(P);
            }   
        }
    }

    while (!vaziap(P)) {
        s[j++] = desempilha(P);
    }

    s[j] = '\0';
    destroiP(&P);
    return s;
}



float valor(char *e) {
    Pilha P = pilha(256);

    for (int i = 0; e[i]; i++) {
        if (isdigit(e[i])) {
            empilha(atof(e+i), P);
            while (isdigit(e[i+1]) || e[i+1] == '.'){
                i++;
            }
            
        } else if(strchr("+*-/", e[i])){
            float y = desempilha(P);
            float x = desempilha(P);
            switch (e[i]) {
                case '+': empilha(x + y, P); break;
                case '-': empilha(x - y, P); break;
                case '*': empilha(x * y, P); break;
                case '/': empilha(x / y, P); break;
            }
        }
    }

    float resultado = desempilha(P);
    destroiP(&P);
    return resultado;
}


int main(){
    char expressao[30];
    //string expressao;
    cout << "Expressao infixa: ";
    
    //getline(cin, expressao);
    cin >> expressao;

    //char* posfixa_resultado = posfixa(expressao);
    char* posfixa_resultado = posfixa(expressao);
    float resultado = valor(posfixa_resultado);

    printf("Posfixa: %s\n\n", posfixa_resultado);
    printf("Valor: %f\n\n", resultado);

}