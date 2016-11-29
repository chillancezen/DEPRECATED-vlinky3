#include <stdio.h>
#include <hugepage_util.h>
#include <vecring.h>

int main()

{
	struct hugepage_memory hp_mem;
	struct vecring_header_t *vr;
	hugepage_util_init();
	int rc=allocate_mmeory_from_hugepage_fs(&hp_mem,"foo-input",needed_memory(DEFAULT_NR_BLOCK64),0);
	vr=(void*)hp_mem.base;
	vecring_init(vr,DEFAULT_NR_BLOCK64);
	
	printf("%d\n",IS_CACHELINE_ALIGNED(&vr->data[0].dummy16_0));
	printf("%d\n",vecring_available(vr));
	printf("%d\n",vecring_used(vr));
	getchar();
	return 0;
	
}
