// =============================================================================
// FUN_00653c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00653c00
// Address:   0x00653c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00653c00 @ 0x00653c00
// Stable ID: aa_00653c00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00652320, FUN_006523f0, FUN_00653c00, FUN_00664640, FUN_006646b0.
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

void __fastcall FUN_00653c00(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  puVar1 = param_1 + 5;

  *param_1 = &PTR_FUN_009e5cd4;

  param_1[2] = &PTR_LAB_009e5ccc;

  *puVar1 = &PTR_LAB_009e5cc4;

  FUN_006646b0(puVar1);

  if (param_1[3] != 0) {

    FUN_00652320(0);

  }

  iVar2 = param_1[6];

  if (iVar2 != 0) {

    FUN_00664640();

    (**(code **)(*DAT_00b05060 + 0x14))(iVar2,0x28,0x16);

  }

  *puVar1 = &PTR_LAB_009db1e0;

  FUN_006523f0();

  return;

}
