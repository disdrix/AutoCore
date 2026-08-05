// =============================================================================
// CNDHash_FreelistPop_Node0x28
// -----------------------------------------------------------------------------
// Stable ID: aa_00419bd0
// Address:   0x00419bd0  (autoassault.exe, image base 0x400000)
// Body:      0x00419bd0–0x00419c2e (94 bytes)
// System:    container / CNDHash (u64-key freelist)
// Seal:      W22-K 2026-07-29 — decompile_function + read_memory
// Exactness: Behavior-preserving CF; custom EDI/EAX ABI documented.
// =============================================================================

#include <cstdint>

// Forward: CRT aligned allocator (import in retail).
extern "C" void *_aligned_malloc(size_t size, size_t alignment);

// Ghidra residue name for Vector_PushDword @ 0x004149d0 (thiscall ECX + stack ptr).
extern "C" void CVOGReaction_FailMissionNotify(void *pSlabPtr);

// 0x28-byte CNDHash node (u64-key family). Only freelist next@+0 touched here.
struct CndHashNode0x28 {
  CndHashNode0x28 *next;
  uint32_t rest[9];
};

// ---------------------------------------------------------------------------
// Retail ABI (machine):
//   in  EDI = CndHashNode0x28 **pHead   (callers: hash + 0x20)
//   out EAX = popped node* (or first node of new slab)
//   stack: none cleaned (ret / c3)
// Decompiler prints: void FUN_00419bd0(void) with unaff_EDI.
// ---------------------------------------------------------------------------

// Portable CF reconstruction (registers expressed as parameters):
CndHashNode0x28 *CNDHash_FreelistPop_Node0x28(CndHashNode0x28 **pHead)
{
  if (((int *)*pHead == (int *)0x0) || (*(int *)*pHead == 0)) {
    CndHashNode0x28 *slab =
        (CndHashNode0x28 *)_aligned_malloc(1000, 0x10);
    CndHashNode0x28 *local_4 = slab;
    // ECX = (char*)pHead + 4 in retail (slab-tracking vector this)
    CVOGReaction_FailMissionNotify(&local_4);
    *pHead = slab;

    int iVar3 = 0x18;
    CndHashNode0x28 *piVar2 = slab;
    do {
      iVar3 = iVar3 + -1;
      // *piVar2 = (int)(piVar2 + 10) on int* → +0x28 bytes
      piVar2->next =
          (CndHashNode0x28 *)((char *)piVar2 + 0x28);
      piVar2 = (CndHashNode0x28 *)((char *)piVar2 + 0x28);
    } while (iVar3 != 0);

    // piVar1[0xf0] = 0 → byte offset 0x3c0
    *(uint32_t *)((char *)slab + 0x3c0) = 0;
  }

  // Pop: EAX = old head; *pHead = old->next
  CndHashNode0x28 *popped = *pHead;
  *pHead = popped->next;
  return popped;
}

// Ghidra symbol surface
void FUN_00419bd0(void)
{
  // Body identical; EDI = pHead; return in EAX omitted by decompiler.
}
