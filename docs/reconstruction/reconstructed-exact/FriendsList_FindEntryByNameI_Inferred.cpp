// =============================================================================
// FriendsList_FindEntryByNameI_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00573a30
// Address:   0x00573a30–0x00573a8b exclusive (91 B / 0x5B)
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_00573a30
// System:    social / friends list (linear name find)
// Agent:     R11-005 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler + disasm control flow.
// Bit-for-bit vs retail EXE: DEFERRED (Terminal false).
// =============================================================================
//
// PURPOSE
//   Case-insensitive linear search over a pointer vector at this+0x8 / this+0xc.
//   Compares each entry's C-string at entry+0x1a via CRT _stricmp.
//   Returns the first matching entry pointer, or null on miss / empty vector.
//
//   Role sealed by callers:
//     - UI_InteractionMenu_AddFriendsToggle (DAT_00d1da2c membership)
//     - /friend command path (already-friend vs add)
//     - Remove-from-Friends button 0x1117a (lookup → TFID at entry+8/+0xc)
//
// ABI
//   __thiscall(this = list host, char *name) → entry* | 0; RET 0x4
//
// DO NOT MERGE with NameTable_FindEntryByNameI_Inferred (0x00573af0):
//   that twin walks this+0x38/+0x3c and compares entry+0x10.
// =============================================================================

#include <cstdint>
#include <cstring>  // _stricmp on MSVC CRT

// Entry: name C-string at +0x1a; TFID-like pair at +0x08/+0x0c (caller-consumed).
// Host:  vector begin T** at +0x08, end T** at +0x0c (MSVC-style pointer vector).

extern "C" int __cdecl _stricmp(const char* a, const char* b);

void* __thiscall FriendsList_FindEntryByNameI_Inferred(void* self, char* name)
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
    char* entry_name = reinterpret_cast<char*>(
        reinterpret_cast<std::uint8_t*>(entry) + 0x1a);

    if (_stricmp(entry_name, name) == 0) {
      return entry;
    }
    index = index + 1;
  }

  return nullptr;
}

// Ghidra twin symbol (scaffold keep):
//   void* __thiscall FUN_00573a30(void* self, char* name);
