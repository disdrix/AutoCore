// =============================================================================
// FUN_005b1fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b1fd0
// Address:   0x005b1fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b1fd0 @ 0x005b1fd0
// Stable ID: aa_005b1fd0
// Embedded strings (evidence for future rename):
//   - "Can\'t save ghost data for object!"
//   - "Packing initial update for object %I64d"
//   - "Global coid pack for %I64d, %d. Hopefully GM only"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~176 non-empty decompiler lines.
//  - Control keywords: if×20, for×3, return×2, goto×1.
//  - Notable callees: BitStream_writeBits×14, BitStream_writeFlag×8, CONCAT31×4, BitStream_writeInt×3, FUN_007a4480×3, FUN_0042be20, FUN_005b1fd0, SUB43.
//  - Strings: "Can\'t save ghost data for object!"; "Packing initial update for object %I64d"; "Global coid pack for %I64d, %d. Hopefully GM only".
//  - Return sites: 2.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint64_t __thiscall FUN_005b1fd0(int param_1,uint32_t /* width from decompiler */ param_2,uint param_3)



{

  float fVar1;

  bool bVar2;

  char cVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  float *pfVar6;

  uint3 uVar8;

  int iVar7;

  float local_38;

  uint32_t /* width from decompiler */ local_34;

  float fStack_30;

  float local_2c;

  float fStack_28;

  uint32_t /* width from decompiler */ uStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  

  iVar4 = *(int *)(param_1 + 0x50);

  if (iVar4 == 0) {

    FUN_007a4480(1,"Can\'t save ghost data for object!");

    return 0;

  }

  if (DAT_00d1798c != '\0') {

    if (DAT_00b051e0 != '\0') {

      FUN_007a4480(0xffffffff,"Packing initial update for object %I64d",

                   *(uint32_t /* width from decompiler */ *)(iVar4 + 0x160),*(uint32_t /* width from decompiler */ *)(iVar4 + 0x164));

    }

    iVar4 = *(int *)(param_1 + 0x50);

    local_2c = *(float *)(iVar4 + 0x164);

    fVar1 = *(float *)(iVar4 + 0x160);

    local_38 = (float)CONCAT31(local_38._1_3_,*(uint8_t *)(iVar4 + 0x168));

    cVar3 = BitStream_writeFlag(local_38);

    if (cVar3 == '\0') {

      BitStream_writeInt(fVar1,0x14);

    }

    else {

      local_34 = local_2c;

      local_38 = fVar1;

      BitStream_writeBits(0x40,&local_38);

      FUN_007a4480(0,"Global coid pack for %I64d, %d. Hopefully GM only",fVar1,local_2c,

                   *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x50) + 0xa8) + 0x34));

    }

  }

  cVar3 = BitStream_writeFlag((param_3 & 8) != 0);

  if (cVar3 != '\0') {

    iVar4 = (**(code **)(**(int **)(param_1 + 0x50) + 0x23c))();

    if (iVar4 < 0) {

      uVar5 = 0;

    }

    else {

      uVar5 = (**(code **)(**(int **)(param_1 + 0x50) + 0x23c))();

    }

    BitStream_writeInt(uVar5,0x12);

    uVar5 = (**(code **)(**(int **)(param_1 + 0x50) + 0x198))();

    cVar3 = BitStream_writeFlag(uVar5);

    fVar1 = local_38;

    if (cVar3 != '\0') {

      local_38 = (float)((uint)local_38 & 0xffffff00);

      if ((uint)(DAT_00b0421c - *(int *)(*(int *)(param_1 + 0x50) + 0x1c)) < 2000) {

        local_38._1_3_ = SUB43(fVar1,1);

        local_38 = (float)CONCAT31(local_38._1_3_,1);

      }

      cVar3 = BitStream_writeFlag(local_38);

      if (cVar3 != '\0') {

        BitStream_writeInt(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x50) + 0xcc),3);

        iVar4 = *(int *)(param_1 + 0x50);

        fStack_18 = *(float *)(iVar4 + 0x48);

        fStack_14 = *(float *)(iVar4 + 0x4c);

        FUN_0042be20(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x40),*(uint32_t /* width from decompiler */ *)(iVar4 + 0x44));

        iVar4 = *(int *)(param_1 + 0x50);

        uStack_20 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x40);

        fStack_1c = *(float *)(iVar4 + 0x44);

        fStack_14 = *(float *)(iVar4 + 0x4c);

        BitStream_writeFlag(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x48));

      }

    }

  }

  iVar4 = (**(code **)(**(int **)(param_1 + 0x50) + 0x1c8))();

  if (((param_3 & 2) != 0) && (iVar7 = *(int *)(iVar4 + 8), iVar7 != 0)) {

    if ((*(char *)(iVar7 + 0x40) == '\0') || (*(int *)(iVar7 + 8) == 0)) {

      bVar2 = true;

    }

    else {

      bVar2 = false;

    }

    if (bVar2) {

      uVar5 = 1;

      goto LAB_005b21e2;

    }

  }

  uVar5 = 0;

