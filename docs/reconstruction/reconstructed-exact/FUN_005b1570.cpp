// =============================================================================
// FUN_005b1570
// -----------------------------------------------------------------------------
// Stable ID: aa_005b1570
// Address:   0x005b1570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b1570 @ 0x005b1570
// Stable ID: aa_005b1570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×8, goto×3, return×1.
//  - Notable callees: BitStream_readBits×5, BitStream_readInt×4, FUN_00424e50×2, FUN_005b1570.
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

void __thiscall FUN_005b1570(int param_1,int param_2,uint32_t /* width from decompiler */ *param_3,int param_4)



{

  byte bVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint8_t uVar5;

  uint16_t uVar6;

  uint32_t /* width from decompiler */ uVar7;

  bool bVar8;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar3 = param_2;

  uVar6 = BitStream_readInt(0xe);

  puVar4 = param_3;

  *(uint16_t *)(param_3 + 3) = uVar6;

  uVar6 = BitStream_readInt(8);

  *(uint16_t *)((int)puVar4 + 0xe) = uVar6;

  uVar5 = BitStream_readInt(8);

  *(uint8_t *)((int)puVar4 + 0x21) = uVar5;

  *puVar4 = 0x2014;

  uVar2 = *(uint *)(iVar3 + 0x18);

  if (*(uint *)(iVar3 + 0x2c) < uVar2) {

    *(uint8_t *)(iVar3 + 0x1c) = 1;

LAB_005b15bb:

    puVar4[1] = 0;

    puVar4[2] = 0;

    *(uint8_t *)(puVar4 + 8) = 0;

    *(uint16_t *)((int)puVar4 + 0x22) = 0;

    puVar4[4] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);

    puVar4[5] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x44);

    puVar4[6] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x48);

    puVar4[7] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c);

    puVar4[10] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);

    puVar4[0xb] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x44);

    uVar7 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x48);

  }

  else {

    bVar1 = *(byte *)((uVar2 >> 3) + *(int *)(iVar3 + 0xc));

    *(uint *)(iVar3 + 0x18) = uVar2 + 1;

    if ((bVar1 & (byte)(1 << ((byte)uVar2 & 7))) == 0) goto LAB_005b15bb;

    BitStream_readBits(0x20,&param_2);

    puVar4[1] = param_2;

    BitStream_readBits(0x20,&param_2);

    puVar4[2] = param_2;

    uVar2 = *(uint *)(iVar3 + 0x18);

    if (*(uint *)(iVar3 + 0x2c) < uVar2) {

      *(uint8_t *)(iVar3 + 0x1c) = 1;

LAB_005b168d:

      puVar4[4] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);

      puVar4[5] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x44);

      puVar4[6] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x48);

      puVar4[7] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c);

    }

    else {

      bVar1 = *(byte *)((uVar2 >> 3) + *(int *)(iVar3 + 0xc));

      *(uint *)(iVar3 + 0x18) = uVar2 + 1;

      if ((bVar1 & (byte)(1 << ((byte)uVar2 & 7))) == 0) goto LAB_005b168d;

      BitStream_readBits(0x40,&local_8);

      puVar4[5] = local_4;

      puVar4[4] = local_8;

      uVar5 = FUN_00424e50();

      *(uint8_t *)(puVar4 + 6) = uVar5;

    }

    uVar2 = *(uint *)(iVar3 + 0x18);

    if (*(uint *)(iVar3 + 0x2c) < uVar2) {

      *(uint8_t *)(iVar3 + 0x1c) = 1;

      bVar8 = false;

    }

    else {

      bVar8 = (*(byte *)((uVar2 >> 3) + *(int *)(iVar3 + 0xc)) & (byte)(1 << ((byte)uVar2 & 7))) !=

              0;

      *(uint *)(iVar3 + 0x18) = uVar2 + 1;

    }

    *(bool *)(puVar4 + 8) = bVar8;

    uVar6 = BitStream_readInt(10);

    *(uint16_t *)((int)puVar4 + 0x22) = uVar6;

    uVar2 = *(uint *)(iVar3 + 0x18);

    if (*(uint *)(iVar3 + 0x2c) < uVar2) {

      *(uint8_t *)(iVar3 + 0x1c) = 1;

    }

    else {

      bVar1 = *(byte *)((uVar2 >> 3) + *(int *)(iVar3 + 0xc));

      *(uint *)(iVar3 + 0x18) = uVar2 + 1;

      if ((bVar1 & (byte)(1 << ((byte)uVar2 & 7))) != 0) {

        BitStream_readBits(0x40,&local_8);

        puVar4[10] = local_8;

        puVar4[0xb] = local_4;

        uVar5 = FUN_00424e50();

        *(uint8_t *)(puVar4 + 0xc) = uVar5;

        goto LAB_005b1605;

      }

    }

    puVar4[10] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);

    puVar4[0xb] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x44);

    uVar7 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x48);

  }

  puVar4[0xc] = uVar7;

  puVar4[0xd] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c);

LAB_005b1605:

  if (0 < param_4 + -0x38) {

    BitStream_readBits((param_4 + -0x38) * 8,puVar4 + 0xe);

  }

  return;

}
