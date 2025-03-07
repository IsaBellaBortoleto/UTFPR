#include "trie.h"

/*  */
Trie* create_node(char data) {
	Trie* node = (Trie*)malloc(sizeof(Trie));
	node->data = data;
	node->end = FALSE;
	node->nchild = 0;
	int i;
	//size is the alphabet size 
	for (i = 0; i < size; i++) {
		node->keys[i] = NULL;
	}
	return node;
}

/* */
void free_node(Trie* node) {
	int i;
	for (i = 0; i < size; i++) {
		if (node->keys[i] != NULL) {
			free_node(node->keys[i]);
		}
	}
	free(node);
}

/* */
Trie* insert(Trie* root, char* word) {
	//printf("\nImplementar a inserção\n");
	if (search_auxiliary(root, word)) {
		printf("Error: already inserted\n");
		return root;
	}
	Trie* t = root;

	for (int i = 0; word[i] != '\0'; i++)
	{
		int index = word[i] - 'a';
		if (t->keys[index] == NULL)
			t->keys[index] = create_node(word[i]);
		t->nchild += 1;
		t = t->keys[index];
	}
	t->end = TRUE;
	return root;
}

/* */
int search_auxiliary(Trie* root, char* word) {
	//printf("\nImplementar a busca\n");
	Trie* t = root;
	for (int i = 0; word[i] != '\0'; i++)
	{
		int index = word[i] - 'a';
		if (t->keys[index] == NULL)
			return FALSE;
		else
			t = t->keys[index];

	}
	if (t->end)
		return TRUE;
	else
		return FALSE;
}

void search(Trie* root, char* word) {
	if (search_auxiliary(root, word))
		printf("Word %s found!\n", word);
	else
		printf("Error: word %s not found!\n", word);
}

/* */
void print(Trie* root, int level) {
	if (root != NULL) {
		int i;
		if (root->data == '\0')
			printf("(null)");
		for (i = 0; i < level; i++) {
			printf("| ");
		}
		printf("%c (%d - %d)\n", root->data, root->end, root->nchild);
		for (i = 0; i < size; i++) {
			print(root->keys[i], level + 1);
		}
	}
}

void delete (Trie* root, char* word) {
	if (!search_auxiliary(root, word)) {
		printf("Essa chave nao existe\n");
		return;
	}
	else
	{
		Trie* t = root;
		Trie* checkpoint  = root;
		int check_index;
		for(int i= 0;word[i]!='\0';i++)
		{
			int index = word[i] - 'a';
			t->nchild = t->nchild-1;
			if ((t->nchild >= 1 && t->end)||(t->nchild >= 2 && !t->end)) {
				checkpoint = t;
				if(word[i+1]!='\0') //se nao for o final da palavra
					check_index = (int)word[i+1] - 'a';
			}
			if (t->nchild > 0)
				t->end = FALSE;
			else{
				free(checkpoint->keys[check_index]);
				checkpoint->keys[check_index] = NULL;
			}
		}
	}	

}