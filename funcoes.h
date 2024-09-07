#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUTOS 100
#define MAX_FORNECEDORES 5

typedef struct {
    char nome[100];
    float preco_sugerido;
    int prazo_entrega; // em dias
}Fornecedor;

typedef struct {
    char nome[100];
    int ref;
    Fornecedor fornecedores[MAX_FORNECEDORES];
    int num_fornecedores;
    float preco_venda;
    int estoque_existente;
}Produto;

void criarProduto(Produto produtos[], int *num_produtos) {
    Produto novo_produto;
    printf("Digite o nome do produto: ");

    if (produtos->nome == NULL || produtos->nome != novo_produto.nome){
        scanf("%s", novo_produto.nome);
        printf("%s\n", novo_produto.nome);
    }else{
        printf("Nome de produto já existente.\n");
    }

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

void adicionarFornecedor(Produto produtos[], int num_produtos) {
    // verificar o nome do produto que quer adicionar o fornecedor 
    char nome_produto[100];
    printf("Digite o nome do produto para adicionar o fornecedor: ");
    scanf("%s", nome_produto);
    // verificar se já tem fornecedores máximos
    for (int i = 0; i < num_produtos; i++) {
        if (strcmp(produtos[i].nome, nome_produto) == 0) {
            if (produtos[i].num_fornecedores >= MAX_FORNECEDORES) {
                printf("Não foi possível adicionar fornecedores, pois já tem o limite.");
            }
        //pedir dados para o novo fornecedor
        Fornecedor novo_fornecedor;

        printf("Digite o nome do novo fornecedor: ");
        scanf("%s", novo_fornecedor.nome);

        printf("Digite o preco sugerido do novo fornecedor: ");
        scanf("%f", &novo_fornecedor.preco_sugerido);

        printf("Digite o prazo de entrega do novo fornecedor: ");
        scanf("%d", &novo_fornecedor.prazo_entrega);

        produtos[i].fornecedores[produtos[i].num_fornecedores] = novo_fornecedor;
        produtos[i].num_fornecedores++;
        printf("Fornecedor adicionado!\n");
        }

        
    }
}

void listarProdutos(Produto produtos[], int num_produtos) {
    for (int i = 0; i < num_produtos; i++) {
        printf("Nome: %s | Referencia: %d | Preco Venda: %.2f | Estoque: %d\n", produtos[i].nome, produtos[i].ref, produtos[i].preco_venda, produtos[i].estoque_existente);
    }
}

void retirarProdutos(Produto produtos[], int *num_produtos) {
    // verificar nome do produto para ser retirado
    char nome_produto[100];
    printf("Digite o nome do produto para ser retirado: ");
    scanf("%s", nome_produto);
    // verificar se nome_produto é igual a um produto da lista e removê-lo
    for (int i = 0; i < *num_produtos; i++) {
        if (strcmp(produtos[i].nome, nome_produto) == 0)  {
            for (int j = i; j < *num_produtos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*num_produtos)--;
        }
        
    }
    printf("O produto foi retirado com sucesso!");
}

void alterarPrecoSugerido(Produto produtos[], int num_produtos) {
    char nome_produto[100];
    char nome_fornecedor[100];
    printf("Digite o nome do produto que quer acessar o fornecedor: ");
    scanf("%s", nome_produto);

    for (int i = 0; i < num_produtos; i++) {
        if (strcmp(produtos[i].nome, nome_produto) == 0) {
            printf("Digite o nome do fornecedor: ");
            scanf("%s", nome_fornecedor);

            for (int j = 0; j< produtos[i].num_fornecedores; j++) {
                if (strcmp(produtos[i].fornecedores[j].nome, nome_fornecedor) == 0) {
                    printf("Digite o novo valor sugerido para o fornecedor digitado: ");
                    scanf("%f", &produtos[i].fornecedores[j].preco_sugerido);
                    printf("Preco sugerido atualizado");            
                }
            }
            printf("Não foi possível encontrar o fornecedor");
        }
    }
}


void alterarPrecoVenda(Produto produtos[], int num_produtos) {
    char nome_produto[100];
    printf("Digite o nome do produto: ");
    scanf("%s", nome_produto);

    for (int i = 0; i < num_produtos; i++) {
        if (strcmp(produtos[i].nome, nome_produto) == 0) {
            printf("Digite o novo preco de venda: ");
            scanf("%f", &produtos[i].preco_venda);
            printf("Preco de venda atualizado!");
        }
    }
}

void pesquisarMelhorFornedor(Produto produtos[], int num_produtos) {
    char nome_produto[100];
    printf("Digite o nome do produto: ");
    scanf("%s", nome_produto);

    for (int i = 0; i < num_produtos; i++) {
        if (strcmp(produtos[i].nome, nome_produto) == 0) {
            if (produtos[i].num_fornecedores == 0) {
                printf("Não foi possível encontrar fornecedor para este produto.");
            }
            Fornecedor melhor_fornecedor = produtos[i].fornecedores[0];
            for (int j = 1; j < produtos[i].num_fornecedores; j++) {
                if (produtos[i].fornecedores[j].preco_sugerido < melhor_fornecedor.preco_sugerido) {
                    melhor_fornecedor = produtos[i].fornecedores[j];
                }
            }
            printf("Melhor Fornecedor: %s\nPreco: %.2f\nPrazo de Entrega: %d\n", melhor_fornecedor.nome, melhor_fornecedor.preco_sugerido, melhor_fornecedor.prazo_entrega);
        }

    }
}

void pesquisarProdutoMaiorLucro(Produto produtos[], int num_produtos) {
    Produto *produto_maior_lucro = &produtos[0];
    float maior_lucro = produto_maior_lucro->preco_venda - produto_maior_lucro->fornecedores->preco_sugerido;

    for (int i = 0; i < num_produtos; i++) {
        for (int j = 0; j < produtos[i].num_fornecedores; j++) {
            float lucro = produtos[i].preco_venda - produtos[i].fornecedores[j].preco_sugerido;
            if (lucro > maior_lucro) {
                maior_lucro = lucro;
                produto_maior_lucro = &produtos[i];
            }
        }
    }
    printf("Produto com maior lucro: %s\nLucro: %.2f", produto_maior_lucro->nome, maior_lucro);
}

void verificarSatisfacaoEncomenda(Produto produtos[], int num_produtos) {
    char nome_produto[100];
    int quant_desejada, prazo_desejado;

    printf("Digite o nome do produto: ");
    scanf("%s", nome_produto);
    printf("Digite a quantidade desejada do produto: ");
    scanf("%d", &quant_desejada);
    printf("Digite o prazo desejado para o produto: ");
    scanf("%d", &prazo_desejado);

    for (int i = 0; i < num_produtos; i++) {
        if (strcmp(produtos[i].nome, nome_produto) == 0) {
            if (produtos[i].estoque_existente >= quant_desejada) {
                printf("O estoque satisfaz o pedido da encomenda.\n");
            } else {
                for (int j = 0; j < produtos[i].num_fornecedores; j++) {
                    if (produtos[i].fornecedores[j].prazo_entrega <= prazo_desejado) {
                        printf("O fornecedor '%s' satisfaz o pedido da encomenda.\n", produtos[i].fornecedores[j].nome);
                    }
                }
                printf("Pedido da encomenda nao pode ser satisfeita.\n");
            }
        }
    }
}