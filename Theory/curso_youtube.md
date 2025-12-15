# C++

C++ es un lenguaje de programación tipado

## Objetos y variables

- Los Objetos con un nombre se denominan Variables

#### Declaración de variables

Tipo + nombre

int x;

#### Asignación de variables

Asignación por copia
x = 5

**Identificadores**
- Solo números, letras y _
- Distingue entre mayúscula y minúscula
- Tiene que empezar por letra minúscula
* Empiezan por letra mayúscula otro tipo de declaraciones como struct, class o enum

**UpperCamelCase**
La primera letra de cada una de las palabras es mayúscula. Ejemplo: MiBlogDeDesarrollo.

#### Casteo de variables
`static_cast<nuevo_tipo>(expresion)`

#### Modos de inicialización

int a;
int b = 0;
int c (0);

Para listas:
int d {0};
int d = {0};
int d {};

## Librería iostream

Librería para entrada y salida de datos

### Variables predefinidas

**Salida de datos**
std::cout -> es un namespace
sirve para enviar cosas por pantalla
`std::cout << "TEXTO";`
`std::cout << VARIABLE;`
`std::cout << "TEXTO" << VARIABLE;`

**Salto de línea**
std::endl

**Entrada de datos**
std::cin >> VARIABLE;

## Literales, Operadores y Expresiones

- Literales o literales constantes: Valores fijos insertados en el código fuente

Operadores: vídeo 10, minuto 1:52

Operador ternario
x ? y : z
variable = (condition) ? expressionTrue : expressionFalse;


## Quitar un bloque de la compilación

\#if 0 // NO compila nada empezando aquí
	std::cout << "hola\n"
	/* comentario
	 * multilinea
	 */
\#endif // hasta aquí

## Strings
std::string

### Sacar una línea
std::getline(entrada, salida);
std::getline(std::cin, variable);

### Longitud del string
sdt::string::length

variable tipo std::string, le pongo el .length
std::string Variable;
Variable.length;

## Bloques internos o anidados

metes en mitad del código
{
	escribe lo que quieras aquí
}

dentro de este bloque puedes cambiar variables que se borran al salir de los corchetes

Alcance local de ocultamiento: (::variable)

## Declaración goto

pones una etiqueta y goto vuelve a esa etiqueta

...
{
	int x;
vuelve:
	std::cout << "hola";
	if (x == 0)
		goto vuelve
...

se puede poner la etiqueta antes o despues

## Plantillas

sirven para hacer funciones cuyos argumentos puedan ser de varios tipos

al declararla, decimos la cantidad de tipos que va a recibir la función, pero no cuales

cuando la llamemos ya le vamos diciendo qué tipos queremos

```
template <typename T>
T funcion(T x, T y)
{
	return (x + y);
}

int main()
{
	funcion(int a, int b);
	funcion(double c, double d)
}
```

```
template <typename T>
T funcion(T x, double y)
{
	return (x + y);
}

int main()
{
	funcion(int a, double b);
	funcion(double c, double d)
}
```

```
template <typename T, typename U>
T funcion(T x, U y)
{
	return (x + y);
}

int main()
{
	funcion(int a, double b);
	funcion(double c, int d)
}
```
