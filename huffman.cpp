  /*
Alunos: MATHEUS ALEXANDRE	-	RA 181441
		LEONEL SOLANO		-	RA 181127
*/

  
  
  #include<bits/stdc++.h>
  using namespace std;

  //N� da arvore de huffman
  struct MinHeapNode{
      char dados;
      int freq;

      MinHeapNode *esq,*dir;

      MinHeapNode(char dados,int freq){
          esq=dir=NULL;
          this->dados=dados;
          this->freq=freq;
     }
};

//Compara��o entre os n�s
struct compara{

    bool operator()(MinHeapNode *l,MinHeapNode *r)
    {
        return (l->freq>r->freq);
    }
};

// Printa os c�digos de huffman
void printCodHuff(struct MinHeapNode* raiz,string str){
   //Se a ra�z � nula ele retorna
   if(!raiz){
       return;
   }
   //Se o dado dentro do n� n�o � "$", significa que n�o � um n� interno, printando a string.
   if(raiz->dados!='$'){
       cout<<raiz->dados<<": "<<str<<endl;
   }

   printCodHuff(raiz->esq,str+"0");
   printCodHuff(raiz->dir,str+"1");
}

//Constru��o da �rvore de huffman
void HuffmanCodigo(char dados[],int freq[],int size){

struct MinHeapNode *esq,*dir,*top;

//Cria o heap min.
priority_queue<MinHeapNode*,vector<MinHeapNode*>,compara> minheap;

// Para cada caracter, cria um n� folha e insere cada n� folha dentro do heap
for(int i=0;i<size;i++){
    minheap.push(new MinHeapNode(dados[i],freq[i]));
 }

 //Enquanto o tamanho for diferente de 1
 while(minheap.size()!=1){
     //Extrai os 2 valores do heap.
     esq = minheap.top();
     minheap.pop();

     dir = minheap.top();
     minheap.pop();

     // Cria um n� inteiro com frequencia igual � soma de ambos os n�s extra�dos.
     // Atribui '$' para ese n� e faz dos 2 n�s extraidos os filhos esquerdo e 
     // direito desse novo n�. Adiciona esse n� ao heap

     top = new MinHeapNode('$',esq->freq+dir->freq);
     top->esq = esq;
     top->dir = dir;

     minheap.push(top);
 }
 //Chama a fun��o para printar o c�digo
 printCodHuff(minheap.top()," ");
}

int main(){

// trocar valores para criar sua tabela

  char arr[] = {'H','F','V','Z','R'};
  int freq[] = {22,13,42,6,3};

  int size=5;
  for(int i=0; i<5; i++){
    cout << "Valor: " << arr[i] << "\tFrequencia: " << freq[i] << "\n";
  }
  
  cout << "\n----- TABELA BIN�RIA ----- \n\n";
  HuffmanCodigo(arr,freq,size);

return 0;
}
