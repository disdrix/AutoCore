// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068f9b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068f9b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068f9b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, return×1.
//  - Notable callees: FUN_0068f520, FUN_0068f9b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068f9b0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  uint uVar1;

  void *pvVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  

  *(uint16_t *)(param_1 + 8) = *(uint16_t *)(param_4 + 0x2c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_4 + 0x40);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_4 + 0x38);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_4 + 0x3c);

  iVar8 = 0;

  if (*(int *)(param_4 + 0x10) == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = (*(int *)(param_4 + 0x14) - *(int *)(param_4 + 0x10)) / 0x54;

  }

  uVar6 = uVar1 & 0xffff;

  *(short *)(param_1 + 0x1c) = (short)uVar1;

  pvVar2 = operator_new__(uVar6 * 0xc);

  if (pvVar2 == (void *)0x0) {

    pvVar2 = (void *)0x0;

  }

  else if (-1 < (int)(uVar6 - 1)) {

    puVar7 = (uint32_t /* width from decompiler */ *)((int)pvVar2 + 4);

    do {

      puVar7[1] = 0;

      *puVar7 = 0;

      puVar7[-1] = 0;

      puVar7 = puVar7 + 3;

      uVar6 = uVar6 - 1;

    } while (uVar6 != 0);

  }

  uVar1 = (uint)*(ushort *)(param_1 + 0x1c);

  *(void **)(param_1 + 0x20) = pvVar2;

  pvVar2 = operator_new__(uVar1 * 0xc);

  if (pvVar2 == (void *)0x0) {

    pvVar2 = (void *)0x0;

  }

  else if (-1 < (int)(uVar1 - 1)) {

    puVar7 = (uint32_t /* width from decompiler */ *)((int)pvVar2 + 4);

    do {

      puVar7[1] = 0;

      *puVar7 = 0;

      puVar7[-1] = 0;

      puVar7 = puVar7 + 3;

      uVar1 = uVar1 - 1;

    } while (uVar1 != 0);

  }

  *(void **)(param_1 + 0x24) = pvVar2;

  if (*(short *)(param_1 + 0x1c) != 0) {

    iVar5 = 0;

    iVar4 = 0;

    do {

      iVar3 = *(int *)(param_4 + 0x10) + iVar4;

      puVar7 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x20) + iVar5);

      *puVar7 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x48);

      puVar7[1] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x4c);

      puVar7[2] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x50);

      iVar3 = *(int *)(param_4 + 0x10) + iVar4;

      puVar7 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x24) + iVar5);

      *puVar7 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x30);

      puVar7[1] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x34);

      puVar7[2] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x38);

      iVar8 = iVar8 + 1;

      iVar4 = iVar4 + 0x54;

      iVar5 = iVar5 + 0xc;

    } while (iVar8 < (int)(uint)*(ushort *)(param_1 + 0x1c));

  }

  pvVar2 = operator_new__((uint)*(ushort *)(param_1 + 0x1c) * (uint)*(ushort *)(param_1 + 8) * 0x80)

  ;

  *(void **)(param_1 + 0x18) = pvVar2;

  FUN_0068f520(param_2,param_3);

  return;

}
