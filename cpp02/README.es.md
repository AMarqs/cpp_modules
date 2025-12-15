# CPP02

Polimorfismo ad-hoc, sobrecarga de operadores y la forma canónica ortodoxa de clases

---

## Ejercicio 00: Mi Primera Clase en Forma Canónica Ortodoxa

| Ejercicio : 00 |
|-------------|
| Mi Primera Clase en Forma Canónica Ortodoxa |
| Directorio de entrega: ex00/ |
| Archivos a entregar: Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp |
| Funciones prohibidas: Ninguna |

Piensas que conoces los números enteros y los números de punto flotante. Qué tierno.

Por favor lee este artículo de 3 páginas (1, 2, 3) para descubrir que no es así. Adelante, léelo.

Hasta hoy, cada número que has usado en tu código era básicamente un entero o un número de punto flotante, o cualquiera de sus variantes (`short`, `char`, `long`, `double`, etc.). Después de leer el artículo anterior, es seguro asumir que los enteros y los números de punto flotante tienen características opuestas.

Pero hoy, las cosas van a cambiar. Vas a descubrir un nuevo y asombroso tipo de número: ¡los números de punto fijo! Siempre ausentes de los tipos escalares de la mayoría de lenguajes, los números de punto fijo ofrecen un valioso equilibrio entre rendimiento, precisión, rango y exactitud. Eso explica por qué los números de punto fijo son particularmente aplicables a gráficos por computadora, procesamiento de sonido o programación científica, solo por nombrar algunos.

Como C++ carece de números de punto fijo, los vas a añadir. Este artículo de Berkeley es un buen comienzo. Si no tienes idea de qué es la Universidad de Berkeley, lee esta sección de su página de Wikipedia.

Crea una clase en Forma Canónica Ortodoxa que represente un número de punto fijo:

- Miembros privados:
	- Un **entero** para almacenar el valor del número de punto fijo.
	- Un **entero constante estático** para almacenar el número de bits fraccionarios. Su valor siempre será el literal entero 8.

- Miembros públicos:
	- Un constructor por defecto que inicializa el valor del número de punto fijo a 0.
	- Un constructor de copia.
	- Un operador de asignación por copia sobrecargado.
	- Un destructor.
	- Una función miembro `int getRawBits( void ) const;` \
	que devuelve el valor crudo del valor de punto fijo.
	- Una función miembro `void setRawBits( int const raw );` \
	que establece el valor crudo del número de punto fijo.

Ejecutar este código:

```
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
```

Debería producir algo similar a:

```
$> ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called // <-- Esta línea puede faltar dependiendo de tu implementación
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>
```

---

## Ejercicio 01: Hacia una clase de números de punto fijo más útil

| Ejercicio : 01 |
|-------------|
| Hacia una clase de números de punto fijo más útil |
| Directorio de entrega: ex01/ |
| Archivos a entregar: Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp |
| Funciones prohibidas: roundf (de <cmath>) |

El ejercicio anterior fue un buen comienzo, pero nuestra clase es bastante inútil. Solo puede representar el valor 0.0.

Añade los siguientes constructores públicos y funciones miembro públicas a tu clase:

- Un constructor que toma un **entero constante** como parámetro. \
Lo convierte al valor de punto fijo correspondiente. El valor de bits fraccionarios debe inicializarse a 8, como en el ejercicio 00.

- Un constructor que toma un **número de punto flotante constante** como parámetro. \
Lo convierte al valor de punto fijo correspondiente. El valor de bits fraccionarios debe inicializarse a 8, como en el ejercicio 00.

- Una función miembro `float toFloat( void ) const;` \
que convierte el valor de punto fijo a un valor de punto flotante.

- Una función miembro `int toInt( void ) const;` \
que convierte el valor de punto fijo a un valor entero.

Y añade la siguiente función a los archivos de la clase Fixed:

- Una sobrecarga del operador de inserción («) que inserta una representación de punto flotante del número de punto fijo en el objeto de flujo de salida pasado como parámetro.

Ejecutar este código:

```
#include <iostream>

int main( void ) {
	Fixed 		a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
```

Debería producir algo similar a:

```
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
```

---

## Ejercicio 02: Ahora sí estamos hablando

| Ejercicio : 02 |
|-------------|
| Ahora sí estamos hablando |
| Directorio de entrega: ex02/ |
| Archivos a entregar: Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp |
| Funciones prohibidas: roundf (de <cmath>) |

Añade funciones miembro públicas a tu clase para sobrecargar los siguientes operadores:

- Los 6 operadores de comparación: >, <, >=, <=, ==, y !=.
- Los 4 operadores aritméticos: +, -, *, y /.
- Los 4 operadores de incremento/decremento (pre-incremento y post-incremento, pre-decremento y post-decremento), que aumentarán o disminuirán el valor de punto fijo por el ϵ más pequeño representable, tal que 1 + ϵ > 1.

Añade estas cuatro funciones miembro sobrecargadas públicas a tu clase:

- Una función miembro estática `min` que toma dos referencias a números de punto fijo como parámetros, y devuelve una referencia al más pequeño.
- Una función miembro estática `min` que toma dos referencias a números de punto fijo constantes como parámetros, y devuelve una referencia al más pequeño.
- Una función miembro estática `max` que toma dos referencias a números de punto fijo como parámetros, y devuelve una referencia al más grande.
- Una función miembro estática `max` que toma dos referencias a números de punto fijo constantes como parámetros, y devuelve una referencia al más grande.

Depende de ti probar cada característica de tu clase. Sin embargo, ejecutar el código de abajo:

```
#include <iostream>

int main( void ) {
	Fixed 		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
```

Debería producir algo como (para mayor legibilidad, los mensajes de constructor/destructor están removidos en el ejemplo de abajo):

```
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
```

[NOTA]
> Si alguna vez haces una división por 0, es aceptable que el programa se cuelgue

---

## Ejercicio 03: BSP

| Ejercicio : 03 |
|-------------|
| BSP |
| Directorio de entrega: ex03/ |
| Archivos a entregar: Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp, Point.{h, hpp}, Point.cpp, bsp.cpp |
| Funciones prohibidas: roundf (de <cmath>) |

Ahora que tienes una clase Fixed funcional, sería bueno usarla.

Implementa una función que indique si un punto está dentro de un triángulo o no. Muy útil, ¿verdad?

[INFO]
> BSP significa Binary Space Partitioning (Particionado del Espacio Binario). De nada.

Comencemos creando la clase Point en Forma Canónica Ortodoxa que representa un punto 2D:

- Miembros privados:
	- Un atributo Fixed const x.
	- Un atributo Fixed const y.
	- Cualquier otra cosa útil.

- Miembros públicos:
	- Un constructor por defecto que inicializa x e y a 0.
	- Un constructor que toma dos números de punto flotante constantes como parámetros. Inicializa x e y con esos parámetros.
	- Un constructor de copia.
	- Un operador de asignación por copia sobrecargado.
	- Un destructor.
	- Cualquier otra cosa útil.

Para concluir, implementa la siguiente función en el archivo apropiado:

`bool bsp( Point const a, Point const b, Point const c, Point const point);`

- a, b, c: Los vértices de nuestro querido triángulo.
- point: El punto a verificar.
- Devuelve: True si el punto está dentro del triángulo. False en caso contrario. \
Por lo tanto, si el punto es un vértice o está en un borde, devolverá False.

Implementa y entrega tus propias pruebas para asegurar que tu clase se comporte como se espera.
