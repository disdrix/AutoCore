// =============================================================================
// FUN_00654c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00654c70
// Address:   0x00654c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00654c70 @ 0x00654c70
// Stable ID: aa_00654c70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0055e2d0, FUN_0055e370, FUN_0055e910, FUN_0055e970, FUN_00652320, FUN_006549b0, FUN_00654c70, block.
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

/* WARNING: Removing unreachable block (ram,0x00654ca6) */



void __thiscall FUN_00654c70(int param_1,int param_2)



{

  if (param_2 != *(int *)(param_1 + 0xc)) {

    if (*(int *)(param_1 + 0xc) != 0) {

      FUN_0055e2d0(param_1 + 0x14);

      FUN_0055e370(param_1 + 0x18);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    }

    FUN_00652320(param_2);

    if (*(int *)(param_1 + 0xc) != 0) {

      FUN_0055e910(param_1 + 0x14);

      FUN_0055e970(param_1 + 0x18);

      FUN_006549b0();

    }

  }

  return;

}
