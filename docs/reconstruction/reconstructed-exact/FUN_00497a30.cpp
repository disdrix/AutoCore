// =============================================================================
// FUN_00497a30  (clean twin — Ghidra plate)
// -----------------------------------------------------------------------------
// Stable ID: aa_00497a30
// Address:   0x00497a30–0x00497ab8  (137 B / 0x89)
// Canonical: Ctx_ClearListTrackedOwnedAtScaledXY_Inferred
// Generated: 2026-07-29 W31-D (twin of named clean)
// =============================================================================

#include <cstdint>

extern "C" float DAT_00aefa50;
extern "C" float DAT_00a14000;

extern "C" void __thiscall FUN_004be2a0(void* self);
extern "C" void operator_delete(void* p);

// Prefer Ctx_ClearListTrackedOwnedAtScaledXY_Inferred.cpp for named port.
extern "C" uint32_t __thiscall FUN_00497a30(
    void* ctx, uint32_t param_2, uint32_t param_3)
{
  auto* c = reinterpret_cast<uint8_t*>(ctx);
  void* mid = *reinterpret_cast<void**>(c + 0xC4);
  auto* host = *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(mid) + 0xE898);

  auto* arr = *reinterpret_cast<uint8_t**>(host + 0x28);
  int dimX = *reinterpret_cast<int*>(host + 4);

  float cell = DAT_00aefa50 * DAT_00a14000;
  uint32_t div = static_cast<uint32_t>(static_cast<int>(cell));

  int index = static_cast<int>(param_3 / div) * dimX
              + static_cast<int>(param_2 / div);
  auto* elem = arr + index * 0x28;
  void* owned = *reinterpret_cast<void**>(elem + 0x24);
  if (owned != nullptr) {
    FUN_004be2a0(owned);
    operator_delete(owned);
  }
  *reinterpret_cast<void**>(elem + 0x24) = nullptr;
  return 1;
}
