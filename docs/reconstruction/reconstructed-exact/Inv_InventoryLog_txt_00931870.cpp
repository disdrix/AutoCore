// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, for×2.
//  - Notable callees: fprintf×3, fopen×2, FUN_00404060, FUN_00931870, fclose.
//  - Strings: "InventoryLog.txt"; ");

  if ((_File == (FILE *)0x0) && (_File = fopen("; "wt+"; "-----Before Swap-----".
//  - Return sites: 3.

// =============================================================================
// Inv_InventoryLog_txt_00931870
// -----------------------------------------------------------------------------
// Stable ID: aa_00931870
// Address:   0x00931870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "InventoryLog.txt"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Inv_InventoryLog_txt_00931870(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ *param_5,uint32_t /* width from decompiler */ param_6,char param_7)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  FILE *_File;

  uint32_t /* width from decompiler */ uVar5;

  char *_Format;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009ad34d;

  pvStack_c = ExceptionList;

  local_4 = 1;

  ExceptionList = &pvStack_c;

  _File = fopen("InventoryLog.txt","at");

  if ((_File == (FILE *)0x0) && (_File = fopen("InventoryLog.txt","wt+"), _File == (FILE *)0x0)) {

    local_4 = local_4 & 0xffffff00;

    FUN_00404060();

                    /* WARNING: Subroutine does not return */

    operator_delete(param_2);

  }

  if (param_7 == '\0') {

    _Format = "-----Before Swap-----";

  }

  else {

    _Format = "\n-----After Swap-----";

  }

  fprintf(_File,_Format);

  for (puVar1 = (uint32_t /* width from decompiler */ *)*param_2; puVar1 != param_2; puVar1 = (uint32_t /* width from decompiler */ *)*puVar1) {

    piVar2 = (int *)puVar1[2];

    if (piVar2 != (int *)0x0) {

      iVar3 = piVar2[0x58];

      iVar4 = piVar2[0x59];

      uVar5 = (**(code **)(*piVar2 + 0x25c))();

      fprintf(_File,"\ncoid: %I64d \nquantity: %d",iVar3,iVar4,uVar5);

    }

  }

  for (puVar1 = (uint32_t /* width from decompiler */ *)*param_5; puVar1 != param_5; puVar1 = (uint32_t /* width from decompiler */ *)*puVar1) {

    piVar2 = (int *)puVar1[2];

    if (piVar2 != (int *)0x0) {

      iVar3 = piVar2[0x58];

      iVar4 = piVar2[0x59];

      uVar5 = (**(code **)(*piVar2 + 0x25c))();

      fprintf(_File,"\ncoid: %I64d \nquantity: %d",iVar3,iVar4,uVar5);

    }

  }

  fclose(_File);

  local_4 = local_4 & 0xffffff00;

  puVar1 = (uint32_t /* width from decompiler */ *)*param_2;

  *param_2 = param_2;

  param_2[1] = param_2;

  if (puVar1 != param_2) {

                    /* WARNING: Subroutine does not return */

    operator_delete(puVar1);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(param_2);

}
