#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { char nome[18];
				 int tipoA;
				 int tipoB;
				 int hp;
				 int att;
				 int spe;	
}Pokemon;

//Questa funzione si occupa di stampare le corrispondenze fra numero e tipo
void corr_tipo(){
	printf("Il tipo e' un numero. I pokemon monotipo hanno 0 come secondo numero\n");
	printf("Fuoco=1\nAcqua=2\nErba=3\nElettro=4\nVolante=5\nRoccia=6\nTerra=7\nAcciaio=8\nNormale=9\nSpettro=10\n");
	printf("Psico=11\nBuio=12\nLotta=13\nColeottero=14\nVeleno=15\nFolletto=16\nDrago=17\nGhiaccio=18\n");	
}

//Questa funzione si occupa di salvare il pokedex in un file di testo
void agg_pokedex ()
{
	int numero,quanti;
	int i;
	Pokemon buff;
	FILE * fpokedex;
	FILE * fnumero;
	printf("Quanti pokemon vuoi aggiungere al pokedex?\n");
	scanf("%d" , &quanti);
	system("cls");
	numero=0;
		
	//inserimento dei nuovi pokemon nel file
	fpokedex=fopen("pokedex.txt","a");

	for(i=0;i<quanti;i++){
		printf("Inserisci il nome del nuovo pokemon numero %d\n",(i+1));
		scanf("%s",buff.nome);
		corr_tipo();
		do{
			printf("Inserisci il primo tipo del nuovo pokemon numero %d\n",(i+1));
			scanf("%d",&buff.tipoA);
		  } while(buff.tipoA>18 || buff.tipoA<1);
		do{
			printf("Inserisci il secondo tipo del nuovo pokemon numero %d\n",(i+1));
			scanf("%d",&buff.tipoB);
		  } while(buff.tipoB>18 || buff.tipoB<0);
		do{
		    printf("Inserisci quanti punti vita ha il numero %d(non puo' essere negativo o nullo)\n",(i+1));
			scanf("%d",&buff.hp);
		}   while(buff.hp<1);
		do{
			printf("Inserisci il valore di attacco del numero %d(non puo' essere negativo o nullo)\n",(i+1));
			scanf("%d",&buff.att);
		}	while(buff.att<1);
		do{
			printf("Inserisci 1 se usa attachi fisici, 2 se usa attacchi speciali\n");
			scanf("%d",&buff.spe);
		}	while(buff.spe!=1 && buff.spe!=2);
		if (fprintf(fpokedex,"\n%s %d %d %d %d %d",buff.nome,buff.tipoA,buff.tipoB,buff.hp,buff.att,buff.spe)<0)
		{
			exit(1);
		}else
		{
				//questa parte aggiorna il numero di pokemon
			numero=num_pok();
			//numero=numero+quanti;
			fnumero=fopen("numero.txt","w");
			fprintf(fnumero,"%d",numero+1);
			fclose(fnumero);
		}
	    system("cls");
	}
	fclose(fpokedex);
	
	
	
}
//Questa funzione serve per stampare i tipi invece dei numeri
void stampa_tipo(int x)
{

switch(x)
{
case 0:;
        break;
       
case 1: printf("Fuoco ");
		break;
case 2: printf("Acqua ");
	    break;
case 3: printf("Erba ");
        break;
case 4: printf("Elettro ");
        break;
case 5: printf("Volante ");
        break;
case 6: printf("Roccia ");
        break;
case 7: printf("Terra ");
        break;
case 8: printf("Acciaio ");
        break;
case 9: printf("Normale ");
		break;
case 10: printf("Spettro ");
		 break;
case 11: printf("Psico ");
		 break;
case 12: printf("Buio ");
		 break;
case 13: printf("Lotta ");
		 break;
case 14: printf("Coleottero ");
		 break;
case 15: printf("Veleno ");
		 break;
case 16: printf("Folletto "); 
		 break;
case 17: printf("Drago ");
		 break;
case 18: printf("Ghiaccio ");
		 break;
default:;break;
}
}

