// =============================================================================
// FUN_00746400  (twin of StdVector_FindOrPushBackDword_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00746400
// Address:   0x00746400  (autoassault.exe, image base 0x400000)
// System:    container / std::vector-like dword registry
// Generated: 2026-08-04 W37-V dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher).
// =============================================================================

// See StdVector_FindOrPushBackDword_Inferred.cpp for named plate.
// Live decompile CF preserved; types upgraded from undefined4.

#include <cstdint>

struct VecDword {
  void *unused_or_vtbl;
  uint32_t *begin;
  uint32_t *end;
  uint32_t *capacityEnd;
};

extern "C" void FUN_004406e0(void); // customcc EAX=vec, ESI=&value

extern "C" uint32_t __thiscall FUN_00746400(VecDword *param_1 /*ECX*/, uint32_t param_2)
{
  uint32_t *piVar1 = param_1->begin;
  for (;;) {
    if (piVar1 == param_1->end) {
LAB_0074641c:
      // EAX=param_1, ESI=&param_2 set by prologue/lea (bytes)
      FUN_004406e0();
      return 0;
    }
    if (*piVar1 == param_2) {
      if (piVar1 != param_1->end)
        return 1;
      goto LAB_0074641c;
    }
    piVar1 = piVar1 + 1;
  }
}
