// =============================================================================
// FUN_00962270
// -----------------------------------------------------------------------------
// Stable ID: aa_00962270
// Address:   0x00962270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00962270 @ 0x00962270
// Stable ID: aa_00962270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0044e560, FUN_00962270.
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

uint32_t /* width from decompiler */ __fastcall FUN_00962270(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad563;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar1 = operator_new(0x58);

  local_4 = 0;

  if (pvVar1 != (void *)0x0) {

    uVar2 = FUN_0044e560(pvVar1,param_1 + 0x3c,*(uint32_t /* width from decompiler */ *)(param_1 + 0x14));

    ExceptionList = local_c;

    return uVar2;

  }

  ExceptionList = local_c;

  return 0;

}
