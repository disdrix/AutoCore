// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_0095c460
// -----------------------------------------------------------------------------
// Stable ID: aa_0095c460
// Callee of Named_Client_InitInstance
// Address:   0x0095c460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×7, return×3.
//  - Notable callees: FUN_0075e830, FUN_00934420, FUN_0095c460, GlobalMemoryStatus.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_Client_InitInstance_0095c460(void)



{

  int unaff_ESI;

  _MEMORYSTATUS local_20;

  

  DAT_00d1b210 = *(char *)(unaff_ESI + 0x14);

  if (DAT_00d1b210 == '\0') {

    *(uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1b644 + 0xe890) + 0x104) = DAT_00aaa7ac;

  }

  else {

    *(uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1b644 + 0xe890) + 0x104) = DAT_00aaa884;

  }

  if ((DAT_00afa2dc < 1) && (DAT_00afe100 = DAT_00afe100 == '\0', DAT_00d1b644 != 0)) {

    *(char *)(*(int *)(DAT_00d1b644 + 0xe894) + 0x78) = DAT_00afe100;

  }

  DAT_00d1b24d = *(char *)(unaff_ESI + 0x51);

  if ((DAT_00d1a851 != '\0') && (DAT_00d1b24d == '\0')) {

    DAT_00d1b24d = '\x01';

  }

  if ((DAT_00d1b780 == (int *)0x0) || (DAT_00d1a8f5 = DAT_00d1b24d, *DAT_00d1b780 != DAT_00d1b778))

  {

    DAT_00d1a8f5 = DAT_00d1a851 != '\0';

  }

  FUN_0075e830(*(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x28));

  FUN_00934420();

  if (DAT_00d1b628 != 0) {

    *(uint *)(DAT_00d1b628 + 0x2e8) = (uint)*(byte *)(unaff_ESI + 0x54);

  }

  DAT_00b035c8 = *(char *)(unaff_ESI + 0x22) == '\0';

  if (*(char *)(unaff_ESI + 0x23) != '\0') {

    DAT_00b036f0 = *(uint8_t *)(unaff_ESI + 0x50);

    return;

  }

  GlobalMemoryStatus(&local_20);

  if (0x20000000 < local_20.dwTotalPhys) {

    DAT_00b036f0 = *(uint8_t *)(unaff_ESI + 0x50);

    return;

  }

  DAT_00d1793d = 1;

  DAT_00b036f0 = *(uint8_t *)(unaff_ESI + 0x50);

  return;

}
