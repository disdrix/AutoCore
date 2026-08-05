// =============================================================================
// BitStream_readString
// -----------------------------------------------------------------------------
// Stable ID: aa_0077daf0
// Address:   0x0077daf0  (autoassault.exe, image base 0x400000)
// Body:      0x0077daf0 – 0x0077dc13
// System:    net / TNL BitStream string (Huffman + raw)
// Dual:      W20-K 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Decode a length-prefixed C-string from BitStream into out.
//   Flag bit 1 = Huffman (tree DAT_00d1eab0, alphabet DAT_00d1eabc);
//   flag bit 0 / overflow = raw u8 length + len*8 bits.
//   Lazy-inits Huffman tables via FUN_0077d520 when DAT_00d17a28 == 0.
//
//   Cached wrapper is BitStream_readStringCached (0x0042ba90) — not this unit.
//
// ABI (machine):
//   ESI = BitStream* this (caller-held register convention)
//   stack arg0 = char* out
//   epilogue plain RET (caller cleans 4)
//   returns 1 always (AL)
// =============================================================================

#include <cstdint>

extern "C" void FUN_0077d520(void); // HuffmanBuildTables (once)
extern "C" void BitStream_readBits(unsigned bitCount, void* dest); // thiscall ESI residual

// BitStream layout used here: +0xc buf, +0x18 bitPos, +0x1c error, +0x2c bitMax
// Globals: DAT_00d17a28 init flag; DAT_00d1eab0 tree*; DAT_00d1eabc alphabet*

extern std::uint8_t DAT_00d17a28;
extern std::uint8_t* DAT_00d1eab0;
extern std::uint8_t* DAT_00d1eabc;

std::uint32_t BitStream_readString(int param_1 /* char* out; ESI = BitStream* */)
{
  std::uint8_t bVar1;
  std::int16_t sVar2;
  std::uint32_t uVar3;
  int unaff_ESI; // BitStream* this
  std::uint32_t uVar4;
  int iVar5;
  std::uint32_t local_4;

  if (DAT_00d17a28 == 0) {
    FUN_0077d520();
  }
  uVar4 = *(std::uint32_t*)(unaff_ESI + 0x18);
  if (*(std::uint32_t*)(unaff_ESI + 0x2c) < uVar4) {
    *(std::uint8_t*)(unaff_ESI + 0x1c) = 1;
  }
  else {
    bVar1 = *(std::uint8_t*)((uVar4 >> 3) + *(int*)(unaff_ESI + 0xc));
    *(std::uint32_t*)(unaff_ESI + 0x18) = uVar4 + 1;
    if ((bVar1 & (std::uint8_t)(1 << ((std::uint8_t)uVar4 & 7))) != 0) {
      uVar4 = 0;
      local_4 = 0;
      BitStream_readBits(8, &local_4);
      local_4 = local_4 & 0xff;
      if (local_4 != 0) {
        do {
          iVar5 = 0;
          do {
            uVar3 = *(std::uint32_t*)(unaff_ESI + 0x18);
            if (*(std::uint32_t*)(unaff_ESI + 0x2c) < uVar3) {
              *(std::uint8_t*)(unaff_ESI + 0x1c) = 1;
LAB_0077dba3:
              sVar2 = *(std::int16_t*)(DAT_00d1eab0 + 4 + iVar5 * 8);
            }
            else {
              bVar1 = *(std::uint8_t*)((uVar3 >> 3) + *(int*)(unaff_ESI + 0xc));
              *(std::uint32_t*)(unaff_ESI + 0x18) = uVar3 + 1;
              if ((bVar1 & (std::uint8_t)(1 << ((std::uint8_t)uVar3 & 7))) == 0) goto LAB_0077dba3;
              sVar2 = *(std::int16_t*)(DAT_00d1eab0 + 6 + iVar5 * 8);
            }
            iVar5 = (int)sVar2;
          } while (-1 < iVar5);
          *(std::uint8_t*)(param_1 + uVar4) =
              *(std::uint8_t*)(DAT_00d1eabc + iVar5 * -0xc + -7);
          uVar4 = uVar4 + 1;
        } while (uVar4 < local_4);
      }
      *(std::uint8_t*)(local_4 + param_1) = 0;
      return 1;
    }
  }
  local_4 = 0;
  BitStream_readBits(8, &local_4);
  uVar4 = local_4 & 0xff;
  BitStream_readBits(uVar4 * 8, (void*)param_1);
  *(std::uint8_t*)(uVar4 + param_1) = 0;
  return 1;
}
