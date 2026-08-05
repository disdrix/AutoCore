// =============================================================================
// BitStream_writeBits
// -----------------------------------------------------------------------------
// Purpose:  Core bit writer for TNL/sector BitStream. Writes bitCount bits from
//           src into the stream buffer (LSB-first within each byte). Grows capacity
//           via FUN_0042b450 when bitPos+count would exceed capacity@+0x30.
//
// Address:  0x0042b4a0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0042b4a0
// System:   network-bitstream
//
// Signature (behavior):
//   bool __thiscall writeBits(BitStream* this, int bitCount, const byte* src)
//   Returns 1 on success; 0 if grow fails (bitPos clamped to capacity).
//   bitCount==0 is a success no-op (returns 1).
//
// Control flow summary:
//   1) bitCount==0 -> return 1
//   2) if bitPos(+0x18)+count > capacity(+0x30): grow; fail -> clamp + return 0
//   3) byte* = buffer(+0xc) + (bitPos>>3); bitInByte = bitPos&7
//   4) Fits in current partial byte -> mask-merge + advance
//   5) bitInByte==0 -> aligned full-byte copy + residual mask
//   6) else unaligned shift/merge across byte boundary
//
// Key offsets (BitStream this):
//   +0x0c  byte* buffer base
//   +0x18  bit position (current write cursor)
//   +0x30  capacity in bits
//
// Callees: FUN_0042b450 (grow)
// Callers: BitStream_writeInt, BitStream_writeFlag (indirect), many packers
//
// Exactness: CF mirrors raw; param_2 typed byte* in decomp but used as int count.
// Bit-for-bit / runtime / diff: DEFERRED.
// Dual reviews:
//   reviews/A_aa_0042b4a0_BitStream_writeBits.md
//   reviews/B_aa_0042b4a0_BitStream_writeBits.md
// =============================================================================

uint32_t /* width from decompiler */ __thiscall BitStream_writeBits(int param_1,byte *param_2,byte *param_3)



{

  byte bVar1;

  char cVar2;

  byte bVar3;

  byte bVar4;

  int iVar5;

  uint uVar6;

  sbyte sVar7;

  uint uVar8;

  byte bVar9;

  uint uVar10;

  byte *pbVar11;

  uint uVar12;

  bool bVar13;

  uint local_4;

  

  uVar10 = (uint)param_2;

  if (param_2 == (byte *)0x0) {

    return 1;

  }

  if (*(uint *)(param_1 + 0x30) < (uint)(*(int *)(param_1 + 0x18) + (int)param_2)) {

    cVar2 = FUN_0042b450();

    if (cVar2 == '\0') {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x30);

      return 0;

    }

  }

  uVar6 = *(uint *)(param_1 + 0x18);

  uVar12 = uVar6 & 7;

  pbVar11 = (byte *)((uVar6 >> 3) + *(int *)(param_1 + 0xc));

  uVar8 = 8 - uVar12;

  bVar13 = param_2 <= uVar8;

  param_2 = param_3;

  sVar7 = (sbyte)uVar12;

  if (bVar13) {

    bVar3 = ('\x01' << ((byte)uVar10 & 0x1f)) - 1;

    *pbVar11 = (*param_3 & bVar3) << sVar7 | ~(bVar3 << sVar7) & *pbVar11;

    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + uVar10;

    return 1;

  }

  iVar5 = uVar6 + uVar10;

  if (uVar12 == 0) {

    *(int *)(param_1 + 0x18) = iVar5;

    if (7 < uVar10) {

      uVar6 = uVar10 >> 3;

      do {

        *pbVar11 = *param_3;

        pbVar11 = pbVar11 + 1;

        param_3 = param_3 + 1;

        uVar10 = uVar10 - 8;

        uVar6 = uVar6 - 1;

      } while (uVar6 != 0);

    }

    if (uVar10 != 0) {

      bVar3 = ('\x01' << ((byte)uVar10 & 0x1f)) - 1;

      *pbVar11 = ~bVar3 & *pbVar11 | *param_3 & bVar3;

      return 1;

    }

  }

  else {

    bVar3 = (byte)uVar8;

    bVar9 = (byte)(0xff >> (bVar3 & 0x1f)) & *pbVar11;

    *(int *)(param_1 + 0x18) = iVar5;

    if (7 < uVar10) {

      local_4 = uVar10 >> 3;

      do {

        bVar4 = *param_2;

        param_2 = param_2 + 1;

        *pbVar11 = bVar4 << sVar7 | bVar9;

        pbVar11 = pbVar11 + 1;

        bVar9 = bVar4 >> (bVar3 & 0x1f);

        uVar10 = uVar10 - 8;

        local_4 = local_4 - 1;

      } while (local_4 != 0);

    }

    bVar4 = (byte)(0xff >> (7 - ((char)iVar5 - 1U & 7) & 0x1f));

    if (uVar10 == 0) {

      *pbVar11 = ~bVar4 & *pbVar11 | bVar4 & bVar9;

      return 1;

    }

    if (uVar10 <= uVar8) {

      *pbVar11 = (*param_2 << sVar7 | bVar9) & bVar4 | ~bVar4 & *pbVar11;

      return 1;

    }

    bVar1 = *param_2;

    *pbVar11 = bVar1 << sVar7 | bVar9;

    pbVar11[1] = bVar1 >> (bVar3 & 0x1f) & bVar4 | ~bVar4 & pbVar11[1];

  }

  return 1;

}
