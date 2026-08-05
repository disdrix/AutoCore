// =============================================================================
// FUN_0099cf50
// -----------------------------------------------------------------------------
// Stable ID: aa_0099cf50
// Address:   0x0099cf50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099cf50 @ 0x0099cf50
// Stable ID: aa_0099cf50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00981fb0×2, FUN_0099cf50.
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

void __thiscall FUN_0099cf50(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  if (*(int *)(param_1 + 4) == 0) {

    puVar1 = operator_new(8);

    if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

      *puVar1 = 0;

      puVar1[1] = 0;

      *(uint32_t /* width from decompiler */ **)(param_1 + 4) = puVar1;

      FUN_00981fb0(param_2);

      return;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  }

  FUN_00981fb0(param_2);

  return;

}
