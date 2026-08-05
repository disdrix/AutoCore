// =============================================================================
// FUN_006523f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006523f0
// Address:   0x006523f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006523f0 @ 0x006523f0
// Stable ID: aa_006523f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006523f0.
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

void __fastcall FUN_006523f0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  puVar1 = (uint32_t /* width from decompiler */ *)param_1[4];

  *param_1 = &PTR_FUN_009e5b24;

  param_1[2] = &PTR_LAB_009e5b1c;

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

    if (*(short *)((int)puVar1 + 6) == 0) {

      (**(code **)*puVar1)(1);

    }

    param_1[4] = 0;

  }

  param_1[2] = &PTR_LAB_009db1d8;

  *param_1 = &PTR_LAB_009cc290;

  return;

}
