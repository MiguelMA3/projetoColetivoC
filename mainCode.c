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

void removerProduto(int codigo) {
    int chave = hash(codigo);
    if (tabela[chave].chave != -1 && tabela[chave].produto.codigo == codigo) {
        tabela[chave].chave = -1;
    }
}

void pesquisaHash() {
    int codigo;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);

    Produto* produto = pesquisarProduto(codigo);
    if (produto != NULL) {
        printf("Produto encontrado:\n");
		printf("Código: %d\n", produto.codigo);
		printf("Nome: %s\n", produto.nome);
		printf("Preço: %.2f\n", produto.preco_unit);
		printf("Estoque: %d\n", produto.qtd_estoque);
		printf("\n");
    } else {
        printf("Produto não encontrado.\n");
    }
}

// Função para ler os dados do arquivo e preencher a tabela hash
void lerArquivo() {
    FILE* arquivo;
    char linha[200];

    // Abrir o arquivo para leitura
    arquivo = fopen("PRODUTOS.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Ler cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        Produto produto;
        char* token;
        int campo = 1;

        // Extrair cada campo da linha usando strtok()
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
                    produto.qtd_estoque = atof(token);
                    break;
            }

            token = strtok(NULL, ",");
            campo++;
        }

        // Inserir o produto na tabela hash
        inserirProduto(produto);
    }

    // Fechar o arquivo
    fclose(arquivo);
}

// Função principal (main)
int main() {
    // Inicializando a tabela hash
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela[i].chave = -1; // Marcando todas as posições como vazias
    }

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
                // Implemente a função pesquisaSequencial()
                break;
            case 2:
                // Implemente a função pesquisaBinaria()
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
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
