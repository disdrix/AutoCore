// =============================================================================
// Mem_ZeroSixDwords_Ecx_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00416370
// Address:   0x00416370  (autoassault.exe, image base 0x400000)
// Body:      0x00416370–0x00416388 exclusive (24 B / 0x18); ret 0; pad CC
// System:    util / memory (six-dword / 0x18-byte zero)
// Generated: 2026-08-04 WQ9I-I dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-04).
// Ghidra:    FUN_00416370
// =============================================================================
//
// PURPOSE:
//   Zero six consecutive dwords at the destination pointer (0x18 bytes).
//   On Win32 x86 this matches sizeof(CRITICAL_SECTION). Sole call site
//   pre-zeros the CS-shaped field at outer-object +0x18 before
//   CriticalSection_Initialize_SehToHresult_Ecx_Inferred (0x00416390).
//
// ABI (sealed from bytes + caller site):
//   ECX  = uint32_t* dest (6 dwords)
//   EAX  = dest on return (MOV EAX,ECX preserved; decompiler shows void)
//   ret  = plain C3; no stack formals
//
// CALLEES: none (leaf)
//
// CALLERS (1):
//   FUN_00489d95 @ 0x00489d9b — MOV ESI,ECX; LEA ECX,[ESI+0x18]; CALL
//
// PAIR:
//   aa_00416390 CriticalSection_Initialize_SehToHresult_Ecx_Inferred
// =============================================================================

#include <cstdint>

// Register contract: dest in ECX; returns dest in EAX; ret 0.
extern "C" uint32_t* Mem_ZeroSixDwords_Ecx_Inferred(uint32_t* dest /*ECX*/)
{
  dest[0] = 0;
  dest[1] = 0;
  dest[2] = 0;
  dest[3] = 0;
  dest[4] = 0;
  dest[5] = 0;
  return dest;
}

extern "C" uint32_t* FUN_00416370(uint32_t* dest /*ECX*/)
{
  return Mem_ZeroSixDwords_Ecx_Inferred(dest);
}
