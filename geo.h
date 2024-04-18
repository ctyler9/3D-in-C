#include <stdio.h>

#ifndef GEO_H_
#define GEO_H_

#define X 0
#define Y 1
#define Z 2
#define W 3

#define V3_COMPS 3
#define V4_COMPS 4
#define PAIR_COMPS 2

typedef struct {
  float cs[V4_COMPS];
} V4;

#define V4_Fmt "V4(%f, %f, %f, %f)"
#define V4_Arg(v4) v4.cs[X], v4.cs[Y], v4.cs[Z], v4.cs[W]

V4 V4_add(V4 a, V4 b);
V4 V4_scale(V4 a, float s);

#define CUBE_FACE_PAIRS 3
#define CUBE_FACES (CUBE_FACE_PAIRS * PAIR_COMPS)

#define TRI_VERTICES 3
#define TRIS_PER_FACE 2
#define TRIS_PER_CUBE (CUBE_FACES * TRIS_PER_FACE)

typedef struct {
  V4 vs[TRI_VERTICES];
} Tri;

void tri_translate(Tri *tri, V4 dir);

void square(Tri mesh[TRIS_PER_FACE], size_t a, size_t b);
void cube_face(size_t a, size_t b, size_t c, float cv, Tri mesh[TRIS_PER_FACE]);
size_t cube(Tri mesh[TRIS_PER_CUBE]);

#endif // GEO_H_
