// =============================================================================
// IgnoreList_EraseEntriesByTfid_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00573ce0
// Address:   0x00573ce0–0x00573d4c exclusive (108 B / 0x6c)
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_00573ce0
// System:    social / ignore list (linear TFID erase + compact)
// Agent:     R13-040 OWN-ONLY dual 2026-08-05 (dual start 2686)
// Exactness: Behavior-preserving rewrite of decompiler + disasm control flow.
// Bit-for-bit vs retail EXE: DEFERRED (Terminal false).
// =============================================================================
//
// PURPOSE
//   Erase every ignore-list entry whose TFID pair matches the stack keys.
//   Walks the pointer vector at this+0x38 / this+0x3c.
//   On match: operator_delete(entry) if non-null, zero the slot, memmove
//   compact the tail, end -= 4, and do NOT advance the cursor (re-scan the
//   element that slid into the current slot → multi-match capable).
//   Always returns 0.
//
//   Role sealed by sole caller:
//     FUN_0080eeb0 remove-from-ignore residual —
//       after FindEntryByTfid + English
//         "has been removed from your ignore list"
//       calls this mutator with peer TFID, then refreshes CDlgTabsSocial.
//
// ABI
//   __thiscall(this = list host,
//              int unused1, int unused2,   // cleaned but unread by body
//              int tfid_lo, int tfid_hi)
//     → 0; RET 0x10
//
// DO NOT MERGE with:
//   IgnoreList_FindEntryByTfid_Inferred (0x00573a90) — read-only; RET 0x8
//   FUN_00573d50 — same erase plate on vector +0x28/+0x2c
//   FUN_005739d0 — friends TFID find on +0x8
// =============================================================================

#include <cstdint>
#include <cstring>

// Entry: TFID pair at +0x08/+0x0c; heap-allocated; freed on match.
// Host:  vector begin T** at +0x38, end T** at +0x3c (MSVC-style pointer vector).
// Common host instance family: multi-list object (friends @+0x8; ignore @+0x38).

// MSVC CRT symbols resolved by the image (not reimplemented here).
extern "C" void __cdecl operator_delete(void* p);
// memmove via IAT DAT_009c652c in the original image.

int __thiscall IgnoreList_EraseEntriesByTfid_Inferred(
    void* self,
    int /*unused1*/,
    int /*unused2*/,
    int tfid_lo,
    int tfid_hi)
{
  auto* host = reinterpret_cast<std::uint8_t*>(self);
  auto** cur = *reinterpret_cast<void***>(host + 0x38);
  auto** end = *reinterpret_cast<void***>(host + 0x3c);

  if (cur == end) {
    return 0;
  }

  auto** next = cur + 1;
  do {
    void* entry = *cur;
    auto* e = reinterpret_cast<std::uint8_t*>(entry);

    if (*reinterpret_cast<int*>(e + 0x08) == tfid_lo &&
        *reinterpret_cast<int*>(e + 0x0c) == tfid_hi) {
      if (entry != nullptr) {
        operator_delete(entry);  // cdecl; returns (decompiler false-noreturn)
      }
      *cur = nullptr;

      // (end - next) in elements, then * 4 → byte count for memmove
      end = *reinterpret_cast<void***>(host + 0x3c);
      const auto byte_count =
          static_cast<std::size_t>(
              (reinterpret_cast<std::uintptr_t>(end) -
               reinterpret_cast<std::uintptr_t>(next)));
      std::memmove(cur, next, byte_count);
      *reinterpret_cast<std::uintptr_t*>(host + 0x3c) -= 4;
      // no cur/next advance — re-examine current slot after compact
    } else {
      cur = cur + 1;
      next = next + 1;
    }

    end = *reinterpret_cast<void***>(host + 0x3c);
  } while (cur != end);

  return 0;
}

// Ghidra twin symbol (scaffold keep):
//   int __thiscall FUN_00573ce0(void* self, int, int, int tfid_lo, int tfid_hi);
