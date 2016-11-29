#include <vecring.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void vecring_init(struct vecring_header_t *vr,int nr_block)
{
	memset(vr,0x0,sizeof(struct vecring_header_t));
	vr->front=0;
	vr->rear=0;
	vr->nr_block64=nr_block;
}

__attribute__((constructor)) void  vecring_arch_detect(void) 
{
	#define _(cpuflag) {\
		fprintf(stderr,"[x]cpu must support %s instruction set\n",(cpuflag)); \
		exit(1); \
	}

	#ifndef __SSE__
	_("sse");
	#endif

	
	#ifndef __SSE2__
		_("sse2");
	#endif

	
	#ifndef __SSE3__
		_("sse3");
	#endif

	#ifndef __SSE4_1__
		_("sse4.1");
	#endif

	#ifndef __SSE4_1__
		_("sse4.2");
	#endif

	#ifndef __AVX__
		_("avx");
	#endif

	#ifndef __AVX2__
	//	_("avx2");
	#endif
	#undef _

	assert(sizeof(struct vecring_block64)==64);
	assert(sizeof(struct vecring_header_t)==64);
}


