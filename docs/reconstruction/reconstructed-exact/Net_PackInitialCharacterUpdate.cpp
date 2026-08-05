// =============================================================================
// Net_PackInitialCharacterUpdate
// -----------------------------------------------------------------------------
// Stable ID: aa_0060a230
// Address:   0x0060a230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Net_PackInitialCharacterUpdate @ 0x0060a230
// Stable ID: aa_0060a230
// Embedded strings (evidence for future rename):
//   - "Can\'t save ghost data for character!"
//   - "Packing initial update for character %I64"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~197 non-empty decompiler lines.
//  - Control keywords: if×17, for×2, return×2.
//  - Notable callees: BitStream_writeBits×28, CONCAT22×9, BitStream_writeFlag×8, BitStream_writeInt×5, CONCAT31×5, FUN_0051ffd0×4, FUN_0042bb40×3, FUN_007a4480×2.
//  - Strings: "Can\'t save ghost data for character!"; "Packing initial update for character %I64".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Packing initial update for character %I64"
 * Domain alias of FUN_0060a230 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint64_t __thiscall

Net_PackInitialCharacterUpdate(int param_1,uint32_t /* width from decompiler */ param_2,uint param_3,uint param_4,uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  int *piVar5;

  uint16_t extraout_var_01;

  uint16_t extraout_var_02;

  uint16_t extraout_var_03;

  uint16_t extraout_var_04;

  uint16_t extraout_var_05;

  uint16_t extraout_var_06;

  uint32_t /* width from decompiler */ uVar6;

  uint8_t uStack_39;

  int iStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  int iStack_2c;

  int iStack_28;

  int iStack_1c;

  int iStack_18;

  int iStack_14;

  

  if (*(int *)(param_1 + 0x50) == 0) {

    FUN_007a4480(1,"Can\'t save ghost data for character!");

    return 0;

  }

  iVar3 = (**(code **)(**(int **)(param_1 + 0x50) + 0x1dc))();

  if (DAT_00d1798c != '\0') {

    if (DAT_00d02a30 != '\0') {

      iVar1 = *(int *)(*(int *)(iVar3 + 4) + 4);

      FUN_007a4480(0xffffffff,"Packing initial update for character %I64",

                   *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + iVar3),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + iVar3));

    }

    FUN_005b1290(param_5);

    uVar6 = 0x11;

    uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x160))(0x11);

    FUN_0042bb40(uVar4,uVar6);

    FUN_0042bb40(iVar3 + 0xcfc,0x33);

    uStack_39 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x27c))();

    BitStream_writeBits(8,&uStack_39);

    iStack_38 = *(int *)(iVar3 + 0x210);

    uStack_34 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x214);

    BitStream_writeBits(0x40,&iStack_38);

    iStack_38 = CONCAT22(extraout_var_04,*(uint16_t *)(iVar3 + 0x6fc));

    BitStream_writeBits(0x10,&iStack_38);

    iStack_38 = CONCAT22(extraout_var_01,*(uint16_t *)(iVar3 + 0x6f8));

    BitStream_writeBits(0x10,&iStack_38);

    iStack_38 = CONCAT22(extraout_var,*(uint16_t *)(iVar3 + 0x708));

    BitStream_writeBits(0x10,&iStack_38);

    iStack_38 = CONCAT22(extraout_var_05,*(uint16_t *)(iVar3 + 0x70c));

    BitStream_writeBits(0x10,&iStack_38);

    iStack_38 = CONCAT22(extraout_var_02,*(uint16_t *)(iVar3 + 0x714));

    BitStream_writeBits(0x10,&iStack_38);

    iStack_38 = CONCAT22(extraout_var_00,*(uint16_t *)(iVar3 + 0x710));

    BitStream_writeBits(0x10,&iStack_38);

    iStack_38 = CONCAT22(extraout_var_06,*(uint16_t *)(iVar3 + 0x704));

    BitStream_writeBits(0x10,&iStack_38);

    iStack_38 = CONCAT22(extraout_var_03,*(uint16_t *)(iVar3 + 0x700));

    BitStream_writeBits(0x10,&iStack_38);

    iStack_38 = *(int *)(iVar3 + 0x638);

    BitStream_writeBits(0x20,&iStack_38);

    uVar4 = FUN_0051ffd0(0);

    BitStream_writeInt(uVar4,0x18);

    uVar4 = FUN_0051ffd0(1);

    BitStream_writeInt(uVar4,0x18);

    uVar4 = FUN_0051ffd0(2);

    BitStream_writeInt(uVar4,0x18);

    uVar4 = FUN_0051ffd0(4);

    BitStream_writeInt(uVar4,3);

    FUN_005b2830(param_5,*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);

  }

  param_4 = param_3 & 0x80000000 | param_4;

  if (param_4 == 0) {

    uVar4 = 0;

  }

  else {

    uVar4 = CONCAT31((int3)(param_4 >> 8),1);

  }

  cVar2 = BitStream_writeFlag(uVar4);

  if (cVar2 != '\0') {

    BitStream_writeInt(*(uint8_t *)(iVar3 + 0x6b4),4);

  }

  if ((param_3 & 0x20000000) == 0) {

    uVar4 = 0;

  }

  else {

    uVar4 = CONCAT31((int3)((param_3 & 0x20000000) >> 8),1);

  }

  cVar2 = BitStream_writeFlag(uVar4);

  if (cVar2 != '\0') {

    iStack_38 = *(int *)(iVar3 + 0xcf4);

    BitStream_writeBits(0x20,&iStack_38);

    iStack_38 = *(int *)(iVar3 + 0xcf8);

    BitStream_writeBits(0x20,&iStack_38);

    FUN_0042bb40(iVar3 + 0xcfc,0x33);

  }

  if ((param_3 & 0x40000000) == 0) {

    uVar4 = 0;

  }

  else {

    uVar4 = CONCAT31((int3)((param_3 & 0x40000000) >> 8),1);

  }

  uVar4 = BitStream_writeFlag(uVar4);

  if ((char)uVar4 != '\0') {

    iStack_38 = CONCAT22((short)((uint)uVar4 >> 0x10),*(uint16_t *)(iVar3 + 0x514));

    BitStream_writeBits(0x10,&iStack_38);

  }

  cVar2 = BitStream_writeFlag((param_3 & 2) != 0);

  if (cVar2 != '\0') {

    if (*(int *)(iVar3 + 8) == 0) {

      piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0x84 + iVar3);

    }

    else {

      piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 8) + 0x3c) + 0xb0);

    }

    iStack_2c = piVar5[1];

    iStack_38 = *piVar5;

    iStack_28 = piVar5[2];

    BitStream_writeBits(0x20,&iStack_38);

    iStack_38 = iStack_2c;

    BitStream_writeBits(0x20,&iStack_38);

    iStack_38 = iStack_28;

    BitStream_writeBits(0x20,&iStack_38);

    if (*(int *)(iVar3 + 8) == 0) {

      piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0x94 + iVar3);

    }

    else {

      piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 8) + 0x3c) + 0x30);

    }

    iStack_1c = piVar5[1];

    iStack_38 = *piVar5;

    iStack_18 = piVar5[2];

    iStack_14 = piVar5[3];

    BitStream_writeBits(0x20,&iStack_38);

    iStack_38 = iStack_1c;

    BitStream_writeBits(0x20,&iStack_38);

    iStack_38 = iStack_18;

    BitStream_writeBits(0x20,&iStack_38);

    iStack_38 = iStack_14;

    BitStream_writeBits(0x20,&iStack_38);

    if (*(int *)(iVar3 + 8) == 0) {

      piVar5 = &DAT_00d02a40;

    }

    else {

      piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 8) + 0x3c) + 0x40);

    }

    iStack_2c = piVar5[1];

    iStack_38 = *piVar5;

    iStack_28 = piVar5[2];

    BitStream_writeBits(0x20,&iStack_38);

    iStack_38 = iStack_2c;

    BitStream_writeBits(0x20,&iStack_38);

    iStack_38 = iStack_28;

    BitStream_writeBits(0x20,&iStack_38);

    piVar5 = (int *)FUN_004c3ac0();

    iStack_2c = piVar5[1];

    iStack_38 = *piVar5;

    iStack_28 = piVar5[2];

    BitStream_writeBits(0x20,&iStack_38);

    iStack_38 = iStack_2c;

    BitStream_writeBits(0x20,&iStack_38);

    iStack_38 = iStack_28;

    BitStream_writeBits(0x20,&iStack_38);

  }

  cVar2 = BitStream_writeFlag((param_3 & 4) != 0);

  if (cVar2 != '\0') {

    if (*(int *)(*(int *)(param_1 + 0x50) + 0xa0) == 0) {

      uStack_30 = 0xffffffff;

      iStack_2c = -1;

      iStack_38 = (uint)iStack_38._1_3_ << 8;

    }

    else {

      iVar3 = *(int *)(*(int *)(param_1 + 0x50) + 0xa0);

      uStack_30 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x160);

      iStack_2c = *(int *)(iVar3 + 0x164);

      iStack_38 = CONCAT31(iStack_38._1_3_,*(uint8_t *)(iVar3 + 0x168));

    }

    BitStream_writeBits(0x40,&uStack_30);

    BitStream_writeFlag(iStack_38);

  }

  if ((param_3 & 0x100) == 0) {

    uVar4 = 0;

  }

  else {

    uVar4 = CONCAT31((int3)((param_3 & 0x100) >> 8),1);

  }

  cVar2 = BitStream_writeFlag(uVar4);

  if (cVar2 != '\0') {

    iVar3 = (**(code **)(**(int **)(param_1 + 0x50) + 0x210))(0);

    BitStream_writeFlag(*(uint8_t *)(iVar3 + 0x529));

  }

  return 0;

}
