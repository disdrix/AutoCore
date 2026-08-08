// =============================================================================
// CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred  (FUN_006c6c50)
// -----------------------------------------------------------------------------
// Stable ID: aa_006c6c50
// Address:   0x006c6c50–0x006c6c98 inclusive (73 B / 0x49); pad CC after
// Module:    autoassault.exe (image base 0x400000)
// System:    interaction-activation / CVOGPhysicsUtils area-query filter gate
// Generated: 2026-08-05 MEGA-039 dual seal
//            (decompile + disassemble_function + read_memory + callers/xrefs)
// Exactness: Behavior-preserving rewrite from decompile + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Leaf filter test used by dualed CVOGPhysicsUtils_GetObjectsInArea
// (0x004ea350) on the default AABB hit loop. For each broadphase hit, tests
// whether the object's type/category dword (hit+0x1c) passes the query's
// filter-flags word (GetObjectsInArea last arg) against a 32×32 bit matrix
// owned by ECX (this), base at this+0x1c.
//
// Early-out: if the upper 16 bits of (object_type ^ filter_flags) are zero
// AND object_type has a non-zero high word, force *out = false (no matrix read).
// Product English for that packing rule remains open → _Inferred suffix.
//
// Rejected scaffold: Named_CalleeOf_Named_VOG_DEBUG_STOP_006c6c50
// (VOG_DEBUG_STOP is the parent null-world fail string, not this leaf).
//
// Sole caller: FUN_004ea350 @ 0x004ea560 (UNCONDITIONAL_CALL).
// ABI: __thiscall ECX=this; stack out*, a, b; RET 0xC; leaf (no callees).

#include <cstdint>

// Filter bit-matrix shell (minimum layout sealed via body).
// Rows: 32 dwords starting at +0x1C; each dword holds 32 bits.
struct AreaQueryFilterBitMatrix_Inferred {
  // ... unknown fields @ +0x00 .. +0x18 ...
  // std::uint32_t bit_rows[32]; // @ +0x1C  (indexed by object_type & 0x1F)
};

// __thiscall: ECX = this; stack out*, object_type, filter_flags; RET 0xC
// Result: *out = 1 if pass, 0 if reject. EAX left holding out* (parent CMP [EAX],0).
extern "C" void __thiscall CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred(
    AreaQueryFilterBitMatrix_Inferred *self,
    std::uint8_t *out,
    std::uint32_t object_type,
    std::uint32_t filter_flags)
{
  // Same non-zero high-16 → hard reject (no matrix probe).
  if ((((object_type ^ filter_flags) & 0xffff0000u) == 0) &&
      ((object_type & 0xffff0000u) != 0)) {
    *out = 0;
    return;
  }

  const std::uint32_t row = object_type & 0x1fu;
  const std::uint32_t bit = filter_flags & 0x1fu;
  const auto *base = reinterpret_cast<const std::uint8_t *>(self);
  const std::uint32_t dword =
      *reinterpret_cast<const std::uint32_t *>(base + 0x1c + row * 4);
  *out = (dword & (1u << bit)) != 0 ? 1 : 0;
}