//Questa funzione stampa il pokedex
void stampa_pokedex(char * nfile, int numero)
{
	int i;
	FILE * fp;
	Pokemon buff;
	
	fp=fopen(nfile ,"r");
	if(fp==NULL){
		printf("Non e' stato trovato nulla\n");
		exit(1);
	}
	for (i=0;i<numero;i++){
	  fscanf(fp,"%s%d%d%d%d%d",buff.nome,&buff.tipoA,&buff.tipoB,&buff.hp,&buff.att,&buff.spe);
	  printf("%d %s ",(i+1),buff.nome);
	  stampa_tipo(buff.tipoA);
	  stampa_tipo(buff.tipoB);
	  printf("\n");
	}
	fclose(fp);
	printf("Premi INVIO per continuare.\n");
	getchar();
	getchar();
}

//Questa funzione dice quali slot di una squadra sono disponibili
void squadra_occ(){
	char *testi[6];
	int i;
	FILE * fsquadra;
	testi[0]="squadra1.txt";
	testi[1]="squadra2.txt";
	testi[2]="squadra3.txt";
	testi[3]="squadra4.txt";
	testi[4]="squadra5.txt";
	testi[5]="squadra6.txt";
	
	for(i=0;i<6;i++){
	 	fsquadra= fopen(testi[i], "r");

        if(fsquadra==NULL)
            printf("Lo slot %d e' vuoto\n", i+1);
        else
            printf("Lo slot %d contiene una squadra\n", i+1);
		fclose(fsquadra);}
	
}
//Questa funzione crea un array di pokemon provenienti da un file
	Pokemon* array_pokemon (char * nfile, int numero){
	FILE * fd;
	Pokemon * buff;
	int i;
	
	buff=malloc(numero*sizeof(Pokemon));
	if(buff==NULL){
		printf("Errore\n");
		return NULL;
	}
	fd=fopen(nfile,"r");
	if(fd==NULL){
		printf("Qualcosa non trovato\n");
		return NULL;
	}
	for(i=0;i<numero;i++){
		fscanf(fd,"%s%d%d%d%d%d",buff[i].nome,&buff[i].tipoA,&buff[i].tipoB,&buff[i].hp,&buff[i].att,&buff[i].spe);
	}
	fclose(fd);
	return buff;
}
//Questa funzione si occupa di creare una squadra
void crea_squadra (){
	int id;
	int i;
	int numero;
	int squadra;
	FILE * fpokedex;
	FILE * fsquadra;
	FILE * fnumero;
	Pokemon * buff;

	//scegliere in quale slot salvare la squadra
	numero=num_pok();
	squadra_occ();
	printf("Quale slot vuoi usare?\nSe e' occupato la squadra precedente verra' persa\n");
	scanf("%d",&squadra);
	switch(squadra){
		case 1:fsquadra=fopen("squadra1.txt","w");break;
		case 2:fsquadra=fopen("squadra2.txt","w");break;
		case 3:fsquadra=fopen("squadra3.txt","w");break;
		case 4:fsquadra=fopen("squadra4.txt","w");break;
		case 5:fsquadra=fopen("squadra5.txt","w");break;
		case 6:fsquadra=fopen("squadra6.txt","w");break;
		default:printf("Non hai scelto uno slot valido\n");exit(0);	
	}
	if(fsquadra==NULL){
		printf("Errore strano\n");
	}	
	
	//crea un array per contenere tutti i pokemon
    buff= array_pokemon("pokedex.txt",numero);
	system("cls");
    //salva la squadra
	stampa_pokedex("pokedex.txt", numero );
	printf("Inserisci il numero del pokedex per creare la tua squadra di 6 pokemon\n");
	for(i=0;i<6;i++){
		do{
			scanf("%d",&id);
		}while(id<1 || id>numero);
		id=id-1;
		fprintf(fsquadra,"%s %d %d %d %d %d\n",buff[id].nome,buff[id].tipoA,buff[id].tipoB,buff[id].hp,buff[id].att,buff[id].spe);
		printf("Il pokemon e' stato inserito correttamente\n");
	}
	free(buff);
	fclose(fsquadra);
	
}

