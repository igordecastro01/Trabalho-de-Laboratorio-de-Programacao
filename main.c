#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_FORNECEDORES 5

typedef struct {
    char nome[100];
    float preco_sugerido;
    int prazo_entrega; // em dias
} Fornecedor;

typedef struct {
    char nome[100];
    int ref;
    Fornecedor fornecedores[MAX_FORNECEDORES];
    int num_fornecedores;
    float preco_venda;
    int estoque_existente;
} Produto;

void salvarProdutosArquivoTxt(Produto produtos[], int num_produtos) {
    FILE *arquivo = fopen("produtos.txt", "a"); // Abre o arquivo no modo append
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Produto p = produtos[num_produtos - 1]; // Salva apenas o último produto adicionado
    fprintf(arquivo, "Nome: %s\n", p.nome);
    fprintf(arquivo, "Referencia: %d\n", p.ref);
    fprintf(arquivo, "Preco de Venda: %.2f\n", p.preco_venda);
    fprintf(arquivo, "Estoque: %d\n", p.estoque_existente);
    fprintf(arquivo, "Numero de Fornecedores: %d\n", p.num_fornecedores);
    for (int j = 0; j < p.num_fornecedores; j++) {
        fprintf(arquivo, "Fornecedor %d:\n", j + 1);
        fprintf(arquivo, "\tNome: %s\n", p.fornecedores[j].nome);
        fprintf(arquivo, "\tPreco Sugerido: %.2f\n", p.fornecedores[j].preco_sugerido);
        fprintf(arquivo, "\tPrazo de Entrega: %d dias\n", p.fornecedores[j].prazo_entrega);
    }
    fprintf(arquivo, "---------------------------\n"); // Separador entre produtos

    fclose(arquivo);
}

int verificarProdutoArquivoTxt(char nome[], int ref) {
    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo == NULL) {
        return 0; // Arquivo ainda não criado, logo o produto não existe
    }

    char linha[256];
    char nome_produto[100];
    int ref_produto;
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "Nome: %[^\n]", nome_produto) == 1) { // Permitir espaços no nome
            fgets(linha, sizeof(linha), arquivo); // Le a linha da referencia
            sscanf(linha, "Referencia: %d", &ref_produto);
            if (strcmp(nome_produto, nome) == 0 && ref_produto == ref) {
                fclose(arquivo);
                return 1; // Produto encontrado
            }
        }
    }

    fclose(arquivo);
    return 0; // Produto não encontrado
}

void criarProduto(Produto produtos[], int *num_produtos) {
    Produto novo_produto;

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]s", novo_produto.nome); // Permitir leitura de strings com espaços
    
    printf("Digite a referencia do produto: ");
    scanf("%d", &novo_produto.ref);
    
    // Verificação se já existe
    if (verificarProdutoArquivoTxt(novo_produto.nome, novo_produto.ref)) {
        printf("Produto já existe!\n");
        return;
    }
    
    // Continuação do cadastro do produto
    novo_produto.num_fornecedores = 0;
       
    printf("Digite o preco de venda do produto: ");
    scanf("%f", &novo_produto.preco_venda);
    if (novo_produto.preco_venda <= 0) {
        printf("Preco de venda invalido!\n");
        return;
    }

    printf("Digite a quantidade do estoque do produto: ");
    scanf("%d", &novo_produto.estoque_existente);
    if (novo_produto.estoque_existente < 0) {
        printf("Quantidade de estoque invalida!\n");
        return;
    }

    // Adiciona o novo produto à lista
    produtos[*num_produtos] = novo_produto;
    (*num_produtos)++;

    // Salva o produto no arquivo
    salvarProdutosArquivoTxt(produtos, *num_produtos);
}

