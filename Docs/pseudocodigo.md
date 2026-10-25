INICIO
    Definir variables enteras: opcion, cantidad, agregarMas, totalVentasDia = 0
    Definir variables decimales: precio, subtotalVenta, descuento, impuesto, totalPagar, pagoCliente
    Definir variables decimales: dineroCaja = 0.0, ventaMayor = 0.0, ventaMenor = 0.0

    REPETIR
        Imprimir "+---------------------------------+"
        Imprimir "|       CONTROL DE VENTAS         |"
        Imprimir "+---------------------------------+"
        Imprimir " 1. Realizar una venta"
        Imprimir " 2. Consultar resumen del dia"
        Imprimir " 3. Salir del programa"
        Imprimir "+---------------------------------+"
        Imprimir "Seleccione una opcion: "
        Leer opcion

        SEGUN opcion HACER
            CASO 1:
                Imprimir ">>> INICIANDO REGISTRO DE VENTA <<<"
                subtotalVenta = 0.0
                agregarMas = 1

                MIENTRAS agregarMas == 1 HACER
                    // Validar precio
                    REPETIR
                        Imprimir "Ingrese el precio del articulo: Q"
                        Leer precio
                        SI precio < 0 ENTONCES
                            Imprimir "Error: El precio no puede ser negativo."
                        FIN SI
                    HASTA QUE precio >= 0

                    // Validar cantidad
                    REPETIR
                        Imprimir "Ingrese la cantidad a llevar (1 a 100): "
                        Leer cantidad
                        SI cantidad <= 0 O cantidad > 100 ENTONCES
                            Imprimir "Error: Cantidad fuera de rango."
                        FIN SI
                    HASTA QUE cantidad > 0 Y cantidad <= 100

                    subtotalVenta = subtotalVenta + (precio * cantidad)

                    // Preguntar si quiere más productos
                    REPETIR
                        Imprimir "Desea registrar otro articulo? (1 = Si, 0 = No): "
                        Leer agregarMas
                        SI agregarMas != 0 Y agregarMas != 1 ENTONCES
                            Imprimir "Error: Solo ingrese 1 o 0."
                        FIN SI
                    HASTA QUE agregarMas == 0 O agregarMas == 1
                FIN MIENTRAS

                // Cálculos finales de la venta
                SI subtotalVenta > 0 ENTONCES
                    descuento = 0.0

                    SI subtotalVenta >= 300 ENTONCES
                        descuento = subtotalVenta * 0.10
                    SINO SI subtotalVenta >= 100 ENTONCES
                        descuento = subtotalVenta * 0.05
                    FIN SI

                    impuesto = subtotalVenta * 0.12
                    totalPagar = (subtotalVenta - descuento) + impuesto

                    Imprimir "--- DETALLE DE LA CUENTA ---"
                    Imprimir "Subtotal: Q", subtotalVenta
                    Imprimir "Descuento aplicado: Q", descuento
                    Imprimir "IVA (12%): Q", impuesto
                    Imprimir "TOTAL A COBRAR: Q", totalPagar

                    // Validar pago
                    REPETIR
                        Imprimir "Ingrese el efectivo recibido: Q"
                        Leer pagoCliente
                        SI pagoCliente < totalPagar ENTONCES
                            Imprimir "Error: El efectivo es insuficiente."
                        FIN SI
                    HASTA QUE pagoCliente >= totalPagar

                    