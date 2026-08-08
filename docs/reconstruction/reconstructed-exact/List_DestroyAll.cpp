// =============================================================================
// List_DestroyAll
// -----------------------------------------------------------------------------
// Stable ID: aa_004bc950
// Address:   0x004bc950–0x004bca4a  (autoassault.exe, image base 0x400000)
// System:    client::list (CS-guarded intrusive list) / inventory-transfer
// Generated: 2026-08-05 R10-028 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Product plate (SEH path): "List Error!  DestroyAll Call Stack:\n%s\n" @ 0x00a33af0
// Family: List_RemoveAll (0x004bc580), List_TraversalLock (0x004294f0),
//         List_IterateNext (0x004022a0).
// CF twin (separate VA): ObjectCsList_DestroyAll_Inferred (0x00424060) — do not merge.
// ABI: ECX = list host; void; bare RET (C3). Body 251 B.

#include <cstdint>
#include <windows.h>

// Host offsets (sealed)
// +0x04 CRITICAL_SECTION
// +0x1c head ListNode*
// +0x20 dword cleared
// +0x24 dword cleared
// +0x28 char traversal-lock flag

// Node: vtbl@0, next@+8  (no node[+4] clear on this path)

extern "C" void __stdcall _CxxThrowException(void*, void*);
extern uint8_t DAT_00acc430[]; // ThrowInfo

void __fastcall List_DestroyAll(int host /* ECX */)
{
  EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(host + 4));

  uint32_t* node = *reinterpret_cast<uint32_t**>(host + 0x1c);

  if (*reinterpret_cast<char*>(host + 0x28) != 0) {
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(host + 4));
    uint32_t code = 0x80070005u; // E_ACCESSDENIED
    _CxxThrowException(&code, reinterpret_cast<void*>(&DAT_00acc430));
    // non-returning
  }

  while (node != nullptr) {
    *reinterpret_cast<uint32_t**>(host + 0x1c) = reinterpret_cast<uint32_t*>(node[2]);
    // scalar deleting dtor: (*node->vtbl)(node, 1)
    // NOTE: unlike List_RemoveAll, does NOT zero node[1] before dtor
    (**(void(__thiscall***)(uint32_t*, int))node)(node, 1);
    node = *reinterpret_cast<uint32_t**>(host + 0x1c);
  }

  *reinterpret_cast<uint32_t*>(host + 0x24) = 0;
  *reinterpret_cast<uint32_t*>(host + 0x20) = 0;
  *reinterpret_cast<uint32_t*>(host + 0x1c) = 0;

  LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(host + 4));
}
