CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic-errors -std=c++17 -O2

SRCS = main.cpp Aluno.cpp GerenciadorArquivo.cpp Benchmark.cpp
OBJS = $(SRCS:.cpp=.o)

GERADOR = arquivo.py

ifeq ($(OS),Windows_NT)
    TARGET = gerenciador_alunos.exe
    PYTHON = python
    RM = del /Q
else
    TARGET = gerenciador_alunos
    PYTHON = python3
    RM = rm -f
endif

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.cpp: Aluno.hpp GerenciadorArquivo.hpp Benchmark.hpp
Aluno.cpp: Aluno.hpp
GerenciadorArquivo.cpp: GerenciadorArquivo.hpp Aluno.hpp
Benchmark.cpp: Benchmark.hpp GerenciadorArquivo.hpp Aluno.hpp

run: all
	$(PYTHON) $(GERADOR) --cenarios
	./$(TARGET)

clean:
	-$(RM) *.o *.bin *.csv $(TARGET)