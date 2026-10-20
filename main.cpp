#include <iostream>
using namespace std;

int main() {
    int opcion, cantidad;
    float precio, totalVenta;

    do {
        cout << "\n===== CONTROL DE VENTAS =====" << endl;
        cout << "1. Realizar una venta" << endl;
        cout << "2. Consultar resumen del dia" << endl;
        cout << "3. Salir del programa" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        

    } while (opcion != 3);

    return 0;
}