// =============================================================================
// FUN_005a2850 — Map_Tree_Predecessor_Isnil15 (structural)
// -----------------------------------------------------------------------------
// Stable ID: aa_005a2850
// Address:   0x005a2850  (autoassault.exe, image base 0x400000)
// System:    shared map/tree helper (isnil +0x15 family)
// Generated: 2026-07-23 scaffold; dual-refined 2026-07-29 W19-N
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte seals.
//            Not modernization. Not bit-for-bit vs retail EXE (deferred).
// Dual:      reviews/A_aa_005a2850_Map_Tree_Predecessor_Isnil15.md
//            reviews/B_aa_005a2850_Map_Tree_Predecessor_Isnil15.md
// =============================================================================
//
// PURPOSE:
//   MSVC-style ordered-tree bidirectional iterator decrement (predecessor).
//   In-place: ECX = Node**; writes *pIt; RET (C3). Leaf — no callees.
//
//   Node links (sealed): left@0, parent@4, right@8, isnil@0x15.
//   Key/color/payload are NOT read — caller maps may differ.
//
//   CF:
//     1) if cur->isnil: *pIt = cur->right  (end → max)
//     2) else if left non-nil: *pIt = rightmost(left)
//     3) else climb parents while cur == parent->left; maybe *pIt = parent
//
// Sibling: FUN_00537770 / Map_Tree_Predecessor_Isnil49 (same CF, isnil@0x49).
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_005a2850(int* param_1 /* Node** pIt */)
{
  char cVar1;
  int iVar2;
  int iVar3;
  int* piVar4;

  piVar4 = (int*)*param_1;
  if (*(char*)((int)piVar4 + 0x15) != '\0') {
    *param_1 = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char*)(iVar2 + 0x15) == '\0') {
    cVar1 = *(char*)(*(int*)(iVar2 + 8) + 0x15);
    iVar3 = *(int*)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char*)(*(int*)(iVar3 + 8) + 0x15);
      iVar2 = iVar3;
      iVar3 = *(int*)(iVar3 + 8);
    }
    *param_1 = iVar2;
    return;
  }
  piVar4 = (int*)piVar4[1];
  if (*(char*)((int)piVar4 + 0x15) == '\0') {
    do {
      if (*param_1 != *piVar4) break;
      *param_1 = (int)piVar4;
      piVar4 = (int*)piVar4[1];
    } while (*(char*)((int)piVar4 + 0x15) == '\0');
    if (*(char*)((int)piVar4 + 0x15) == '\0') {
      *param_1 = (int)piVar4;
    }
  }
  return;
}
