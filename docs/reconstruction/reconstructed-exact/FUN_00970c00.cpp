// =============================================================================
// FUN_00970c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00970c00
// Address:   0x00970c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00970c00 @ 0x00970c00
// Stable ID: aa_00970c00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0043d5e0, FUN_00447350, FUN_00745d70, FUN_00970910, FUN_00970c00.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00970c00(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  void *unaff_EBX;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  iVar3 = param_2;

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009acca6;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0043d5e0();

  if (param_2 != *(int *)(param_1 + 0x14)) {

    piVar2 = *(int **)(param_2 + 0x10);

    iVar4 = FUN_00970910(iVar3);

    iVar5 = (**(code **)(*piVar2 + 0x1c))();

    piVar1 = (int *)(param_1 + 0xe8 + iVar4 * 4);

    *piVar1 = *piVar1 - iVar5;

    piVar1 = (int *)(param_1 + 0xfc + iVar4 * 4);

    *piVar1 = *piVar1 + -1;

    puVar6 = operator_new(0x40);

    uStack_4 = 0;

    if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar6 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      FUN_00745d70(puVar6,iVar3,param_4);

      *puVar6 = &PTR_FUN_00a9e99c;

      puVar6[0xf] = piVar2;

    }

    uStack_4 = 0xffffffff;

    FUN_00447350(param_1 + 0x10,&param_2,param_2);

    ExceptionList = unaff_EBX;

    return puVar6;

  }

  ExceptionList = local_c;

  return (uint32_t /* width from decompiler */ *)0x0;

}
