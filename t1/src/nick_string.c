char *monta_arquivo(char *dir, char *a, char *e) {
  char *str = malloc(sizeof(char) * (strlen(dir) + strlen(a) + strlen(e) + 1));
  sprintf(str, "%s%s.%s", dir, a, e);
  return str;
}

char *pega_path(char *str) {
  char *buffer = malloc(MAX_BUFFER * sizeof(char));
  sscanf(str, "%*c%*c%s", buffer);
  return buffer;
}

char *substitui_str(char *str, char *new) {
  free(str);
  str = malloc(sizeof(char) * (strlen(new) + 1));
  strcpy(str, new);
  return str;
}

char *limpa(char *str) {
  free(str);
  return alloc_inicial();
}

char *alloc_inicial() {
  char *str = malloc(sizeof(char));
  *str = 0;
  return str;
}

char *concatena(char *inicio, char *fim) {
  inicio = (char *) realloc(inicio, sizeof(char) * (strlen(inicio) + strlen(fim) + 1));
  inicio = strcat(inicio, fim);
  return inicio;
}

char *pega_string(char *str) {
  char *buffer = malloc(MAX_BUFFER * sizeof(char));
  sscanf(str, "%*c%*c\"%[^\"]", buffer);
  return buffer;
}

int interpreta(char *str) {
  //retorna a opcao
  switch (str[0]) {
    case 'x':
      return 1;
      break;
    case 'y':
      return 2;
      break;
    case 'z':
      return 3;
      break;
    case 'l':
      switch (str[1]) {
        case 'x':
          return 4;
          break;
        case 'y':
          return 5;
          break;
        case 'z':
          return 6;
          break;
      }
      break;
    case 'd':
      return 7;
      break;
    case 'a':
      return 8;
      break;
    case 'e':
      return 9;
      break;
    case 'c':
      return 10;
      break;
    case 'o':
      return 11;
      break;
    case 'w':
      return 12;
      break;
    case 'f':
      return 13;
      break;
    default:
      return 0;
  }
}

char *le_linha(FILE *f) {
  char *str = malloc(MAX_BUFFER * sizeof(char));
  fgets(str, MAX_BUFFER, f);
  return str;
}

char *arruma_dir(char *dir) {
  if (dir[strlen(dir) - 1] != '/') {
    dir = concatena(dir, "/");
  }
  return dir;
}

char *verifica_quebras(char *str) {
  int i;
  for (i = 0; i < strlen(str); i++) {
    if (str[i] == '\\' && str[i + 1] == 'n') {
      str[i] = ' ';
      str[i + 1] = '\n';
    }
  }
}
