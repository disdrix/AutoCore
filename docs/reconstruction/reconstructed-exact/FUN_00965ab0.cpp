// =============================================================================
// FUN_00965ab0  — twin of MeshWeightDebugOverlay_Update
// -----------------------------------------------------------------------------
// Stable ID: aa_00965ab0
// Address:   0x00965ab0  (autoassault.exe, image base 0x400000)
// Body:      0x00965ab0 – 0x0096650A exclusive (2650 B / 0xA5A)
// Wave:      W36-N OWN-ONLY dual 2026-07-29
// Exactness: Structural; see MeshWeightDebugOverlay_Update.cpp
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

struct MeshWeightDebugOverlay;

extern "C" void MeshWeightDebugOverlay_Update(MeshWeightDebugOverlay* self);

// Ghidra: void FUN_00965ab0(int param_1)
// Sealed retail ABI: stdcall self* on stack, body uses EDI, RET 4.
extern "C" void FUN_00965ab0(int param_1)
{
  MeshWeightDebugOverlay_Update(reinterpret_cast<MeshWeightDebugOverlay*>(param_1));
}
