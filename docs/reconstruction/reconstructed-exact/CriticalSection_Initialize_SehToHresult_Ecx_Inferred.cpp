// =============================================================================
// CriticalSection_Initialize_SehToHresult_Ecx_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00416390
// Address:   0x00416390  (autoassault.exe, image base 0x400000)
// Body:      0x00416390–0x0041640A exclusive (122 B / 0x7A); ret 0; pad CC
// System:    util / Win32 sync (CRITICAL_SECTION init)
// Generated: 2026-08-04 WQ9I-I dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + SEH bytes.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-04).
// Ghidra:    FUN_00416390
// =============================================================================
//
// PURPOSE:
//   SEH-wrapped InitializeCriticalSection(cs) returning HRESULT:
//     success           → 0 (S_OK)
//     STATUS_NO_MEMORY  → 0x8007000E (E_OUTOFMEMORY)
//     any other SEH     → 0x80004005 (E_FAIL)
//
// ABI (sealed from bytes + caller site):
//   ECX  = LPCRITICAL_SECTION
//   EAX  = HRESULT
//   ret  = plain C3; no stack formals
//
// CALLEES:
//   InitializeCriticalSection via IAT dword [0x009c61ec]
//
// CALLERS (1):
//   FUN_00489dc5 @ 0x00489e50 — LEA ECX,[ESI+0x18]; CALL;
//     if (EAX < 0) DAT_00d1f0f0 = 1;
//
// PAIR:
//   aa_00416370 Mem_ZeroSixDwords_Ecx_Inferred (pre-zeros same +0x18 region)
//
// SEH (bytes):
//   scope DAT_00aaa698: { -1, filter=0x004163C4, handler=0x004163D4 }
//   frame handler DAT_00489cb0 (MSVC SEH glue)
//   filter returns 1 (EXCEPTION_EXECUTE_HANDLER)
//   handler: code-0xC0000017 → E_OUTOFMEMORY else E_FAIL
//            (NEG/SBB/AND 0xFFF93FF7/ADD 0x8007000E)
// =============================================================================

#include <cstdint>
#include <windows.h>

// Register contract: cs in ECX; HRESULT in EAX; ret 0.
// Portable stand-in: SEH→HRESULT map matches retail filter/handler math.
extern "C" HRESULT CriticalSection_Initialize_SehToHresult_Ecx_Inferred(
    LPCRITICAL_SECTION cs /*ECX*/)
{
  __try {
    InitializeCriticalSection(cs);
    return static_cast<HRESULT>(0);
  } __except (EXCEPTION_EXECUTE_HANDLER) {
    const DWORD code = GetExceptionCode();
    if (code == static_cast<DWORD>(0xC0000017)) { // STATUS_NO_MEMORY
      return static_cast<HRESULT>(0x8007000E);    // E_OUTOFMEMORY
    }
    return static_cast<HRESULT>(0x80004005);      // E_FAIL
  }
}

extern "C" HRESULT FUN_00416390(LPCRITICAL_SECTION cs /*ECX*/)
{
  return CriticalSection_Initialize_SehToHresult_Ecx_Inferred(cs);
}
