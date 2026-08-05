// =============================================================================
// FUN_00512460  (scaffold alias — prefer Object_SetRaceIdOwnerChain_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00512460
// Address:   0x00512460 – 0x00512487  (autoassault.exe, image base 0x400000)
// System:    object / faction
// Generated: 2026-07-23 scaffold; Dual A/B sealed 2026-07-29 (W24-G)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Leaf thiscall: write race/faction DWORD at +0x10 on self, then on every
 *   owner along +0xAC until (and including) the null-owner root.
 * - Stack arg cleaned with ret 4; ECX = pObject.
 * - Companion getter: Object_GetRootRaceId @ 0x00512440.
 * - Runtime / differential verification: OPEN.
 */

void __thiscall FUN_00512460(int param_1, undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 0xac);
  piVar2 = (int *)(param_1 + 0xac);
  *(undefined4 *)(param_1 + 0x10) = param_2;
  while (iVar1 != 0) {
    iVar1 = *piVar2;
    *(undefined4 *)(iVar1 + 0x10) = param_2;
    piVar2 = (int *)(iVar1 + 0xac);
    iVar1 = *piVar2;
  }
  return;
}
