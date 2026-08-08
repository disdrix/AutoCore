// =============================================================================
// FUN_005739d0  (scaffold twin of FriendsList_FindEntryByTfid_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005739d0
// Address:   0x005739d0–0x00573a28 exclusive (88 B / 0x58)
// Module:    autoassault.exe (image base 0x400000)
// System:    social / friends list
// Agent:     R13-039 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED (Terminal false).
// Named clean: reconstructed-exact/FriendsList_FindEntryByTfid_Inferred.cpp
// =============================================================================

#include <cstdint>

// PURPOSE: Friends-list exact TFID-pair linear find (vector @+0x8/+0xc).
// ABI: __thiscall; stack tfid_lo, tfid_hi; RET 0x8; EAX = entry* | 0.

void* __thiscall FUN_005739d0(void* param_1, int param_2, int param_3)
{
  auto* host = reinterpret_cast<std::uint8_t*>(param_1);
  int iVar2 = 0;

  for (;;) {
    auto* begin_ptr = *reinterpret_cast<std::uint8_t**>(host + 8);
    int iVar1;
    if (begin_ptr == nullptr) {
      iVar1 = 0;
    } else {
      auto* end_ptr = *reinterpret_cast<std::uint8_t**>(host + 0xc);
      iVar1 = static_cast<int>(
          (reinterpret_cast<std::uintptr_t>(end_ptr) -
           reinterpret_cast<std::uintptr_t>(begin_ptr)) >> 2);
    }

    if (iVar1 <= iVar2) {
      break;
    }

    auto** begin = reinterpret_cast<void**>(
        *reinterpret_cast<std::uintptr_t*>(host + 8));
    void* entry = begin[iVar2];
    auto* e = reinterpret_cast<std::uint8_t*>(entry);

    if (*reinterpret_cast<int*>(e + 8) == param_2 &&
        *reinterpret_cast<int*>(e + 0xc) == param_3) {
      return entry;
    }

    iVar2 = iVar2 + 1;
  }

  return nullptr;
}
