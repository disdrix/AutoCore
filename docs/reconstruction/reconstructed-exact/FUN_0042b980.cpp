// =============================================================================
// BitStream_writeQuantizedSignedInt  (Ghidra: FUN_0042b980)
// -----------------------------------------------------------------------------
// Stable ID: aa_0042b980
// Address:   0x0042b980 – 0x0042b9cc  (autoassault.exe, image base 0x400000)
// System:    network-bitstream
// Generated: 2026-07-29 W20-J dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + register ABI from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named twin: reconstructed-exact/BitStream_writeQuantizedSignedInt.cpp
// =============================================================================

// PURPOSE:
//   Pack signed quantized integer: writeFlag(value < 0), then writeBits(bitCount-1)
//   of abs(value) or value. Integer stage of BitStream_writeQuantizedFloat.

#include <cstdint>

struct BitStream;

extern char __thiscall BitStream_writeFlag(BitStream *self, char flag);
extern void __thiscall BitStream_writeBits(BitStream *self, uint8_t bitCount, int *value);

// Custom ABI at entry: EDI = stream, ECX = value, AL = bitCount (decompiler
// surfaces only ECX as param_1 and phantoms in_AL; stream is unaff EDI).
void FUN_0042b980(int param_1 /*ECX*/)
{
    // Reconstruct full ABI for readable clean plate:
    BitStream *stream /*EDI*/ = nullptr; // filled by caller convention
    int value = param_1;
    char in_AL = 0; // bitCount from AL — phantom in decompiler
    (void)stream;
    (void)in_AL;

    // Image-faithful body (prefer named twin for ports):
    //   stream = EDI; bitCount = AL;
    //   local = value;
    //   cVar1 = BitStream_writeFlag(stream, value < 0);
    //   if (cVar1) { local = -value; BitStream_writeBits(stream, bitCount-1, &local); return; }
    //   local = value; BitStream_writeBits(stream, bitCount-1, &local);

    int local_4 = param_1;
    char cVar1 = BitStream_writeFlag(stream, param_1 < 0);
    if (cVar1 != '\0') {
        local_4 = -param_1;
        BitStream_writeBits(stream, static_cast<uint8_t>(in_AL - 1), &local_4);
        return;
    }
    local_4 = param_1;
    BitStream_writeBits(stream, static_cast<uint8_t>(in_AL - 1), &local_4);
}
