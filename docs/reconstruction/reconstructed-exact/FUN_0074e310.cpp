// =============================================================================
// FUN_0074e310
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e310
// Address:   0x0074e310  (autoassault.exe, image base 0x400000)
// System:    Palantir light/effect list manager
// Wave:      W38-T dual seal 2026-08-04
// Exactness: Behavior-preserving rewrite from decompile + read_memory.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// Named plate: LightMgr_ListRegister_PushBack_Inferred.cpp
// Twin entry for Ghidra FUN_* registry linkage.

#include <cstdint>

struct RefCountedVObj {
  void** vtbl;
  int32_t refcount;
};

extern "C" void FUN_00449440();

uint32_t __thiscall FUN_0074e310(void* host, RefCountedVObj* obj)
{
  auto* base = reinterpret_cast<uint8_t*>(host);
  auto** begin_ptr = reinterpret_cast<RefCountedVObj***>(base + 0x08);
  auto** end_ptr = reinterpret_cast<RefCountedVObj***>(base + 0x0C);

  RefCountedVObj** begin = *begin_ptr;
  RefCountedVObj** end = *end_ptr;

  uint32_t size = (begin == nullptr)
                      ? 0u
                      : static_cast<uint32_t>(end - begin);
  (void)size;
  FUN_00449440();  // edx=host+4, ecx=size+1 — resize vector to size+1

  end = *end_ptr;
  RefCountedVObj** slot = end - 1;

  if (obj != nullptr) {
    obj->refcount += 1;
    if (obj->refcount == 1) {
      reinterpret_cast<void(__thiscall*)(RefCountedVObj*)>(obj->vtbl[1])(obj);
    }
  }

  RefCountedVObj* old_obj = *slot;
  if (old_obj != nullptr) {
    old_obj->refcount -= 1;
    if (old_obj->refcount == 0) {
      reinterpret_cast<void(__thiscall*)(RefCountedVObj*)>(old_obj->vtbl[2])(old_obj);
    }
  }

  *slot = obj;
  void* identity = *reinterpret_cast<void**>(base + 0x00);
  reinterpret_cast<void(__thiscall*)(RefCountedVObj*, void*)>(obj->vtbl[12])(
      obj, identity);
  return 0;
}
