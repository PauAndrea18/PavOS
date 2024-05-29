# PavOS <br>*Sistema Operativo basado en el kernel de Linux*

## Especificaciones mínimas
- Procesador: 1 GHz o superior
- Memoria RAM: 512 MB o más
- Espacio en disco: 10 GB o más 

## Descripción
PavOS es un sistema operativo ligero basado en el kernel de Linux, diseñado para funcionar en entornos de máquinas virtuales. Este sistema operativo se ejecuta exclusivamente por consola, ofreciendo un enfoque minimalista y eficiente. PavOS incluye soporte completo para drivers de USB, lo que permite la conexión y el uso de dispositivos USB de manera fluida y sin complicaciones. Además, PavOS permite la conexión remota mediante el protocolo SSH (Secure Shell), facilitando la administración y el acceso seguro desde cualquier lugar. 

## Instrucciones de uso

### Paso 1: Descargar e Instalar VirtualBox
1. *Descargar VirtualBox:* Ve al sitio oficial de VirtualBox (https://www.virtualbox.org/wiki/Downloads) y descarga la versión correspondiente a tu sistema operativo (Windows, macOS, Linux).
2. *Instalar VirtualBox:* Ejecuta el archivo descargado y sigue las instrucciones del instalador para completar la instalación.

### Paso 2: Importar el Archivo .ova
1. *Descargar el archivo .ova de PavOS:* Descarga el archivo .ova en el siguiente enlace https://drive.google.com/file/d/1cqixXu4HziuommELByFbt1l8bcJ-dNbA/view?usp=drive_link
2. *Abrir VirtualBox:* Inicia VirtualBox desde el menú de inicio (Windows) o desde tu carpeta de aplicaciones (macOS, Linux).
3. *Acceder al Asistente de Importación:* Haz clic en Archivo en la barra de menú y selecciona Importar servicio virtualizado...
4. *Seleccionar el Archivo .ova:*
   - En la ventana del Asistente de Importación, haz clic en el icono de la carpeta para abrir el explorador de archivos.
   - Navega hasta la ubicación del archivo .ova en tu sistema, selecciona el archivo y haz clic en Abrir.
5. *Iniciar la Importación:*
   - Después de seleccionar el archivo .ova, haz clic en Siguiente.
   - Revisa la configuración de la máquina virtual que se mostrará. Puedes ajustar los parámetros según tus necesidades.
   - Haz clic en Importar para comenzar el proceso de importación. Este proceso puede tardar varios minutos, dependiendo del tamaño del archivo .ova y las especificaciones de tu computadora.

### Paso 3: Configuración del Adaptador de red
   - Selecciona la maquina virtual en el panel izquierdo de VirtualBox.
   - Haz click en Configuración en el panel derecho en la parte superior.
   - Abre la configuración de Red en la ventana emergente.
   - En la pestaña del Adaptador 1, verifica que la opción "Habilitar adaptador de red" este activada, en el subtitulo "Conectado a" selecciona NAT y haz click en Aceptar.

### Paso 4: Iniciar la Máquina Virtual
1. *Seleccionar la Máquina Virtual:* En el panel izquierdo de VirtualBox, selecciona la máquina virtual importada.
2. *Iniciar la Máquina Virtual:* Haz clic en Iniciar en la parte superior del panel para arrancar la máquina virtual.
3. Sigue las instrucciones del sistema operativo PavOS e inicia sesión con las siguientes credenciales
```bash
`PavOS login:` root
`Password:` PavOS

```
       
## Paso a paso del Sistema Operativo
El sistema operativo PavOS fue creado siguiendo cada uno de los pasos que se encuentran en la guía que brinda el libro Linux From Scratch, en este caso se uso la versión 12.1, en el siguiente link se encuentra de forma online https://www.linuxfromscratch.org/lfs/view/12.1/

## Notas de la versión
- Versión: 1.0
- Novedades: Esta versión inicial de PavOS incluye las herramientas básicas de línea de comandos para un funcionamiento eficiente en entornos de máquinas virtuales.

## Contacto y soporte
Para obtener ayuda o informar de problemas, contacta con nuestro equipo de soporte en pavos.contact@gmail.com.

<br>

# *Aplicaciones Incluidas*

Para PavOS se han desarrollado dos aplicaciones destacadas que se pueden ejecutar directamente desde la consola, aportando diferentes funcionalidades y mejorando la experiencia de usuario al utilizar este sistema operativo. Estas aplicaciones han sido diseñadas con el din de ofrecer herramientas esenciales que aumentan la productividad y eficiencia de PavOS. Gracias a su ejecución por consola, estas aplicaciones aseguran un rendimiento rápido y sin distracciones, alineándose con el enfoque minimalista y eficiente de PavOS.

## CalculadoraTotazoPro
CalculadoraTotazoPro es una calculadora capaz de realizar las siguientes operaciones:

- Suma
- Resta
- Multiplicación
- División
- Porcentajes

La calculadora tiene en cuenta la jerarquía de operadores, asegurando que las operaciones se realicen en el orden correcto.

### Desarrollo de CalculadoraTotazoPro
CalculadoraTotazoPro está implementada en el lenguaje de programación C y consta de varios métodos esenciales para su funcionamiento: 

- **Método `obtenerSigToken`:** se encarga de leer la siguiente porción de la expresión matemática ingresada por el usuario. Esta porción puede ser un número o un operador. Para números, maneja tanto los decimales, convirtiendo comas a puntos, como los porcentajes, dividiendo el número entre 100 si se encuentra un símbolo de porcentaje. Para operadores, identifica el carácter correspondiente. Este método se asegura de ignorar los espacios en blanco y finaliza cuando alcanza el final de la línea o de la cadena.

- **Método `evaluarExpresion`:** es el núcleo de la calculadora, encargado de evaluar la expresión matemática completa. Utiliza una pila para manejar la jerarquía de operadores, almacenando temporalmente números y operadores hasta que se pueda resolver la expresión correctamente. Comienza verificando que la expresión inicie con un número válido, luego procede a evaluar operadores y operandos en secuencia, realizando las operaciones aritméticas básicas (suma, resta, multiplicación, división) de acuerdo con la precedencia de operadores. Si encuentra errores como operadores consecutivos o división por cero, muestra un mensaje de error y termina la ejecución.

- **Método `limpiarBuffer`:** se utiliza para preparar la entrada del usuario, asegurándose de que no queden caracteres residuales en el buffer de entrada estándar (stdin) que puedan interferir con la lectura de una nueva expresión.

- **Método `main`:** es la función principal que controla el flujo de la calculadora. Al iniciar, muestra un mensaje de bienvenida y entra en un bucle infinito donde espera a que el usuario presione Enter para ingresar una operación. Luego lee la expresión matemática ingresada, la evalúa utilizando `evaluarExpresion` y muestra el resultado. Para salir de la calculadora, el usuario debe presionar Ctrl+C, lo que termina la ejecución del programa.

### Compilación y Ejecución

Para compilar CalculadoraTotazoPro, ejecute el siguiente comando:

```bash
gcc -o calculadoratotazopro calculadoratotazopro.c
```

Una vez compilado, mueva el archivo ejecutable al directorio /usr/bin para poder ejecutarlo como un comando del sistema operativo:

```bash
sudo mv calculadoratotazopro /usr/bin/
```

Para ejecutar la calculadora:

```bash
calculadoratotazopro
```

Presione Enter para continuar con la ejecución y digite la operación que desea realizar.
Para salir de la calculadora, presione `Ctrl+C`.


## MimiBlocks
MimiBlocks es un editor de archivos txt con las siguientes características:

- Permite el desplazamiento en el texto.
- Permite la edición del texto.
- Para guardar los cambios realizados, presione la tecla `Esc`.
- Para cancelar la edición, presione `Ctrl+C`.
- Recibe como parámetro el nombre del archivo a editar.
  - Si el archivo existe, permite editar su contenido.
  - Si el archivo no existe, lo crea para su edición.

### Desarrollo de MimiBlocks
MimiBlocks está implementado en el lenguaje de programación C utilizando la biblioteca `ncurses` para la manipulación de la interfaz de usuario en la terminal y consta de varios métodos esenciales para su funcionamiento:  

- **Método `save_text`:** guarda el contenido del archivo editado. Recorre la lista de nodos que representan el contenido del archivo y escribe cada carácter en el archivo especificado. El método read_text lee el contenido de un archivo txt y lo almacena en una lista doblemente enlazada de nodos, donde cada nodo representa un carácter del archivo junto con sus coordenadas en la pantalla. Si el archivo no existe, lo crea.

- **Método `encontrar_node`:** busca un nodo específico en la lista enlazada basado en las coordenadas y y x. Dependiendo del valor de opc, busca hacia adelante o hacia atrás en la lista. modificar_x y modificar_y ajustan las coordenadas x e y de los nodos en la lista cuando se insertan o eliminan caracteres, asegurando que la representación del texto en pantalla sea correcta.

- **Método `main`:** es la función principal que inicializa el entorno ncurses y controla el flujo del editor de texto. Lee el archivo inicial en una lista de nodos, muestra el contenido en la pantalla y permite al usuario navegar y modificar el texto. El bucle principal captura las teclas de entrada y realiza las acciones correspondientes, como moverse por el texto, insertar caracteres, y guardar o cancelar los cambios. Cuando el usuario presiona Esc, el texto se guarda y el programa termina. Si presiona Ctrl+C, el programa termina sin guardar los cambios.

### Compilación y Ejecución
Para compilar MimiBlocks, ejecute el siguiente comando:

```bash
gcc -o mimiblocks mimiblocks.c -lncurses
```

Una vez compilado, mueva el archivo ejecutable al directorio /usr/bin para poder ejecutarlo como un comando del sistema operativo:

```bash
sudo mv mimiblocks /usr/bin/
```

Para ejecutar el editor, recuerde que debe tener como parametro el nombre del archivo txt que se desea editar:

```bash
mimiblocks <nombre de archivo>.txt
```

Para salir del editor y guardar los cambios, presione Esc. <br>
Para salir sin guardar, presione Ctrl+C.

*¡Disfruta de la funcionalidad de PavOS con CalculadoraTotazoPro y MimiBlocks!*
