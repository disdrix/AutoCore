// =============================================================================
// LightMgr_SetActiveSlot3c_Refcount_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e0d0
// Address:   0x0074e0d0  (autoassault.exe, image base 0x400000)
// System:    Palantir light manager — active refcounted slot at +0x3c
// Wave:      W37-AE dual seal 2026-08-04
// Exactness: Behavior-preserving rewrite from decompile + read_memory.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Swap host[+0x3c] to a new refcounted object (or null).
//   - If new != null: refcount++ at new[+4]; if became 1, vtbl[+4]().
//   - If old at host[+0x3c] != null: refcount--; if 0, vtbl[+8]().
//   - Store new at host[+0x3c].
// Callers: PalantirEnv rebuild/tear default lights; UI/host Directional attach.
// ABI: __thiscall(host*, new_obj*); RET 4; void.
//

#include <cstdint>

struct RefCountedVObj {
  void** vtbl;       // +0x00; [+4]=on_first_addref, [+8]=on_last_release
  int32_t refcount;  // +0x04
};

struct LightMgrHost {
  // ...
  // +0x3c: RefCountedVObj* active_slot
};

// ECX = host; stack = new_obj* (may be null); RET 4
void __thiscall LightMgr_SetActiveSlot3c_Refcount_Inferred(
    LightMgrHost* host,
    RefCountedVObj* new_obj)
{
  if (new_obj != nullptr) {
    new_obj->refcount += 1;
    if (new_obj->refcount == 1) {
      // vtbl[+4]
      reinterpret_cast<void(__thiscall*)(RefCountedVObj*)>(new_obj->vtbl[1])(new_obj);
    }
  }

  RefCountedVObj* old_obj =
      *reinterpret_cast<RefCountedVObj**>(reinterpret_cast<uint8_t*>(host) + 0x3c);
  if (old_obj != nullptr) {
    old_obj->refcount -= 1;
    if (old_obj->refcount == 0) {
      // vtbl[+8]
      reinterpret_cast<void(__thiscall*)(RefCountedVObj*)>(old_obj->vtbl[2])(old_obj);
    }
  }

  *reinterpret_cast<RefCountedVObj**>(reinterpret_cast<uint8_t*>(host) + 0x3c) = new_obj;
}
