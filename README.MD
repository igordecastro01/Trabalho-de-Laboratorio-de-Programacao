<h1>
<a href="http://www.campusrussas.ufc.br/">
<img align="center" width="100px" src="http://www.campusrussas.ufc.br/uploads/347f54af29eee81064aa7565b4652a.png"></a>
<span> Universidade Federal do Ceará - Campus de Russas</span>
</h1>

## Trabalho prático -  Laboratório de Programação

### Introdução:

Neste trabalho, vocês terão a oportunidade de aplicar seus conhecimentos de programação em linguagem C para implementar um sistema gerenciador utilizando as operações básicas de CRUD (Create, Read, Update, Delete) e persistindo os dados em arquivos. Cada grupo poderá escolher um tema específico para desenvolver o sistema gerenciador, permitindo a aplicação prática dos conceitos aprendidos em laboratório de programação (Ver temas no final do arquivo).

### Objetivo:

O objetivo deste trabalho é desenvolver um sistema gerenciador utilizando a linguagem de programação C, que permita a criação, leitura, atualização e exclusão de registros em arquivos. O sistema deverá ser capaz de armazenar e recuperar informações de maneira eficiente, além de fornecer funcionalidades relevantes.

### Requisitos Funcionais:

1. Criação de registros: o sistema deverá permitir a criação de novos registros com base nas entidades definidas para o tema escolhido. Os dados inseridos pelo usuário devem ser validados antes de serem armazenados nos arquivos.

2. Leitura de registros: o sistema deverá possibilitar a leitura e consulta dos registros existentes nos arquivos, apresentando as informações de forma clara e organizada para o usuário.

3. Atualização de registros: o sistema deve permitir a atualização dos registros existentes nos arquivos, possibilitando a modificação dos dados armazenados de acordo com as necessidades do usuário.

4. Exclusão de registros: o sistema deverá permitir a exclusão de registros específicos, removendo-os dos arquivos e mantendo a integridade dos demais dados.

5. Persistência de dados: os registros devem ser armazenados em arquivos para garantir a persistência das informações. É importante implementar mecanismos de leitura e escrita de arquivos eficientes, levando em consideração a estrutura dos registros.

6. Interface de usuário: é recomendado implementar uma interface intuitiva para que o usuário possa interagir facilmente com o sistema. Utilize menus, opções numeradas ou qualquer outra forma de interação que facilite a utilização do sistema.

### Requisitos Não Funcionais:

1. Organização do código: o código-fonte do sistema deve ser organizado, bem estruturado e comentado de forma clara para facilitar a leitura e manutenção futura.

2. Tratamento de erros: o sistema deve ser capaz de tratar possíveis erros e exceções que possam ocorrer durante a execução, fornecendo mensagens adequadas para o usuário.

3. Documentação: é importante documentar o projeto, explicando as escolhas de implementação, estruturas de dados utilizadas e detalhes relevantes do código.

Neste documento, também deve conter os problemas e dificuldades encontradas durante a execução do trabalho.

### Estrutura do Relatório Final

Do relatório final deverão constar a identificação do trabalho e a identificação completa dos alunos que o realizaram. Este relatório deverá seguir as seguintes recomendações de estrutura:

1. Introdução - Identificação e descrição do trabalho e objetivos propostos.

2. Estruturas de Dados - definição das estruturas de dados utilizadas no programa.

3. Algoritmos - Apresentar o algoritmo de funcionamento global do programa. Para as funcionalidades fundamentais do programa, apresentar o(s) algoritmo(s) envolvidos. Os algoritmos devem ser descritos em Português Estruturado ou Fluxogramas.

4. Manual do Utilizador - Descrição das funcionalidades do programa apresentadas ao utilizador.

5. Conclusões - Apresentação das dificuldades que foram sentidas na execução do trabalho. Limitações do programa desenvolvido e funcionalidades que poderiam/deveriam ser modificadas/melhoradas.

# Tema: Gestão Comercial

O proprietário de uma loja pretende ter informatizada informação sobre os produtos que vende habitualmente e respectivos fornecedores. Terá que ser guardada informação sobre o nome do produto, a referência do produto, o nome do fornecedor, preço de compra do produto, preço de venda do produto e estoque existente. Note que cada produto pode ter mais do que um fornecedor (máximo 5), tendo para cada fornecedor um determinado preço de compra e prazo de entrega. Desenvolva um programa em Linguagem C que implemente uma aplicação para ajudar o proprietário da loja. A aplicação deverá manter num vector os dados dos produtos ordenados alfabeticamente, e conter as seguintes funcionalidades:

• Acrescentar produtos;

• Acrescentar fornecedor a um produto;

• Listar produtos;

• Retirar produtos;

• Alterar preço de compra de um produto a um determinado fornecedor;

• Alterar preço de venda de um produto;

• Pesquisar para um dado produto qual o fornecedor aconselhável;

• Pesquisar qual o produto que permite tirar o maior lucro;

• Verificar a possibilidade de satisfação da encomenda, de um dado produto em determinada no período previsto.