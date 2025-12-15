# CPP03

Herencia

---

## Ejercicio 00: ¡Yyyyyy... ABIERTO!

| Ejercicio : 00 |
|----------------|
| ¡Yyyyyy... ABIERTO! |
| Directorio de entrega: ex00/ |
| Archivos a entregar: Makefile, main.cpp, ClapTrap.{h, hpp}, ClapTrap.cpp |
| Funciones prohibidas: Ninguna |

¡Primero, tienes que implementar una clase! ¡Qué original!

Se llamará **ClapTrap** y tendrá los siguientes atributos privados inicializados a los valores especificados entre paréntesis:

- Nombre, que se pasa como parámetro al constructor
- Puntos de vida (10), que representan la salud del ClapTrap
- Puntos de energía (10)
- Daño de ataque (0)

Agrega las siguientes funciones miembro públicas para que el ClapTrap se comporte de manera más realista:

- `void attack(const std::string& target);`
- `void takeDamage(unsigned int amount);`
- `void beRepaired(unsigned int amount);`

Cuando ClapTrap ataca, hace que su objetivo pierda `<daño de ataque>` puntos de vida. Cuando ClapTrap se repara a sí mismo, recupera `<cantidad>` puntos de vida. Atacar y repararse cuestan 1 punto de energía cada uno. Por supuesto, ClapTrap no puede hacer nada si no le quedan puntos de vida o puntos de energía. Sin embargo, dado que estos ejercicios sirven como introducción, las instancias de ClapTrap no deben interactuar directamente entre sí, y los parámetros no se referirán a otra instancia de ClapTrap.

En todas estas funciones miembro, necesitas imprimir un mensaje para describir lo que sucede. Por ejemplo, la función attack() puede mostrar algo como (por supuesto, sin los corchetes angulares):

`ClapTrap <nombre> ataca a <objetivo>, causando <daño> puntos de daño!`

Los constructores y el destructor también deben mostrar un mensaje, para que tus compañeros evaluadores puedan ver fácilmente que han sido llamados.

Implementa y entrega tus propias pruebas para asegurar que tu código funciona como se espera.

---

## Ejercicio 01: ¡Serena, mi amor!

| Ejercicio : 01 |
|----------------|
| ¡Serena, mi amor! |
| Directorio de entrega: ex01/ |
| Archivos a entregar: Archivos del ejercicio anterior + ScavTrap.{h, hpp}, ScavTrap.cpp |
| Funciones prohibidas: Ninguna |

Porque nunca puedes tener suficientes ClapTraps, ahora crearás un robot derivado. Se llamará `ScavTrap` y heredará los constructores y destructor de ClapTrap. Sin embargo, sus constructores, destructor y `attack()` imprimirán mensajes diferentes. Después de todo, los ClapTraps son conscientes de su individualidad.

Ten en cuenta que el encadenamiento adecuado de construcción/destrucción debe mostrarse en tus pruebas. Cuando se crea un ScavTrap, el programa comienza construyendo un ClapTrap. La destrucción ocurre en orden inverso. ¿Por qué?

**ScavTrap** usará los atributos de ClapTrap (actualiza ClapTrap en consecuencia) y debe inicializarlos a:

- Name (nombre), que se pasa como parámetro al constructor
- Hit points (100) (puntos de vida), que representan la salud del ClapTrap
- Energy points (50) (puntos de energía)
- Attack damage (20) (daño de ataque)

ScavTrap también tendrá su propia habilidad especial:

`void guardGate();`

Esta función miembro mostrará un mensaje indicando que ScavTrap está ahora en modo Guardián de la Puerta.

No olvides agregar más pruebas a tu programa.

---

## Ejercicio 02: Trabajo repetitivo

| Ejercicio : 02 |
|----------------|
| Trabajo repetitivo |
| Directorio de entrega: ex02/ |
| Archivos a entregar: Archivos de ejercicios anteriores + FragTrap.{h, hpp}, FragTrap.cpp |
| Funciones prohibidas: Ninguna |

Hacer ClapTraps probablemente está empezando a ponerte nervioso.

Ahora, implementa una clase **FragTrap** que herede de ClapTrap. Es muy similar a ScavTrap. Sin embargo, sus mensajes de construcción y destrucción deben ser diferentes. El encadenamiento adecuado de construcción/destrucción debe mostrarse en tus pruebas. Cuando se crea un FragTrap, el programa comienza construyendo un ClapTrap. La destrucción ocurre en orden inverso.

Lo mismo ocurre con los atributos, pero con valores diferentes esta vez:

- Name (nombre), que se pasa como parámetro al constructor
- Hit points (100) (puntos de vida), que representan la salud del ClapTrap
- Energy points (100) (puntos de energía)
- Attack damage (30) (daño de ataque)

FragTrap también tiene una habilidad especial:

`void highFivesGuys(void);`

Esta función miembro muestra una solicitud positiva de choca esos cinco en la salida estándar.

De nuevo, agrega más pruebas a tu programa.

---

## Ejercicio 03: ¡Ahora está raro!

| Ejercicio : 03 |
|----------------|
| ¡Ahora está raro! |
| Directorio de entrega: ex03/ |
| Archivos a entregar: Archivos de ejercicios anteriores + DiamondTrap.{h, hpp}, DiamondTrap.cpp |
| Funciones prohibidas: Ninguna |

En este ejercicio, crearás un monstruo: un ClapTrap que es mitad FragTrap, mitad ScavTrap. Se llamará **DiamondTrap**, y heredará de FragTrap Y ScavTrap. ¡Esto es muy arriesgado!

La clase DiamondTrap tendrá un atributo privado llamado `name`. Este atributo debe tener exactamente el mismo nombre de variable que en la clase base ClapTrap (sin referirse al nombre del robot).

Para ser más claro, aquí hay dos ejemplos: \
Si la variable de ClapTrap es `name`, dale a la variable de DiamondTrap el nombre `name`. \
Si la variable de ClapTrap es `_name`, dale a la variable de DiamondTrap el nombre `_name`.

Sus atributos y funciones miembro se heredarán de sus clases padre:

- Name (nombre), que se pasa como parámetro a un constructor
- `ClapTrap::name` (parámetro del constructor + sufijo `"_clap_name"`)
- Hit points (FragTrap) (puntos de vida)
- Energy points (ScavTrap) (puntos de energía)
- Attack damage (FragTrap) (daño de ataque)
- `attack()` (ScavTrap)

Además de las funciones especiales de ambas clases padre, DiamondTrap tendrá su propia habilidad especial:

`void whoAmI();`

Esta función miembro mostrará tanto su nombre como su nombre de ClapTrap.

Por supuesto, la instancia de ClapTrap de DiamondTrap se creará una vez, y solo una vez. Sí, hay un truco.

De nuevo, agrega más pruebas a tu programa.

[NOTA]
> ¿Conoces las banderas del compilador -Wshadow y -Wno-shadow?
