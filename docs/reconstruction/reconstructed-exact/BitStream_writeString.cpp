// =============================================================================
// BitStream_writeString
// -----------------------------------------------------------------------------
// Stable ID: aa_0077d960
// Address:   0x0077d960 – 0x0077daec  (autoassault.exe, image base 0x400000)
// System:    net / TNL BitStream string (Huffman + raw)
// Dual:      W21-C 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Encode a length-prefixed C-string into BitStream.
//   Flag bit 0 = raw (u8 len + len*8 bits); flag bit 1 = Huffman
//   (u8 len + per-char alphabet codes). Chooses raw when len*8 <= Huffman cost.
//   Lazy-inits tables via FUN_0077d520 when DAT_00d17a28 == 0.
//
//   Cached wrapper is BitStream_writeStringCached (0x0042bb40) — sole caller.
//   Read twin: BitStream_readString (0x0077daf0).
//
// ABI (machine):
//   EAX = BitStream* this
//   EBX = const char* str  (null → empty / length-0 path)
//   stack arg0 = uint maxLen
//   epilogue plain RET (caller cleans 4)
//   returns 1 always (AL)
// =============================================================================

#include <cstdint>

extern "C" char FUN_0042b450(void); // grow/ensure capacity (this in ECX residual)
extern "C" void FUN_0077d520(void); // HuffmanBuildTables (once)
extern "C" std::uint32_t BitStream_writeBits(unsigned bitCount, const void* src); // thiscall ECX

// BitStream layout used here: +0xc buf, +0x18 bitPos, +0x30 bitCap
// Globals: DAT_00d17a28 init flag; DAT_00d1eabc alphabet* (0xc stride)

extern std::uint8_t DAT_00d17a28;
extern std::uint8_t* DAT_00d1eabc;

static void WriteFlagBit(std::uint8_t* bs, int value)
{
  std::uint32_t bitPos = *reinterpret_cast<std::uint32_t*>(bs + 0x18);
  std::uint32_t bitCap = *reinterpret_cast<std::uint32_t*>(bs + 0x30);
  if ((bitPos + 1u <= bitCap) || (FUN_0042b450() != 0)) {
    std::uint8_t* bytep =
        reinterpret_cast<std::uint8_t*>(*reinterpret_cast<int*>(bs + 0x0c)) + (bitPos >> 3);
    std::uint8_t mask = static_cast<std::uint8_t>(1u << (bitPos & 7));
    if (value)
      *bytep = static_cast<std::uint8_t>(*bytep | mask);
    else
      *bytep = static_cast<std::uint8_t>(*bytep & static_cast<std::uint8_t>(~mask));
    *reinterpret_cast<std::uint32_t*>(bs + 0x18) = bitPos + 1;
  }
}

// Machine entry: EAX=bs, EBX=str, stack maxLen → always 1
std::uint32_t BitStream_writeString(std::uint32_t maxLen /* EAX=bs, EBX=str */)
{
  // Decompiler residuals: in_EAX / unaff_EBX
  int in_EAX;              // BitStream*
  char* unaff_EBX;         // const char* str
  std::uint8_t* bs = reinterpret_cast<std::uint8_t*>(in_EAX);
  char* str = unaff_EBX;

  if (str == nullptr) {
    WriteFlagBit(bs, 0);
    std::uint32_t local_4 = 0;
    BitStream_writeBits(8, &local_4);
    return 1;
  }

  if (DAT_00d17a28 == 0) {
    FUN_0077d520();
  }

  char* pc = str;
  char c;
  do {
    c = *pc;
    pc = pc + 1;
  } while (c != '\0');
  std::uint32_t len = static_cast<std::uint32_t>(pc - (str + 1));
  if (maxLen < len) {
    len = maxLen;
  }

  std::uint32_t huffCost = 0;
  std::uint32_t i = 0;
  if (len != 0) {
    do {
      std::uint8_t ch = static_cast<std::uint8_t>(str[i]);
      i = i + 1;
      huffCost = huffCost + *(DAT_00d1eabc + 4 + static_cast<std::uint32_t>(ch) * 0xc);
    } while (i < len);
  }

  std::uint32_t local_4 = len;
  if (len * 8u <= huffCost) {
    // Raw cheaper or equal
    WriteFlagBit(bs, 0);
    BitStream_writeBits(8, &local_4);
    BitStream_writeBits(len * 8u, str);
    return 1;
  }

  // Huffman
  WriteFlagBit(bs, 1);
  BitStream_writeBits(8, &local_4);
  i = 0;
  if (len != 0) {
    do {
      int entry = reinterpret_cast<int>(DAT_00d1eabc) +
                  static_cast<int>(static_cast<std::uint8_t>(str[i])) * 0xc;
      BitStream_writeBits(*reinterpret_cast<std::uint8_t*>(entry + 4),
                          reinterpret_cast<void*>(entry + 8));
      i = i + 1;
    } while (i < len);
  }
  return 1;
}
