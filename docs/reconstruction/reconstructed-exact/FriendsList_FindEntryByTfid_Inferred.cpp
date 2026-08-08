// =============================================================================
// FriendsList_FindEntryByTfid_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005739d0
// Address:   0x005739d0–0x00573a28 exclusive (88 B / 0x58)
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_005739d0
// System:    social / friends list (linear TFID find)
// Agent:     R13-039 OWN-ONLY dual 2026-08-05 (dual start 2686)
// Exactness: Behavior-preserving rewrite of decompiler + disasm control flow.
// Bit-for-bit vs retail EXE: DEFERRED (Terminal false).
// =============================================================================
//
// PURPOSE
//   Exact TFID-pair linear search over a pointer vector at this+0x8 / this+0xc.
//   Compares each entry's int pair at entry+0x08 / entry+0x0c.
//   Returns the first matching entry pointer, or null on miss / empty vector.
//
//   Role sealed by callers:
//     - FUN_0080f3b0 presence residual — English "Your friend" using entry+0x1a name;
//       enemy path uses sibling FUN_00573b50 + "Your enemy"
//     - FUN_00574020 / FUN_00574270 insert-if-missing residuals (miss → FUN_005746e0)
//
// ABI
//   __thiscall(this = list host, int tfid_lo, int tfid_hi) → entry* | 0; RET 0x8
//
// DO NOT MERGE with:
//   FriendsList_FindEntryByNameI_Inferred (0x00573a30) — same +0x8 vector, name@+0x1a
//   IgnoreList_FindEntryByTfid_Inferred (0x00573a90) — +0x38 vector, TFID key
//   NameTable_FindEntryByNameI_Inferred (0x00573af0) — +0x38 vector, name@+0x10
// =============================================================================

#include <cstdint>

// Entry: TFID pair at +0x08/+0x0c; name C-string at +0x1a (caller-consumed).
// Host:  vector begin T** at +0x08, end T** at +0x0c (MSVC-style pointer vector).
// Common host instance: DAT_00d1da2c (friends @+0x8; ignore @+0x38).

void* __thiscall FriendsList_FindEntryByTfid_Inferred(void* self, int tfid_lo, int tfid_hi)
{
  auto* host = reinterpret_cast<std::uint8_t*>(self);
  int index = 0;

  for (;;) {
    auto* begin_ptr = *reinterpret_cast<std::uint8_t**>(host + 0x08);
    int count;
    if (begin_ptr == nullptr) {
      count = 0;
    } else {
      auto* end_ptr = *reinterpret_cast<std::uint8_t**>(host + 0x0c);
      // (end - begin) in bytes >> 2  == element count (pointer elements)
      count = static_cast<int>(
          (reinterpret_cast<std::uintptr_t>(end_ptr) -
           reinterpret_cast<std::uintptr_t>(begin_ptr)) >> 2);
    }

    if (count <= index) {
      break;
    }

    auto** begin = reinterpret_cast<void**>(
        *reinterpret_cast<std::uintptr_t*>(host + 0x08));
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
//   void* __thiscall FUN_005739d0(void* self, int tfid_lo, int tfid_hi);
