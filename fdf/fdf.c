#include "fdf.h"

float mat1[4][4], mat2[4][4];
float matrix[4][4];

int SinTable[256];
int CosTable[256];

# define SIN(x) SinTable[abs((int)x&255)]
# define COS(x) CosTable[abs((int)x&255)]

void MAT_Copy(float source[4][4], float dest[4][4])
{
    int i,j;
    for(i=0; i<4; i++)
      for(j=0; j<4; j++)
         dest[i][j]=source[i][j];
}

void MAT_Mult(float mat1[4][4], float mat2[4][4], float dest[4][4])
{
   int i,j;
   for(i=0; i<4; i++)
      for(j=0; j<4; j++)
         dest[i][j]=mat1[i][0]*mat2[0][j]+
                    mat1[i][1]*mat2[1][j]+
                    mat1[i][2]*mat2[2][j]+
                    mat1[i][3]*mat2[3][j];
}

void VEC_MultMatrix(_3D *Source,float mat[4][4],_3D *Dest)
{
    Dest->x=Source->x*mat[0][0]+
            Source->y*mat[1][0]+
            Source->z*mat[2][0]+
                      mat[3][0];
    Dest->y=Source->x*mat[0][1]+
            Source->y*mat[1][1]+
            Source->z*mat[2][1]+
                      mat[3][1];
    Dest->z=Source->x*mat[0][2]+
            Source->y*mat[1][2]+
            Source->z*mat[2][2]+
                      mat[3][2];
}

void M3D_Init()
{
   int d;
   for(d=0; d<256; d++)
   {
       SinTable[d]=sin(d*M_PI/128.0);
       CosTable[d]=cos(d*M_PI/128.0);
   }
}
//start matrix transformations
void MAT_Identity(float mat[4][4])
{
    mat[0][0]=1; mat[0][1]=0; mat[0][2]=0; mat[0][3]=0;
    mat[1][0]=0; mat[1][1]=1; mat[1][2]=0; mat[1][3]=0;
    mat[2][0]=0; mat[2][1]=0; mat[2][2]=1; mat[2][3]=0;
    mat[3][0]=0; mat[3][1]=0; mat[3][2]=0; mat[3][3]=1;
}

void TR_Translate(float matrix[4][4],float tx,float ty,float tz)
{
   float tmat[4][4];
   tmat[0][0]=1;  tmat[0][1]=0;  tmat[0][2]=0;  tmat[0][3]=0;
   tmat[1][0]=0;  tmat[1][1]=1;  tmat[1][2]=0;  tmat[1][3]=0;
   tmat[2][0]=0;  tmat[2][1]=0;  tmat[2][2]=1;  tmat[2][3]=0;
   tmat[3][0]=tx; tmat[3][1]=ty; tmat[3][2]=tz; tmat[3][3]=1;
   MAT_Mult(matrix,tmat,mat1);
   MAT_Copy(mat1,matrix);
}

void TR_Scale(float matrix[4][4],float sx,float sy, float sz)
{
   float smat[4][4];
   smat[0][0]=sx; smat[0][1]=0;  smat[0][2]=0;  smat[0][3]=0;
   smat[1][0]=0;  smat[1][1]=sy; smat[1][2]=0;  smat[1][3]=0;
   smat[2][0]=0;  smat[2][1]=0;  smat[2][2]=sz; smat[2][3]=0;
   smat[3][0]=0;  smat[3][1]=0;  smat[3][2]=0;  smat[3][3]=1;
   MAT_Mult(matrix, smat, mat1);
   MAT_Copy(mat1, matrix);
}

void TR_Rotate(float matrix[4][4],int ax,int ay,int az)
{
   float xmat[4][4], ymat[4][4], zmat[4][4];
   xmat[0][0]=1;        xmat[0][1]=0;        xmat[0][2]=0;        xmat[0][3]=0;
   xmat[1][0]=0;        xmat[1][1]=COS(ax);  xmat[1][2]=SIN(ax);  xmat[1][3]=0;
   xmat[2][0]=0;        xmat[2][1]=-SIN(ax); xmat[2][2]=COS(ax);  xmat[2][3]=0;
   xmat[3][0]=0;        xmat[3][1]=0;        xmat[3][2]=0;        xmat[3][3]=1;

   ymat[0][0]=COS(ay);  ymat[0][1]=0;        ymat[0][2]=-SIN(ay); ymat[0][3]=0;
   ymat[1][0]=0;        ymat[1][1]=1;        ymat[1][2]=0;        ymat[1][3]=0;
   ymat[2][0]=SIN(ay);  ymat[2][1]=0;        ymat[2][2]=COS(ay);  ymat[2][3]=0;
   ymat[3][0]=0;        ymat[3][1]=0;        ymat[3][2]=0;        ymat[3][3]=1;

   zmat[0][0]=COS(az);  zmat[0][1]=SIN(az);  zmat[0][2]=0;        zmat[0][3]=0;
   zmat[1][0]=-SIN(az); zmat[1][1]=COS(az);  zmat[1][2]=0;        zmat[1][3]=0;
   zmat[2][0]=0;        zmat[2][1]=0;        zmat[2][2]=1;        zmat[2][3]=0;
   zmat[3][0]=0;        zmat[3][1]=0;        zmat[3][2]=0;        zmat[3][3]=1;

   MAT_Mult(matrix,ymat,mat1);
   MAT_Mult(mat1,xmat,mat2);
   MAT_Mult(mat2,zmat,matrix);
}
//end matrix transformations
//display 3D world
void Project(vertex_t * Vertex)
{
   if(!Vertex->Aligned.z)
	  Vertex->Aligned.z = 1;
   Vertex->Screen.x = FOCAL_DISTANCE * Vertex->Aligned.x / Vertex->Aligned.z + 200;
   Vertex->Screen.y = FOCAL_DISTANCE * Vertex->Aligned.y / Vertex->Aligned.z + 200;
}

int main()
{
  vertex_t *map;
  vertex_t *world;
  vertex_t *aligned;
  aligned = malloc(sizeof(vertex_t *));
  world = malloc(sizeof(vertex_t *));
  map = malloc(sizeof(vertex_t *));
  map->Local.x = 1;
  map->Local.y = 10;
  map->Local.z = 1;
  MAT_Identity(matrix);
  TR_Scale(matrix, map->Local.x, map->Local.y, map->Local.z);
  TR_Rotate(matrix, map->Local.x, map->Local.y, map->Local.z);
  TR_Translate(matrix, map->Local.x, map->Local.y, map->Local.z);
  VEC_MultMatrix(&map->Local, matrix, &world->World);
  MAT_Identity(matrix);
  TR_Translate(matrix, (float)-10, (float)-10, (float)0);
  TR_Rotate(matrix, (float)-10, (float)-10, (float)0);
  VEC_MultMatrix(&world->World, matrix, &aligned->Aligned);
  //Project(aligned);
  printf("%f\n", map->Local.x);
  printf("%f\n", map->Local.y);
  printf("%f\n", map->Local.z);
  printf("%f\n", world->World.x);
  printf("%f\n", world->World.y);
  printf("%f\n", world->World.z);
  printf("%f\n", aligned->Screen.x);
  printf("%f\n", aligned->Screen.y);
}
