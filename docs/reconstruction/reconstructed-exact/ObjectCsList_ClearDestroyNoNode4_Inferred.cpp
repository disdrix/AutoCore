// =============================================================================
// ObjectCsList_ClearDestroyNoNode4_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051bc90
// Address:   0x0051bc90–0x0051bd8b exclusive (251 B / 0xFB); bare C3
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_0051bc90
// System:    object core / CS-owned list teardown
// Dual:      2026-07-29 W31-S OWN-ONLY
// =============================================================================
//
// ABI: __thiscall/__fastcall; ECX = list*; no stack formals; void; bare RET
//
// CF (machine-sealed):
//   1. SEH LAB_009a3520 + __chkstk 0x1004
//   2. EnterCriticalSection(list+4)
//   3. if list+0x28 != 0: LeaveCS; throw 0x80070005 (E_ACCESSDENIED)
//   4. while head = list+0x1C:
//        head = node->next (+8)
//        (*node->vtbl)(1)          // NO node+4 = 0  ← twin difference
//   5. zero +0x24 / +0x20 / +0x1C
//   6. LeaveCriticalSection; restore FS:[0]; RET
//
// Twin: ObjectCsList_ClearDestroy_Inferred (0x0051b8a0, W30-F) clears node+4.
// Callers: list scalar dtor FUN_0051bf10; complete dtor FUN_0051d0e0 (×2).
// Does NOT free list / DeleteCS (callers do).

#include <stdint.h>
#include <windows.h>

struct ObjectCsListNode {
  void **vtbl;              // +0x00
  uint32_t field04;         // +0x04  NOT cleared in this unit
  ObjectCsListNode *next;   // +0x08
};

extern "C" void *__cdecl _CxxThrowException(void *pExceptionObject, void *pThrowInfo);
extern "C" void *DAT_00acc430; // ThrowInfo*

// __thiscall/__fastcall; ECX=list*; void; bare RET
void __fastcall ObjectCsList_ClearDestroyNoNode4_Inferred(void *list_raw)
{
  auto *list = reinterpret_cast<uint8_t *>(list_raw);
  // SEH + chkstk frame omitted (behavior-preserving CF only)

  EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));

  auto *node = *reinterpret_cast<ObjectCsListNode **>(list + 0x1C);

  if (list[0x28] != 0) {
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));
    uint32_t hr = 0x80070005u;
    _CxxThrowException(&hr, &DAT_00acc430);
    // noreturn
  }

  while (node != nullptr) {
    *reinterpret_cast<ObjectCsListNode **>(list + 0x1C) = node->next;
    using ScalarDtor = void(__thiscall *)(ObjectCsListNode *, int);
    reinterpret_cast<ScalarDtor>(node->vtbl[0])(node, 1);
    node = *reinterpret_cast<ObjectCsListNode **>(list + 0x1C);
  }

  *reinterpret_cast<uint32_t *>(list + 0x24) = 0;
  *reinterpret_cast<uint32_t *>(list + 0x20) = 0;
  *reinterpret_cast<uint32_t *>(list + 0x1C) = 0;

  LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));
}
