#include "gshadow.h"

#define BUFLEN		1024

struct sgrp *getsgnam(const char *name) {
	static size_t buffer_size;
	static struct sgrp resbuf;
	struct sgrp *result;
	static char *buffer;

	if (!buffer) {
		buffer_size = BUFLEN;
		buffer = (char *)malloc(buffer_size);
	}

	while (!buffer) {
		char *new_buf;
		buffer_size += 2;
		new_buf = (char *)realloc(buffer, buffer_size);

		if (!new_buf) {
			free(buffer);
			errno = ENOMEM;
		}

		buffer = new_buf;
	}

	if (!buffer) {
		result = NULL;
	}

	return result;
}
