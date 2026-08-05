// =============================================================================
// AssManager_RemoveResolver_Inferred
// -----------------------------------------------------------------------------
// Purpose:  assManager path: remove a resolver key from the GuardedVector at
//           this+0x58. On miss, log "Removing resolver not found" (assManager.cpp
//           line 0x27b, level 3) and return. On hit, erase first equal entry.
//
// Address:  0x00423e00  (autoassault.exe, image base 0x400000)
// Body:     0x00423e00–0x00423e43 (68 bytes)
// Stable:   aa_00423e00
// System:   assets / assManager
// Ghidra:   FUN_00423e00
//
// ABI (bytes): ECX = assManager*; EAX = resolver key (dword);
//              plain RET; decompiler void(void) incomplete.
// Strings:  assManager.cpp path @ 0x00a9e930;
//           "Removing resolver not found" @ 0x00a9e888
// Callees:  FUN_0043e5b0 (find; EAX=container), vog_LogMessage,
//           FUN_0043c550 / GuardedVector_EraseFirstEqual (ESI=container)
// Sole caller: FUN_007b65d0 — EAX=[EBX+8], ECX=[DAT_00d1f058]
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W29-C seal).
// =============================================================================

#include <stdint.h>

struct GuardedVectorHeader; /* family layout sealed elsewhere (W28-C) */

/* EAX=container; stack key*; returns AL bool found (no mutate). */
extern uint8_t FUN_0043e5b0(int *key);

/* ESI=container; stdcall key*; RET 4; AL found. Sealed W28-C. */
extern uint8_t GuardedVector_EraseFirstEqual(int *key);

extern void vog_LogMessage(const char *file, int line, int level,
                           const char *msg);

/* Retail: ECX=this, EAX=key. */
void AssManager_RemoveResolver_Inferred(void *assManager /*ECX*/,
                                        int key /*EAX*/)
{
  int local_key = key;
  /* bytes: MOV ESI, ECX; ADD ESI, 0x58 — container at this+0x58 */
  GuardedVectorHeader *container =
      (GuardedVectorHeader *)((uint8_t *)assManager + 0x58);

  /* CALL FUN_0043e5b0 with EAX=container, arg=&local_key */
  (void)container;
  uint8_t found = FUN_0043e5b0(&local_key);
  if (found == 0) {
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp",
        0x27b,
        3,
        "Removing resolver not found");
    return;
  }

  /* ESI still container; CALL GuardedVector_EraseFirstEqual(&local_key) */
  GuardedVector_EraseFirstEqual(&local_key);
}
