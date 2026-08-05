// =============================================================================
// FUN_0051b2a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b2a0
// Address:   0x0051b2a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0051b2a0 @ 0x0051b2a0
// Stable ID: aa_0051b2a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00519280, FUN_0051b2a0.
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

void __thiscall

FUN_0051b2a0(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  

  if ((param_1[0x52] == 0) || (param_1[0x53] - param_1[0x52] >> 4 == 0)) {

    iVar1 = (**(code **)(*param_1 + 0x1cc))();

    if ((iVar1 != 0) && (*(int *)(iVar1 + 8) != 0)) {

      FUN_00519280(*(int *)(iVar1 + 8),param_1 + 0x51,param_2,param_3,param_4,param_5);

    }

  }

  return;

}
