#include "./geo.h"
#include <stdio.h>
// #include <stdlib.h>

V4 V4_add(V4 a, V4 b) {
  return (V4){
      .x = a.x + b.x,
      .y = a.y + b.y,
      .z = a.z + b.z,
      .w = a.w + b.w,
  };
}

V4 V4_scale(V4 a, float s) {
  return (V4){
      .x = a.x * s,
      .y = a.y * s,
      .z = a.z * s,
      .w = a.w * s,
  };
}

void cube_face(float size, Tri face[TRIS_PER_FACE]) {
  for (size_t i = 0; i < TRIS_PER_FACE; ++i) {
    for (size_t j = 0; j < TRI_VERTICES; ++j) {
      size_t k = i + j;
      face[i].vs[j].x = (float)(k & 1) * size;
      face[i].vs[j].y = (float)(k >> 1) * size;
      face[i].vs[j].z = 0.0f;
      face[i].vs[j].w = 0.0f;
    }
  }
}

void tri_translate(Tri *tri, V4 dir) {

  for (size_t i = 0; i < TRI_VERTICES; ++i) {
    tri->vs[i] = v4_add(tri->vs[i], dir);
  }
}

void cube(float size, Tri cube[TRIS_PER_CUBE]) {
  size_t count = 0;

  Tri face[TRIS_PER_FACE];
  cube_face(size_face);

  cube[count++] = face[0];
  cube[count++] = face[1];
}
