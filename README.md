# Jasson_Marcos_ws_AA_RR_2024
# Seminário: Análise de Algoritmos de Busca

Este repositório contém o código e os resultados para a análise comparativa de dois algoritmos de busca: Busca em Profundidade (DFS) e A*. O objetivo é comparar o tempo de execução desses algoritmos em diferentes tamanhos de grafo e analisar a tendência de comportamento assintótico.

## Conteúdo do Repositório

1. **[Código C para DFS](dfs.c)**: Implementação do algoritmo de Busca em Profundidade e medição do tempo de execução.
2. **[Código C para A\*](a_star.c)**: Implementação do algoritmo de Busca A* e medição do tempo de execução.
3. **[Código Python para Análise](analise.py)**: Script para gerar gráficos comparando os tempos de execução dos algoritmos e ajustar modelos de tendência.
4. **Resultados**: Tempos de execução e gráficos de análise.

## Análise da Função do Algoritmo DFS e Busca A*

### DFS
O algoritmo de Busca em Profundidade (DFS) é um método fundamental para explorar grafos. Sua função de custo está relacionada ao tempo de execução do algoritmo, considerando o número de vértices e arestas no grafo. A seguir está a análise detalhada do custo:

### 1. Inicialização dos Vértices
O DFS inicia com a inicialização de todos os vértices do grafo, marcando-os como brancos e definindo seus predecessores como NIL.
- **Custo:** \(O(V)\), onde \(V\) é o número de vértices.

### 2. Visitação de Vizinhos
O algoritmo percorre todos os vértices e, para cada vértice não visitado, chama a função `DFS-VISIT`. Durante essa visitação, o algoritmo examina todas as arestas incidentes a cada vértice.
- **Custo:** O laço que percorre as arestas adjacentes de um vértice é executado \(O(E)\), onde \(E\) é o número de arestas.

### 3. Tempo Total de Execução
O algoritmo DFS garante que cada vértice é visitado exatamente uma vez e cada aresta é examinada uma vez. Isso ocorre porque, ao visitar um vértice, ele é marcado como preto e não é visitado novamente.
- **Custo Total (Função de Custo do DFS):** \(O(V + E)\)

### Busca A*
No algoritmo A* (A-estrela), utilizado para encontrar o caminho mais curto em grafos ou mapas, a complexidade de tempo é frequentemente descrita em termos de b e d, onde:

- b é o fator de ramificação médio do grafo ou espaço de busca. Representa o número médio de filhos (ou sucessores) que cada nó ou estado pode ter.
- d é a profundidade da solução ou a distância do nó inicial até o nó objetivo na árvore de busca.

### Complexidade do A*

A complexidade de tempo do A* é geralmente expressa como: O(b^d)

## Instruções para Executar

### Compilar e Executar o Código C

1. **DFS**:
   - Navegue até o diretório contendo o código `dfs.c`.
   - Compile o código usando o comando:
     ```bash
     gcc dfs.c -o dfs
     ```
   - Execute o programa:
     ```bash
     ./dfs
     ```

2. **A\***:
   - Navegue até o diretório contendo o código `a_star.c`.
   - Compile o código usando o comando:
     ```bash
     gcc a_star.c -o a_star
     ```
   - Execute o programa:
     ```bash
     ./a_star
     ```

### Analisar os Dados com Python

1. **Dependências**:
   - Certifique-se de ter o `matplotlib` e `scipy` instalados. Instale-os usando:
     ```bash
     pip install matplotlib scipy
     ```

2. **Executar o Script de Análise**:
   - Navegue até o diretório contendo o script `analise.py`.
   - Execute o script:
     ```bash
     python analise.py
     ```

## Resultados

Os resultados da análise incluem gráficos comparando os tempos de execução dos algoritmos DFS e A* para diferentes tamanhos de grafo. O ajuste dos modelos é realizado para identificar a tendência assintótica de cada algoritmo.
O Gráfico pode ser visualizado [aqui](Grafico.png)

## Análise da Tendência de Comportamento Assintótico

A análise foi realizada ajustando modelos lineares e quadráticos aos dados de tempo de execução. Gráficos com os ajustes e análise da tendência assintótica estão disponíveis no script de análise Python.

## Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para detalhes.

