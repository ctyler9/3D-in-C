#ifndef GEO_H_
#define GEO_H_

typedef struct {
  float x, y, z, w;
} V4;

#define V4_Fmt "V4(%f, %f, %f, %f)"
#define V4_Arg(v4) v4.x, v4.y, v4.z, v4.w

V4 V4_add(V4 a, V4 b);

V4 V4_scale(V4 a, float s);

#define TRI_VERTICES 3
#define TRIS_PER_FACE 2
#define TRIS_PER_CUBE (CUBE_FACES * TRIS_PER_FACE)

typedef struct {
  V4 vs[TRI_VERTICES];
} Tri;

void tri_translate(Tri *tri, V4 dir);

void cube_face(float size, Tri side[TRIS_PER_FACE]);

#endif // GEO_H_
