// =============================================================================
// CVOGObjectiveRequirement_Deliver_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00610bc0
// Address:   0x00610bc0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-29 dual A/B refine (type=3, +0x23 default sealed)
// Exactness: Behavior-preserving rewrite of image + decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Construct a Deliver objective requirement (req type 3).
//   Sets Deliver vtable PTR_FUN_009e0f24 and field defaults.
//
// SEALED:
//   - *(int32*)(this + 0x0c) = 3
//   - *(uint8*)(this + 0x23) = 1  (require-count / enforce-qty default)
//
// RTTI: .?AVCVOGObjectiveRequirement_Deliver@@ @ 0x00afe97c

extern void* PTR_FUN_009e0f24;
extern void* PTR_LAB_009e3bac;

// Base requirement ctor (FUN_00637da0): *this = PTR_LAB_009e3bac; this[1] = owner.
void __thiscall FUN_00637da0(void* self, void* owner);

struct CVOGObjectiveRequirement_Deliver {
  void* vtable;           // +0x00
  void* owner;            // +0x04  (base)
  // +0x08 progress slot — not written by this ctor
  int32_t type;           // +0x0c  SEALED default 3
  int32_t cbidItem;       // +0x10  default -1
  int32_t numToDeliver;   // +0x14  default 0
  int32_t targetNpcCbid; // +0x18  default -1
  int32_t continentId;    // +0x1c  default -1
  uint8_t giveItemAtStart;     // +0x20  default 1
  uint8_t takeItemAtEnd;       // +0x21  default 1
  uint8_t npcTargetCompletes;  // +0x22  default 1
  uint8_t requireCount;        // +0x23  SEALED default 1
};

CVOGObjectiveRequirement_Deliver* __thiscall
CVOGObjectiveRequirement_Deliver_ctor(
    CVOGObjectiveRequirement_Deliver* self,
    void* owner)
{
  FUN_00637da0(self, owner);

  self->giveItemAtStart = 1;
  self->takeItemAtEnd = 1;
  self->npcTargetCompletes = 1;
  self->requireCount = 1;              // +0x23 default SEALED

  self->vtable = &PTR_FUN_009e0f24;
  self->type = 3;                      // requirement type SEALED
  self->cbidItem = -1;
  self->numToDeliver = 0;
  self->targetNpcCbid = -1;
  self->continentId = -1;

  return self;
}
