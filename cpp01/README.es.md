# CPP01

Asignación de memoria, punteros a miembros, referencias y declaraciones switch.

---

## Ejercicio 00: BraiiiiiiinnnzzzZ

| Ejercicio : 00 |
|-------------|
| BraiiiiiiinnnzzzZ |
| Directorio de entrega: ex00/ |
| Archivos a entregar: Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp newZombie.cpp, randomChump.cpp |
| Funciones prohibidas: Ninguna |

Primero, implementa una clase **Zombie**. Tiene un atributo string privado `name`.
Agrega una función miembro `void announce( void );` a la clase Zombie. Los zombis se anuncian de la siguiente manera:

`<name>: BraiiiiiiinnnzzzZ...`

No imprimas los corchetes angulares (< y >). Para un zombi llamado Foo, el mensaje sería:

`Foo: BraiiiiiiinnnzzzZ...`

Luego, implementa las siguientes dos funciones:

- `Zombie* newZombie( std::string name );` \
Esta función crea un zombi, lo nombra, y lo devuelve para que puedas usarlo fuera del ámbito de la función.

- `void randomChump( std::string name );` \
Esta función crea un zombi, lo nombra, y hace que se anuncie.

Ahora, ¿cuál es el punto real del ejercicio? Tienes que determinar en qué caso es mejor asignar zombis en la pila o en el heap.

Los zombis deben ser destruidos cuando ya no los necesites. El destructor debe imprimir un mensaje con el nombre del zombi para propósitos de depuración.

--- 

## Ejercicio 01: ¡Más cerebros!

| Ejercicio : 01 |
|-------------|
| Moar brainz! |
| Directorio de entrega: ex01/ |
| Archivos a entregar: Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp, zombieHorde.cpp |
| Funciones prohibidas: Ninguna |

¡Es hora de crear una **horda de Zombis**!

Implementa la siguiente función en el archivo apropiado:

`Zombie* zombieHorde( int N, std::string name );`

Debe asignar N objetos Zombie en una sola asignación. Luego, debe inicializar los zombis, dándole a cada uno de ellos el nombre pasado como parámetro. La función devuelve un puntero al primer zombi.

Implementa tus propias pruebas para asegurar que tu función `zombieHorde()` funcione como se espera. Intenta llamar `announce()` para cada uno de los zombis.

No olvides usar `delete` para desasignar todos los zombis y verificar **fugas de memoria**.

---

## Ejercicio 02: HOLA ESTE ES EL CEREBRO

| Ejercicio : 02 |
|-------------|
| HI THIS IS BRAIN |
| Directorio de entrega: ex02/ |
| Archivos a entregar: Makefile, main.cpp |
| Funciones prohibidas: Ninguna |

Escribe un programa que contenga:

- Una variable string inicializada a `"HI THIS IS BRAIN"`.
- `stringPTR`: un puntero al string.
- `stringREF`: una referencia al string.

Tu programa debe imprimir:

- La dirección de memoria de la variable string.
- La dirección de memoria mantenida por `stringPTR`.
- La dirección de memoria mantenida por `stringREF`.

Y luego:
- El valor de la variable string.
- El valor señalado por `stringPTR`.
- El valor señalado por `stringREF`.

Eso es todo—sin trucos. El objetivo de este ejercicio es desmitificar las referencias, que pueden parecer completamente nuevas. Aunque hay algunas pequeñas diferencias, esto es simplemente otra sintaxis para algo que ya haces: manipulación de direcciones.

---

## Ejercicio 03: Violencia innecesaria

| Ejercicio : 03 |
|-------------|
| Unnecessary violence |
| Directorio de entrega: ex03/ |
| Archivos a entregar: Makefile, main.cpp, Weapon.{h, hpp}, Weapon.cpp, HumanA.{h,hpp}, HumanA.cpp, HumanB.{h, hpp}, HumanB.cpp |
| Funciones prohibidas: Ninguna |

Implementa una clase `Weapon` que tenga:

- Un atributo privado `type`, que es un string.
- Una función miembro `getType()` que devuelve una referencia constante a `type`.
- Una función miembro `setType()` que establece `type` usando el nuevo valor pasado como parámetro.

Ahora, crea dos clases: **HumanA** y **HumanB**. Ambas tienen un `Weapon` y un `name`. También tienen una función miembro `attack()` que muestra (sin los corchetes angulares):

`<name> ataca con su <weapon type>`

HumanA y HumanB son casi idénticas excepto por estos dos pequeños detalles:

