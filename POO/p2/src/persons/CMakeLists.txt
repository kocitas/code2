add_library(persons persons.cc persons.h)
target_include_directories(persons PUBLIC ${CMAKE_CURRENT_LIST_DIR})
add_executable(persons-main persons-main.cc)
target_link_libraries(persons-main PUBLIC persons)