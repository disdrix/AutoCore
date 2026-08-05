// =============================================================================
// List_RemoveAll
// -----------------------------------------------------------------------------
// Stable ID: aa_004bc580
// Address:   0x004bc580  (autoassault.exe, image base 0x400000)
// System:    client::list (CS-guarded intrusive list)
// Generated: 2026-08-04 W37-U dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Product plate (SEH path): "List Error!  RemoveAll Call Stack:\n%s\n"
// Family: List_TraversalLock (0x004294f0), List_IterateNext (0x004022a0).
// ABI: ECX = list host; void; bare RET (C3). Body 252 B.

#include <cstdint>
#include <windows.h>

// Host offsets (sealed)
// +0x04 CRITICAL_SECTION
// +0x1c head ListNode*
// +0x20 dword cleared
// +0x24 dword cleared
// +0x28 char traversal-lock flag

// Node: vtbl@0, field@+4, next@+8

extern "C" void __stdcall _CxxThrowException(void*, void*);
extern uint8_t DAT_00acc430[]; // ThrowInfo

void __fastcall List_RemoveAll(int host /* ECX */)
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
    node[1] = 0;
    // scalar deleting dtor: (*node->vtbl)(node, 1)
    (**(void(__thiscall***)(uint32_t*, int))node)(node, 1);
    node = *reinterpret_cast<uint32_t**>(host + 0x1c);
  }

  *reinterpret_cast<uint32_t*>(host + 0x24) = 0;
  *reinterpret_cast<uint32_t*>(host + 0x20) = 0;
  *reinterpret_cast<uint32_t*>(host + 0x1c) = 0;

  LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(host + 4));
}
