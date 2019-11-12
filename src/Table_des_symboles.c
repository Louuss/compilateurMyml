
/*#include "Table_des_symboles.h"

#include <stdlib.h>
#include <stdio.h>

// The storage structure is implemented as a linked chain //

// linked element def //

typedef struct elem {
	sid symbol_name;
	symb_value_type symbol_value;
	struct elem * next;
} elem;

// linked chain initial element //
static elem * storage=NULL;

// get the symbol value of symb_id from the symbol table //
symb_value_type get_symbol_value(sid symb_id) {
	elem * tracker=storage;

	// look into the linked list for the symbol value //
	while (tracker) {
		if (tracker -> symbol_name == symb_id) return tracker -> symbol_value;
		tracker = tracker -> next;
	}

	// if not found does cause an error //
	fprintf(stderr,"Error : symbol %s have no defined value\n",(char *) symb_id);
	exit(-1);
};

// set the value of symbol symb_id to value //
symb_value_type set_symbol_value(sid symb_id,symb_value_type value) {

	elem * tracker;

	// (optionnal) check that sid is valid symbol name and exit error if not //
	if (! sid_valid(symb_id)) {
		fprintf(stderr,"Error : symbol id %p is not have no valid sid\n",symb_id);
		exit(-1);
	}

	// look for the presence of symb_id in storage //

	tracker = storage;
	while (tracker) {
		if (tracker -> symbol_name == symb_id) {
			tracker -> symbol_value = value;
			return tracker -> symbol_value;
		}
		tracker = tracker -> next;
	}

	// otherwise insert it at head of storage with proper value //

	tracker = malloc(sizeof(elem));
	tracker -> symbol_name = symb_id;
	tracker -> symbol_value = value;
	tracker -> next = storage;
	storage = tracker;
	return storage -> symbol_value;
}


*/


#include "Table_des_symboles.h"

#include <stdlib.h>
#include <stdio.h>

// The storage structure is implemented as a linked chain //

// linked element def //





typedef struct elem {
	sid symbol_name;
	int reg_id;
	symb_value_type symbol_value;
	struct elem * next;
} elem;

typedef struct storage {
	struct storage* prev;
 	struct storage* next;
	elem* item;
} storage;

// linked chain initial element //
//static elem * storage=NULL;

static storage * stor = NULL;


void moreStorage()
{
	storage* s = malloc(sizeof(storage));

	s->prev = stor ;
	s->next = NULL ;
	s->item = NULL ;
	stor->next = s;
	stor = s ;
}

void lessStorage()
{
	if (stor->prev != NULL)
		stor = stor->prev ;
}



// get the symbol value of symb_id from the symbol table //
symb_value_type get_symbol_value(sid symb_id) {
 storage* s = stor;
 elem * tracker;


int i=1;
 // look into the linked list for the symbol value //
 while (s)
 {
  tracker = s->item;
  while (tracker) {
   if (tracker -> symbol_name == symb_id)
    return tracker -> symbol_value;

   tracker = tracker -> next;
  }

   s=s->prev;


 }

 // if not found does cause an error //
 fprintf(stderr,"Error : symbol %s have no defined value\n",(char *) symb_id);
 exit(-1);
};

void displaySymbols(){
	elem * tracker;
	storage* s = stor;

	int i =1;
	// look into the linked list for the symbol value //
	while (s)
	{
		tracker = s ->item;
		while (tracker) {
			printf("Variable de niveaux %d --> %s\n", i, tracker -> symbol_name);
			tracker = tracker -> next;
		}

		s=s->prev;
		i++;

	}


}


// set the value of symbol symb_id to value //
symb_value_type set_symbol_value(sid symb_id,symb_value_type value) {

	elem * tracker;

	if (stor == NULL)
	{
		stor = malloc(sizeof(storage));
		stor->next = NULL;
		stor-> prev = NULL;
		stor->item = NULL;
	}

	// (optionnal) check that sid is valid symbol name and exit error if not //
	if (! sid_valid(symb_id)) {
		fprintf(stderr,"Error : symbol id %p is not have no valid sid\n",symb_id);
		exit(-1);
	}

	// look for the presence of symb_id in storage //

	tracker = stor->item;
	while (tracker) {
		if (tracker -> symbol_name == symb_id) {
			tracker -> symbol_value = value;
			//fprintf(test_c,"r%d = \n", tracker->symbol_value.reg, value.value);
			return tracker -> symbol_value;
		}
		tracker = tracker -> next;
	}

	// otherwise insert it at head of storage with proper value //
	//fprintf(test_c, "r%d = \n", regIdCounter, value.value);
	//fprintf(test_c, "%s = r%d\n", symb_id, regIdCounter);
	tracker = malloc(sizeof(elem));
	tracker -> symbol_name = symb_id;
	tracker -> symbol_value = value;
	tracker -> next = stor->item;
	stor->item = tracker;

	return stor->item -> symbol_value;
}