//Questa funzione si occupa di calcolare l'interazione fra i tipi
float debolezza(int a,int d){
	switch(a){
		case 1:if(d==3 || d==8 || d==14 || d==18){return 2;}
			   else{if(d==1 || d==2 || d==6 || d==17){return 0.5;}
			   else{return 1;};};//Fuoco
		case 2:if(d==1 || d==6 || d==7){return 2;}
			   else{if(d==2 || d==3 || d==17){return 0.5;}
			   else{return 1;};};//Acqua
		case 3:if(d==2 || d==6 || d==7){return 2;}
			   else{if(d==1 || d==3 || d==5 || d==8 || d==14 || d==15 || d==17){return 0.5;}
			   else{return 1;};};//Erba
		case 4:if(d==2 || d==5){return 2;}
			   else{if(d==3 || d==4 || d==17){return 0.5;}
			   else{if(d==7){return 0;}
			   else{return 1;};};};//Elettro
		case 5:if(d==3 || d==13 || d==14){return 2;}
			   else{if(d==4 || d==6 || d==8){return 0.5;}
			   else{return 1;};};//Volante
		case 6:if(d==1 || d==5 || d==14 || d==18){return 2;}
			   else{if(d==7 || d==8 || d==13){return 0.5;}
			   else{return 1;};};//Roccia
		case 7:if(d==1 || d==4 || d==6 || d==8 || d==15){return 2;}
			   else{if(d==3 || d==14){return 0.5;}
			   else{if(d==5){return 0;}
			   else{return 1;};};};//Terra
		case 8:if(d==6 || d==16 || d==18){return 2;}
			   else{if(d==1 || d==2 ||d==4 ||d==8){return 0.5;}
			   else{return 1;};};//Acciaio
		case 9:if(d==6 || d==8){return 0.5;}
			   else{if(d==10){return 0;}
			   else{return 1;};};//Normale
		case 10:if(d==10 || d==11){return 2;}
			   else{if(d==12){return 0.5;}
			   else{if(d==9){return 0;}
			   else{return 1;};};};//Spettro
		case 11:if(d==13 || d==15){return 2;}
			   else{if(d==11 || d==8){return 0.5;}
			   else{if(d==12){return 0;}
			   else{return 1;};};};//Psico
		case 12:if(d==10 || d==11){return 2;}
			   else{if(d==8 || d==12 || d==13){return 0.5;}
			   else{return 1;};};//Buio
		case 13:if(d==6 || d==8 || d==9 || d==12 || d==18){return 2;}
			   else{if(d==5 || d==11 || d==14 || d==15 || d==16){return 0.5;}
			   else{if(d==10){return 0;}
			   else{return 1;};};};//Lotta
		case 14:if(d==3 || d==11 || d==12){return 2;}
			   else{if(d==1 || d==5 || d==8 || d==10 || d==13 || d==15 || d==16){return 0.5;}
			   else{return 1;};};//Coleottero
		case 15:if(d==3 || d==16){return 2;}
			   else{if(d==6 || d==7 || d==10 || d==15){return 0.5;}
			   else{if(d==8){return 0;}
			   else{return 1;};};};//Veleno
		case 16:if(d==12 || d==13 || d==17){return 2;}
			   else{if(d==1 || d==8 || d==15){return 0.5;}
			   else{return 1;};};//Folletto
		case 17:if(d==17){return 2;}
			   else{if(d==8){return 0.5;}
			   else{if(d==16){return 0;}
			   else{return 1;};};};//Drago
		case 18:if(d==3 || d==5 || d==7 || d==17){return 2;}
			   else{if(d==1 || d==2 || d==8 || d==18){return 0.5;}
			   else{return 1;};};//Ghiaccio
		default:return 1;
	}
}


//Questa funzione stampa se un attaco sia stato o no efficace
void superef(float x){
	if(x==4){printf("E' un sacco super efficcace\n\n");}
	if(x==2){printf("E' super efficace\n\n");}
	if(x==0.5){printf("Non e' molto efficacie...\n\n");}
	if(x==0.25){printf("E' davvero poco efficace\n\n");}
	if(x==0){printf("Non ha alcun effetto...\n\n");}
	if(x==1){printf("\n\n");}}
