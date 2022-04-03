#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	double a,b,r;
	//a,b-Хранят введенные числа
	char op;//хранит знак операции
	printf("list of available operations :\n+  addition \n - subtraction \n * multiplication \n / division \n ! factorial (of n1) \n e n1 to the power of n2 \n");
	//список доступных пользователю операций,символ в начале строки вводим при запросе выбора операции
	do
	{
		printf("enter first number \n");
		//Считываем число 2 внутри Switch по причине того, что в некоторых операциях, например при вычислении факториала второе число не нужно
	    scanf("%lf", &a);
		printf("select the operator \n");
		scanf(" %c", &op);
		switch(op)
			{
			    case '+':
					    printf("enter second number \n");
					    scanf("%lf", &b);
					    printf("%lf \n",a+b);
					    break;
			    case '-':
			    	    printf("enter second number \n");
			    		scanf("%lf", &b);
			    		printf("%lf \n",a-b);
			    		break;
			    case '*':
			    	    printf("enter second number \n");
			    	    scanf("%lf", &b);
			    	    printf("%lf \n",a*b);
			    	    break;
			    case '/':
			    	    printf("enter second number \n");
			    		scanf("%lf", &b);
			    		printf("%lf \n",a/b);
			    		break;
			    case 'e':
			    		printf("enter second number \n");
			    		scanf("%lf", &b);
			    		r = a;
			    		//проверка на целость a и b
			    		do
			    		{
			    			r=--r;
			    		}while(!(r < 1));
			    		if(r == 0)//если a-целое, то:
			    		{
			    			//printf("%lf \n",a);
			    			r = b;
			    			do
			    			{
			    				r=--r;
			    			}while(!(r < 1));
			    			if(r == 0)//если b-целое, то:
			    			{
			    				r = a;
			    				for(float i = 1; i<b;i++)
			    				{
			    					r=r*a;
			    				}
			    				printf("%lf \n",r);
			    			}
			    		}
			    		break;
			    case '!'://здесь незадействованную b использую как счетчик для результата
			    	    b = 1;
			    	    for(int i = 1;i <= a;i++)
			    		{
			    		    b = b*i;;
			    		}
			    		printf("%lf \n",b);
			    		break;
			    default:
			    		printf("no such operation is available \n");
			}
		    printf("do you wish to do another operation?(Y) \n");//Завершит цикл работы калькулятора
			scanf(" %c", &op);                                     //при вводе любого символа кроме 'Y'
	}while(op == 'Y');                                             //Вложил в переменную водящую в знак
	                                                               //Т.к. на этом этапе работы она уже не используется

	return EXIT_SUCCESS;
}


/*
do
{
	switch(op)
	{
	   case '+':
		    printf("enter second number");
		    scanf("%Lf",b);
		    printf("%Lf",a+b);
		    break;
	   case '-':
		    printf("enter second number");
		   	scanf("%Lf",b);
		   	printf("%Lf",a-b);
	   	    break;
	   case '*':
		    printf("enter second number");
		   	scanf("%Lf",b);
		   	printf("%Lf",a*b);
	   		break;
	   case '/':
		    printf("enter second number");
		   	scanf("%Lf",b);
		   	printf("%Lf",a/b);
	   		break;
	   case '!':
		    b = 1;
		    for(int i = 1;i<a;i++)
		    {
		    	b=b*i;
		    }
	   		printf("%Lf",b);
	   		break;
	   case '^':
		    printf("enter second number");
		   	scanf("%If",b);
		    buffer = 1;
		    for(int i = 1;i<a;i++)
		    {
		    	buffer=buffer*a;
		    }
		   	printf("%Lf",buffer);
	   		break;
	   default:
		    printf("невозможно выполнить операцию");
	}
	printf("повторное выполнение?Y/N");
	scanf(" %c", op);
}while(op == 'Y');*/
