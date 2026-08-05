// Legacy string-scaffold alias → AssManager_RemoveResolver_Inferred
// Stable ID: aa_00423e00 @ 0x00423e00
// Prefer: AssManager_RemoveResolver_Inferred.cpp / FUN_00423e00.cpp

#include <stdint.h>

extern uint8_t FUN_0043e5b0(int *key);
extern uint8_t FUN_0043c550(int *key);
extern void vog_LogMessage(const char *file, int line, int level,
                           const char *msg);

void Named_assManager_00423e00(void *assManager /*ECX*/, int key /*EAX*/)
{
  int local_key = key;
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