LAB_005b21e2:

  cVar3 = BitStream_writeFlag(uVar5);

  if (cVar3 != '\0') {

    if (*(int *)(iVar4 + 8) == 0) {

      pfVar6 = (float *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0x84 + iVar4);

    }

    else {

      pfVar6 = (float *)(*(int *)(*(int *)(iVar4 + 8) + 0x3c) + 0xb0);

    }

    local_2c = pfVar6[1];

    local_38 = *pfVar6;

    fStack_28 = pfVar6[2];

    BitStream_writeBits(0x20,&local_38);

    local_38 = local_2c;

    BitStream_writeBits(0x20,&local_38);

    local_38 = fStack_28;

    BitStream_writeBits(0x20,&local_38);

    if (*(int *)(iVar4 + 8) == 0) {

      pfVar6 = (float *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0x94 + iVar4);

    }

    else {

      pfVar6 = (float *)(*(int *)(*(int *)(iVar4 + 8) + 0x3c) + 0x30);

    }

    fStack_1c = pfVar6[1];

    local_38 = *pfVar6;

    fStack_18 = pfVar6[2];

    fStack_14 = pfVar6[3];

    BitStream_writeBits(0x20,&local_38);

    local_38 = fStack_1c;

    BitStream_writeBits(0x20,&local_38);

    local_38 = fStack_18;

    BitStream_writeBits(0x20,&local_38);

    local_38 = fStack_14;

    BitStream_writeBits(0x20,&local_38);

    if (*(int *)(iVar4 + 8) == 0) {

      pfVar6 = (float *)&DAT_00b051f0;

    }

    else {

      pfVar6 = (float *)(*(int *)(*(int *)(iVar4 + 8) + 0x3c) + 0x40);

    }

    fStack_28 = pfVar6[2];

    local_2c = pfVar6[1];

    fStack_30 = *pfVar6;

    uVar8 = (uint3)((uint)pfVar6 >> 8);

    if (fStack_28 * fStack_28 + local_2c * local_2c + fStack_30 * fStack_30 <= _DAT_009d93f0) {

      iVar7 = (uint)uVar8 << 8;

    }

    else {

      iVar7 = CONCAT31(uVar8,1);

    }

    cVar3 = BitStream_writeFlag(iVar7);

    if (cVar3 != '\0') {

      local_38 = fStack_30;

      BitStream_writeBits(0x20,&local_38);

      local_38 = local_2c;

      BitStream_writeBits(0x20,&local_38);

      local_38 = fStack_28;

      BitStream_writeBits(0x20,&local_38);

    }

    iVar4 = *(int *)(*(int *)(iVar4 + 8) + 0x3c);

    fStack_28 = *(float *)(iVar4 + 0x58);

    local_2c = *(float *)(iVar4 + 0x54);

    fStack_30 = *(float *)(iVar4 + 0x50);

    uVar8 = (uint3)((uint)(iVar4 + 0x50) >> 8);

    if (fStack_28 * fStack_28 + local_2c * local_2c + fStack_30 * fStack_30 <= _DAT_009d93f0) {

      iVar4 = (uint)uVar8 << 8;

    }

    else {

      iVar4 = CONCAT31(uVar8,1);

    }

    cVar3 = BitStream_writeFlag(iVar4);

    if (cVar3 != '\0') {

      local_38 = fStack_30;

      BitStream_writeBits(0x20,&local_38);

      local_38 = local_2c;

      BitStream_writeBits(0x20,&local_38);

      local_38 = fStack_28;

      BitStream_writeBits(0x20,&local_38);

    }

  }

  return 0;

}
