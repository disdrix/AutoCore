// Twin of AssManager_RemoveResolver_Inferred.cpp — Ghidra FUN_* alias.
// Stable ID: aa_00423e00 @ 0x00423e00. See named clean for full header.

#include <stdint.h>

extern uint8_t FUN_0043e5b0(int *key);
extern uint8_t FUN_0043c550(int *key); /* GuardedVector_EraseFirstEqual */
extern void vog_LogMessage(const char *file, int line, int level,
                           const char *msg);

/* Retail ABI: ECX=assManager*, EAX=key; container = this+0x58. */
void FUN_00423e00(void *assManager /*ECX*/, int key /*EAX*/)
{
  int local_key = key;
  uint8_t *container_base = (uint8_t *)assManager + 0x58;
  (void)container_base;

  if (FUN_0043e5b0(&local_key) == 0) {
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp",
        0x27b,
        3,
        "Removing resolver not found");
    return;
  }
  FUN_0043c550(&local_key);
}
