// =============================================================================
// FUN_0077d440  (twin of BitStream_HuffmanAssignCodes)
// -----------------------------------------------------------------------------
// Stable ID: aa_0077d440
// Address:   0x0077d440 – 0x0077d514  (autoassault.exe, image base 0x400000)
// System:    net / TNL BitStream Huffman (code assignment walk)
// Dual:      W26-C 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

extern "C" std::uint8_t FUN_0042b450();
extern std::uint8_t* DAT_00d1eabc;
extern std::uint8_t* DAT_00d1eab0;

// cdecl; void; 3 stack formals — decompiler-faithful body
extern "C" void FUN_0077d440(int param_1, int param_2, int param_3)
{
  int iVar1;
  char cVar2;
  int iVar3;
  std::uint8_t* pbVar4;

  if (param_2 < 0) {
    iVar3 = reinterpret_cast<int>(DAT_00d1eabc) + (param_2 * 3 + 3) * -4;
    *reinterpret_cast<std::uint32_t*>(iVar3 + 8) =
        **reinterpret_cast<std::uint32_t**>(param_1 + 0xc);
    *reinterpret_cast<std::uint8_t*>(iVar3 + 4) =
        static_cast<std::uint8_t>(param_3);
    return;
  }

  iVar1 = *reinterpret_cast<int*>(param_1 + 0x18);
  iVar3 = reinterpret_cast<int>(DAT_00d1eab0) + param_2 * 8;

  if (*reinterpret_cast<std::uint32_t*>(param_1 + 0x30) <
      static_cast<std::uint32_t>(iVar1 + 1)) {
    cVar2 = static_cast<char>(FUN_0042b450());
    if (cVar2 != '\0') {
      goto LAB_0077d499;
    }
  } else {
  LAB_0077d499:
    pbVar4 = reinterpret_cast<std::uint8_t*>(
        *reinterpret_cast<int*>(param_1 + 0xc) +
        (*reinterpret_cast<std::uint32_t*>(param_1 + 0x18) >> 3));
    *pbVar4 = static_cast<std::uint8_t>(
        *pbVar4 &
        ~static_cast<std::uint8_t>(
            1 << (*reinterpret_cast<std::uint32_t*>(param_1 + 0x18) & 7)));
    *reinterpret_cast<int*>(param_1 + 0x18) =
        *reinterpret_cast<int*>(param_1 + 0x18) + 1;
  }

  FUN_0077d440(param_1,
               static_cast<int>(*reinterpret_cast<std::int16_t*>(iVar3 + 4)),
               param_3 + 1);
  *reinterpret_cast<int*>(param_1 + 0x18) = iVar1;

  if (*reinterpret_cast<std::uint32_t*>(param_1 + 0x30) <
      static_cast<std::uint32_t>(iVar1 + 1)) {
    cVar2 = static_cast<char>(FUN_0042b450());
    if (cVar2 == '\0') {
      goto LAB_0077d4fe;
    }
  }
  pbVar4 = reinterpret_cast<std::uint8_t*>(
      *reinterpret_cast<int*>(param_1 + 0xc) +
      (*reinterpret_cast<std::uint32_t*>(param_1 + 0x18) >> 3));
  *pbVar4 = static_cast<std::uint8_t>(
      *pbVar4 |
      static_cast<std::uint8_t>(
          1 << (*reinterpret_cast<std::uint32_t*>(param_1 + 0x18) & 7)));
  *reinterpret_cast<int*>(param_1 + 0x18) =
      *reinterpret_cast<int*>(param_1 + 0x18) + 1;

LAB_0077d4fe:
  FUN_0077d440(param_1,
               static_cast<int>(*reinterpret_cast<std::int16_t*>(iVar3 + 6)),
               param_3 + 1);
  *reinterpret_cast<int*>(param_1 + 0x18) = iVar1;
}
