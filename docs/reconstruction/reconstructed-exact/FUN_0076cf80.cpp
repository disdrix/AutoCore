// =============================================================================
// FUN_0076cf80
// -----------------------------------------------------------------------------
// Stable ID: aa_0076cf80
// Address:   0x0076cf80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076cf80 @ 0x0076cf80
// Stable ID: aa_0076cf80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT31, FUN_0076cd60, FUN_0076cf80, GetModuleFileNameA.
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

void FUN_0076cf80(void)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *unaff_EDI;

  CHAR local_110 [260];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac272;

  local_c = ExceptionList;

  local_4 = 0;

  DAT_00d1f040 = unaff_EDI;

  ExceptionList = &local_c;

  *unaff_EDI = 0;

  unaff_EDI[1] = 0;

  *(uint8_t *)(unaff_EDI + 2) = 0;

  GetModuleFileNameA((HMODULE)0x0,local_110,0x104);

  pvVar1 = operator_new(0x80);

  local_4 = CONCAT31(local_4._1_3_,1);

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0076cd60(0);

  }

  unaff_EDI[1] = uVar2;

  *unaff_EDI = uVar2;

  ExceptionList = local_c;

  return;

}
