CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic-errors -std=c++17 -O2
TARGET = gerenciador_alunos

SRCS = main.cpp Aluno.cpp GerenciadorArquivo.cpp Benchmark.cpp
OBJS = $(SRCS:.cpp=.o)

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
	./$(TARGET)

clean:
	rm -f *.o *.bin $(TARGET)