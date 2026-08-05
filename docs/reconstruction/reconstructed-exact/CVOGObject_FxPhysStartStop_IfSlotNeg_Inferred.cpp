// =============================================================================
// CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred
// -----------------------------------------------------------------------------
// Purpose:  On a client object whose slot field (+0x25c) is negative, optionally
//           stop (remove phys-link by +0x914 key) and/or start (attach phys-link
//           by +0x258/+0x914/+0x254). Sets or clears +0x90f bit0.
//           Unslotted twin of FUN_0058e270 (slot-filter path).
//
// Address:  0x0058e300 – 0x0058e370 exclusive (112 bytes)
// Stable:   aa_0058e300
// Ghidra:   FUN_0058e300
// Callers:  FUN_004b7030 (want_start/want_stop), FUN_004b7150 (0, phys stop)
// Callees:  FUN_0096d550, FUN_0096d460, FUN_0096dc80
//
// Convention: MSVC thiscall; ECX=object*; 2 stack dwords; RET 8
// Exactness:  Preserves retail CF; callee this restored from bytes.
// Bit-for-bit package: DEFERRED. Runtime / differential: OPEN.
// Dual A/B (static): SEALED accept 2026-07-29 (W26-L).
// =============================================================================

#include <cstdint>

std::uint32_t __thiscall FUN_0096d550(void* host, std::uint32_t key);
std::uint32_t __thiscall FUN_0096d460(void* host, std::uint32_t key);
std::uint32_t __thiscall FUN_0096dc80(void* host, std::uint32_t keyA,
                                      std::uint32_t keyB, std::uint32_t paramC);

/// Apply FX phys stop and/or start when object slot id is negative.
void __thiscall CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred(
    void* self,
    void* want_start,   // non-null → try attach on this host
    void* want_stop)    // non-null → remove link on this host
{
  auto* obj = reinterpret_cast<std::uint8_t*>(self);

  if (*reinterpret_cast<int*>(obj + 0x25c) >= 0) {
    return;
  }

  if (want_stop != nullptr) {
    FUN_0096d550(want_stop, *reinterpret_cast<std::uint32_t*>(obj + 0x914));
  }

  if (want_start != nullptr) {
    std::uint32_t found =
        FUN_0096d460(want_start, *reinterpret_cast<std::uint32_t*>(obj + 0x258));
    if (found == 0) {
      FUN_0096dc80(want_start,
                   *reinterpret_cast<std::uint32_t*>(obj + 0x258),
                   *reinterpret_cast<std::uint32_t*>(obj + 0x914),
                   *reinterpret_cast<std::uint32_t*>(obj + 0x254));
      obj[0x90f] = static_cast<std::uint8_t>(obj[0x90f] | 0x01);
      return;
    }
  }

  obj[0x90f] = static_cast<std::uint8_t>(obj[0x90f] & 0xFE);
}
