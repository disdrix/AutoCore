// =============================================================================
// FUN_00408a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00408a30
// Address:   0x00408a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00408a30 @ 0x00408a30
// Stable ID: aa_00408a30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00408a30.
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

void FUN_00408a30(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bc690;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  puVar1 = operator_new(0x30);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar1 = 0;

  }

  if (puVar1 + 1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1[1] = 0;

  }

  if (puVar1 + 2 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1[2] = 0;

  }

  *(uint8_t *)(puVar1 + 10) = 1;

  *(uint8_t *)((int)puVar1 + 0x29) = 0;

  ExceptionList = local_10;

  return;

}
