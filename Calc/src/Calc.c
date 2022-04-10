#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	double *a,*b,*r;
	//a,b-Хранят введенные числа
	char op;//хранит знак операции
	printf("list of available operations :\n +  addition \n - subtraction \n * multiplication \n / division \n ! factorial (of n1) \n e n1 to the power of n2 \n");
	printf("Vector operations:\n 1 vector addition \n 2 vector subtraction \n 3 scalar multiplication \n");
	//список доступных пользователю операций,символ в начале строки вводим при запросе выбора операции
	r = malloc(sizeof(double));
	do
	{
		printf("choose vector(V) or non-vector operators(N) \n");
		scanf(" %c", &op);
		r = malloc(sizeof(double));
		if(op == 'N')
		{
			a = malloc(sizeof(double));
			b = malloc(sizeof(double));
			printf("select the operator \n");
			scanf(" %c", &op);
			printf("enter first number \n");
			scanf("%lf", &a[0]);
			//Считываем число 2 внутри Switch по причине того, что в некоторых операциях, например при вычислении факториала второе число не нужно
			switch(op)
						{
						    case '+':
								    printf("enter second number \n");
								    scanf("%lf", &b[0]);
								    printf("%lf \n",a[0]+b[0]);
								    break;
						    case '-':
						    	    printf("enter second number \n");
						    		scanf("%lf", &b[0]);
						    		printf("%lf \n",a[0]-b[0]);
						    		break;
						    case '*':
						    	    printf("enter second number \n");
						    	    scanf("%lf", &b[0]);
						    	    printf("%lf \n",a[0]*b[0]);
						    	    break;
						    case '/':
						    	    printf("enter second number \n");
						    		scanf("%lf", &b[0]);
						    		printf("%lf \n",a[0]/b[0]);
						    		break;
						    case 'e':
						    		printf("enter second number \n");
						    		scanf("%lf", &b[0]);
						    		r[0] = a[0];
						    		//проверка на целость a и b
						    		do
						    		{
						    			r[0] = r[0] - 1;

						    		}while(!(r[0] < 1));
						    		if(r[0] == 0)//если a-целое, то:
						    		{
						    			//printf("%lf \n",r[0]);
						    			r[0] = b[0];
						    			do
						    			{
						    				r[0]=r[0] - 1;
						    			}while(!(r[0] < 1));
						    			if(r[0] == 0)//если b-целое, то:
						    			{
						    				r[0] = a[0];
						    				for(float i = 1; i<b[0];i++)
						    				{
						    					r[0]=r[0]*a[0];
						    				}
						    				printf("%lf \n",r[0]);
						    			}
						    		}
						    		else
						    		{
						    			printf("operation requires integer numbers \n");
						    		}
						    		break;
						    case '!'://здесь незадействованную b использую как счетчик для результата
						    	    b[0] = 1;
						    	    for(int i = 1;i <= a[0];i++)
						    		{
						    		    b[0] = b[0]*i;;
						    		}
						    		printf("%lf \n",b[0]);
						    		break;
						    default:
						    		printf("no such operation is available \n");
						}
		}
		else if(op == 'V')
		{
			printf("enter vector length \n");
			scanf("%lf", &r[0]);
			a = malloc(r[0]*sizeof(double));
			b = malloc(r[0]*sizeof(double));
			for(int i = 0; i < r[0]; i++)
			{
				printf("enter digit number %i from vector 1 \n", i);
				scanf("%lf", a+i);
				//printf("%lf \n", a[i]);
			}
			for(int i = 0; i < r[0]; i++)
			{
				printf("enter digit number %i from vector 2 \n", i);
			    scanf("%lf", b+i);
				//printf("%lf \n", b[i]);
			}
			printf("select the operator \n");
			scanf(" %c", &op);
			switch(op)
			{
			case '1': //векторная сумма
				for(int i = 0; i < r[0]; i++)
							{
								a[i] = a[i]+b[i];//на время выполнения операции храню результаты в *а,все равно потом ее очищать
								printf("%lf \n", a[i]);
							}
				break;
			case '2': //векторная разность
				for(int i = 0; i < r[0]; i++)
							{
								a[i] = a[i]-b[i];//на время выполнения операции храню результаты в *а,все равно потом ее очищать
								printf("%lf \n", a[i]);
							}
				break;
			case '3': //скалярное произведение
				for(int i = 0; i < r[0]; i++)
							{
								a[i] = a[i]*b[i];//на время выполнения операции храню результаты в *а,все равно потом ее очищать
								printf("%lf \n", a[i]);
							}
				break;
			default:
				printf("no such operation is available \n");
				break;
			}
		free(a);
		free(b);
		free(r);
		}
		else
		{
			printf("no such option available \n");
		}
		printf("do you wish to do another operation?(Y) \n");//Завершит цикл работы калькулятора
		scanf(" %c", &op);                                   //при вводе любого символа кроме 'Y'
	}while(op == 'Y');                                       //Вложил в переменную водящую в знак
	                                                         //Т.к. на этом этапе работы она уже не используется

	return EXIT_SUCCESS;
}
