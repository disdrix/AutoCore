// =============================================================================
// Skill_InsertActiveCastBinding_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00518ca0
// Address:   0x00518ca0–0x00518ce4  (0x44 bytes; autoassault.exe @ 0x400000)
// System:    skills-abilities
// Dual A/B:  2026-07-29 W24-H
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Pack (skillId, TFID16) and insert-or-find into the active-cast binding map
//   at mapOwner+0x68 (lazy shell FUN_00518c20 / leave-FUN).
//
// ABI (byte-sealed)
//   __thiscall  ret 0x14
//   ECX = mapOwner
//   stack: skillId, tfid0, tfid1, tfid2, tfid3
//
// Callees
//   FUN_00518c20  — lazy map* @ owner+0x68
//   FUN_004cbe20  — map insert-or-find (key int @ node+0x10; isnil @+0x29)
//
// Sole static caller
//   Skill_HB_FireTail_FxTargetAndPeriodStamp @ 0x00578c55
//   (target vtbl+0x214 + HB flag +0x639 bit 0x02; TFID from HB+0x678; skillId HB+0x620)
//
// Rejected alias
//   Named_CalleeOf_Skill_Skill_d_has_invalid_frequency_d_00518ca0
// =============================================================================

#include <cstdint>

extern "C" void *FUN_00518c20(void *mapOwner); // __fastcall / thiscall unary
extern "C" void FUN_004cbe20(void *map, void *outPair, const void *value); // thiscall

// Local value_type layout (24 B) matching node pair @ +0x10:
//   +0  int  skillId
//   +4  int  pad          (unwritten by this body)
//   +8  u32  tfid[4]      (16 B; consumers read node+0x18…+0x24)

void __thiscall Skill_InsertActiveCastBinding_Inferred(
    void *mapOwner,
    int skillId,
    uint32_t tfid0,
    uint32_t tfid1,
    uint32_t tfid2,
    uint32_t tfid3)
{
  uint32_t local[6];
  uint32_t outPair[2];

  local[0] = (uint32_t)skillId;
  // local[1] left uninitialized (pair pad / node+0x14)
  local[2] = tfid0;
  local[3] = tfid1;
  local[4] = tfid2;
  local[5] = tfid3;

  void *map = FUN_00518c20(mapOwner);
  FUN_004cbe20(map, outPair, local);
  // insert result discarded
}