void adicionarFornecedorArquivo() {
    char nome_produto[100];
    printf("Digite o nome do produto para adicionar o fornecedor: ");
    scanf(" %[^\n]s", nome_produto); // Permitir espaços no nome do produto

    // Abrir o arquivo original e criar um temporário para atualizar
    FILE *arquivo = fopen("produtos.txt", "r");
    FILE *arquivo_temp = fopen("produtos_temp.txt", "w");

    if (arquivo == NULL || arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256];
    char nome_produto_arquivo[100];
    int produto_encontrado = 0;
    int num_fornecedores_atualizados = 0;

    // Lê o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Verifica se a linha atual é o nome de um produto
        if (sscanf(linha, "Nome: %99[^\n]", nome_produto_arquivo) == 1) {
            fputs(linha, arquivo_temp); // Copia a linha para o arquivo temporário

            // Se o produto encontrado corresponder ao nome informado
            if (strcmp(nome_produto_arquivo, nome_produto) == 0) {
                produto_encontrado = 1;

                // Copia as informações restantes do produto (referência, preço, etc.)
                fgets(linha, sizeof(linha), arquivo);
                fputs(linha, arquivo_temp); // Referência
                fgets(linha, sizeof(linha), arquivo);
                fputs(linha, arquivo_temp); // Preço
                fgets(linha, sizeof(linha), arquivo);
                fputs(linha, arquivo_temp); // Estoque

                // Copia os fornecedores antigos até encontrar o separador
                while (fgets(linha, sizeof(linha), arquivo) && strcmp(linha, "---------------------------\n") != 0) {
                    fputs(linha, arquivo_temp);
                    num_fornecedores_atualizados++;
                }

                // Adicionar o novo fornecedor
                Fornecedor novo_fornecedor;
                printf("Digite o nome do novo fornecedor: ");
                scanf(" %[^\n]s", novo_fornecedor.nome);

                printf("Digite o preco sugerido do novo fornecedor: ");
                scanf("%f", &novo_fornecedor.preco_sugerido);

                printf("Digite o prazo de entrega do novo fornecedor: ");
                scanf("%d", &novo_fornecedor.prazo_entrega);

                // Adicionar o novo fornecedor ao arquivo temporário
                fprintf(arquivo_temp, "Fornecedor %d:\n", num_fornecedores_atualizados);
                fprintf(arquivo_temp, "Nome: %s\n", novo_fornecedor.nome);
                fprintf(arquivo_temp, "Preco sugerido: %.2f\n", novo_fornecedor.preco_sugerido);
                fprintf(arquivo_temp, "Prazo de entrega: %d dias\n", novo_fornecedor.prazo_entrega);
                fprintf(arquivo_temp, "---------------------------\n");

                num_fornecedores_atualizados++;
                printf("Fornecedor adicionado com sucesso!\n");
            } else {
                // Copia todas as outras linhas que não são relacionadas ao produto encontrado
                while (fgets(linha, sizeof(linha), arquivo) && strcmp(linha, "---------------------------\n") != 0) {
                    fputs(linha, arquivo_temp);
                }
                fputs(linha, arquivo_temp); // Copia o separador
            }
        } else {
            // Copia qualquer outra linha (não relacionada ao produto)
            fputs(linha, arquivo_temp);
        }
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    if (produto_encontrado) {
        remove("produtos.txt");
        rename("produtos_temp.txt", "produtos.txt");
        printf("Arquivo atualizado com sucesso!\n");
    } else {
        remove("produtos_temp.txt");
        printf("Produto nao encontrado no arquivo!\n");
    }
}




void listarProdutosArquivoTxt() {
    FILE *arquivo = fopen("produtos.txt", "r"); // Abre o arquivo no modo leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo ou arquivo vazio.\n");
        return;
    }

    char linha[256]; // Buffer para leitura
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha); // Exibe a linha lida
    }

    fclose(arquivo);
}

void apagarProdutoArquivoTxt(char nome[], int ref) {
    FILE *arquivo = fopen("produtos.txt", "r");
    FILE *arquivo_temp = fopen("produtos_temp.txt", "w");

    if (arquivo == NULL || arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256];
    char nome_produto[100];
    int ref_produto;
    int produto_encontrado = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "Nome: %99[^\n]", nome_produto) == 1) {
            fgets(linha, sizeof(linha), arquivo); // Le a linha da referencia
            sscanf(linha, "Referencia: %d", &ref_produto);

            if (strcmp(nome_produto, nome) == 0 && ref_produto == ref) {
                produto_encontrado = 1; // Produto encontrado, não copia para o arquivo temporário
                // Pular as linhas do produto até o separador
                while (fgets(linha, sizeof(linha), arquivo) && strcmp(linha, "---------------------------\n") != 0);
                continue; // Pula a escrita deste produto
            }
        }
        // Escreve os produtos não removidos no arquivo temporário
        fputs(linha, arquivo_temp);
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    if (produto_encontrado) {
        remove("produtos.txt");
        rename("produtos_temp.txt", "produtos.txt");
        printf("Produto removido com sucesso!\n");
    } else {
        remove("produtos_temp.txt");
        printf("Produto não encontrado.\n");
    }
}


int main() {
    Produto produtos[MAX_PRODUTOS];
    int num_produtos = 0;
    int opcao;

    do {
        printf("\nMenu de Opcoes: \n");
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
                adicionarFornecedorArquivo();
                break;
            case 3: 
                listarProdutosArquivoTxt();
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
