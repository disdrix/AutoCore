// =============================================================================
// Map_EraseRange_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_0053a260
// Address:   0x0053a260  (autoassault.exe, image base 0x400000)
// System:    MSVC std map/set range erase (Val12 node, isnil@+0x19)
// Generated: 2026-07-29 W28-S dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// PURPOSE: Erase [first, last) on a Val12 RB map/set shell.
// Full-range: recursive free FUN_00538690 + head reset + size=0.
// Partial: in-order successor walk + Map_EraseNode_Val12 (FUN_005399f0) per node.
// ABI: thiscall; ECX=map; stack (outIt, first, last); ret 0x0c.
// Peer: Map_EraseNode_Val12 (aa_005399f0). Not isnil@+0x29 / +0x15 families.
// Name: Ghidra FUN_0053a260; inferred Map_EraseRange_Val12.
//

#include <cstdint>

// Map shell: head @ +4, size @ +8
// Node: left@0 parent@4 right@8 ... color@+0x18 isnil@+0x19 value@+0x0c (Val12)

void __thiscall Map_EraseRange_Val12(
    int map /* ECX */,
    uint32_t *outIt,
    int *first,
    int *last)
{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;

  piVar4 = last;
  piVar6 = *(int **)(map + 4);   // head sentinel
  piVar3 = first;

  // Full-range fast path: [begin, end) == entire tree
  if ((first == (int *)*piVar6) && (last == piVar6)) {
    FUN_00538690((void *)piVar6[1]);          // free subtree at head->parent
    *(int *)(*(int *)(map + 4) + 4) = *(int *)(map + 4);  // parent = head
    *(uint32_t *)(map + 8) = 0;               // size = 0
    *(uint32_t *)*(uint32_t *)(map + 4) = *(uint32_t *)(map + 4); // left = head
    *(int *)(*(int *)(map + 4) + 8) = *(int *)(map + 4);         // right = head
    *outIt = **(uint32_t **)(map + 4);        // begin (== end)
    return;
  }

  // Partial range: erase each node, advancing via tree successor
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x19) == '\0') {   // not isnil → real node
      piVar6 = (int *)piVar3[2];                   // right
      if (*(char *)((int)piVar6 + 0x19) == '\0') {
        // successor = min of right subtree
        cVar1 = *(char *)(*piVar6 + 0x19);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x19);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      } else {
        // climb parents while coming from right
        cVar1 = *(char *)(piVar3[1] + 0x19);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x19);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_005399f0(&first, piVar3);   // Map_EraseNode_Val12
    piVar3 = piVar6;                // advance to precomputed successor
  }
  *outIt = (uint32_t)piVar3;
  return;
}

// External (not owned): FUN_00538690, FUN_005399f0 (Map_EraseNode_Val12)
