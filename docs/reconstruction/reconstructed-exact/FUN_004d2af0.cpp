// =============================================================================
// FUN_004d2af0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d2af0
// Address:   0x004d2af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d2af0 @ 0x004d2af0
// Stable ID: aa_004d2af0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, return×1.
//  - Notable callees: FUN_0049c5f0×2, memmove×2, FUN_00491140, FUN_004d2af0.
//  - Return sites: 1.

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

void __thiscall FUN_004d2af0(int param_1,int *param_2)



{

  char cVar1;

  float *pfVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  void *pvVar5;

  int iVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  uint8_t local_18 [8];

  uint8_t auStack_10 [12];

  size_t sStack_4;

  

  pfVar2 = (float *)(**(code **)(*param_2 + 0x40))(local_18);

  uVar9 = (uint)(*pfVar2 / *(float *)(param_1 + 0xe7c0));

  iVar3 = (**(code **)(*param_2 + 0x40))(auStack_10);

  uVar7 = *(int *)(param_1 + 0xe7b8) - 1;

  uVar8 = (uint)(*(float *)(iVar3 + 8) / *(float *)(param_1 + 0xe7c4));

  uVar9 = ((int)uVar9 < 0) - 1 & uVar9;

  if ((int)uVar9 <= (int)uVar7) {

    uVar7 = uVar9;

  }

  uVar9 = *(int *)(param_1 + 0xe7bc) - 1;

  uVar8 = ((int)uVar8 < 0) - 1 & uVar8;

  if ((int)uVar8 <= (int)uVar9) {

    uVar9 = uVar8;

  }

  cVar1 = (**(code **)(*param_2 + 0x28))();

  if (cVar1 == '\x02') {

    iVar3 = (*(int *)(param_1 + 0xe7b8) * uVar9 + uVar7) * 0x20;

    pvVar5 = *(void **)(iVar3 + 0x18 + *(int *)(param_1 + 0xe7b4));

    iVar3 = iVar3 + 0x10 + *(int *)(param_1 + 0xe7b4);

    puVar4 = (uint32_t /* width from decompiler */ *)

             FUN_0049c5f0(&stack0xffffffdc,*(uint32_t /* width from decompiler */ *)(iVar3 + 4),pvVar5,&sStack_4);

    if ((void *)*puVar4 == pvVar5) goto LAB_004d2c3a;

    sStack_4 = (*(int *)(iVar3 + 8) - (int)pvVar5 >> 2) * 4;

    pvVar5 = memmove((void *)*puVar4,pvVar5,sStack_4);

    iVar6 = (int)pvVar5 + sStack_4;

  }

  else {

    iVar3 = (*(int *)(param_1 + 0xe7b8) * uVar9 + uVar7) * 0x20 + *(int *)(param_1 + 0xe7b4);

    pvVar5 = *(void **)(iVar3 + 8);

    puVar4 = (uint32_t /* width from decompiler */ *)

             FUN_0049c5f0(&stack0xffffffdc,*(uint32_t /* width from decompiler */ *)(iVar3 + 4),pvVar5,&sStack_4);

    if ((void *)*puVar4 == pvVar5) goto LAB_004d2c3a;

    sStack_4 = (*(int *)(iVar3 + 8) - (int)pvVar5 >> 2) * 4;

    pvVar5 = memmove((void *)*puVar4,pvVar5,sStack_4);

    iVar6 = (int)pvVar5 + sStack_4;

  }

  *(int *)(iVar3 + 8) = iVar6;

LAB_004d2c3a:

  if (*(int *)(param_1 + 0xe894) != 0) {

    FUN_00491140(param_2);

  }

  return;

}
