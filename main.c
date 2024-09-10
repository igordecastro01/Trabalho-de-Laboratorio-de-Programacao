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
<<<<<<< HEAD
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
        printf("O produto foi retirado com sucesso!");
=======
    scanf(" %[^\n]s", nome_produto); // Permitir espaços no nome do produto

    // Abrir o arquivo original e criar um temporário para atualizar
    FILE *arquivo = fopen("produtos.txt", "r");
    FILE *arquivo_temp = fopen("produtos_temp.txt", "w");

    if (arquivo == NULL || arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
>>>>>>> e7d8b6384fdcac07ef0b5f942d2f29aa24d55cc9
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
                }
                num_fornecedores_atualizados++;

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

void mostrarPrecoSugerido() {
    char nome_produto[100];
    printf("Digite o nome do produto para ver o preço sugerido: ");
    scanf(" %[^\n]s", nome_produto);

    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256], nome_produto_arquivo[100];
    float menor_preco = -1.0;
    int produto_encontrado = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "Nome: %99[^\n]", nome_produto_arquivo) == 1) {
            if (strcmp(nome_produto_arquivo, nome_produto) == 0) {
                produto_encontrado = 1;

                // Pula as informações até chegar nos fornecedores
                for (int i = 0; i < 3; i++) {
                    fgets(linha, sizeof(linha), arquivo);
                }

                while (fgets(linha, sizeof(linha), arquivo) && strstr(linha, "Fornecedor") != NULL) {
                    float preco_sugerido;
                    fgets(linha, sizeof(linha), arquivo); // Nome do fornecedor
                    sscanf(fgets(linha, sizeof(linha), arquivo), "Preco sugerido: %f", &preco_sugerido); // Preço sugerido
                    fgets(linha, sizeof(linha), arquivo); // Prazo de entrega

                    if (menor_preco == -1 || preco_sugerido < menor_preco) {
                        menor_preco = preco_sugerido;
                    }
                }
                break;
            }
        }
    }

    if (produto_encontrado) {
        if (menor_preco == -1) {
            printf("Nenhum fornecedor encontrado para o produto.\n");
        } else {
            printf("O menor preço sugerido para %s é: R$ %.2f\n", nome_produto, menor_preco);
        }
    } else {
        printf("Produto não encontrado.\n");
    }

    fclose(arquivo);
}

void alterarPrecoVenda() {
    char nome_produto[100];
    printf("Digite o nome do produto para alterar o preço de venda: ");
    scanf(" %[^\n]s", nome_produto);

    float novo_preco;
    printf("Digite o novo preço de venda: ");
    scanf("%f", &novo_preco);

    FILE *arquivo = fopen("produtos.txt", "r");
    FILE *arquivo_temp = fopen("produtos_temp.txt", "w");

    if (arquivo == NULL || arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256];
    char nome_produto_arquivo[100];
    int produto_encontrado = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        fputs(linha, arquivo_temp);
        if (sscanf(linha, "Nome: %99[^\n]", nome_produto_arquivo) == 1) {
            if (strcmp(nome_produto_arquivo, nome_produto) == 0) {
                produto_encontrado = 1;

                // Copia as informações do produto até chegar no preço de venda
                for (int i = 0; i < 2; i++) {
                    fgets(linha, sizeof(linha), arquivo);
                    fputs(linha, arquivo_temp);
                }

                // Altera o preço de venda
                fprintf(arquivo_temp, "Preco de venda: %.2f\n", novo_preco);
                fgets(linha, sizeof(linha), arquivo); // Pula a linha do preço antigo

                continue;
            }
        }
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    if (produto_encontrado) {
        remove("produtos.txt");
        rename("produtos_temp.txt", "produtos.txt");
        printf("Preço de venda atualizado com sucesso!\n");
    } else {
        remove("produtos_temp.txt");
        printf("Produto não encontrado.\n");
    }
}


void pesquisarMelhorFornecedor() {
    char nome_produto[100];
    printf("Digite o nome do produto para pesquisar o melhor fornecedor: ");
    scanf(" %[^\n]s", nome_produto);

    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256], nome_produto_arquivo[100], melhor_fornecedor[100];
    float menor_preco = -1.0;
    int produto_encontrado = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "Nome: %99[^\n]", nome_produto_arquivo) == 1) {
            if (strcmp(nome_produto_arquivo, nome_produto) == 0) {
                produto_encontrado = 1;

                for (int i = 0; i < 3; i++) {
                    fgets(linha, sizeof(linha), arquivo);
                }

                while (fgets(linha, sizeof(linha), arquivo) && strstr(linha, "Fornecedor") != NULL) {
                    char fornecedor[100];
                    float preco_sugerido;
                    sscanf(fgets(linha, sizeof(linha), arquivo), "Nome: %99[^\n]", fornecedor);
                    sscanf(fgets(linha, sizeof(linha), arquivo), "Preco sugerido: %f", &preco_sugerido);

                    if (menor_preco == -1 || preco_sugerido < menor_preco) {
                        menor_preco = preco_sugerido;
                        strcpy(melhor_fornecedor, fornecedor);
                    }
                    fgets(linha, sizeof(linha), arquivo); // Prazo de entrega
                }
                break;
            }
        }
    }

    if (produto_encontrado) {
        if (menor_preco == -1) {
            printf("Nenhum fornecedor encontrado.\n");
        } else {
            printf("O melhor fornecedor para %s é: %s com preço de R$ %.2f\n", nome_produto, melhor_fornecedor, menor_preco);
        }
    } else {
        printf("Produto não encontrado.\n");
    }

    fclose(arquivo);
}


