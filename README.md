(EN)
# REST API Using C++
A simple REST API with SQLITE utilizing Crow

## Purpose of this project

This is a Final Project for the Object Oriented Programming subject in the Computer Engineering career from Universidad Nacional de Mar del Plata.
It was decided by myself to apply the obtained knowledge to a C++ API as a fun, non-widespread idea.
Also, as I am being introduced to API designs externally from a professional point of view, I also took the idea of following the specific design pattern of Spring Boot (Controller - Service - Repository) to both have a better understanding of said architecture and take a look at C++'s capability to create a similar Framework if a more experienced and overall better programmer would put their hands in an idea as weird as this one.

## Used tools
My main libraries for this project were both [SQLite's wrapper for C/C++](https://www.sqlite.org/cintro.html) for Database connection and [Crow](https://crowcpp.org/master/) to manage the whole REST API.
To handle JSON conversion, I utilized [nlohmann's JSON for Modern C++](https://github.com/nlohmann/json)

## Endpoint list

**Authors:**\
GET All Authors: localhost:8090/authors \
GET Author by ID: localhost:8090/author/{id}

**Quotes:**\
GET All Quotes: localhost:8090/quotes (Query param: authorId to filter by authorId) \
GET Author by ID: localhost:8090/quote/{id}

## Desired additions / TODO list

- **Externalize database.** Even if implementing a SQLite connection was an interesting challenge, it wouldn't serve greater purpose in a REST API. It might be a better idea to use more powerful engines like PostgreSQL.
- **Better image handling.** All images are currently being saved as BASE64 strings in the 'Author' database. This results on really long strings as responses, and it would be a better idea to separate them to a different table.
- **Multi filtering.** There is currently a filter functionality in which you can query by a single filter. For example, in the GET All Quotes endpoint you can get quotes by Author ID if desired. I would like to add more complexity to this, so you would be able to filter by more than one field.
- **Pagination.**
- **Sorting.**
- **Toggleable logging.** Enable/disable logs depending on properties. Also log to files.
- **Authentication.**
