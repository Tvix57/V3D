#include "parser.h"

Model *getModel(char *filename) {
  FILE *input = fopen(filename, "r");

  Model *result = malloc(sizeof(Model));
  memset(result, 0, sizeof(Model));
  char str[128] = "";
  while (!feof(input)) {
    fgets(str, 128, input);
    if (str[0] != '#') {
      if (strstr(str, "v ")) result->vertex_count++;
      if (strstr(str, "f ")) result->face_count++;
    }
    memset(str, 0, 128);
  }

  fseek(input, 0, SEEK_SET);

  char ch;
  result->vertexes =
      (double *)malloc(result->vertex_count * 3 * sizeof(double));
  result->faces =
      (unsigned int *)malloc(result->face_count * 3 * sizeof(unsigned int));
  result->face_count *= 3;

  double xMax = 0;
  double xMin = 0;
  double yMax = 0;
  double yMin = 0;

  int i = 0, j = 0;
  while (!feof(input)) {
    fgets(str, 128, input);
    if (str[0] != '#') {
      if (strstr(str, "v ")) {
        sscanf(str, "%c %lf %lf %lf", &ch, &result->vertexes[i++],
               &result->vertexes[i++], &result->vertexes[i++]);
        if (result->vertexes[i - 3] > xMax) xMax = result->vertexes[i - 3];
        if (result->vertexes[i - 3] < xMin) xMin = result->vertexes[i - 3];
        if (result->vertexes[i - 2] > yMax) yMax = result->vertexes[i - 2];
        if (result->vertexes[i - 2] < yMin) yMin = result->vertexes[i - 2];
      }
      if (strstr(str, "f ")) {
        if (strchr(str, '/')) {
          char *token = strtok(str, " ");
          int k = 0;
          while (token != NULL && k < 4) {
            char buf[20] = "";
            if (*token >= '0' && *token <= '9') {
              strncpy(buf, token, strpbrk(token, "/\0") - token);
              result->faces[j++] = atoi(buf) - 1;
            }
            token = strtok(NULL, " ");
            k++;
          }
        } else {
          sscanf(str, "%c %d %d %d", &ch, &result->faces[j++],
                 &result->faces[j++], &result->faces[j++]);
        }
      }
    }
  }

  result->winWidth = fabs(xMax) + fabs(xMin);
  result->winHeight = fabs(yMax) + fabs(yMin);

  fclose(input);
  return result;
}

void clearModel(Model *obj) {
  if (obj != NULL) {
    if (obj->faces && obj->face_count > 0) {
      free(obj->faces);
    }
    if (obj->vertexes && obj->vertex_count > 0) {
      free(obj->vertexes);
    }

    free(obj);
  }
}
