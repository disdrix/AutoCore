// =============================================================================
// FUN_005153a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005153a0
// Address:   0x005153a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005153a0 @ 0x005153a0
// Stable ID: aa_005153a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_004b70c0×2, FUN_005153a0.
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

void __thiscall FUN_005153a0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x124);

  if (iVar1 != *(int *)(param_1 + 0x128)) {

    do {

      FUN_004b70c0(param_2,param_3,param_4);

      iVar1 = iVar1 + 4;

    } while (iVar1 != *(int *)(param_1 + 0x128));

  }

  iVar1 = *(int *)(param_1 + 0x138);

  if (iVar1 != *(int *)(param_1 + 0x13c)) {

    do {

      FUN_004b70c0(param_2,param_3,param_4);

      iVar1 = iVar1 + 4;

    } while (iVar1 != *(int *)(param_1 + 0x13c));

  }

  return;

}
