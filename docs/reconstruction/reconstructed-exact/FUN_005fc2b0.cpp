// =============================================================================
// FUN_005fc2b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005fc2b0
// Address:   0x005fc2b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fc2b0 @ 0x005fc2b0
// Stable ID: aa_005fc2b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005fc2b0, FUN_00649e70, FUN_0064a1b0.
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

void FUN_005fc2b0(void)



{

  int iVar1;

  uint8_t auStack_b8 [148];

  void *pvStack_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a7bde;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  FUN_00649e70();

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xc0,0x2e);

  *(uint16_t *)(iVar1 + 4) = 0xc0;

  pvStack_1c = (void *)0x0;

  FUN_0064a1b0(auStack_b8);

  ExceptionList = pvStack_24;

  return;

}
