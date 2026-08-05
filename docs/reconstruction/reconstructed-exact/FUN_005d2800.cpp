// =============================================================================
// FUN_005d2800
// -----------------------------------------------------------------------------
// Stable ID: aa_005d2800
// Address:   0x005d2800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d2800 @ 0x005d2800
// Stable ID: aa_005d2800
// Embedded strings (evidence for future rename):
//   - "Can\'t save ghost data for creature!"
//   - "Packing initial update for creature %I64d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~210 non-empty decompiler lines.
//  - Control keywords: if×23, for×2, return×2.
//  - Notable callees: BitStream_writeBits×19, BitStream_writeFlag×16, BitStream_writeInt×5, CONCAT31×3, FUN_007a4480×2, FUN_004c3ac0, FUN_005b1290, FUN_005b2830.
//  - Strings: "Can\'t save ghost data for creature!"; "Packing initial update for creature %I64d".
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

uint64_t __thiscall

FUN_005d2800(int param_1,uint32_t /* width from decompiler */ param_2,uint param_3,uint param_4,uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  bool bVar2;

  char cVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint *puVar8;

  uint8_t uStack_3d;

  int local_3c;

  uint uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint uStack_2c;

  uint uStack_28;

  uint uStack_20;

  uint uStack_1c;

  uint uStack_18;

  uint uStack_14;

  

  local_3c = param_1;

  if (*(int *)(param_1 + 0x50) == 0) {

    FUN_007a4480(1,"Can\'t save ghost data for creature!");

    return 0;

  }

  iVar4 = (**(code **)(**(int **)(param_1 + 0x50) + 0x1d8))();

  if (DAT_00d1798c != '\0') {

    if (DAT_00bc5590 != '\0') {

      iVar6 = *(int *)(*(int *)(iVar4 + 4) + 4);

      FUN_007a4480(0xffffffff,"Packing initial update for creature %I64d",

                   *(uint32_t /* width from decompiler */ *)(iVar6 + 0x164 + iVar4),*(uint32_t /* width from decompiler */ *)(iVar6 + 0x168 + iVar4));

    }

    FUN_005b1290(param_5);

    cVar3 = BitStream_writeFlag(*(int *)(iVar4 + 0x128) != -1);

    if (cVar3 != '\0') {

      BitStream_writeInt(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x128),0x14);

    }

    cVar3 = BitStream_writeFlag((*(uint *)(iVar4 + 0x218) & *(uint *)(iVar4 + 0x21c)) != 0xffffffff)

    ;

    if (cVar3 != '\0') {

      BitStream_writeInt(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x218),0x14);

    }

    uVar5 = *(uint *)(iVar4 + 0x220) & *(uint *)(iVar4 + 0x224);

    if (uVar5 == 0xffffffff) {

      uVar7 = 0xffffff00;

    }

    else {

      uVar7 = CONCAT31((int3)(uVar5 >> 8),1);

    }

    cVar3 = BitStream_writeFlag(uVar7);

    if (cVar3 != '\0') {

      BitStream_writeInt(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x220),0x14);

    }

    puVar8 = (uint *)(iVar4 + 0x228);

    uStack_1c = *(uint *)(iVar4 + 0x22c);

    uStack_14 = *(uint *)(iVar4 + 0x234);

    if (((*puVar8 & uStack_1c) == 0xffffffff) && ((char)*(uint32_t /* width from decompiler */ *)(iVar4 + 0x230) == '\0')) {

      bVar2 = true;

    }

    else {

      bVar2 = false;

    }

    cVar3 = BitStream_writeFlag(!bVar2);

    if (cVar3 != '\0') {

      uStack_38 = *puVar8;

      uStack_34 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x22c);

      uStack_18 = *(uint *)(iVar4 + 0x230);

      uStack_14 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x234);

      uStack_1c = uStack_34;

      BitStream_writeBits(0x40,&uStack_38);

      uStack_20 = *puVar8;

      uStack_1c = *(uint *)(iVar4 + 0x22c);

      uStack_14 = *(uint *)(iVar4 + 0x234);

      BitStream_writeFlag(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x230));

    }

    cVar3 = BitStream_writeFlag(*(int *)(iVar4 + 600) != 0);

    if (cVar3 != '\0') {

      iVar6 = *(int *)(iVar4 + 600);

      iVar1 = *(int *)(*(int *)(iVar6 + 4) + 4);

      uStack_38 = *(uint *)(iVar1 + 0x164 + iVar6);

      uStack_34 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + iVar6);

      BitStream_writeBits(0x40,&uStack_38);

    }

    BitStream_writeFlag(*(char *)(iVar4 + 0x205) == '\0');

    uStack_3d = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x27c))();

    BitStream_writeBits(8,&uStack_3d);

    BitStream_writeFlag(*(uint8_t *)(iVar4 + 0x30b));

    FUN_005b2830(param_5,*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4);

  }

  cVar3 = BitStream_writeFlag((param_3 & 0x20) != 0);

  if (cVar3 != '\0') {

    iVar6 = *(int *)(*(int *)(iVar4 + 4) + 4) + iVar4;

    uStack_38 = *(uint *)(iVar6 + 0x44);

    uStack_34 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x48);

    uStack_18 = *(uint *)(iVar6 + 0x4c);

    uStack_14 = *(uint *)(iVar6 + 0x50);

    BitStream_writeBits(0x40,&uStack_38);

  }

  cVar3 = BitStream_writeFlag((param_3 & 8) != 0);

  if (cVar3 != '\0') {

    iVar6 = (**(code **)(**(int **)(local_3c + 0x50) + 0x23c))();

    if (iVar6 < 0) {

      uVar7 = 0;

    }

    else {

      uVar7 = (**(code **)(**(int **)(local_3c + 0x50) + 0x23c))();

    }

    BitStream_writeInt(uVar7,0x12);

    uVar7 = (**(code **)(**(int **)(local_3c + 0x50) + 0x198))();

    BitStream_writeFlag(uVar7);

  }

  cVar3 = BitStream_writeFlag((param_3 & 0x40) != 0);

  if (cVar3 != '\0') {

    iVar6 = (**(code **)(**(int **)(local_3c + 0x50) + 0x244))();

    if (iVar6 < 0) {

      uVar7 = 0;

    }

    else {

      uVar7 = (**(code **)(**(int **)(local_3c + 0x50) + 0x244))();

    }

    BitStream_writeInt(uVar7,0x12);

  }

  param_4 = param_3 & 0x80000000 | param_4;

  if (param_4 == 0) {

    uVar7 = 0;

  }

  else {

    uVar7 = CONCAT31((int3)(param_4 >> 8),1);

  }

  cVar3 = BitStream_writeFlag(uVar7);

  if (cVar3 != '\0') {

    uStack_3d = *(uint8_t *)(iVar4 + 0x26c);

    BitStream_writeBits(8,&uStack_3d);

  }

  cVar3 = BitStream_writeFlag((param_3 & 2) != 0);

  if (cVar3 != '\0') {

    if (*(int *)(iVar4 + 8) == 0) {

      puVar8 = (uint *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0x84 + iVar4);

    }

    else {

      puVar8 = (uint *)(*(int *)(*(int *)(iVar4 + 8) + 0x3c) + 0xb0);

    }

    uStack_2c = puVar8[1];

    uStack_38 = *puVar8;

    uStack_28 = puVar8[2];

    BitStream_writeBits(0x20,&uStack_38);

    uStack_38 = uStack_2c;

    BitStream_writeBits(0x20,&uStack_38);

    uStack_38 = uStack_28;

    BitStream_writeBits(0x20,&uStack_38);

    if (*(int *)(iVar4 + 8) == 0) {

      puVar8 = (uint *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0x94 + iVar4);

    }

    else {

      puVar8 = (uint *)(*(int *)(*(int *)(iVar4 + 8) + 0x3c) + 0x30);

    }

    uStack_1c = puVar8[1];

    uStack_38 = *puVar8;

    uStack_18 = puVar8[2];

    uStack_14 = puVar8[3];

    BitStream_writeBits(0x20,&uStack_38);

    uStack_38 = uStack_1c;

    BitStream_writeBits(0x20,&uStack_38);

    uStack_38 = uStack_18;

    BitStream_writeBits(0x20,&uStack_38);

    uStack_38 = uStack_14;

    BitStream_writeBits(0x20,&uStack_38);

    if (*(int *)(iVar4 + 8) == 0) {

      puVar8 = &DAT_00bc55a0;

    }

    else {

      puVar8 = (uint *)(*(int *)(*(int *)(iVar4 + 8) + 0x3c) + 0x40);

    }

    uStack_2c = puVar8[1];

    uStack_38 = *puVar8;

    uStack_28 = puVar8[2];

    BitStream_writeBits(0x20,&uStack_38);

    uStack_38 = uStack_2c;

    BitStream_writeBits(0x20,&uStack_38);

    uStack_38 = uStack_28;

    BitStream_writeBits(0x20,&uStack_38);

    puVar8 = (uint *)FUN_004c3ac0();

    uStack_2c = puVar8[1];

    uStack_38 = *puVar8;

    uStack_28 = puVar8[2];

    BitStream_writeBits(0x20,&uStack_38);

    uStack_38 = uStack_2c;

    BitStream_writeBits(0x20,&uStack_38);

    uStack_38 = uStack_28;

    BitStream_writeBits(0x20,&uStack_38);

  }

  cVar3 = BitStream_writeFlag((param_3 & 4) != 0);

  if (cVar3 != '\0') {

    if (*(int *)(*(int *)(local_3c + 0x50) + 0xa0) == 0) {

      uStack_38 = 0xffffffff;

      uStack_34 = 0xffffffff;

      local_3c = (uint)local_3c._1_3_ << 8;

    }

    else {

      iVar4 = *(int *)(*(int *)(local_3c + 0x50) + 0xa0);

      uStack_38 = *(uint *)(iVar4 + 0x160);

      uStack_34 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x164);

      local_3c = CONCAT31(local_3c._1_3_,*(uint8_t *)(iVar4 + 0x168));

    }

    BitStream_writeBits(0x40,&uStack_38);

    BitStream_writeFlag(local_3c);

  }

  return 0;

}
