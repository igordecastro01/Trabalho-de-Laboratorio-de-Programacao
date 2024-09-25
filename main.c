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
    FILE *arquivo = fopen("produtos.txt", "w"); // Abre o arquivo no modo escrita
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < num_produtos; i++) {
        Produto p = produtos[i];
        fprintf(arquivo, "Nome: %s\n", p.nome);
        fprintf(arquivo, "Referencia: %d\n", p.ref);
        fprintf(arquivo, "Preco de venda: %.2f\n", p.preco_venda);
        fprintf(arquivo, "Estoque: %d\n", p.estoque_existente);
        fprintf(arquivo, "Numero de Fornecedores: %d\n", p.num_fornecedores);
        for (int j = 0; j < p.num_fornecedores; j++) {
            fprintf(arquivo, "Fornecedor %d:\n", j + 1);
            fprintf(arquivo, "\tNome: %s\n", p.fornecedores[j].nome);
            fprintf(arquivo, "\tPreco Sugerido: %.2f\n", p.fornecedores[j].preco_sugerido);
            fprintf(arquivo, "\tPrazo de Entrega: %d dias\n", p.fornecedores[j].prazo_entrega);
        }
        fprintf(arquivo, "---------------------------\n"); // Separador entre produtos
    }

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

<<<<<<< HEAD
void adicionarFornecedorArquivo(Produto produtos[], int num_produtos) {
=======
void adicionarFornecedor(Produto produtos[], int *num_produtos) {
>>>>>>> fd4ef75fb00e05c3eb62be11e45a44212bf9267f
    char nome_produto[100];
    printf("Digite o nome do produto para adicionar o fornecedor: ");
// <<<<<<< HEAD
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
// =======
    scanf(" %[^\n]s", nome_produto); // Permitir espaços no nome do produto

<<<<<<< HEAD
    // Abrir o arquivo original e criar um temporário para atualizar
    FILE *arquivo = fopen("produtos.txt", "r");
    FILE *arquivo_temp = fopen("produtos_temp.txt", "w");

    if (arquivo == NULL || arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
// >>>>>>> e7d8b6384fdcac07ef0b5f942d2f29aa24d55cc9
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
=======
    for (int i = 0; i < *num_produtos; i++) {
        if (strcmp(produtos[i].nome, nome_produto) == 0) {
            if (produtos[i].num_fornecedores >= MAX_FORNECEDORES) {
                printf("Não foi possível adicionar fornecedores, pois já tem o limite.");
                return;
>>>>>>> fd4ef75fb00e05c3eb62be11e45a44212bf9267f
            }

            // Pedir dados para o novo fornecedor
            Fornecedor novo_fornecedor;

            printf("Digite o nome do novo fornecedor: ");
            scanf(" %[^\n]s", novo_fornecedor.nome);

            printf("Digite o preco sugerido do novo fornecedor: ");
            scanf("%f", &novo_fornecedor.preco_sugerido);

            printf("Digite o prazo de entrega do novo fornecedor: ");
            scanf("%d", &novo_fornecedor.prazo_entrega);

            produtos[i].fornecedores[produtos[i].num_fornecedores] = novo_fornecedor;
            produtos[i].num_fornecedores++;
            printf("Fornecedor adicionado!\n");

            // Salvar o produto com o novo fornecedor
            salvarProdutosArquivoTxt(produtos, *num_produtos);
            return;
        }
    }

    printf("Produto não encontrado.\n");
}
}

void retirarProdutos(Produto produtos[], int *num_produtos) {
    // verificar nome do produto para ser retirado
    char nome_produto[100];
    printf("Digite o nome do produto para ser retirado: ");
    scanf(" %[^\n]s", nome_produto);
    // verificar se nome_produto é igual a um produto da lista e removê-lo
    for (int i = 0; i < *num_produtos; i++) {
        if (strcmp(produtos[i].nome, nome_produto) == 0)  {
            for (int j = i; j < *num_produtos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*num_produtos)--;
            printf("O produto foi retirado com sucesso!");
            salvarProdutosArquivoTxt(produtos, *num_produtos);
            return;
        }
    }
    printf("Produto não encontrado.\n");
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

void carregarFornecedores(Produto produtos[], int *num_produtos) {
    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256];
    int produto_atual = -1;

    // Ler o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strncmp(linha, "Nome:", 5) == 0) {
            produto_atual++;
            sscanf(linha, "Nome: %[^\n]s", produtos[produto_atual].nome);
            
            // Ler as próximas linhas do arquivo até obter todos os dados do produto
            fgets(linha, sizeof(linha), arquivo); // Referência
            sscanf(linha, "Referencia: %d", &produtos[produto_atual].ref);

            fgets(linha, sizeof(linha), arquivo); // Preço de venda
            sscanf(linha, "Preco de venda: %f", &produtos[produto_atual].preco_venda);

            fgets(linha, sizeof(linha), arquivo); // Estoque
            sscanf(linha, "Estoque: %d", &produtos[produto_atual].estoque_existente);

            fgets(linha, sizeof(linha), arquivo); // Numero de Fornecedores
            sscanf(linha, "Numero de Fornecedores: %d", &produtos[produto_atual].num_fornecedores);

            // Inicializa o número de fornecedores para o produto
            produtos[produto_atual].num_fornecedores = 0;
        }

        // Ler informações dos fornecedores se encontrado "Fornecedor"
        if (strncmp(linha, "Fornecedor", 10) == 0) { 
            int fornecedor_atual = produtos[produto_atual].num_fornecedores;

            // Lê a linha com o nome do fornecedor
            fgets(linha, sizeof(linha), arquivo); 

            // Lê a linha com o preço sugerido
            fgets(linha, sizeof(linha), arquivo);

            // Lê a linha com o prazo de entrega
            fgets(linha, sizeof(linha), arquivo); 

            sscanf(linha, "\tPrazo de Entrega: %d dias\n", &produtos[produto_atual].fornecedores[fornecedor_atual].prazo_entrega); 

            // Copia o nome do fornecedor
            sscanf(linha, "\tNome: %[^\n]s", produtos[produto_atual].fornecedores[fornecedor_atual].nome);

            // Ler o preço sugerido
            sscanf(linha, "\tPreco Sugerido: %f\n", &produtos[produto_atual].fornecedores[fornecedor_atual].preco_sugerido);

            // Incrementa o número de fornecedores
            produtos[produto_atual].num_fornecedores++;
        }
    }

    // Define o número de produtos carregados
    *num_produtos = produto_atual + 1;

    fclose(arquivo);
}

