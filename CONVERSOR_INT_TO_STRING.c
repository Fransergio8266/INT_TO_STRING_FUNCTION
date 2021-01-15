#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PROT�TIPO DE FUN��O QUE CONVERTE INTEIRO SIGNED EM STRING
void IntToStr( int num,  char * str );

int power(int base,int pot);

int main(int argc, char *argv[]) {
	int num=-54;
	char str[4];
	IntToStr( num, str );
	printf("string:%s",str);
	
	return 0;
}

int power(int base,int pot)
{
	if(pot==0)
	{
		return 1;	
	}
	else if(pot==1)
	{
		return 10;	
	}
	else if(pot>1)
	{
		unsigned short int i=0;
		unsigned int num=base;
	for(i;i<pot-1;i++)
	{
		num=num*base;
	}
	return num;
	}
}

void IntToStr( int num,  char * str )
{
	int inc=0;//VARI�VEL QUE SER� INCREMENTADA E NO FIM TER� O VALOR DE int n
	int inicio=0;//VARI�VEL QUE MARCA EM QUAL �NDICE COME�A O PRIMEIRO DIGITO DO N�MERO: SE >=0:inicio=0 E SE <0:inicio=1
	int mult=0;//VARI�VEL QUE SERVE COMO POT�NCIA DE BASE 10 PARA MARCAR A CASA DECIMAL DO D�GITO MAIS SIGNIFICATIVO DO int num
	if(num<0)
	{
		num=-num;inicio=1;//SE O ARGUMENTO int num � NEGATIVO, CALCULA-SE SEU M�DULO
	}
	while(--num>=0)
	{
		++inc;
	}
//DEPENDENDO EM QUAL FAIXA DE VALORES EST� O M�DULO DO ARGUMENTO, A POT�NCIA MULT RECEBE SEU VALOR ADEQUADO
if(inc<10)
	{mult=0;}
else if(inc<100)
	{mult=1;}
else if(inc<1000)
	{mult=2;}
else if(inc<10000)
	{mult=3;}
else if(inc<100000)
	{mult=4;}
int cont;
int num_v[mult+1+inicio];//TAMANHO DO VETOR DE INTEIROS QUE RECEBER� CADA D�GITO DO N�EMRO int num
if(inicio==0)//POVOA O VETOR DE INTEIRO E DE CHAR CASO O ARGUMENTO int num SEJA MAIOR IGUAL A ZERO
	{
	for(cont=0;cont<=mult;cont++)
	{
		num_v[cont]=inc/(power(10,mult-cont));//ATRIBUI APENAS O D�GITO MAIS SIGNIFICATIVO
		str[cont]='0'+num_v[cont];//CONVERTE D�GITO INTEIRO EM CHAR E POVOA CHAR ARRAY
		inc=inc-(num_v[cont])*(power(10,mult-cont));//EXCLUI O D�GITO MAIS SIGNIFICATIVO DO N�MERO
	}
	}

else
{ 
	for(cont=1;cont<=mult+1;cont++){//POVOA O VETOR DE INTEIRO E DE CHAR CASO O ARGUMENTO int num SEJA MENOR DO QUE ZERO
		num_v[cont]=inc/(power(10,mult-cont+1));//ATRIBUI APENAS O D�GITO MAIS SIGNIFICATIVO
		str[cont]='0'+num_v[cont];//CONVERTE D�GITO INTEIRO EM CHAR E POVOA //CHAR ARRAY
		inc=inc-(num_v[cont])*(power(10,mult-cont+1));}//EXCLUI O D�GITO MAIS //SIGNIFICATIVO DO N�MERO
}
if(inicio==1)
	{str[0]='-';}//CASO O ARGUMENTO int NUM SEJA MENOR DO //QUE ZERO, INSERE O CARACTER '-' NA PRIMEIRA POSSI��O DO ARRAY DE CARACTERES 
str[cont]='\0'; //TRANSFORMA ARRAY DE CARACTERES EM STRING
}
