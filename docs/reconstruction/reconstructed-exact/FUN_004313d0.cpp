// =============================================================================
// FUN_004313d0  (scaffold twin of StdTree_IteratorDecrement)
// -----------------------------------------------------------------------------
// Stable ID: aa_004313d0
// Address:   0x004313d0  (autoassault.exe, image base 0x400000)
// System:    shared client::stdtree
// Generated: 2026-07-23 scaffold; dual seal refine 2026-07-29 W22-O
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical named twin: reconstructed-exact/StdTree_IteratorDecrement.cpp
// =============================================================================

/*
 * MSVC _Tree iterator predecessor (operator--).
 * EDX = node**; nil flag at +0x2d; left/parent/right at +0/+4/+8.
 * Live decompile ≡ raw; no callees; plain ret.
 */

void __fastcall FUN_004313d0(unsigned /* unused ECX */, int *param_2 /* EDX = node** */)
{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;

  piVar4 = (int *)*param_2;
  if (*(char *)((int)piVar4 + 0x2d) != '\0') {
    *param_2 = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x2d) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x2d);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x2d);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *param_2 = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x2d) == '\0') {
    do {
      if (*param_2 != *piVar4)
        break;
      *param_2 = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x2d) == '\0');
    if (*(char *)((int)piVar4 + 0x2d) == '\0') {
      *param_2 = (int)piVar4;
    }
  }
  return;
}
