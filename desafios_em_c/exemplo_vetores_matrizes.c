#include <stdio.h>

int main() {
    
    int index;
    char * nomesAlunos[3][3] = {
        {"Aluno 1", "Pt: 30", "Mat: 90"},
        {"Aluno 2", "Pt: 60", "Mat: 60"},
        {"Aluno 3", "Pt: 90", "Mat: 30"}
    };

    printf("Digite o numero do aluno que queira ver: ");
    printf("1, 2 ou 3: ");
    scanf("%d", &index);

    printf("As notas do aluno %s sao: %s e %s\n", nomesAlunos[index-1][0], nomesAlunos[index-1][1], nomesAlunos[index-1][2]);

    return 0;
}