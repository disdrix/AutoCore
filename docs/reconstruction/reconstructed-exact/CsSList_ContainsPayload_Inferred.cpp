// =============================================================================
// CsSList_ContainsPayload_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004e15a0
// Address:   0x004e15a0  (autoassault.exe, image base 0x400000)
// System:    client containers / deferred-queue membership
// Generated: 2026-07-29 W20-P dual (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF sealed by bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Thread-safe membership test on a CS-protected singly-linked payload list.
//   Twin of CsSList_AppendPayload_Inferred (FUN_004024d0) — same list/node layout.
//
// ABI (bytes sealed):
//   __thiscall  ECX = list*, stack arg0 = void* payload
//   ret 4
//   return AL: 0 = not found, 1 = found
//
// LAYOUT (sealed):
//   list+0x04 head*; list+0x10 CRITICAL_SECTION; list+0x28 CRITICAL_SECTION
//   node+0x04 payload*; node+0x08 next*
//
// NOTE: Always enters BOTH critical sections (no count≤3 gate unlike Append).
// =============================================================================

#include <cstdint>

#if defined(_WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#else
// Non-Windows host: CS stubs for documentation builds only.
struct CRITICAL_SECTION {};
inline void EnterCriticalSection(CRITICAL_SECTION*) {}
inline void LeaveCriticalSection(CRITICAL_SECTION*) {}
#endif

struct CsSListNode_Inferred {
  void* vtbl;      // +0x00 (unused by Contains)
  void* payload;   // +0x04
  CsSListNode_Inferred* next; // +0x08
};

struct CsSList_Inferred {
  void* vtbl_or_pad;           // +0x00
  CsSListNode_Inferred* head;  // +0x04
  CsSListNode_Inferred* tail;  // +0x08 (unused here)
  std::uint32_t count;         // +0x0C (unused here)
  CRITICAL_SECTION cs_inner;   // +0x10
  // … CS object size … outer CS at +0x28 relative to list base
};

// Offsets used as in retail body (byte-addressed).
static constexpr std::uint32_t kListHeadOff  = 0x04u;
static constexpr std::uint32_t kListCsInner  = 0x10u;
static constexpr std::uint32_t kListCsOuter  = 0x28u;
static constexpr std::uint32_t kNodePayload  = 0x04u;
static constexpr std::uint32_t kNodeNext     = 0x08u;

std::uint32_t __thiscall CsSList_ContainsPayload_Inferred(void* list /*ECX*/,
                                                          void* payload /*stack*/)
{
  auto* base = reinterpret_cast<std::uint8_t*>(list);

  auto* cs_outer = reinterpret_cast<CRITICAL_SECTION*>(base + kListCsOuter);
  auto* cs_inner = reinterpret_cast<CRITICAL_SECTION*>(base + kListCsInner);

  EnterCriticalSection(cs_outer);
  EnterCriticalSection(cs_inner);

  auto* node = *reinterpret_cast<std::uint8_t**>(base + kListHeadOff);
  while (true) {
    if (node == nullptr) {
      LeaveCriticalSection(cs_inner);
      LeaveCriticalSection(cs_outer);
      return 0;
    }
    if (*reinterpret_cast<void**>(node + kNodePayload) == payload) {
      break;
    }
    node = *reinterpret_cast<std::uint8_t**>(node + kNodeNext);
  }

  LeaveCriticalSection(cs_inner);
  LeaveCriticalSection(cs_outer);
  return 1;
}
