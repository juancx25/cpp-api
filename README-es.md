(ES)
# API REST usando C++
Una API REST simple en C++ usando Crow

## Propósito de este proyecto

Se trata de un Trabajo Final para la asignatura de Programación Orientada a Objectos en la carrera de Ingenería en Computación de la Universidad Nacional de Mar del Plata.
Decidí demostrar los conceptos y conocimientos obtenidos a través de una idea divertida y no tan popular en este lenguaje.
Además, al estar introduciéndome a diseños de APIs externamente desde un punto de vista profesional, también tomé la idea de seguir el patrón de diseño específico de Spring Boot (Controller - Service - Repository) para tener un mejor entendimiento de esa arquitectura, además de probar la capacidad de C++ de crear un Framework similar si un programador más experimentado y habilidoso tuviera una idea así de extraña.

## Herramientas utilizadas
Mis librerías principales utilizadas en este proyecto fueron [el wrapper de SQL para C/C++](https://www.sqlite.org/cintro.html) para las conexiones con la base de datos y [Crow](https://crowcpp.org/master/) para administrar la API REST en su totalidad.
Para soportar conversión a JSON, usé [JSON for Modern C++](https://github.com/nlohmann/json) de nlohmann.

## Lista de endpoints

**Autores:**\
GET Todos los Autores: localhost:8090/authors \
GET Autor por ID: localhost:8090/author/{id}

**Frases:**\
GET Todas las Frases: localhost:8090/quotes (Query param: authorId para filtrar por authorId) \
GET Frase por ID: localhost:8090/quote/{id}

## Adiciones deseadas / TODO list

- **Externalizar base de datos.**. Incluso si implementar una conexión a SQLite fue un desafío interesante, no sería demasiado útil en una API REST. Quizá sería una mejor idea usar motores más potentes como PostgreSQL.
- **Mejor manejo de imágenes**. Todas las imágenes se están guardando como un strings en BASE64 en la tabla 'Author'. Esto resulta en respuestas con strings larguísimos, y sería una mejor idea separar las imágenes en una tabla diferente.
- **Filtrado múltiple.** Ahora mismo podemos filtrar por un campo. Por ejemplo, en el endpoint GET Todas las Frases podemos traer Frases por ID de Autor si quisiéramos. Me gustaría agregar mayor complejidad, permitiendo filtrar por más de un campo.
- **Paginación.**
- **Ordenamiento.**
- **Logging toggleable.** Activar/desactivar logs dependiendo de las propiedades. También poder loguear a archivos.
- **Autenticación.**
