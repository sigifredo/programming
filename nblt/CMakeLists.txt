project( nblt )
cmake_minimum_required( VERSION 2.8.3 )

include_directories( include )

set(MAIN_SRCS
src/main.cpp
src/utils.cpp
src/utils_linux.cpp
src/Iteraction.cpp
src/Date.cpp
)

add_executable( main ${MAIN_SRCS} )