//Questa funzione ritorna quanti pokemon sono presenti nel pokedex	
int num_pok(){
	FILE * fnumero;
	int numero;
	fnumero=fopen("numero.txt","r");
	if(fnumero==NULL){
		printf("Il pokedex non esiste\n");
		exit(1);
	}
	fscanf(fnumero,"%d",&numero);
	fclose(fnumero);
	return numero;
}
//Questa funzione controlla una squadra esistente
void stampa_squadra(){
	int squadra;
	squadra_occ();
	printf("Quale squadra vuoi guardare?\n");
	scanf("%d",&squadra);
	switch(squadra){
		case 1:stampa_pokedex("squadra1.txt",6);break;
		case 2:stampa_pokedex("squadra2.txt",6);break;
		case 3:stampa_pokedex("squadra3.txt",6);break;
		case 4:stampa_pokedex("squadra4.txt",6);break;
		case 5:stampa_pokedex("squadra5.txt",6);break;
		case 6:stampa_pokedex("squadra6.txt",6);break;
		default:printf("Non hai selezionato una squadra valida\n");
				printf("Premi INVIO per continuare.\n");
				getchar();
				getchar();
		
	}
	
}
//Questa funzione si occupa di calcolare il danno 
//le variabili rappresentano rispettivamente:Il tipo della mossa, attacco di chi attaca, tipi di chi difende 
int danno(int tipo_a, int att_a,int tipod_a,int tipod_b){
	float debolez;
	int danno;
	
	debolez=debolezza(tipo_a,tipod_a)*debolezza(tipo_a,tipod_b);
	danno=att_a*debolez;
	superef(debolez);
	return danno;
}

//Questa funzione stampa i crediti
 void crediti(){
 	printf("Si ringraziano tutte le persone che hanno creduto in me e tutti quelli che mi vogliono bene\n");
 	printf("La forza che mi hanno dato con il loro sostegno e i loro consigli mi hanno permesso di arrivare fino a qui\n");
 	printf("Grazie al loro supporto sono riuscito a superare tutte le difficoltà che mi hanno ostacolato\n");
 	printf("Ringrazio Emanuele Medaglia che mi ha aiutato ad ottenre i mezzi necessari per scrivere questo capolavoro\n");
 	printf("Ringrazio Simone Masullo che mi ha aiutato a risolvere questioni spinose e a stanare alcuni bacarozzi\n");
 	printf("Ringrazio Umberto Frianzese, Antonio Napolitino e Aniello La Pietra per le conosenze che hanno condiviso con me,");
 	printf("senza le quali questo ambizioso progetto non avrebbe mai visto la luce\n");
 	printf("Ringrazio Andrea Delia che mi ha consigliato lungo il percorso grazie alla sua saggia esperienza\n");
 	printf("E infine ringrazio Emma Manzo e Edoardo Iannacone, che non hanno fatto un cazzo, ma vi voglio bene comunque\n");
 }
