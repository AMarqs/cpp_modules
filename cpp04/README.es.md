# CPP04

Polimorfismo por subtipo, clases abstractas e interfaces

---

## Ejercicio 00: Polimorfismo

| Ejercicio : 00 |
|----------------|
| Polimorfismo |
| Directorio de entrega: ex00/ |
| Ficheros a entregar: Makefile, main.cpp, *.cpp, *.{h, hpp} |
| Funciones prohibidas: Ninguna |

En cada ejercicio debes proporcionar las pruebas más completas que puedas. Los constructores y destructores de cada clase deben mostrar mensajes específicos. No uses el mismo mensaje para todas las clases.

Empieza implementando una clase base sencilla llamada **Animal**. Tiene un atributo protegido:

- `std::string type;`

Implementa una clase **Dog** que herede de Animal. \
Implementa una clase **Cat** que herede de Animal.

Estas dos clases derivadas deben establecer su campo `type` según su nombre. Así, el tipo de Dog se inicializará a "Dog" y el de Cat a "Cat". El tipo de la clase Animal puede dejarse vacío o establecerse al valor que prefieras.

Cada animal debe poder usar la función miembro: `makeSound()`

Imprimirá un sonido apropiado (los gatos no ladran).

Al ejecutar el siguiente código deberían imprimirse los sonidos específicos de las clases Dog y Cat, no el de Animal.

```
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // ¡imprimirá el sonido del gato!
	j->makeSound();
	meta->makeSound();
	...

	return 0;
}
```

Para asegurarte de que lo entiendes, implementa una clase **WrongCat** que herede de una clase **WrongAnimal**. Si sustituyes Animal y Cat por las versiones "Wrong" en el código anterior, **WrongCat** debería imprimir el sonido de **WrongAnimal**.

Implementa y entrega más pruebas de las dadas arriba.

---

## Ejercicio 01: I don’t want to set the world on fire

| Ejercicio : 01 |
|----------------|
| I don’t want to set the world on fire |
| Directorio de entrega: ex01/ |
| Ficheros a entregar: Ficheros del ejercicio anterior + *.cpp, *.{h, hpp} |
| Funciones prohibidas: Ninguna |

Los constructores y destructores de cada clase deben mostrar mensajes específicos.

Implementa una clase **Brain**. Contiene un array de 100 `std::string` llamado `ideas`.

De este modo, Dog y Cat tendrán un atributo privado `Brain*`. \
Al construirse, Dog y Cat crearán su Brain usando `new Brain();` \
Al destruirse, Dog y Cat eliminarán su Brain.

En tu función `main`, crea y rellena un array de objetos **Animal**. La mitad serán objetos **Dog** y la otra mitad objetos **Cat**. Al final de la ejecución de tu programa, recorre este array y elimina cada Animal. Debes eliminar directamente perros y gatos como Animals. Los destructores apropiados deben llamarse en el orden esperado.

No olvides comprobar que no hay pérdidas de memoria (memory leaks).

La copia de un Dog o un Cat no debe ser superficial (shallow). ¡Debes comprobar que tus copias son profundas (deep copies)!

```
int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j; // no debe crear una fuga
	delete i;
	...

	return 0;
}
```

Implementa y entrega más pruebas de las dadas arriba.

---

## Ejercicio 02: Clase abstracta

| Ejercicio : 02 |
|----------------|
| Clase abstracta |
| Directorio de entrega: ex02/ |
| Ficheros a entregar: Ficheros del ejercicio anterior + *.cpp, *.{h, hpp} |
| Funciones prohibidas: Ninguna |

Crear objetos de tipo Animal no tiene sentido después de todo. Es cierto, ¡no hacen ningún sonido!

Para evitar posibles errores, la clase por defecto Animal no debería poder instanciarse. Arregla la clase Animal para que nadie pueda instanciarla. Todo debe seguir funcionando como antes.

Si lo deseas, puedes actualizar el nombre de la clase añadiendo un prefijo A a Animal.

---

## Ejercicio 03: Interfaz y repaso

