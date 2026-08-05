// =============================================================================
// FUN_00422880  (alias → OleDb_AllocCtxBlock_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00422880
// Address:   0x00422880  (autoassault.exe, image base 0x400000)
// System:    COM / OLE DB ctx gate alloc
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W24-B)
// Exactness: Behavior-preserving rewrite. Prefer named plate.
// =============================================================================

#include <cstdint>
#include <cstddef>

#ifndef E_OUTOFMEMORY
#define E_OUTOFMEMORY ((int32_t)0x8007000E)
#endif

extern "C" void* operator_new__(std::size_t size);

// Retail: __stdcall (block*, count) ret 8; HRESULT in EAX (decompiler void understates).
// SEH frame + tail FUN_004228d1 omitted as CRT/compiler glue.
int32_t FUN_00422880(void** param_1, int32_t param_2)
{
  *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(param_1) + 4) = param_2;
  *param_1 = nullptr;
  *param_1 = operator_new__(static_cast<std::size_t>(param_2) * 8u);
  if (*param_1 != nullptr) {
    return 0;
  }
  return E_OUTOFMEMORY;
}

// Canonical: OleDb_AllocCtxBlock_Inferred
