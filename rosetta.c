#include <stdio.h>
#include <string.h>
 
typedef struct Dados {
	struct Dados *left, *right;
	int priority;
	char v;
} *Dados;
 
struct Dados pool[256] = {{0}};
Dados qqq[255], *q = qqq - 1;
int n_Dadoss = 0, qend = 1;
char *code[128] = {0}, buf[1024];
 
Dados new_Dados(int priority, char c, Dados a, Dados b)
{
	Dados n = pool + n_Dadoss++;
	if (priority) n->v = c, n->priority = priority;
	else {
		n->left = a, n->right = b;
		n->priority = a->priority + b->priority;
	}
	return n;
}
 
/* priority queue */
void PQInsert(Dados n)
{
	int j, i = qend++;
	while ((j = i / 2)) {
		if (q[j]->priority <= n->priority) break;
		q[i] = q[j], i = j;
	}
	q[i] = n;
}
 
Dados PQDelmin()
{
	int i, l;
	Dados n = q[i = 1];
 
	if (qend < 2) return 0;
	qend--;
	while ((l = i * 2) < qend) {
		if (l + 1 < qend && q[l + 1]->priority < q[l]->priority) l++;
		q[i] = q[l], i = l;
	}
	q[i] = q[qend];
	return n;
}
 
/* walk the tree and put 0s and 1s */
void build_code(Dados n, char *s, int len)
{
	static char *out = buf;
	if (n->v) {
		s[len] = 0;
		strcpy(out, s);
		code[n->v] = out;
		out += len + 1;
		return;
	}
 
	s[len] = '0'; 
	build_code(n->left,  s, len + 1);
	s[len] = '1'; 
	build_code(n->right, s, len + 1);
}
 
 
void encode(const char *s, char *out)
{
	while (*s) {
		strcpy(out, code[*s]);
		out += strlen(code[*s++]);
	}
}
 
void decode(const char *s, Dados t)
{
	Dados n = t;
	while (*s) {
		if (*s++ == '0') n = n->left;
		else n = n->right;
 
		if (n->v) putchar(n->v), n = t;
	}
 
	putchar('\n');
	if (t != n) printf("garbage input\n");
}
void init(const char *s)
{
	int i, priority[128] = {0};
	char c[16];
 
	while (*s) priority[(int)*s++]++;
 
	for (i = 0; i < 128; i++)
		if (priority[i]) PQInsert(new_Dados(priority[i], i, 0, 0));
 
	while (qend > 2) 
		PQInsert(new_Dados(0, 0, PQDelmin(), PQDelmin()));
 
	build_code(q[1], c, 0);
}
 
int main(void)
{
	int i;
	const char *str = "AAAAAAAAAACCCCGGGGGGGGGTTTTTTT", buf[1024];
 
	init(str);
	for (i = 0; i < 128; i++)
		if (code[i]) printf("'%c': %s\n", i, code[i]);
 
	encode(str, buf);
	printf("encoded: %s\n", buf);
 
	printf("decoded: ");
	decode(buf, q[1]);
 
	return 0;
}