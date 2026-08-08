// =============================================================================
// ObjectCsList_DestroyAll_Inferred  (aa_00424060)
// -----------------------------------------------------------------------------
// Address:   0x00424060–0x0042415a inclusive (251 B / 0xFB)
// Wave:      WQ9L-E OWN-ONLY dual 2026-08-05
// System:    object core / CS-owned list DestroyAll
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + read_memory + product SEH string. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Product method English from SEH catch: "DestroyAll".
//   Under CRITICAL_SECTION at list+4: if traversal flag +0x28 set, throw
//   0x80070005 (E_ACCESSDENIED). Else drain singly-linked head at +0x1C
//   (next @ node+8), scalar-delete each node via vtbl[0](1), zero
//   +0x24/+0x20/+0x1C, LeaveCS.
//   Does NOT free the list object or DeleteCriticalSection (callers do).
//   Does NOT clear node+4 (NoNode4 twin of ObjectCsList_ClearDestroyNoNode4
//   @ 0x0051bc90; opposite of ClearDestroy @ 0x0051b8a0 which zeros node+4).
//
// ABI:
//   ECX = list*. SEH LAB_009bd790 + __chkstk 0x1004. Bare RET (C3). void.
//
// UI CONTEXT:
//   CNDUIWindow nested member @ +0x1E8 (vtbls 00a964b8 / 00a964ac =
//   CNDDoubleListPtr / CNDDoubleList of STextMarkup) dual-calls this then
//   DeleteCriticalSection(+0x1EC). Shared by many list types.
//
// STRING:
//   "List Error!  DestroyAll Call Stack:\n%s\n" @ 0x00a33af0
// =============================================================================

#include <cstdint>
#include <windows.h>

struct ObjectCsListNode {
  void** vtbl;              // +0x00
  uint32_t field04;         // +0x04  NOT cleared in this unit
  ObjectCsListNode* next;   // +0x08
};

extern "C" void* __cdecl _CxxThrowException(void* pExceptionObject, void* pThrowInfo);
extern "C" void* DAT_00acc430; // ThrowInfo*

// __thiscall/__fastcall; ECX=list*; void; bare RET
extern "C" void __fastcall ObjectCsList_DestroyAll_Inferred(void* list_raw)
{
  auto* list = reinterpret_cast<uint8_t*>(list_raw);
  // SEH LAB_009bd790 + __chkstk 0x1004 frame omitted (behavior CF only)

  EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));

  auto* node = *reinterpret_cast<ObjectCsListNode**>(list + 0x1C);

  if (list[0x28] != 0) {
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));
    uint32_t hr = 0x80070005u; // E_ACCESSDENIED
    _CxxThrowException(&hr, &DAT_00acc430);
    // noreturn — catch logs DestroyAll call stack
  }

  while (node != nullptr) {
    *reinterpret_cast<ObjectCsListNode**>(list + 0x1C) = node->next;
    // NO node->field04 = 0
    using ScalarDtor = void(__thiscall*)(ObjectCsListNode*, int);
    reinterpret_cast<ScalarDtor>(node->vtbl[0])(node, 1);
    node = *reinterpret_cast<ObjectCsListNode**>(list + 0x1C);
  }

  *reinterpret_cast<uint32_t*>(list + 0x24) = 0;
  *reinterpret_cast<uint32_t*>(list + 0x20) = 0;
  *reinterpret_cast<uint32_t*>(list + 0x1C) = 0;

  LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));
}

// Ghidra twin name
extern "C" void __fastcall FUN_00424060(void* list_raw)
{
  ObjectCsList_DestroyAll_Inferred(list_raw);
}
