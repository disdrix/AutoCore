// =============================================================================
// Object_LoadOrReplaceAnimSlot
// -----------------------------------------------------------------------------
// Stable ID: aa_005828b0
// Address:   0x005828b0  (autoassault.exe, image base 0x400000)
// System:    client::special-event / visual anim slots
// Generated: 2026-07-29 W18-C dual A/B seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   On a visual host, replace anim slot[slotIndex] with a newly loaded animation
//   from path (e.g. "obj_f_inc_mov_01_airlift_at.anm"):
//     1) require controller at this+0x24
//     2) if slot occupied: controller.Remove (vtbl+0x10), teardown, delete, zero
//     3) new 0x78 + ctor FUN_0074ed90 → store slot
//     4) resolve path (FUN_00989e00) + load (FUN_0074ee40); fail if < 0
//     5) duration = float at (DAT_00b04c74 + 0x238) via FUN_0079a110
//     6) FUN_0074e910(slot, start=0, duration)
//     7) slot+0x4c = flagByte
//     8) controller.Add (vtbl+0x0C)
//     9) return 1 on success, else 0
//
// ABI: __thiscall — ECX = visual host*; stack (slotIndex, path, flagByte); ret 0xC.
//
// CALLERS (airlift trio slots 1/2/3, flag 0):
//   ClientSpecialEvent_TeleportIn_ctor  0x00978d20  (ECX = visual @ event+0x24)
//   ClientSpecialEvent_TeleportOut_ctor 0x009781d0  (ECX = visual @ event+0x10)
//   FUN_00979310                        0x00979310  (ECX = visual @ +0x10)
//
// SEALED: thiscall ret 0xC; slot table this+0x2c; controller this+0x24; 0x78 size.
// =============================================================================

#include <cstdint>

struct AnimController;
struct AnimSlot;

// Visual host fields used by this unit (product type Open).
struct VisualAnimHost {
  // ...
  // +0x24
  AnimController* controller;
  // +0x2c
  AnimSlot* slots[/* runtime extent; callers use 1..3 */];
};

// Controller vtbl: +0x0C Add(slot*), +0x10 Remove(slot*)  (MSVC thiscall on controller)
struct AnimControllerVtbl {
  // ...
  void(__thiscall* Add)(AnimController* self, AnimSlot* slot);     // +0x0C
  void(__thiscall* Remove)(AnimController* self, AnimSlot* slot);  // +0x10
};

struct AnimController {
  AnimControllerVtbl* vtbl;
};

// 0x78-byte slot (ctor FUN_0074ed90). Only +0x4c written here after load.
struct AnimSlot {
  uint8_t pad0[0x4c];
  uint8_t flag_4c;   // set from arg; ctor default 1
  // ... through 0x78
};

extern "C" void* __cdecl operator_new(uint32_t size);
extern "C" void __cdecl operator_delete(void* p);

// Slot lifecycle (addresses sealed as callees; bodies not OWN).
extern "C" AnimSlot* __fastcall FUN_0074ed90(AnimSlot* self);  // ctor
extern "C" void __fastcall FUN_0074eb20(AnimSlot* self);       // teardown
extern "C" void __fastcall FUN_0074ecf0(AnimSlot* self);       // dtor
extern "C" void __thiscall FUN_0074e910(AnimSlot* self, float start, float duration);
extern "C" int __thiscall FUN_0074ee40(AnimSlot* self, void* pathHandle);
extern "C" void __thiscall FUN_00989e00(void* pathCache /* ECX=0x00d1eac8 */,
                                       void* outHandle,
                                       const char* path);
extern "C" long double /* float10 */ __fastcall FUN_0079a110(void* clock /* DAT_00b04c74 */);

extern "C" void* DAT_00d1eac8;  // path-cache this for FUN_00989e00
extern "C" void* DAT_00b04c74;  // duration singleton (+0x238 float)

// MSVC thiscall: ECX = visual; callee cleans 12 stack bytes (ret 0xC).
uint32_t __thiscall Object_LoadOrReplaceAnimSlot(VisualAnimHost* self,
                                                 int slotIndex,
                                                 const char* path,
                                                 uint8_t flagByte)
{
  if (self->controller == nullptr) {
    return 0;
  }

  AnimSlot* existing = self->slots[slotIndex];
  if (existing != nullptr) {
    self->controller->vtbl->Remove(self->controller, existing);
    FUN_0074eb20(existing);
    AnimSlot* p = self->slots[slotIndex];
    if (p != nullptr) {
      FUN_0074ecf0(p);
      operator_delete(p);
    }
    self->slots[slotIndex] = nullptr;
  }

  AnimSlot* neu = static_cast<AnimSlot*>(operator_new(0x78));
  AnimSlot* built = (neu != nullptr) ? FUN_0074ed90(neu) : nullptr;
  self->slots[slotIndex] = built;

  void* pathHandle = nullptr;
  FUN_00989e00(DAT_00d1eac8, &pathHandle, path);

  int loadRc = FUN_0074ee40(self->slots[slotIndex], &pathHandle);
  if (loadRc < 0) {
    return 0;
  }

  float duration = static_cast<float>(FUN_0079a110(DAT_00b04c74));
  FUN_0074e910(self->slots[slotIndex], 0.0f, duration);
  self->slots[slotIndex]->flag_4c = flagByte;
  self->controller->vtbl->Add(self->controller, self->slots[slotIndex]);
  return 1;
}
