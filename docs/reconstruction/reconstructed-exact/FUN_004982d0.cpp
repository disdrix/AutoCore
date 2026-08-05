// =============================================================================
// FUN_004982d0  (twin of ListTrackedCtx_ClearResetCapacity10_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004982d0
// Address:   0x004982d0–0x004982e2 inclusive (19 B / 0x13)
// Module:    autoassault.exe (image base 0x400000)
// Wave:      W37-AD 2026-08-04
// Exactness: Behavior-preserving; body hex 568bf1e8a8f9ffffc7460c0a000000b0015ec3
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" std::uint8_t __thiscall FUN_00497c80(std::uint8_t* self);

// Retail: PUSH ESI; MOV ESI,ECX; CALL FUN_00497c80;
//         MOV dword [ESI+0xC],10; MOV AL,1; POP ESI; RET
extern "C" std::uint8_t __thiscall FUN_004982d0(std::uint8_t* self /*ECX*/)
{
  FUN_00497c80(self);
  *reinterpret_cast<std::uint32_t*>(self + 0x0C) = 10;
  return 1;
}
