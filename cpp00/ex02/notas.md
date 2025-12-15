# ENUNCIADO

Hoy es tu primer día en GlobalBanksters United. Después de superar con éxito las pruebas de reclutamiento 
(gracias a algunos trucos de Microsoft Office que te enseñó un amigo), te uniste al equipo de desarrollo. 
También sabes que el reclutador quedó impresionado por la rapidez con la que instalaste Adobe Reader. 
Ese pequeño extra marcó la diferencia y te ayudó a vencer a todos tus oponentes (es decir, los otros 
candidatos): ¡lo lograste!

De todos modos, tu jefe acaba de darte trabajo. Tu primera tarea es recrear un archivo perdido. 
Algo salió mal y un archivo fuente fue borrado por error. Desafortunadamente, tus compañeros no saben qué 
es Git y usan memorias USB para compartir código. En este punto, tendría sentido irte de este lugar ahora 
mismo. Sin embargo, decides quedarte. ¡Reto aceptado!

Tus compañeros desarrolladores te dan un montón de archivos. Al compilar tests.cpp descubres que el 
archivo que falta es Account.cpp. Por suerte, el archivo de cabecera Account.hpp se salvó. También hay un 
archivo de registro. Quizás podrías usarlo para entender cómo se implementó la clase Account.

Empiezas a recrear el archivo Account.cpp. En solo unos minutos, escribes unas líneas de puro y asombroso 
C++. Tras un par de compilaciones fallidas, tu programa pasa las pruebas. Su salida coincide perfectamente 
con la guardada en el archivo de registro (excepto por las marcas de tiempo, que obviamente serán 
diferentes ya que las pruebas guardadas en el archivo de registro se ejecutaron antes de que te 
contrataran)

# EXPLICACIÓN

En el ejercicio 2 (“Account”), debes implementar una clase en C++ que simule cuentas bancarias y gestione operaciones como depósitos, retiros y mostrar información de las cuentas. El objetivo es practicar conceptos fundamentales de C++ orientado a objetos, como:

- Clases y objetos: Definir la clase Account con atributos y métodos adecuados.

- Atributos estáticos: Usar variables estáticas para llevar el conteo global de cuentas, depósitos, retiros y el monto total.

- Constructores y destructores: Implementar el constructor para inicializar cada cuenta y el destructor para manejar el cierre de cuentas.

- Métodos de instancia y estáticos: Métodos para operar sobre una cuenta individual (depósito, retiro, mostrar estado) y métodos estáticos para mostrar información global de todas las cuentas.

- Const y static: Usar correctamente los modificadores const y static según corresponda.

- Inicialización y encapsulamiento: Inicializar correctamente los atributos y mantener la información privada cuando sea necesario.

- Salida formateada: Mostrar la información siguiendo el formato del archivo de log, incluyendo timestamps.

No debes usar memoria dinámica ni librerías externas (solo la estándar de C++98). El ejercicio te ayuda a entender cómo modelar entidades reales (cuentas bancarias) usando clases, cómo compartir información entre instancias usando atributos estáticos, y cómo estructurar tu código de forma clara y mantenible.

# PASOS GENÉRICOS

- Paso 1: Define los atributos estáticos y de instancia

	En la clase Account, necesitas atributos estáticos para llevar el conteo global de cuentas, depósitos, retiros y el monto total.
	También necesitas atributos de instancia para cada cuenta: índice, monto, número de depósitos y retiros.

	¿Qué hacer?
	Revisa el header y asegúrate de tener los atributos privados necesarios.
	Los atributos estáticos se inicializan fuera de la clase, en el archivo .cpp.

- Paso 2: Implementa el constructor
	El constructor debe asignar el índice de la cuenta, inicializar el monto con el depósito inicial y actualizar los contadores globales.

	¿Qué hacer?
	En el constructor, incrementa el número de cuentas y suma el depósito inicial al total global.
	Asigna el índice usando el contador de cuentas antes de incrementarlo.

- Paso 3: Implementa el destructor
	El destructor debe mostrar un mensaje indicando que la cuenta se ha cerrado y actualizar los contadores globales si es necesario.

	¿Qué hacer?
	Muestra el estado de la cuenta al cerrarse (puedes inspirarte en el log).
	No olvides el formato de salida.

- Paso 4: Métodos de depósito y retiro
	makeDeposit(int deposit): suma el depósito al monto de la cuenta y actualiza los contadores globales.
	makeWithdrawal(int withdrawal): resta el retiro si hay suficiente saldo, actualiza los contadores y muestra el resultado.

	¿Qué hacer?
	Implementa la lógica para modificar los atributos y mostrar la información correspondiente.

- Paso 5: Métodos de información
	displayStatus(): muestra el estado actual de la cuenta.
	displayAccountsInfos(): muestra la información global de todas las cuentas.

	¿Qué hacer?
	Usa los atributos estáticos para mostrar la información global.
	Usa los atributos de instancia para mostrar la información de cada cuenta.

- Paso 6: Timestamps
	El log muestra un timestamp en cada línea. Implementa el método estático _displayTimestamp() para mostrar la fecha y hora en el formato adecuado.

	¿Qué hacer?
	Investiga cómo obtener la fecha y hora en C++98 y formatearla como en el log.


# PASO A PASO

## PASO 1

