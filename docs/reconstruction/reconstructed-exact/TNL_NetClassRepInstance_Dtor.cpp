// =============================================================================
// TNL_NetClassRepInstance_Dtor
// -----------------------------------------------------------------------------
// Stable ID: aa_005a2470
// Address:   0x005a2470  (autoassault.exe, image base 0x400000)
// Body:      0x005a2470–0x005a248e exclusive (30 B); CC pad; next @ 0x005a2490
// System:    tnl / NetClassRep
// Generated: 2026-07-29 W26-R dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B: accept (2026-07-29).
// Ghidra:    FUN_005a2470
// =============================================================================
//
// PURPOSE:
//   In-place destructor for a TNL NetClassRepInstance-style ClassRep:
//     install NetClassRepInstance vtbl → free owned className at +0x20 →
//     restore base ClassRep vtbl (0x009d7af4).
//   Does NOT operator_delete the storage (see scalar deleting FUN_005a2730).
//   Does NOT unlink from global ClassList (DAT_00d179a4).
//
// ABI: MSVC __thiscall
//   ECX = this
//   plain ret
//
// CALLEES: free (IAT 0x009c6524)
// GLOBALS: PTR_FUN_009d7bf4 (NetClassRepInstance vtbl),
//          PTR_LAB_009d7af4 (base ClassRep vtbl)
// SIBLING: TNL_NetClassRepInstance_Ctor @ 0x005a2410
// CALLERS: atexit FUN_009c3de0 (static DAT_00b04f40);
//          scalar deleting dtor FUN_005a2730
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern void* PTR_FUN_009d7bf4; // NetClassRepInstance vtbl @ 0x009d7bf4
extern void* PTR_LAB_009d7af4; // base ClassRep vtbl @ 0x009d7af4

struct NetClassRepInstance {
  void* vtbl;                 // +0x00
  uint32_t classGroupMask;    // +0x04
  uint32_t classVersion;      // +0x08
  uint32_t classType;         // +0x0C
  uint32_t classId[4];        // +0x10 .. +0x1C
  char* className;            // +0x20  (owned heap string from ctor strdup)
  uint32_t _pad_base[4];      // +0x24 .. +0x30
  NetClassRepInstance* next;  // +0x34  ClassList link (not touched here)
};

void __fastcall TNL_NetClassRepInstance_Dtor(NetClassRepInstance* self)
{
  char* name = self->className;
  self->vtbl = &PTR_FUN_009d7bf4;
  free(name);
  self->vtbl = &PTR_LAB_009d7af4;
}
