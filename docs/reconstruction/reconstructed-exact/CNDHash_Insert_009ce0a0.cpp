// =============================================================================
// CNDHash_Insert_009ce0a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0051e3d0
// Address:   0x0051e3d0  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0051e3d0
// System:    container / CNDHash insert family (node vtbl 0x009ce0a0)
// Generated: 2026-07-29 W21-D dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   CNDHash insert(key, value) specialized by node vtbl PTR_FUN_009ce0a0.
//   Same control flow as CNDHash_Insert (0x0053c560) and twin
//   CNDHash_Insert_009ce0a8 (0x0051e4d0) — must not merge call sites.
//
// ABI:
//   __thiscall  ECX = CNDHash*
//   stack: uint key, void *value, char softIfExists
//   ret 0xC
//
// RETURNS:
//   0           inserted
//   1           soft: key already present (softIfExists != 0)
//   0x80004003  null value (E_POINTER)
//   0x80004005  hard duplicate (E_FAIL)
//
// CALLER:
//   FUN_00519a30 — three sites, softIfExists = 0
// =============================================================================

#include <stdint.h>

// External callees (sealed / named elsewhere where available).
extern void * __thiscall CNDHash_LookupByKey(void *self, uint32_t key);
extern void * __thiscall FUN_0053ada0(void); // freelist alloc; ECX = freelist header
extern void FUN_00537d30(void);              // bucket chain integrity
extern void FUN_007a4480(int severity, const char *fmt, ...);

// Node vtbl stamp for this insert variant.
extern uint32_t PTR_FUN_009ce0a0;

// Structural name — product English for this vtbl specialty open.
uint32_t __thiscall CNDHash_Insert_009ce0a0(
    void *self, uint32_t key, void *value, char softIfExists)
{
  int bucketHead;
  void *existing;
  uint32_t *node;

  if (value == 0) {
    return 0x80004003; /* E_POINTER */
  }
  if (*(char *)((int)self + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:insert, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  if (softIfExists != 0) {
    existing = CNDHash_LookupByKey(self, key);
    if (existing != 0) {
      return 1;
    }
  }
  existing = CNDHash_LookupByKey(self, key);
  if (existing != 0) {
    FUN_007a4480(0, "Duplicate hash insert %u, failing out", key);
    return 0x80004005; /* E_FAIL */
  }
  /* ECX preset to self+0x20 by caller site in body */
  node = (uint32_t *)FUN_0053ada0();
  node[3] = 0;
  *node = (uint32_t)&PTR_FUN_009ce0a0;
  node[5] = 0;
  node[6] = 0;
  *(uint8_t *)(node + 1) = 0;
  node[2] = (uint32_t)value;
  node[4] = key;
  bucketHead = *(int *)(*(int *)((int)self + 0x10)
                        + (*(uint32_t *)((int)self + 8) & key) * 4);
  node[3] = *(uint32_t *)(bucketHead + 4);
  *(uint32_t **)(bucketHead + 4) = node;
  FUN_00537d30();
  if (*(int *)((int)self + 0x18) != 0) {
    *(uint32_t **)(*(int *)((int)self + 0x18) + 0x14) = node;
    node[5] = 0;
    node[6] = *(uint32_t *)((int)self + 0x18);
    *(int *)((int)self + 0xc) = *(int *)((int)self + 0xc) + 1;
    *(uint32_t **)((int)self + 0x18) = node;
    return 0;
  }
  *(uint32_t **)((int)self + 0x18) = node;
  *(uint32_t **)((int)self + 0x14) = node;
  node[6] = 0;
  node[5] = 0;
  *(int *)((int)self + 0xc) = *(int *)((int)self + 0xc) + 1;
  return 0;
}