| Ejercicio : 03 |
|----------------|
| Interfaz y repaso |
| Directorio de entrega: ex03/ |
| Ficheros a entregar: Makefile, main.cpp, *.cpp, *.{h, hpp} |
| Funciones prohibidas: Ninguna |

Las interfaces no existen en C++98 (ni siquiera en C++20). Sin embargo, a las clases puramente abstractas se las llama comúnmente interfaces. Así que, en este último ejercicio, intentemos implementar interfaces para asegurarnos de que entiendes este módulo.

Completa la definición de la clase **AMateria** siguiente e implementa las funciones miembro necesarias.

```
class AMateria
{
	protected:
		[...]
	
	public:
		AMateria(std::string const & type);
		[...]

		std::string const & getType() const; // Devuelve el tipo de la materia

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
```

Implementa las clases concretas de Materias: **Ice** y **Cure**. Usa sus nombres en minúsculas ("ice" para Ice, "cure" para Cure) para establecer sus tipos. Por supuesto, su función miembro `clone()` devolverá una nueva instancia del mismo tipo (es decir, si clonas una Materia Ice, obtendrás una nueva Materia Ice).

La función miembro `use(ICharacter&)` mostrará:

- Ice: "`* shoots an ice bolt at <name> *`"
- Cure: "`* heals <name>’s wounds *`"

`<name>` es el nombre del Character pasado como parámetro. No imprimas los signos de menor y mayor (< y >).

[NOTA]
> Al asignar una Materia a otra, copiar el tipo no tiene sentido.

Escribe la clase concreta **Character** que implementará la siguiente interfaz:

```
class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};
```

El **Character** posee un inventario de 4 huecos, lo que significa como máximo 4 Materias. El inventario está vacío al construirse. Equipa las Materias en el primer hueco vacío que encuentre, en el siguiente orden: del hueco 0 al 3. Si intenta añadir una Materia a un inventario lleno, o usar/"desequipar" (unequip) una Materia inexistente, no debe ocurrir nada (pero los bugs siguen estando prohibidos). ¡La función `unequip()` NO debe borrar la Materia!

[NOTA]
> Gestiona como prefieras las Materias que tu personaje deje en el suelo. Guarda las direcciones antes de llamar a `unequip()`, o lo que consideres, pero no olvides que debes evitar fugas de memoria.

La función `use(int, ICharacter&)` tendrá que usar la Materia en `slot[idx]`, y pasar el parámetro `target` a la función `AMateria::use`.

[ADVERTENCIA]
> El inventario de tu personaje debe poder soportar cualquier tipo de `AMateria`.

Tu **Character** debe tener un constructor que reciba su nombre como parámetro. Cualquier copia (usando constructor de copia u operador de asignación) de un Character debe ser **profunda** (deep). Durante la copia, las Materias de un Character deben borrarse antes de que se añadan las nuevas a su inventario. Por supuesto, las Materias deben borrarse cuando un Character es destruido.

Escribe la clase concreta **MateriaSource** que implementará la siguiente interfaz:

```
class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};
```

- `learnMateria(AMateria*)` \
Copia la Materia pasada como parámetro y la almacena en memoria para que pueda clonarse más tarde. Al igual que el Character, **MateriaSource** puede conocer como máximo 4 Materias. No es necesario que sean únicas.

- `createMateria(std::string const &)` \
Devuelve una nueva Materia. Esta será una copia de la Materia previamente aprendida por **MateriaSource** cuyo tipo sea igual al pasado como parámetro. Devuelve 0 si el tipo es desconocido.

En resumen, tu **MateriaSource** debe ser capaz de aprender "plantillas" de Materias para crearlas cuando sea necesario. Luego, podrás generar una nueva Materia usando solo una cadena que identifique su tipo.

Al ejecutar este código:

```
int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	
	return 0;
}
```

Debe mostrar:

```
$> clang++ -W -Wall -Werror *.cpp
$> ./a.out | cat -e
* shoots an ice bolt at bob *$
* heals bob's wounds *$
```

Como siempre, implementa y entrega más pruebas de las dadas arriba.
