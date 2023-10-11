#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int puissance(int e,int n){
    //elever un nombre e a une puissance n
    int f = e;
    if (n == 0){
        return 1;
    }
    for(int i = 0; i<n-1; i++){
        f = f*e;
    }
    return f;
}

void remplir_tableau(int b, char *t){
    //remplir un tableau
    char letter = 'A';
    for(int i = 0; i<b; i++){
        if (i <= 9){
            sprintf((t+i), "%d", i);;
        }else{
            *(t+i)= letter;
            letter++;
        }
    }

}


void convertir_base_voulue(int n, char a[n+1], int b1, int b2, char *s){
    char t1[b1+1];
    char t2[b2+1];
    char f[100];
    char h[100];
    int j = 0;
    int k;
    int m =-1;
    int l =0;

    //initialement on remplit le tableau
    remplir_tableau(b1, t1);
    remplir_tableau(b2, t2);
    int c = 0;
    for(int i =n-1; i >=0; i--){
        //ici on se rassure que l'element entre appartient a la base specifie au depart et on converti ce nombre en base 10
        while((j <b1)&&(a[i] != t1[j])){
            j = j + 1;
        }
        if (a[i] == t1[j]){
            //conversion en base 10
            c = c + (j*puissance(b1, n-1-i));
        }
        else{
            // dans le cas ou le nombre n'est pas de la base on sort du programme
            printf("le nombre entree n'est pas de la base\n");
            return ;
        }
        j = 0;
    }
    if(c == 0){
        printf("le nombre %s dans la base %d vaut %c dans la base %d",a,b1,t2[c],b2);
        return;
    }

    if ((b2>b1)&&(c<b2)){
        //si on constate que l'element a convertir a juste un caractere dans la base dans laquellle on veut convertir on sort 
        printf("le nombre %s dans la base %d vaut %c dans la base %d",a,b1,t2[c],b2);
        return;
    }
        //printf("%d\n",c);
        while (c >= b2){
            //on fait les divisions successives on recupere le reste et le divendende pour la prochaine division
            k = c%b2;
            c = c/b2;
            m = m+1;
            //on stocke directement l'element correspondant au reste dans la base b2
            f[m] = t2[k];
        }
        if (c != 0){
            //si le dernier dividende est different de 0 on le concatene egalement 
            m = m+1;
            f[m] = t2[c];
        }
        while(m >=0){
            //ici on iverse la chaine
            h[l] = f[m];
            l = l+1;
            m = m-1;
        }
        printf("le nombre %s dans la base %d vaut %s dans la base %d",a,b1,h,b2);
}

int main(){
    //int A = 11;
    int b1;
    int b2;
    char d[100];
    char h[100];
    printf("----------------conversion d'une chaine de caractere d'une base α vers une base \\u03B2 ---------------\n");
    printf("entrer l'element a convertir :\n");
    scanf("%s", d);
    printf("entrer la base du nombre : \n");
    scanf("%d",&b1);
    printf("entrer la base dans laquelle on doit le convertir : \n");
    scanf("%d",&b2);
    convertir_base_voulue(strlen(d),d,b1,b2,h);

}
