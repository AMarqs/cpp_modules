# Módulos de C++

Introducción a C++

## Introducción

El objetivo de estos módulos es introducirte a la Programación Orientada a Objetos. Este será el punto de partida de tu viaje con C++. Muchos lenguajes son recomendados para aprender POO. Decidimos elegir C++ ya que se deriva de tu viejo amigo C. Dado que C++ es un lenguaje complejo, y para mantener las cosas simples, tu código seguirá el estándar C++98. Somos conscientes de que el C++ moderno es muy diferente en muchos aspectos.

---

## Reglas generales

#### Compilación

- Compila tu código con c++ y las flags `-Wall -Wextra -Werror`

- Tu código debería seguir compilando si añades la flag `-std=c++98`

#### Convenciones de formato y nombres

- Los directorios de ejercicios serán nombrados de esta manera: `ex00, ex01, ...  , exn`

- Nombra tus archivos, clases, funciones, funciones miembro y atributos como se requiere en las directrices.

- Escribe los nombres de clases en formato **UpperCamelCase**. Los archivos que contengan código de clase siempre serán nombrados según el nombre de la clase. Por ejemplo:
`ClassName.hpp`/`ClassName.h`, `ClassName.cpp`, o `ClassName.tpp`. Entonces, si tienes un archivo de cabecera que contiene la definición de una clase "BrickWall" que representa una pared de ladrillo, su nombre será `BrickWall.hpp`.

- A menos que se especifique lo contrario, cada mensaje de salida debe terminar con un carácter de nueva línea y ser mostrado en la salida estándar.

- ¡Adiós Norminette! No se impone ningún estilo de código en los módulos de C++. Puedes seguir tu favorito. Pero ten en cuenta que código que tus evaluadores pares no puedan entender es código que no pueden calificar. Haz tu mejor esfuerzo para escribir código limpio y legible.

#### Permitido/Prohibido

Ya no estás programando en C. ¡Es hora de C++! Por lo tanto:

- Tienes permitido usar casi todo de la biblioteca estándar. Así, en lugar de quedarte con lo que ya conoces, sería inteligente usar las versiones tipo-C++ de las funciones de C que estás acostumbrado a usar tanto como sea posible.

- Sin embargo, no puedes usar ninguna otra biblioteca externa. Significa que las librerías C++11 (y formas derivadas) y Boost están prohibidas. Las siguientes funciones también están prohibidas: `*printf()`, `*alloc()` y `free()`. Si las usas, tu calificación será 0 y punto.

- Nota que a menos que se declare explícitamente lo contrario, las palabras clave using namespace `<ns_name>` y `friend` están prohibidas. De lo contrario, tu calificación será -42.

- **Solo tienes permitido usar la STL en los Módulos 08 y 09**. Eso significa: no **Contenedores** (vector/list/map, etc.) y no **Algoritmos** (cualquier cosa que requiera incluir el header `<algorithm>`) hasta entonces. De lo contrario, tu calificación será -42.

#### Algunos requisitos de diseño

- La fuga de memoria también ocurre en C++. Cuando asignas memoria (usando la palabra clave new), debes evitar **fugas de memoria**.

- Desde el Módulo 02 hasta el Módulo 09, tus clases deben ser diseñadas en la **Forma Canónica Ortodoxa, excepto cuando se declare explícitamente lo contrario**.

- Cualquier implementación de función puesta en un archivo de cabecera (excepto para plantillas de función) significa 0 para el ejercicio.

- Deberías poder usar cada uno de tus headers independientemente de otros. Así, deben incluir todas las dependencias que necesiten. Sin embargo, debes evitar el problema de la doble inclusión añadiendo **guardas de inclusión**. De lo contrario, tu calificación será 0.

#### Léeme

- Puedes añadir algunos archivos adicionales si los necesitas (es decir, para dividir tu código). Como estas tareas no son verificadas por un programa, siéntete libre de hacerlo mientras entregues los archivos obligatorios.

- A veces, las directrices de un ejercicio parecen cortas pero los ejemplos pueden mostrar requisitos que no están escritos explícitamente en las instrucciones.

- ¡Lee cada módulo completamente antes de empezar! En serio, hazlo.

[!WARNING]
> Respecto al Makefile para proyectos de C++, se aplican las mismas reglas que en C (ver el capítulo de la Norma sobre el Makefile).

---

## Reglas específicas (desde el Módulo 02 hasta el Módulo 09)

De ahora en adelante, todas tus clases deben ser diseñadas en la Forma Canónica Ortodoxa, a menos que se declare explícitamente lo contrario. Entonces implementarán las cuatro funciones miembro requeridas a continuación:

- Constructor por defecto
- Constructor de copia
- Operador de asignación por copia
- Destructor

Divide el código de tu clase en dos archivos. El archivo de cabecera (.hpp/.h) contiene la definición de la clase, mientras que el archivo fuente (.cpp) contiene la implementación.

---

## Módulos

### CPP00

Espacios de nombres, clases, funciones miembro, flujos stdio, listas de inicialización, static, const, y algunas otras cosas básicas.

### CPP01

Asignación de memoria, punteros a miembros, referencias y declaraciones switch.

### CPP02

Polimorfismo ad-hoc, sobrecarga de operadores y la forma canónica ortodoxa de clases.

### CPP03
### CPP04
### CPP05
### CPP06
### CPP07
### CPP08
### CPP09
