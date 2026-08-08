// =============================================================================
// CsSList_RemoveFirstByPredicate_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00405920
// Address:   0x00405920  (autoassault.exe, image base 0x400000)
// System:    client containers / CS-protected singly-linked list
// Generated: 2026-08-05 MEGA-042 dual (decompile + disassemble + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF sealed by bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
//
// PURPOSE:
//   Thread-safe remove of the FIRST list node whose payload matches a
//   caller-supplied predicate(payload, cookie). Twin of:
//     CsSList_AppendPayload_Inferred   (FUN_004024d0)
//     CsSList_ContainsPayload_Inferred (FUN_004e15a0)
//
// ABI (bytes sealed):
//   __thiscall  ECX = list*
//   stack arg0  bool (*)(void* payload, void* cookie)  — cdecl-ish RET 8
//   stack arg1  void* cookie
//   epilogue    ret 8
//   returns     void
//
// Layout (sealed):
//   list+0x04 head*, +0x08 tail*, +0x0C count (InterlockedDecrement),
//   +0x10 CRITICAL_SECTION (always), +0x28 CRITICAL_SECTION (always)
//   node: +0 vtbl, +4 payload*, +8 next*
//
// NOTE: Always enters BOTH critical sections (no count≤3 gate unlike Append).
//       Removes at most one node; scalar-deleting dtor via vtbl[0](1).
//
// Ghidra alias: FUN_00405920
// Retired:      Named_CalleeOf_Named_CalleeOf_Client_SendInventoryAddItem_00405920
// Dual reviews: A_/B_aa_00405920_CsSList_RemoveFirstByPredicate_Inferred.md
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
inline long InterlockedDecrement(long volatile* p) { return --(*p); }
#endif

struct CsSListNode_Inferred {
  void* vtbl;                     // +0x00  slot0 = scalar deleting dtor
  void* payload;                  // +0x04
  CsSListNode_Inferred* next;     // +0x08
};

// Offsets used as in retail body (byte-addressed).
static constexpr std::uint32_t kListHeadOff = 0x04u;
static constexpr std::uint32_t kListTailOff = 0x08u;
static constexpr std::uint32_t kListCountOff = 0x0Cu;
static constexpr std::uint32_t kListCsInner = 0x10u;
static constexpr std::uint32_t kListCsOuter = 0x28u;

// Predicate: live call sites use pointer-equality stubs @ 0x4cd580 / 0x92d8e0
// (MOV/CMP/SETE/RET 8). Convention matches cdecl with RET 8 cleanup.
typedef char (__cdecl *CsSList_Pred_Inferred)(void* payload, void* cookie);

// MSVC thiscall: ECX = list
void __thiscall CsSList_RemoveFirstByPredicate_Inferred(
    void* list /*ECX*/,
    CsSList_Pred_Inferred pred /*stack*/,
    void* cookie /*stack*/)
{
  auto* base = reinterpret_cast<std::uint8_t*>(list);

  auto* cs_outer = reinterpret_cast<CRITICAL_SECTION*>(base + kListCsOuter);
  auto* cs_inner = reinterpret_cast<CRITICAL_SECTION*>(base + kListCsInner);

  EnterCriticalSection(cs_outer);
  EnterCriticalSection(cs_inner);

  auto** head_slot = reinterpret_cast<CsSListNode_Inferred**>(base + kListHeadOff);
  auto** tail_slot = reinterpret_cast<CsSListNode_Inferred**>(base + kListTailOff);

  CsSListNode_Inferred* prev = nullptr;
  CsSListNode_Inferred* node = *head_slot;

  while (true) {
    if (node == nullptr) {
      LeaveCriticalSection(cs_inner);
      LeaveCriticalSection(cs_outer);
      return;
    }

    char match = pred(node->payload, cookie);
    if (match != '\0') {
      // Unlink
      if (prev == nullptr) {
        *head_slot = node->next;
      } else {
        prev->next = node->next;
      }
      if (node->next == nullptr) {
        *tail_slot = prev;
      }

      // Clear payload then scalar-deleting dtor: (*vtbl)(1) with ECX=node
      node->payload = nullptr;
      using DtorFn = void(__thiscall*)(CsSListNode_Inferred* self, int flags);
      auto* vtbl = *reinterpret_cast<DtorFn**>(node);
      (*vtbl)(node, 1);

      InterlockedDecrement(reinterpret_cast<LONG*>(base + kListCountOff));

      LeaveCriticalSection(cs_inner);
      LeaveCriticalSection(cs_outer);
      return;
    }

    prev = node;
    node = node->next;
  }
}