void pesquisarProdutoMaiorLucro() {
    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256], nome_produto_arquivo[100], produto_maior_lucro[100];
    float maior_lucro = -1.0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "Nome: %99[^\n]", nome_produto_arquivo) == 1) {
            float preco_venda;
            float menor_preco = -1.0;

            // Pula até chegar no preço de venda
            for (int i = 0; i < 2; i++) {
                fgets(linha, sizeof(linha), arquivo);
            }
            sscanf(linha, "Preco de venda: %f", &preco_venda);

            // Pula até os fornecedores
            for (int i = 0; i < 1; i++) {
                fgets(linha, sizeof(linha), arquivo);
            }

            while (fgets(linha, sizeof(linha), arquivo) && strstr(linha, "Fornecedor") != NULL) {
                float preco_sugerido;
                fgets(linha, sizeof(linha), arquivo); // Nome do fornecedor
                sscanf(fgets(linha, sizeof(linha), arquivo), "Preco sugerido: %f", &preco_sugerido);
                fgets(linha, sizeof(linha), arquivo); // Prazo de entrega

                if (menor_preco == -1 || preco_sugerido < menor_preco) {
                    menor_preco = preco_sugerido;
                }
            }

            if (menor_preco != -1) {
                float lucro = preco_venda - menor_preco;
                if (lucro > maior_lucro) {
                    maior_lucro = lucro;
                    strcpy(produto_maior_lucro, nome_produto_arquivo);
                }
            }
        }
    }

    if (maior_lucro != -1) {
        printf("O produto com maior lucro é: %s com lucro de R$ %.2f\n", produto_maior_lucro, maior_lucro);
    } else {
        printf("Nenhum produto encontrado com fornecedores.\n");
    }

    fclose(arquivo);
}

void verificarSatisfacaoEncomenda() {
    char nome_produto[100];
    printf("Digite o nome do produto para verificar a satisfação da encomenda: ");
    scanf(" %[^\n]s", nome_produto);

    int prazo_desejado;
    printf("Digite o prazo desejado de entrega (em dias): ");
    scanf("%d", &prazo_desejado);

    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256], nome_produto_arquivo[100];
    int produto_encontrado = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "Nome: %99[^\n]", nome_produto_arquivo) == 1) {
            if (strcmp(nome_produto_arquivo, nome_produto) == 0) {
                produto_encontrado = 1;

                // Pular informações até chegar aos fornecedores
                for (int i = 0; i < 3; i++) {
                    fgets(linha, sizeof(linha), arquivo);
                }

                // Verificar prazo de entrega dos fornecedores
                while (fgets(linha, sizeof(linha), arquivo) && strstr(linha, "Fornecedor") != NULL) {
                    char nome_fornecedor[100];
                    int prazo_entrega;

                    fgets(linha, sizeof(linha), arquivo); // Nome do fornecedor
                    sscanf(linha, "Nome: %99[^\n]", nome_fornecedor);
                    fgets(linha, sizeof(linha), arquivo); // Preço sugerido
                    sscanf(fgets(linha, sizeof(linha), arquivo), "Prazo de entrega: %d", &prazo_entrega);

                    if (prazo_entrega <= prazo_desejado) {
                        printf("Fornecedor %s atende ao prazo desejado com entrega em %d dias.\n", nome_fornecedor, prazo_entrega);
                    } else {
                        printf("Fornecedor %s não atende ao prazo desejado. Entrega em %d dias.\n", nome_fornecedor, prazo_entrega);
                    }
                }
                break;
            }
        }
    }

    if (!produto_encontrado) {
        printf("Produto não encontrado.\n");
    }

    fclose(arquivo);
}



int main() {
    Produto produtos[MAX_PRODUTOS];
    int num_produtos = 0;
    int opcao;

    char nome[100];
    int ref;


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
            case 4:
                printf("Digite o nome do produto a ser removido: ");
                scanf(" %[^\n]s", nome);
                printf("Digite a referencia do produto a ser removido: ");
                scanf("%d", &ref);
                apagarProdutoArquivoTxt(nome, ref);
                break;
            case 5:
                mostrarPrecoSugerido();
                break;
<<<<<<< HEAD
            case 6: 
                alterarPrecoVenda(produtos, num_produtos);
                break;
            case 7: 
                pesquisarMelhorFornedor(produtos, num_produtos);
=======
            case 6:
                alterarPrecoVenda();
>>>>>>> e7d8b6384fdcac07ef0b5f942d2f29aa24d55cc9
                break;
            case 7:
                pesquisarMelhorFornecedor();
                break;
            case 8:
                pesquisarProdutoMaiorLucro();
                break;
            case 9:
                verificarSatisfacaoEncomenda();
            case 0:
                break;  
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);
    
    return 0;
}
