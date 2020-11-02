#include "gshadow.h"

#define _S(x)	x ? x : ""

int putsgent(const struct sgrp *g, FILE *stream) {
	int e = 0;

	if (!g->sg_namp) {
		errno = EINVAL;
		return -1;
	}

	if (fprintf(stream, "%s:%s:", g->sg_namp, _S (g->sg_passwd)) < 0) {
		++e;
	}

	bool first = true;
	char **sp = g->sg_adm;
	if (sp) {
		while (*sp) {
			if (fprintf(stream, "%s%s", first ? "" : ",", *sp++) < 0) {
				++e;
				break;
			}
			first = false;
		}
	}

	if (putc(':', stream) == EOF) {
		++e;
	}

	first = true;
	sp = g->sg_mem;
	if (sp) {
		while (*sp) {
			if (fprintf(stream, "%s%s", first ? "" : ",", *sp++) < 0)
				++e;
				break;
		}
		first = false;
	}

	if (putc(':', stream) == EOF) {
		++e;
	}

	return e ? -1 : 0;
}
