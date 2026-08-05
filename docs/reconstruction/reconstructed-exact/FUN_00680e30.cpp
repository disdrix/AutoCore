// =============================================================================
// FUN_00680e30
// -----------------------------------------------------------------------------
// Stable ID: aa_00680e30
// Address:   0x00680e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00680e30 @ 0x00680e30
// Stable ID: aa_00680e30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00680e30.
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

void __thiscall FUN_00680e30(int param_1,uint param_2)



{

  void *pvVar1;

  

  if (*(uint *)(param_1 + 8) < param_2) {

    if ((char)param_2 != '\0') {

      param_2 = ((param_2 >> 8) + 1) * 0x100;

    }

    operator_delete__(*(void **)(param_1 + 4));

    pvVar1 = operator_new__(param_2);

    *(uint *)(param_1 + 8) = param_2;

    *(void **)(param_1 + 4) = pvVar1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  return;

}
