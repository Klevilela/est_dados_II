#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
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
};

int main()
{
	Arvore *arvore = new Arvore();

	arvore->criaNo(5);
	arvore->criaNo(2);
	arvore->criaNo(6);
	arvore->criaNo(1);
	arvore->criaNo(8);

	arvore->preordem(arvore->raiz);
	cout << endl;
	arvore->posordem(arvore->raiz);
	cout << endl;
	arvore->inordem(arvore->raiz);
	cout << endl;
	arvore->calculaqtdNos(arvore->raiz);
	cout << endl;
	arvore->calculaAlturaArvore(arvore->raiz);
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
