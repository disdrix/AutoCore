// =============================================================================
// FUN_008d1890
// -----------------------------------------------------------------------------
// Stable ID: aa_008d1890
// Address:   0x008d1890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d1890 @ 0x008d1890
// Stable ID: aa_008d1890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_00405ef0, FUN_00521b40, FUN_00523200, FUN_0052a3f0, FUN_008cfa00, FUN_008d1890.
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

void __thiscall

FUN_008d1890(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,void *param_5,int param_6)



{

  int *piVar1;

  int iVar2;

  int unaff_EBX;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac5d0;

  local_c = ExceptionList;

  local_4 = 0;

  if ((((param_5 != (void *)0x0) && (param_6 - (int)param_5 >> 2 != 0)) &&

      (*(int *)(param_1 + 0x544) != 0)) && (*(int *)(*(int *)(param_1 + 0x544) + 0x48) != 0)) {

    iVar2 = *(int *)(param_1 + 0x80c + param_2 * 4);

    if ((unaff_EBX == 1) || ((unaff_EBX == 4 && (*(int *)(param_1 + 0x5a4) == 1)))) {

      iVar2 = 0;

    }

    ExceptionList = &local_c;

    if (1 < *(int *)(*(int *)((int)param_5 + iVar2 * 4) + 0x90)) {

      piVar1 = (int *)(param_1 + 0x860 + param_2 * 4);

      ExceptionList = &local_c;

      *piVar1 = *piVar1 + param_3;

      if (*(int *)(param_1 + 0x860 + param_2 * 4) < 1) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x860 + param_2 * 4) =

             *(uint32_t /* width from decompiler */ *)(*(int *)((int)param_5 + iVar2 * 4) + 0x90);

      }

      if (*(int *)(*(int *)((int)param_5 + iVar2 * 4) + 0x90) <

          *(int *)(param_1 + 0x860 + param_2 * 4)) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x860 + param_2 * 4) = 1;

      }

      FUN_0052a3f0(unaff_EBX,*(uint32_t /* width from decompiler */ *)((int)param_5 + iVar2 * 4),

                   *(uint32_t /* width from decompiler */ *)(param_1 + 0x860 + param_2 * 4));

      FUN_00523200();

      FUN_00521b40();

      FUN_008cfa00(param_1);

    }

    local_4 = 0xffffffff;

    FUN_00405ef0();

    ExceptionList = local_c;

    return;

  }

  local_4 = 0xffffffff;

  if (param_5 != (void *)0x0) {

    ExceptionList = &local_c;

                    /* WARNING: Subroutine does not return */

    operator_delete(param_5);

  }

  return;

}
