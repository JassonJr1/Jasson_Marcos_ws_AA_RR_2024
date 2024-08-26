# Jasson_Marcos_ws_AA_RR_2024
# Seminário: Análise de Algoritmos de Busca

Este repositório contém o código e os resultados para a análise comparativa de dois algoritmos de busca: Busca em Profundidade (DFS) e A*. O objetivo é comparar o tempo de execução desses algoritmos em diferentes tamanhos de grafo e analisar a tendência de comportamento assintótico.

## Conteúdo do Repositório

1. **Código C para DFS**: Implementação do algoritmo de Busca em Profundidade e medição do tempo de execução.
2. **Código C para A\***: Implementação do algoritmo de Busca A* e medição do tempo de execução.
3. **Código Python para Análise**: Script para gerar gráficos comparando os tempos de execução dos algoritmos e ajustar modelos de tendência.
4. **Resultados**: Tempos de execução e gráficos de análise.

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

