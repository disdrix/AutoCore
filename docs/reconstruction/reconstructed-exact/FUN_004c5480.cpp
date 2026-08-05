// =============================================================================
// FUN_004c5480
// -----------------------------------------------------------------------------
// Stable ID: aa_004c5480
// Address:   0x004c5480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c5480 @ 0x004c5480
// Stable ID: aa_004c5480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004c5480, FUN_00519280, FUN_0051b2a0.
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

FUN_004c5480(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5

            )



{

  FUN_0051b2a0(param_2,param_3,param_4,param_5);

  if (*(int *)(param_1 + -0x27c) != 0) {

    if ((*(int *)(param_1 + -0x208) == 0) ||

       (*(int *)(param_1 + -0x204) - *(int *)(param_1 + -0x208) >> 4 == 0)) {

      FUN_00519280(*(int *)(param_1 + -0x27c),param_1 + -0x20c,param_2,param_3,param_4,param_5);

    }

  }

  return;

}