//Questa funzione illuderà chi usa il programma che esistano delle mosse vere
void mossa(int tipo,int spat){
	switch(tipo){
		case 1:if(spat==1){printf("Fuoco Carica\n");}
			   if(spat==2){printf("Lanciafiamme\n");}
			   break;
	    case 2:if(spat==1){printf("Cascata\n");}
			   if(spat==2){printf("Idrovampata\n");}
			   break;
	    case 3:if(spat==1){printf("Fendi Foglia\n");}
			   if(spat==2){printf("Verdebufera\n");}
			   break;
		case 4:if(spat==1){printf("Tuono Pugno\n");}
			   if(spat==2){printf("Fulmine\n");}
			   break;
		case 5:if(spat==1){printf("Volo\n");}
			   if(spat==2){printf("Eterelama\n");}
			   break;
		case 6:if(spat==1){printf("Pietrataglio\n");}
			   if(spat==2){printf("Gemmoforza\n");}
			   break;
		case 7:if(spat==1){printf("Terremoto\n");}
			   if(spat==2){printf("Geoforza\n");}
			   break;
		case 8:if(spat==1){printf("Meteor Pugno\n");}
			   if(spat==2){printf("Cannonflash\n");}
			   break;
		case 9:if(spat==1){printf("Ritorno\n");}
			   if(spat==2){printf("Ipervoce\n");}
			   break;
		case 10:if(spat==1){printf("Ombra Artigli\n");}
			   if(spat==2){printf("Palla Ombra\n");}
			   break;
		case 11:if(spat==1){printf("Psicotaglio\n");}
			   if(spat==2){printf("Psichico\n");}
			   break;
		case 12:if(spat==1){printf("Nottesferza\n");}
			   if(spat==2){printf("Neropulsar\n");}
			   break;
		case 13:if(spat==1){printf("Breccia\n");}
			   if(spat==2){printf("Forza Sfera\n");}
			   break;		
		case 14:if(spat==1){printf("Forbice X\n");}
			   if(spat==2){printf("Ronzio\n");}
			   break;
		case 15:if(spat==1){printf("Velenpuntura\n");}
			   if(spat==2){printf("Fango Bomba\n");}
			   break;
		case 16:if(spat==1){printf("Carineria\n");}
			   if(spat==2){printf("Magibrillio\n");}
			   break;
		case 17:if(spat==1){printf("Drago Artigli\n");}
			   if(spat==2){printf("Dragopulsar\n");}
			   break;
		case 18:if(spat==1){printf("Gelodenti\n");}
			   if(spat==2){printf("Geloraggio\n");}
			   break;
		default:break;	   	   	   
		}
		
}
//Questa funzione stampa la squadra per le fasi della lotta
void stampa_squadra_lotta(Pokemon* squadra){
	int i;
	for(i=0;i<6;i++){
		printf("%d %s ",(i+1),squadra[i].nome);
		stampa_tipo(squadra[i].tipoA);
		stampa_tipo(squadra[i].tipoB);
		printf("Hp %d\n",squadra[i].hp);
	}
}
//Questa funzione seleziona un pokemon
int seleziona_pokemon(Pokemon* squadra){
	int sel;
	stampa_squadra_lotta(squadra);
 	
 	do{
 		scanf("%d",&sel);
 		if(sel<1 || sel>6){
 			printf("Non hai selezionato un Pokemon valido\n");
		 }else{if (squadra[sel-1].hp==0){
		 	printf("Il pokemon scelto e' esausto, scegline uno vivo\n");
		}else{return sel-1 ;};}
		 }while((sel<1 || sel>6) || squadra[sel-1].hp==0);
 	
	 }
//Questa funzione somma gli hp di una squadra di pokemon
int somma_hp(Pokemon *squadra){
	int somma;
	int i;
	somma=0;
	for (i=0;i<6;i++){
		somma=somma+squadra[i].hp;
	}
	return somma;
}

