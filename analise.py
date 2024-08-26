import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Dados para análise
entradas = np.array([1000, 5000, 10000, 15000, 20000])
tempos_dfs = np.array([0.0005, 0.1385, 0.5364, 1.2289, 2.1474])  # Tempos para DFS
tempos_a_star = np.array([0.0000, 0.0001, 0.0002, 0.0003, 0.0004])  # Tempos para A*

# Modelos para ajuste
def modelo_linear(x, a, b):
    return a * x + b

def modelo_quadratico(x, a, b, c):
    return a * x**2 + b * x + c

# Ajustar os modelos aos dados
params_dfs_linear, _ = curve_fit(modelo_linear, entradas, tempos_dfs)
params_dfs_quadratico, _ = curve_fit(modelo_quadratico, entradas, tempos_dfs)
params_a_star_linear, _ = curve_fit(modelo_linear, entradas, tempos_a_star)
params_a_star_quadratico, _ = curve_fit(modelo_quadratico, entradas, tempos_a_star)

# Gerar valores ajustados para o gráfico
entradas_fit = np.linspace(min(entradas), max(entradas), 100)
tempos_dfs_linear_fit = modelo_linear(entradas_fit, *params_dfs_linear)
tempos_dfs_quadratico_fit = modelo_quadratico(entradas_fit, *params_dfs_quadratico)
tempos_a_star_linear_fit = modelo_linear(entradas_fit, *params_a_star_linear)
tempos_a_star_quadratico_fit = modelo_quadratico(entradas_fit, *params_a_star_quadratico)

# Plotar os dados e os ajustes
plt.figure(figsize=(12, 8))

# DFS
plt.subplot(1, 2, 1)
plt.plot(entradas, tempos_dfs, 'o', label='Dados Reais DFS')
plt.plot(entradas_fit, tempos_dfs_linear_fit, '-', label='Ajuste Linear DFS', color='blue')
plt.plot(entradas_fit, tempos_dfs_quadratico_fit, '--', label='Ajuste Quadrático DFS', color='green')
plt.xlabel('Número de Vértices')
plt.ylabel('Tempo de Execução (segundos)')
plt.title('DFS: Ajuste de Modelos')
plt.legend()
plt.grid(True)

# A*
plt.subplot(1, 2, 2)
plt.plot(entradas, tempos_a_star, 'o', label='Dados Reais A*')
plt.plot(entradas_fit, tempos_a_star_linear_fit, '-', label='Ajuste Linear A*', color='red')
plt.plot(entradas_fit, tempos_a_star_quadratico_fit, '--', label='Ajuste Quadrático A*', color='orange')
plt.xlabel('Número de Vértices')
plt.ylabel('Tempo de Execução (segundos)')
plt.title('A*: Ajuste de Modelos')
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()

