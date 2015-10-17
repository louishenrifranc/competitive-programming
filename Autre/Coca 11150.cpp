
#include <cstdio>

int total (int N, int E) {
  if (N == 0) return 0;
  return N + total((N + E) / 3, (N + E) % 3);
}

int main () {
  int N;
  while (scanf("%d", &N) == 1) {
    if (N % 2 == 1) printf("%d\n", total(N, 0));
    else printf("%d\n", total(N, 2));
  }
}
