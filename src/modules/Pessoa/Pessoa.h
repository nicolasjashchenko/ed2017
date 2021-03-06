#ifndef PESSOA__H
#define PESSOA__H

/*
Esse é o módulo que se encarrega de representar as pessoas da cidade e os
seus dados. As pessoas possuem vários dados, como cpf, nome, sobrenome,
entre outros.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../Celular/Celular.h"

typedef void* Pessoa;

Pessoa new_pessoa(char *cpf, char *nome, char *sobrenome, char sexo, char *nasc);
char *pessoa_get_cpf(Pessoa p);
char *pessoa_get_nome(Pessoa p);
char *pessoa_get_sobrenome(Pessoa p);
char pessoa_get_sexo(Pessoa p);
char *pessoa_get_nasc(Pessoa p);
Celular pessoa_get_celular(Pessoa p);
int cmp_pessoa_cpf(Pessoa p, void *cpf);
int cmp_pessoa_operadora(Pessoa p, void *op);
int cmp_pessoa_pessoa(Pessoa p, Pessoa r);
void pessoa_set_celular(Pessoa p, Celular celular);
void pessoa_imprime_dados(Pessoa p, FILE *out);

#endif