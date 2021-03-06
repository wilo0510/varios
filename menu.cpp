#include <iostream>
using namespace std;
class Cubeta
{
	int tamanio;
	int *elemento;
	};

class Arreglo {
	int tamanio;
	int *elemento;
	
	public:
		Arreglo(int);
		int busquedaSecuencial(int);
		int busquedaBinariaI(int);
		int buscarBinarioR(int,int,int);
		void mostrar();
		void cargar();
		int burbuja();
		int insercion();
		int shellsort();	
		void merge(int*,int*,int,int,int);
		void mergesort(int *a, int*b, int low, int high);
		void quicksort(int A[] ,int b,int c);	
		void operator=(Arreglo);
};

Arreglo::Arreglo(int tamanio){
	this->tamanio=tamanio;
	elemento=new int[tamanio];
}
void Arreglo::cargar(){	
		
		int num;
		for (int i=0;i<tamanio;i++){
			cout<<"Ingresa el elemento "<<i+1<<" : ";
			cin>>num;
			elemento[i]=num;
		}
		
}
int Arreglo::busquedaBinariaI(int numeroBusqueda)
{
	int operacion=0;
	int primero = 0;
    int mitad;
    int ultimo = tamanio - 1;
 	
    while (primero <= ultimo) {
        mitad = (primero + ultimo) / 2;
		operacion++;
        if (numeroBusqueda == elemento[mitad]) {
            cout << "Se encuentra en la posicion " << mitad + 1 << endl;
            
			primero=ultimo+1;//para que se acabe el while
        } else {
            if (elemento[mitad] > numeroBusqueda) {
                ultimo = mitad - 1;
            } else {
            	if(elemento[mitad] < numeroBusqueda)
            	{
                	primero = mitad + 1;
                }
                
            }
        }
        if(primero==ultimo)
        {
        	cout<<"No se encontro el dato en el arreglo \n";
		}
        
        
    }
    
    
	return operacion;
 } 
int Arreglo::busquedaSecuencial(int numeroBusqueda)
{
	int i=0,aux=0,operacion=0;
	do
	{
		operacion++;
		if(elemento[i]==numeroBusqueda)
		{
			cout<<"El elemento se encuentra ubicado en la posicion "<<i+1<<" del arreglo \n";
			aux=1;
		}
		i++;
	}while(aux==0 && i<tamanio);
	if(aux==0)
	{
	cout<<"No se encontro el elemento en el arreglo \n";	
	}
	return operacion;
	
 } 
int Arreglo::burbuja(){
int i, j,aux,op=0;
for (i=0;i<tamanio-1;i++)
	for (j=i+1;j<tamanio;j++){	
	op++;	
		if (elemento[i]>elemento[j]){
			aux=elemento[i];
			elemento[i]=elemento[j];
			elemento[j]=aux;	
}
		}
		return op;
}



int Arreglo::insercion(){
	int aux,a,op=0;
	for (int k=1;k<tamanio;k++){
		aux=elemento[k];
		a=k-1;
		op++;
		while (a>=0 && elemento [a]>aux){
			elemento[a+1]=elemento[a];
			a--;
			if (a>=0)
			op++;
		}
		elemento[a+1]=aux;
			
	}
return op;
}

int Arreglo::shellsort()
{
	int j;
	int op=0;
	for (int gap = tamanio / 2; gap > 0; gap /= 2)
	{
		cout << "divisor : " << gap << endl;
		for (int i = gap; i < tamanio; ++i)
		{
			int temp = elemento[i];
			op++;
			for (j = i; j >= gap && temp < elemento[j - gap]; j -= gap)
			{
				cout << endl << "Cambiar elemento " << elemento[j - gap] << " por " << elemento[j] << endl;
				elemento[j] = elemento[j - gap];
			}
			elemento[j] = temp;
			op++;
		}
	}
	return op;
}
void Arreglo::merge(int *a, int *b, int low, int pivot, int high)
{
    int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;
 
    while((h<=pivot)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>pivot)
    {
        for(k=j; k<=high; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=pivot; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];
}
void Arreglo::mergesort(int *a, int*b, int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=(low+high)/2;
        mergesort(a,b,low,pivot);
        mergesort(a,b,pivot+1,high);
        merge(a,b,low,pivot,high);
    }
}
void Arreglo::quicksort(int A[],int izq, int der )
{ 
int i, j, x , aux; 
i = izq; 
j = der; 
x = A[(izq + der) /2]; 
    do{ 
        while( (A[i] < x) && (j <= der) )
        { 
            i++;
        } 
 
        while( (x < A[j]) && (j > izq) )
        { 
            j--;
        } 
 
        if( i <= j )
        { 
            aux = A[i]; A[i] = A[j]; A[j] = aux; 
            i++;  j--; 
        }
         
    }while( i <= j ); 
 
    if( izq < j ) 
        quicksort( A, izq, j ); 
    if( i < der ) 
        quicksort( A, i, der ); 
}


void Arreglo::mostrar(){
	cout<<"El arreglo es: ";
	for (int j=0;j<tamanio;j++)
		if (j<tamanio-1)
		cout<<elemento[j]<<"-";
		else 
		cout<<elemento[j];
	cout<<"\n";	
}

