// =============================================================================
// StdVector_FindOrPushBackDword_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00746400
// Address:   0x00746400  (autoassault.exe, image base 0x400000)
// System:    container / std::vector-like dword registry
// Generated: 2026-08-04 W37-V dual seal (from live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher).
// =============================================================================

// PURPOSE: Linear-scan a dword vector [begin+4, end+8) for `value`.
//   Hit  → return 1 (already present).
//   Miss → push via StdVector_PushBackDword (FUN_004406e0) → return 0.
// ABI: __thiscall ECX=vector host; one stack dword; RET 4.
// Common host: DAT_00d1f620 (phase-token / bootstrap registry).

#include <cstdint>

struct VecDword {
  void *unused_or_vtbl; // +0x00 — not touched here
  uint32_t *begin;      // +0x04
  uint32_t *end;        // +0x08
  uint32_t *capacityEnd;// +0x0c — used only inside push callee
};

// FUN_004406e0 — customcc EAX=vec, ESI=&value (not owned)
extern "C" void StdVector_PushBackDword_Inferred(VecDword * /*EAX*/, const uint32_t * /*ESI*/);

extern "C" uint32_t __thiscall StdVector_FindOrPushBackDword_Inferred(
    VecDword *vec /*ECX*/,
    uint32_t value)
{
  uint32_t *cursor = vec->begin;
  uint32_t *end = vec->end;

  for (;;) {
    if (cursor == end) {
append:
      // Retail: EAX still holds `vec` from prologue MOV EAX,ECX;
      // LEA ESI, &value before call.
      StdVector_PushBackDword_Inferred(vec, &value);
      return 0;
    }
    if (*cursor == value) {
      if (cursor != end)
        return 1;
      goto append;
    }
    ++cursor;
  }
}

// Ghidra twin symbol
extern "C" uint32_t __thiscall FUN_00746400(VecDword *vec, uint32_t value)
{
  return StdVector_FindOrPushBackDword_Inferred(vec, value);
}
