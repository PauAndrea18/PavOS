# PavOS <br>*Sistema Operativo basado en el kernel de Linux*

## Especificaciones mínimas
- Procesador: 1 GHz o superior
- Memoria RAM: 512 MB o más
- Espacio en disco: 10 GB o más 

## Descripción
PavOS es un sistema operativo ligero basado en el kernel de Linux, diseñado para funcionar en entornos de máquinas virtuales. Este sistema operativo se ejecuta exclusivamente por consola, ofreciendo un enfoque minimalista y eficiente.

## Instrucciones de uso
1. *Descarga del ISO:* Descarga el archivo ISO de PavOS desde [enlace de descarga].

2. *Creación de una nueva máquina virtual:*
   - Abre VM VirtualBox y haz clic en el botón "Nueva" en la parte superior.
   - Ingresa un nombre para tu máquina virtual (por ejemplo, "PavOS") y selecciona el tipo de sistema operativo como "Linux".
   - Elige la versión adecuada de Linux en la lista desplegable.
   - Selecciona la cantidad de memoria RAM que deseas asignar a la máquina virtual.
   - Crea un disco duro virtual con un tamaño mínimo de 10 GB y elige el tipo adecuado según tus preferencias y recursos disponibles.

3. *Configuración de la máquina virtual:*
   - En la configuración de la máquina virtual, en la sección "Almacenamiento", selecciona el controlador de SATA y haz clic en el icono del disco duro.
   - Selecciona "Elegir un archivo de disco óptico virtual" y busca el archivo ISO de PavOS que descargaste anteriormente.

4. *Inicio de la máquina virtual:*
   - Selecciona la máquina virtual en la lista y haz clic en "Iniciar" en la parte superior.
   - La máquina virtual arrancará desde el ISO de PavOS y comenzará el proceso de instalación.

5. *Instalación de PavOS:*
   - Sigue las instrucciones en pantalla para instalar PavOS en el disco duro virtual creado anteriormente.
   - Durante la instalación, se te pedirá que elijas el idioma, la distribución del teclado y otros ajustes.
   - Una vez completada la instalación, reinicia la máquina virtual.

6. *Inicio de PavOS:*
   - Una vez reiniciada la máquina virtual, PavOS debería iniciarse automáticamente.
   - Ingresa las credenciales de inicio de sesión (por defecto, usuario: root, contraseña: PavOS) para acceder al sistema operativo.

## Notas de la versión
- Versión: 1.0
- Novedades: Esta versión inicial de PavOS incluye las herramientas básicas de línea de comandos para un funcionamiento eficiente en entornos de máquinas virtuales.

## Contacto y soporte
Para obtener ayuda o informar de problemas, contacta con nuestro equipo de soporte en pavos.contact@gmail.com.


# PavOS

PavOS es un sistema operativo que incluye dos aplicaciones principales:

## Aplicaciones Incluidas

### CalculadoraTotazoPro
CalculadoraTotazoPro es una calculadora avanzada capaz de realizar las siguientes operaciones:

- Suma
- Resta
- Multiplicación
- División
- Porcentajes

La calculadora tiene en cuenta la jerarquía de operadores, asegurando que las operaciones se realicen en el orden correcto.

### MimiBlocks
MimiBlocks es un editor de archivos txt con las siguientes características:

- Permite el desplazamiento en el texto.
- Permite la edición del texto.
- Para guardar los cambios realizados, presione la tecla `Esc`.
- Para cancelar la edición, presione `Ctrl+C`.
- Recibe como parámetro el nombre del archivo a editar.
  - Si el archivo existe, permite editar su contenido.
  - Si el archivo no existe, lo crea para su edición.

## Requisitos del Sistema

Para ejecutar PavOS y sus aplicaciones incluidas, se recomienda contar con las siguientes especificaciones mínimas:

- Espacio en disco: 10GB

## Desarrollo de CalculadoraTotazoPro

CalculadoraTotazoPro está implementada en el lenguaje de programación C y consta de varios métodos esenciales para su funcionamiento. El método `obtenerSigToken` se encarga de leer la siguiente porción de la expresión matemática ingresada por el usuario. Esta porción puede ser un número o un operador. Para números, maneja tanto los decimales, convirtiendo comas a puntos, como los porcentajes, dividiendo el número entre 100 si se encuentra un símbolo de porcentaje. Para operadores, identifica el carácter correspondiente. Este método se asegura de ignorar los espacios en blanco y finaliza cuando alcanza el final de la línea o de la cadena.

El método `evaluarExpresion` es el núcleo de la calculadora, encargado de evaluar la expresión matemática completa. Utiliza una pila para manejar la jerarquía de operadores, almacenando temporalmente números y operadores hasta que se pueda resolver la expresión correctamente. Comienza verificando que la expresión inicie con un número válido, luego procede a evaluar operadores y operandos en secuencia, realizando las operaciones aritméticas básicas (suma, resta, multiplicación, división) de acuerdo con la precedencia de operadores. Si encuentra errores como operadores consecutivos o división por cero, muestra un mensaje de error y termina la ejecución.

El método `limpiarBuffer` se utiliza para preparar la entrada del usuario, asegurándose de que no queden caracteres residuales en el buffer de entrada estándar (stdin) que puedan interferir con la lectura de una nueva expresión.

Finalmente, el método `main` es la función principal que controla el flujo de la calculadora. Al iniciar, muestra un mensaje de bienvenida y entra en un bucle infinito donde espera a que el usuario presione Enter para ingresar una operación. Luego lee la expresión matemática ingresada, la evalúa utilizando `evaluarExpresion` y muestra el resultado. Para salir de la calculadora, el usuario debe presionar Ctrl+C, lo que termina la ejecución del programa.

### Compilación y Ejecución

Para compilar CalculadoraTotazoPro, ejecute el siguiente comando:

```bash
gcc -o calculadoratotazopro calculadoratotazopro.c -lpthread
```
