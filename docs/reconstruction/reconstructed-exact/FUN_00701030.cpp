// =============================================================================
// FUN_00701030
// -----------------------------------------------------------------------------
// Stable ID: aa_00701030
// Address:   0x00701030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00701030 @ 0x00701030
// Stable ID: aa_00701030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00701030.
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

void __fastcall FUN_00701030(int param_1)



{

  if (-1 < *(int *)(param_1 + 0x2108)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x2100),*(int *)(param_1 + 0x2108) << 5,0x12);

  }

  if (-1 < (int)*(uint *)(param_1 + 0x1b8)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x1b0),(*(uint *)(param_1 + 0x1b8) & 0x7fffffff) * 0x50,

               0x12);

  }

  if (-1 < *(int *)(param_1 + 0x10)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 8),*(int *)(param_1 + 0x10) << 2,0x12);

  }

  return;

}
