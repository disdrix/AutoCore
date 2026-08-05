// =============================================================================
// FUN_007fafd0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fafd0
// Address:   0x007fafd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fafd0 @ 0x007fafd0
// Stable ID: aa_007fafd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_007b5be0, FUN_007f9c60, FUN_007fafd0, FUN_0096efd0.
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

void __fastcall FUN_007fafd0(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b328e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00a8467c;

  local_4 = 0;

  puVar3 = param_1 + 0x126;

  iVar2 = 3;

  do {

    if ((void *)*puVar3 != (void *)0x0) {

      operator_delete__((void *)*puVar3);

    }

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  FUN_007f9c60();

  pvVar1 = (void *)param_1[0x14d];

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[0x14d] = 0;

  if ((void *)param_1[0x14e] != (void *)0x0) {

    operator_delete__((void *)param_1[0x14e]);

  }

  param_1[0x14e] = 0;

  if ((void *)param_1[0x14f] != (void *)0x0) {

    operator_delete__((void *)param_1[0x14f]);

  }

  param_1[0x14f] = 0;

  local_4 = 0xffffffff;

  FUN_007b5be0();

  ExceptionList = local_c;

  return;

}
