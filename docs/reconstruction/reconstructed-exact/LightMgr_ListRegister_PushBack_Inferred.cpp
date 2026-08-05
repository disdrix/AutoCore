// =============================================================================
// LightMgr_ListRegister_PushBack_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e310
// Address:   0x0074e310  (autoassault.exe, image base 0x400000)
// System:    Palantir light/effect list manager — push-back register + bind
// Wave:      W38-T dual seal 2026-08-04
// Exactness: Behavior-preserving rewrite from decompile + read_memory.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Append a refcounted object to host's pointer vector (begin@+8,
//   end@+0xC), AddRef new / Release prior slot value, then call
//   obj->vtbl[+0x30](*host) to bind. Returns 0. RET 4.
// Grow: FUN_00449440 / FUN_00449560 resize to size+1 (unowned helpers).
// Peers: LightMgr_SetActiveSlot3c (0x0074e0d0), unregister FUN_0074e260.
// Callers: PalantirEnv_RebuildDefaultLights (Direction + Hemi cores at +0x8c),
//   Reflect resolve, BTLG path, other light hosts via [host+4] this-adjust.
// ABI: __thiscall(host*, obj*); returns 0; RET 4.
//

#include <cstdint>

struct RefCountedVObj {
  void** vtbl;       // +0x00; [1]=on_first_addref (+4), [2]=on_last_release (+8),
                     //        [12]=bind (+0x30)
  int32_t refcount;  // +0x04
};

// Host layout (byte offsets):
//   +0x00 identity (void*) — passed to bind
//   +0x04 prefix (unused here; FUN_00449440 takes host+4 so +4/+8 = begin/end)
//   +0x08 begin (RefCountedVObj**)
//   +0x0C end   (RefCountedVObj**)
//   +0x10 capacity (grow helper)

// External: vector resize-to-N via this+4 view (ecx=N, edx=host+4).
extern "C" void FUN_00449440(/* edx = host+4, ecx = new_size */);

// ECX = host; stack = obj* (callers non-null); RET 4; returns 0
uint32_t __thiscall LightMgr_ListRegister_PushBack_Inferred(
    void* host,
    RefCountedVObj* obj)
{
  auto* base = reinterpret_cast<uint8_t*>(host);
  auto** begin_ptr = reinterpret_cast<RefCountedVObj***>(base + 0x08);
  auto** end_ptr = reinterpret_cast<RefCountedVObj***>(base + 0x0C);

  RefCountedVObj** begin = *begin_ptr;
  RefCountedVObj** end = *end_ptr;

  uint32_t size;
  if (begin == nullptr) {
    size = 0;
  } else {
    size = static_cast<uint32_t>(end - begin);
  }

  // Bytes: lea edx,[ebx+4]; lea ecx,[size+1]; call FUN_00449440
  (void)size;
  FUN_00449440();  // actual: edx=host+4, ecx=size+1 (register ABI)

  // Re-read end after resize
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

  // vtbl[+0x30](*host) — bind to host identity dword at +0
  void* identity = *reinterpret_cast<void**>(base + 0x00);
  reinterpret_cast<void(__thiscall*)(RefCountedVObj*, void*)>(obj->vtbl[12])(
      obj, identity);

  return 0;
}