1. **Atributos estáticos y de instancia**

	Atributos estáticos (compartidos por todas las cuentas):

	- _nbAccounts: número total de cuentas creadas.
	- _totalAmount: suma total de dinero en todas las cuentas.
	- _totalNbDeposits: número total de depósitos realizados.
	- _totalNbWithdrawals: número total de retiros realizados.

	Atributos de instancia (propios de cada cuenta):

	- _accountIndex: índice único de la cuenta.
	- _amount: dinero actual en la cuenta.
	- _nbDeposits: número de depósitos realizados en esta cuenta.
	- _nbWithdrawals: número de retiros realizados en esta cuenta.

	¿Qué tienes que hacer?

	En el archivo Account.hpp, ya están declarados estos atributos.
	En el archivo Account.cpp, debes inicializar los atributos estáticos fuera de la clase, así:
	Esto se pone al principio del archivo .cpp, fuera de cualquier función.


# PASO 2

1. **Inicialización en el constructor**

	Cuando creas una nueva cuenta, debes:

	- Asignar el índice de la cuenta (_accountIndex) usando el valor actual de _nbAccounts antes de incrementarlo.
	- Inicializar el monto (_amount) con el valor recibido como parámetro (initial_deposit).
	- Inicializar los contadores de depósitos y retiros de la cuenta en cero.
	- Actualizar los atributos estáticos: incrementar _nbAccounts y sumar el depósito inicial a _totalAmount.

	¿Qué hacer ahora?

	Ve al constructor en Account.cpp y escribe estas inicializaciones dentro del cuerpo del constructor.
	Recuerda que puedes mostrar un mensaje de creación de cuenta (usando el formato del log) para comprobar que funciona.

2. **Mostrar mensaje de creación con timestamp**

	Cuando se crea una cuenta, el log muestra algo así:

	[19920104_091532] index:0;amount:42;created

	Tu programa debe imprimir una línea similar cada vez que se crea una cuenta.

	¿Cómo hacerlo?

	- Método para mostrar el timestamp:
	Implementa un método estático llamado _displayTimestamp() en la clase Account. Este método debe imprimir la fecha y hora entre corchetes, por ejemplo: [YYYYMMDD_HHMMSS].
	Para empezar, puedes usar una fecha fija para probar, y luego investigar cómo obtener la fecha actual en C++98.

	- En el constructor:
	Llama a _displayTimestamp() y luego imprime el resto de la información: index:<_accountIndex>;amount:<_amount>;created

	Ejemplo de lógica (no el código completo):

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;

	¿Qué hacer ahora?

	Implementa el método _displayTimestamp() como estático en tu archivo .cpp.
	Llama a ese método y muestra el mensaje en el constructor después de inicializar los atributos.

3. **Método timestamp**

	Para hacer el método _displayTimestamp() en C++98, puedes usar las funciones de la librería <ctime> para obtener la fecha y hora actual y formatearla como en el log.

	Aquí tienes los pasos y el ejemplo de código para implementarlo:

	1. Incluye la librería necesaria
	2. Implementa el método estático en Account.cpp
	3. No olvides incluir <iomanip> para usar std::setw y std::setfill.

	¿Qué hace este método?

	Obtiene la fecha y hora actual.
	La imprime en el formato [YYYYMMDD_HHMMSS].
	Ahora puedes llamar a Account::_displayTimestamp(); antes de imprimir cualquier mensaje que requiera el timestamp.


# PASO 3

¿Qué debe hacer el destructor de Account?

1. Mostrar el mensaje de cierre de cuenta:

	Debe imprimir una línea similar al log, por ejemplo:
	[timestamp] index:0;amount:42;closed

	Usando el método _displayTimestamp() para el timestamp.

2. Actualizar contadores globales si es necesario:

	En este ejercicio, normalmente solo se muestra el mensaje. Los contadores globales suelen actualizarse en los métodos de depósito/retiro, pero si quieres, puedes restar el monto de la cuenta al total global aquí (no es obligatorio según el log).

	Ejemplo de lógica para el destructor (no el código completo):
	¿Qué hacer ahora?

	Ve al destructor en Account.cpp.
	Llama a _displayTimestamp() y muestra el mensaje con el índice y el monto de la cuenta, seguido de ;closed.


# PASO 4

## Método de Depósito: makeDeposit(int deposit)

Lógica:

- Muestra el timestamp.
- Muestra el estado previo de la cuenta (p_amount).
- Suma el depósito al monto de la cuenta.
- Actualiza el contador de depósitos de la cuenta y el global.
- Actualiza el monto total global.
- Muestra el estado después del depósito (incluye el nuevo monto y el número de depósitos).

Formato de salida (según el log):
[timestamp] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1

## Método de Retiro: makeWithdrawal(int withdrawal)

Lógica:

- Muestra el timestamp.
- Muestra el estado previo de la cuenta (p_amount).
- Si el retiro es posible (hay suficiente saldo):
	- Resta el retiro al monto de la cuenta.
	- Actualiza el contador de retiros de la cuenta y el global.
	- Actualiza el monto total global.
	- Muestra el estado después del retiro (incluye el nuevo monto y el número de retiros).
- Si el retiro no es posible:
	- Muestra el mensaje de retiro rechazado.

Formato de salida (según el log):
- Si el retiro es exitoso:
[timestamp] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
-  Si el retiro es rechazado:
[timestamp] index:0;p_amount:47;withdrawal:refused


# PASO 5

## Método de instancia: displayStatus()

Lógica:

- Muestra el estado actual de la cuenta.
- Debe incluir el timestamp y los datos de la cuenta: índice, monto, número de depósitos y retiros.

Formato de salida (según el log):
[timestamp] index:0;amount:47;deposits:1;withdrawals:0

## Método estático: displayAccountsInfos()

Lógica:

- Muestra la información global de todas las cuentas.
- Debe incluir el timestamp y los datos globales: número de cuentas, monto total, depósitos y retiros totales.

Formato de salida (según el log):
[timestamp] accounts:8;total:12442;deposits:8;withdrawals:6