// =============================================================================
// FUN_00753db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00753db0
// Address:   0x00753db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00753db0 @ 0x00753db0
// Stable ID: aa_00753db0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_00753db0, FUN_00759de0.
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

void __fastcall FUN_00753db0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int *piVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  pvStack_c = ExceptionList;

  puStack_8 = &LAB_009b3fa0;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a9f974;

  local_4 = 1;

  piVar1 = (int *)param_1[0x43];

  for (piVar2 = (int *)param_1[0x42]; piVar2 != piVar1; piVar2 = piVar2 + 1) {

    if ((uint32_t /* width from decompiler */ *)*piVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)*piVar2)(1);

    }

  }

  if ((void *)param_1[0x42] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x42]);

  }

  param_1[0x42] = 0;

  param_1[0x43] = 0;

  param_1[0x44] = 0;

  local_4 = 0xffffffff;

  FUN_00759de0();

  ExceptionList = pvStack_c;

  return;

}
