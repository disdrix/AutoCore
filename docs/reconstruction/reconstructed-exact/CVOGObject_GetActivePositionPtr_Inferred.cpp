// =============================================================================
// CVOGObject_GetActivePositionPtr_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Resolve the active position source pointer for a CVOG object:
//           local override (+0x240), phys body (+0xb0 off phys base), or
//           embedded component pose (typeOff+0x84).
//
// Address:  0x004c3ac0  (autoassault.exe, image base 0x400000)
// Body:     0x004c3ac0–0x004c3aef (48 bytes)
// Stable:   aa_004c3ac0
// System:   object pose
// Ghidra:   FUN_004c3ac0
//
// ABI:      __fastcall / thiscall-shape  float* GetActivePositionPtr(Object *self)
//           ECX=self; bare RET
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W20-O seal).
// =============================================================================

#include <cstdint>

struct CVOGObject_PosShell {
  // +0x00 vtbl / base
  // +0x04 MI helper → type offset chain
  // +0x08 phys / action link (nullable)
  // +0x240 local position override (vec4; written by FUN_004c3a40/FUN_004cb3e0)
};

/* CVOGObject_GetActivePositionPtr_Inferred — leaf position source selector.

   Parameters:
     self: CVOG object (ECX)

   Returns:
     Pointer to active position floats:
       - self+0x240 when (component+0xb8 & 7)==0
       - *( *(self+8)+0x3c ) + 0xb0 when phys link non-null
       - self + typeOff + 0x84 otherwise

   Side effects: none (leaf). */

std::uint8_t *__fastcall CVOGObject_GetActivePositionPtr_Inferred(void *self)
{
  auto *base = reinterpret_cast<std::uint8_t *>(self);
  int typeOff = *reinterpret_cast<int *>(
      *reinterpret_cast<std::uint8_t **>(base + 4) + 4);

  if ((*(base + typeOff + 0xb8) & 7) == 0) {
    return base + 0x240;
  }

  void *phys = *reinterpret_cast<void **>(base + 8);
  if (phys != nullptr) {
    auto *physBase = *reinterpret_cast<std::uint8_t **>(
        reinterpret_cast<std::uint8_t *>(phys) + 0x3c);
    return physBase + 0xb0;
  }

  return base + typeOff + 0x84;
}
