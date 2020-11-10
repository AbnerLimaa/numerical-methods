#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define TAMANHO_CABECALHO 3

static char cabecalho[TAMANHO_CABECALHO];
static char dimensoes_imagem[10];
static char* altura_imagem;
static char* largura_imagem;
static int altura;
static int largura;
static char max_pixel[4];
static int intervalo;

int convert_ascii_to_int(char* string)
{
    int tamanho = strlen(string);
    int multiplicador = 1;
    int soma = 0;
    if(tamanho > 0)
    {
        int i = tamanho - 1;
        while(i >= 0)
        {
            int digito = string[i] - 48;
            soma += (digito*multiplicador);
            multiplicador *= 10;
            i--;
        }
    }
    return soma;
}

char* cortar_string(char* fonte, int inicio, int fim)
{
    int tamanho = fim - inicio + 2;
    if(strlen(fonte) >= tamanho - 1)
    {
        int j = 0;
        char* texto = (char*)calloc(tamanho, sizeof(char));
        texto[tamanho - 1] = '\0';
        for(int i = inicio; i <= fim; i++)
        {
            texto[j] = fonte[i];
            j++;
        }
        return texto;
    }
    return NULL;
}

int derivada_forward(int fx1, int fx2)
{
    return fx2 - fx1;
}

int derivada_backward(int fx1, int fx2)
{
    return fx2 - fx1;
}

int derivada_central(int fx1, int fx2)
{
    return (fx2 - fx1) / 2;
}

void processar_imagem(FILE *imagem, int inicio_pixels)
{
    int ponteiro = inicio_pixels;
    char* buffer = (char*)calloc(largura, sizeof(char));
    char cr = '\r';
    fseek(imagem, inicio_pixels, SEEK_SET);
    FILE *imagem_processada = fopen("imagem_processada.pgm", "w");
    fprintf(imagem_processada, cabecalho, &cr);
    fseek(imagem_processada, 3, SEEK_SET);
    fprintf(imagem_processada, dimensoes_imagem, &cr);
    fseek(imagem_processada, 13, SEEK_SET);
    fprintf(imagem_processada, max_pixel, &cr);
    fseek(imagem_processada, inicio_pixels, SEEK_SET);
    for(int i = 0; i < altura; i++)
    {
        fread(buffer, largura, 1, imagem);
        int pixel_anterior = buffer[largura - 2];
        for(int j = 0; j < largura - 1; j++)
        {
            buffer[j] = derivada_forward(buffer[j], buffer[j + 1]);
        }
        buffer[largura - 1] = derivada_backward(pixel_anterior, buffer[largura - 1]);
        fwrite(buffer, largura, 1, imagem_processada);
        ponteiro += largura;
        fseek(imagem, ponteiro, SEEK_SET);
        fseek(imagem_processada, ponteiro, SEEK_SET);
    }
    fclose(imagem_processada);
}

void abrir_arquivo(char* arquivo)
{
    FILE *imagem = fopen(arquivo, "r");
    fgets(cabecalho, TAMANHO_CABECALHO, imagem);
    fseek(imagem, 3, SEEK_SET);

    fgets(dimensoes_imagem, 10, imagem);
    altura_imagem = cortar_string(dimensoes_imagem, 0, 3);
    largura_imagem = cortar_string(dimensoes_imagem, 5, 8);
    fseek(imagem, 13, SEEK_SET);

    fgets(max_pixel, 4, imagem);
    
    intervalo = convert_ascii_to_int(max_pixel);
    altura = convert_ascii_to_int(altura_imagem);
    largura = convert_ascii_to_int(largura_imagem);
    
    processar_imagem(imagem, 17);
    fclose(imagem);
}

int main(int argc, char* argv[])
{
    if(strstr(argv[1], ".pgm") != NULL)
        abrir_arquivo(argv[1]);
}