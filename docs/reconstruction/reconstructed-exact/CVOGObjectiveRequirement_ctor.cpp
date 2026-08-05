// =============================================================================
// CVOGObjectiveRequirement_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00637da0
// Address:   0x00637da0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-29 W17-Q dual A/B seal; supersedes scaffold FUN_00637da0.cpp
// Exactness: Behavior-preserving rewrite of decompiler + body bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Shared base constructor for RTTI class CVOGObjectiveRequirement:
//     - *this = base vtable PTR_LAB_009e3bac (0x009e3bac)
//     - this+0x04 = parent (owning objective / table parent)
//   Subclass ctors (Collect, Deliver, Kill, …) call this then overwrite vfptr
//   and write RequirementType at +0x0c plus type-specific fields.
//
// ABI: MSVC __thiscall; stack parent; RET 4; returns this in EAX.
// RTTI: .?AVCVOGObjectiveRequirement@@ @ 0x00afe9dc
//
// Dual: reviews/A|B_aa_00637da0_CVOGObjectiveRequirement_ctor.md
// Bytes: 8B C1  8B 4C 24 04  C7 00 AC 3B 9E 00  89 48 04  C2 04 00
// =============================================================================

#include <cstdint>

// Base requirement vtable (temporary; subclasses overwrite *this)
static void* const kBaseRequirementVtable = reinterpret_cast<void*>(0x009e3bac);

void* __thiscall CVOGObjectiveRequirement_ctor(void* self, void* parent)
{
  auto* p = reinterpret_cast<std::uint32_t*>(self);

  *reinterpret_cast<void**>(p) = kBaseRequirementVtable; // +0x00 vfptr
  p[1] = reinterpret_cast<std::uint32_t>(parent);        // +0x04 parent

  return self;
}
