// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00689b70
// -----------------------------------------------------------------------------
// Stable ID: aa_00689b70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00689b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper. Evidence string: "no frond geometry exists, possible prior call to DeleteFrondGeometry". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "no frond geometry exists, possible prior call to DeleteFrondGeometry"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×9, return×5, goto×1.
//  - Notable callees: CONCAT22, FUN_006871b0, FUN_00687660, FUN_00689b70, FUN_0068b800.
//  - Return sites: 5.

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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00689b70(int *param_1,int param_2,uint param_3)



{

  int iVar1;

  int iVar2;

  short sVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint16_t uVar5;

  uint uVar6;

  int iVar7;

  ushort uVar8;

  uint32_t /* width from decompiler */ local_c;

  float local_8;

  uint8_t local_4 [4];

  

  iVar2 = param_2;

  iVar1 = param_1[0x17];

  if (iVar1 == 0) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &DAT_00d08e78,"no frond geometry exists, possible prior call to DeleteFrondGeometry")

    ;

    return;

  }

  if (*(int *)(iVar1 + 100) == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = *(int *)(iVar1 + 0x68) - *(int *)(iVar1 + 100) >> 2;

  }

  *(short *)(param_2 + 0x4c) = (short)(uVar6 / 3);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x50) = *(uint32_t /* width from decompiler */ *)(param_1[0x17] + 0x54);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x60) = *(uint32_t /* width from decompiler */ *)(param_1[0x17] + 100);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x54) = *(uint32_t /* width from decompiler */ *)(param_1[0x17] + 0x84);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x58) = *(uint32_t /* width from decompiler */ *)(param_1[0x17] + 0x94);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x5c) = *(uint32_t /* width from decompiler */ *)(param_1[0x17] + 0xa4);

  *(uint32_t /* width from decompiler */ *)(param_2 + 100) = *(uint32_t /* width from decompiler */ *)(param_1[0x17] + 0xb4);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x68) = *(uint32_t /* width from decompiler */ *)(param_1[0x17] + 0xe4);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x6c) = *(uint32_t /* width from decompiler */ *)(param_1[0x17] + 0xf4);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x70) = *(uint32_t /* width from decompiler */ *)(param_1[0x17] + 0x104);

  uVar6 = param_3;

  if ((short)param_3 == -1) {

    uVar6 = FUN_006871b0(0xbf800000);

  }

  sVar3 = (short)uVar6;

  *(int *)(iVar2 + 0x3c) = (int)sVar3;

  if (-1 < sVar3) {

    iVar7 = sVar3 * 0x10;

    iVar1 = *(int *)(iVar7 + 4 + *(int *)(param_1[0x17] + 0x44));

    if (iVar1 != 0) {

      uVar5 = (uint16_t)(*(int *)(iVar7 + *(int *)(param_1[0x17] + 0x44) + 8) - iVar1 >> 2);

      goto LAB_00689c4e;

    }

  }

  uVar5 = 0;

LAB_00689c4e:

  *(uint16_t *)(iVar2 + 0x40) = uVar5;

  iVar1 = *(int *)(param_1[0x17] + 0x34);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x44) = *(uint32_t /* width from decompiler */ *)((uVar6 & 0xffff) * 0x10 + iVar1 + 4);

  uVar4 = FUN_0068b800(uVar6);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x48) = uVar4;

  if (((DAT_00d08e54 == '\0') || (param_1[0x13] == 0)) || (*(int *)(param_1[0x13] + 8) < 1)) {

    *(float *)(iVar2 + 0x74) = (float)*(byte *)(param_1 + 0x11);

    return;

  }

  uVar8 = *(short *)(*param_1 + 0xb4) + 1;

  local_c = 0xbf800000;

  param_3 = 0xffffffff;

  if (param_1[0xd] == 0) {

    param_2 = *(uint32_t /* width from decompiler */ *)(*param_1 + 0x14);

  }

  else {

    param_2 = *(uint32_t /* width from decompiler */ *)(param_1[0xd] + 0x10);

  }

  local_8 = (float)*(byte *)(param_1 + 0x11);

  FUN_00687660(param_2,CONCAT22((short)((uint)iVar1 >> 0x10),uVar8),param_1[7],param_1[10],

               param_1[8],local_8,&local_c,local_4,&param_3,&param_2);

  if ((int)(short)param_3 == uVar8 - 2) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x74) = local_c;

    return;

  }

  if ((int)(short)param_3 == uVar8 - 1) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x74) = 0x437f0000;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x3c) = 0xffffffff;

    return;

  }

  *(float *)(iVar2 + 0x74) = local_8;

  return;

}