void alterarPrecoSugerido(Produto produtos[], int num_produtos) {
    char nome_produto[100], nome_fornecedor[100];
    float novo_preco;
    
    // Obter o nome do produto, nome do fornecedor e o novo preço sugerido
    printf("Digite o nome do produto para alterar o preço sugerido: ");
    scanf(" %[^\n]s", nome_produto);
    printf("Digite o nome do fornecedor: ");
    scanf(" %[^\n]s", nome_fornecedor);
    printf("Digite o novo preço sugerido: ");
    scanf("%f", &novo_preco);

    FILE *arquivo = fopen("produtos.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256], nome_produto_arquivo[100], nome_fornecedor_arquivo[100];
    int produto_encontrado = 0;
    int fornecedor_encontrado = 0;

    // Ler o arquivo linha por linha e salvar no arquivo temporário
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Copia a linha para o arquivo temporário, pois estamos a fazer uma cópia com alterações
        fputs(linha, temp); 
        
        // Verifica se a linha atual é o nome de um produto
        if (sscanf(linha, "Nome: %99[^\n]", nome_produto_arquivo) == 1) { 
            if (strcmp(nome_produto_arquivo, nome_produto) == 0) {
                produto_encontrado = 1;

                // Pula as informações até chegar nos fornecedores
                for (int i = 0; i < 3; i++) { 
                    fgets(linha, sizeof(linha), arquivo); 
                    fputs(linha, temp); // Copia as linhas intermediárias
                }

                // Processa os fornecedores
                while (fgets(linha, sizeof(linha), arquivo) && strstr(linha, "Fornecedor") != NULL) {
                    // Lê o nome do fornecedor da linha atual
                    fgets(linha, sizeof(linha), arquivo); // Lê a linha com o nome do fornecedor
                    sscanf(linha, "\tNome: %[^\n]s", nome_fornecedor_arquivo); // Extrai o nome

                    // Verifica se o fornecedor é o que queremos alterar
                    if (strcmp(nome_fornecedor_arquivo, nome_fornecedor) == 0) {
                        fornecedor_encontrado = 1;

                        // Lê o preço atual e escreve o novo preço no arquivo temporário
                        fgets(linha, sizeof(linha), arquivo); 
                        fprintf(temp, "Preco sugerido: %.2f\n", novo_preco); 

                        // Lê o prazo de entrega e escreve no arquivo temporário
                        fgets(linha, sizeof(linha), arquivo); 
                        fputs(linha, temp);
                    } else {
                        // Se não for o fornecedor, copia as linhas normalmente
                        fgets(linha, sizeof(linha), arquivo); 
                        fputs(linha, temp); // Preço sugerido
                        fgets(linha, sizeof(linha), arquivo);
                        fputs(linha, temp); // Prazo de entrega
                    }
                }
            }
        } else {
            // Copia as outras linhas que não são o produto
            fputs(linha, temp); 
        }
    }

    fclose(arquivo);
    fclose(temp);

    // Verifica se o produto e o fornecedor foram encontrados
    if (produto_encontrado && fornecedor_encontrado) {
        // Remove o arquivo original e renomeia o arquivo temporário
        remove("produtos.txt");
        rename("temp.txt", "produtos.txt");
        printf("Preço sugerido alterado com sucesso!\n");

        // Atualizar o vetor de produtos (não é estritamente necessário, mas pode ser útil para manter a sincronização)
        for (int i = 0; i < num_produtos; i++) {
            if (strcmp(produtos[i].nome, nome_produto) == 0) {
                for (int j = 0; j < produtos[i].num_fornecedores; j++) {
                    if (strcmp(produtos[i].fornecedores[j].nome, nome_fornecedor) == 0) {
                        produtos[i].fornecedores[j].preco_sugerido = novo_preco;
                        printf("Preço atualizado no vetor de produtos.\n");
                        break;
                    }
                }
                break;
            }
        }
    } else {
        // Caso não tenha encontrado o produto ou fornecedor
        remove("temp.txt"); // Remove o arquivo temporário
        if (!produto_encontrado) {
            printf("Produto não encontrado.\n");
        } else if (!fornecedor_encontrado) {
            printf("Fornecedor não encontrado para o produto especificado.\n");
        }
    }
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
                for (int i = 0; i < 1; i++) {
                    fgets(linha, sizeof(linha), arquivo);
                    fputs(linha, arquivo_temp);
                }

                // Altera o preço de venda
                fprintf(arquivo_temp, "Preco de venda: %.2f\n", novo_preco);
                

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
        printf("O produto com maior lucro é: %s \n", produto_maior_lucro);
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
        // Verifica se a linha atual é o nome de um produto
        if (sscanf(linha, "Nome: %99[^\n]", nome_produto_arquivo) == 1) { 
            if (strcmp(nome_produto_arquivo, nome_produto) == 0) {
                produto_encontrado = 1;

                // Pula as informações até chegar aos fornecedores
                for (int i = 0; i < 3; i++) { 
                    fgets(linha, sizeof(linha), arquivo);
                }

                // Verificar prazo de entrega dos fornecedores
                while (fgets(linha, sizeof(linha), arquivo) && strstr(linha, "Fornecedor") != NULL) {
                    char nome_fornecedor[100];
                    int prazo_entrega;

                    // Lê o nome do fornecedor da linha atual
                    fgets(linha, sizeof(linha), arquivo); // Lê a linha com o nome do fornecedor
                    sscanf(linha, "\tNome: %[^\n]s", nome_fornecedor); // Extrai o nome

                    // Lê o preço sugerido (ignorando a linha)
                    fgets(linha, sizeof(linha), arquivo); 

                    // Lê o prazo de entrega da linha atual
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

    // Carrega produtos do arquivo
    carregarFornecedores(produtos, &num_produtos);

    do {
        printf("\nMenu de Opcoes: \n");
        printf("1 - Acrescentar Produto: \n");
        printf("2 - Adicionar Fornecedor: \n");
        printf("3 - Listar Produtos \n");
        printf("4 - Retirar Produtos \n");
        printf("5 - Alterar Preco Sugerido pelo fornecedor\n");
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
<<<<<<< HEAD
                adicionarFornecedorArquivo(produtos, num_produtos);
=======
                adicionarFornecedor(produtos, &num_produtos);
>>>>>>> fd4ef75fb00e05c3eb62be11e45a44212bf9267f
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
                //carregarFornecedores(produtos, &num_produtos); // já carregou no início
                alterarPrecoSugerido(produtos, num_produtos);
                break;
            case 6: 
<<<<<<< HEAD
                alterarPrecoVenda(produtos, num_produtos);
                break;
            case 7: 
                pesquisarMelhorFornecedor(produtos, num_produtos);
=======
                alterarPrecoVenda();
                break;
            case 7: 
                pesquisarMelhorFornecedor();
>>>>>>> fd4ef75fb00e05c3eb62be11e45a44212bf9267f
                break;
            case 8:
                pesquisarProdutoMaiorLucro();
                break;
            case 9:
                verificarSatisfacaoEncomenda();
                break;
            case 0:
                break;  
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);
<<<<<<< HEAD
=======

    return 0;
>>>>>>> fd4ef75fb00e05c3eb62be11e45a44212bf9267f
}