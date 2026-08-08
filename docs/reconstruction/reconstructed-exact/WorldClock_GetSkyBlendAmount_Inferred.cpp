// =============================================================================
// WorldClock_GetSkyBlendAmount_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00553cd0
// Address:   0x00553cd0–0x00553cd6 inclusive (7 B; autoassault.exe base 0x400000)
// System:    environment / world clock / sky blend
// Generated: 2026-08-04 WQ9F-J OWN dual A/B seal
// Exactness: Behavior-preserving rewrite of live decompile + sealed bytes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Supersedes: FUN_00553cd0.cpp scaffold.
// Dual: reviews/A|B_aa_00553cd0_WorldClock_GetSkyBlendAmount_Inferred.md
// Sibling: WorldClock_GetQuarterPhase01_Inferred (aa_00553dd0) — same host.
// =============================================================================
//
// PURPOSE:
//   Load the stored float at clock+0x15c onto x87 ST0.
//   Sole static consumer FUN_004912c0 uses the value as sky material
//   fBlendAmount (FUN_00490af0 / SkyBox* family).
//
// ABI: ECX = clock; bare ret (C3); result on x87 ST0.
// Bytes: D9 81 5C 01 00 00 C3   ; fld dword ptr [ecx+0x15c] ; ret
// =============================================================================

float __fastcall WorldClock_GetSkyBlendAmount_Inferred(void* clock /*ECX*/)
{
  return *reinterpret_cast<float*>(reinterpret_cast<char*>(clock) + 0x15c);
}
