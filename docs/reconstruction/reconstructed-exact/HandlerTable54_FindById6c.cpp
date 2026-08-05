// =============================================================================
// HandlerTable54_FindById6c
// -----------------------------------------------------------------------------
// Stable ID: aa_00508c00
// Address:   0x00508c00  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00508c00
// System:    status/hook handler table family (slot +0x54)
// Generated: 2026-07-29 W20-R dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Linear lookup: scan registry->table_at_0x54[0 .. DAT_00d02988) for the
//   first entry whose id field at entry+0x6c equals the requested id.
//   Return that entry pointer, or null.
//
// ABI:
//   __thiscall  ECX = registry*
//   stack0      int32 id
//   ret 4
//
// FAMILY (same CF, different table / count):
//   FUN_00508ac0  +0x44 / DAT_00d02974
//   FUN_00508bb0  +0x50 / DAT_00d02980
//   FUN_00508c00  +0x54 / DAT_00d02988   <-- this unit
//   FUN_00508c50  +0x58 / DAT_00d02984
//
// CALLERS (selected):
//   Vehicle_ApplyItemStatusHooksOnEquip (0x004fe380) — subtype 0xb handlers
//   CVOGLootGenerator_GetTypeFromIDPrefix family, FUN_00513580, …
// =============================================================================

#include <stdint.h>

// Runtime-filled table length (BSS zero in static image).
extern int32_t DAT_00d02988;

// Entry layout (partial): id at +0x6c only sealed here.
struct HandlerTableEntry {
  // ...
  // int32_t id; // @ +0x6c
};

struct HandlerTableRegistry {
  // ...
  // HandlerTableEntry **table54; // @ +0x54
};

// INFERRED name — product English unknown.
void *__thiscall HandlerTable54_FindById6c(HandlerTableRegistry *self, int32_t id)
{
  int32_t i;
  HandlerTableEntry **table;

  i = 0;
  if ((id != -1) && (DAT_00d02988 > 0)) {
    table = *(HandlerTableEntry ***)((char *)self + 0x54);
    do {
      if (*(int32_t *)((char *)table[i] + 0x6c) == id) {
        return table[i];
      }
      i = i + 1;
    } while (i < DAT_00d02988);
  }
  return 0;
}
