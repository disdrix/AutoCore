// =============================================================================
// BitStream_writeInt
// -----------------------------------------------------------------------------
// Purpose:  Convenience wrapper: write an integer using the low bitCount bits
//           via BitStream_writeBits(bitCount, &value). Decompiler surfaces
//           custom/register this; clean keeps CF only.
//
// Address:  0x0042b8f0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0042b8f0
// System:   network-bitstream
//
// Behavior: writeBits(bitCount, &value) - value is stack-local copy of first arg.
// Dual reviews:
//   reviews/A_aa_0042b8f0_BitStream_writeInt.md
//   reviews/B_aa_0042b8f0_BitStream_writeInt.md
// =============================================================================

void BitStream_writeInt(uint32_t /* width from decompiler */ param_1,uint8_t param_2)



{

  BitStream_writeBits(param_2,&param_1);

  return;

}
