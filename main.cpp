#include <iostream>
using namespace std;

int main() {
    int opcion, cantidad, agregarMas;
    int totalVentasDia = 0;
    float precio, subtotalVenta, descuento, impuesto, totalPagar, pagoCliente;
    float dineroCaja = 0.0;
    float ventaMayor = 0.0, ventaMenor = 0.0; // Variables nuevas

    do {
        cout << "\n+---------------------------------+" << endl;
        cout << "|       CONTROL DE VENTAS         |" << endl;
        cout << "+---------------------------------+" << endl;
        cout << " 1. Realizar una venta" << endl;
        cout << " 2. Consultar resumen del dia" << endl;
        cout << " 3. Salir del programa" << endl;
        cout << "+---------------------------------+" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n>>> INICIANDO REGISTRO DE VENTA <<<" << endl;
                subtotalVenta = 0.0;
                agregarMas = 1;

                // Ciclo para agregar productos
                while (agregarMas == 1) {
                    do {
                        cout << "Ingrese el precio del articulo: Q";
                        cin >> precio;
                        if (precio < 0) {
                            cout << "  [!] Error: El precio no puede ser negativo." << endl;
                        }
                    } while (precio < 0);

                    do {
                        cout << "Ingrese la cantidad a llevar (1 a 100): ";
                        cin >> cantidad;
                        if (cantidad <= 0 || cantidad > 100) {
                            cout << "  [!] Error: Cantidad fuera de rango." << endl;
                        }
                    } while (cantidad <= 0 || cantidad > 100);

                    subtotalVenta = subtotalVenta + (precio * cantidad);

                    do {
                        cout << "Desea registrar otro articulo? (1 = Si, 0 = No): ";
                        cin >> agregarMas;
                        if (agregarMas != 0 && agregarMas != 1) {
                            cout << "  [!] Error: Solo ingrese 1 o 0." << endl;
                        }
                    } while (agregarMas != 0 && agregarMas != 1);
                }

                // Cálculos de la venta
                if (subtotalVenta > 0) {
                    descuento = 0.0;

                    if (subtotalVenta >= 300) {
                        descuento = subtotalVenta * 0.10;
                    } else if (subtotalVenta >= 100) {
                        descuento = subtotalVenta * 0.05;
                    }

                    impuesto = subtotalVenta * 0.12; 
                    totalPagar = (subtotalVenta - descuento) + impuesto;

                    cout << "\n--- DETALLE DE LA CUENTA ---" << endl;
                    cout << "Subtotal: Q" << subtotalVenta << endl;
                    cout << "Descuento aplicado: Q" << descuento << endl;
                    cout << "IVA (12%): Q" << impuesto << endl;
                    cout << "TOTAL A COBRAR: Q" << totalPagar << endl;
                    cout << "----------------------------" << endl;

                    do {
                        cout << "Ingrese el efectivo recibido: Q";
                        cin >> pagoCliente;
                        if (pagoCliente < totalPagar) {
                            cout << "  [!] Error: El efectivo es insuficiente. Faltan Q" << (totalPagar - pagoCliente) << endl;
                        }
                    } while (pagoCliente < totalPagar);

                    cout << "\n  Venta completada con exito." << endl;
                    cout << "  Cambio a entregar: Q" << (pagoCliente - totalPagar) << endl;

                    // Lógica para registrar venta mayor y menor
                    if (totalVentasDia == 0) {
                        // Si es la primera venta, es la mayor y menor al mismo tiempo
                        ventaMayor = totalPagar;
                        ventaMenor = totalPagar;
                    } else {
                        if (totalPagar > ventaMayor) {
                            ventaMayor = totalPagar;
                        }
                        if (totalPagar < ventaMenor) {
                            ventaMenor = totalPagar;
                        }
                    }

                    dineroCaja = dineroCaja + totalPagar;
                    totalVentasDia = totalVentasDia + 1;
                }
                break;

            case 2:
                cout << "\n>>> RESUMEN DE OPERACIONES <<<" << endl;
                if (totalVentasDia == 0) {
                    cout << "No se han registrado ventas el dia de hoy." << endl;
                } else {
                    cout << "Total de clientes atendidos: " << totalVentasDia << endl;
                    cout << "Efectivo total en caja: Q" << dineroCaja << endl;
                    cout << "Venta mayor registrada: Q" << ventaMayor << endl;
                    cout << "Venta menor registrada: Q" << ventaMenor << endl;
                }
                break;

            case 3:
                cout << "\nCerrando sistema de caja... Hasta luego." << endl;
                break;

            default:
                cout << "\n[!] Error: Opcion no valida. Elija 1, 2 o 3." << endl;
                break;
        }

    } while (opcion != 3);

    return 0;
}