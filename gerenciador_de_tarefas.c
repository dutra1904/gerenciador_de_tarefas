#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_DESC 256

typedef struct {
    char description[MAX_DESC];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("\nLimite de tarefas atingido!\n");
        return;
    }

    printf("\nDigite a descricao da tarefa: ");
    getchar(); // Limpar o buffer do teclado
    fgets(tasks[taskCount].description, MAX_DESC, stdin);
    tasks[taskCount].description[strcspn(tasks[taskCount].description, "\n")] = 0; // Remover o '\n'
    tasks[taskCount].completed = 0;
    taskCount++;
    printf("Tarefa adicionada com sucesso!\n");
}

void viewTasks() {
    if (taskCount == 0) {
        printf("\nNenhuma tarefa adicionada ainda.\n");
        return;
    }

    printf("\nTarefas:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%c] %s\n", i + 1, tasks[i].completed ? 'X' : ' ', tasks[i].description);
    }
}

void updateTask() {
    int index;

    if (taskCount == 0) {
        printf("\nNenhuma tarefa para atualizar.\n");
        return;
    }

    viewTasks();
    printf("\nDigite o numero da tarefa que deseja atualizar: ");
    scanf("%d", &index);

    if (index < 1 || index > taskCount) {
        printf("Tarefa invalida!\n");
        return;
    }

    getchar(); // Limpar o buffer do teclado
    printf("Digite a nova descricao da tarefa: ");
    fgets(tasks[index - 1].description, MAX_DESC, stdin);
    tasks[index - 1].description[strcspn(tasks[index - 1].description, "\n")] = 0;
    printf("Tarefa atualizada com sucesso!\n");
}

void completeTask() {
    int index;

    if (taskCount == 0) {
        printf("\nNenhuma tarefa para completar.\n");
        return;
    }

    viewTasks();
    printf("\nDigite o numero da tarefa que deseja marcar como concluida: ");
    scanf("%d", &index);

    if (index < 1 || index > taskCount) {
        printf("Tarefa invalida!\n");
        return;
    }

    tasks[index - 1].completed = 1;
    printf("Tarefa marcada como concluida!\n");
}

void deleteCompletedTasks() {
    if (taskCount == 0) {
        printf("\nNenhuma tarefa para deletar.\n");
        return;
    }

    int newTaskCount = 0;
    for (int i = 0; i < taskCount; i++) {
        if (!tasks[i].completed) {
            tasks[newTaskCount++] = tasks[i];
        }
    }

    taskCount = newTaskCount;
    printf("Tarefas concluidas foram deletadas!\n");
}

int main() {
    int option;

    do {
        printf("\nGerenciador de Tarefas\n");
        printf("1 - Adicionar tarefa\n");
        printf("2 - Ver tarefa(s) adicionada(s)\n");
        printf("3 - Atualizar tarefa\n");
        printf("4 - Completar tarefa\n");
        printf("5 - Deletar tarefas concluidas\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                updateTask();
                break;
            case 4:
                completeTask();
                break;
            case 5:
                deleteCompletedTasks();
                break;
            case 6:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (option != 6);

    return 0;
}
