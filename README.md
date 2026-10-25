# Registro y Control de Ventas (Caja Registradora)

## Descripción del Proyecto
Este es un programa desarrollado en C++ diseñado para gestionar las transacciones diarias de un comercio. El sistema permite el ingreso de múltiples artículos por cliente, calcula de forma automática los descuentos aplicables según el volumen de compra, suma el Impuesto al Valor Agregado (IVA) y mantiene un registro del efectivo en caja, así como de la venta más alta y más baja del día.

## Instrucciones de Compilación y Ejecución
Para hacer funcionar este programa, se requiere un entorno de desarrollo compatible con C++ (como Visual Studio, Code::Blocks, o un compilador GCC/MinGW).

*Desde la terminal:*
1. Navegue hasta la carpeta donde se encuentra el código fuente.
2. Compile el archivo ejecutando el comando: 
   g++ main.cpp -o sistema_ventas.exe
3. Ejecute el programa con: 
   ./sistema_ventas.exe

## Estructuras de Control y Lógica Implementada

A diferencia de un flujo lineal, este sistema utiliza una arquitectura basada en ciclos para mantener la ejecución viva y validar cada dato ingresado:

*   *Menú Principal (do-while y switch):* El esqueleto del programa es un ciclo do-while que muestra la interfaz y captura la elección del usuario. La decisión se procesa a través de una estructura switch con casos específicos para Vender, Ver Resumen o Salir.
*   *Ingreso de Productos (while):* El proceso de venta está envuelto en un ciclo while que evalúa la variable agregarMas. Esto permite al cajero seguir sumando productos a una misma cuenta hasta que ingrese el número 0.
*   *Validaciones Estrictas (do-while):* Para evitar que el sistema colapse por errores humanos, se implementaron bucles do-while en las entradas críticas. El programa no avanzará si se detecta un precio negativo, una cantidad irreal (menor a 1 o mayor a 100), o si el efectivo entregado por el cliente es menor al total a cobrar.
*   *Cálculo de Descuentos (if / else if):* Al finalizar la cuenta, el flujo pasa por un bloque condicional que evalúa el subtotal. Si la compra es igual o superior a Q300, aplica un 10%; si es mayor o igual a Q100, aplica un 5%.

