#include <stdio.h>

void quick(int vet[], int esq, int dir){
    int pivo = esq, i,ch,j;         
    for(i=esq+1;i<=dir;i++){        
        j = i;                      
        if(vet[j] < vet[pivo]){     
            ch = vet[j];               
            while(j > pivo){           
                vet[j] = vet[j-1];      
                j--;                    
            }
            vet[j] = ch;               
            pivo++;                    
        }
    }
    if(pivo-1 >= esq){              
        quick(vet,esq,pivo-1);      
    }
    if(pivo+1 <= dir){              
        quick(vet,pivo+1,dir);      
    }
 }

int main() {
  int n;
  scanf("%d", &n);

  if (n >= 0) {
    int num[n];

    for (int i = 0; i < n; i++) {
      scanf("%d", &num[i]);
    }

    quick(num, 0, n-1);

    for (int i = 0; i < n; i++) {
      if (i != (n-1)) {
        printf("%d ", num[i]);
      } else {
        printf("%d\n", num[i]);
      }
    }
  }

  return 0;
}