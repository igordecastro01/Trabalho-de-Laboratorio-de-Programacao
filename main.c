#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int main() {
    Produto produtos[MAX_PRODUTOS];
    int num_produtos = 0;
    int opcao;

    do {
        printf("Menu de Opcoes: \n");
        printf("1 - Acrescentar Produto: \n");
        printf("2 - Adicionar Fornecedor: \n");
        printf("3 - Listar Produtos \n");
        printf("4 - Retirar Produtos \n");
        printf("5 - Alterar Preco Sugerido \n");
        printf("6 - Alterar Preco de Venda \n");
        printf("7 - Pesquisar Melhor Fornecedor \n");
        printf("8 - Pesquisar Produto com Maior Lucro \n");
        printf("9 - Verificar Satisfacao da Encomenda \n");
        printf("0 - Sair \n");
        printf("Escolha uma Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                criarProduto(produtos, &num_produtos);
                break;
            case 2:
                adicionarFornecedor(produtos, num_produtos);
                break;
            case 3: 
                listarProdutos(produtos, num_produtos);
                break;
            case 4:
                retirarProdutos(produtos, &num_produtos);
                break;
            case 5: 
                alterarPrecoSugerido(produtos, num_produtos);
                break;
            case 6: 
                alterarPrecoVenda(produtos, num_produtos);
                break;
            case 7: 
                pesquisarMelhorFornedor(produtos, num_produtos);
                break;
            case 8: 
                pesquisarProdutoMaiorLucro(produtos, num_produtos);
                break;
            case 9:
                verificarSatisfacaoEncomenda(produtos, num_produtos);
                break;
            case 0: 
                break;  
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);
    
    return 0;
}