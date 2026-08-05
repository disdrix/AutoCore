// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00688390
// -----------------------------------------------------------------------------
// Stable ID: aa_00688390
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00688390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: ABS, FUN_00687660, FUN_00687c30, FUN_00688390.
//  - Return sites: 4.

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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00688390(int *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  ushort uVar4;

  bool bVar5;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  uint uStack_4;

  

  if (((DAT_00d08e54 == '\0') || (param_1[0x13] == 0)) || (*(int *)(param_1[0x13] + 8) < 1)) {

    *(uint8_t *)(param_2 + 0xf0) = 0;

    *(uint8_t *)(param_2 + 0x100) = 0;

    *(uint8_t *)(param_2 + 0x110) = 0;

    return;

  }

  uStack_14 = 0xffffffff;

  uStack_c = 0xffffffff;

  uVar4 = *(short *)(*param_1 + 0xb4) + 1;

  uStack_10 = 0xbf800000;

  uStack_8 = 0xbf800000;

  if (param_1[0xd] == 0) {

    uStack_18 = *(uint32_t /* width from decompiler */ *)(*param_1 + 0x14);

  }

  else {

    uStack_18 = *(uint32_t /* width from decompiler */ *)(param_1[0xd] + 0x10);

  }

  uStack_4 = (uint)*(byte *)(param_1 + 0x11);

  FUN_00687660(uStack_18,uVar4,param_1[7],param_1[10],param_1[8],(float)uStack_4,&uStack_10,

               &uStack_8,&uStack_14,&uStack_c);

  iVar2 = uVar4 - 1;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xfc) = 0xbf800000;

  uVar3 = uStack_10;

  if (((short)uStack_14 == iVar2) || (uVar3 = uStack_8, (short)uStack_c == iVar2)) {

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xfc) = uVar3;

  }

  bVar5 = *(int *)(param_2 + 0xfc) != -0x40800000;

  *(bool *)(param_2 + 0xf0) = bVar5;

  if (bVar5) {

    uVar3 = FUN_00687c30(*(uint32_t /* width from decompiler */ *)(param_1[0x10] + 0x18),ABS(*(float *)(param_1[0x10] + 0x10))

                        );

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xf8) = uVar3;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xf4) = *(uint32_t /* width from decompiler */ *)(param_1[0x13] + 0xc);

  }

  *(uint8_t *)(param_2 + 0x100) = 0;

  if (*(char *)((int)param_1 + 0x69) != '\0') {

    *(int **)(param_2 + 0x118) = param_1 + 0x1b;

    iVar2 = *(int *)(param_1[0x13] + 0xc);

    iVar1 = *(int *)(param_1[0x13] + 8);

    *(float *)(param_2 + 0x11c) = *(float *)(param_2 + 0xfc);

    bVar5 = g_flZero <= *(float *)(param_2 + 0xfc);

    *(int *)(param_2 + 0x114) = iVar1 * 0x20 + -0x20 + iVar2;

    if (bVar5) {

      *(uint8_t *)(param_2 + 0x110) = 1;

      return;

    }

    *(uint8_t *)(param_2 + 0x110) = 0;

    return;

  }

  *(uint8_t *)(param_2 + 0x110) = 0;

  return;

}
