// =============================================================================
// Named_CalleeOf_Client_BuildInterfaceOptionsDialog_00817140
// -----------------------------------------------------------------------------
// Stable ID: aa_00817140
// Callee of Client_BuildInterfaceOptionsDialog
// Address:   0x00817140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_BuildInterfaceOptionsDialog: UI/dialog helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×10, do×4, while×4, goto×4, return×3.
//  - Notable callees: FUN_00418700, FUN_00418790, FUN_00817140.
//  - Return sites: 3.

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

void Named_CalleeOf_Client_BuildInterfaceOptionsDialog_00817140(uint32_t /* width from decompiler */ *param_1,char *param_2,int param_3)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ *puVar5;

  char *pcVar6;

  int iVar7;

  char *pcVar8;

  char *pcVar9;

  int *piVar10;

  

  iVar2 = param_3;

  puVar3 = param_1;

  piVar10 = *(int **)param_1[0x1c5];

  if (piVar10 == (int *)param_1[0x1c5]) {

LAB_00817204:

    puVar5 = operator_new(8);

    pcVar9 = param_2;

    *puVar5 = 0;

    param_1 = puVar5;

    if (param_2 != (char *)0x0) {

      pcVar6 = param_2;

      do {

        cVar1 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

      pcVar6 = operator_new__((uint)(pcVar6 + (1 - (int)(param_2 + 1))));

      *puVar5 = pcVar6;

      do {

        cVar1 = *pcVar9;

        *pcVar6 = cVar1;

        pcVar9 = pcVar9 + 1;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

    }

    puVar5[1] = iVar2;

    iVar2 = puVar3[0x1c5];

    iVar7 = FUN_00418700(iVar2,*(uint32_t /* width from decompiler */ *)(iVar2 + 4),&param_1);

    FUN_00418790();

    *(int *)(iVar2 + 4) = iVar7;

    **(int **)(iVar7 + 4) = iVar7;

    if (puVar3[0x1c6] == 1) {

      puVar3[0x1c3] = param_3;

      if ((int *)puVar3[0x1c2] != (int *)0x0) {

        (**(code **)(*(int *)puVar3[0x1c2] + 0x1d8))(param_2,1,1);

LAB_008172b4:

        (**(code **)(*(int *)puVar3[0x1c2] + 0x34c))();

      }

    }

    return;

  }

LAB_00817160:

  if (*(int *)(piVar10[2] + 4) != param_3) goto code_r0x0081716c;

  if (*(void **)piVar10[2] != (void *)0x0) {

    operator_delete__(*(void **)piVar10[2]);

  }

  pcVar9 = param_2;

  *(uint32_t /* width from decompiler */ *)piVar10[2] = 0;

  if (param_2 != (char *)0x0) {

    pcVar6 = param_2;

    do {

      cVar1 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar1 != '\0');

    pvVar4 = operator_new__((uint)(pcVar6 + (1 - (int)(param_2 + 1))));

    *(void **)piVar10[2] = pvVar4;

    pcVar6 = *(char **)piVar10[2];

    pcVar8 = pcVar9;

    do {

      cVar1 = *pcVar8;

      *pcVar6 = cVar1;

      pcVar8 = pcVar8 + 1;

      pcVar6 = pcVar6 + 1;

    } while (cVar1 != '\0');

  }

  if (puVar3[0x1c3] != iVar2) {

    return;

  }

  if ((int *)puVar3[0x1c2] == (int *)0x0) {

    return;

  }

  (**(code **)(*(int *)puVar3[0x1c2] + 0x1d8))(pcVar9,1,1);

  goto LAB_008172b4;

code_r0x0081716c:

  piVar10 = (int *)*piVar10;

  if (piVar10 == (int *)param_1[0x1c5]) goto LAB_00817204;

  goto LAB_00817160;

}
