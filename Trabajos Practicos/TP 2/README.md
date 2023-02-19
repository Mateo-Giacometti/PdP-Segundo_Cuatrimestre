<h1 align="center">TP 2+3</h1>
<h2 align="center">Algoritmos genéticos</h2>

### Integrantes: Tiziano Levi Martin Bernal, Fausto Julián Pettinari, Ignacio Schuemer y Mateo Giacometti
### Profesores: Patricio Moreno y Emilio Oca

![UDESA LOGO](https://user-images.githubusercontent.com/101142182/177570532-6c64a0f6-4c89-4ffd-a214-95629d620ab9.png)

## Descripción del problema y la solución propuesta
El presente trabajo práctico tiene como finalidad tratar el famoso “Problema del viajante” mediante la implementación de un algoritmo genético. Para ello, se trabajará sobre datos de ciudades de las cuales solamente conocemos sus coordenadas. El objetivo será obtener la ruta (o una de las rutas) más corta posible, al pasar una vez por cada ciudad y volver al punto de donde se inició el viaje. Para resolución de este trabajo, utilizaremos el paradigma de programación orientada a objetos (POO) y la implementación del programa se llevará a cabo por medio del lenguaje de programación C++. Asimismo, para la representación gráfica de los resultados obtenidos utilizaremos el lenguaje Python e implementaremos diferentes librerías como Numpy, Matplotlib y Pandas. 

Nuestra solución del problema cuenta con una serie de pasos estrictamente definidos. En primer lugar, procedemos a extraer toda la información necesaria (nombre de la ciudad, coordenada en X y coordenada en Y) del archivo CSV que se nos provee en la consigna. Con estos datos obtenidos, precederemos a crear objetos de clase “City” para representar a todas las ciudades a lo largo del programa. Luego de su creación, la referencia a las mismas es almacenada dentro de un vector el cual simula el recorrido del viajante por estas ciudades. A este vector se lo reordenara varias veces con la finalidad de obtener una amplia variedad de formas de recorrer las ciudades. Por medio de estos vectores, procederemos a crear distintos objetos del tipo “Route”, los cuales son la representación de las diferentes rutas que pueden recorrer las ciudades. El conjunto de estas rutas representa una “generación” de las mismas, las cuales se almacenan en otro vector con el cual creamos objetos de la clase “RouteSet”, la cual se utiliza como representación de una “generación de rutas”. Sobre este objeto se aplicará todas las funcionalidades provistas por el “algoritmo genético”, el cual es una clase por sí misma denominada “GeneticAlg”.  A lo largo de cada generación que vaya pasando, el algoritmo genético se encargara de realizar las siguientes acciones: 

~Seleccionar las mejores rutas de cada generación, las cuales procederán a pasar a la siguiente.

~Aplicar un método de selección (en nuestro caso el Roulette Wheel Selection Method) para elegir a los padres de los individuos de la siguiente generación.

~Crear individuos a través de la combinación de genes de los individuos que cumplen el rol de padres.

~Aplicarles mutaciones a estos hijos. 

Todo este proceso se repetirá en numero de generaciones que se le solicite al programa o hasta que el umbral de variación entre generaciones sea insignificante. 

Finalmente, si el usuario así lo indica, si mostrará una representación grafica de la primera generación de rutas, de la mejor generación conseguida y de la evolución de la mejor ruta a lo largo de todas las generaciones producidas. 

## Análisis del problema, requerimientos y diseño inicial

<h3 align="left">Etapas de desarrollo</h3>

1. Análisis del problema y planificación 

Lo primero que se hizo a la hora de recibir el enunciado fue leerlo repetidas veces mientras se intentaba dilucidar qué era lo que se tenía que hacer para cumplir con la consigna solicitada. Luego de esto, se procedió a investigar y recopilar información sobre diferentes temáticas del trabajo practico de las cuales el equipo no poseía mucho conocimiento, como puede ser el caso de los algoritmos genéticos, métodos de selección, reproducción o mutación, manejo de archivos de formato CSV, etc.   

2. Definición de las clases 

Antes de comenzar con el proceso de escritura de código, se pensaron y confeccionaron las clases fundamentales que se incluirían en nuestro código, junto a sus posibles atributos y métodos. En esta etapa se definieron las clases “Point”, “City”, “Route” y ”RouteSet”. De igual forma se agregaron nuevas clases y métodos en posteriores etapas del trabajo. 

3. Extracción de datos y parseo de argumentos

En esta etapa, se elaboraron las funciones requeridas para extraer la información requerida del archivo CSV y controlar el parseo de argumentos por la línea de comandos. Posteriormente, se identificó que estas funciones podrían fungir como clases con obligaciones especificas para esta etapa del programa. Así, surgieron las clases “Reader” y “Parser”, encargadas de realizar las funciones anteriormente descriptas. Para estas dos clases, consideramos pertinente aplicarles el patrón de diseño “Singleton”.

4. Confección de las clases definidas previamente

Procedimos a plasmar en código aquello que pensamos en las etapas mas tempranas de desarrollo. Se elaboraron nuevos métodos y se modificaron atributos con respecto a lo planteado originalmente debido al seguimiento de requerimientos que antes no se contemplaron, como el almacenamiento de referencias a ciertos objetos o el acceso a valores de ciertos atributos de las clases (getters).

5. Creación del Algoritmo genético

En primer lugar, se intentó plantear el algoritmo genético como un grupo de funciones las cuales se encargarían de aplicar ordenadamente cada una de las etapas propias de este tipo de algoritmos. Pero a lo largo de esta etapa de desarrollo, se consideró conveniente transformar este conjunto de funciones en métodos de una clase que se encargaría de administrar todos los aspectos relacionados con el algoritmo genético. Desarrollos y pruebas a destacar de esta son la creación de la clase “Fitness” y las implementaciones de distintos tipos de métodos de selección (decantando finalmente por el método de la ruleta), crossover y mutación.

> Nota: La barra de progreso que se muestra en la terminal mientras se ejecuta el programa fue extraida del repositorio de gipert, a quien referenciamos en la bibliografia. 

6. Desarrollo de las funciones para graficar los resultados de ejecución desde Python

Luego de obtener una versión funcional y optima de nuestro programa, se prosiguió con la implementación de funciones en Python que recibieran los datos obtenidos del algoritmo y creara una representación grafica de estos resultados. Para conseguir esto, se elaboraron métodos para diferentes clases encargados de almacenar todos los datos necesarios dentro de archivos en formato CSV, los cueles el archivo .py se encargará de abrir, leer y extraer la información necesaria para graficar. Estas representaciones consisten en 3 gráficos: la representación de la primer rutas, la más optima obtenida (se consigue mediante la representación de las ciudades con puntos colocados en las coordenadas cartesianas correspondientes y la unión de las mismas mediante rectas) y la evolución de la distancia de la mejor ruta a lo largo de cada generación.

> Nota: Para correr el archivo grafic.py desde nuestro nuestros archivos cpp utilizamos la funcion "system()", la cual es inseguro y tiene problemas para funcionar con WSL. 

7. Organización y elaboración de tests  

A pesar de que se realizaron testeos a lo largo de cada etapa del desarrollo, el equipo se ha tomado el tiempo de ordenar y elaborar la mayor cantidad de pruebas posibles con la finalidad de poder certificar el correcto funcionamiento de cada aspecto del programa. 

8. Corrección de memory leak

Esta etapa consistió en el seguimiento de las fugas de memoria del programa y la elaboración de los destructores de todas las clases mediante las cuales se creaban los objetos necesarios para el funcionamiento del programa. 

9. Organización de archivos y revisiones generales

Se realizó una revisión final de todo el trabajo la cual consistió en la reducción en la longitud de ciertas líneas de código, la fragmentación de ciertas funciones en otras más cortas, la modificación de nombres de clases, métodos y atributos con la finalidad de respetar un estilo y la distribución del código en varios archivos siguiendo un criterio coherente y buscando facilitar el entendimiento del funcionamiento del sistema a terceros. 

<h3 align="left">Problemas que se generaron</h3>

~Problemas con memory leak: A lo largo de la realización de trabajo, se cometió el error de no prestarle su debida atención a las fujas de memoria que se estaban produciendo a lo largo de la ejecución del programa. Debido a esta mala práctica, tuvimos que dedicar mucho tiempo al seguimiento de estas fugas mediante la utilización de programa Valgrind y elaboración de los destructores de todas las clases. A pesar de todos los inconvenientes, finalmente logramos conseguir que nuestro código libere toda la memoria que solicita a lo largo de su ejecución. 

~Problemas con metodos del algoritmo genético: Por otro lado, en los primeros días de trabajo se el equipo tuvo ciertas confusiones a la hora de elaborar los métodos “selection”, “breed” y “crossover”. Uno de los aspectos que más retrasó el desarrollo del trabajo fue la falta de compresión sobre el funcionamiento de estas partes del algoritmo genético. En específico, las dificultades radicaron en la falta de inventiva a la hora de plasmar el método de selección en forma de código, verificar si era conveniente seleccionar las mejores rutas de cada generación y hacerlas pasar a la siguiente o encontrar una forma conveniente de cruzar rutas para crear nuevas. Luego de muchos intentos y pruebas, el equipo consiguió comprender que cómo debía realizar estas tareas y se logró conseguir buenos resultados al final del algoritmo. 


## Diagramas de clases, secuencias, funciones, etc

<h3 align="center">Diagrama de Clases</h4>

![Diagrama en blanco](https://user-images.githubusercontent.com/101135942/203109572-b0fad1a2-7c24-43d2-9be9-f0d4298de1c0.jpeg)

<h3 align="center">Diagrama de Secuencias</h4>

![Diagrama de secuencia A G jpeg](https://user-images.githubusercontent.com/101135942/203112274-20f39aa0-0ad8-4aeb-8d17-9f7d8530c0b2.jpg)


## Indicaciones para ejecutar correctamente el programa y las pruebas
Antes de comenzar la complilación del programa en custion, es importante descargar un numero de librerias de python necesarias, principalmente, para el manejo de archivos de texto y la generacion de los diferentes graficos que representaran los resultados obtenidos de la ejecución del programa. Para ello, se le facilita al usuario el archivo "requirements.txt", mediante el cual se podra instalar todas las librerias necesarias para el correcto funcionamiento del programa. La instalación se realiza con el siguiente comando.
```shell
pip install -r requirements.txt
```
Luego de la realización de este paso, se requiera la compilacion de los diferentes archivos .cpp del proyecto. Para esto, se recomienda compilar con el siguiente comando. 
```shell
g++ -g fileReader.cpp geneticAlg.cpp main.cpp parser.cpp pointCityClasses.cpp routeClasses.cpp RouteSetFitnessClasses.cpp status.cpp -o main
```
Para comenzar con la ejecución del programa, es necesario completar uan serie de argumentos los cuales configuran el comportamiento del algoritmo y la representacion de los resultados obtenidos. Estos argumentos a completar son los siguientes. 

-f, --file:   Ruta al archivo csv con las ciudades.

-v, --variation:   Tasa de cambio entre las soluciones de una generación de rutas y las anteriores.

-g, --generations:   Número de generaciones para el algoritmo genético.

-o, --output:   Formato de salida para las soluciones del algoritmo genético.

-p, --population:   Tamaño de la población para el algoritmo genético.

-e, --elite:   Individuos de élite para el algoritmo genético.

-m, --mutation:   Tasa de mutación para el algoritmo genético.

> Nota: Utilizando los comandos -h o --help en la terminal, se podrá obtener la misma informacion que se presentó anteriormente. Este argumento solo funciona si se coloca en soledad.

A continuación, se presenta un ejemplo de como podria realizarse una ejecucion del programa. 
```shell
./main --file csvTest.csv --variation 100 --generations 2000 --output graphic --elite 30 --mutation 0.3 --population 100
```

## Resultados de ejecuciones bajo condiciones normales e inesperadas de entrada

<h3 align="left">Condición normal de entrada - Se corre el programa sin solicitar que se grafiquen los resulados finales</h3>

![WhatsApp Image 2022-11-20 at 17 04 52](https://user-images.githubusercontent.com/101135942/202947865-2a6a4ba4-ae3d-4eff-9667-c2a285bc939d.jpg)

<h3 align="left">Condición normal de entrada - Se corre el programa solicitando que se grafiquen los resulados finales</h3>

![WhatsApp Image 2022-11-20 at 17 07 27](https://user-images.githubusercontent.com/101135942/202948805-71a0d5b9-10b2-47d0-9983-93d5cbfc1be9.jpg)

<h4 align="center">Grafico de la primera ruta</h4>

<p align="center">
  <img src="https://user-images.githubusercontent.com/101135942/202949127-d6461daa-504b-4739-bb26-7d8aeb026cfb.jpg" />
</p>

<h4 align="center">Grafico de la mejor ruta obtenida por el algoritmo genético</h4>

<p align="center">
  <img src="https://user-images.githubusercontent.com/101135942/202950987-ad632a8c-e769-4604-b2c1-c2719d00944e.jpg" />
</p>

<h4 align="center">Grafico de la evolucion de la mejor ruta de cada generación</h4>

<p align="center">
  <img src="https://user-images.githubusercontent.com/101135942/202951269-f48c9855-4cdf-4ef8-a9c1-4f2063f146aa.jpg" />
</p>

<h3 align="left">Condición normal de entrada - Se ejecuta el argumento "help"</h3>

<p align="center">
  <img src="https://user-images.githubusercontent.com/101135942/203126384-0103a69c-6abc-4d90-92fb-58dd3b03c541.jpg"
</p>

<h3 align="left">Condición inesperada de entrada - No se pasan la cantidad suficiente de argumentos</h3>

![WhatsApp Image 2022-11-20 at 17 31 01](https://user-images.githubusercontent.com/101135942/202951681-03e658c7-4e16-4bb5-b5cc-a04ae613a8bc.jpg)

<h3 align="left">Condición inesperada de entrada - Se solicita la creacion de lo graficos pasandole un valor incompatible al argumento</h3>

![WhatsApp Image 2022-11-20 at 17 21 40](https://user-images.githubusercontent.com/101135942/202951914-b0a3220f-665e-41e5-92d0-b16e1a88de01.jpg)

<h3 align="left">Condición inesperada de entrada - Se pasa un numero de individuos de elite superior a la cantidad de individuos que componen una generación</h3>

![WhatsApp Image 2022-11-20 at 17 23 08](https://user-images.githubusercontent.com/101135942/202952117-8a8a8342-4d3f-4a56-9e13-a9beace4183d.jpg)

> Nota: Si no se completa el argumento referido a la cantidad de individuos que componen una población, este asumirá el valor por defecto de 100 individuos.

## Bibliografía
GeeksforGeeks. (29 de septiembre de 2022). Genetic Algorithms. https://www.geeksforgeeks.org/genetic-algorithms/

Kie Codes. (13 de julio de 2020). Genetic Algorithms Explained By Example. YouTube. https://www.youtube.com/watch?v=uQj5UNhCPuo

AKP’s CS Lessons. (11 de junio de 2020). Roulette Wheel Selection Method| Genetic Algorithm | Roulette Wheel Selection for Genetic Algorithm. YouTube. https://www.youtube.com/watch?v=-B15r-8WX48

workshop-ga/workshop-ga at main · udesa-pp/workshop-ga. (s. f.). GitHub. https://github.com/udesa-pp/workshop-ga/tree/main/workshop-ga

GitHub - gipert/progressbar: A very simple progress bar for C++ loops. (s. f.). GitHub. https://github.com/gipert/progressbar

