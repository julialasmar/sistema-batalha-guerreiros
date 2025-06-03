#include<stdio.h>
#include <stdlib.h>
#include <time.h>

struct Guerreiro{
 int id_guerreiro;
 int ataque;
 int defesa;
 int carisma;
 int pontos_vida;
};

int rolaDados(){

 int dado1 = rand() % 6+1;
 int dado2 = rand() % 6+1;
 int dado3 = rand() % 6+1;

 return dado1+dado2+dado3;
}

void criaGuerreiro(struct Guerreiro *g){

 g->ataque = rolaDados();
 g->carisma = rolaDados();
 g->defesa = rolaDados();
 g->pontos_vida = g->ataque+g->carisma+g->defesa;
}

int bonusCarisma(int carisma){

 if (carisma == 18) {
    return 3;
 } else if (carisma == 16 || carisma == 17) {
    return 2;
 } else if (carisma == 14 || carisma == 15) {
    return 1;
 } else if (carisma == 6 || carisma == 7) {
    return -1;
 } else if (carisma == 4 || carisma == 5) {
    return -2;
 } else if (carisma == 3) {
    return -3;
 } else {
    return 0;
 }
}

void ataca (struct Guerreiro *g1, struct Guerreiro *g2){

 int golpePrimeiro, dados;
 dados = rolaDados();
 golpePrimeiro = dados + g1->ataque + bonusCarisma(g1->carisma);
 printf("\nPRIMEIRO GUERREIRO:\nAtaque + Dado + Bonus de carisma -> %d + %d + %d",g1->ataque, dados, bonusCarisma(g1->carisma));
 printf("\nGolpe -> %d\n",golpePrimeiro);

 int escudoSegundo, dados2;
 dados2 = rolaDados();
 escudoSegundo = dados2 + g2->defesa + bonusCarisma(g2->carisma);
 printf("\nSEGUNDO GUERREIRO:\nDefesa + Dado + Bonus de carisma -> %d + %d + %d",g2->defesa, dados2, bonusCarisma(g2->carisma));
 printf("\nEscudo -> %d\n",escudoSegundo);

 int dano;
 dano = golpePrimeiro - escudoSegundo;

 if(dano > 0 && ((g2->pontos_vida - dano) > 0)){
    g2->pontos_vida = g2->pontos_vida - dano;
 }
 printf("\n-------------------------------------------------\n");
 printf("\nDano -> %d\n",dano);
}

int main(){
 int id;
 srand(time(NULL));

 //primeiro guerreiro
 struct Guerreiro heroi;
 printf("Digite o id do primeiro guerreiro: ");
 scanf("%d",&heroi.id_guerreiro);

 criaGuerreiro(&heroi);
 printf("\nID do primeiro guerreiro: %d\nAtaque: %d\nCarisma: %d\nDefesa: %d\nPontos de vida: %d\n",heroi.id_guerreiro, heroi.ataque,heroi.carisma, heroi.defesa,heroi.pontos_vida);
 printf("Bonus de carisma: %d\n\n",bonusCarisma(heroi.carisma));

 //segundo guerreiro
 struct Guerreiro heroi2;
 printf("Digite o id do segundo guerreiro: ");
 scanf("%d",&heroi2.id_guerreiro);

 criaGuerreiro(&heroi2);
 printf("\nID do segundo guerreiro: %d\nAtaque: %d\nCarisma: %d\nDefesa: %d\nPontos de vida: %d\n",heroi2.id_guerreiro, heroi2.ataque,heroi2.carisma, heroi2.defesa,heroi2.pontos_vida);
 printf("Bonus de carisma: %d\n",bonusCarisma(heroi2.carisma));

 //ataque
 printf("\n-------------------------------------------------\n");
 ataca(&heroi,&heroi2);
 printf("Pontos de vida do segundo guerreiro depois do ataque: %d\n",heroi2.pontos_vida);

 return 0;
}
