// =============================================================================
// FUN_00560a30 — Ghidra symbol alias
// -----------------------------------------------------------------------------
// Stable ID: aa_00560a30
// Address:   0x00560a30  (autoassault.exe, image base 0x400000)
// Body:      0x00560a30 – 0x00560c8b
// System:    physics / island host glue
// Dual:      2026-07-29 W20-B
// Named:     PhysSim_MergeHosts_Inferred.cpp  (authoritative clean CF)
// =============================================================================
//
// PURPOSE: Merge physics host/island src into dest under world ECX; destroy src.
//
// ABI (byte-sealed):
//   Host* __thiscall FUN_00560a30(World* world, Host* dest, Host* src);
//   RET 0x8
//
// CALLER: PhysSim_FlushPendingBodyPairs_Inferred (0x00561320)
// =============================================================================

// Full control-flow reconstruction lives in:
//   PhysSim_MergeHosts_Inferred.cpp
