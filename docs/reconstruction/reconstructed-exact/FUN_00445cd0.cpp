// =============================================================================
// FUN_00445cd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00445cd0
// Address:   0x00445cd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00445cd0 @ 0x00445cd0
// Stable ID: aa_00445cd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00445cd0, FUN_00446b60, FUN_00446be0, FUN_00447660.
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

void __thiscall FUN_00445cd0(uint param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  uint uVar2;

  int unaff_ESI;

  uint local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009be868;

  pvStack_c = ExceptionList;

  local_4 = 0;

  iVar1 = *(int *)(unaff_ESI + 4);

  if (iVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = (*(int *)(unaff_ESI + 8) - iVar1) / 0xc;

  }

  local_10 = param_1;

  if (uVar2 < param_1) {

    ExceptionList = &pvStack_c;

    FUN_00446be0();

  }

  else {

    ExceptionList = &pvStack_c;

    if ((iVar1 != 0) &&

       (ExceptionList = &pvStack_c, param_1 < (uint)((*(int *)(unaff_ESI + 8) - iVar1) / 0xc))) {

      ExceptionList = &pvStack_c;

      FUN_00446b60(unaff_ESI,&local_10,iVar1 + param_1 * 0xc,*(int *)(unaff_ESI + 8));

    }

  }

  local_4 = 0xffffffff;

  FUN_00447660(&local_10,*param_3,param_3);

                    /* WARNING: Subroutine does not return */

  operator_delete(param_3);

}
