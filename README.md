# Pong

Una implementación del clásico juego de Pong en C++ utilizando la biblioteca SDL (Simple DirectMedia Layer). Este proyecto fue concebido como un ejericio para ir aprendiendo los fundamentos de desarrollo de videojuegos, incluyendo la representación gráfica (_graphic rendering_), detección de colisión, movimiento basado en vector de dirección y manejo de eventos. 

![C++](https://img.shields.io/badge/C++-20+-blue?logo=cplusplus)
![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey)
![License](https://img.shields.io/badge/License-MIT-green)

## Características

* Clásico juego de Pong, jugador vs. máquina, con una IA muy simple: seguir la dirección de la pelota. 
* Puede detectar colisiones de la pelota con las paletas y los bordes superior e inferior. 
* Utiliza un vector para indicar la dirección en el movimiento, y usa un delta del tiempo para calcular la velocidad. 

## Requisitos

La aplicación utiliza Visual Studio Code con el compilador de Microsoft, Visual C++, así que es necesario instalar el conjunto de herramientas de Visual Studio. 

Asimismo, es necesario descargar la librería SDL2. 

Se proporciona un archivo CMakeLists.txt para poder compilar la aplicación utilizando la paleta de comandos de Visual Studio Code:

```
CMake: Configure
CMake: Build
```

## Documentación

Algunas clases importantes a tener en cuenta:

* GameApp - representa la aplicación, gestiona el _loop_ del juego y calcula los ticks (delta) por cada iteración. 
* Renderer - envoltorio alrededor de SDL_Renderer, para ocultar su complejidad, utiliza un puntero opaco. 
* Scene - representa una escena dentro de la pantalla, la cual contiene elementos que son renderizados. Reacciona a los eventos emitidos por componentes de la escena. 
* SceneItem - un elemento que será representado dentro de una escena, puede ser movido, cambiado de tamaño y dibujado en la pantalla. 
* Event - representa un evento ocurrido en el juego. 
* InputHandler - transforma las entradas del usuario (teclado, ventana, etc.) recibidas por SDL en eventos que son lanzados hacia el gestor de eventos.  
* EventBus - recibe eventos y los procesa a los receptores de eventos suscritos. 

## Pendientes

Todavía quedan pendientes por realizar, algunos cambios y características que tengo que añadir: 

* Restructurar las clases para utilizar métodos más modernos. En esta implementación uso punteros crudos en lugar de punteros inteligentes como ```std::shared_ptr```, probablemente no queramos eso en general. 
* Añadir un evento para identificar cuando la pelota traspasa los bordes laterales y llevar el conteo del marcador
* Establecer condiciones de victoria y derrota, y reaccionar ante ello. 
* Incluir una pantalla de inicio en lugar de lanzarte al juego directamente, y una vez que el juego concluye regresar a esta pantalla. 
* Incluir colores, quizás pintar la cancha de verde y la pelota de algún otro color, que cambie según el jugador que ha hecho contacto.
* Hacer que la pelota cambie de velocidad dependiendo de la sección de la paleta con la que es golpeada: las orillas aumentan velocidad, el centro la disminuye.
* Similarmente, que la pelota cambie el ángulo de reflexión dependiendo del tipo de golpe recibido en la paleta. 

Algún día.