void Arreglo::operator= (Arreglo A){
	this->tamanio=A.tamanio;
	for (int k=0;k<tamanio;k++)
		elemento[k]=A.elemento[k];
	
	
}
int Arreglo::buscarBinarioR(int izq,int der,int numeroBusqueda) 
{ 
		int op=0;
	//se encuentra la mitad del vector o intervalo 
	int mitad =(int)((izq+der)/2);
	//se verifica si el numero no esta en el arreglo
	op++;
	if((izq==der && elemento[mitad]!=numeroBusqueda) || elemento[der]<numeroBusqueda || elemento[izq]>numeroBusqueda)
	{
		cout<<"No se encuentra el dato en el arreglo \n";
		return op;
	}
	//caso-base de la recursividad -cuando se encuentra el dato buscado en el arreglo
	op++;
	if(elemento[mitad] == numeroBusqueda)
	{
		cout<<"El dato se encuentra en la posicion "<<mitad<<"\n";
		return op;
	}
	else
	{
		//verifica si el dato esta a la izquierda
		if(elemento[mitad]>numeroBusqueda)
		{
			return buscarBinarioR( izq , mitad-1 , numeroBusqueda);
		}else{
			return buscarBinarioR( mitad+1 , der ,numeroBusqueda);
		}
	}
	
} 

int main (){
	int n,validacionArreglo=0,numeroBuscado;
	char opcion,opcionBuscar,opcionOrdenar;
	 
	cout<<"--Bienvenido"<<"\n";
	cout <<"De que tamanio es el arreglo?\n";
	cin>>n;	
	Arreglo A(n),B(n),copia(n);
	do{
	
	
	cout<<"\t\t\tQue desea hacer con el arreglo?: \n\n";
    cout<<"(C)argar\n";
    cout<<"(M)ostrar\n";
    cout<<"(B)uscar\n";
    cout<<"(O)rdenar\n";
    cout<<"(T)erminar\n";
    cin>>opcion;
 
switch(opcion)
{
case 'C':
	A.cargar();
	B=A;
	validacionArreglo=1;
	break;
case 'M':
	if(validacionArreglo!=0)
	B.mostrar();
	else
	cout<<"POR FAVOR CARGUE PRIMERO EL ARREGLO\n";
	break;
case 'B':
	if(validacionArreglo!=0)
	{
	
		do{
		
		cout<<"\t\t\tComo desea buscar el dato ? \n\n";
	    cout<<"(S)ecuencial\n";
	    cout<<"Binario (I)terativo\n";
	    cout<<"(B)inario Recursivo\n";
	    cout<<"(R)egresar\n";
	    cin>>opcionBuscar;
	    switch(opcionBuscar)
	    {
	    	case 'S':
	    		cout<<"POR FAVOR INGRESE EL DATO A BUSCAR EN EL ARREGLO: \n";
				cin>>numeroBuscado;
				cout<<"En la Busqueda Secuencial se realizaron "<<B.busquedaSecuencial(numeroBuscado)<<" operaciones fundamentales \n";
	    		break;
	    	case 'I':
	    		copia=B;
	    		copia.burbuja();
	    		cout<<"POR FAVOR INGRESE EL DATO A BUSCAR EN EL ARREGLO: \n";
				cin>>numeroBuscado;
				cout<<"En la Busqueda Binaria se realizaron "<<copia.busquedaBinariaI(numeroBuscado)<<" operaciones fundamentales \n";
	    		break;
	    	case 'B':
	    		copia=B;
	    		copia.burbuja();
	    		cout<<"POR FAVOR INGRESE EL DATO A BUSCAR EN EL ARREGLO: \n";
				cin>>numeroBuscado;
				cout<<"En la Busqueda Binaria se realizaron "<<copia.buscarBinarioR(0,n,numeroBuscado)<<" operaciones fundamentales \n";
	    		break;
	    	case 'R':
	    		break;
	    	default: cout<<"El valor ingresado no esta en el menu"<<endl;
		}
	    
		}while(opcionBuscar!='R');
	}
	else
	cout<<"POR FAVOR CARGUE PRIMERO EL ARREGLO"<<"\n";

		break;
	case 'O':
		do{
		
		cout<<"\t\t\tComo desea organizar el vector ? \n\n";
	    cout<<"(B)urbuja\n";
	    cout<<"(I)nsercion\n";
	    cout<<"(S)hell\n";
	    cout<<"(Q)uicksort\n";
	    cout<<"(M)ergesort\n";
	    cout<<"(C)ubetas\n";
	    cout<<"(R)egresar\n";
	    cin>>opcionOrdenar;
	    switch(opcionOrdenar)
	    {
	    	case 'B':
			int operaciones =B.burbuja();
			cout <<"METODO BURBUJA"<<"\n \n";
			B.mostrar();
			cout <<"cantidad de operaciones realizadas en burbuja "<<operaciones<<"\n \n";
			B=A;
			break;
			
			case 'I':
			cout <<"METODO INSERCION"<<"\n \n";
			int operaciones =B.insercion();
			B.mostrar(); 
			cout <<"cantidad de operaciones realizadas en Insercion "<<operaciones<<"\n \n";
			B=A;
			break;
			
			case 'S':
			cout <<"METODO SHELL"<<"\n \n";
			int operaciones =B.shellsort();
			B.mostrar();
			cout <<"cantidad de operaciones realizadas en Shell "<<operaciones<<"\n \n";
			B=A;	
			break;

			case 'Q':
			cout <<"METODO QUICK SORT"<<"\n \n";
			//quicksort(B,0,n-1);
			B=A;	
			break;

			case 'M':
			cout <<"METODO MERGE SORT"<<"\n \n";
			int num;
			num = sizeof(A)/sizeof(int);
			cout<<num;
			B=A;	
			break;
	    	
	    	default: cout<<"El valor ingresado no esta en el menu"<<endl;
		}
	    
		}while(opcionOrdenar!='R');
		break;
		
default: cout<<"El valor ingresado no esta en el menu"<<endl;
}


}while (opcion!='T');

}
