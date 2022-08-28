#ifndef SRC_INCLUDE_PARSER_H_
#define SRC_INCLUDE_PARSER_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned int vertex_count;
  unsigned int face_count;
  double *vertexes;
  unsigned int *faces;
  double winWidth;
  double winHeight;
} Model;

Model *getModel(char *filename);
void clearModel(Model *obj);

#endif  // SRC_INCLUDE_PARSER_H_
