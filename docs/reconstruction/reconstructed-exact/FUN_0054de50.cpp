// =============================================================================
// FUN_0054de50 — Ghidra symbol alias
// -----------------------------------------------------------------------------
// Stable ID: aa_0054de50
// Address:   0x0054de50  (autoassault.exe, image base 0x400000)
// Body:      0x0054de50 – 0x0054e03a
// System:    skills-abilities
// Dual:      2026-07-29 W20-B
// Named:     SkillElementTypeMap_TreeInsertAndRebalance.cpp  (authoritative clean CF)
// =============================================================================
//
// PURPOSE: Always-insert + red-black rebalance for skill-element type map
//          (node size 0x18). Not insert-or-find.
//
// ABI (byte-sealed):
//   void __thiscall FUN_0054de50(
//       MapShell* map,              // ECX — head@+4, size@+8
//       MapNode_IntPtr** outIt,    // *outIt = new node
//       char addLeft,               // 1 left / 0 right of where
//       MapNode_IntPtr* where,
//       const IntPtrPair* value);   // 2 dwords → node+0x0C
//   RET 0x10
//
// THROW: size > 0x1ffffffd → "map/set<T> too long" @ 0x00a1530c
// NODE:  new(0x18) via FUN_006173a0; color@+0x14 (0=red); isnil@+0x15
// CALLER: SkillElementTypeMap_InsertOrFind (0x0054eb20) ×2
// =============================================================================

// Full control-flow reconstruction lives in:
//   SkillElementTypeMap_TreeInsertAndRebalance.cpp
// This file is the stable FUN_* path for tooling that keys on Ghidra names.
