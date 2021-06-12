#include <stdio.h>

int main(){
    int dia, id, nota, qtdeRestaurantes;
    int maiorNota, idMaiorNota;

    dia = 1;
    while(scanf ("%d", &qtdeRestaurantes) != EOF){
        scanf("%d %d", &idMaiorNota, &maiorNota);
        for(int i = 1; i < qtdeRestaurantes; i++){
            scanf("%d %d", &id, &maiorNota);
            if(nota > maiorNota ||
            (nota == maiorNota && id < idMaiorNota)) {
                maiorNota = nota;
                idMaiorNota = id;
            }
        }
        printf("Dia %d\n%d\n\n", dia, idMaiorNota);
        dia++;
    }
    return 0;
}