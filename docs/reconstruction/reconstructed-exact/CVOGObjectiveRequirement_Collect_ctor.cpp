// =============================================================================
// CVOGObjectiveRequirement_Collect_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00611690
// Address:   0x00611690  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-29 dual A/B seal (type=2); supersedes scaffold FUN_00611690.cpp
// Exactness: Behavior-preserving rewrite of decompiler + body bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Construct CVOGObjectiveRequirement_Collect:
//     - base FUN_00637da0(parent)  → vfptr base, this+0x04 = parent
//     - *this = Collect vtable 0x009e12c4
//     - this+0x0c = RequirementType 2
//     - CBID +0x10 = -1; NumToCollect +0x14 = 0; OptionalDropPercent +0x48 = 0.0f
//     - remaining pads -1 / 0 as body stores
//
// ABI: __thiscall; stack parent; RET 4; returns this.
// Factory: FUN_00547050 matches u"collect", alloc 0x68, CALL 0x00611690.
//
// Dual: reviews/A|B_aa_00611690_CVOGObjectiveRequirement_Collect_ctor.md
// =============================================================================

#include <cstdint>

// External: shared objective-requirement base ctor @ 0x00637da0
extern "C" void __thiscall FUN_00637da0(void* self, void* parent);

// Collect vtable (RTTI CVOGObjectiveRequirement_Collect)
static void* const kCollectVtable = reinterpret_cast<void*>(0x009e12c4);

void* __thiscall CVOGObjectiveRequirement_Collect_ctor(void* self, void* parent)
{
  auto* p = reinterpret_cast<std::uint32_t*>(self);

  FUN_00637da0(self, parent);

  // Body order (bytes @ 0x00611690): after base, set CBID sentinel, then vtable + type.
  p[4] = 0xFFFFFFFFu;                         // +0x10 collectReqItemCbid
  *reinterpret_cast<void**>(p) = kCollectVtable;
  p[3] = 2u;                                  // +0x0c RequirementType = Collect

  *reinterpret_cast<std::uint8_t*>(reinterpret_cast<char*>(p) + 0x18) = 0;
  p[5] = 0u;                                  // +0x14 NumToCollect

  p[8]  = 0xFFFFFFFFu; // +0x20
  p[9]  = 0xFFFFFFFFu; // +0x24
  p[10] = 0xFFFFFFFFu; // +0x28
  p[11] = 0xFFFFFFFFu; // +0x2c
  p[12] = 0xFFFFFFFFu; // +0x30
  p[13] = 0xFFFFFFFFu; // +0x34
  p[14] = 0xFFFFFFFFu; // +0x38
  p[15] = 0xFFFFFFFFu; // +0x3c
  p[16] = 0xFFFFFFFFu; // +0x40
  p[17] = 0xFFFFFFFFu; // +0x44

  p[0x19] = 0xFFFFFFFFu; // +0x64
  p[0x14] = 0xFFFFFFFFu; // +0x50
  p[0x15] = 0xFFFFFFFFu; // +0x54
  p[0x17] = 0xFFFFFFFFu; // +0x5c
  p[0x18] = 0xFFFFFFFFu; // +0x60

  p[7] = 0u;             // +0x1c

  // +0x48 OptionalDropPercent — body uses movss of zero (not integer store)
  *reinterpret_cast<float*>(reinterpret_cast<char*>(p) + 0x48) = 0.0f;

  *reinterpret_cast<std::uint8_t*>(reinterpret_cast<char*>(p) + 0x19) = 0;
  *reinterpret_cast<std::uint8_t*>(reinterpret_cast<char*>(p) + 0x58) = 0;

  return self;
}
