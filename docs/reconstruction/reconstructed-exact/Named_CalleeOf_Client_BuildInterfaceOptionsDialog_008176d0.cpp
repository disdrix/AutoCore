// =============================================================================
// Named_CalleeOf_Client_BuildInterfaceOptionsDialog_008176d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008176d0
// Callee of Client_BuildInterfaceOptionsDialog
// Address:   0x008176d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_BuildInterfaceOptionsDialog: UI/dialog helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, for×1.
//  - Notable callees: FUN_00418700×2, FUN_00418790×2, FUN_007b5dd0, FUN_008176d0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_BuildInterfaceOptionsDialog
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

void __thiscall Named_CalleeOf_Client_BuildInterfaceOptionsDialog_008176d0(int *param_1,int *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  int *piVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  piVar5 = param_2;

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b32f5;

  local_c = ExceptionList;

  if (param_2 != (int *)0x0) {

    for (puVar1 = *(uint32_t /* width from decompiler */ **)param_1[0x144]; puVar1 != (uint32_t /* width from decompiler */ *)param_1[0x144];

        puVar1 = (uint32_t /* width from decompiler */ *)*puVar1) {

      if ((int *)puVar1[2] == param_2) {

        return;

      }

    }

    ExceptionList = &local_c;

    cVar3 = (**(code **)(*param_2 + 0x3d8))();

    if (cVar3 == '\0') {

      (**(code **)(*param_1 + 0xa8))(piVar5);

      (**(code **)(*piVar5 + 0x43c))();

    }

    iVar2 = param_1[0x144];

    iVar4 = FUN_00418700(iVar2,*(uint32_t /* width from decompiler */ *)(iVar2 + 4),&param_2);

    FUN_00418790();

    *(int *)(iVar2 + 4) = iVar4;

    **(int **)(iVar4 + 4) = iVar4;

    if (((char)param_1[0x151] != '\0') &&

       (((char)param_1[0x31a] != '\0' || ((char)param_1[0x35b] != '\0')))) {

      param_2 = operator_new(0x488);

      piVar5 = (int *)0x0;

      uStack_4 = 0;

      if (param_2 != (void *)0x0) {

        piVar5 = (int *)FUN_007b5dd0(param_2,0);

      }

      uStack_4 = 0xffffffff;

      param_2 = piVar5;

      (**(code **)(*param_1 + 0xa8))(piVar5);

      if ((((*(byte *)(param_1 + 0x148) & 1) == 0) && ((char)param_1[0x31a] != '\0')) ||

         ((char)param_1[0x35b] == '\0')) {

        (**(code **)(*piVar5 + 0x28))(param_1 + 0x31a);

      }

      else {

        (**(code **)(*piVar5 + 0x28))(param_1 + 0x35b);

      }

      iVar2 = param_1[0x147];

      iVar4 = FUN_00418700(iVar2,*(uint32_t /* width from decompiler */ *)(iVar2 + 4),&param_2);

      FUN_00418790();

      *(int *)(iVar2 + 4) = iVar4;

      **(int **)(iVar4 + 4) = iVar4;

    }

  }

  ExceptionList = local_c;

  return;

}
