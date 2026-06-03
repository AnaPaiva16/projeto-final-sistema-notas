# <p align="center"> ✨<code>SISTEMA DE NOTAS v4.1</code> ✨</p>
<p align="center">
  <img src="https://img.shields.io/badge/🌸%20Estilo-Soft%20Pink%20%26%20Purple-ff69b4?style=for-the-badge" alt="Estilo">
  <img src="https://img.shields.io/badge/🔮%20Versão-4.1%20Deluxe-9370DB?style=for-the-badge" alt="Versão">
  <img src="https://img.shields.io/badge/💻%20Ambiente-Windows%20Only-8A2BE2?style=for-the-badge" alt="Ambiente">
</p>

---

## <p align="center">🎀 Paleta de Cores do Projeto 🎀</p>
<p align="center">
  <img src="https://via.placeholder.com/15/FF69B4/000000?text=+" alt="Pink"> <code>#FF69B4 (Pink)</code> &nbsp;&nbsp;
  <img src="https://via.placeholder.com/15/9370DB/000000?text=+" alt="Purple"> <code>#9370DB (Purple)</code> &nbsp;&nbsp;
  <img src="https://via.placeholder.com/15/E6E6FA/000000?text=+" alt="Lilac"> <code>#E6E6FA (Lilac)</code>
</p>

> 💜 *“Transformando linhas de código brutas em uma experiência acadêmica mágica, organizada e cheia de cor!”*

Este sistema foi desenvolvido com muito carinho e dedicação durante o curso **Técnico em Desenvolvimento de Sistemas** no **SENAI-SP**. O projeto base foi completamente transformado através de **modificações autorais criativas**, focadas em design de interface de terminal, inteligência de dados (Business Intelligence), relatórios focados em decisões pedagógicas e blindagem total contra erros de digitação.

---

## 🦄 Linha do Tempo de Desenvolvimento (Commits)

Aqui está a evolução detalhada do projeto, destacando o que era a estrutura base e onde eu brilhei com as minhas **Adições Criativas Autorais** em cada etapa:

| 📌 Commit | 📝 O que o projeto pedia | 🌸 Meu Toque Autoral Especial |
| :--- | :--- | :--- |
| **Commit 1: Leitura de Alunos** | Menu inicial, fluxo do relatório, menu "Sobre o Sistema" e repetição para leitura dos nomes (`nomes[20]`). | Validação robusta com `do-while` e `nomes[i].empty()` para impedir nomes em branco ao apertar "Enter" por engano. |
| **Commit 2: Notas e Médias** | Matriz de notas `notas[20][5]`, cálculo das médias e inserção de data/hora no arquivo físico via `<ctime>`. | Lista fixa de matérias estruturada (`listaMaterias[4]`) com menu interativo e vetor acumulador `somaDisciplinas[5]` para estatísticas da turma. |
| **Commit 3: Anti-Quebra** | *Não existia no escopo base.* | **Blindagem total!** Uso estratégico de `cin.fail()`, `cin.clear()` e `cin.ignore()`. Se digitarem uma letra em campos numéricos, o sistema limpa o erro e pede o dado certo de novo, evitando travamentos. |
| **Commit 4: Interface e Relatório** | Exibição dos resultados e gravação dos dados no arquivo físico `relatorio.txt` usando `<fstream>`. | **Design Estilizado:** Cores no terminal via `<windows.h>`, mensagens afetivas originais e **Métricas Avançadas** (Cálculo automático do Aluno Destaque e Disciplina Crítica). |
| **Commit 5: Histórico Salvo** | Integração com `ifstream` para ler o arquivo diretamente no terminal através da Opção 2. | Formatação perfeita na tela resgatando o design visual do arquivo gravado e criação automática de um sistema de logs (`acessos.txt`). |
| **Commit 6: Monitoria Técnica** | *Não existia no escopo base.* | **Filtro de Recuperação (Opção 5):** Criação de um gerador de relatórios focado em alunos com média entre 5.0 e 6.9, isolando os dados em `recuperacao.txt` para ações pedagógicas imediatas. |
| **Commit 7: Sistema de Arquivos** | *Não existia no escopo base.* | **Customização Dinâmica:** Permite que o usuário digite o nome que quiser para os arquivos salvos. Conta com auto-complete automático para extensões `.txt` e vinculação inteligente do leitor (Opção 2) com o último arquivo criado. |

---

## 🦄 Recursos Exclusivos da Versão 4.1 Deluxe

> ✨ **Animações de Carregamento:** Funções baseadas em `Sleep()` que simulam processamento real de banco de dados no console.
> 
> 📊 **Data Viz no Terminal:** Gráficos de barras horizontais gerados dinamicamente com caracteres de preenchimento (`█` e `░`) baseados na média final do aluno.
> 
> 🔍 **Auditoria Automatizada:** Criação do arquivo de logs `acessos.txt` que registra o momento exato de cada leitura do relatório.
> 
> 🚨 **Filtro de Risco Crítico:** Exportação isolada de alunos com média menor que 5.0 diretamente para o arquivo `reprovados.txt` (Opcional C).
> 
> ⚠️ **Foco em Recuperação:** Geração sob demanda do arquivo `recuperacao.txt` (Opção 5) para listar alunos que estão na zona de atenção e precisam de reforço.
> 
> 📂 **Arquivos Customizados & Inteligentes:** Liberdade para nomear os relatórios na hora de salvar. O sistema lembra o último nome digitado para exibi-lo na tela automaticamente quando você quiser consultar o histórico!

---

## 🚀 Tech Stack & Ferramentas Estilizadas

* 🎀 **C++ Core:** ![C++](https://img.shields.io/badge/C%2B%2B-Pink-ff69b4?style=flat-square&logo=c%2B%2B) → Base lógica, matrizes, algoritmos de ordenação (*Bubble Sort* para o Ranking) e vetores.
* 🔮 **Windows API:** ![WinAPI](https://img.shields.io/badge/Windows%20API-Purple-8a2be2?style=flat-square&logo=windows) → Ativação do arco-íris de cores e animações de tempo no terminal.
* 🔮 **Fstream & Iomanip:** ![Files](https://img.shields.io/badge/I%2FO%20Stream-Lilac-da70d6?style=flat-square) → Gravação e leitura de múltiplos arquivos simultâneos e tratamento cirúrgico de strings para evitar quebras de tabela em UTF-8.
* 🎀 **Git / GitHub:** ![Git](https://img.shields.io/badge/Git-Rose-ffb6c1?style=flat-square&logo=git) → Controle e histórico impecável dos Commits estruturados e separados por responsabilidade.

---

## 💻 Como Rodar o Seu Próprio Sistema

Para ver o festival de cores e mensagens acontecer na sua tela, certifique-se de estar usando o **Windows** e execute os comandos abaixo no terminal do seu VS Code (use o *Command Prompt*):

```bash
# 1. Faça o download do repositório maravilhoso
git clone [https://github.com/seu-usuario/sistema-de-notas.git](https://github.com/seu-usuario/sistema-de-notas.git)

# 2. Entre na pasta do projeto
cd sistema-de-notas

# 3. Compile com o GCC
g++ main.cpp -o SistemaNotasDeluxe.exe

# 4. Dê o play na magia!
./SistemaNotasDeluxe.exe