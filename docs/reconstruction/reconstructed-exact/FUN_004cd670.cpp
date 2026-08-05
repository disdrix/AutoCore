// =============================================================================
// FUN_004cd670
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd670
// Address:   0x004cd670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cd670 @ 0x004cd670
// Stable ID: aa_004cd670
// Embedded strings (evidence for future rename):
//   - "@@CVOGSectorMap::InitGenerators CVOGCreatureGenerator"
//   - "@@CVOGSectorMap::InitGenerators CVOGLootGenerator"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CONCAT31×2, FUN_007a4390×2, FUN_007a4400×2, FUN_004cd670, FUN_0050c1b0, FUN_00568920.
//  - Strings: "@@CVOGSectorMap::InitGenerators CVOGCreatureGenerator"; "@@CVOGSectorMap::InitGenerators CVOGLootGenerator".
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

void FUN_004cd670(void)



{

  void *pvVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1ea2;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_007a4400("@@CVOGSectorMap::InitGenerators CVOGCreatureGenerator");

  local_4 = 0;

  pvVar1 = operator_new(0x2c);

  local_4 = CONCAT31(local_4._1_3_,1);

  if (pvVar1 == (void *)0x0) {

    DAT_00b037ec = 0;

  }

  else {

    DAT_00b037ec = FUN_00568920(DAT_00b041fc,1,pvVar1);

  }

  local_4 = 0xffffffff;

  FUN_007a4390();

  FUN_007a4400("@@CVOGSectorMap::InitGenerators CVOGLootGenerator");

  local_4 = 2;

  pvVar1 = operator_new(0xbc);

  local_4 = CONCAT31(local_4._1_3_,3);

  if (pvVar1 == (void *)0x0) {

    DAT_00b037e8 = 0;

  }

  else {

    DAT_00b037e8 = FUN_0050c1b0(DAT_00b041fc,pvVar1);

  }

  local_4 = 0xffffffff;

  FUN_007a4390();

  ExceptionList = pvStack_c;

  return;

}
