#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <stack>
using namespace std;
class No
{
public:
	int valor;
	No *left;
	No *right;
	No(int n)
	{
		valor = n;
		left = NULL;
		right = NULL;
	}
};

class Arvore
{
public:
	No *raiz;
	int quantNos;
	int h;
	Arvore()
	{
		raiz = NULL;
		quantNos = 0;
		h = -1;
	}

	int isEmpty()
	{
		return (raiz == NULL);
	}

	void criaNo(char n)
	{
		No *novo = new No(n);
		inserirSemRecursao(raiz, novo);
		// inserirComRecursao(raiz, novo);
	}

	void inserirSemRecursao(No *arv, No *n)
	{
		if (isEmpty())
		{
			raiz = n;
		}

		else
		{
			No *atual = raiz;
			No *anterior = NULL;

			while (atual != NULL)
			{
				anterior = atual;

				if (n->valor < atual->valor)
				{
					atual = atual->left;
				}
				else
				{
					atual = atual->right;
				}
			}

			if (n->valor < anterior->valor)
			{
				anterior->left = n;
			}
			else
			{
				anterior->right = n;
			}
		}

		quantNos++;
		h++;
	}
	void inserirComRecursao(No *arv, No *n)
	{
		if (isEmpty())
			raiz = n;
		else
			inserirComRecursaoRecursivo(raiz, n);

		quantNos++;
		h++;
	}

	void inserirComRecursaoRecursivo(No *atual, No *n)
	{
		if (n->valor < atual->valor)
		{
			if (atual->left == NULL)
			{
				atual->left = n;
			}
			else
			{
				inserirComRecursaoRecursivo(atual->left, n);
			}
		}
		else
		{
			if (atual->right == NULL)
			{
				atual->right = n;
			}
			else
			{
				inserirComRecursaoRecursivo(atual->right, n);
			}
		}
	}

	int calculaqtdNos(No *arv)
	{
		return quantNos;
	}

	int calculaAlturaArvore(No *arv)
	{
		int h_esq = 1;
		int h_dir = 1;
		int maior_h;

		if (arv == NULL)
		{
			return h;
		}
		else
		{
			if (arv->left != NULL)
			{
				calculaAlturaArvore(arv->left);
				h_esq++;
			}
			if (arv->right != NULL)
			{
				calculaAlturaArvore(arv->right);
				h_dir++;
			}

			if (h_esq > h_dir)
			{
				maior_h = h_esq;
				cout << maior_h << endl;
			}
			else if (h_dir > h_esq)
			{
				maior_h = h_dir;
				// cout << maior_h << endl;
			}
			else
			{
				maior_h = h_esq;
				// cout << maior_h << endl;
			}

			return maior_h;

			// cout << maior_h << endl;
		}
	}

	int arvcompleta()
	{
		int altura = calculaAlturaArvore(raiz);
		int maxNos = pow(2, altura + 1) - 1;

		return maxNos;
	}

	int arvcheia()
	{
		int altura = calculaAlturaArvore(raiz);
		return (altura == arvcompleta()) ? 1 : 0;
	}

	void preordem(No *n)
	{
		if (n != NULL)
		{
			cout << n->valor << " ";
			preordem(n->left);
			preordem(n->right);
		}
	}

	void posordem(No *n)
	{
		if (n != NULL)
		{
			preordem(n->left);
			preordem(n->right);
			cout << n->valor << " ";
		}
	}

	void inordem(No *n)
	{
		if (n != NULL)
		{
			preordem(n->left);
			cout << n->valor << " ";
			preordem(n->right);
		}
	}
	/*busca sem recursao*/
	int buscaSemRecursao(No *p, int valor){
		
		while (p != NULL)
		{
			if (p->valor == valor)
			return 1;
			else if (valor < p->valor)
			{
				p = p->left;
			}else{
				p = p->right;
			}
			
		}

		return 0;
	}

    /*pos ordem sem recursao*/
    void posordemsemrecurssao(No *root) {
    if (root == NULL)
        return;

    stack<No*> pilha1;
    stack<No*> pilha2;

    pilha1.push(root);

    while (!pilha1.empty()) {
        No* atual = pilha1.top();
        pilha1.pop();
        pilha2.push(atual);

        if (atual->left)
            pilha1.push(atual->left);

        if (atual->right)
            pilha1.push(atual->right);
    }

    while (!pilha2.empty()) {
        cout << pilha2.top()->valor << " ";
        pilha2.pop();
    }
}
    
	/*no minimo*/
	void removeNoMinimo()
    {
        if (raiz == NULL) 
            return;

        No *atual = raiz;
        No *anterior = NULL;

        while (atual->left != NULL)
        {
            anterior = atual;
            atual = atual->left;
        }

        if (anterior == NULL)
        {
            raiz = atual->right;
        }
        else
        {
            anterior->left = atual->right;
        }

        delete atual;
        quantNos--;
    }
};

int main()
{
	Arvore *arvore = new Arvore();

	arvore->criaNo(100);
	arvore->criaNo(70);
	arvore->criaNo(40);
	arvore->criaNo(80);
    arvore->criaNo(110);


	arvore->preordem(arvore->raiz);
	cout << endl;

    arvore->posordemsemrecurssao(arvore->raiz);
    cout << endl;
	/*arvore->posordem(arvore->raiz);
	cout << endl;
	arvore->inordem(arvore->raiz);
	cout << endl;
	arvore->calculaqtdNos(arvore->raiz);
	cout << endl;
	arvore->calculaAlturaArvore(arvore->raiz);*/
	/*cout << arvore->buscaSemRecursao(arvore->raiz, 1) << endl;
	cout << arvore->buscaSemRecursao(arvore->raiz, 100) << endl;*/
	/*arvore->preordem(arvore->raiz);
	cout<<endl;
	arvore->removeNoMinimo();
	arvore->preordem(arvore->raiz);*/
	/* No *raiz = new No(5);
	No *no_1 = new No(2);
	No *no_2 = new No(6);

	cout << arvore->isEmpty() << endl;
	arvore->inserirSemRecursao(arvore->raiz, raiz);

	cout << arvore->isEmpty() << endl;
	arvore->inserirSemRecursao(raiz, no_1);
	cout << "Qtd nos: " << arvore->quantNos << endl;

	arvore->inserirSemRecursao(raiz, no_2);
	cout << "Qtd nos: " << arvore->quantNos << endl;

	cout << "Pre ordem: ";
	arvore->preordem(raiz);
	cout << endl;

	cout << "Pos ordem: ";
	arvore->posordem(raiz);
	cout << endl;

	cout << "Em ordem: ";
	arvore->inordem(raiz);
	cout << endl; */
}