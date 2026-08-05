// =============================================================================
// FUN_00984890
// -----------------------------------------------------------------------------
// Stable ID: aa_00984890
// Address:   0x00984890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00984890 @ 0x00984890
// Stable ID: aa_00984890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: EnterCriticalSection, FUN_00719ba0, FUN_00984890, LeaveCriticalSection.
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

uint32_t /* width from decompiler */ FUN_00984890(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int unaff_EDI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af7b3;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (*(char *)(unaff_EDI + 0x50) != '\0') {

    ExceptionList = &pvStack_c;

    EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x38));

  }

  local_4 = 0;

  puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x30);

  for (puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x2c); puVar2 != puVar1; puVar2 = puVar2 + 1) {

    FUN_00719ba0(*puVar2);

  }

  if (*(char *)(unaff_EDI + 0x50) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x38));

  }

  ExceptionList = pvStack_c;

  return 0;

}
