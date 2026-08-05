// =============================================================================
// FUN_00760d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00760d80
// Address:   0x00760d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00760d80 @ 0x00760d80
// Stable ID: aa_00760d80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_004406e0×2, FUN_00412d40, FUN_004376e0, FUN_00760830, FUN_00760d80, FUN_00972e50.
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

int * __fastcall

FUN_00760d80(int *param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ param_4,int param_5,int param_6)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  uint8_t auStack_60 [60];

  void *pvStack_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009b0a52;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  iVar2 = (**(code **)(*param_1 + 4))();

  if (iVar2 != 0x47504345) {

    ExceptionList = pvStack_1c;

    return (int *)0x0;

  }

  pvVar3 = operator_new(0xc4);

  piVar5 = (int *)0x0;

  uStack_14 = 0;

  if (pvVar3 != (void *)0x0) {

    piVar5 = (int *)FUN_004376e0(pvVar3,param_1);

  }

  uStack_14 = 0xffffffff;

  if (((param_1[0x16] != 0) && (param_1[0x17] != 0)) &&

     (*(int *)(param_1[0x17] + 0x1c) != param_1[0x18])) {

    (**(code **)(*param_1 + 0x80))();

  }

  iVar2 = param_1[0x19];

  if ((*(byte *)(iVar2 + 0xbc) & 1) != 0) {

    iVar2 = FUN_00972e50();

  }

  iVar1 = *piVar5;

  uVar4 = FUN_00412d40(auStack_60,iVar2,param_4);

  (**(code **)(iVar1 + 0x4c))(uVar4);

  piVar5[0x16] = param_6;

  if ((*(int *)(param_2 + 0xc) == 0) ||

     ((uint)((*(int *)(param_2 + 0x10) - *(int *)(param_2 + 0xc)) / 0x28) <= param_3)) {

    FUN_00760830(param_3 + 1);

  }

  FUN_004406e0();

  uVar4 = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

  FUN_004406e0();

  (**(code **)(*piVar5 + 0x20))(uVar4);

  piVar5[0x19] = param_5 + 0x30;

  ExceptionList = pvStack_24;

  return piVar5;

}
