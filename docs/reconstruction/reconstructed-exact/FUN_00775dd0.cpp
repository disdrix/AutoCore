// =============================================================================
// FUN_00775dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00775dd0
// Address:   0x00775dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00775dd0 @ 0x00775dd0
// Stable ID: aa_00775dd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00770440, FUN_007707d0, FUN_007716f0, FUN_00774f50, FUN_00775dd0.
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

int FUN_00775dd0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  uint8_t local_10 [16];

  

  iVar1 = FUN_00770440();

  if (iVar1 == 0) {

    iVar1 = FUN_007716f0(param_1);

    if (iVar1 == 0) {

      iVar1 = FUN_00774f50(local_10,param_3);

    }

    FUN_007707d0();

  }

  return iVar1;

}
