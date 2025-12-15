# Resumen Completo de C++ (Módulos 00-04)

## CPP00: Fundamentos de Programación Orientada a Objetos

### Namespaces
Los espacios de nombres permiten organizar el código y evitar conflictos de nombres. En C++ usamos `std::` para acceder a la biblioteca estándar. Por ejemplo, `std::cout` en lugar de solo `cout`.

### Clases y Objetos
Una clase es un tipo de dato personalizado que encapsula datos (atributos) y funciones (métodos). Un objeto es una instancia de una clase. Por ejemplo, `PhoneBook` es una clase que puede almacenar contactos, y cada instancia de `PhoneBook` es un objeto independiente con su propio conjunto de contactos.

### Member Functions (Funciones Miembro)
Son funciones que pertenecen a una clase y operan sobre sus datos. Pueden ser públicas (accesibles desde fuera) o privadas (solo accesibles dentro de la clase). Por ejemplo, `addContact()` es una función miembro de `PhoneBook`.

### stdio streams
C++ usa streams para entrada/salida: `std::cout` para imprimir en pantalla, `std::cin` para leer del teclado. Son más seguros y fáciles de usar que `printf()` y `scanf()`.

### Initialization Lists
Permiten inicializar atributos de una clase directamente en el constructor, antes de que se ejecute su cuerpo. Son más eficientes que asignar valores dentro del constructor:

```cpp
Contact::Contact() : firstName(""), lastName("") { }
// Más eficiente que:
Contact::Contact()
{
    firstName = "";
    lastName = "";
}
```

### static y const
- `static`: Hace que un atributo sea compartido por todas las instancias de una clase, o que una función pueda llamarse sin crear un objeto.
- `const`: Indica que un valor no puede modificarse después de su inicialización, o que una función no modifica el objeto.

### Encapsulación (public vs private)
Los atributos deben ser privados para proteger los datos y evitar modificaciones no deseadas. Solo se accede a ellos mediante funciones públicas (getters/setters).

### Arrays Estáticos
Arrays de tamaño fijo que se almacenan en el stack. Por ejemplo, un `PhoneBook` puede tener un array de 8 contactos sin usar asignación dinámica.

---

## CPP01: Gestión de Memoria y Referencias

### Stack vs Heap
- **Stack**: Memoria automática, rápida, tamaño limitado. Las variables se destruyen al salir del scope.
- **Heap**: Memoria dinámica, manual (usando `new`/`delete`), más grande pero más lenta. Útil cuando no sabes cuánta memoria necesitas o cuando los objetos deben vivir más allá del scope actual.

### Asignación Dinámica (new y delete)
- `new` reserva memoria en el heap y devuelve un puntero: `Zombie* z = new Zombie("Foo");`
- `delete` libera la memoria: `delete z;`
- `new[]` para arrays: `Zombie* horde = new Zombie[N];`
- `delete[]` para liberar arrays: `delete[] horde;`

**Regla de oro**: Cada `new` debe tener su correspondiente `delete` para evitar memory leaks.

### Punteros
Variables que almacenan direcciones de memoria. Permiten manipulación directa de memoria y pasar datos por referencia. Se declaran con `*`:

```cpp
int* ptr = &variable;  // ptr apunta a variable
*ptr = 42;             // modifica el valor de variable
```

### Referencias
Una forma más segura y limpia de trabajar con direcciones. Se declaran con `&` y actúan como un alias de una variable:

```cpp
int& ref = variable;   // ref es un alias de variable
ref = 42;              // modifica variable
```

**Diferencia clave**: Los punteros pueden ser nulos o cambiar a qué apuntan; las referencias siempre deben inicializarse y no pueden cambiar su objetivo.

### Pointers to Member Functions
Punteros que apuntan a funciones miembro de una clase. Útiles para implementar callbacks o tablas de funciones:

```cpp
void (Harl::*complaints[4])(void) = {
    &Harl::debug, &Harl::info, &Harl::warning, &Harl::error
};
```
Esto evita largas cadenas de if/else.

### Memory Leaks
Ocurren cuando reservas memoria con `new` pero olvidas liberarla con `delete`. El programa consume memoria indefinidamente. Usa herramientas como `valgrind` para detectarlos:

```bash
valgrind --leak-check=full ./programa
```

### Switch Statements
Alternativa más limpia a múltiples if/else cuando comparas una variable contra varios valores constantes:

