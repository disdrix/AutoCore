// =============================================================================
// FUN_00513de0  — scaffold alias; prefer Item_SetBroken.cpp
// -----------------------------------------------------------------------------
// Stable ID: aa_00513de0
// Address:   0x00513de0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-23 scaffold; dual A/B 2026-07-29 → Item_SetBroken
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: ItemFlag_Broken setter (mask 0x80000 / bit 19).
// Canonical clean: reconstructed-exact/Item_SetBroken.cpp
// Dual: docs/reconstruction/reviews/A|B_aa_00513de0_Item_SetBroken.md

#include <cstdint>

extern "C" void __fastcall FUN_00512670(int item);

void __thiscall FUN_00513de0(int *param_1, std::uint32_t param_2)
{
  int *extraout_ECX;

  if (((std::uint32_t)param_1[0x5f] >> 0x13 & 1) != (param_2 & 0xff)) {
    FUN_00512670((int)param_1);
    param_1 = extraout_ECX; // decompiler artifact; bytes keep ECX
  }
  // SEALED mask 0x80000
  param_1[0x5f] = (int)((std::uint32_t)param_1[0x5f] ^
                        (((param_2 & 0xff) << 0x13 ^ (std::uint32_t)param_1[0x5f]) & 0x80000u));
  if ((*(std::uint8_t *)((int)param_1 + 0x17e) & 8) != 0) {
    /* bytes: tail jmp [vtbl+0x90] with stack arg 0 — decompiler shows call */
    (**(void (**)(void))(*param_1 + 0x90))();
    return;
  }
  return;
}
