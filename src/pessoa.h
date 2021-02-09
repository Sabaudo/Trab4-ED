#ifndef PESSOA__H
#define PESSOA__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *Pessoa;
Pessoa criarPessoa (char cpf[], char nome[], char sobrenome[], char sexo[], char nascimento[]);

char* getPessoaCpf (Pessoa p);
char* getPessoaName (Pessoa p);
char* getPessoaLastName (Pessoa p);
char* getPessoaSexo (Pessoa p);
char* getPessoaNascimento (Pessoa p);

void destroiPessoa(Pessoa p);

#endif