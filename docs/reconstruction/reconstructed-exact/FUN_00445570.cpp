// =============================================================================
// FUN_00445570
// -----------------------------------------------------------------------------
// Stable ID: aa_00445570
// Address:   0x00445570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00445570 @ 0x00445570
// Stable ID: aa_00445570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00445570, FUN_00445900, FUN_00448270.
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

void __fastcall FUN_00445570(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ in_EAX;

  int local_4;

  

  iVar1 = *(int *)(param_1 + 4);

  local_4 = param_1;

  if ((iVar1 != 0) &&

     ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x24) <

      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 0x24))) {

    iVar1 = *(int *)(param_1 + 8);

    FUN_00448270(param_1);

    *(int *)(param_1 + 8) = iVar1 + 0x24;

    return;

  }

  FUN_00445900(&local_4,*(uint32_t /* width from decompiler */ *)(param_1 + 8),in_EAX);

  return;

}
