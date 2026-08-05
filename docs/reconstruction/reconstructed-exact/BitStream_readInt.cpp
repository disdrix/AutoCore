// =============================================================================
// BitStream_readInt
// -----------------------------------------------------------------------------
// Purpose:  Read bitCount bits as unsigned int. Masks to bitCount bits unless
//           bitCount==32 (full word, no mask). Used for TFID path ids (0x12=18 bits).
//
// Address:  0x0042b8b0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0042b8b0
// System:   network-bitstream
//
// Control flow:
//   local=0; readBits(bitCount, &local);
//   if bitCount != 32: local &= (1<<bitCount)-1
//   return local
//
// Dual reviews:
//   reviews/A_aa_0042b8b0_BitStream_readInt.md
//   reviews/B_aa_0042b8b0_BitStream_readInt.md
// =============================================================================

uint BitStream_readInt(byte param_1)



{

  uint local_4;

  

  local_4 = 0;

  BitStream_readBits(param_1,&local_4);

  if (param_1 != 0x20) {

    local_4 = local_4 & (1 << (param_1 & 0x1f)) - 1U;

  }

  return local_4;

}
