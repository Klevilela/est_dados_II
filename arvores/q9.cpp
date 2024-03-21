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
        if (isdigit(e[i])) {
            s[j++] = e[i];
        } else if (strchr("+-*/", e[i])) {
            while (!vaziap(P) && prio(P->item[P->topo]) >= prio(e[i])) {
                s[j++] = desempilha(P);
            }
            empilha(e[i], P);
        } else if (e[i] == '(') {
            empilha('(', P);
        } else if (e[i] == ')') {
            while (P->item[P->topo] != '(') {
                s[j++] = desempilha(P);
            }
            desempilha(P); // Desempilha o '('
        }
    }

    while (!vaziap(P)) {
        s[j++] = desempilha(P);
    }

    s[j] = '\0';
    destroiP(&P);
    return s;
}



int valor(char *e) {
    Pilha P = pilha(256);

    for (int i = 0; e[i]; i++) {
        if (isdigit(e[i])) {
            empilha(e[i] - '0', P);
        } else {
            int y = desempilha(P);
            int x = desempilha(P);
            switch (e[i]) {
                case '+': empilha(x + y, P); break;
                case '-': empilha(x - y, P); break;
                case '*': empilha(x * y, P); break;
                case '/': empilha(x / y, P); break;
            }
        }
    }

    int resultado = desempilha(P);
    destroiP(&P);
    return resultado;
}


int main(){
    char expressao[30];
    cout << "Expressao infixa: ";
    cin >> expressao;

    char* posfixa_resultado = posfixa(expressao);
    int resultado = valor(posfixa_resultado);

    printf("Posfixa: %s\n\n", posfixa_resultado);
    printf("Valor: %d\n\n", resultado);

    
}