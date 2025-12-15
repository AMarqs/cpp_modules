# CPP00

Espacios de nombres, clases, funciones miembro, stdio streams, listas de inicialización, static, const, y otras cosas básicas.

---

## Ejercicio 00: Megáfono

| Ejercicio : 00 |
|-------------|
| Megaphone |
| Directorio de entrega: ex00/ |
| Archivos a entregar: Makefile, megaphone.cpp |
| Funciones prohibidas: Ninguna |

Solo para asegurarnos de que todos estén despiertos, escribe un programa que produzca la siguiente salida:

```
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *$>
```

---

## Ejercicio 01: Mi Increíble Agenda Telefónica

| Ejercicio : 01 |
|-------------|
| My Awesome PhoneBook |
| Directorio de entrega: ex01/ |
| Archivos a entregar: Makefile, *.cpp, *.{h, hpp} |
| Funciones prohibidas: Ninguna |

¡Bienvenido a los años 80 y su increíble tecnología! Escribe un programa que se comporte como un software de agenda telefónica increíblemente malo.

Tienes que implementar dos clases:

- PhoneBook
	- Tiene un array de contactos.
	- Puede almacenar un máximo de 8 contactos. Si el usuario intenta agregar un noveno contacto, reemplaza el más antiguo por el nuevo.
	- Ten en cuenta que la asignación dinámica está prohibida.

- Contact
	- Representa un contacto de la agenda telefónica.
	
En tu código, la agenda telefónica debe ser instanciada como una instancia de la clase PhoneBook. Lo mismo para los contactos. Cada uno de ellos debe ser instanciado como una instancia de la clase Contact. Eres libre de diseñar las clases como quieras, pero ten en cuenta que todo lo que siempre se use dentro de una clase es privado, y todo lo que se pueda usar fuera de una clase es público.

Al inicio del programa, la agenda telefónica está vacía y se solicita al usuario que ingrese uno de tres comandos. El programa solo acepta ADD, SEARCH y EXIT.

- ADD: guardar un nuevo contacto
	- Si el usuario ingresa este comando, se le solicita que ingrese la información del nuevo contacto campo por campo. Una vez que todos los campos hayan sido completados, agrega el contacto a la agenda telefónica.
	- Los campos del contacto son: nombre, apellido, apodo, número de teléfono y secreto más oscuro. Un contacto guardado no puede tener campos vacíos.
	
- SEARCH: mostrar un contacto específico
	- Muestra los contactos guardados como una lista de 4 columnas: índice, nombre, apellido y apodo.
	- Cada columna debe tener 10 caracteres de ancho. Un carácter de tubería ('|') las separa. El texto debe estar alineado a la derecha. Si el texto es más largo que la columna, debe ser truncado y el último carácter mostrable debe ser reemplazado por un punto ('.').
	- Luego, solicita al usuario nuevamente el índice de la entrada a mostrar. Si el índice está fuera de rango o es incorrecto, define un comportamiento relevante. De lo contrario, muestra la información del contacto, un campo por línea.
	
- EXIT
	- ¡El programa termina y los contactos se pierden para siempre!
	
- Cualquier otra entrada es ignorada.

Una vez que un comando haya sido ejecutado correctamente, el programa espera otro. Se detiene cuando el usuario ingresa EXIT.

---

## Ejercicio 02: El Trabajo de Tus Sueños

| Ejercicio : 02 |
|-------------|
| The Job Of Your Dreams |
| Directorio de entrega: ex02/ |
| Archivos a entregar: Makefile, Account.cpp, Account.hpp, tests.cpp |
| Funciones prohibidas: Ninguna |

[!NOTE]
> Account.hpp, tests.cpp, y el archivo de registro están disponibles para descargar en la página de intranet del módulo.

Hoy es tu primer día en *GlobalBanksters United*. Después de pasar exitosamente las pruebas de reclutamiento (gracias a algunos trucos de *Microsoft Office* que te mostró un amigo), te uniste al equipo de desarrollo. También sabes que el reclutador quedó impresionado por la rapidez con la que instalaste *Adobe Reader*. Ese pequeño extra marcó toda la diferencia y te ayudó a vencer a todos tus oponentes (también conocidos como los otros candidatos): ¡lo lograste!

De todos modos, tu gerente acaba de darte algo de trabajo que hacer. Tu primera tarea es recrear un archivo perdido. Algo salió mal y un archivo fuente fue eliminado por error. Desafortunadamente, tus colegas no saben qué es Git y usan  USB para compartir código. En este punto, tendría sentido salir de este lugar ahora mismo. Sin embargo, decides quedarte. ¡Desafío aceptado!

Tus compañeros desarrolladores te dan un montón de archivos. Compilar tests.cpp revela que el archivo faltante es Account.cpp. Afortunadamente para ti, el archivo de encabezado Account.hpp fue guardado. También hay un archivo de registro. Tal vez podrías usarlo para entender cómo fue implementada la clase Account.

Empiezas a recrear el archivo Account.cpp. En solo unos minutos, codificas algunas líneas de puro C++ increíble. Después de un par de compilaciones fallidas, tu programa pasa las pruebas. Su salida coincide perfectamente con la guardada en el archivo de registro (excepto por las marcas de tiempo que obviamente diferirán ya que las pruebas guardadas en el archivo de registro se ejecutaron antes de que fueras contratado).

[!NOTE]
> El orden en que los destructores son llamados puede diferir dependiendo de tu compilador/sistema operativo. Así que tus destructores pueden ser llamados en orden inverso.