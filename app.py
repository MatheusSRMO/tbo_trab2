import sys
import math
import random


if __name__ == "__main__":
    N = int(sys.argv[1]) # Numero de vertices

    # Calcula a quantidade de arestas
    # Qnt de arestas segue {3} U {9}^k U {2} onde k = log10(N) - 1
    # (Apenas para seguir o padrão dos arquivos de entrada do professor)
    """
        Para N = 10 -> k = 0
        Para N = 100 -> k = 1
        Para N = 1000 -> k = 2
        Para N = 10000 -> k = 3
        Formula: k = log10(N) - 1
    """

    k = math.floor(math.log10(N)) - 1
    num_arestas = int("3" + str(9)*k + "2")
    print(N, num_arestas)

    size_s = int(sys.argv[2]) # Tamanho do conjunto S
    size_c = int(sys.argv[3]) # Tamanho do conjunto C
    size_m = int(sys.argv[4]) # Tamanho do conjunto M

    # Armazena os vertices que já foram sorteados, para não sortear repetidos
    vertices = []

    # Sorteia os vertices de S
    for i in range(size_s):
        v = random.randint(0, N-1)
        while v in vertices:
            v = random.randint(0, N-1)
        vertices.append(v)

    # Sorteia os vertices de C
    for i in range(size_c):
        v = random.randint(0, N-1)
        while v in vertices:
            v = random.randint(0, N-1)
        vertices.append(v)

    # Sorteia os vertices de M
    for i in range(size_m):
        v = random.randint(0, N-1)
        while v in vertices:
            v = random.randint(0, N-1)
        vertices.append(v)

    edges = []
    # Sorteia as arestas
    for i in range(num_arestas):
        v1 = random.randint(0, N-1)
        v2 = random.randint(0, N-1)
        while v1 == v2:
            v2 = random.randint(0, N-1)
        w = random.random()
        edges.append((v1, v2, w))

    # Nome do arquivo de saida, seguindo o padrão do professor
    file_name = f"N{N}_S{size_s}_C{size_c}_M{size_m}.txt"

    # Escreve o arquivo
    with open(file_name, "w") as f:
        f.write(f"{N} {num_arestas}\n")
        f.write(f"{size_s} {size_c} {size_m}\n")
        for v in vertices:
            f.write(f"{v}\n")
        for edge in edges:
            f.write(f"{edge[0]} {edge[1]} {edge[2]}\n")
