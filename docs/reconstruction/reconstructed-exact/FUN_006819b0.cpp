// =============================================================================
// FUN_006819b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006819b0
// Address:   0x006819b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006819b0 @ 0x006819b0
// Stable ID: aa_006819b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006819b0.
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

void __thiscall FUN_006819b0(int param_1,uint param_2)



{

  void *pvVar1;

  

  if ((*(uint *)(param_1 + 0x20) < param_2) && (param_2 != 0)) {

    if (*(void **)(param_1 + 0x1c) != (void *)0x0) {

      operator_delete__(*(void **)(param_1 + 0x1c));

    }

    pvVar1 = operator_new__(param_2);

    *(void **)(param_1 + 0x1c) = pvVar1;

    *(uint *)(param_1 + 0x20) = param_2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  }

  return;

}
