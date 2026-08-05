// =============================================================================
// Elem0x28_CompleteDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_005b8000
// Address:   0x005b8000–0x005b810b  (267 B / 0x10B, autoassault.exe base 0x400000)
// System:    class / cookie-vector element destructor (stride 0x28)
// Generated: 2026-07-29 W29-F dual A/B (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + body bytes seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_005b8000
// =============================================================================
//
// PURPOSE:
//   Element complete destructor for 0x28-byte vector elements. Registered as the
//   per-element dtor for _eh_vector_destructor_iterator_ from:
//     - Class_009c7a1c_CompleteDtor (FUN_004970b0) array at host+0x28
//     - FUN_00494170 / FUN_004941b0 (same stride 0x28)
//
//   Order:
//     1) If owned@+0x24: complete-dtor FUN_004be2a0(owned); operator_delete(owned); zero.
//     2) For each list-host pointer in vector [+0x14,+0x18): free node payloads @node+8,
//        empty list (sentinel self-links, size 0), free remaining nodes + head + list host.
//     3) Free vector storage; zero +0x14/+0x18/+0x1C.
//     4) Free buffer begin@+0x4; zero +0x4/+0x8/+0xC.
//
// ABI:
//   __thiscall; ECX=element; no stack formals; bare RET; void.
//   SEH: LAB_009a6b0a; EH state 1 on owned path.
//
// NOTE:
//   Ghidra may mark operator_delete as noreturn; machine fall-through is normal.
//   Product English for element / owned type open — structural name used.
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_004be2a0(void* owned);  // owned-object complete dtor
extern "C" void operator_delete(void* p);

// Machine: void __thiscall FUN_005b8000(void* elem)
extern "C" void __thiscall Elem0x28_CompleteDtor(void* elem)
{
  auto* e = reinterpret_cast<uint8_t*>(elem);

  // --- owned object @ +0x24 ---
  void* owned = *reinterpret_cast<void**>(e + 0x24);
  if (owned != nullptr) {
    FUN_004be2a0(owned);  // bytes: mov ecx, owned; call
    operator_delete(owned);
  }
  *reinterpret_cast<void**>(e + 0x24) = nullptr;

  // --- vector of list-host pointers @ +0x14 / +0x18 / +0x1C ---
  int** it  = *reinterpret_cast<int***>(e + 0x14);
  int** end = *reinterpret_cast<int***>(e + 0x18);

  for (; it != end; ++it) {
    // Walk nodes from head@list+8; free payload at node+8 (node[2] as int*)
    int* listHost = *it;
    int* head = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(listHost) + 8);
    int* node = *reinterpret_cast<int**>(head);  // first after sentinel
    if (node != head) {
      do {
        void* payload = reinterpret_cast<void*>(node[2]);
        if (payload != nullptr) {
          operator_delete(payload);
        }
        node = reinterpret_cast<int*>(*node);
      } while (node != *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(listHost) + 8));
    }

    // Empty list + free nodes/head/listHost (bytes seal dual delete + loop)
    if (listHost != nullptr) {
      int** headSlot = *reinterpret_cast<int***>(reinterpret_cast<uint8_t*>(listHost) + 8);
      void* first = *headSlot;
      *headSlot = reinterpret_cast<int*>(headSlot);  // head->next = head
      *reinterpret_cast<int**>(
          reinterpret_cast<uint8_t*>(
              *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(listHost) + 8)) +
          4) =
          *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(listHost) + 8);  // head->prev
      *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(listHost) + 0x0C) = 0;

      void* cur = first;
      void* headObj = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(listHost) + 8);
      while (cur != headObj) {
        void* next = *reinterpret_cast<void**>(cur);
        operator_delete(cur);
        cur = next;
        headObj = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(listHost) + 8);
      }
      operator_delete(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(listHost) + 8));
      *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(listHost) + 8) = nullptr;
      operator_delete(listHost);
    }
  }

  void* vecStorage = *reinterpret_cast<void**>(e + 0x14);
  if (vecStorage != nullptr) {
    operator_delete(vecStorage);
  }
  *reinterpret_cast<void**>(e + 0x14) = nullptr;
  *reinterpret_cast<void**>(e + 0x18) = nullptr;
  *reinterpret_cast<void**>(e + 0x1C) = nullptr;

  // --- buffer triple @ +0x4 / +0x8 / +0xC ---
  void* buf = *reinterpret_cast<void**>(e + 0x4);
  if (buf != nullptr) {
    operator_delete(buf);
  }
  *reinterpret_cast<void**>(e + 0x4) = nullptr;
  *reinterpret_cast<void**>(e + 0x8) = nullptr;
  *reinterpret_cast<void**>(e + 0x0C) = nullptr;
}
