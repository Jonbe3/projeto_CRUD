#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes para definir o tamanho da tela
#define LINHAS 24
#define COLUNAS 80

// Função para limpar a tela do terminal
void limpar_tela() {
    system("cls");
}
// Função para posicionar o cursor na posição especificada
void posicionar_cursor(int linha, int coluna) {
    printf("\033[%d;%df", linha, coluna);
}
// Função para imprimir um caractere na posição especificada
void imprimir_caractere(int linha, int coluna, char caractere) {
    posicionar_cursor(linha, coluna);
    putchar(caractere);
    fflush(stdout);
}
// Função para imprimir uma string na posição especificada
void imprimir_string(int linha, int coluna, const char* string) {
    posicionar_cursor(linha, coluna);
    printf("%s", string);
    fflush(stdout);
}
// Função para imprimir um número inteiro na posição especificada
void imprimir_inteiro(int linha, int coluna, int numero) {
    posicionar_cursor(linha, coluna);
    printf("%d", numero);
    fflush(stdout);
}
// Função para imprimir um número decimal na posição especificada
void imprimir_decimal(int linha, int coluna, float numero) {
    posicionar_cursor(linha, coluna);
    printf("%.2f", numero);
    fflush(stdout);
}
// Função para inicializar a tela do terminal
void inicializar_tela() {
    limpar_tela();
}
// Função para desenhar uma janela na tela
void janela(int lin_inicial, int col_inicial, int lin_final, int col_final, const char* titulo, int tipo_moldura) {
    // Implemente o código para desenhar a janela conforme as especificações
}
// Função para exibir um label na tela
void label(int linha, int coluna, const char* texto) {
    imprimir_string(linha, coluna, texto);
}
// Função para ler uma string da tela
void ler_string(int linha, int coluna, int tamanho, char* destino) {
    posicionar_cursor(linha, coluna);
    fgets(destino, tamanho, stdin);
    destino[strcspn(destino, "\n")] = '\0'; // Remover o caractere de nova linha (\n) da string lida
}
// Função para ler um número inteiro da tela
int ler_inteiro(int linha, int coluna, int tamanho) {
    char buffer[tamanho + 1];
    ler_string(linha, coluna, tamanho, buffer);
    return atoi(buffer);
}
// Função para ler um número decimal da tela
float ler_decimal(int linha, int coluna, int tamanho) {
    char buffer[tamanho + 1];
    ler_string(linha, coluna, tamanho, buffer);
    return atof(buffer);
}
int main() {
    // Exemplo de uso das funções
    
    inicializar_tela();
    janela(5, 10, 15, 50, "Minha Janela", 1);
    label(7, 12, "Digite seu nome:");
    char nome[51];
    ler_string(8, 12, 50, nome);
    label(10, 12, "Digite sua idade:");
    int idade = ler_inteiro(11, 12, 3);
    label(13, 12, "Digite um valor decimal:");
    float valor = ler_decimal(14, 12, 10);
    limpar_tela();
    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    printf("Valor: %.2f\n", valor);
    
    return 0;
}