# Crear la librería 'persons' con persons.cc y persons.h
add_library(persons persons.cc persons.h)

# Indicar dónde buscar los includes de la librería
target_include_directories(persons PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# Crear el ejecutable persons-main
add_executable(persons-main persons-main.cc)

# Vincular el ejecutable con la librería
target_link_libraries(persons-main PUBLIC persons)
