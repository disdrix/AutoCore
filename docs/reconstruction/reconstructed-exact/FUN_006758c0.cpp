// =============================================================================
// FUN_006758c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006758c0
// Address:   0x006758c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006758c0 @ 0x006758c0
// Stable ID: aa_006758c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_006758c0, FUN_00680fd0.
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

void FUN_006758c0(uint32_t /* width from decompiler */ *param_1,int param_2,uint param_3,int param_4,uint param_5,

                 uint32_t /* width from decompiler */ param_6,int param_7)



{

  uint uVar1;

  

  for (; (param_2 != param_4 || (param_3 != param_5)); param_3 = param_3 + 1) {

    uVar1 = param_3;

    if (*(uint *)(param_2 + 8) <= param_3) {

      uVar1 = param_3 - *(uint *)(param_2 + 8);

    }

    FUN_00680fd0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 4) + uVar1 * 4));

    param_7 = param_7 + 1;

  }

  param_1[1] = param_7;

  *param_1 = param_6;

  return;

}
