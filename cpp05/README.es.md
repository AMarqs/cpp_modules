# CPP05:

Repetición y Excepciones

---

## Ejercicio 00: ¡Mami, cuando sea grande, quiero ser burócrata!

| Ejercicio : 00 |
|---------------|
| ¡Mami, cuando sea grande, quiero ser burócrata! |
| Directorio: ex00/ |
| Archivos a entregar: Makefile, main.cpp, Bureaucrat.{h, hpp}, Bureaucrat.cpp |
| Prohibido: Ninguno |

[NOTA]
> Ten en cuenta que las clases de excepción no tienen que ser diseñadas en Forma Canónica Ortodoxa. Sin embargo, todas las demás clases deben seguirla.

Diseñemos una pesadilla artificial de oficinas, pasillos, formularios y colas de espera. ¿Suena divertido? ¿No? Qué mal.

Primero, empecemos con el engranaje más pequeño de esta vasta máquina burocrática: el **Burócrata**. Un Burócrata debe tener:

- Un `nombre` constante.
- Un `grado` que va de 1 (el grado más alto posible) a 150 (el grado más bajo posible).

Cualquier intento de instanciar un Burócrata con un grado inválido debe lanzar una excepción: ya sea `Bureaucrat::GradeTooHighException` o `Bureaucrat::GradeTooLowException`.

Proporcionarás getters para ambos atributos: `getName()` y `getGrade()`. También debes implementar dos funciones miembro para incrementar o decrementar el grado del burócrata. Si el grado se sale del rango, ambas funciones deben lanzar las mismas excepciones que el constructor.

[ADVERTENCIA]
> Recuerda, como el grado 1 es el más alto y el 150 el más bajo, incrementar un grado 3 debería resultar en un grado 2 para el burócrata.

Las excepciones lanzadas deben poder ser capturadas usando bloques `try` y `catch`:

```cpp
try
{
    /* hacer algunas cosas con los burócratas */
}
catch (std::exception & e)
{
    /* manejar la excepción */
}
```

Debes implementar una sobrecarga del operador de inserción (`<<`) para imprimir la salida en el siguiente formato (sin los corchetes angulares):

`<nombre>, burócrata grado <grado>.`

Como de costumbre, entrega algunas pruebas para demostrar que todo funciona como se espera.

---

## Ejercicio 01: ¡En formación, gusanos!

| Ejercicio : 01 |
|---------------|
| ¡En formación, gusanos! |
| Directorio: ex01/ |
| Archivos a entregar: Archivos del ejercicio anterior + Form.{h, hpp}, Form.cpp |
| Prohibido: Ninguno |

Ahora que tienes burócratas, démosles algo que hacer. ¿Qué mejor actividad podría haber que llenar una pila de formularios?

Creemos una clase **Formulario**. Tiene:

- Un `nombre` constante.
- Un `booleano` que indica si está firmado (en la construcción, no lo está).
- Un `grado` constante requerido para firmarlo.
- Un `grado` constante requerido para ejecutarlo.

Todos estos atributos son **privados**, no protegidos.

Los grados del **Formulario** siguen las mismas reglas que los del Burócrata. Por lo tanto, se lanzarán las siguientes excepciones si el grado de un formulario está fuera de los límites:

`Form::GradeTooHighException` y `Form::GradeTooLowException`.

Como antes, escribe getters para todos los atributos y sobrecarga el operador de inserción (`<<`) para imprimir toda la información del formulario.

Además, añade una función miembro `beSigned()` al `Formulario` que tome un Burócrata como parámetro. Cambia el estado del formulario a firmado si el grado del burócrata es suficientemente alto (mayor o igual al requerido). Recuerda, el grado 1 es más alto que el grado 2. Si el grado es demasiado bajo, lanza una `Form::GradeTooLowException`.

Luego, añade una función miembro `signForm()` en la clase Burócrata. Esta función debe llamar a `Form::beSigned()` para intentar firmar el formulario. Si el formulario se firma con éxito, imprimirá algo como:

`<burócrata> firmó <formulario>`

De lo contrario, imprimirá algo como:

`<burócrata> no pudo firmar <formulario> porque <razón>.`

Implementa y entrega algunas pruebas para asegurar que todo funciona como se espera.

