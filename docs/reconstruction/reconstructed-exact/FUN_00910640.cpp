// =============================================================================
// FUN_00910640
// -----------------------------------------------------------------------------
// Stable ID: aa_00910640
// Address:   0x00910640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00910640 @ 0x00910640
// Stable ID: aa_00910640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00792600, FUN_0090fbd0, FUN_00910640.
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

void __fastcall FUN_00910640(int *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  FUN_00792600();

  FUN_0090fbd0(param_1);

  if (((*(char *)((int)param_1 + 0x509) != '\0') && (DAT_00d1b8dc != (int *)0x0)) &&

     (DAT_00d1b978 != 0)) {

    (**(code **)(*param_1 + 0xa8))(DAT_00d1b978);

    (**(code **)(*param_1 + 0xa8))(DAT_00d1b8dc);

    (**(code **)(*DAT_00d1b8dc + 0x43c))();

  }

  uVar2 = DAT_00aaaad4;

  param_1[0x1d6] = 0;

  iVar1 = *(int *)(DAT_00d1b644 + 0xe890);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10c) = uVar2;

  *(uint8_t *)(iVar1 + 0x48) = 1;

  *(uint8_t *)(iVar1 + 0xcc) = 1;

  return;

}
