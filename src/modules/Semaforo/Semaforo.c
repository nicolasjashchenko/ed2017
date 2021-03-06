#include "Semaforo.h"

typedef struct semaforo {
  double x, y, ciclo;
  char id[100], fill[100], stroke[100];
}* StSemaforo;

Semaforo new_semaforo(double x, double y, char *id, char *fill, char *stroke) {
  StSemaforo s = malloc(sizeof(struct semaforo));
  Semaforo semaforo = s;
  s->x = x;
  s->y = y;
  s->ciclo = 0;
  strcpy(s->id, id);
  strcpy(s->fill, fill);
  strcpy(s->stroke, stroke);
  return semaforo;
}

double semaforo_get_x(Semaforo s) {
  StSemaforo semaforo = (StSemaforo) s;
  return semaforo->x;
}

double semaforo_get_y(Semaforo s) {
  StSemaforo semaforo = (StSemaforo) s;
  return semaforo->y;
}

double semaforo_get_ciclo(Semaforo s) {
  StSemaforo semaforo = (StSemaforo) s;
  return semaforo->ciclo;
}

char* semaforo_get_id(Semaforo s) {
  StSemaforo semaforo = (StSemaforo) s;
  return semaforo->id;
}

char* semaforo_get_fill(Semaforo s) {
  StSemaforo semaforo = (StSemaforo) s;
  return semaforo->fill;
}

char* semaforo_get_stroke(Semaforo s) {
  StSemaforo semaforo = (StSemaforo) s;
  return semaforo->stroke;
}

void semaforo_set_ciclo(Semaforo s, double ciclo) {
  StSemaforo semaforo = (StSemaforo) s;
  semaforo->ciclo = ciclo;
}

int semaforo_inside_circ(Semaforo s, void *circ) {
  Circ *c = (Circ*) circ;
  return circ_interno(*c, semaforo_get_x(s), semaforo_get_y(s));
}

int semaforo_inside_rect(Semaforo s, void *rect) {
  Rect *r = (Rect*) rect;
  return rect_interno(*r, semaforo_get_x(s), semaforo_get_y(s));
}

void semaforo_print_xy(FILE *f, Semaforo s) {
  fprintf(f, "Semaforo - x: %f y: %f\n", semaforo_get_x(s), semaforo_get_y(s));
}
