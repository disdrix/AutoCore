// =============================================================================
// WorldObj_UnbindOrDefer_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005614f0
// Address:   0x005614f0–0x00561571 (129 B / 0x81); ret 8
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_005614f0
// System:    world-object unbind / defer (no destroy)
// Dual:      2026-07-29 W30-J OWN-ONLY
// =============================================================================
//
// ABI: __thiscall  ECX = Manager*; stack = uint8_t* outDone, Object* obj; void; ret 8
//
// CF:
//   if manager+0x12c == 1:
//     grow/push obj onto defer queue at +0xf0; obj.ref6++; *outDone=0; return
//   if manager+0x24 > 0: PhysSim_FlushPendingBodyPairs (00561320)
//   UnbindLinks (0055fbf0 this=manager, obj)
//   CompactObjPtrList (0055f0b0 this=obj)
//   ClearStampHostCleanup (0055fd80 this=manager, obj)
//   *outDone = 1
//
// Contrast WorldObj_RemoveOrDefer (00561450): that path also runs 0062a490 /
// 005ffff0, decrements ref@+6, and destroys when ref==0. This unit does not.
//
// Callers: WorldObj_SnapshotHostRefsAndUnbind (005617c0), FUN_00561580.

#include <cstdint>

extern "C" void FUN_005b3370(int *desc, int elemSize);
extern "C" void __thiscall FUN_00561320(int manager);
extern "C" void __thiscall FUN_0055fbf0(int manager, int obj);
extern "C" void __fastcall FUN_0055f0b0(int obj);
extern "C" void __thiscall FUN_0055fd80(int manager, int obj);

void __thiscall WorldObj_UnbindOrDefer_Inferred(int manager, uint8_t *outDone, int obj)
{
  if (*(uint8_t *)(manager + 0x12c) == 1) {
    if (*(uint32_t *)(manager + 0xf4) ==
        (*(uint32_t *)(manager + 0xf8) & 0x7fffffffu)) {
      FUN_005b3370((int *)(manager + 0xf0), 4);
    }
    *(int *)(*(int *)(manager + 0xf0) + *(int *)(manager + 0xf4) * 4) = obj;
    *(int *)(manager + 0xf4) = *(int *)(manager + 0xf4) + 1;
    *(int16_t *)(obj + 6) = (int16_t)(*(int16_t *)(obj + 6) + 1);
    *outDone = 0;
    return; // ret 8
  }

  if (*(int *)(manager + 0x24) > 0) {
    FUN_00561320(manager);
  }
  FUN_0055fbf0(manager, obj);
  FUN_0055f0b0(obj);
  FUN_0055fd80(manager, obj);
  *outDone = 1;
  return; // ret 8
}
