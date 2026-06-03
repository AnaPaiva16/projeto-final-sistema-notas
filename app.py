from flask import Flask, render_template, request, redirect, url_for
import os

app = Flask(__name__)

# Rota principal: Lê o arquivo e exibe a página com o formulário e a lista
@app.route('/')
def index():
    dados_alunos = []
    # Verifica se o seu arquivo de relatório existe para ler os dados
    if os.path.exists('relatorio.txt'):
        with open('relatorio.txt', 'r', encoding='utf-8') as f:
            # Lê as linhas do arquivo ignorando linhas em branco
            dados_alunos = [linha.strip() for linha in f.readlines() if linha.strip()]
            
    return render_template('index.html', alunos=dados_alunos)

# Rota de envio: Recebe os dados do formulário da página e grava no arquivo TXT
@app.route('/salvar', methods=['POST'])
def salvar_nota():
    # Pega os dados digitados na tela pelo usuário
    nome = request.form.get('nome')
    n1 = float(request.form.get('nota1', 0))
    n2 = float(request.form.get('nota2', 0))
    n3 = float(request.form.get('nota3', 0))
    n4 = float(request.form.get('nota4', 0))
    
    # Calcula a média do aluno de forma automática
    media = (n1 + n2 + n3 + n4) / 4
    
    # Define a situação com base nas regras do seu sistema pedagógico
    if media >= 7:
        situacao = "Aprovado(a) 🎉"
    elif media >= 5:
        situacao = "Recuperação ⚠️"
    else:
        situacao = "Reprovado(a) 🚨"
    
    # Formata a string exatamente no padrão de relatório para salvar
    linha_aluno = f"Aluno: {nome} | Notas: [{n1}, {n2}, {n3}, {n4}] | Média: {media:.2f} | Situação: {situacao}\n"
    
    # Abre o arquivo em modo 'a' (append) para adicionar o novo registro no final
    with open('relatorio.txt', 'a', encoding='utf-8') as f:
        f.write(linha_aluno)
        
    # Redireciona o navegador de volta para a página inicial para atualizar a tabela
    return redirect(url_for('index'))

if __name__ == '__main__':
    # Inicializa o servidor web local na porta padrão (5000)
    app.run(debug=True)