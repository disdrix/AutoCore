// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00899030
// -----------------------------------------------------------------------------
// Stable ID: aa_00899030
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x00899030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00899030.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00899030(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  int unaff_EBX;

  int unaff_ESI;

  uint8_t *puStack_3c;

  int iStack_38;

  uint8_t *puStack_34;

  uint8_t *puStack_30;

  uint8_t *puStack_2c;

  uint8_t local_20 [4];

  uint8_t auStack_1c [8];

  uint8_t auStack_14 [12];

  uint8_t local_8 [8];

  

  if ((*(int *)(unaff_ESI + 0x534) != 0) && (*(int *)(unaff_ESI + 0x514) != 0)) {

    iVar1 = **(int **)(unaff_ESI + 0x534);

    if (DAT_00af9328 < DAT_00af932c) {

      puStack_2c = (uint8_t *)0x1;

      puStack_30 = local_20;

      puStack_34 = (uint8_t *)0x89907d;

      (**(code **)(iVar1 + 0x140))();

      puStack_34 = &stack0xffffffd8;

      iStack_38 = 0x8990d4;

      (**(code **)(**(int **)(unaff_ESI + 0x514) + 0x130))();

      iStack_38 = 0;

      puStack_3c = (uint8_t *)0x1;

      iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x534) + 0x120))(auStack_1c);

      uVar5 = *(uint32_t /* width from decompiler */ *)(iVar1 + 4);

      iVar1 = 0;

      piVar2 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x534) + 0x120))(local_20,1,0);

      puStack_3c = (uint8_t *)((unaff_EBX - iVar1) / 2 + *piVar2);

      iStack_38 = uVar5;

      (**(code **)(**(int **)(unaff_ESI + 0x514) + 0x110))(&puStack_3c);

      return;

    }

    if (DAT_00af932c < DAT_00af9328) {

      puStack_2c = local_20;

      puStack_30 = (uint8_t *)0x89914b;

      (**(code **)(iVar1 + 0x140))();

      puStack_30 = &stack0xffffffd8;

      puStack_34 = (uint8_t *)0x8991a0;

      (**(code **)(**(int **)(unaff_ESI + 0x514) + 0x130))();

      puStack_34 = (uint8_t *)0x0;

      iStack_38 = 1;

      puStack_3c = auStack_14;

      iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x534) + 0x120))();

      iVar3 = 1 - iStack_38;

      iVar1 = *(int *)(iVar1 + 4);

      puVar4 = (uint32_t /* width from decompiler */ *)

               (**(code **)(**(int **)(unaff_ESI + 0x534) + 0x120))(&stack0xffffffd8,1,0);

      puStack_3c = (uint8_t *)*puVar4;

      iStack_38 = iVar3 / 2 + iVar1;

      (**(code **)(**(int **)(unaff_ESI + 0x514) + 0x110))(&puStack_3c);

      return;

    }

    iVar3 = **(int **)(unaff_ESI + 0x514);

    puStack_2c = local_8;

    puStack_30 = (uint8_t *)0x899215;

    puStack_30 = (uint8_t *)(**(code **)(iVar1 + 0x140))();

    puStack_34 = (uint8_t *)0x899222;

    (**(code **)(iVar3 + 0x130))();

    iVar1 = **(int **)(unaff_ESI + 0x514);

    puStack_34 = (uint8_t *)0x0;

    iStack_38 = 1;

    puStack_3c = auStack_14;

    uVar5 = (**(code **)(**(int **)(unaff_ESI + 0x534) + 0x120))();

    (**(code **)(iVar1 + 0x114))(uVar5);

  }

  return;

}
