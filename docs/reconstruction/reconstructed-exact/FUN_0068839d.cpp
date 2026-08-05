// =============================================================================
// FUN_0068839d
// -----------------------------------------------------------------------------
// Stable ID: aa_0068839d
// Address:   0x0068839d  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068839d @ 0x0068839d
// Stable ID: aa_0068839d
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: ABS, FUN_00687660, FUN_00687c30, FUN_0068839d.
//  - Return sites: 4.

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

void __thiscall FUN_0068839d(int *param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  char cVar5;

  int unaff_EBX;

  ushort uVar6;

  bool in_ZF;

  bool bVar7;

  uint32_t /* width from decompiler */ uStack00000004;

  short sStack00000008;

  uint32_t /* width from decompiler */ uStack0000000c;

  short sStack00000010;

  uint32_t /* width from decompiler */ uStack00000014;

  uint uStack00000018;

  int in_stack_00000020;

  

  cVar5 = (char)unaff_EBX;

  if (((in_ZF) || (param_1[0x13] == unaff_EBX)) || (*(int *)(param_1[0x13] + 8) <= unaff_EBX)) {

    *(char *)(in_stack_00000020 + 0xf0) = cVar5;

    *(char *)(in_stack_00000020 + 0x100) = cVar5;

    *(char *)(in_stack_00000020 + 0x110) = cVar5;

    return;

  }

  _sStack00000008 = 0xffffffff;

  _sStack00000010 = 0xffffffff;

  uVar6 = *(short *)(*param_1 + 0xb4) + 1;

  uStack0000000c = 0xbf800000;

  uStack00000014 = 0xbf800000;

  if (param_1[0xd] == unaff_EBX) {

    uStack00000004 = *(uint32_t /* width from decompiler */ *)(*param_1 + 0x14);

  }

  else {

    uStack00000004 = *(uint32_t /* width from decompiler */ *)(param_1[0xd] + 0x10);

  }

  uStack00000018 = (uint)*(byte *)(param_1 + 0x11);

  FUN_00687660(uStack00000004,uVar6,param_1[7],param_1[10],param_1[8],(float)uStack00000018,

               &stack0x0000000c,&stack0x00000014,&stack0x00000008,&stack0x00000010);

  iVar2 = in_stack_00000020;

  iVar3 = uVar6 - 1;

  *(uint32_t /* width from decompiler */ *)(in_stack_00000020 + 0xfc) = 0xbf800000;

  uVar4 = uStack0000000c;

  if ((sStack00000008 == iVar3) || (uVar4 = uStack00000014, sStack00000010 == iVar3)) {

    *(uint32_t /* width from decompiler */ *)(in_stack_00000020 + 0xfc) = uVar4;

  }

  bVar7 = *(int *)(in_stack_00000020 + 0xfc) != -0x40800000;

  *(bool *)(in_stack_00000020 + 0xf0) = bVar7;

  if (bVar7 != (bool)cVar5) {

    uVar4 = FUN_00687c30(*(uint32_t /* width from decompiler */ *)(param_1[0x10] + 0x18),ABS(*(float *)(param_1[0x10] + 0x10))

                        );

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xf8) = uVar4;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xf4) = *(uint32_t /* width from decompiler */ *)(param_1[0x13] + 0xc);

  }

  *(char *)(iVar2 + 0x100) = cVar5;

  if (*(char *)((int)param_1 + 0x69) != cVar5) {

    *(int **)(iVar2 + 0x118) = param_1 + 0x1b;

    iVar3 = *(int *)(param_1[0x13] + 0xc);

    iVar1 = *(int *)(param_1[0x13] + 8);

    *(float *)(iVar2 + 0x11c) = *(float *)(iVar2 + 0xfc);

    bVar7 = g_flZero <= *(float *)(iVar2 + 0xfc);

    *(int *)(iVar2 + 0x114) = iVar1 * 0x20 + -0x20 + iVar3;

    if (bVar7) {

      *(uint8_t *)(iVar2 + 0x110) = 1;

      return;

    }

    *(uint8_t *)(iVar2 + 0x110) = 0;

    return;

  }

  *(char *)(iVar2 + 0x110) = cVar5;

  return;

}
