// =============================================================================
// BitStream_readFlag
// -----------------------------------------------------------------------------
// Purpose:  Read 1 bit into *out as 0/1. On OOB (bitPos > endBits@+0x2c): sets
//           error@+0x1c=1, *out=0, returns !error (false when errored).
//
// Address:  0x0042ad50  (autoassault.exe, image base 0x400000)
// Stable:   aa_0042ad50
// System:   network-bitstream
//
// Control flow:
//   if bitPos > endBits: error=1; *out=0; return error==0
//   *out = (buf[bitPos>>3] & (1<<(bitPos&7))) != 0; bitPos++; return error==0
//
// Dual reviews:
//   reviews/A_aa_0042ad50_BitStream_readFlag.md
//   reviews/B_aa_0042ad50_BitStream_readFlag.md
// =============================================================================

bool __thiscall BitStream_readFlag(int param_1,uint8_t *param_2)



{

  byte bVar1;

  uint uVar2;

  

  uVar2 = *(uint *)(param_1 + 0x18);

  if (*(uint *)(param_1 + 0x2c) < uVar2) {

    *(uint8_t *)(param_1 + 0x1c) = 1;

    *param_2 = 0;

    return *(char *)(param_1 + 0x1c) == '\0';

  }

  bVar1 = *(byte *)((uVar2 >> 3) + *(int *)(param_1 + 0xc));

  *(uint *)(param_1 + 0x18) = uVar2 + 1;

  *param_2 = (bVar1 & (byte)(1 << ((byte)uVar2 & 7))) != 0;

  return *(char *)(param_1 + 0x1c) == '\0';

}
