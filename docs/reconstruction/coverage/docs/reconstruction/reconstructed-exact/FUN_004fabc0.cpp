// =============================================================================
// FUN_004fabc0
// -----------------------------------------------------------------------------
// Stable ID: aa_004fabc0
// Address:   0x004fabc0  (autoassault.exe, image base 0x400000)
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

uint __thiscall FUN_004fabc0(int param_1,int *param_2,uint32_t /* width from decompiler */ *param_3)

{
  int iVar1;
  char cVar2;
  uint32_t /* width from decompiler */ uVar3;
  uint uVar4;
  uint32_t /* width from decompiler */ uVar5;
  
  if (param_2 == (int *)0x0) {
    return 8;
  }
  if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {
    *param_3 = 0;
  }
  param_2[0x5f] = param_2[0x5f] | 0x10;
  FUN_00512670();
  if (((uint)param_2[0x5f] >> 0x13 & 1) != 0) {
    return 9;
  }
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);
  if ((iVar1 != 0) && (*(char *)(iVar1 + 0xf6) != '\0')) {
    return 0xf;
  }
  uVar5 = 0;
  uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0,1);
  cVar2 = FUN_00514390(uVar3,uVar5);
  if (cVar2 != '\0') {
    switch(*(uint32_t /* width from decompiler */ *)(param_2[0x2a] + 0x38)) {
    case 6:
      uVar3 = __RTDynamicCast(param_2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                              &CVOGSimpleObject<class_CVOGGraphicsBase>::RTTI_Type_Descriptor,0,
                              param_3);
      uVar4 = FUN_004f6940(uVar3,param_3);
      return uVar4;
    default:
      return 8;
    case 8:
    case 0x32:
      return 0xc;
    case 10:
      uVar3 = (**(code **)(*param_2 + 500))(param_3);
      uVar4 = FUN_004f6840(uVar3,param_3);
      return uVar4;
    case 0xc:
      uVar3 = (**(code **)(*param_2 + 0x1e0))(param_3);
      uVar4 = FUN_004f65e0(uVar3,param_3);
      return uVar4;
    case 0xe:
      goto switchD_004fac7b_caseD_e;
    case 0x10:
      uVar3 = (**(code **)(*param_2 + 0x1f0))(param_3);
      uVar4 = FUN_004f6890(uVar3,param_3);
      return uVar4;
    case 0x1c:
      uVar3 = (**(code **)(*param_2 + 0x1f8))(param_3);
      uVar4 = FUN_004f67e0(uVar3,param_3);
      return uVar4;
    }
  }
  return 6;
switchD_004fac7b_caseD_e:
  cVar2 = FUN_004ce5f0(param_1);
  if (cVar2 == '\0') {
    return 1;
  }
  cVar2 = FUN_004f6560();
  return -(uint)(cVar2 != '\0') & 0xe;
}
