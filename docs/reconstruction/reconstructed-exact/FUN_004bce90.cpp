// =============================================================================
// FUN_004bce90  (scaffold twin — prefer CNDHash_Ctor_009cb450.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bce90
// Address:   0x004bce90–0x004bcf01  (114 B / 0x72)
// Dual A/B:  2026-07-29 W28-J
// =============================================================================

#include <cstdint>

extern void *PTR_FUN_009cb450;
extern void __fastcall FUN_004bc7a0(void *thisHash);

void *__thiscall FUN_004bce90(void *param_1, std::uint8_t param_2)
{
  auto *p = reinterpret_cast<std::uint32_t *>(param_1);
  p[0] = reinterpret_cast<std::uint32_t>(&PTR_FUN_009cb450);
  p[1] = 0;
  p[3] = 0;
  p[2] = 1u << (param_2 & 0x1f);
  p[4] = 0;
  p[5] = 0;
  p[6] = 0;
  *reinterpret_cast<std::uint8_t *>(p + 7) = param_2;
  *reinterpret_cast<std::uint8_t *>(reinterpret_cast<std::uint8_t *>(p) + 0x1d) = 0;
  p[8] = 0;
  p[10] = 0;
  p[11] = 0;
  p[12] = 0;
  FUN_004bc7a0(param_1);
  return param_1;
}