---

## Ejercicio 02: No, necesitas el formulario 28B, no el 28C...

| Ejercicio : 02 |
|---------------|
| No, necesitas el formulario 28B, no el 28C... |
| Directorio: ex02/ |
| Archivos a entregar: Makefile, main.cpp, Bureaucrat.[{h, hpp},cpp], + AForm.[{h, hpp},cpp], ShrubberyCreationForm.[{h, hpp},cpp], + RobotomyRequestForm.[{h, hpp},cpp], PresidentialPardonForm.[{h, hpp},cpp] |
| Prohibido: Ninguno |

Ahora que tienes formularios básicos, es hora de crear algunos más que realmente hagan algo.

En todos los casos, la clase base Formulario debe ser una clase abstracta y, por lo tanto, debe ser renombrada como AForm. Ten en cuenta que los atributos del formulario deben permanecer privados y que pertenecen a la clase base.

Añade las siguientes clases concretas:

- **ShrubberyCreationForm:** Grados requeridos: firma 145, ejecución 137
    Crea un archivo `<target>_shrubbery` en el directorio de trabajo y escribe árboles ASCII dentro de él.

- **RobotomyRequestForm:** Grados requeridos: firma 72, ejecución 45
    Hace algunos ruidos de perforación, luego informa que `<target>` ha sido robotomizado con éxito el 50% de las veces. De lo contrario, informa que la robotomización falló.

- **PresidentialPardonForm:** Grados requeridos: firma 25, ejecución 5
    Informa que `<target>` ha sido perdonado por Zaphod Beeblebrox.

Todos ellos toman solo un parámetro en su constructor: el objetivo del formulario. Por ejemplo, "casa" si quieres plantar arbustos en casa.

Ahora, añade la función miembro `execute(Bureaucrat const & executor) const` al formulario base e implementa una función para ejecutar la acción del formulario en las clases concretas. Debes verificar que el formulario esté firmado y que el grado del burócrata que intenta ejecutar el formulario sea suficientemente alto. De lo contrario, lanza una excepción apropiada.

Si verificas los requisitos en cada clase concreta o en la clase base (y luego llamas a otra función para ejecutar el formulario) depende de ti. Sin embargo, una forma es más elegante que la otra.

Finalmente, añade la función miembro `executeForm(AForm const & form) const` a la clase Burócrata. Debe intentar ejecutar el formulario. Si tiene éxito, imprime algo como:

`<burócrata> ejecutó <formulario>`

Si no, imprime un mensaje de error explícito.

Implementa y entrega algunas pruebas para asegurar que todo funciona como se espera.

---

## Ejercicio 03: Al menos esto es mejor que hacer café

| Ejercicio : 03 |
|---------------|
| Al menos esto es mejor que hacer café |
| Directorio: ex03/ |
| Archivos a entregar: Archivos de ejercicios anteriores + Intern.{h, hpp}, Intern.cpp |
| Prohibido: Ninguno |

Dado que llenar formularios todo el día sería demasiado cruel para nuestros burócratas, existen los becarios para asumir esta tediosa tarea. En este ejercicio, debes implementar la clase **Interno**. El becario no tiene nombre, ni grado, ni características únicas. Lo único que les importa a los burócratas es que hagan su trabajo.

Sin embargo, el becario tiene una habilidad clave: la función `makeForm()`. Esta función toma dos cadenas como parámetros: la primera representa el nombre de un formulario y la segunda representa el objetivo del formulario. Devuelve un puntero a un objeto `AForm` (correspondiente al nombre del formulario pasado como parámetro), con su objetivo inicializado al segundo parámetro.

Debería imprimir algo como:

`El becario crea <formulario>`

Si el nombre del formulario proporcionado no existe, imprime un mensaje de error explícito.

Debes evitar soluciones ilegibles y desordenadas, como usar una estructura excesiva de `if/elseif/else`. Este tipo de enfoque no será aceptado durante el proceso de evaluación. Como de costumbre, debes probar todo para asegurar que funciona como se espera.

Por ejemplo, el siguiente código crea un **RobotomyRequestForm** dirigido a "Bender":

```cpp
{
    Intern someRandomIntern;
    AForm* rrf;
    
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
```
