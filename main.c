#include <stdio.h>
#include <stdlib.h>
#define MAX_PRODUTOS 100
#define MAX_FORNECEDORES 5

typedef struct {
    char nome[50];
    float preco_sugerido;
    int prazo_entrega; // em dias
}Fornecedor;

typedef struct {
    char nome[50];
    int ref;
    Fornecedor fornecedores[MAX_FORNECEDORES];
    int num_fornecedores;
    float preco_venda;
    int estoque_existente;
}Produto;

void criarProduto(Produto produtos[], int *num_produtos) {
    Produto novo_produto;

    printf("Digite o nome do produto: ");
    scanf("%s", novo_produto.nome);
    printf("%s\n", novo_produto.nome);

    printf("Digite a referencia do produto: ");
    scanf("%d", &novo_produto.ref);
    printf("%d\n", novo_produto.ref);

    novo_produto.num_fornecedores = 0;

    printf("Digite o preco de venda do produto: ");
    scanf("%f", &novo_produto.preco_venda);
    printf("%f\n", novo_produto.preco_venda);

    printf("Digite a quantidade do estoque do produto: ");
    scanf("%d", &novo_produto.estoque_existente);
    printf("%d\n", novo_produto.estoque_existente);

    produtos[*num_produtos] = novo_produto;
    (*num_produtos)++;

    for (int i = 0; i < *num_produtos - 1; i++) {
        for (int j = i + 1; j < *num_produtos; j++) {
            if (strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                Produto temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }
}

void adicionarFornecedor() {
}

void listarProdutos(Produto produtos[], int num_produtos) {
    for (int i = 0; i < num_produtos; i++) {
        printf("Nome: %s | Referencia: %d | Preco Venda: %.2f | Estoque: %d\n", produtos[i].nome, produtos[i].ref, produtos[i].preco_venda, produtos[i].estoque_existente);
    }
}

void retirarProdutos() {
}

void alterarPrecoSugerido() {
}

void alterarPrecoVenda() {
}

void pesquisarMelhorFornedor() {
}

void pesquisarProdutoMaiorLucro() {
}

void verificarSatisfacaoEncomenda() {
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int num_produtos = 0;
    int opcao;

    do {
        printf("Menu de Opcoes: \n");
        printf("1 - Acrescentar Produto: \n");
        printf("3 - Listar Produtos \n");
        printf("Escolha uma Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                criarProduto(produtos, &num_produtos);
                break;
            case 3: 
                listarProdutos(produtos, num_produtos);
                break;
            default:
                printf("Opcao invalida!");
                break;
        }
    } while (opcao != 0);
}