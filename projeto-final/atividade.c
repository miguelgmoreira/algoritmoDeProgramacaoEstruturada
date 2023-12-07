#include <stdio.h>
#include <string.h>

struct registro {
  char proprietario[50];
  char combustivel[10];
  char modelo[50];
  char cor[20];
  char chassi[20];
  int ano;
  char placa[8];
  struct registro *proximo;
};

void inserir_registro(struct registro **inicio, char *proprietario, char *combustivel, char *modelo, char *cor, char *chassi, int ano, char *placa) {
  struct registro *novo = malloc(sizeof(struct registro));
  strcpy(novo->proprietario, proprietario);
  strcpy(novo->combustivel, combustivel);
  strcpy(novo->modelo, modelo);
  strcpy(novo->cor, cor);
  strcpy(novo->chassi, chassi);
  novo->ano = ano;
  strcpy(novo->placa, placa);
  novo->proximo = NULL;

  if (*inicio == NULL) {
    *inicio = novo;
  } else {
    struct registro *no = *inicio;
    while (no->proximo != NULL) {
      no = no->proximo;
    }
    no->proximo = novo;
  }
}

void imprimir_lista(struct registro *inicio) {
  struct registro *no = inicio;

  while (no != NULL) {
    printf("Proprietário: %s\n", no->proprietario);
    printf("Combustível: %s\n", no->combustivel);
    printf("Modelo: %s\n", no->modelo);
    printf("Cor: %s\n", no->cor);
    printf("Chassi: %s\n", no->chassi);
    printf("Ano: %d\n", no->ano);
    printf("Placa: %s\n", no->placa);
    no = no->proximo;
  }
}

void listar_proprietarios_diesel_2010(struct registro *inicio) {
  struct registro *no = inicio;

  while (no != NULL) {
    if (no->combustivel == "diesel" && no->ano >= 2010) {
      printf("Proprietário: %s\n", no->proprietario);
    }
    no = no->proximo;
  }
}

void listar_placas_J(struct registro *inicio) {
  struct registro *no = inicio;

  while (no != NULL) {
    if (no->placa[0] == 'J' && (no->placa[3] == '0' || no->placa[3] == '2' || no->placa[3] == '4' || no->placa[3] == '7')) {
      printf("Placa: %s\n", no->placa);
    }
    no = no->proximo;
  }
}

void listar_modelo_cor(struct registro *inicio) {
  struct registro *no = inicio;

  while (no != NULL) {
    if (isalpha(no->placa[1]) && (no->placa[0] + no->placa[1] + no->placa[2] + no->placa[3] + no->placa[4] + no->placa[5]) % 2 == 0) {
      printf("Modelo: %s\nCor: %s\n", no->modelo, no->cor);
    }
    no = no->proximo;
  }
}

void trocar_proprietario(struct registro *inicio, char *chassi, char *novo_proprietario) {
  struct registro *no = inicio;

  while (no != NULL) {
    if (strcmp(no->chassi, chassi) == 0) {
      strcpy(no->proprietario, novo_proprietario);
      return;
    }
    no = no->proximo;
  }

  printf("Carro não encontrado.\n");
}