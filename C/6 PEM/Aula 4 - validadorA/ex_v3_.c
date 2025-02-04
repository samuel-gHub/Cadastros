/*  
	
	* 0 Rio Grande do Sul
    * 1 Distrito Federal, Goi�s, Mato Grosso, Mato Grosso do Sul e Tocantins
    * 2 Amazonas, Par�, Roraima, Amap�, Acre e Rond�nia
    * 3 Cear�, Maranh�o e Piau�
    * 4 Para�ba, Pernambuco, Alagoas e Rio Grande do Norte
    * 5 Bahia e Sergipe
    * 6 Minas Gerais
    * 7 Rio de Janeiro e Esp�rito Santo
    * 8 S�o Paulo
    * 9 Paran� e Santa Catarina

*/


#include <stdio.h>
#include <stdbool.h>



bool todosRepetidos(int cpf[])
{
	int i;
	
	for(i = 1; i < 11; i++)
	{
		if(cpf[0] != cpf[i]) 
			return false;
	}	
	return true;
}



int calculaDigito(int cpf[], int mult[], int N)
{
	int i, soma = 0;
	
    for (i = 0; i < N; i++)
    {
        soma = soma + cpf[i] * mult[i];
    }
    
    return ((soma * 10) % 11) % 10;
}


void imprimeRegiaoOrigem(int cpf[])
{
	switch (cpf[8])
    {
    case 0:
        printf("Origem do CPF: Rio Grande do Sul");
        break;
        
    case 1:
        printf("Origem do CPF: Distrito Federal, Goi�s, Mato Grosso, Mato Grosso do Sul ou Tocantins");
        break;
        
    case 2:
        printf("Origem do CPF: Amazonas, Para, Roraima, Amapa, Acre ou Rondonia");
        break;
        
    case 3:
        printf("Origem do CPF: Ceara, Maranh�o ou Piaui");
        break;
    case 4:
        printf("Origem do CPF: Paraiba, Pernambuco, Alagoas e Rio Grande do Norte");
        break;
        
    case 5:
        printf("Origem do CPF: Bahia e Sergipe");
        break;
        
    case 6:
        printf("Origem do CPF: Minas Gerais");
        break;
        
    case 7:
        printf("Origem do CPF: Rio de Janeiro e Espirito Santo");
        break;
    
    case 8:
        printf("Origem do CPF: Sao Paulo");
        break;
        
    case 9:
        printf("Origem do CPF: Parana e Santa Catarina");
        break;
    
    default:
    	printf("Emissor invalido.");
        break;
    }
}




int main()
{
    int cpf[11];
    int m1[9] = {10, 9, 8, 7, 6, 5, 4, 3, 2};
    int m2[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    int i;
    
    printf("Entre com os 11 digitos do CPF: ");
    
    for (i = 0; i < 11; i++)
    {
        scanf("%d", &cpf[i]);
    }
    
    
    
    
    //C�lculo do primeiro d�gito verificador
    

    if (calculaDigito(cpf, m1, 9) == cpf[9] && 
	calculaDigito(cpf, m2, 10) == cpf[10] &&
	! todosRepetidos(cpf))
    {
        printf("\nCPF valido.\n");
        imprimeRegiaoOrigem(cpf);
    }
    else
    {
        printf("\nErro no CPF.");
    }


    return 0;
}