//Lotta Pokemon
 void lotta(){
 	int quadra_a;
 	int quadra_b;
 	int sel;
 	int att;
 	int nem; 	
 	int hp_squadra_a;
 	int hp_squadra_b;
 	Pokemon * squadra_a;
 	Pokemon * squadra_b;
  	 	
 	//Questa parte fa selezionare le due squadre per lo scontro e quali sono i primi pokemon che si scontrano
 	squadra_occ();
 
 	do{
 		printf("Seleziona la squadra che vuoi usare\n");
       	scanf("%d",&quadra_a);
 		switch(quadra_a){
 			case 1:squadra_a=array_pokemon("squadra1.txt",6);break;
 			case 2:squadra_a=array_pokemon("squadra2.txt",6);break;
 			case 3:squadra_a=array_pokemon("squadra3.txt",6);break;
 			case 4:squadra_a=array_pokemon("squadra4.txt",6);break;
 			case 5:squadra_a=array_pokemon("squadra5.txt",6);break;
 			case 6:squadra_a=array_pokemon("squadra6.txt",6);break;
 			default:printf("Non hai selezionato una squadra valida\n");
			 };}while((quadra_a>7 && quadra_a<1) || squadra_a==NULL);
	 
	do{
 		printf("Seleziona la squadra che vuoi affrontare\n");
       	scanf("%d",&quadra_b);
 		switch(quadra_b){
 			case 1:squadra_b=array_pokemon("squadra1.txt",6);break;
 			case 2:squadra_b=array_pokemon("squadra2.txt",6);break;
 			case 3:squadra_b=array_pokemon("squadra3.txt",6);break;
 			case 4:squadra_b=array_pokemon("squadra4.txt",6);break;
 			case 5:squadra_b=array_pokemon("squadra5.txt",6);break;
 			case 6:squadra_b=array_pokemon("squadra6.txt",6);break;
 			default:printf("Non hai selezionato una squadra valida\n");
			 };}while((quadra_b>7 && quadra_b<1) || squadra_b==NULL);
    hp_squadra_a=somma_hp(squadra_a);
    hp_squadra_b=somma_hp(squadra_b);
	system("cls");
	printf("Seleziona il pokemon con cui vuoi iniziare\n");
 	att=seleziona_pokemon(squadra_a);
 	nem=0;
 	printf("%s e' entrato in campo\n\n",squadra_b[nem].nome);
	//questa parte dovrebbe far funzionare la parte della lotta
	while(1){
		printf("Seleziona cosa vuoi fare\n");
		printf("1 %s usa ",squadra_a[att].nome); mossa(squadra_a[att].tipoA,squadra_a[att].spe);
		if(squadra_a[att].tipoB!=0){
			printf("2 %s usa ",squadra_a[att].nome); mossa(squadra_a[att].tipoB,squadra_a[att].spe);};
		printf("3 Cambia pokemon\n");
		do{
			scanf("%d",&sel);
		}while (!((squadra_a[att].tipoB!=0 && sel==2) || sel==1 || sel==3 ));
		switch(sel){
			case 1:printf("%s usa ",squadra_a[att].nome);
			       mossa(squadra_a[att].tipoA,squadra_a[att].spe);
			       squadra_b[nem].hp-=danno(squadra_a[att].tipoA,squadra_a[att].att,squadra_b[nem].tipoA,squadra_b[nem].tipoB);
			       break;
			case 2:printf("%s usa ",squadra_a[att].nome);
			       mossa(squadra_a[att].tipoB,squadra_a[att].spe);
			       squadra_b[nem].hp=squadra_b[nem].hp-danno(squadra_a[att].tipoB,squadra_a[att].att,squadra_b[nem].tipoA,squadra_b[nem].tipoB);
			       break;
		    case 3:att=seleziona_pokemon(squadra_a);
				   break;
				   }
		
			if(squadra_b[nem].hp>0){
			printf("%s usa ",squadra_b[nem].nome);
			mossa(squadra_b[nem].tipoA,squadra_b[nem].spe);
			squadra_a[att].hp-=danno(squadra_b[nem].tipoA,squadra_b[nem].att,squadra_a[att].tipoA,squadra_a[att].tipoB);
			hp_squadra_a=somma_hp(squadra_a);
			if(squadra_a[att].hp<0){
				squadra_a[att].hp=0;
				printf("%s e' esausto\n\nSeleziona un nuovo pokemon\n",squadra_a[att].nome);
				if(hp_squadra_a>0){
					att=seleziona_pokemon(squadra_a);	
				}
				else{
					printf("Hai perso\n");
					printf("Premi INVIO per continuare.\n");
			     	getchar();
				    getchar();
					break;
				}				
			}
		}
		if(squadra_b[nem].hp<=0){
			squadra_b[nem].hp=0;
			printf("%s e' esausto\n\n",squadra_b[nem].nome);
			hp_squadra_b=somma_hp(squadra_b);
			if(hp_squadra_b>0){
				nem=nem+1;
				printf("%s e' entrato in campo\n\n",squadra_b[nem].nome);
			}
			else{
				printf("Hai vinto\n");
				crediti();
				printf("Premi INVIO per continuare.\n");
				getchar();
				getchar();
				break;
			}
		}
		
	}
}

int main(){
	int r;
	int cacchetta=0;
	do{
		system("cls");
		printf("Vuoi aggiungere dei pokemon al pokedex? Premi 1\nVuoi visionare il Pokedex?Premi 2\n");
		printf("Vuoi creare una nuova squadra?Premi 3\nVuoi vedere il contenuto di una squadra?Premi 4\n");
		printf("Vuoi far lottare due squadre?Premi 5\nQualunque altro tasto termina il programma.\n");
		scanf("%d",&r);
		system("cls");
		switch(r){
			case 1:agg_pokedex();
				     break;
			case 2:stampa_pokedex("pokedex.txt",num_pok());
			         break;
			case 3:crea_squadra ();
				     break;
			case 4:stampa_squadra();
				     break;
			case 5:lotta();
				   break;		 	       
			default:cacchetta=-1;
					 break;	
		}
	}while(cacchetta!=-1);
	
	
	
	
	return 0;
	
}
