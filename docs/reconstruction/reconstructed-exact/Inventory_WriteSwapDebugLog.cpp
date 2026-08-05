// =============================================================================
// Inventory_WriteSwapDebugLog
// -----------------------------------------------------------------------------
// Purpose:  Appends before/after cargo swap dump lines to InventoryLog.txt.
//
// Address:  0x00931870  (autoassault.exe, image base 0x400000)
// Stable:   aa_00931870
// System:   inventory-transfer
//
// String evidence: "InventoryLog.txt" / "-----Before Swap-----"
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_00931870.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_00931870 using string evidence: "InventoryLog.txt" / "-----Before Swap-----"
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

void Inventory_WriteSwapDebugLog(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

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
