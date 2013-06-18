#ifndef H_HSTRIE
#define H_HSTRIE


#include "hotpot/hp_platform.h"

#define HOTSCRIPT_TRIE_LEAF_MAX                                           (1000000)
#define HOTSCRIPT_TRIE_CHAR_MAX                                           (255)
#define HOTSCRIPT_TRIE_WIDTH                                              (68)
#define HOTSCRIPT_TRIE_INVALID_INDEX                                      (0xffffffff)

#ifndef _DEF_HOTSCRIPT_TRIE_LEAF
#define _DEF_HOTSCRIPT_TRIE_LEAF
typedef struct tagHOTSCRIPT_TRIE_LEAF HOTSCRIPT_TRIE_LEAF;
#endif// _DEF_HOTSCRIPT_TRIE_LEAF
struct tagHOTSCRIPT_TRIE_LEAF
{
	hpint64		data;
	hpuint8		mark;
	hpuint32	count;
	hpuint32	next_leaf_index;
	hpuint32	children_index_size;
	hpuint32	children_index[HOTSCRIPT_TRIE_WIDTH];
};


#ifndef _DEF_HOTSCRIPT_TRIE
#define _DEF_HOTSCRIPT_TRIE
typedef struct tagHOTSCRIPT_TRIE HOTSCRIPT_TRIE;
#endif// _DEF_HOTSCRIPT_TRIE
struct tagHOTSCRIPT_TRIE
{
	hpuint32	max_leaf_index;
	hpuint32	char2index[HOTSCRIPT_TRIE_CHAR_MAX];
	hpuint32	free_lesf_head;
	hpuint32	root_index;
	hpuint32	total_alloc;
	hpuint32	leafs_num;
	HOTSCRIPT_TRIE_LEAF	leafs[HOTSCRIPT_TRIE_LEAF_MAX];
};


hpint32 hotscript_trie_init(HOTSCRIPT_TRIE *self, hpuint64 size, const char *token_set);

hpint32 hotscript_trie_insert(HOTSCRIPT_TRIE *self, const char *s, hpint64 data);

hpint32 hotscript_trie_delete(HOTSCRIPT_TRIE* xtrie, const char* s);

hpint32 hotscript_trie_search(HOTSCRIPT_TRIE* self, const char* s, hpint64 *data);

hpint32 hotscript_trie_clear(HOTSCRIPT_TRIE* self);

hpint32 hotscript_trie_fini(HOTSCRIPT_TRIE *self);



#endif//H_HSTRIE