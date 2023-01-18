  /*
Alunos: MATHEUS ALEXANDRE	-	RA 181441
		LEONEL SOLANO		-	RA 181127
*/

  
  
  #include<bits/stdc++.h>
  using namespace std;

  //Nó da arvore de huffman
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

//Comparação entre os nós
struct compara{

    bool operator()(MinHeapNode *l,MinHeapNode *r)
    {
        return (l->freq>r->freq);
    }
};

// Printa os códigos de huffman
void printCodHuff(struct MinHeapNode* raiz,string str){
   //Se a raíz é nula ele retorna
   if(!raiz){
       return;
   }
   //Se o dado dentro do nó não é "$", significa que não é um nó interno, printando a string.
   if(raiz->dados!='$'){
       cout<<raiz->dados<<": "<<str<<endl;
   }

   printCodHuff(raiz->esq,str+"0");
   printCodHuff(raiz->dir,str+"1");
}

//Construção da árvore de huffman
void HuffmanCodigo(char dados[],int freq[],int size){

struct MinHeapNode *esq,*dir,*top;

//Cria o heap min.
priority_queue<MinHeapNode*,vector<MinHeapNode*>,compara> minheap;

// Para cada caracter, cria um nó folha e insere cada nó folha dentro do heap
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

     // Cria um nó inteiro com frequencia igual à soma de ambos os nós extraídos.
     // Atribui '$' para ese nó e faz dos 2 nós extraidos os filhos esquerdo e 
     // direito desse novo nó. Adiciona esse nó ao heap

     top = new MinHeapNode('$',esq->freq+dir->freq);
     top->esq = esq;
     top->dir = dir;

     minheap.push(top);
 }
 //Chama a função para printar o código
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
  
  cout << "\n----- TABELA BINÁRIA ----- \n\n";
  HuffmanCodigo(arr,freq,size);

return 0;
}
