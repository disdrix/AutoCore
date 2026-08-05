// =============================================================================
// FUN_00546f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00546f40
// Address:   0x00546f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00546f40 @ 0x00546f40
// Stable ID: aa_00546f40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00546f40, FUN_00548210.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall FUN_00546f40(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  iVar3 = param_2;

  iVar1 = *(int *)(param_1 + 0x13c);

  if ((iVar1 == 0) ||

     ((uint)(*(int *)(param_1 + 0x144) - iVar1 >> 2) <=

      (uint)(*(int *)(param_1 + 0x140) - iVar1 >> 2))) {

    FUN_00548210(*(uint32_t /* width from decompiler */ *)(param_1 + 0x140),1,&param_2);

  }

  else {

    piVar2 = *(int **)(param_1 + 0x140);

    *piVar2 = param_2;

    *(int **)(param_1 + 0x140) = piVar2 + 1;

  }

  *(uint8_t *)(iVar3 + 0x14) = *(uint8_t *)(param_1 + 0x130);

  *(char *)(param_1 + 0x130) = *(char *)(param_1 + 0x130) + '\x01';

  return;

}
