// =============================================================================
// FUN_007ab0f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ab0f0
// Address:   0x007ab0f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ab0f0 @ 0x007ab0f0
// Stable ID: aa_007ab0f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00403450, FUN_007ab0f0, free.
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

void FUN_007ab0f0(int *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *unaff_ESI;

  uint8_t **unaff_EDI;

  uint8_t *local_90;

  uint8_t local_8c [124];

  void *pvStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009aba77;

  local_c = ExceptionList;

  iVar1 = *param_1;

  if (iVar1 == 0) {

    if ((void *)unaff_ESI[0xa2] != (void *)0x0) {

      ExceptionList = &local_c;

      operator_delete__((void *)unaff_ESI[0xa2]);

    }

    unaff_ESI[0xa2] = 0;

    ExceptionList = local_c;

    return;

  }

  local_90 = local_8c;

  ExceptionList = &local_c;

  uVar2 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(iVar1,uVar2);

  uStack_4 = 0;

  (**(code **)(*unaff_ESI + 0x308))(local_90);

  if (unaff_EDI != &local_90) {

    free(unaff_EDI);

  }

  ExceptionList = pvStack_10;

  return;

}
