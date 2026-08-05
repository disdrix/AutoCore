// =============================================================================
// Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d1b40
// -----------------------------------------------------------------------------
// Stable ID: aa_008d1b40
// Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
// Address:   0x008d1b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_00405ef0, FUN_00521b40, FUN_00523200, FUN_00523430, FUN_008cfa00, FUN_008d19f0, FUN_008d1b40.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall

Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d1b40(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,int param_4,uint32_t /* width from decompiler */ param_5,void *param_6

            ,int param_7)



{

  int *piVar1;

  int iVar2;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &DAT_009ad2a6;

  local_c = ExceptionList;

  local_4 = 0;

  if ((((param_6 != (void *)0x0) && (iVar2 = param_7 - (int)param_6 >> 2, iVar2 != 0)) &&

      (*(int *)(param_1 + 0x544) != 0)) && (*(int *)(*(int *)(param_1 + 0x544) + 0x48) != 0)) {

    piVar1 = (int *)(param_1 + 0x80c + param_3 * 4);

    ExceptionList = &local_c;

    *piVar1 = *piVar1 + param_4;

    if (*(int *)(param_1 + 0x828 + param_3 * 4) <= *(int *)(param_1 + 0x80c + param_3 * 4)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x80c + param_3 * 4) = 0;

    }

    if (*(int *)(param_1 + 0x80c + param_3 * 4) < 0) {

      *(int *)(param_1 + 0x80c + param_3 * 4) = iVar2 + -1;

    }

    FUN_00523430(param_2,*(uint32_t /* width from decompiler */ *)((int)param_6 + *(int *)(param_1 + 0x80c + param_3 * 4) * 4)

                 ,0);

    FUN_008d19f0();

    FUN_00523200();

    FUN_00521b40();

    FUN_008cfa00(param_1);

    local_4 = 0xffffffff;

    FUN_00405ef0();

    ExceptionList = local_c;

    return;

  }

  local_4 = 0xffffffff;

  if (param_6 != (void *)0x0) {

    ExceptionList = &local_c;

                    /* WARNING: Subroutine does not return */

    operator_delete(param_6);

  }

  return;

}
