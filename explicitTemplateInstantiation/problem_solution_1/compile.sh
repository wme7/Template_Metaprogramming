g++ -c -Wall -Wextra -std=c++11 -pedantic-errors -o notmain.o notmain.cpp
g++ -c -Wall -Wextra -std=c++11 -pedantic-errors -o myTemplate.o myTemplate.cpp
g++ -c -Wall -Wextra -std=c++11 -pedantic-errors -o main.o main.cpp
g++    -Wall -Wextra -std=c++11 -pedantic-errors -o main.out notmain.o myTemplate.o main.o
echo notmain.o
nm -C -S notmain.o | grep MyTemplate
echo main.o
nm -C -S main.o | grep MyTemplate
echo myTemplate.o
nm -C -S myTemplate.o | grep MyTemplate