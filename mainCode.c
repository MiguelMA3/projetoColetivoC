#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int codigo;
	char nome[55];
	int qtd_estoque;
    float preco_unit;
} Produto;

void pesquisaSequencial() {
	printf("Opção de pesquisa sequencial selecionada\n");
}

void pesquisaBinaria() {
	printf("Opção de pesquisa binária selecionada\n");
}

void tabelaHash() {
	
}

void pesquisaHash() {
	printf("Opção de pesquisa de tabela hash selecionada\n");
}


int main(){
	FILE *arq = fopen("PRODUTOS", "a");
	if (arq == NULL)
		exit(0);

	Produto produto1;
	produto1.codigo = 123;
	strcpy(produto1.nome, "monitor");
	produto1.preco_unit = 500.00;
	produto1.qtd_estoque = 40;
	
	Produto produto2;
	produto2.codigo = 1234;
	strcpy(produto2.nome, "computador");
	produto2.preco_unit = 1200.00;
	produto2.qtd_estoque = 16;
	
	Produto produto3;
	produto3.codigo = 12345;
	strcpy(produto3.nome, "teclado");
	produto3.preco_unit = 100.00;
	produto3.qtd_estoque = 100;
	
	Produto produto4;
	produto4.codigo = 123456;
	strcpy(produto4.nome, "mouse");
	produto4.preco_unit = 80.00;
	produto4.qtd_estoque = 99;
	
	
	fprintf(arq, "%d %s %.2f %d\n", produto1.codigo, produto1.nome, produto1.preco_unit, produto1.qtd_estoque);
	fprintf(arq, "%d %s %.2f %d\n", produto2.codigo, produto2.nome, produto2.preco_unit, produto2.qtd_estoque);
	fprintf(arq, "%d %s %.2f %d\n", produto3.codigo, produto3.nome, produto3.preco_unit, produto3.qtd_estoque);
	fprintf(arq, "%d %s %.2f %d\n", produto4.codigo, produto4.nome, produto4.preco_unit, produto4.qtd_estoque);
	
	fclose(arq);

	int opcao;

	do {
		system("cls");
		printf("\nMenu de Opções:\n");
		printf("1. Pesquisa Sequencial\n");
		printf("2. Pesquisa Binária\n");
		printf("3. Pesquisa de Tabela Hash\n");
		printf("4. Sair\n");
		printf("Escolha uma opção: ");
		scanf("%d", &opcao);

		switch (opcao) {
			case 1:
				pesquisaSequencial();
				break;
			case 2:
				pesquisaBinaria();
				break;
			case 3:
				pesquisaHash();
				break;
			case 4:
				printf("Saindo do programa...\n");
				break;
			default:
				printf("Opção inválida! Tente novamente.\n");
				break;
		}
	} while (opcao != 4);
}