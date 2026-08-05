// =============================================================================
// FUN_005134e0  (canonical: Object_HasFlag8SelfOrLinked)
// -----------------------------------------------------------------------------
// Stable ID: aa_005134e0
// Address:   0x005134e0  (autoassault.exe, image base 0x400000)
// System:    targeting / object-flags
// Generated: 2026-07-29 W17-E dual (scaffold name kept; prefer Object_HasFlag8SelfOrLinked)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Link-aware flag-8 predicate (mask 0x08 @ +0x184 / linked).
// Prefer reconstructed-exact/Object_HasFlag8SelfOrLinked.cpp

bool __fastcall FUN_005134e0(int param_1)
{
  int iVar1;
  bool bVar2;

  if (*(int **)(param_1 + 0xac) == (int *)0x0) {
    return (*(unsigned int *)(param_1 + 0x184) & 8) != 0;
  }
  iVar1 = (**(int (**)())(**(int **)(param_1 + 0xac) + 0x19c))();
  bVar2 = (*(unsigned char *)(param_1 + 0x184) & 8) != 0;
  if (iVar1 != 0) {
    return bVar2 ||
           (*(unsigned char *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x188 + iVar1) & 8) != 0;
  }
  return bVar2 || (*(unsigned char *)(*(int *)(param_1 + 0xac) + 0x184) & 8) != 0;
}
