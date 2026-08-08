// =============================================================================
// FUN_005a4590  (scaffold twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_005a4590
// Address:   0x005a4590  (autoassault.exe, image base 0x400000)
// Body:      0x005a4590 – 0x005a4862 inclusive (723 B / 0x2D3)
// System:    skills-abilities / MSVC std::_Tree erase isnil@+0x21
// Generated: 2026-08-05 R12-032 dual seal
// Canonical: StdTree_EraseAndRebalance_Isnil21_Inferred
// Exactness: Behavior-preserving rewrite; see named clean for full body.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   Single-node erase + RB rebalance for isnil@+0x21 trees (node 0x24).
//   thiscall; ECX=map; stack outIt + node; ret 8.
//   Full reconstruction: StdTree_EraseAndRebalance_Isnil21_Inferred.cpp
//
// CALLERS (1): FUN_005a4c30
// CALLEES: FUN_004e12c0, FUN_004cb2c0, FUN_00421a60, FUN_0050e9f0, FUN_005a27f0,
//          operator_delete, throw path ("invalid map/set<T> iterator")
// =============================================================================

// Implementation lives in StdTree_EraseAndRebalance_Isnil21_Inferred.cpp
// (provides both StdTree_EraseAndRebalance_Isnil21_Inferred and FUN_005a4590).
