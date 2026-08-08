// INDUSTRIAL / SCAFFOLD NOTE:
// This clean retains limited decompiler tokens (undefined4) pending full rewrite.
// Behavior is dual-sealed; product English and full CF rewrite residual.
// Wave: pre-existing industrial unit (not WQ9J). Not a fresh Ghidra dump.
// =============================================================================
// Ctx_ClearListTrackedOwnedAtScaledXY_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00497a30
// Address:   0x00497a30â€“0x00497ab8  (137 B / 0x89, autoassault.exe base 0x400000)
// System:    ctx â†’ host grid single-cell owned ListTrackedObj* @ +0x24
// Generated: 2026-07-29 W31-D dual A/B (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex + floats.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00497a30
// =============================================================================
//
// PURPOSE:
//   Resolve host via *( *(ctx+0xC4) + 0xE898 ), map stack (xUnits,yUnits) into
//   a grid index using div = trunc(DAT_00aefa50 * DAT_00a14000), then destroy
//   and free owned ListTrackedObj* at that cell's +0x24 and null the slot.
//
// ABI:
//   __thiscall; ECX = ctx; stack uint xUnits, uint yUnits; ret 8; returns 1.
//
// SCALE GLOBALS (read_memory):
//   DAT_00aefa50 â€” runtime scale float (image 32.0f; rebuild may set 64/32)
//   DAT_00a14000 â€” 0.0625f
//   product â†’ 2.0 (scale 32) or 4.0 (scale 64)
//
// NOTE:
//   No static xrefs (orphan). Ghidra ROUND() â‰ˆ FPU fistp with RC=chop.
// =============================================================================

#include <cstdint>

// Image globals (addresses sealed; values runtime-mutable for scale).
extern "C" float DAT_00aefa50;  // 0x00aefa50
extern "C" float DAT_00a14000;  // 0x00a14000 â€” 0.0625f in image

extern "C" void __thiscall ListTrackedObj_CompleteDtor(void* self);  // FUN_004be2a0
extern "C" void operator_delete(void* p);

// Machine: undefined4 __thiscall FUN_00497a30(int ctx, uint x, uint y)
extern "C" uint32_t __thiscall Ctx_ClearListTrackedOwnedAtScaledXY_Inferred(
    void* ctx, uint32_t xUnits, uint32_t yUnits)
{
  auto* c = reinterpret_cast<uint8_t*>(ctx);
  void* mid = *reinterpret_cast<void**>(c + 0xC4);
  auto* host = *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(mid) + 0xE898);

  auto* arr = *reinterpret_cast<uint8_t**>(host + 0x28);
  int dimX = *reinterpret_cast<int*>(host + 4);

  // FPU path: load scale, fmul 0.0625, force RC=chop, fistp â†’ int divisor.
  // Decompiler surfaces as (uint)(int)ROUND(DAT_00aefa50 * DAT_00a14000).
  float cell = DAT_00aefa50 * DAT_00a14000;
  uint32_t div = static_cast<uint32_t>(static_cast<int>(cell));  // chop toward zero

  int index = static_cast<int>(yUnits / div) * dimX
              + static_cast<int>(xUnits / div);
  auto* elem = arr + index * 0x28;
  void* owned = *reinterpret_cast<void**>(elem + 0x24);
  if (owned != nullptr) {
    ListTrackedObj_CompleteDtor(owned);
    operator_delete(owned);
  }
  *reinterpret_cast<void**>(elem + 0x24) = nullptr;
  return 1;
}

