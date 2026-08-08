// =============================================================================
// FUN_00573ce0  (Ghidra twin of IgnoreList_EraseEntriesByTfid_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00573ce0
// Address:   0x00573ce0–0x00573d4c exclusive (108 B / 0x6c)
// Module:    autoassault.exe (image base 0x400000)
// Canonical: IgnoreList_EraseEntriesByTfid_Inferred
// Agent:     R13-040 OWN-ONLY dual 2026-08-05 (dual start 2686)
// Exactness: Behavior-preserving; ABI sealed via disasm + read_memory.
// Bit-for-bit vs retail EXE: DEFERRED (Terminal false).
// =============================================================================

#include <cstdint>
#include <cstring>

extern "C" void __cdecl operator_delete(void* p);

// __thiscall; RET 0x10; always returns 0
// Stack: unused1, unused2, tfid_lo, tfid_hi (body reads only last two)
int __thiscall FUN_00573ce0(
    void* param_1,
    int /*param_2*/,
    int /*param_3*/,
    int param_4,
    int param_5)
{
  auto* host = reinterpret_cast<std::uint8_t*>(param_1);
  auto** dst = *reinterpret_cast<void***>(host + 0x38);

  if (dst != *reinterpret_cast<void***>(host + 0x3c)) {
    auto** src = dst + 1;
    do {
      void* entry = *dst;
      auto* e = reinterpret_cast<std::uint8_t*>(entry);

      if (*reinterpret_cast<int*>(e + 0x08) == param_4 &&
          *reinterpret_cast<int*>(e + 0x0c) == param_5) {
        if (entry != nullptr) {
          operator_delete(entry);
        }
        *dst = nullptr;
        auto* endp = *reinterpret_cast<std::uint8_t**>(host + 0x3c);
        const auto n =
            static_cast<std::size_t>(
                (reinterpret_cast<std::uintptr_t>(endp) -
                 reinterpret_cast<std::uintptr_t>(src)));
        std::memmove(dst, src, n);
        *reinterpret_cast<std::uintptr_t*>(host + 0x3c) -= 4;
      } else {
        dst = dst + 1;
        src = src + 1;
      }
    } while (dst != *reinterpret_cast<void***>(host + 0x3c));
  }

  return 0;
}
