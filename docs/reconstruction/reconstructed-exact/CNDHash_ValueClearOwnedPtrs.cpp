// =============================================================================
// CNDHash_ValueClearOwnedPtrs
// -----------------------------------------------------------------------------
// Stable ID: aa_00604e30
// Address:   0x00604e30–0x00604e84  (85 B / 0x55; autoassault.exe @ 0x400000)
// System:    container / CNDHash (medal family; nested value teardown for 009ce0a8)
// Dual A/B:  2026-07-29 W26-P
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Clear four owned heap pointer slots on a CNDHash node value object:
//   value+0x04, +0x08, +0x0C, +0x10. For each: if non-null, operator_delete
//   (cdecl, RETURNS), then zero the slot. Does not free `value` itself and
//   does not touch value+0.
//
// ABI
//   MSVC __thiscall (Ghidra labels __fastcall); ECX = value*; plain RET
//
// Callers
//   CNDHash_ReclaimAll_ValueOwning_009ce0a8 (FUN_0051bfb0) @ 0x0051bfe4
//   FUN_0051bd90 (scalar dtor stamp 009ce0a8) @ 0x0051bda3
//
// Related
//   Parent then operator_delete(value). Plain owning reclaim siblings
//   (009cefec / 009cefe4) skip this helper.
//
// DECOMPILER GAP
//   Ghidra marks operator_delete as noreturn — FALSE; zeros + next slots run.
//
// Rejected alias
//   Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00604e30
// =============================================================================

#include <cstdint>

extern void operator_delete(void *p);

// void __thiscall — bare ret
void __fastcall CNDHash_ValueClearOwnedPtrs(void *value)
{
  void *p;

  p = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(value) + 0x04);
  if (p != nullptr) {
    operator_delete(p); // RETURNS
  }
  *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(value) + 0x04) = nullptr;

  p = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(value) + 0x08);
  if (p != nullptr) {
    operator_delete(p);
  }
  *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(value) + 0x08) = nullptr;

  p = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(value) + 0x0c);
  if (p != nullptr) {
    operator_delete(p);
  }
  *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(value) + 0x0c) = nullptr;

  p = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(value) + 0x10);
  if (p != nullptr) {
    operator_delete(p);
  }
  *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(value) + 0x10) = nullptr;
}
