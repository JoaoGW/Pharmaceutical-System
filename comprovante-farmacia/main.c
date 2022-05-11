#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main()
{
    //Pegando as informações de carecteres por região
    setlocale(LC_ALL, "Portuguese");

    //Varíaveis de Armazenamento dos Dados Básicos
    char nomeCliente[30];
    char enderecoCliente[40];
    int telefoneCliente = 0;
    int rgCliente = 0;
    int cpfCliente = 0;
    char nomeMedico [30];
    int crmMedico = 0;
    char nomeVendedor [30];
    int usuarioVendedor = 0;


    //Variáveis de Armazenamento dos Produtos e seus valores
    int codigoProdutos;
    float valor;
    float desconto = 0;
    float valorFinal = 0;
    int qtdProdutos = 0;
    int inseridos = 0;


    //Outros valores e variáveis
    int itens = 0;


    //Sistema de Login do Atendente
    char login [15]= "atendente01";
    char senha [15]= "meucachorro";
    char logininserido [15];
    char senhainserida[15];
    int numtentativas = 1;
    int loginrealizado = 0;


    //Inicialização do Sistema de Login
    printf("Faça Login para Continuar...\n\n");
    sleep(1);
    do{
    printf("Insira o seu Login de Funcionário:");
    scanf("%s", logininserido);
    sleep(1);

    printf("Insira a sua senha de Funcionário:");
    scanf("%s", senhainserida);
    sleep(1);

    if(numtentativas < 3) {
        if (strcmp(login, logininserido) == 0 && strcmp(senha, senhainserida) == 0) {
            printf("Você foi logado(a) com sucesso!\n\n");
            loginrealizado = 1;
            sleep(2);
        }else {
            printf("Os dados que você inseriu estão incorretos, tente novamente\n\n");
            numtentativas += 1;
        }
    }
    else {
        printf("Você atingiu o número máximo de tentativas de login\n");
        sleep(1);
        printf("Reiniciando o Sistema por Métodos de Segurança\n");
        exit(1);
        }
    }
    while(loginrealizado != 1);

    //Inicialização
    printf("-----------------------------------------------------------------\n");
    printf("Sistema de Recibos de Farmácias para Windows -  V1.1\n\n");
    printf("Farmácia de Manipulação XYZ - Bairro Sul\n");
    printf("Alameda das Farmácias -  São Paulo - SP      FONE: 2383-1831\n");
    printf("Dr. Andrezinho de Jesus da Silva             CRF: 01010\n");
    printf("-----------------------------------------------------------------\n\n");

    //Segunda parte do corpo
    time_t t;
    time(&t);
    printf("Horário e Data da Execução do Programa: %s\n", ctime(&t));

    //Pegando as informações básicas sobre o Cliente e o Médico Responsável do dia
    //Nome Completo do Cliente
    printf("Insira o Primeiro Nome do Cliente: ");
    scanf("%s", nomeCliente);
    printf("Dados Salvos com Sucesso! %s\n", nomeCliente);

    //Endereço do Cliente
    printf("Insira o Endereço do Cliente: (sem espaços)");
    scanf("%s", enderecoCliente);
    printf("Dados Salvos com Sucesso! %s\n", enderecoCliente);

    //Telefone ou celular do Cliente
    printf("Insira o Número de Telefone do Cliente: ");
    scanf("%d", &telefoneCliente);
    printf("Dados Salvos com Sucesso! +55%d\n", telefoneCliente);

    //Número de Registro Civil do Cliente
    printf("Insira o RG do Cliente: ");
    scanf("%d", &rgCliente);
    printf("Dados Salvos com Sucesso! %d\n", rgCliente);

    //Número de Pessoa Física do Cliente
    printf("Insira o Número do CPF do Cliente: ");
    scanf("%d", &cpfCliente);
    printf("Dados Salvos com Sucesso! %d\n", cpfCliente);

    //Nome do Médico Responsável pelas concordâncias no dia
    printf("Insira o Primeiro Nome do Médico Responsável no dia: ");
    scanf("%s", nomeMedico);
    printf("Dados Salvos com Sucesso! %s\n", nomeMedico);

    //CRM do Médico
    printf("Insira o CRM do Médico Responsável: ");
    scanf("%d", &crmMedico);
    printf("Dados Salvos com Sucesso! %d\n", crmMedico);

    //Nome Completo do Atendente/Vendedor
    printf("Insira o Primeiro Nome de quem está vendendo: ");
    scanf("%s", nomeVendedor);
    printf("Dados Salvos com Sucesso! %s\n", nomeVendedor);

    //Número de Usuário do Atendente/Vendedor
    printf("Vendedor, Insira o seu Usuário: ");
    scanf("%d", &usuarioVendedor);
    printf("Dados Salvos com Sucesso! %d\n", usuarioVendedor);

    //Quantidade de Produtos Diferentes que serão utilizados pelo cliente
    printf("Atendente, quantos produtos diferentes o cliente necessita na receita dele? ");
    scanf("%d", &qtdProdutos);
    printf("-----------------------------------------------------------------\n\n");


    //Cálculo dos Valores dos Produtos e seus Descontos
    do {
        printf("Insira o Código do Produto que será utilizado\n");
        scanf("%d", &codigoProdutos);
        itens += 1;
        printf("Qual o Valor deste Produto?");
        scanf("%f", &valor);
        valorFinal = valorFinal + valor;
        printf("Insira o Valor do Desconto (em reais):");
        scanf("%f", &desconto);
        valorFinal = valorFinal - desconto;
        inseridos += 1;
    }
    while(inseridos < qtdProdutos);

    //Apresentação do Valor Final da Compra
    printf("-----------------------------------------------------------------\n\n");
    printf("O Valor Final da Compra é de: %.2f Reais Brasileiros\n", valorFinal);
    printf("Gerando Recibo/Comprovante...\n");
    sleep(4);
    printf("=================================================================\n\n\n");

    //Impressão do Comprovante de Compra para o Cliente:
    //Cabeçalho do Recibo
    printf("Recibo do Cliente\n");
    printf("-----------------------------------------------------------------\n");
    printf("Sistema de Recibos de Farmácias para Windows -  V1.1\n\n");
    printf("Farmácia de Manipulação XYZ - Bairro Sul\n");
    printf("Alameda das Farmácias -  São Paulo - SP      FONE: 2383-1831\n");
    printf("Dr. Andrezinho de Jesus da Silva             CRF: 01010\n");
    printf("-----------------------------------------------------------------\n\n");

    //Segunda Parte do Recibo
    printf("Horário e Data da Impressão do Recibo: %s\n", ctime(&t));
    printf("Nome: %s\n", nomeCliente);
    printf("Endereço: %s\n", enderecoCliente);
    printf("Fone: %d\n", telefoneCliente);
    printf("RG: %d                CPF: %d\n", rgCliente, cpfCliente);
    printf("Dr(a). %s             CRM: %d\n", nomeMedico, crmMedico);
    printf("Vendedor(a): %s       Usuário: %d\n", nomeVendedor, usuarioVendedor);
    printf("-----------------------------------------------------------------\n\n");

    //Terceira Parte do Recibo
    printf("Total em Descontos: R$ %.2f", desconto);
    printf("Valor a Pagar: R$ %.2f\n", valorFinal);
    printf("Sinal R$___________\n");
    printf("Cartão__________ Tipo: ()Crédito ()Débito ()Dinheiro\n");
    printf("Retirada Disponível em: ________________\n");
    printf("Quantidade de Itens: %d\n", qtdProdutos);
    printf("Atendente/Vendedor(a): %s\n", nomeVendedor);
    printf("-----------------------------------------------------------------\n\n");

    //Quarta Parte do Recibo
    printf("Na encomenda ou na retirada de seus produtos, traga este papel\n");
    printf("dentro do prazo de retirada máximo de 30 dias\n");
    printf("Assinado: ___________________\n");
    printf("Aprovado por: ____________________\n");

    return 0;
}
