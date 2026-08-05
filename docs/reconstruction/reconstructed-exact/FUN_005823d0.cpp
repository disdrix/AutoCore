// =============================================================================
// FUN_005823d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005823d0
// Address:   0x005823d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005823d0 @ 0x005823d0
// Stable ID: aa_005823d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_005134e0, FUN_005823d0.
//  - Return sites: 2.

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

void __thiscall FUN_005823d0(int param_1,uint param_2)



{

  uint *puVar1;

  int iVar2;

  

  iVar2 = *(int *)(*(int *)(param_1 + -0x8c) + 4);

  puVar1 = (uint *)(iVar2 + param_1 + 0xf0);

  *puVar1 = *puVar1 ^ ((param_2 & 0xff) * 8 ^ *(uint *)(iVar2 + 0xf0 + param_1)) & 8;

  if (*(int *)(param_1 + -0x88) != 0) {

    if ((*(uint *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 0xf0 + param_1) >> 3 & 1) == 0) {

      FUN_005134e0();

    }

                    /* WARNING: Could not recover jumptable at 0x00582448. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*(int *)(param_1 + -0x90) + 0x1c))();

    return;

  }

  return;

}
