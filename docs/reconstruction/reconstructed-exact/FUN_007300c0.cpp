// =============================================================================
// FUN_007300c0  (clean twin of PalToolNoMap_Host0x34_MeshBuildUpload_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_007300c0
// Address:   0x007300c0  (autoassault.exe, image base 0x400000)
// Body:      0x007300c0–0x007308b7 (2040 B / 0x7F8)
// System:    palantir graphics / PalTool material + mesh upload
// Generated: 2026-07-29 W36-J dual seal
// Exactness: Structural port map of decompiler CF (not full SEH expansion).
// Named twin: PalToolNoMap_Host0x34_MeshBuildUpload_Inferred.cpp
// =============================================================================
//
// AUTHORITATIVE CONTROL FLOW: raw decompile in
//   docs/reconstruction/raw/aa_007300c0_FUN_007300c0.md
//
// Sealed surface:
//   stdcall host*; RET 4; SEH LAB_009b1eb6
//   material @ host+0x24 (PalToolMaterialNoMap.fx + Mat*)
//   host+0x20 = vert meta; host+0x1c = index meta; host+0x2c = 4
//   VB path FUN_00414bc0(0x152) + Lock vtbl+0x2c flag 0x800
//   IB path FUN_0044b9c0 / FUN_0044ba80 / FUN_0044bbc0(..., host+0x14, 0)
//   return 0 success / 0xFFFFFFFF failure
//
// Prefer named twin for documented stage map. Do not trust decompiler
// piRam00000010 absolute aliases on the second geometry block.

#include <cstdint>

extern "C" uint32_t FUN_007300c0(void *host /* stack param_1 */);

// Implementation lives with the named clean (structural stages).
// This twin documents the Ghidra symbol and sealed ABI only.
