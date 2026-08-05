// =============================================================================
// FUN_0052dac0  —  Reward region lookup / insert helper
// -----------------------------------------------------------------------------
// Stable ID: aa_0052dac0
// Address:   0x0052dac0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-29 seal (dual A/B + three-rep decompile + read_memory)
// Exactness: Behavior-preserving rewrite. Map base corrected from assembly
//            (decompiler wrongly uses whole `this` for FUN_00538a40).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   On container map at this+0x508 (sentinel this+0x50c), find entry by key.
//   Return pointer to value blob at node+0x18 ("reward region"), or null if
//   missing and createIfMissing==0. If missing and createIfMissing!=0, insert
//   a mostly-0xFFFFFFFF payload via FUN_0052c700 and return the new region*.
//
// ABI (asm-sealed): __thiscall, 2 stack args, ret 8.
//   ECX = container*
//   [esp+4] = key (uint32)
//   [esp+8] = createIfMissing (char)
//   EAX = region* (node+0x18) or 0
//
// Callees:
//   FUN_00538a40 — tree find (this = map @ container+0x508)
//   FUN_0052c700 — insert/overwrite 12 dwords @ node+0x18; returns node+0x18
//
// Callers:
//   Client_ShowNpcMissionDialogUI @ 0x00943a85  (create=0, ECX=char*)
//   FUN_004d08c0 @ 0x004d0912                     (create=1)
//   FUN_004d5c10 @ 0x004d5d20 / 0x004d5e90 / 0x004d63f6 (create=1)

#include <cstdint>

// Map find: writes *outNode = node* (or end). Decompiler types approximate.
extern "C" void __thiscall FUN_00538a40(void *map, int *outNode, std::uint32_t *key);

// Insert-or-overwrite value; returns node+0x18 (decompiler may show void — wrong).
extern "C" int __thiscall FUN_0052c700(void *container, std::uint32_t key, int *payload12dwords);

// -----------------------------------------------------------------------------

int __thiscall FUN_0052dac0(void *self, std::uint32_t key, char createIfMissing)
{
  int node_holder[12];
  std::uint8_t trailing_byte;
  int region;

  // Assembly: lea ecx, [this+0x508] before call — not whole this.
  FUN_00538a40(
      reinterpret_cast<void *>(reinterpret_cast<std::uint8_t *>(self) + 0x508),
      node_holder,
      &key);

  if (node_holder[0] != *reinterpret_cast<int *>(
          reinterpret_cast<std::uint8_t *>(self) + 0x50c)) {
    return node_holder[0] + 0x18;
  }

  if (createIfMissing == '\0') {
    return 0;
  }

  // Payload window for FUN_0052c700's 12-dword copy starting at node_holder+1.
  node_holder[9]  = -1;
  node_holder[10] = -1;
  node_holder[11] = -1;
  node_holder[1]  = -1;
  node_holder[2]  = -1;
  node_holder[3]  = -1;
  node_holder[4]  = -1;
  node_holder[5]  = -1;
  node_holder[6]  = -1;
  node_holder[7]  = -1;
  node_holder[8]  = -1;
  trailing_byte   = 0;

  region = FUN_0052c700(self, key, node_holder + 1);
  return region;
}
