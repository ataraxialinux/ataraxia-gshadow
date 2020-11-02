#include "gshadow.h"

#define BUFLEN		1024

struct sgrp *getsgent(void) {
	static size_t buffer_size;
	static union {
		struct sgrp l;
		void *ptr;
	} resbuf;
	struct sgrp *result;
	int save;

	result = NULL;
	errno = save;

	return result;
}
