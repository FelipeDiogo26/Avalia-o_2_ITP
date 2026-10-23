# Projeto em C — Boletim de uma Pequena Turma

1. Identificação

- Aluno: Felipe Gabriel Diogo Bernardo.
- Projeto escolhido: Opção 1 — Boletim de uma pequena turma


2. Descrição do projeto

O projeto consiste em um programa desenvolvido em linguagem C para cadastrar estudantes, registrar suas notas e calcular as médias (individuais e da turma).

O objetivo é facilitar a organização das notas e a identificação do desempenho dos estudantes de uma turma.

Funcionalidades implementadas:

- Solicitar a quantidade de estudantes, permitindo de 1 a 10.
- Cadastrar o nome de cada estudante.
- Registrar três notas por estudante, aceitando valores de 0 a 10.
- Armazenar as notas em uma matriz.
- Calcular a média individual de cada estudante.
- Utilizar alocação dinâmica de memória para armazenar as médias.
- Exibir um boletim com os nomes, as notas, as médias e a situação de cada estudante.
- Calcular a média geral da turma.
- Identificar todos os estudantes que obtiveram a maior média.
- Validar a quantidade de estudantes, os nomes e os valores das notas.

A situação de cada estudante é definida da seguinte forma:
- Média maior ou igual a 6,0: Atingiu a meta.
- Média menor que 6,0: Abaixo da meta.

Compilação e execução:

O programa foi desenvolvido em linguagem C e pode ser compilado utilizando o GCC ou executado em uma IDE, como o Dev-C++.

Compilação com GCC

No terminal, acesse a pasta em que está salvo o arquivo `boletim.c` e execute:

gcc boletim.c -o boletim

Execução:

No Windows, execute:

boletim.exe

Se estiver utilizando o terminal do Linux, execute:

./boletim

Também é possível abrir o arquivo `boletim.c` no Dev-C++, compilar e executar o programa pela própria IDE.

4. Testes

Teste 1 — Funcionamento normal

Entrada:

Quantidade de estudantes: 2
Nome do estudante 1: Ana
Nome do estudante 2: Bruno

Notas de Ana: 8, 7, 9
Notas de Bruno: 5, 6, 4

As notas devem ser digitadas individualmente, conforme solicitado pelo programa.

Resultado esperado:

| Estudante | Nota 1 | Nota 2 | Nota 3 | Média |    Situação    |
|    Ana    |  8,00  |  7,00  |  9,00  |  8,00 | Atingiu a meta |
|   Bruno   |  5,00  |  6,00  |  4,00  |  5,00 | Abaixo da meta |

Média geral da turma: 6,50

Estudante(s) com maior média: Ana.

Teste 2 — Entrada inválida e limite das notas

Situação: o usuário informa uma quantidade de estudantes fora do intervalo permitido ou digita uma nota inválida.

Exemplo de entrada:

Digite a quantidade de estudantes (1 a 10): 12

Resultado esperado:

Quantidade invalida! Tente novamente.

O programa deverá solicitar novamente a quantidade de estudantes até que seja informado um valor válido.

Outro teste possível é digitar uma nota acima de 10, como '11'. O programa deverá exibir uma mensagem de nota inválida e solicitar novamente a nota.

5. Vídeo de apresentação

Link do vídeo no YouTube: https://youtu.be/BKC2xNaKO7Y

O vídeo apresentará o funcionamento do programa, explicará suas principais funcionalidades e demonstrará a execução de testes.

6. Referências

- Material didático e orientações fornecidas na disciplina.
