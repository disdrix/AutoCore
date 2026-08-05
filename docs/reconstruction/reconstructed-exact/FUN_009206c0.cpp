// =============================================================================
// FUN_009206c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009206c0
// Address:   0x009206c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009206c0 @ 0x009206c0
// Stable ID: aa_009206c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00910ad0, FUN_009206c0.
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

void __fastcall FUN_009206c0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009b7e5b;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a2f0a4;

  local_4 = 1;

  iVar1 = param_1[0x348];

  if (iVar1 != 0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1))(1);

  }

  param_1[0x348] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x31d] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x31d])(1);

  }

  param_1[0x31d] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x31c] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x31c])(1);

  }

  param_1[0x31c] = 0;

  local_4 = local_4 & 0xffffff00;

  if ((void *)param_1[0x328] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x328]);

  }

  param_1[0x328] = 0;

  param_1[0x329] = 0;

  param_1[0x32a] = 0;

  local_4 = 0xffffffff;

  FUN_00910ad0();

  ExceptionList = pvStack_c;

  return;

}
