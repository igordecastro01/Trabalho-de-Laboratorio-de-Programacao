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
    char ref[50];
    Fornecedor fornecedores[MAX_FORNECEDORES];
    int num_fornecedores;
    float preco_venda;
    int estoque_existente;
}Produto;

void criarProduto() {
    Produto novo_produto;

    printf("Digite o nome do produto: ");
    scanf("%s", &novo_produto.nome);
    printf(novo_produto.nome);

    printf("Digite a referência do produto: ");
    scanf("%d", &novo_produto.ref);
    printf(novo_produto.ref);

    novo_produto.num_fornecedores = 0;

    printf("Digite o preco de venda do produto: ");
    scanf("%f", &novo_produto.preco_venda);
    printf("%f", novo_produto.preco_venda);

    printf("Digite a quantidade do estoque do produto: ");
    scanf("%d", &novo_produto.estoque_existente);
    printf(novo_produto.estoque_existente);
}

void adicionarFornecedor() {
}

void listarProdutos() {
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
    criarProduto();
}