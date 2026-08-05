// =============================================================================
// FUN_00689950
// -----------------------------------------------------------------------------
// Stable ID: aa_00689950
// Address:   0x00689950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00689950 @ 0x00689950
// Stable ID: aa_00689950
// Embedded strings (evidence for future rename):
//   - "no branch geometry exists, possible prior call to DeleteBranchGeometry"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×9, return×5, goto×1.
//  - Notable callees: CONCAT22, FUN_00687660, FUN_00687d40, FUN_00689950, FUN_0068b800.
//  - Return sites: 5.

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

void __thiscall FUN_00689950(int *param_1,int *param_2,uint param_3)



{

  int iVar1;

  int *piVar2;

  short sVar3;

  uint16_t uVar4;

  uint uVar5;

  int iVar6;

  ushort uVar7;

  int local_c;

  float local_8;

  uint8_t local_4 [4];

  

  piVar2 = param_2;

  iVar1 = param_1[1];

  if (iVar1 == 0) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &DAT_00d08e78,

               "no branch geometry exists, possible prior call to DeleteBranchGeometry");

    return;

  }

  if (*(int *)(iVar1 + 100) == 0) {

    uVar5 = 0;

  }

  else {

    uVar5 = *(int *)(iVar1 + 0x68) - *(int *)(iVar1 + 100) >> 2;

  }

  *(short *)(param_2 + 4) = (short)(uVar5 / 3);

  param_2[5] = *(int *)(param_1[1] + 0x54);

  param_2[9] = *(int *)(param_1[1] + 100);

  param_2[6] = *(int *)(param_1[1] + 0x84);

  param_2[7] = *(int *)(param_1[1] + 0x94);

  param_2[8] = *(int *)(param_1[1] + 0xa4);

  param_2[10] = *(int *)(param_1[1] + 0xb4);

  param_2[0xb] = *(int *)(param_1[1] + 0xe4);

  param_2[0xc] = *(int *)(param_1[1] + 0xf4);

  param_2[0xd] = *(int *)(param_1[1] + 0x104);

  uVar5 = param_3;

  if ((short)param_3 == -1) {

    uVar5 = FUN_00687d40(0xbf800000);

  }

  sVar3 = (short)uVar5;

  *piVar2 = (int)sVar3;

  if (-1 < sVar3) {

    iVar6 = sVar3 * 0x10;

    iVar1 = *(int *)(iVar6 + 4 + *(int *)(param_1[1] + 0x44));

    if (iVar1 != 0) {

      uVar4 = (uint16_t)(*(int *)(iVar6 + *(int *)(param_1[1] + 0x44) + 8) - iVar1 >> 2);

      goto LAB_00689a2d;

    }

  }

  uVar4 = 0;

LAB_00689a2d:

  *(uint16_t *)(piVar2 + 1) = uVar4;

  iVar1 = *(int *)(param_1[1] + 0x34);

  piVar2[2] = *(int *)((uVar5 & 0xffff) * 0x10 + iVar1 + 4);

  iVar6 = FUN_0068b800(uVar5);

  piVar2[3] = iVar6;

  if (((DAT_00d08e54 == '\0') || (param_1[0x13] == 0)) || (*(int *)(param_1[0x13] + 8) < 1)) {

    piVar2[0xe] = (int)(float)*(byte *)(param_1 + 0x11);

    return;

  }

  uVar7 = *(short *)(*param_1 + 0xb4) + 1;

  local_c = -0x40800000;

  param_3 = 0xffffffff;

  if (param_1[0xd] == 0) {

    param_2 = *(int **)(*param_1 + 0x14);

  }

  else {

    param_2 = *(int **)(param_1[0xd] + 0x10);

  }

  local_8 = (float)*(byte *)(param_1 + 0x11);

  FUN_00687660(param_2,CONCAT22((short)((uint)iVar1 >> 0x10),uVar7),param_1[7],param_1[10],

               param_1[8],local_8,&local_c,local_4,&param_3,&param_2);

  if ((int)(short)param_3 == uVar7 - 2) {

    piVar2[0xe] = local_c;

    return;

  }

  if ((int)(short)param_3 == uVar7 - 1) {

    piVar2[0xe] = 0x437f0000;

    *piVar2 = -1;

    return;

  }

  piVar2[0xe] = (int)local_8;

  return;

}
