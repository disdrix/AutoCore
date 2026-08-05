// =============================================================================
// BitStream_writeQuantizedFloat
// -----------------------------------------------------------------------------
// Purpose:  Thin trampoline into FUN_0042b980 (quantize float -> integer bits +
//           write). Decompiler loses formals; real args live on the stack/register
//           contract of the callee. Not sealed alone - open FUN_0042b980 unit.
//
// Address:  0x0042b910  (autoassault.exe, image base 0x400000)
// Stable:   aa_0042b910
// System:   network-bitstream
//
// Dual reviews:
//   reviews/A_aa_0042b910_BitStream_writeQuantizedFloat.md
//   reviews/B_aa_0042b910_BitStream_writeQuantizedFloat.md
// =============================================================================

void BitStream_writeQuantizedFloat(void)



{

  FUN_0042b980();

  return;

}
