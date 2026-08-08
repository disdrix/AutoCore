// =============================================================================
// FUN_0040b3b0  (scaffold twin → StdTree_ConstructEmpty_Isnil19_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040b3b0
// Address:   0x0040b3b0–0x0040b40a exclusive (90 B / 0x5A)
// System:    MSVC std::_Tree empty construct — isnil@+0x19 / node 0x1c
// Generated: 2026-08-05 R13-017 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical: StdTree_ConstructEmpty_Isnil19_Inferred.cpp
// =============================================================================

#include <cstdint>

// Forward to named clean plate (identical body).
extern "C" void* __stdcall StdTree_ConstructEmpty_Isnil19_Inferred(void* shell);

extern "C" void* __stdcall FUN_0040b3b0(void* shell)
{
  return StdTree_ConstructEmpty_Isnil19_Inferred(shell);
}

/*
 * Sealed CF (assembly):
 *   SEH setup (LAB_009bda98)
 *   ESI = [ESP+0x14]  // shell*
 *   EAX = CALL FUN_0040bfc0  // residual buyhead 0x1c
 *   [ESI+4] = EAX;  byte [EAX+0x19] = 1
 *   head L/P/R = self; [ESI+8] = 0
 *   EAX = ESI; ADD ESP,0xC; RET 4
 *
 * Reject: thiscall, void, isnil29/31 families, freelist, product MissionTracker English as unit name.
 */
