// =============================================================================
// FUN_005fa640
// -----------------------------------------------------------------------------
// Stable ID: aa_005fa640
// Address:   0x005fa640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fa640 @ 0x005fa640
// Stable ID: aa_005fa640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005f57e0, FUN_005fa640.
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

uint32_t /* width from decompiler */ FUN_005fa640(void)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a7b4b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar1 = operator_new(0xf8);

  local_4 = 0;

  if (pvVar1 != (void *)0x0) {

    uVar2 = FUN_005f57e0(pvVar1);

    ExceptionList = local_c;

    return uVar2;

  }

  ExceptionList = local_c;

  return 0;

}
