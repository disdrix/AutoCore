// =============================================================================
// FUN_00546800
// -----------------------------------------------------------------------------
// Stable ID: aa_00546800
// Address:   0x00546800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00546800 @ 0x00546800
// Stable ID: aa_00546800
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, while×1.
//  - Notable callees: FUN_00545e30, FUN_00546800, FUN_0059dd10.
//  - Return sites: 3.

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

void __fastcall FUN_00546800(int param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a41fe;

  local_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_00545e30();

  iVar4 = 0;

  while( true ) {

    if (*(int *)(param_1 + 0x13c) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(param_1 + 0x140) - *(int *)(param_1 + 0x13c) >> 2;

    }

    pvVar1 = *(void **)(param_1 + 0x13c);

    if (iVar2 <= iVar4) break;

    piVar3 = (int *)((int)pvVar1 + iVar4 * 4);

    if ((*piVar3 != 0) && (pvVar1 = (void *)*piVar3, pvVar1 != (void *)0x0)) {

      FUN_0059dd10();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x13c) + iVar4 * 4) = 0;

    iVar4 = iVar4 + 1;

  }

  if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x13c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x140) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x144) = 0;

  ExceptionList = local_c;

  return;

}
