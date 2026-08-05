// =============================================================================
// FUN_004e15a0  (scaffold alias → CsSList_ContainsPayload_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e15a0
// Address:   0x004e15a0  (autoassault.exe, image base 0x400000)
// System:    client containers / deferred-queue membership
// Generated: 2026-07-29 W20-P dual — scaffold keeps Ghidra name; clean is primary.
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Canonical clean: CsSList_ContainsPayload_Inferred.cpp
// =============================================================================

#include <cstdint>

#if defined(_WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#else
struct CRITICAL_SECTION {};
inline void EnterCriticalSection(CRITICAL_SECTION*) {}
inline void LeaveCriticalSection(CRITICAL_SECTION*) {}
#endif

// Scaffold: same sealed CF as clean; names stay close to decompiler surface.
std::uint32_t __thiscall FUN_004e15a0(void* param_1 /*list ECX*/,
                                      void* param_2 /*payload stack*/)
{
  auto* base = reinterpret_cast<std::uint8_t*>(param_1);

  EnterCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(base + 0x28));
  EnterCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(base + 0x10));

  auto* node = *reinterpret_cast<std::uint8_t**>(base + 4);
  while (true) {
    if (node == nullptr) {
      LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(base + 0x10));
      LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(base + 0x28));
      return 0;
    }
    if (*reinterpret_cast<void**>(node + 4) == param_2) {
      break;
    }
    node = *reinterpret_cast<std::uint8_t**>(node + 8);
  }

  LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(base + 0x10));
  LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(base + 0x28));
  return 1;
}