- Mientras **HumanA** toma el `Weapon` en su constructor, **HumanB** no lo hace.
- **HumanB** puede no tener siempre un arma, mientras que **HumanA** siempre estará armado.

Si tu implementación es correcta, ejecutar el siguiente código imprimirá un ataque con "crude spiked club" seguido de un segundo ataque con "some other type of club" para ambos casos de prueba:

```
int main()
{
	{
		Weapon  club = Weapon("crude spiked club");
		
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon  club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
```

No olvides verificar fugas de memoria.

---

## Ejercicio 04: Sed es para perdedores

| Ejercicio : 04 |
|-------------|
| Sed is for losers |
| Directorio de entrega: ex04/ |
| Archivos a entregar: Makefile, main.cpp, *.cpp, *.{h, hpp} |
| Funciones prohibidas: std::string::replace |

Crea un programa que tome tres parámetros en el siguiente orden: un nombre de archivo y dos strings, `s1` y `s2`.

Debe abrir el archivo `<filename>` y copiar su contenido en un nuevo archivo `<filename>.replace`, reemplazando cada ocurrencia de `s1` con `s2`.

Usar funciones de manipulación de archivos de C está prohibido y será considerado trampa. Todas las funciones miembro de la clase `std::string` están permitidas, excepto `replace`. ¡Úsalas sabiamente!

Por supuesto, maneja entradas inesperadas y errores. Debes crear y entregar tus propias pruebas para asegurar que tu programa funcione como se espera.

---

## Ejercicio 05: Harl 2.0

| Ejercicio : 05 |
|-------------|
| Harl 2.0 |
| Directorio de entrega: ex05/ |
| Archivos a entregar: Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp |
| Funciones prohibidas: Ninguna |

¿Conoces a Harl? Todos lo conocemos, ¿no es así? En caso de que no, encuentra abajo el tipo de comentarios que Harl hace. Están clasificados por niveles:

- Nivel **"DEBUG"**: Los mensajes de debug contienen información contextual. Se usan principalmente para diagnóstico de problemas. \
Ejemplo: *"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"*

- Nivel **"INFO"**: Estos mensajes contienen información extensa. Son útiles para rastrear la ejecución del programa en un entorno de producción. \
Ejemplo: *"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"*

- Nivel **"WARNING"**: Los mensajes de advertencia indican un problema potencial en el sistema. Sin embargo, puede ser manejado o ignorado. \
Ejemplo: *"I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."*

- Nivel **"ERROR"**: Estos mensajes indican que ha ocurrido un error irrecuperable. Esto es usualmente un problema crítico que requiere intervención manual. \
Ejemplo: *"This is unacceptable! I want to speak to the manager now."*

Vas a automatizar a Harl. No será difícil ya que siempre dice las mismas cosas. Tienes que crear una clase **Harl** con las siguientes funciones miembro privadas:

- `void debug( void );`
- `void info( void );`
- `void warning( void );`
- `void error( void );`

**Harl** también tiene una función miembro pública que llama a las cuatro funciones miembro anteriores dependiendo del nivel pasado como parámetro:

`void    complain( std::string level );`

El objetivo de este ejercicio es usar **punteros a funciones miembro**. Esto no es una sugerencia. Harl tiene que quejarse sin usar un bosque de if/else if/else. ¡Él no lo piensa dos veces!

Crea y entrega pruebas para mostrar que Harl se queja mucho. Puedes usar los ejemplos de comentarios listados arriba en el enunciado o elegir usar comentarios propios.

---

## Ejercicio 06: Filtro de Harl

| Ejercicio : 06 |
|-------------|
| Harl filter |
| Directorio de entrega: ex06/ |
| Archivos a entregar: Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp |
| Funciones prohibidas: Ninguna |

A veces no quieres prestar atención a todo lo que dice Harl. Implementa un sistema para filtrar lo que dice Harl dependiendo de los niveles de log que quieras escuchar.

Crea un programa que tome como parámetro uno de los cuatro niveles. Mostrará todos los mensajes desde este nivel y superiores. Por ejemplo:

```
$> ./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years, whereas you started working here just last month.

[ ERROR ]
This is unacceptable! I want to speak to the manager now.

$> ./harlFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ]
```

Aunque hay varias formas de lidiar con Harl, una de las más efectivas es usar SWITCH para apagarlo.

Dale el nombre `harlFilter` a tu ejecutable.

Debes usar, y tal vez descubrir, la declaración switch en este ejercicio.