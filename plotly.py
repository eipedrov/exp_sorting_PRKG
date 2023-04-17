import plotly.graph_objs as go
import plotly.offline as pyo

# Importar os dados do arquivo de log
with open('run_exp_data_merge.log', 'r') as f:
    dados = f.readlines()

x_data = []
y_data = []

# Extrair os dados relevantes do arquivo de log
for linha in dados:
    campos = linha.strip().split()
    x_data.append(campos[0])
    y_data.append(campos[1])

# Criar o trace e o data para o gráfico de linha
trace = go.Scatter(x=x_data, y=y_data, mode='lines')

data = [trace]

# Criar o layout para o gráfico
layout = go.Layout(title='Meu gráfico de linha do arquivo de log')

# Criar a figura que combina o data e o layout
fig = go.Figure(data=data, layout=layout)

# Exibir o gráfico
pyo.plot(fig)
