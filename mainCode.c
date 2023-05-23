#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto
{
	int codigo;
	char nome[55];
	int qtd_estoque;
    float preco_unit;
};

int main(){
	FILE *arq = fopen("PRODUTOS", "w");
	if (arq == NULL)
		exit(0);
	
	struct Produto produto1;
	produto1.codigo = 123;
	strcpy(produto1.nome, "monitor");
	produto1.preco_unit = 500.00;
	produto1.qtd_estoque = 40;
	
	struct Produto produto2;
	produto2.codigo = 1234;
	strcpy(produto2.nome, "computador");
	produto2.preco_unit = 1200.00;
	produto2.qtd_estoque = 16;
	
	struct Produto produto3;
	produto3.codigo = 12345;
	strcpy(produto3.nome, "teclado");
	produto3.preco_unit = 100.00;
	produto3.qtd_estoque = 100;
	
	struct Produto produto4;
	produto4.codigo = 123456;
	strcpy(produto4.nome, "mouse");
	produto4.preco_unit = 80.00;
	produto4.qtd_estoque = 99;
	
	
	fprintf(arq, "%d %s %.2f %d\n", produto1.codigo, produto1.nome, produto1.preco_unit, produto1.qtd_estoque);
	fprintf(arq, "%d %s %.2f %d\n", produto2.codigo, produto2.nome, produto2.preco_unit, produto2.qtd_estoque);
	fprintf(arq, "%d %s %.2f %d\n", produto3.codigo, produto3.nome, produto3.preco_unit, produto3.qtd_estoque);
	fprintf(arq, "%d %s %.2f %d\n", produto4.codigo, produto4.nome, produto4.preco_unit, produto4.qtd_estoque);
	
	fclose(arq);
	return 0;
}

