#ifndef _LIBVECRING_HUGEPAGE_UTIL_H
#define _LIBVECRING_HUGEPAGE_UTIL_H
/*only support 2M hugepage size*/
#include <inttypes.h>

struct hugepage_file{
	int is_used;
	char path[64];
	void * mapped_base;
	int socket_id;
};
struct hugepage_memory{
	struct hugepage_file * hp_files;
	int nr_files;
	uint64_t base;
	int prefered_socket_node;
};
void hugepage_util_init(void);
void free_hugepage_files(struct hugepage_file*hp_file,
	int nr_files);
int allocate_mmeory_from_hugepage_fs(struct hugepage_memory *hp_mem,
	char *vring_id,
	int length,
	int prefered_node);
int hugepage_util_module_test(void);
#endif