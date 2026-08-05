// =============================================================================
// FUN_00419bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00419bd0
// Address:   0x00419bd0  (autoassault.exe, image base 0x400000)
// Body:      0x00419bd0–0x00419c2e (94 bytes)
// System:    container / CNDHash u64-key freelist
// Generated: 2026-07-23 scaffold; W22-K seal 2026-07-29
// Named clean: CNDHash_FreelistPop_Node0x28.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Lazy freelist pop for 0x28-byte CNDHash nodes.
// ABI: EDI = Node**; EAX = popped Node* (decompiler void under-recovers).
// Grow: _aligned_malloc(1000,0x10); track via 0x004149d0 (Vector_PushDword residue
//       named CVOGReaction_FailMissionNotify); chain 0x18 links @ +0x28; term @ +0x3c0.
// Callers: 0x00413920, 0x00419620 (EDI = hash+0x20).
// =============================================================================

#include <cstdint>

extern "C" void *_aligned_malloc(size_t size, size_t alignment);
extern "C" void CVOGReaction_FailMissionNotify(void *pSlabPtr);

// Decompiler-shaped body (register fiction kept):
void FUN_00419bd0(void)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *unaff_EDI; // retail: freelist head pointer (Node**)
  int *local_4;

  if (((int *)*unaff_EDI == (int *)0x0) || (*(int *)*unaff_EDI == 0)) {
    piVar1 = (int *)_aligned_malloc(1000, 0x10);
    local_4 = piVar1;
    CVOGReaction_FailMissionNotify(&local_4); // ECX=EDI+4 in retail
    *unaff_EDI = (int)piVar1;
    iVar3 = 0x18;
    piVar2 = piVar1;
    do {
      iVar3 = iVar3 + -1;
      *piVar2 = (int)(piVar2 + 10); // +10 dwords = +0x28
      piVar2 = piVar2 + 10;
    } while (iVar3 != 0);
    piVar1[0xf0] = 0; // byte offset 0x3c0
  }
  // Machine also: EAX = *unaff_EDI before advance
  *unaff_EDI = *(int *)*unaff_EDI;
  return;
}
