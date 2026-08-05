// =============================================================================
// FUN_005828b0  (scaffold alias — prefer Object_LoadOrReplaceAnimSlot.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_005828b0
// Address:   0x005828b0  (autoassault.exe, image base 0x400000)
// System:    client::special-event / visual anim slots
// Generated: 2026-07-29 W18-C dual A/B (scaffold mirror of structural clean)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Load/replace visual anim slot[index] from path; return 1/0.
// ABI: thiscall, ret 0xC, ECX=visual (see Object_LoadOrReplaceAnimSlot.cpp).

#include <cstdint>

extern "C" void* __cdecl operator_new(uint32_t size);
extern "C" void __cdecl operator_delete(void* p);
extern "C" void* __fastcall FUN_0074ed90(void* self);
extern "C" void __fastcall FUN_0074eb20(void* self);
extern "C" void __fastcall FUN_0074ecf0(void* self);
extern "C" void __thiscall FUN_0074e910(void* self, float a, float b);
extern "C" int __thiscall FUN_0074ee40(void* self, void* path);
extern "C" void __thiscall FUN_00989e00(void* cache, void* out, const char* path);
extern "C" long double __fastcall FUN_0079a110(void* clock);
extern "C" void* DAT_00d1eac8;
extern "C" void* DAT_00b04c74;

uint32_t __thiscall FUN_005828b0(int self, int slotIndex, const char* path, uint8_t flagByte)
{
  if (*(int*)(self + 0x24) == 0) {
    return 0;
  }

  int existing = *(int*)(self + 0x2c + slotIndex * 4);
  if (existing != 0) {
    int* ctrl = *(int**)(self + 0x24);
    (*(void(__thiscall**)(int*, int))(*(int*)ctrl + 0x10))(ctrl, existing);
    FUN_0074eb20((void*)*(int*)(self + 0x2c + slotIndex * 4));
    void* p = *(void**)(self + 0x2c + slotIndex * 4);
    if (p != nullptr) {
      FUN_0074ecf0(p);
      operator_delete(p);
    }
    *(int*)(self + 0x2c + slotIndex * 4) = 0;
  }

  void* neu = operator_new(0x78);
  void* built = (neu != nullptr) ? FUN_0074ed90(neu) : nullptr;
  *(void**)(self + 0x2c + slotIndex * 4) = built;

  void* pathHandle = nullptr;
  FUN_00989e00(DAT_00d1eac8, &pathHandle, path);

  int rc = FUN_0074ee40(*(void**)(self + 0x2c + slotIndex * 4), &pathHandle);
  if (rc < 0) {
    return 0;
  }

  float dur = static_cast<float>(FUN_0079a110(DAT_00b04c74));
  FUN_0074e910(*(void**)(self + 0x2c + slotIndex * 4), 0.0f, dur);
  *(uint8_t*)(*(int*)(self + 0x2c + slotIndex * 4) + 0x4c) = flagByte;

  int* ctrl = *(int**)(self + 0x24);
  (*(void(__thiscall**)(int*, int))(*(int*)ctrl + 0x0C))(
      ctrl, *(int*)(self + 0x2c + slotIndex * 4));
  return 1;
}
