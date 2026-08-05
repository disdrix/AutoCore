// =============================================================================
// BitStream_writeQuantizedSignedInt
// -----------------------------------------------------------------------------
// Stable ID: aa_0042b980
// Address:   0x0042b980 – 0x0042b9cc  (autoassault.exe, image base 0x400000)
// System:    network-bitstream
// Twin:      reconstructed-exact/FUN_0042b980.cpp
// Sibling:   BitStream_readQuantizedSignedInt / FUN_0042b9d0 @ 0x0042b9d0
// Caller:    BitStream_writeQuantizedFloat @ 0x0042b910
// Generated: 2026-07-29 W20-J dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + register ABI from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Write sign flag + (bitCount-1) magnitude bits for a signed quantized int.
//   Parent writeQuantizedFloat scales float * ((1<<(bitCount-1))-1) then truncates.

#include <cstdint>

struct BitStream;

extern char __thiscall BitStream_writeFlag(BitStream *self, char flag);
extern void __thiscall BitStream_writeBits(BitStream *self, uint8_t bitCount, int *value);

void BitStream_writeQuantizedSignedInt(BitStream *stream /*EDI*/,
                                       int value /*ECX*/,
                                       uint8_t bitCount /*AL*/)
{
    int local = value;
    uint8_t magBits = static_cast<uint8_t>(bitCount - 1);
    char wroteNeg = BitStream_writeFlag(stream, value < 0);
    if (wroteNeg != 0) {
        local = -value;
        BitStream_writeBits(stream, magBits, &local);
        return;
    }
    local = value;
    BitStream_writeBits(stream, magBits, &local);
}
