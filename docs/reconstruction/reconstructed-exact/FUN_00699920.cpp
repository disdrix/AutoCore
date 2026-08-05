// =============================================================================
// FUN_00699920
// -----------------------------------------------------------------------------
// Stable ID: aa_00699920
// Address:   0x00699920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00699920 @ 0x00699920
// Stable ID: aa_00699920
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00687b70, FUN_00699920, FUN_0069f400.
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

uint16_t * __fastcall FUN_00699920(uint16_t *param_1)



{

  void *pvVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aad4b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = 0;

  pvVar1 = operator_new__(0x100);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    iVar2 = 4;

    do {

      FUN_0069f400();

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  local_4 = 0xffffffff;

  *(void **)(param_1 + 2) = pvVar1;

  FUN_00687b70(4);

  ExceptionList = local_c;

  return param_1;

}
