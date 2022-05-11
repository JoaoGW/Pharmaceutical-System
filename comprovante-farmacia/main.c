#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main()
{
    //Pegando as informa��es de carecteres por regi�o
    setlocale(LC_ALL, "Portuguese");

    //Var�aveis de Armazenamento dos Dados B�sicos
    char nomeCliente[30];
    char enderecoCliente[40];
    int telefoneCliente = 0;
    int rgCliente = 0;
    int cpfCliente = 0;
    char nomeMedico [30];
    int crmMedico = 0;
    char nomeVendedor [30];
    int usuarioVendedor = 0;


    //Vari�veis de Armazenamento dos Produtos e seus valores
    int codigoProdutos;
    float valor;
    float desconto = 0;
    float valorFinal = 0;
    int qtdProdutos = 0;
    int inseridos = 0;


    //Outros valores e vari�veis
    int itens = 0;


    //Sistema de Login do Atendente
    char login [15]= "atendente01";
    char senha [15]= "meucachorro";
    char logininserido [15];
    char senhainserida[15];
    int numtentativas = 1;
    int loginrealizado = 0;


    //Inicializa��o do Sistema de Login
    printf("Fa�a Login para Continuar...\n\n");
    sleep(1);
    do{
    printf("Insira o seu Login de Funcion�rio:");
    scanf("%s", logininserido);
    sleep(1);

    printf("Insira a sua senha de Funcion�rio:");
    scanf("%s", senhainserida);
    sleep(1);

    if(numtentativas < 3) {
        if (strcmp(login, logininserido) == 0 && strcmp(senha, senhainserida) == 0) {
            printf("Voc� foi logado(a) com sucesso!\n\n");
            loginrealizado = 1;
            sleep(2);
        }else {
            printf("Os dados que voc� inseriu est�o incorretos, tente novamente\n\n");
            numtentativas += 1;
        }
    }
    else {
        printf("Voc� atingiu o n�mero m�ximo de tentativas de login\n");
        sleep(1);
        printf("Reiniciando o Sistema por M�todos de Seguran�a\n");
        exit(1);
        }
    }
    while(loginrealizado != 1);

    //Inicializa��o
    printf("-----------------------------------------------------------------\n");
    printf("Sistema de Recibos de Farm�cias para Windows -  V1.1\n\n");
    printf("Farm�cia de Manipula��o XYZ - Bairro Sul\n");
    printf("Alameda das Farm�cias -  S�o Paulo - SP      FONE: 2383-1831\n");
    printf("Dr. Andrezinho de Jesus da Silva             CRF: 01010\n");
    printf("-----------------------------------------------------------------\n\n");

    //Segunda parte do corpo
    time_t t;
    time(&t);
    printf("Hor�rio e Data da Execu��o do Programa: %s\n", ctime(&t));

    //Pegando as informa��es b�sicas sobre o Cliente e o M�dico Respons�vel do dia
    //Nome Completo do Cliente
    printf("Insira o Primeiro Nome do Cliente: ");
    scanf("%s", nomeCliente);
    printf("Dados Salvos com Sucesso! %s\n", nomeCliente);

    //Endere�o do Cliente
    printf("Insira o Endere�o do Cliente: (sem espa�os)");
    scanf("%s", enderecoCliente);
    printf("Dados Salvos com Sucesso! %s\n", enderecoCliente);

    //Telefone ou celular do Cliente
    printf("Insira o N�mero de Telefone do Cliente: ");
    scanf("%d", &telefoneCliente);
    printf("Dados Salvos com Sucesso! +55%d\n", telefoneCliente);

    //N�mero de Registro Civil do Cliente
    printf("Insira o RG do Cliente: ");
    scanf("%d", &rgCliente);
    printf("Dados Salvos com Sucesso! %d\n", rgCliente);

    //N�mero de Pessoa F�sica do Cliente
    printf("Insira o N�mero do CPF do Cliente: ");
    scanf("%d", &cpfCliente);
    printf("Dados Salvos com Sucesso! %d\n", cpfCliente);

    //Nome do M�dico Respons�vel pelas concord�ncias no dia
    printf("Insira o Primeiro Nome do M�dico Respons�vel no dia: ");
    scanf("%s", nomeMedico);
    printf("Dados Salvos com Sucesso! %s\n", nomeMedico);

    //CRM do M�dico
    printf("Insira o CRM do M�dico Respons�vel: ");
    scanf("%d", &crmMedico);
    printf("Dados Salvos com Sucesso! %d\n", crmMedico);

    //Nome Completo do Atendente/Vendedor
    printf("Insira o Primeiro Nome de quem est� vendendo: ");
    scanf("%s", nomeVendedor);
    printf("Dados Salvos com Sucesso! %s\n", nomeVendedor);

    //N�mero de Usu�rio do Atendente/Vendedor
    printf("Vendedor, Insira o seu Usu�rio: ");
    scanf("%d", &usuarioVendedor);
    printf("Dados Salvos com Sucesso! %d\n", usuarioVendedor);

    //Quantidade de Produtos Diferentes que ser�o utilizados pelo cliente
    printf("Atendente, quantos produtos diferentes o cliente necessita na receita dele? ");
    scanf("%d", &qtdProdutos);
    printf("-----------------------------------------------------------------\n\n");


    //C�lculo dos Valores dos Produtos e seus Descontos
    do {
        printf("Insira o C�digo do Produto que ser� utilizado\n");
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

    //Apresenta��o do Valor Final da Compra
    printf("-----------------------------------------------------------------\n\n");
    printf("O Valor Final da Compra � de: %.2f Reais Brasileiros\n", valorFinal);
    printf("Gerando Recibo/Comprovante...\n");
    sleep(4);
    printf("=================================================================\n\n\n");

    //Impress�o do Comprovante de Compra para o Cliente:
    //Cabe�alho do Recibo
    printf("Recibo do Cliente\n");
    printf("-----------------------------------------------------------------\n");
    printf("Sistema de Recibos de Farm�cias para Windows -  V1.1\n\n");
    printf("Farm�cia de Manipula��o XYZ - Bairro Sul\n");
    printf("Alameda das Farm�cias -  S�o Paulo - SP      FONE: 2383-1831\n");
    printf("Dr. Andrezinho de Jesus da Silva             CRF: 01010\n");
    printf("-----------------------------------------------------------------\n\n");

    //Segunda Parte do Recibo
    printf("Hor�rio e Data da Impress�o do Recibo: %s\n", ctime(&t));
    printf("Nome: %s\n", nomeCliente);
    printf("Endere�o: %s\n", enderecoCliente);
    printf("Fone: %d\n", telefoneCliente);
    printf("RG: %d                CPF: %d\n", rgCliente, cpfCliente);
    printf("Dr(a). %s             CRM: %d\n", nomeMedico, crmMedico);
    printf("Vendedor(a): %s       Usu�rio: %d\n", nomeVendedor, usuarioVendedor);
    printf("-----------------------------------------------------------------\n\n");

    //Terceira Parte do Recibo
    printf("Total em Descontos: R$ %.2f", desconto);
    printf("Valor a Pagar: R$ %.2f\n", valorFinal);
    printf("Sinal R$___________\n");
    printf("Cart�o__________ Tipo: ()Cr�dito ()D�bito ()Dinheiro\n");
    printf("Retirada Dispon�vel em: ________________\n");
    printf("Quantidade de Itens: %d\n", qtdProdutos);
    printf("Atendente/Vendedor(a): %s\n", nomeVendedor);
    printf("-----------------------------------------------------------------\n\n");

    //Quarta Parte do Recibo
    printf("Na encomenda ou na retirada de seus produtos, traga este papel\n");
    printf("dentro do prazo de retirada m�ximo de 30 dias\n");
    printf("Assinado: ___________________\n");
    printf("Aprovado por: ____________________\n");

    return 0;
}
