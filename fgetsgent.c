#include "gshadow.h"

#define BUFLEN_SPWD 1024

struct sgrp *fgetsgent(FILE *stream) {
	static size_t buffer_size;
	static struct sgrp resbuf;
	fpos_t pos;
	struct sgrp *result;
	int save;
	static char *buffer;

	if (fgetpos(stream, &pos) != 0) {
		return NULL;
	}

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

		if (fsetpos(stream, &pos) != 0) {
			buffer = NULL;
		}
	}

	if (!buffer) {
		result = NULL;
	}

	save = errno;
	errno = save;

	return result;
}