```cpp
switch (level)
{
    case WARNING:
        // código
        break;
    case ERROR:
        // código
        break;
}
```

---

## CPP02: Polimorfismo Ad-hoc y Sobrecarga de Operadores

### Orthodox Canonical Form (OCF)
Todas las clases deben implementar estas 4 funciones:

1. **Constructor por defecto**: Inicializa el objeto sin parámetros
   ```cpp
   Fixed::Fixed() : _value(0) { }
   ```

2. **Constructor de copia**: Crea un nuevo objeto copiando otro existente
   ```cpp
   Fixed::Fixed(const Fixed& other) : _value(other._value) { }
   ```

3. **Operador de asignación**: Copia los valores de un objeto a otro ya existente
   ```cpp
   Fixed& operator=(const Fixed& other)
   {
       if (this != &other)
           _value = other._value;
       return *this;
   }
   ```

4. **Destructor**: Libera recursos cuando el objeto se destruye
   ```cpp
   ~Fixed::Fixed() { }
   ```

**¿Por qué es importante?** Evita comportamientos indefinidos al copiar objetos y problemas con memoria dinámica.

### Operator Overloading (Sobrecarga de Operadores)
Permite que tus clases usen operadores como `+`, `-`, `==`, `<<`, etc., de forma natural:

```cpp
Fixed a(2), b(3);
Fixed c = a + b;           // operator+
if (a < b) { }             // operator<
std::cout << a;            // operator<<
```

Los operadores se implementan como funciones miembro o funciones amigas. Por ejemplo:

```cpp
Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}
```

### Fixed-Point Numbers
Alternativa a los números de punto flotante. Usan un entero para representar tanto la parte entera como la fraccionaria. Por ejemplo, con 8 bits fraccionales, el número 42.5 se representa como `42.5 * 256 = 10880` (entero).

**Ventajas**: Más rápidos y predecibles que los floats, útiles en sistemas embebidos o gráficos.

### Conversión entre Tipos
Implementar constructores y funciones de conversión permite convertir entre tu clase y tipos primitivos:

```cpp
Fixed::Fixed(int value) : _value(value << _fractionalBits) { }
Fixed::Fixed(float value) : _value(roundf(value * (1 << _fractionalBits))) { }
int Fixed::toInt() const { return _value >> _fractionalBits; }
float Fixed::toFloat() const { return (float)_value / (1 << _fractionalBits); }
```

### Static Member Functions
Funciones que pertenecen a la clase, no a instancias individuales. No necesitan un objeto para ser llamadas:
```cpp
Fixed::max(a, b);  // No necesitas un objeto Fixed específico
```

### Const Correctness
Disciplina de marcar como `const` todo lo que no modifica datos:
- Parámetros que no se modifican: `void func(const Fixed& f)`
- Funciones que no modifican el objeto: `int getValue() const`
- Variables que no cambian: `const int MAX = 100`

Esto previene errores y hace el código más seguro y claro.

---

## CPP03: Herencia y Jerarquías de Clases

### Inheritance (Herencia)
Permite crear clases nuevas basadas en clases existentes, reutilizando código. La clase derivada hereda atributos y métodos de la clase base:

```cpp
class Hijo : public Padre
{
    // Hijo hereda todo de Padre
};
```

**¿Por qué usar herencia?** Para modelar relaciones "es-un" (Hijo ES-UN Padre) y evitar duplicar código.

### Protected Attributes
Nivel de acceso intermedio entre `private` y `public`. Los atributos `protected` son accesibles por la clase y sus derivadas, pero no desde fuera:

```cpp
class Padre
{
    protected:
        int _hitPoints;  // Hijo puede acceder a esto
};
```

### Construction/Destruction Chaining
Cuando creas un objeto derivado, primero se construye la clase base, luego la derivada. La destrucción ocurre en orden inverso:

```cpp
// Crear Hijo:
// 1. Constructor Padre
// 2. Constructor Hijo

// Destruir Hijo:
// 1. Destructor Hijo
// 2. Destructor Padre
```

Esto asegura que los recursos se manejen correctamente.

### Virtual Functions
Funciones que pueden ser sobreescritas en clases derivadas. El método correcto se llama según el tipo real del objeto, no el tipo del puntero:

