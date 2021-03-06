// AUTOR:       Diego Vázquez Campos
// FECHA:       22/05/2020
// EMAIL:       alu0101014326@ull.edu.es
// VERSION:     1.0
// ASIGNATURA:  Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 6
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once 

#include <iostream>
#include "matrix_t.hpp"
#include "queue_l_t.hpp"
#include "pair_t.hpp"

#define TRACE(x) cout << (#x) << "= " << (x) << endl


#define PASS_ID  0 // indica pasillo
#define WALL_ID  1 // indica pared
#define PATH_ID  2 // indica camino de salida
#define START_ID 8 // indica inicio del laberinto
#define END_ID   9 // indica la salida del laberinto

// caracteres usados para mostrar el laberinto por pantalla
#define WALL_CHR  "█"
#define PASS_CHR  " "
#define PATH_CHR  "·"
#define START_CHR "A"
#define END_CHR   "B"

using namespace std;
using namespace AED;

typedef matrix_t<short> matrix_t_short;
typedef matrix_t<bool> matrix_t_bool;
typedef queue_l_t<pair_t<short>> qop; // queue of pairs

// enumera las direcciones Norte, Este, Sur y Oeste (West)
enum direction_t {N, E, S, W};

// define vectores de desplazamiento en las 4 direcciones:
//                      N   E  S   W
const short i_d[] = { -1, 0, 1,  0};
const short j_d[] = {  0, 1, 0, -1};

//                   N   E  S   W
//const short i_d[] = {1, -1, 1, -1, -1, 0, 1,  0};
//const short j_d[] = {1, -1, -1, 1, 0, 1, 0, -1};


class maze_t 
{
private:
  matrix_t_short matrix_; // matriz que guarda los valores leídos de la entrada
  matrix_t_bool visited_; // matriz que guarda si una celda ha sido visitada o no
  int i_start_, j_start_, i_end_, j_end_; // guarda las filas y columnas de entrada (start) y salida (end)
  qop sol_; // guarda el camino de la solución

  matrix_t_short deadends_;
  

public:
  // constructor y destructor
  maze_t(void);
  ~maze_t();

  // método para resolver el laberinto y que invoca al otro método recursivo
  bool solve(void);
  

  istream& read(istream& = cin);
  ostream& write(ostream& = cout) const;
  void print_sol(ostream& = cout);

  int contar_muros(void);
  void centrar(void);
  
private:
  bool is_ok_(const int, const int) const;
  bool solve_(const int, const int, int &count);
};

istream& operator>>(istream&, maze_t&);
ostream& operator<<(ostream&, const maze_t&);