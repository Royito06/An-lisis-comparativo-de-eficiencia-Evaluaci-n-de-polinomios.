#include <cmath>
#include <random>

#include "Gestion.h"


double EvaluacionEstandar(const std::vector<int>& coeficiente, double x) {
    double resultado = 0.0;
    int grado = coeficiente.size() - 1;
    for (int i = 0; i <= grado; ++i) {
        resultado += coeficiente[i] * std::pow(x, grado - i);
    }
    return resultado;
}

double evaluarHorner(const std::vector<int>& coeficiente, double x) {
    double resultado = coeficiente[0];
    for (size_t i = 1; i < coeficiente.size(); ++i) {
        resultado = resultado * x + coeficiente[i];
    }
    return resultado;
}

std::vector<int> generarcoeficientes(int grado) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-10, 10);
    std::vector<int> coeficiente(grado + 1);
    for (int i = 0; i <= grado; ++i) {
        coeficiente[i] = dis(gen);
    }
    return coeficiente;
}

double generarX() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10.0, 10.0);
    double x;
    do {
        x = dis(gen);
    } while (x == 0.0); // evitar x = 0
    return x;
}
