// =============================================================================
// BitStream_writeFlag
// -----------------------------------------------------------------------------
// Purpose:  Write a single boolean as 1 bit into the BitStream (set or clear
//           the bit at bitPos, then advance +1). Grows via FUN_0042b450 if needed;
//           on grow fail returns silently without writing.
//
// Address:  0x0042b770  (autoassault.exe, image base 0x400000)
// Stable:   aa_0042b770
// System:   network-bitstream
//
// Control flow:
//   if bitPos+1 > capacity(+0x30): grow; fail -> return
//   mask = 1 << (bitPos & 7)
//   flag ? OR mask : AND ~mask; bitPos++
//
// Exactness: CF mirrors raw. Dual reviews:
//   reviews/A_aa_0042b770_BitStream_writeFlag.md
//   reviews/B_aa_0042b770_BitStream_writeFlag.md
// =============================================================================

void __thiscall BitStream_writeFlag(int param_1,char param_2)



{

  char cVar1;

  byte *pbVar2;

  byte bVar3;

  

  if (*(uint *)(param_1 + 0x30) < *(int *)(param_1 + 0x18) + 1U) {

    cVar1 = FUN_0042b450();

    if (cVar1 == '\0') {

      return;

    }

  }

  bVar3 = '\x01' << ((byte)*(uint *)(param_1 + 0x18) & 7);

  pbVar2 = (byte *)((*(uint *)(param_1 + 0x18) >> 3) + *(int *)(param_1 + 0xc));

  if (param_2 != '\0') {

    *pbVar2 = *pbVar2 | bVar3;

    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;

    return;

  }

  *pbVar2 = *pbVar2 & ~bVar3;

  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;

  return;

}
