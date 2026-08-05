// =============================================================================
// FUN_00429850
// -----------------------------------------------------------------------------
// Stable ID: aa_00429850
// Address:   0x00429850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00429850 @ 0x00429850
// Stable ID: aa_00429850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_00429970×2, FUN_00429850, FUN_00456660.
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

void __fastcall FUN_00429850(uint param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  

  iVar1 = *(int *)(param_2 + 4);

  if (iVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(param_2 + 8) - iVar1 >> 2;

  }

  if (param_1 <= uVar2) {

    if ((iVar1 != 0) && (param_1 < (uint)(*(int *)(param_2 + 8) - iVar1 >> 2))) {

      FUN_00456660(param_2,iVar1 + param_1 * 4,*(int *)(param_2 + 8));

    }

    return;

  }

  if (iVar1 != 0) {

    FUN_00429970(*(uint32_t /* width from decompiler */ *)(param_2 + 8));

    return;

  }

  FUN_00429970(*(uint32_t /* width from decompiler */ *)(param_2 + 8));

  return;

}
