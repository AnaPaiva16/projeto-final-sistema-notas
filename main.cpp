#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <iomanip> 
#include <ctime>   

using namespace std;

void carregarEfeito(string mensagem) {
    cout << mensagem;
    for (int i = 0; i < 3; i++) {
        Sleep(300);
        cout << ".";
    }
    Sleep(200);
    cout << " [OK] ✨" << endl;
}

void desenharGrafico(float mediaFinal) {
    int blocos = mediaFinal;
    cout << "[";
    for (int i = 0; i < 10; i++) {
        if (i < blocos) {
            cout << "█";
        } else {
            cout << "░"; 
        }
    }
    cout << "] ";
}

// Mensagens motivacionais baseadas na média do aluno
void exibirMensagemMotivacional(float mediaFinal, HANDLE hConsole) {
    cout << " 💬 MENSAGEM: ";
    if (mediaFinal >= 9.0) {
        SetConsoleTextAttribute(hConsole, 11); // Ciano
        cout << "\"Sensacional! Seu empenho te levou ao topo. Continue brilhando!\" 🌟" << endl;
    } else if (mediaFinal >= 7.0) {
        SetConsoleTextAttribute(hConsole, 10); // Verde
        cout << "\"Muito bem! Você alcançou o objetivo com dedicação e mérito.\" 🚀" << endl;
    } else if (mediaFinal >= 5.0) {
        SetConsoleTextAttribute(hConsole, 14); // Amarelo
        cout << "\"Você está no caminho! Um pouco mais de foco e você chega lá.\" 📚" << endl;
    } else {
        SetConsoleTextAttribute(hConsole, 12); // Vermelho
        cout << "\"Não desista! Cada erro é apenas um passo para um aprendizado maior.\" 💪" << endl;
    }
    SetConsoleTextAttribute(hConsole, 7); // Reseta para cor padrão
}

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 

    string nomes[20];
    int qtdAlunos = 0;
    float notas[20][5];
    float media[20];
    int qtdDisciplinas = 0;
    int opcaoInicial;

    string listaMaterias[4] = {"Português", "Matemática", "Humanas", "Ciências"};
    string disciplinasEscolhidas[5]; 
    float somaDisciplinas[5] = {0, 0, 0, 0, 0}; 
    float maiorNotaPorMateria[5] = {0, 0, 0, 0, 0}; 
    
    // Variável global do escopo do main para lembrar qual foi o último arquivo geral salvo
    string ultimoArquivoSalvo = "relatorio.txt";

    do {
        cout << "\n┌────────────────────────────────────────┐" << endl;
        cout << "│      ✨ SISTEMA DE NOTAS v4.1 ✨       │" << endl;
        cout << "├────────────────────────────────────────┤" << endl;
        cout << "│ ➕ 1 - Novo Relatório                  │" << endl;
        cout << "│ 📂 2 - Ver Relatório Salvo             │" << endl;
        cout << "│ 🎀 3 - Sobre o Sistema                 │" << endl; 
        cout << "│ 🚨 4 - Gerar Relatório de Reprovados   │" << endl; 
        cout << "│ ⚠️  5 - Gerar Relatório de Recuperação  │" << endl; 
        cout << "│ ✖️  0 - Sair                            │" << endl;
        cout << "└────────────────────────────────────────┘" << endl;
        cout << "🔍 Escolha uma opção: ";
        cin >> opcaoInicial;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcaoInicial = -1;
        }

        switch (opcaoInicial) {
            case 1: { 
                system("cls"); 
                do {
                    cout << "\n👩‍💻 Quantidade de alunos (1 a 20): ";
                    cin >> qtdAlunos;
                } while (qtdAlunos < 1 || qtdAlunos > 20);

                cin.ignore();

                for (int i = 0; i < qtdAlunos; i++) {
                    do {
                        cout << "⭐ Nome do aluno " << i + 1 << ": ";
                        getline(cin, nomes[i]);
                        if(nomes[i].empty()) {
                            cout << "❌ O nome não pode estar em branco! Tente novamente.\n";
                        }
                    } while (nomes[i].empty());
                }

                do {
                    cout << "\n📚 Quantidade de disciplinas (1 a 4): ";
                    cin >> qtdDisciplinas;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        qtdDisciplinas = -1; 
                    }
                } while (qtdDisciplinas < 1 || qtdDisciplinas > 4);

                cout << "\n--- 📑 SELEÇÃO DE DISCIPLINAS ---" << endl;
                for (int j = 0; j < qtdDisciplinas; j++) {
                    int opcao = -1;
                    do {
                        cout << "\n📌 Escolha a disciplina " << j + 1 << ":" << endl;
                        for (int m = 0; m < 4; m++) {
                            cout << "  " << m + 1 << ". " << listaMaterias[m] << endl;
                        }
                        cout << "✨ Opção: ";
                        cin >> opcao;

                        if (cin.fail() || opcao < 1 || opcao > 4) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "❌ Opção inválida!" << endl;
                            opcao = -1;
                        }
                    } while (opcao == -1);
                    
                    disciplinasEscolhidas[j] = listaMaterias[opcao - 1];
                }

                for(int j=0; j<5; j++) {
                    somaDisciplinas[j] = 0;
                    maiorNotaPorMateria[j] = -1;
                }

                for (int i = 0; i < qtdAlunos; i++) {
                    cout << "\n▶️ Inserindo notas de: " << nomes[i] << endl;
                    float soma = 0;
                    for (int j = 0; j < qtdDisciplinas; j++) {
                        do {
                            cout << "  🌸 " << left << setw(12) << disciplinasEscolhidas[j] << " (0 a 10): "; 
                            cin >> notas[i][j];

                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                                notas[i][j] = -1;
                            }
                        } while (notas[i][j] < 0 || notas[i][j] > 10);
                        soma += notas[i][j];
                        somaDisciplinas[j] += notas[i][j]; 
                        
                        if (notas[i][j] > maiorNotaPorMateria[j]) {
                            maiorNotaPorMateria[j] = notas[i][j];
                        }
                    }
                    media[i] = soma / qtdDisciplinas;
                }

                system("cls");
                cout << "\n";
                carregarEfeito("🔮 Processando médias e gerando gráficos");

                SetConsoleTextAttribute(hConsole, 11); 
                cout << "\n==================================================" << endl;
                cout << "             📊 RELATÓRIO DE DESEMPENHO           " << endl;
                cout << "==================================================" << endl;
                SetConsoleTextAttribute(hConsole, 7); 
                
                int aprovados = 0, recuperacao = 0, reprovados = 0;
                float maiorMedia = -1, menorMedia = 11;
                string alunoMaior = "", alunoMenor = "";
                
                cout << fixed << setprecision(1); 

                for (int i = 0; i < qtdAlunos; i++) {
                    if (media[i] > maiorMedia) { maiorMedia = media[i]; alunoMaior = nomes[i]; }
                    if (media[i] < menorMedia) { menorMedia = media[i]; alunoMenor = nomes[i]; }

                    cout << "\n--------------------------------------------------" << endl;
                    cout << " ► "; 
                    SetConsoleTextAttribute(hConsole, 13); 
                    cout << "ALUNO(A): " << nomes[i] << endl;
                    SetConsoleTextAttribute(hConsole, 7); 
                    cout << "--------------------------------------------------" << endl;
                    
                    SetConsoleTextAttribute(hConsole, 14); 
                    cout << "   Disciplina            | Nota" << endl;
                    SetConsoleTextAttribute(hConsole, 7); 
                    cout << "--------------------------------------------------" << endl;
                    
                    for (int j = 0; j < qtdDisciplinas; j++) {
                        cout << "  ▪ ";
                        if (disciplinasEscolhidas[j] == "Português")      cout << "Português            | ";
                        else if (disciplinasEscolhidas[j] == "Matemática") cout << "Matemática           | ";
                        else if (disciplinasEscolhidas[j] == "Humanas")    cout << "Humanas              | ";
                        else if (disciplinasEscolhidas[j] == "Ciências")   cout << "Ciências             | ";
                        
                        if (notas[i][j] >= 7.0) {
                            SetConsoleTextAttribute(hConsole, 10); 
                        } else if (notas[i][j] >= 5.0) {
                            SetConsoleTextAttribute(hConsole, 14); 
                        } else {
                            SetConsoleTextAttribute(hConsole, 12); 
                        }
                        cout << fixed << setprecision(1) << setw(4) << notas[i][j] << endl;
                        SetConsoleTextAttribute(hConsole, 7); 
                    }
                    cout << "--------------------------------------------------" << endl;
                    
                    cout << "📈 RENDIMENTO: ";
                    desenharGrafico(media[i]);
                    cout << "MÉDIA: " << media[i] << " - ";

                    if (media[i] >= 7) {
                        SetConsoleTextAttribute(hConsole, 10); 
                        cout << "[APROVADO] 🎉" << endl;
                        aprovados++;
                    }
                    else if (media[i] >= 5) {
                        SetConsoleTextAttribute(hConsole, 14); 
                        cout << "[RECUPERAÇÃO] ⚠️" << endl;
                        recuperacao++;
                    }
                    else {
                        SetConsoleTextAttribute(hConsole, 12); 
                        cout << "[REPROVADO] ❌" << endl;
                        reprovados++;
                    }
                    SetConsoleTextAttribute(hConsole, 7); 

                    exibirMensagemMotivacional(media[i], hConsole);
                    cout << "--------------------------------------------------" << endl;
                }

                float piorMediaMateria = 11.0;
                string materiaMaisDificil = "";
                for (int j = 0; j < qtdDisciplinas; j++) {
                    float mediaMateriaAtual = somaDisciplinas[j] / qtdAlunos;
                    if (mediaMateriaAtual < piorMediaMateria) {
                        piorMediaMateria = mediaMateriaAtual;
                        materiaMaisDificil = disciplinasEscolhidas[j];
                    }
                }

                float percentualAprovados = ((float)aprovados / qtdAlunos) * 100.0;

                cout << "\n==================================================" << endl;
                cout << "               💎 MÉTRICAS DA TURMA               " << endl;
                cout << "====================================================" << endl;
                cout << "• ✅ Aprovados:   " << aprovados << " aluno(s)" << endl;
                cout << "• ⚠️  Recuperação: " << recuperacao << " aluno(s)" << endl;
                cout << "• ❌ Reprovados:  " << reprovados << " aluno(s)" << endl;
                cout << "• 📊 Taxa de Aproveitamento: " << percentualAprovados << "%" << endl;
                cout << "--------------------------------------------------" << endl;
                cout << "🏆 Destaque (Maior Média): " << alunoMaior << " (" << maiorMedia << ")" << endl;
                cout << "📉 Atenção (Menor Média):   " << alunoMenor << " (" << menorMedia << ")" << endl;
                cout << "--------------------------------------------------" << endl;
                
                cout << "👑 RANKING DOS MELHORES ALUNOS:" << endl;
                string nomesRanking[20];
                float mediasRanking[20];
                for (int m = 0; m < qtdAlunos; m++) {
                    nomesRanking[m] = nomes[m];
                    mediasRanking[m] = media[m];
                }
                for (int a = 0; a < qtdAlunos - 1; a++) {
                    for (int b = 0; b < qtdAlunos - a - 1; b++) {
                        if (mediasRanking[b] < mediasRanking[b+1]) {
                            swap(mediasRanking[b], mediasRanking[b+1]);
                            swap(nomesRanking[b], nomesRanking[b+1]);
                        }
                    }
                }
                int exibirTop = (qtdAlunos < 3) ? qtdAlunos : 3;
                for (int r = 0; r < exibirTop; r++) {
                    cout << "   " << r + 1 << "º Lugar: " << left << setw(15) << nomesRanking[r] << " - Média: " << mediasRanking[r] << endl;
                }
                cout << "--------------------------------------------------" << endl;
                
                cout << "🔥 Disciplina Mais Desafiadora: " << materiaMaisDificil << " (Média: " << piorMediaMateria << ")" << endl;
                cout << "🥇 Maior Nota Registrada por Matéria:" << endl;
                for (int j = 0; j < qtdDisciplinas; j++) {
                    cout << "   - " << disciplinasEscolhidas[j] << ": " << maiorNotaPorMateria[j] << endl;
                }
                cout << "==================================================" << endl;

                // ADIÇÃO SOLICITADA: Escolha do nome do arquivo
                cin.ignore(); 
                string nomeArquivoGeral;
                cout << "\n📝 Digite o nome do arquivo para salvar (Ex: notas_bi1.txt)\n";
                cout << "👉 [Ou pressione ENTER para usar o padrão 'relatorio.txt']: ";
                getline(cin, nomeArquivoGeral);
                
                if (nomeArquivoGeral.empty()) {
                    ultimoArquivoSalvo = "relatorio.txt";
                } else {
                    // Garante que o arquivo tenha extensão .txt se o usuário esquecer
                    if (nomeArquivoGeral.find(".txt") == string::npos) {
                        nomeArquivoGeral += ".txt";
                    }
                    ultimoArquivoSalvo = nomeArquivoGeral;
                }

                ofstream arquivo(ultimoArquivoSalvo);
                if (arquivo.is_open()) {
                    time_t agora = time(0);
                    char* dataHora = ctime(&agora);
                    
                    arquivo << "Data do relatorio: " << dataHora; 
                    arquivo << "==================================================\n";
                    arquivo << "               RELATÓRIO DE NOTAS                 \n";
                    arquivo << "==================================================\n";
                    
                    arquivo << fixed << setprecision(1); 
                    for (int i = 0; i < qtdAlunos; i++) {
                        arquivo << "Aluno: " << left << setw(15) << nomes[i] 
                                << " | Media: " << setw(4) << media[i] << " | Situacao: ";
                        if (media[i] >= 7) arquivo << "Aprovado\n";
                        else if (media[i] >= 5) arquivo << "Recuperacao\n";
                        else arquivo << "Reprovado\n";
                    }
                    arquivo << "--------------------------------------------------\n";
                    arquivo << "Resumo: " << aprovados << " aprovados, " << recuperacao << " em recuperacao, " << reprovados << " reprovados.\n";
                    arquivo << "Taxa de Aproveitamento: " << percentualAprovados << "%\n";
                    arquivo << "Maior media: " << alunoMaior << " (" << maiorMedia << ")\n";
                    arquivo << "Menor media: " << alunoMenor << " (" << menorMedia << ")\n";
                    arquivo << "==================================================\n";
                    arquivo.close();
                    cout << "\n";
                    carregarEfeito("🌸 Exportando dados para " + ultimoArquivoSalvo);
                }
                break;
            }
            case 2: { 
                system("cls");
                // Modificado para sempre abrir o ÚLTIMO arquivo que você customizou ou salvou!
                ifstream leitura(ultimoArquivoSalvo);
                if (leitura.is_open()) {
                    string linha;
                    cout << "\n📂 --- CONTEÚDO DO ARQUIVO SALVO [" << ultimoArquivoSalvo << "] ---\n";
                    while (getline(leitura, linha)) {
                        cout << linha << endl;
                    }
                    leitura.close();
                    cout << "--------------------------------------------------\n";
                    
                    ofstream logAcesso("acessos.txt", ios::app);
                    if (logAcesso.is_open()) {
                        time_t agoraLog = time(0);
                        char* dataHoraLog = ctime(&agoraLog);
                        logAcesso << "O arquivo " << ultimoArquivoSalvo << " foi lido em: " << dataHoraLog;
                        logAcesso.close();
                    }
                    
                } else {
                    cout << "\n🎀 [Aviso] Nenhum relatório com o nome '" << ultimoArquivoSalvo << "' foi encontrado." << endl;
                }
                break;
            }
            case 3: { 
                system("cls");
                cout << "\n============= SOBRE O SISTEMA =============" << endl;
                cout << "🌸 Sistema de Notas v4.1 " << endl;
                cout << "👑 Desenvolvido por: Paiva's Tech" << endl; 
                cout << "💖 Turma: LOPAL 2026 - SENAI-SP" << endl;
                cout << "=============================================" << endl;
                break;
            }
            case 4: { 
                system("cls");
                if (qtdAlunos == 0) {
                    cout << "\n⚠️ [!] É necessário rodar o relatório (Opção 1) primeiro para ter dados!" << endl;
                    break;
                }
                
                cin.ignore();
                string nomeArqReprovados;
                cout << "\n📝 Digite o nome para o arquivo de reprovados\n";
                cout << "👉 [Ou pressione ENTER para usar o padrão 'reprovados.txt']: ";
                getline(cin, nomeArqReprovados);
                
                if (nomeArqReprovados.empty()) {
                    nomeArqReprovados = "reprovados.txt";
                } else if (nomeArqReprovados.find(".txt") == string::npos) {
                    nomeArqReprovados += ".txt";
                }
                
                ofstream arqReprovados(nomeArqReprovados);
                if (arqReprovados.is_open()) {
                    time_t ago = time(0);
                    char* dtHora = ctime(&ago);
                    
                    arqReprovados << "Data do relatório: " << dtHora;
                    arqReprovados << "=== LISTA DE ALUNOS REPROVADOS ===\n\n";
                    
                    int cont = 0;
                    for (int i = 0; i < qtdAlunos; i++) {
                        if (media[i] < 5) { 
                            arqReprovados << "• " << nomes[i] << " (Média: " << media[i] << ")\n";
                            cont++;
                        }
                    }
                    if (cont == 0) arqReprovados << "Nenhum aluno reprovado nesta listagem! 🎉\n";
                    
                    arqReprovados.close();
                    carregarEfeito("🔍 Filtrando alunos com notas baixas");
                    cout << "\n✨ [OK] '" << nomeArqReprovados << "' gerado com sucesso com " << cont << " registro(s)." << endl;
                }
                break;
            }
            case 5: { 
                system("cls");
                if (qtdAlunos == 0) {
                    cout << "\n⚠️ [!] É necessário rodar o relatório (Opção 1) primeiro para ter dados!" << endl;
                    break;
                }
                
                cin.ignore();
                string nomeArqRecup;
                cout << "\n📝 Digite o nome para o arquivo de recuperação\n";
                cout << "👉 [Ou pressione ENTER para usar o padrão 'recuperacao.txt']: ";
                getline(cin, nomeArqRecup);
                
                if (nomeArqRecup.empty()) {
                    nomeArqRecup = "recuperacao.txt";
                } else if (nomeArqRecup.find(".txt") == string::npos) {
                    nomeArqRecup += ".txt";
                }
                
                ofstream arqRecup(nomeArqRecup);
                if (arqRecup.is_open()) {
                    time_t agora = time(0);
                    char* dataHora = ctime(&agora);
                    
                    arqRecup << "Data do relatorio: " << dataHora;
                    arqRecup << "=== LISTA DE ALUNOS EM RECUPERAÇÃO ===\n";
                    arqRecup << "FOCO PEDAGÓGICO: Alunos que precisam de monitoria interna.\n\n";
                    
                    int contRec = 0;
                    arqRecup << fixed << setprecision(1);
                    for (int i = 0; i < qtdAlunos; i++) {
                        if (media[i] >= 5.0 && media[i] < 7.0) { 
                            arqRecup << "Aluno: " << left << setw(15) << nomes[i] << " | Média Geral: " << media[i] << "\n";
                            contRec++;
                        }
                    }
                    if (contRec == 0) arqRecup << "Parabéns! Nenhum aluno em situação de recuperação técnica. 🎉\n";
                    
                    arqRecup.close();
                    carregarEfeito("⚠️  Mapeando alunos em situação de recuperação");
                    cout << "\n✨ [OK] '" << nomeArqRecup << "' gerado com sucesso com " << contRec << " registro(s)." << endl;
                    cout << "💡 Dica: Use esse arquivo para montar grupos de estudo e reforço escolar!" << endl;
                }
                break;
            }
            case 0:
                cout << "\n💖 Saindo... Muito obrigada por usar o sistema!" << endl;
                break;
            default:
                cout << "\n❌ Opção inválida! Tente novamente." << endl;
                break;
        }
    } while (opcaoInicial != 0);

    return 0;
}