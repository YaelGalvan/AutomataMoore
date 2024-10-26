#include <iostream>
#include <string>

using namespace std;

// Definición de los estados del autómata de Moore
enum State { S0, S1 };

// Función para procesar la cadena de entrada con el autómata de Moore
string procesarSecuencia(const string& entrada) {
    State estadoActual = S0;
    string salida = "";  // Cadena para almacenar la salida modificada

    // Procesa cada bit de la secuencia de entrada
    for (char bit : entrada) {
        switch (estadoActual) {
            case S0:
                if (bit == '1') {
                    estadoActual = S1;  // Si recibe "1", cambia al estado S1
                    salida += '0';      // En S0, si recibe "1", la salida es "0" (reemplazando el primer "1")
                } else if (bit == '0') {
                    salida += '0';      // Si recibe "0", simplemente añade "0" a la salida
                }
                break;

            case S1:
                if (bit == '1') {
                    estadoActual = S0;  // Si recibe otro "1", vuelve a S0
                    salida += '0';      // Reemplaza el segundo "1" con otro "0"
                } else if (bit == '0') {
                    estadoActual = S0;  // Si recibe "0", vuelve a S0
                    salida += '0';      // Mantiene el "0"
                }
                break;
        }
    }

    return salida;  // Devuelve la secuencia modificada
}

int main() {
    // Ejemplo de secuencias de prueba
    string secuencia = "110110101111";  // Puedes cambiar esta secuencia para probar otras

    cout << "Secuencia original: " << secuencia << endl;
    string salida = procesarSecuencia(secuencia);
    cout << "Secuencia procesada: " << salida << endl;

    return 0;
}
