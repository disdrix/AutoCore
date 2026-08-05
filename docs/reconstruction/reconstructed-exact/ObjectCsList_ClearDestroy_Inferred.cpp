// =============================================================================
// ObjectCsList_ClearDestroy_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b8a0
// Address:   0x0051b8a0-0x0051b99c exclusive (252 B / 0xFC)
// System:    object core / CS-owned list teardown
// Generated: 2026-07-29 W30-F dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory seals.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
// Drain a 0x2C CS-list (Object SharedBase helper @ core+0xB0, vtbl
// PTR_FUN_009ce154): under CS at +4, if TraversalLock flag +0x28 is set throw
// 0x80070005; else walk head +0x1C, next@node+8, clear node+4, scalar-delete
// each node via vtbl[0](1); zero +0x24/+0x20/+0x1C; LeaveCS.
// Does NOT free the list object itself (caller scalar-deletes +0xB0 after).
//
// Sibling: List_ClearDestroy 0x0040dc40 (next@+0x10 node layout).
// Near twin: FUN_0051bc90 (no node+4 clear; used from CS-list dtor path).

#include <cstdint>
#include <windows.h>

struct ObjectCsList {
  void *vtbl;                 // +0x00  PTR_FUN_009ce154
  CRITICAL_SECTION cs;        // +0x04
  // pad to +0x1C
  void **head;                // +0x1C  (stored as node*)
  uint32_t field20;           // +0x20
  uint32_t field24;           // +0x24
  uint8_t  traversalFlag;     // +0x28
};

struct ObjectCsListNode {
  void **vtbl;                // +0x00
  uint32_t payloadOrRef;      // +0x04  cleared before dtor in THIS unit
  ObjectCsListNode *next;     // +0x08
};

extern "C" void *__cdecl _CxxThrowException(void *pExceptionObject, void *pThrowInfo);
extern "C" void *DAT_00acc430; // ThrowInfo*

// __thiscall/__fastcall; ECX=list*; void; bare RET
void __fastcall ObjectCsList_ClearDestroy_Inferred(void *list_raw)
{
  auto *list = reinterpret_cast<uint8_t *>(list_raw);
  // SEH LAB_009a3510 + __chkstk 0x1004 frame (throw path)

  EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));

  auto *node = *reinterpret_cast<ObjectCsListNode **>(list + 0x1C);

  if (list[0x28] != 0) {
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));
    uint32_t hr = 0x80070005;
    _CxxThrowException(&hr, &DAT_00acc430);
    // noreturn
  }

  while (node != nullptr) {
    *reinterpret_cast<ObjectCsListNode **>(list + 0x1C) = node->next;
    node->payloadOrRef = 0;
    using ScalarDtor = void(__thiscall *)(ObjectCsListNode *, int);
    reinterpret_cast<ScalarDtor>(node->vtbl[0])(node, 1);
    node = *reinterpret_cast<ObjectCsListNode **>(list + 0x1C);
  }

  *reinterpret_cast<uint32_t *>(list + 0x24) = 0;
  *reinterpret_cast<uint32_t *>(list + 0x20) = 0;
  *reinterpret_cast<uint32_t *>(list + 0x1C) = 0;

  LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));
}
