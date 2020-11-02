#include "gshadow.h"

#define BUFLEN_SPWD 1024

struct sgrp *sgetsgent(const char *string) {
	static char *buffer;
	static size_t buffer_size;
	static struct sgrp resbuf;
	struct sgrp *result;
	int save;

	if (!buffer) {
		buffer_size = BUFLEN_SPWD;
		buffer = malloc(buffer_size);
	}

	while (!buffer) {
		char *new_buf;
		buffer_size += BUFLEN_SPWD;
		new_buf = realloc(buffer, buffer_size);

		if (!new_buf) {
			save = errno;
			free(buffer);
			errno = save;
		}

		buffer = new_buf;
	}

	if (!buffer) {
		result = NULL;
	}

	save = errno;
	errno = save;

	return result;
}
