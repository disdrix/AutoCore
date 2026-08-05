// =============================================================================
// FUN_00745f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00745f80
// Address:   0x00745f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00745f80 @ 0x00745f80
// Stable ID: aa_00745f80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: EnterCriticalSection, FUN_00745f80, LeaveCriticalSection.
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

void FUN_00745f80(void)



{

  int unaff_EDI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac169;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (*(char *)(unaff_EDI + 0x38) != '\0') {

    ExceptionList = &pvStack_c;

    EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x20));

  }

  local_4 = 0;

  if (*(uint32_t /* width from decompiler */ **)(unaff_EDI + 8) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_EDI + 8))(1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8) = 0;

  if (*(char *)(unaff_EDI + 0x38) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x20));

  }

  ExceptionList = pvStack_c;

  return;

}
