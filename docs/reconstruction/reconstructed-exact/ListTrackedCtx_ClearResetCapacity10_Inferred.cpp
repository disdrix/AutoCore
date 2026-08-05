// =============================================================================
// ListTrackedCtx_ClearResetCapacity10_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004982d0
// Address:   0x004982d0–0x004982e2 inclusive (19 B / 0x13)
// Module:    autoassault.exe (image base 0x400000)
// System:    Palantir env child / list-tracked ctx (object size 0xC8)
// Wave:      W37-AD 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Thin thiscall wrapper: clear-destroy-reset the ListTrackedCtx (W33-R
//   FUN_00497c80), then set capacity field +0xC to the constant 10, return 1.
//
// RELATED:
//   Clear body: ListTrackedCtx_ClearDestroyAndReset_Inferred (0x00497c80, W33-R)
//   Ctor:       ListTrackedCtx_Ctor_Inferred (0x00497920, W32-P)
//   Sibling:    FUN_004982f0 (clear + capacity 10 + recompute dims)
//   Sole caller: FUN_0048fc90 @ 0x0048fe6d with ECX = env+0x100
//
// ABI: __thiscall; ECX=self; bare RET; AL=1.
// =============================================================================

#include <cstdint>

extern "C" std::uint8_t __thiscall ListTrackedCtx_ClearDestroyAndReset_Inferred(
    std::uint8_t* self);

// Ghidra: FUN_004982d0
extern "C" std::uint8_t __thiscall ListTrackedCtx_ClearResetCapacity10_Inferred(
    std::uint8_t* self)
{
  ListTrackedCtx_ClearDestroyAndReset_Inferred(self);
  *reinterpret_cast<std::uint32_t*>(self + 0x0C) = 10;
  return 1;
}

// Ghidra twin name
extern "C" std::uint8_t __thiscall FUN_004982d0(std::uint8_t* self)
{
  return ListTrackedCtx_ClearResetCapacity10_Inferred(self);
}
