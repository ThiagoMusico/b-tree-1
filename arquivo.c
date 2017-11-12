#include "arquivo.h"


// Tem que verificar se o arquivo de índice já existe Miss
void criarIndice(Arvore* A){
	A->raiz = NULL;
}

int regVariavel(Registro r, char *buffer){

	// Imprime no buffer os dados do registro, formatados da maneira necessária
	sprintf(buffer, "%d|%s|%s|", r.id, r.titulo, r.genero);
	return strlen(buffer);
}

char *separaCampos(char *buffer, int *p) {
    int pos = *p;

    // Troca todos os '|' por '\0' e permite que tenhamos acesso individual a cada campo
    while(buffer[*p]!='|')
        (*p)++;
    buffer[*p] = '\0';
    (*p)++;
    return &buffer[pos];
}

vvoid InserirMusica(int id, char titulo[30], char genero[20], FILE *dados, int *tamTitulo, int *tamGenero){

	// Parte do código responsável por inserir a música no arquivo de dados
	Registro *r = malloc(sizeof(Registro)); // Aloca um novo registro

	// Salva as varíaveis passadas como parâmetro no registro
	r->id = id;
	strcpy(r->titulo, titulo);
	strcpy(r->genero, genero);

	// Variáveis para identificar o real tamanho das strings
	*tamTitulo = strlen(r->titulo);
	*tamGenero = strlen(r->genero);

	// Aloca no buffer os dados do registro
	char buffer[200];
	int size = regVariavel(*r, buffer);

	fwrite(&size, sizeof(int), 1, dados);	// Escreve o tamanho do registro no começo dele
	fwrite(&buffer, sizeof(buffer), 1, dados);	// Escreve o buffer (os dados formatados do registro)

	// Parte do código responsável por atualizar o índice
	if(A->raiz == NULL){
		Pagina p = (Pagina*) malloc(sizeof(Pagina));
		A->raiz = p;
		p->folha = 0;
		p->numChaves = 1;
		p->chaves[0] = id;
		p->byteoffset[0] = 0;	
	}

	free(r);

}

int pesquisaMusicaID(int id){

}

void removeMusicaID(){

}

void mostraArvoreB(){
	
}

int caractereValido(char *string){
	int i, comp;
	comp = strlen((string));
	for(i = 0; i < comp; i++){
		if(*string[i] < 65 || (*string[i] > 90 && *string[i] < 97) || *string[i] > 122){
			return 0;
		}
	}
	return 1;

}