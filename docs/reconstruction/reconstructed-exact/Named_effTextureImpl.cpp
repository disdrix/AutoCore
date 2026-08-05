// READABILITY (auto CF):
//  - Body size: ~119 non-empty decompiler lines.
//  - Control keywords: if×17, goto×1, return×1.
//  - Notable callees: FUN_0096c810×3, vog_LogMessage×2, FUN_0043f120, FUN_0076cec0, FUN_0096a630, FUN_0096bbb0, FUN_0096bdc0, FUN_0096c060.
//  - Return sites: 1.

// =============================================================================
// Named_effTextureImpl
// -----------------------------------------------------------------------------
// Stable ID: aa_0096d100
// Address:   0x0096d100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effTextureImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall Named_effTextureImpl(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint uVar5;

  int iVar6;

  int unaff_EBX;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [24];

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b08e4;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0096c8e0();

  *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 0x10;

  if (param_4 == 0) {

    iVar2 = (-(uint)((*(uint *)(param_1 + 0x2c) & 0x100) != 0) & 0xfffffffc) + 1;

  }

  else {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_4 + 4);

    *(uint *)(param_1 + 0x2c) = *(uint *)(param_4 + 0x10) | 0x1000;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = *(uint32_t /* width from decompiler */ *)(param_4 + 0x14);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_4 + 0x18);

    if ((*(byte *)(param_1 + 0x2d) & 1) == 0) goto LAB_0096d1ee;

    iVar2 = *(int *)(param_4 + 0x28);

  }

  if ((iVar2 == 0) || (iVar2 == -1)) {

    FUN_0096a630();

    local_4 = 0;

    FUN_0076cec0();

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",0xf6

                  );

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  }

LAB_0096d1ee:

  (**(code **)(*param_2 + 0x34))();

  iVar2 = FUN_0096c060();

  (**(code **)(*param_2 + 0x38))();

  if (((-1 < iVar2) && (*(uint32_t /* width from decompiler */ **)(param_1 + 0xc) != (uint32_t /* width from decompiler */ *)0x0)) &&

     (iVar3 = (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0xc))(), iVar3 == -1)) {

    vog_LogMessage();

    iVar2 = -1;

  }

  if ((unaff_EBX != 0) && ((*(byte *)(unaff_EBX + 0x11) & 2) != 0)) {

    iVar2 = FUN_0043f120();

    if (iVar2 == 0) {

      puVar4 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_0096bbb0();

    }

    iVar2 = FUN_0096cad0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x24));

    if (iVar2 < 0) {

      if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)*puVar4)();

      }

      puVar4 = (uint32_t /* width from decompiler */ *)0x0;

    }

    iVar2 = FUN_0096bdc0();

    if (iVar2 < 0) {

      if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)*puVar4)();

      }

      puVar4 = (uint32_t /* width from decompiler */ *)0x0;

    }

    if (*(int **)(param_1 + 0x10) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x10) + 8))();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    piVar1 = (int *)puVar4[4];

    *(int **)(param_1 + 0x10) = piVar1;

    (**(code **)(*piVar1 + 4))();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = puVar4[9];

    *(uint *)(param_1 + 0x2c) = puVar4[0xb] | 0x2000;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = puVar4[0xc];

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = puVar4[3];

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = puVar4[7];

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = puVar4[8];

    (**(code **)*puVar4)();

  }

  uVar5 = *(uint *)(param_1 + 0x2c) & 0xf;

  if (uVar5 == 2) {

    iVar6 = FUN_0096c810();

    iVar3 = DAT_00d1f614;

    if (DAT_00d1f614 != 0) {

      *(int *)(DAT_00d1f614 + 0x39c) = *(int *)(DAT_00d1f614 + 0x39c) + iVar6;

      *(int *)(iVar3 + 0x354) = *(int *)(iVar3 + 0x354) + 1;

    }

  }

  else if (uVar5 == 4) {

    iVar6 = FUN_0096c810();

    iVar3 = DAT_00d1f614;

    if (DAT_00d1f614 != 0) {

      *(int *)(DAT_00d1f614 + 0x3a4) = *(int *)(DAT_00d1f614 + 0x3a4) + iVar6;

      *(int *)(iVar3 + 0x35c) = *(int *)(iVar3 + 0x35c) + 1;

    }

  }

  else {

    iVar6 = FUN_0096c810();

    iVar3 = DAT_00d1f614;

    if (DAT_00d1f614 != 0) {

      *(int *)(DAT_00d1f614 + 0x394) = *(int *)(DAT_00d1f614 + 0x394) + iVar6;

      *(int *)(iVar3 + 0x34c) = *(int *)(iVar3 + 0x34c) + 1;

    }

  }

  if (((*(int *)(DAT_00d1f04c + 0x30) != 0) && (((byte)*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) & 0xf) == 1))

     && ((*(int *)(param_1 + 0x30) == 1 && (1 < *(uint *)(param_1 + 0x48))))) {

    (**(code **)(**(int **)(param_1 + 0x10) + 0x2c))();

  }

  ExceptionList = pvStack_10;

  return iVar2;

}
