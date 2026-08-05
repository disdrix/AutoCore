// =============================================================================
// FUN_00504d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00504d40
// Address:   0x00504d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

void __thiscall FUN_00504d40(int param_1,uint32_t /* width from decompiler */ *param_2,void *param_3)

{
  int iVar1;
  uint32_t /* width from decompiler */ *puVar2;
  int *piVar3;
  void *pvVar4;
  uint32_t /* width from decompiler */ uVar5;
  uint32_t /* width from decompiler */ uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a3028;
  local_c = ExceptionList;
  if ((((char)param_2 < '\x03') && (-1 < (char)param_2)) &&
     (iVar8 = (int)(char)param_2, *(int *)(param_1 + 0x340 + iVar8 * 4) != 0)) {
    piVar3 = *(int **)(param_1 + 0x374 + iVar8 * 0xc);
    iVar1 = param_1 + iVar8 * 0xc;
    ExceptionList = &local_c;
    if (piVar3 != (int *)0x0) {
      ExceptionList = &local_c;
      (**(code **)(*piVar3 + 0x1c))();
      if (*(uint32_t /* width from decompiler */ **)(iVar1 + 0x374) != (uint32_t /* width from decompiler */ *)0x0) {
        (**(code **)**(uint32_t /* width from decompiler */ **)(iVar1 + 0x374))(1);
      }
      *(uint32_t /* width from decompiler */ *)(iVar1 + 0x374) = 0;
      if (*(uint32_t /* width from decompiler */ **)(iVar1 + 0x370) != (uint32_t /* width from decompiler */ *)0x0) {
        (**(code **)**(uint32_t /* width from decompiler */ **)(iVar1 + 0x370))(1);
      }
      param_2 = (uint32_t /* width from decompiler */ *)(param_1 + (iVar8 * 3 + 0xdb) * 4);
      *(uint32_t /* width from decompiler */ *)(iVar1 + 0x370) = 0;
      pvVar4 = (void *)*param_2;
      if (pvVar4 != (void *)0x0) {
        FUN_0074ecf0();
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar4);
      }
      *param_2 = 0;
    }
    param_2 = operator_new(0x78);
    uStack_4 = 0;
    if (param_2 == (void *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_0074ed90();
    }
    puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + (iVar8 * 3 + 0xdb) * 4);
    *puVar2 = uVar6;
    uStack_4 = 0xffffffff;
    FUN_00989e00(&param_2,param_3);
    iVar7 = FUN_0074ee40(&param_2);
    if (iVar7 < 0) {
      pvVar4 = (void *)*puVar2;
      if (pvVar4 != (void *)0x0) {
        FUN_0074ecf0();
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar4);
      }
      *puVar2 = 0;
      ExceptionList = local_c;
      return;
    }
    fVar9 = (float10)FUN_0079a110();
    FUN_0074e910(0,(float)fVar9);
    param_3 = operator_new(0x5c);
    uStack_4 = 1;
    if (param_3 == (void *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_0074d750();
    }
    uStack_4 = 0xffffffff;
    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x374) = uVar6;
    param_3 = operator_new(0x14);
    uStack_4 = 2;
    if (param_3 == (void *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_0040d4f0();
    }
    uVar5 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x340 + iVar8 * 4);
    uStack_4 = 0xffffffff;
    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x370) = uVar6;
    FUN_0074d420(uVar5);
    (**(code **)(**(int **)(iVar1 + 0x374) + 4))(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x370),0);
    (**(code **)(**(int **)(iVar1 + 0x374) + 0xc))(*puVar2);
    (**(code **)(**(int **)(iVar1 + 0x374) + 0x18))(*puVar2,0,0x3f800000);
  }
  ExceptionList = local_c;
  return;
}