```cpp
class Animal
{
    public:
       virtual void makeSound() { std::cout << "???" << std::endl; }
};

class Dog : public Animal
{
    public:
        void makeSound() { std::cout << "Woof!" << std::endl; }
};

Animal* pet = new Dog();
pet->makeSound();  // Imprime "Woof!" gracias a virtual
```

### Multiple Inheritance
Una clase puede heredar de múltiples clases base:

```cpp
class DiamondTrap : public FragTrap, public ScavTrap
{
    // Hereda de ambas
};
```

### Diamond Problem
Problema que surge con herencia múltiple cuando dos clases base heredan de una misma clase:
```
    ClapTrap
    /      \
FragTrap  ScavTrap
    \      /
  DiamondTrap
```

DiamondTrap tendría dos copias de los atributos de ClapTrap, causando ambigüedad.

### Virtual Inheritance
Solución al diamond problem. Asegura que solo haya una copia de la clase base compartida:

```cpp
class FragTrap : virtual public ClapTrap { };
class ScavTrap : virtual public ClapTrap { };
```

### Overriding Methods
Reemplazar el comportamiento de un método heredado en la clase derivada. Permite personalizar funcionalidad:

```cpp
class ScavTrap : public ClapTrap
{
    public:
        void attack(const std::string& target)
        {
            // Implementación diferente a ClapTrap
        }
};
```

---

## CPP04: Polimorfismo de Subtipo, Clases Abstractas e Interfaces

### Subtype Polymorphism
Capacidad de tratar objetos derivados como si fueran objetos de la clase base. Permite escribir código genérico:

```cpp
Animal* animals[10];
animals[0] = new Dog();
animals[1] = new Cat();

for (int i = 0; i < 2; i++)
    animals[i]->makeSound();  // Cada uno hace su sonido
```

### Virtual Functions y VTables
Cuando declaras una función `virtual`, C++ crea una tabla virtual (vtable) para despacho dinámico. En tiempo de ejecución, se busca qué versión del método llamar según el tipo real del objeto.

### Abstract Classes (Clases Abstractas)
Clases que no pueden instanciarse directamente, diseñadas para ser heredadas. Definen una interfaz común:

```cpp
class AAnimal   // 'A' de Abstract
{  
    public:
        virtual void makeSound() = 0;  // Pura virtual
};

// Error: AAnimal a;  // No se puede instanciar
Dog d;  // OK, Dog implementa makeSound()
```

### Pure Virtual Functions
Funciones declaradas como `= 0`, sin implementación. Obligan a las clases derivadas a implementarlas:

```cpp
virtual void makeSound() = 0;  // Función pura virtual
```

Cualquier clase con al menos una función pura virtual es abstracta.

### Interfaces
En C++98 no existen interfaces formalmente, pero se simulan con clases abstractas puras (solo funciones virtuales puras, sin atributos):

```cpp
class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const& getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};
```

### Deep Copy vs Shallow Copy
- **Shallow copy**: Copia solo los valores de los atributos. Si hay punteros, ambos objetos apuntan a la misma memoria (¡peligro!).
- **Deep copy**: Copia también los datos apuntados, creando copias independientes:

```cpp
Dog::Dog(const Dog& other)
{
    _brain = new Brain(*other._brain);  // Copia profunda
}
```

**Crucial** cuando trabajas con punteros o memoria dinámica.

### Virtual Destructors
Si una clase se usa como base para herencia, su destructor **debe ser virtual**:

```cpp
class Animal
{
    public:
        virtual ~Animal() { }  // IMPORTANTE
};
```

Si no es virtual, al borrar un objeto derivado mediante un puntero a la base, solo se llama al destructor de la base, causando memory leaks.

### Dynamic Binding (Enlace Dinámico)
La decisión de qué función llamar se toma en tiempo de ejecución, no en compilación. Esto permite polimorfismo real:

```cpp
Animal* pet = rand() % 2 ? new Dog() : new Cat();
pet->makeSound();  // No sabemos qué sonido hasta que se ejecute
```

### Composition (Composición)
Incluir objetos de otras clases como atributos. "Tiene-un" en lugar de "es-un". Por ejemplo, Dog tiene-un Brain:

```cpp
class Dog : public Animal
{
    private:
        Brain* _brain;
};
```

La composición es más flexible que la herencia y debe preferirse cuando la relación no es claramente "es-un".

---

