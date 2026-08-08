// =============================================================================
// IgnoreList_FindEntryByTfid_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00573a90
// Address:   0x00573a90–0x00573ae7 exclusive (87 B / 0x57)
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_00573a90
// System:    social / ignore list (linear TFID find)
// Agent:     R12-025 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler + disasm control flow.
// Bit-for-bit vs retail EXE: DEFERRED (Terminal false).
// =============================================================================
//
// PURPOSE
//   Exact TFID-pair linear search over a pointer vector at this+0x38 / this+0x3c.
//   Compares each entry's int pair at entry+0x08 / entry+0x0c.
//   Returns the first matching entry pointer, or null on miss / empty vector.
//
//   Role sealed by callers:
//     - remove-from-ignore residual (FUN_0080eeb0) — English
//         "has been removed from your ignore list" using entry+0x10 name
//     - trade request auto-refuse when peer TFID is listed (FUN_0080a170)
//     - convoy invite auto-decline when inviter TFID is listed (FUN_0080fa50)
//     - Client_RecvBroadcast float-text only when speaker TFID is NOT listed
//
// ABI
//   __thiscall(this = list host, int tfid_lo, int tfid_hi) → entry* | 0; RET 0x8
//
// DO NOT MERGE with:
//   FriendsList_FindEntryByNameI_Inferred (0x00573a30) — +0x8 vector, name@+0x1a
//   FUN_005739d0 friends TFID twin — +0x8 vector
//   NameTable_FindEntryByNameI_Inferred (0x00573af0) — same +0x38 vector, name@+0x10
// =============================================================================

#include <cstdint>

// Entry: TFID pair at +0x08/+0x0c; name C-string at +0x10 (caller-consumed).
// Host:  vector begin T** at +0x38, end T** at +0x3c (MSVC-style pointer vector).
// Common host instance: DAT_00d1da2c (friends @+0x8; ignore @+0x38).

void* __thiscall IgnoreList_FindEntryByTfid_Inferred(void* self, int tfid_lo, int tfid_hi)
{
  auto* host = reinterpret_cast<std::uint8_t*>(self);
  int index = 0;

  for (;;) {
    auto* begin_ptr = *reinterpret_cast<std::uint8_t**>(host + 0x38);
    int count;
    if (begin_ptr == nullptr) {
      count = 0;
    } else {
      auto* end_ptr = *reinterpret_cast<std::uint8_t**>(host + 0x3c);
      // (end - begin) in bytes >> 2  == element count (pointer elements)
      count = static_cast<int>(
          (reinterpret_cast<std::uintptr_t>(end_ptr) -
           reinterpret_cast<std::uintptr_t>(begin_ptr)) >> 2);
    }

    if (count <= index) {
      break;
    }

    auto** begin = reinterpret_cast<void**>(
        *reinterpret_cast<std::uintptr_t*>(host + 0x38));
    void* entry = begin[index];
    auto* e = reinterpret_cast<std::uint8_t*>(entry);

    if (*reinterpret_cast<int*>(e + 0x08) == tfid_lo &&
        *reinterpret_cast<int*>(e + 0x0c) == tfid_hi) {
      return entry;
    }
    index = index + 1;
  }

  return nullptr;
}

// Ghidra twin symbol (scaffold keep):
//   void* __thiscall FUN_00573a90(void* self, int tfid_lo, int tfid_hi);
