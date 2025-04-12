#ifndef GESTIONES_HPP
#define GESTIONES_HPP

#include <vector>

double EvaluacionEstandar(const std::vector<int>& coeficiente, double x);
double evaluarHorner(const std::vector<int>& coeficiente, double x);
std::vector<int> generarcoeficientes(int grado);
double generarX();

#endif
