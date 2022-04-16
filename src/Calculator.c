#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	double *a,*b,*r;
	//a,b-Хранят введенные числа
	//r-Длина вектора в векторных операциях, а так же буфер для некоторых операций в которых он необходим
	char op,vs;//op-хранит знак операции,vs-векторные/скалярные операции
	char fname1[100],fname2[100];


	int ch;//проверка на конец файла
	FILE *fin,*fout;

	/*fin = fopen("Input.txt","r");
	fout = fopen("Output.txt","w");*/
	do
	{

		printf("please enter the name of the input file \n");
		scanf("%s", fname1);
		printf("%s \n", fname1);

		//fin=fopen("Input.txt","r");
		fin=fopen(fname1,"r");
		printf("please enter the name of the output file \n");
		scanf("%s", fname2);
		printf("%s \n", fname2);

		//fout=fopen("Output1.txt","w");
	    fout=fopen(fname2,"w");
		if(fin == NULL)
		{
			printf("An error has occured when opening the input file \n");
		}
		else
		{
			if(fout == NULL)
			{
				printf("An error has occured when opening the output file \n");
				//printf("An error has occured when opening the file \n");
			}
			else
			{
				do
											{
												//printf("Введите имя файла для ввода");
												//scanf("");
												fscanf(fin,"%c ", &op);
												fscanf(fin,"%c ", &vs);
												r = malloc(sizeof(double));
												if(vs == 's')
												{
													a = malloc(sizeof(double));
													b = malloc(sizeof(double));
													fprintf(fout,"( ");
													fscanf(fin,"%lf ", &a[0]);
													fprintf(fout,"%lf ", a[0]);
													//Считываем число 2 внутри Switch по причине того, что в некоторых операциях, например при вычислении факториала второе число не нужно
													switch(op)
																{
																    case '+':
																		    //fprintf(fout,"enter second number \n");
																    	    fprintf(fout,"%c ", op);
																		    fscanf(fin,"%lf", &b[0]);
																		    fprintf(fout,"%lf ", b[0]);
																		    fprintf(fout,") ");
																		    fprintf(fout," = ( %lf )\n",a[0]+b[0]);
																		    break;
																    case '-':
																    	    //fprintf(fout,"enter second number \n");
																    	    fprintf(fout,"%c ", op);
																    		fscanf(fin,"%lf", &b[0]);
																    		fprintf(fout,"%lf ", b[0]);
																    		fprintf(fout,") ");
																    		fprintf(fout," = ( %lf )\n",a[0]-b[0]);
																    		break;
																    case '*':
																    	    //fprintf(fout,"enter second number \n")
																    	    fprintf(fout,"%c ", op);
																    	    fscanf(fin,"%lf", &b[0]);
																    	    fprintf(fout,"%lf ", b[0]);
																    	    fprintf(fout,") ");
																    	    fprintf(fout," = ( %lf )\n",a[0]*b[0]);
																    	    break;
																    case '/':
																    	    //fprintf(fout,"enter second number \n");
																    	    fprintf(fout,"%c ", op);
																    		fscanf(fin,"%lf", &b[0]);
																    		fprintf(fout,"%lf ", b[0]);
																    		fprintf(fout,") ");
																    		fprintf(fout," = ( %lf )\n",a[0]/b[0]);
																    		break;
																    case 'e':
																    		//fprintf(fout,"enter second number \n");
																    	    fprintf(fout,"%c ", op);
																    		fscanf(fin,"%lf", &b[0]);
																    		fprintf(fout,"%lf ", b[0]);
																    		fprintf(fout,") ");
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
																    				fprintf(fout," = ( %lf ) \n",r[0]);
																    			}
																    		}
																    		else
																    		{
																    			fprintf(fout,"operation requires integer numbers \n");
																    		}
																    		break;
																    case '!'://здесь незадействованную b использую как счетчик для результата
																    	    fprintf(fout,"%c ", op);
																    	    b[0] = 1;
																    	    for(int i = 1;i <= a[0];i++)
																    		{
																    		    b[0] = b[0]*i;;
																    		}
																    		fprintf(fout,"( %lf )\n",b[0]);
																    		break;
																    default:
																    		fprintf(fout,"no such scalar operation is available \n");
																}
												}
												else if(vs == 'v')
												{
													fscanf(fin," %lf", &r[0]);
													a = malloc(r[0]*sizeof(double));
													b = malloc(r[0]*sizeof(double));
													fprintf(fout,"( ");
													for(int i = 0; i < r[0]; i++)
													{
														fscanf(fin," %lf", a+i);
														fprintf(fout,"%lf ", a[i]);
													}
													fprintf(fout,") ");
													fprintf(fout,"%c ", op);
													fprintf(fout,"( ");
													for(int i = 0; i < r[0]; i++)
													{
													    fscanf(fin," %lf", b+i);
													    fprintf(fout,"%lf ", b[i]);
													}
													fprintf(fout,") ");
													fprintf(fout,"= ");
													fprintf(fout,"( ");
													switch(op)
													{
													case '+': //векторная сумма
														for(int i = 0; i < r[0]; i++)
																	{
																		a[i] = a[i]+b[i];//на время выполнения операции храню результаты в *а,все равно потом ее очищать
																		fprintf(fout,"%lf ", a[i]);
																	}
														break;
													case '-': //векторная разность
														for(int i = 0; i < r[0]; i++)
																	{
																		a[i] = a[i]-b[i];//на время выполнения операции храню результаты в *а,все равно потом ее очищать
																		fprintf(fout,"%lf ", a[i]);
																	}
														break;
													case '*': //скалярное произведение
														for(int i = 0; i < r[0]; i++)
																	{
																		a[i] = a[i]*b[i];//на время выполнения операции храню результаты в *а,все равно потом ее очищать
																		fprintf(fout,"%lf ", a[i]);
																	}
														break;
													default:
														fprintf(fout,"no such vector operation is available \n");
														break;
													}
													fprintf(fout,") \n");
												free(a);
												free(b);
												free(r);
												}
												else
												{
													fprintf(fout,"no such option available \n");
												}

												//fscanf(fin,"\n%c", &op);
												//fprintf(fin,"%c", &op);
												//fprintf(fout,"do you wish to do another operation?(Y) \n");//Завершит цикл работы калькулятора
												//при вводе любого символа кроме 'Y'
											    //Вложил в переменную водящую в знак
											    //Т.к. на этом этапе работы она уже не используется
											}while(( ch = fgetc( fin ) ) != EOF);
			}

	}
		fclose(fin);//Файлы закрываю в конце цикла считывания цикла имени файла,т.к. открывать их в самом начале
		fclose(fout);
		printf("do you want to run another file? (Y) \n");//При вводе Y повторит цикл ввода/обработки файла
		scanf(" %c", &op);
	}while(op == 'Y');

	return EXIT_SUCCESS;
}
