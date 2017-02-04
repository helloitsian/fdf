#ifndef FDF_H
# define FDF_H
# define FOCAL_DISTANCE 200

# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct
{
   short x, y;
} _2D;

typedef struct
{
   float x, y, z;
} _3D;

typedef struct
{
   _3D Local;
   _3D World;
   _3D Screen;
   _3D Aligned;
} vertex_t;

#endif
