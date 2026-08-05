// =============================================================================
// FUN_0044c270
// -----------------------------------------------------------------------------
// Stable ID: aa_0044c270
// Address:   0x0044c270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044c270 @ 0x0044c270
// Stable ID: aa_0044c270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_00446f30×2, FUN_0044c270, FUN_004645c0.
//  - Return sites: 3.

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

void __fastcall FUN_0044c270(uint param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  

  iVar1 = *(int *)(param_2 + 4);

  if (iVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(param_2 + 8) - iVar1 >> 3;

  }

  if (uVar2 < param_1) {

    if (iVar1 == 0) {

      FUN_00446f30(*(uint32_t /* width from decompiler */ *)(param_2 + 8),&stack0x00000004);

      return;

    }

    FUN_00446f30(*(uint32_t /* width from decompiler */ *)(param_2 + 8),&stack0x00000004);

    return;

  }

  if ((iVar1 != 0) && (param_1 < (uint)(*(int *)(param_2 + 8) - iVar1 >> 3))) {

    FUN_004645c0(iVar1 + param_1 * 8,*(int *)(param_2 + 8));

  }

  return;

}
