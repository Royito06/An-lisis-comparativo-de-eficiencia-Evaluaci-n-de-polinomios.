# AnalisisDeEficienciaDeEvaluacionDePolinomios

# ⚡ Comparación de Métodos de Evaluación de Polinomios

Este proyecto en C++ compara el rendimiento entre dos algoritmos para evaluar polinomios: con el **método estándar** y el **método de Horner**, midiendo tiempos de ejecución promedio para distintos grados que van desde 10 hasta 1000.  
Los resultados se almacenan en un archivo CSV para su análisis y visualización posterior.

---

## ✍️ Autor  
**Nombre:** José Rodrigo Espinoza García

---

## 💻 Requisitos del Sistema

- **Compilador C++**: `g++` versión 9.0 o superior  
- **Sistema operativo**: Windows 10/11 o Linux.  
- **Memoria RAM**: Mínimo 2GB (recomendado 4GB+ para pruebas de alto grado)  


---

## ⚙️ Instrucciones de Compilación y Ejecución

### 🔧 Windows (CMD/PowerShell)

```bash
g++ main.cpp Gestiones.cpp -o evaluacion_polinomios -std=c++11 -O2
.\evaluacion_polinomios.exe
```

### 🐧 Linux (Terminal)

```bash
sudo apt update && sudo apt install g++
g++ main.cpp Gestiones.cpp -o evaluacion_polinomios -std=c++11 -O2
./evaluacion_polinomios
```

Al ejecutarse, el programa pedirá un nombre para el archivo CSV que se generará con los resultados.

---

## 📐 Explicación de los Métodos de Evaluación

### ⚙ Método Estándar

Evalúa el polinomio con la forma general:

\[
P(x) = a<sub>0</sub>x<sup>n</sup> + a<sub>1</sub>x<sup>n−1</sup> + a<sub>2</sub>x<sup>n−2</sup> + ... + a<sub>n</sub>x<sup>0</sup>
\]
 
- Requiere muchas operaciones para grados grandes.  
- **Complejidad:**  \( O(n<sup>2</sup>) \)

### ⚙ Método de Horner

Reorganiza el cálculo así:

\[
P(x) = a<sub>0</sub> + x · (a<sub>1</sub> + x · (a<sub>2</sub> + ... + x · (a<sub>n−1</sub> + x · a<sub>n</sub>) ... ))
\]

- Solo utiliza sumas y multiplicaciones.  
- Menor uso de memoria y CPU.  
- **Complejidad:** \( O(n) \)

---

## 📈 Resultados experimentales

![Gráfica de análisis de eficiencia](https://github.com/Royito06/AnalisisDeEficienciaDeEvaluacionDePolinomios/blob/main/Gr%C3%A1ficaAn%C3%A1lisisDeEficiencia.png?raw=true)


---

## 🔍 Análisis 

Al  analizar los resultados se puede ver que el método Horner termina por ser mas eficiente para la evaluacion de los polinomios al aumentar el grado, por que este método logra reducir considerablemente la cantidad de operaciones necesarias al refrmular los polinomios. Al aumentar cada vez mas el grado de los polinomios se aprecia mejor la complejidad de ambos métodos, siendo el método estándar de complejidad O(n<sup>2</sup>) y el método Horner O(n).

---

## 📘 Conclusión

El experimento realizado confirma que el método de Horner es notablemente más eficiente que el método estándar para evaluar polinomios, especialmente a medida que aumenta el grado del polinomio. Esto se debe a que Horner reduce la cantidad de operaciones necesarias al reformular el polinomio, logrando una complejidad lineal O(n), frente a la complejidad cuadrática O(n<sup>2</sup>) del método estándar.

---

## 📁 Datos experimentales

| Grado | Tiempo Estándar (µs) | Tiempo Horner (µs) |
|-------|----------------------|---------------------|
| 10    | 5.2                  | 1.5                 |
| 20    | 15.7                 | 2.8                 |
| 30    | 31.4                 | 4.2                 |
| 40    | 55.8                 | 5.9                 |
| 50    | 87.3                 | 7.5                 |
| ...   | ...                  | ...                 |

Los datos completos se encuentran en el siguiente archivo CSV [AnálisisDeEficiencia.csv](https://github.com/Royito06/AnalisisDeEficienciaDeEvaluacionDePolinomios/blob/main/An%C3%A1lisisDeEficiencia.csv).


