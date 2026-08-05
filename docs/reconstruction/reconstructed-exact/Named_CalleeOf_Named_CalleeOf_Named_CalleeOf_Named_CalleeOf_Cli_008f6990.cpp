// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008f6990
// -----------------------------------------------------------------------------
// Stable ID: aa_008f6990
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa
// Address:   0x008f6990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×5, goto×1, return×1.
//  - Notable callees: FUN_008f6990.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008f6990(void)



{

  int *piVar1;

  int in_EAX;

  int iVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int unaff_ESI;

  int **ppiStack_60;

  int iStack_5c;

  uint8_t *puStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint8_t *puStack_4c;

  uint8_t *puStack_48;

  uint8_t *puStack_44;

  int **ppiStack_40;

  int *piStack_3c;

  int *piStack_38;

  int *local_28 [2];

  int aiStack_20 [8];

  

  piVar1 = *(int **)(unaff_ESI + 0x548);

  if (piVar1 != (int *)0x0) {

    piStack_38 = (int *)0x0;

    piStack_3c = (int *)0x1;

    ppiStack_40 = local_28;

    puStack_44 = (uint8_t *)0x8f69b7;

    iVar2 = (**(code **)(*piVar1 + 0x120))();

    puStack_44 = (uint8_t *)0x1;

    puStack_48 = &stack0xffffffd4;

    puStack_4c = (uint8_t *)0x8f69ca;

    iVar3 = (**(code **)(*piVar1 + 0x140))();

    if (in_EAX < *(int *)(iVar2 + 4) + *(int *)(iVar3 + 4)) {

      piVar1 = *(int **)(unaff_ESI + 0x548);

      piStack_38 = (int *)0x1;

      piStack_3c = aiStack_20;

      ppiStack_40 = (int **)0x8f69f4;

      local_28[0] = piVar1;

      iVar2 = (**(code **)(*piVar1 + 0x120))();

      ppiStack_40 = (int **)0x1;

      puStack_44 = &stack0xffffffcc;

      puStack_48 = (uint8_t *)0x8f6a07;

      iVar3 = (**(code **)(*piVar1 + 0x140))();

      in_EAX = *(int *)(iVar2 + 4) + *(int *)(iVar3 + 4);

      goto LAB_008f6a29;

    }

  }

  if ((int)((float)DAT_00d1e81c * DAT_00a0f708) < in_EAX) {

    in_EAX = (int)((float)DAT_00d1e81c * DAT_00a0f708);

  }

LAB_008f6a29:

  if (DAT_00d17944 == 0) {

    aiStack_20[0] = 0;

    DAT_00af9214 = 0;

  }

  else {

    aiStack_20[0] = (int)(0.0 / (float)DAT_00d1e818);

    DAT_00af9214 = (int)(((float)in_EAX * DAT_00aaa670) / (float)DAT_00d1e81c);

  }

  *(int *)(unaff_ESI + 0x524) = DAT_00af9214;

  piStack_38 = (int *)0x1;

  piStack_3c = aiStack_20;

  ppiStack_40 = (int **)0x8f6aa9;

  (**(code **)(**(int **)(unaff_ESI + 0x548) + 0x120))();

  ppiStack_40 = (int **)&stack0xffffffcc;

  puStack_44 = (uint8_t *)0x8f6ac6;

  (**(code **)(**(int **)(unaff_ESI + 0x534) + 0x110))();

  if (*(int *)(unaff_ESI + 0x530) != 0) {

    piVar1 = *(int **)(unaff_ESI + 0x52c);

    puStack_44 = (uint8_t *)0x0;

    puStack_48 = (uint8_t *)0x1;

    puStack_4c = &stack0xffffffd0;

    uStack_50 = 0x8f6af6;

    piStack_38 = piVar1;

    iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x534) + 0x120))();

    uStack_50 = 0;

    uStack_54 = 1;

    puStack_58 = &stack0xffffffcc;

    iStack_5c = 0x8f6b0b;

    iVar3 = (**(code **)(*piVar1 + 0x120))();

    iVar2 = *(int *)(iVar2 + 4);

    iVar3 = *(int *)(iVar3 + 4);

    iStack_5c = 1;

    ppiStack_60 = &piStack_38;

    iVar4 = (**(code **)(*piVar1 + 0x140))();

    iVar4 = *(int *)(iVar4 + 4);

    puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_ESI + 0x530) + 0x140))(&piStack_38,1);

    ppiStack_60 = (int **)*puVar5;

    iStack_5c = (iVar2 - iVar3) - iVar4;

    (**(code **)(**(int **)(unaff_ESI + 0x530) + 300))(&ppiStack_60);

    (**(code **)(**(int **)(unaff_ESI + 0x530) + 0x34c))();

  }

  return;

}
