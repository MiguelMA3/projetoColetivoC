#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10000

typedef struct {
	int codigo;
	char nome[55];
	int qtd_estoque;
	float preco_unit;
} Produto;

typedef struct {
    int chave;
    Produto produto;
} HashItem;

HashItem tabela[TABLE_SIZE];

int hash(int chave) {
    return chave % TABLE_SIZE;
}

void inserirProduto(Produto produto) {
    int chave = hash(produto.codigo);
    tabela[chave].chave = chave;
    tabela[chave].produto = produto;
}

Produto* pesquisarProduto(int codigo) {
    int chave = hash(codigo);
    if (tabela[chave].chave != -1 && tabela[chave].produto.codigo == codigo) {
        return &tabela[chave].produto;
    }
    return NULL;
}

void pesquisaHash() {
    int codigo;
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);

    Produto* produto = pesquisarProduto(codigo);
    if (produto != NULL) {
        printf("Produto encontrado:\n");
		printf("Codigo: %d\n", produto.codigo);
		printf("Nome: %s\n", produto.nome);
		printf("Preco: %.2f\n", produto.preco_unit);
		printf("Estoque: %d\n", produto.qtd_estoque);
		printf("\n");
    } else {
        printf("Produto nao encontrado.\n");
    }
}

void lerArquivo() {
    FILE* arquivo;
    char linha[200];

    arquivo = fopen("PRODUTOS.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        Produto produto;
        char* token;
        int campo = 1;

        token = strtok(linha, ",");
        while (token != NULL) {
            switch (campo) {
                case 1:
                    produto.codigo = atoi(token);
                    break;
                case 2:
                    strcpy(produto.nome, token);
                    break;
                case 3:
                    produto.preco_unit = atof(token);
                    break;
                case 4:
                    produto.qtd_estoque = atoi(token);
                    break;
            }

            token = strtok(NULL, ",");
            campo++;
        }

        inserirProduto(produto);
    }

    fclose(arquivo);
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela[i].chave = -1;
    }

    int opcao;
    do {
        system("cls");
        printf("\nMenu de Opcoes:\n");
        printf("1. Pesquisa Sequencial\n");
        printf("2. Pesquisa Binaria\n");
        printf("3. Pesquisa de Tabela Hash\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                //pesquisaSequencial()
                break;
            case 2:
                //pesquisaBinaria()
                break;
            case 3:
                pesquisaHash();
                getchar();
                getchar();
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
