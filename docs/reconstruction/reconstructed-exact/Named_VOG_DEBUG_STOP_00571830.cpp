// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00512670×2, FUN_00571010, FUN_00571830, FUN_007a4480.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_00571830
// -----------------------------------------------------------------------------
// Stable ID: aa_00571830
// Address:   0x00571830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_VOG_DEBUG_STOP_00571830(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int *piVar1;

  int iVar2;

  

  piVar1 = (int *)FUN_00571010(param_3,param_4);

  if (piVar1 == (int *)0x0) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    return 0;

  }

  iVar2 = (**(code **)(*piVar1 + 0x25c))();

  (**(code **)(*piVar1 + 0x260))(iVar2 + param_2);

  FUN_00512670();

  if (*(int *)(param_1 + 0x24) != 0) {

    FUN_00512670();

  }

  *(uint8_t *)(param_1 + 0x21) = 1;

  return 1;

}
