// =============================================================================
// FUN_0058e300  (scaffold twin of CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0058e300
// Address:   0x0058e300 – 0x0058e370  (autoassault.exe, image base 0x400000)
// System:    client object / FX phys link
// Dual:      W26-L 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow +
//            byte-sealed thiscall ECX on callees. Not modernization.
// =============================================================================

#include <cstdint>

// Nested phys-list helpers (signatures approximate; not OWN this dual)
std::uint32_t __thiscall FUN_0096d550(void* host, std::uint32_t key);
std::uint32_t __thiscall FUN_0096d460(void* host, std::uint32_t key);
std::uint32_t __thiscall FUN_0096dc80(void* host, std::uint32_t keyA,
                                      std::uint32_t keyB, std::uint32_t paramC);

// thiscall; RET 8; void
void __thiscall FUN_0058e300(int param_1, int param_2, int param_3)
{
  int iVar1;

  if (*(int *)(param_1 + 0x25c) < 0) {
    if (param_3 != 0) {
      // bytes: ECX = param_3 (want_stop), stack = *(param_1+0x914)
      FUN_0096d550(reinterpret_cast<void*>(param_3),
                   *reinterpret_cast<std::uint32_t*>(param_1 + 0x914));
    }
    if (param_2 != 0) {
      iVar1 = static_cast<int>(
          FUN_0096d460(reinterpret_cast<void*>(param_2),
                       *reinterpret_cast<std::uint32_t*>(param_1 + 0x258)));
      if (iVar1 == 0) {
        FUN_0096dc80(reinterpret_cast<void*>(param_2),
                     *reinterpret_cast<std::uint32_t*>(param_1 + 0x258),
                     *reinterpret_cast<std::uint32_t*>(param_1 + 0x914),
                     *reinterpret_cast<std::uint32_t*>(param_1 + 0x254));
        *reinterpret_cast<std::uint8_t*>(param_1 + 0x90f) =
            static_cast<std::uint8_t>(
                *reinterpret_cast<std::uint8_t*>(param_1 + 0x90f) | 1);
        return;
      }
    }
    *reinterpret_cast<std::uint8_t*>(param_1 + 0x90f) =
        static_cast<std::uint8_t>(
            *reinterpret_cast<std::uint8_t*>(param_1 + 0x90f) & 0xFE);
  }
  return;
}
