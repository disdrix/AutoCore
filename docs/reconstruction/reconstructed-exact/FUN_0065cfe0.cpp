// =============================================================================
// FUN_0065cfe0
// -----------------------------------------------------------------------------
// Stable ID: aa_0065cfe0
// Address:   0x0065cfe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065cfe0 @ 0x0065cfe0
// Stable ID: aa_0065cfe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0065cfe0.
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

void __fastcall FUN_0065cfe0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = 0;

  *param_1 = &PTR_FUN_009e7068;

  if (0 < (int)param_1[4]) {

    iVar1 = 0;

    do {

      (*(code *)**(uint32_t /* width from decompiler */ **)(param_1[3] + iVar1))(0);

      iVar2 = iVar2 + 1;

      iVar1 = iVar1 + 0x1c;

    } while (iVar2 < (int)param_1[4]);

  }

  if (-1 < (int)param_1[5]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[3],(param_1[5] & 0x7fffffff) * 0x1c,0x12);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
