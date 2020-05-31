//importação de bibliotecas
#include <stdio.h>
//declaração de variáveis globais
int n1,n2;
//atribuição de funções globais
int main(){
    //declaração de variáveis locais
    int i,month,year,monthdays,day,weekday; 
    char months[12][10] = {"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"
    };
    char days[7][5] = {"Dom ","Seg ","Ter ","Qua ","Qui ","Sex ","Sab "
    };
    //entrada do mês e ano
    printf("Digite o mês desejado: ");
    scanf("%d", & month);
    printf("Digite o ano desejado: ");
    scanf("%d", & year);
    //atribuição de funções locais
    void printdays(int n1,int n2){
        for(i = n1; i < monthdays; i++){
            if(i < 10){
                printf("   %d",i+1);
            }
            else{
                printf("  %d",i+1);
            }
            if(((i+1) + n2) % 7==0 && i < monthdays-1){
                printf("\n");
                i+=1;
                printf(" %d",i+1);
            }
        }
        return ;
    }
    //imprimir dias da semana
    printf("\n        %s %d\n",months[month-1],year);
    for (i=0; i < 7;i++){
        printf(days[i]);
    }
    printf("\n");
    //verificar quantidade de dias do mês
    monthdays = 30 + (month + month/8) % 2;
    //verificar se ano é bissexto
    if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        monthdays = 29;
    }
    else {
        if (month == 2){
            monthdays = 28;
        }
    }
    //verificar qual dia da semana começa o mês
    day = 1;
    if (month < 3){
        day += year;
        year--;
    }
    else {
        day += year -2;
    }
    weekday = (23 * month /9 + day + 4 + year /4 - year /100 + year /400) % 7;
    //imprimir calendário
    switch(weekday){    
        case 0:
            printf(" %d",1);
            printdays(1,weekday);
            break;
        case 1:
            printf("     %d",1);
            printdays(1,weekday);
            break;
        case 2:
            printf("         %d",1);
            printdays(1,weekday);
            break;
        case 3:
            printf("             %d",1);
            printdays(1,weekday);
            break;
        case 4:
            printf("                 %d",1);
            printdays(1,weekday);
            break;
        case 5:
            printf("                     %d",1);
            printdays(1,weekday);
            break;
        case 6:
            printf("                         %d\n 2",1);
            printdays(2,weekday);
            break;
    }
    return 0;
}
