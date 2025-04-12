#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>

#include "Gestion.h"

using namespace std;
using namespace std::chrono;

int main() {
    // Generar grados de 10 en 10 hasta 1000
    vector<int> grados;
    for (int n = 10; n <= 1000; n += 10) {
        grados.push_back(n);
    }

    string filename;
    cout<<"Ingrese el nombre del archivo CSV en el que se guardar\240n los resultados\n";
    cin>>filename;
    filename=filename+".CSV";

    ofstream archivo(filename);
    if (!archivo) {
        cerr << "Error al crear el archivo resultados.csv\n";
        return 1;
    }


    archivo << "grado,tiempo estandar(us),tiempo horner(us)\n";

    // Probar cada grado
    for (int grado : grados) {
        vector<int> coeficiente = generarcoeficientes(grado);
        double x = generarX();

        // Evaluación estándar
        auto inicio1 = high_resolution_clock::now();
        for (int i = 0; i < 1000; ++i) {
            EvaluacionEstandar(coeficiente, x);
        }
        auto duracion1 = duration_cast<microseconds>(high_resolution_clock::now() - inicio1).count() / 1000.0;

        // Evaluación Horner
        auto inicio2 = high_resolution_clock::now();
        for (int i = 0; i < 1000; ++i) {
            evaluarHorner(coeficiente, x);
        }
        auto duracion2 = duration_cast<microseconds>(high_resolution_clock::now() - inicio2).count() / 1000.0;

        // Guardar resultados
        archivo << grado << "," << fixed << setprecision(2)
                << duracion1 << "," << duracion2 << "\n";

        cout << "Grado " << setw(4) << grado << ": "
             << "Estandar= " << setw(6) << duracion1 << " us, "
             << "Horner=" << setw(6) << duracion2 << " us\n";
    }

    cout << "\nResultados guardados en "<<filename<<"\n";
    return 0;
}
