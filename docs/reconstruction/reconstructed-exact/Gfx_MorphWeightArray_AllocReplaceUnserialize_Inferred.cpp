// =============================================================================
// Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred  (Ghidra: FUN_004373b0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004373b0
// Address:   0x004373b0  (autoassault.exe, image base 0x400000)
// System:    graphics / gfxMorphWeightArrayImpl — MWGT alloc+host-slot+unserialize
// Generated: 2026-08-04 W38-E dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate gfxMorphWeightArrayImpl (0x1c), inline-ctor, AddRef, release previous
//   host[+4], store new pointer (including null on OOM), unserialize MWGT chunk.
//
// ABI (bytes win over decompiler void/unaff formals):
//   EBX     = host*  (refcounted slot at host+4)
//   stack+4 = stoChunkReader* reader
//   RET 4
//   return  = status in EAX from FUN_0073efc0 (decompiler void is wrong)
//
// OOM: still releases old, stores null, still calls unserialize(null).
//      Differs from phy twin 0x004372a0 (which preserves slot and returns -1).
//
// BODY: 0x004373b0–0x00437419 exclusive (105 B). Dual: accept-with-gaps.
// =============================================================================

#include <cstdint>

struct RefCountedVtbl {
  void (*fn0)(void* self);
  void (*on_first_ref)(void* self);  // +4 → FUN_0056f570 nop
  void (*destroy)(void* self);       // +8 → FUN_00464890
};

struct GfxMorphWeightArray {
  RefCountedVtbl* vtbl;  // +0x00 PTR_FUN_00aa2f48
  int32_t refcount;      // +0x04
  uint32_t f08;          // +0x08
  uint32_t f0c;          // +0x0c
  uint32_t f10;          // +0x10
  uint32_t count;        // +0x14 (unserialize write)
  uint32_t token;        // +0x18 (unserialize write)
};

struct MorphHostWithSlot {
  uint32_t reserved0;            // +0x00
  GfxMorphWeightArray* slot;     // +0x04
};

// Unowned callees — declarations only.
extern "C" void* operator_new(uint32_t size);
// Hybrid: ECX = reader, stack = obj (Ghidra thiscall-shaped).
extern "C" uint32_t FUN_0073efc0(void* reader /*ECX*/, GfxMorphWeightArray* obj /*stack*/);

// Documentary signature — real ABI is register-heavy (see plate).
// Ports must: EBX=host, push reader, call, expect RET 4, status in EAX.
extern "C" uint32_t Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred(
    MorphHostWithSlot* host /*EBX*/,
    void* reader /*stack*/)
{
  auto* obj = static_cast<GfxMorphWeightArray*>(operator_new(0x1c));
  if (obj != nullptr) {
    obj->refcount = 0;
    // Bytes: MOV dword ptr [EAX], 0x00aa2f48
    obj->vtbl = reinterpret_cast<RefCountedVtbl*>(0x00aa2f48);
    obj->f08 = 0;
    obj->f0c = 0;
    obj->f10 = 0;
    obj->count = 0;
    obj->token = 0;
  }

  if (obj != nullptr) {
    obj->refcount += 1;
    if (obj->refcount == 1) {
      obj->vtbl->on_first_ref(obj);
    }
  }

  GfxMorphWeightArray* old = host->slot;
  if (old != nullptr) {
    old->refcount -= 1;
    if (old->refcount == 0) {
      old->vtbl->destroy(old);
    }
  }
  host->slot = obj;  // including null

  return FUN_0073efc0(reader, obj);
}
