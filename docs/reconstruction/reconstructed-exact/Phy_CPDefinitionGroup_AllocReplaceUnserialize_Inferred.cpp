// =============================================================================
// Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred  (Ghidra: FUN_004372a0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004372a0
// Address:   0x004372a0  (autoassault.exe, image base 0x400000)
// System:    physics / phyCPDefinition — CPDG group alloc+slot-replace+unserialize
// Generated: 2026-08-04 W38-E dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate phyCPDefinitionGroupImpl (0x14), AddRef, release previous *outSlot,
//   store new pointer, unserialize CPDG chunk from stoChunkReader.
//
// ABI (bytes win over decompiler void/unaff formals):
//   EDI     = outSlot (T**)
//   stack+4 = stoChunkReader* reader
//   RET 4
//   return  = status in EAX; 0xFFFFFFFF on alloc failure (slot unchanged)
//
// RECOUNT PROTOCOL (shared with RefCountedSlot_ReleaseAndClear):
//   +0x00 vtbl
//   +0x04 refcount
//   vtbl+4 on first ref (nop FUN_0056f570 for this type)
//   vtbl+8 destroy on last release (FUN_00464890)
//
// BODY: 0x004372a0–0x0043733e exclusive (158 B). Dual: accept-with-gaps.
// =============================================================================

#include <cstdint>

struct RefCountedVtbl {
  void (*fn0)(void* self);
  void (*on_first_ref)(void* self);  // +4
  void (*destroy)(void* self);       // +8
};

struct PhyCPDefinitionGroup {
  RefCountedVtbl* vtbl;  // +0x00 PTR_FUN_00a9da68
  int32_t refcount;      // +0x04
  uint32_t unk08;        // +0x08 (ctor does not set — gap)
  void* container;       // +0x0c from FUN_004933f0
  uint32_t zero10;       // +0x10
};

// Unowned callees — declarations only.
extern "C" void* operator_new(uint32_t size);
extern "C" PhyCPDefinitionGroup* FUN_004371c0(void* mem);  // ctor
// Hybrid: stack = obj, EBX = reader (not a pure cdecl).
extern "C" uint32_t FUN_00989850(PhyCPDefinitionGroup* obj);

// Documentary signature — real ABI is register-heavy (see plate).
// Ports must: EDI=outSlot, push reader, call, expect RET 4, status in EAX.
extern "C" uint32_t Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred(
    PhyCPDefinitionGroup** out_slot /*EDI*/,
    void* reader /*stack*/)
{
  void* mem = operator_new(0x14);
  PhyCPDefinitionGroup* obj = nullptr;
  if (mem != nullptr) {
    obj = FUN_004371c0(mem);
  }

  if (obj == nullptr) {
    return 0xFFFFFFFFu;  // *out_slot unchanged
  }

  obj->refcount += 1;
  if (obj->refcount == 1) {
    obj->vtbl->on_first_ref(obj);
  }

  PhyCPDefinitionGroup* old = *out_slot;
  if (old != nullptr) {
    old->refcount -= 1;
    if (old->refcount == 0) {
      old->vtbl->destroy(old);
    }
  }
  *out_slot = obj;

  // Bytes: MOV EBX, reader; PUSH obj; CALL FUN_00989850
  (void)reader;
  return FUN_00989850(obj);
}
