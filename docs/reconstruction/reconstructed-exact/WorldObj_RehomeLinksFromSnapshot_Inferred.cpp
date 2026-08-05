// =============================================================================
// WorldObj_RehomeLinksFromSnapshot_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00560f70
// Address:   0x00560f70  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00560f70
// Body:      0x00560f70–0x00561312 (930 B); ret 8
// System:    world-object / phys rehome after mode exit
// Dual:      2026-07-29 W27-O
// =============================================================================
//
// ABI: __thiscall  ECX = Manager*; stack = WorldObj*, Snapshot*{ptr*,count}; void; ret 8
//
// Stages:
//   0. Guarded reattach: flag +0x12c, FUN_0055e760, FUN_0055fa40 (same as 00560f30)
//   1. Snapshot children → host (obj+0x44) list +0x58; child+0x14 = host
//   2. Link array obj+0x88/+0x8c → open-coded PhysSim_PushBodyPair on manager+0x20
//   3. Action array obj+0x94/+0x98 → match host list, 006292a0 + 00628f10,
//      action+0x10 = host; neighbor pairs via action vtbl+0x18 + arena DAT_00b05060
//
// Caller: FUN_005d4440 when old HBAI mode code == 7 (snapshot from FUN_005617c0).
// Residual: unaff_EBX second virtual after child vtbl+0x28 — decompiler artifact.
//
// Full line-faithful body: see FUN_00560f70.cpp (authoritative CF twin).

// Forward declaration only — keep named twin thin; implement via FUN twin.
void __thiscall WorldObj_RehomeLinksFromSnapshot_Inferred(int manager, int obj, int *snapshot);
