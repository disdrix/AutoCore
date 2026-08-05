// =============================================================================
// FUN_0096ef70  (scaffold twin of RefCountedPtr_DefaultCtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0096ef70
// Address:   0x0096ef70–0x0096ef78  (autoassault.exe, image base 0x400000)
// Dual A/B:  2026-07-29 W25-N — prefer RefCountedPtr_DefaultCtor_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// =============================================================================

#include <cstdint>

// Ghidra surface name preserved for xref continuity.
// Retail also returns this in EAX (mov eax,ecx before store).
void __fastcall FUN_0096ef70(uint32_t* param_1 /*ECX*/)
{
  *param_1 = 0;
}
