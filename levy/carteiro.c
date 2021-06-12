#include<stdio.h>
#include<stdlib.h>
void intercala (int p, int q, int r, int v[]) 
{
   int *w;                                 
   w = malloc ((r-p) * sizeof (int));      
   int i = p, j = q;                       
   int k = 0;                              

   while (i < q && j < r) {                
      if (v[i] <= v[j])  w[k++] = v[i++];  
      else  w[k++] = v[j++];               
   }                                       
   while (i < q)  w[k++] = v[i++];         
   while (j < r)  w[k++] = v[j++];         
   for (i = p; i < r; ++i)  v[i] = w[i-p]; 
   free (w);                               
}

void mergesort (int p, int r, int v[])
{
   if (p < r-1) {                 
      int q = (p + r)/2;          
      mergesort (p, q, v);        
      mergesort (q, r, v);        
      intercala (p, q, r, v);     
   }
}
int busca(int m, int ini, int fim,int *v)
{
    int meio=(ini+fim)/2;
    if (v[meio]==m) return meio;
    if (v[meio]<m) return busca(m,meio+1,fim,v);
    return busca(m,ini,meio-1,v);
}
int main()
{
    int n,m,*casa,*encom;
    scanf("%d%d",&n,&m);
    casa = malloc(n*sizeof(int));
    encom = malloc(m*sizeof(int));
    for (int i=1;i<=n;i++)
        scanf("%d",&casa[i]);
    mergesort(0,n,casa);
    for (int j=1;j<=m;j++)
        scanf("%d",&encom[j]);
    int tempo=0;
    int posicao=1;
    for (int i=1;i<m;i++)
    {
        int proxima_posicao=busca(encom[i],1,n,casa);
        tempo+=abs(proxima_posicao-posicao);
        posicao=proxima_posicao;
    }
    printf("%d\n",tempo);
    return 0;
}