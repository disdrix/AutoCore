// =============================================================================
// FUN_00445970
// -----------------------------------------------------------------------------
// Stable ID: aa_00445970
// Address:   0x00445970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00445970 @ 0x00445970
// Stable ID: aa_00445970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00414b60, FUN_00445970, FUN_00446450, FUN_004464d0, _aligned_free.
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

void __thiscall FUN_00445970(uint param_1)



{

  uint uVar1;

  int iVar2;

  int unaff_ESI;

  void *in_stack_00000038;

  void *in_stack_000000cc;

  uint32_t /* width from decompiler */ in_stack_000000d0;

  uint32_t /* width from decompiler */ in_stack_000000d4;

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bee88;

  local_c = ExceptionList;

  local_4 = 0;

  iVar2 = *(int *)(unaff_ESI + 4);

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = (*(int *)(unaff_ESI + 8) - iVar2) / 0xd4;

  }

  local_10 = param_1;

  if (uVar1 < param_1) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(unaff_ESI + 8) - iVar2) / 0xd4;

    }

    ExceptionList = &local_c;

    FUN_004464d0(unaff_ESI,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),param_1 - iVar2,&stack0x00000004);

  }

  else {

    ExceptionList = &local_c;

    if ((iVar2 != 0) &&

       (ExceptionList = &local_c, param_1 < (uint)((*(int *)(unaff_ESI + 8) - iVar2) / 0xd4))) {

      ExceptionList = &local_c;

      FUN_00446450(unaff_ESI,&local_10,iVar2 + param_1 * 0xd4,*(int *)(unaff_ESI + 8));

    }

  }

  _aligned_free(in_stack_00000038);

  in_stack_00000038 = (void *)0x0;

  if (in_stack_000000cc == (void *)0x0) {

    in_stack_000000cc = (void *)0x0;

    in_stack_000000d0 = 0;

    in_stack_000000d4 = 0;

    FUN_00414b60();

    ExceptionList = local_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(in_stack_000000cc);

}
