// =============================================================================
// CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress
// -----------------------------------------------------------------------------
// Stable ID: aa_0060d630
// Address:   0x0060d630  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-08-04 WQ7R-H dual seal (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   UseItem requirement: on matched object-use event (caller FUN_0060df70,
//   events 9/10 after MatchTargetCore), if local player and eval not yet full:
//     - optional give CBID @+0x28 via FUN_005310a0 (log fail string)
//     - progress slot float += 1.0
//     - re-eval vtable+8
//     - optional remove primary inventory / destroy world object
//     - optional remove secondary inventory CBID @+0x2c
//     - if eval complete: optional GiveMission(@+0x4c) + give CBID @+0x48
//
// CLASS: CVOGObjectiveRequirement_UseItem (RTTI + vtable PTR_FUN_009dfc1c)
// ABI:   __thiscall; three stack args; ret 0x0C; AL = 0|1
// STRING: "Failed to give item %d to %I64d, objective %d mission: %S(%d)" @0x009e00a0
//
// CALLEES: CVOGReaction_GiveMission, CVOGReaction_RemoveInventoryItem,
//          FUN_005310a0 (give-by-cbid), FUN_007a4480 (log), FUN_004d0e90 (mark destroy)
// =============================================================================

#include <cstdint>

extern "C" float g_flOne;
extern "C" char FUN_005310a0(std::int32_t cbid, std::int32_t qty);
extern "C" void FUN_007a4480(int level, const char* fmt, ...);
extern "C" void CVOGReaction_RemoveInventoryItem(std::int32_t cbid, int qty);
extern "C" void CVOGReaction_GiveMission(std::int32_t missionId);
extern "C" void FUN_004d0e90(void* obj);

// this = UseItem requirement*
// pCharCtx = character/context object used for local gate + COID log
// pProgress = objective progress blob (slot floats; Eval reads same layout)
// pWorldObj = matched world object (destroy path; decompiler may show as unaff_EBX)
std::uint8_t __thiscall CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress(
    int* thisReq,
    int pCharCtx,
    int pProgress,
    int pWorldObj)
{
  // Local-player gate: entity+0x7e via (charCtx+4)->+4 + 0xa8 + charCtx
  if (*(char*)(*(int*)(*(int*)(*(int*)(pCharCtx + 4) + 4) + 0xa8 + pCharCtx) + 0x7e) == 0) {
    return 0;
  }

  // Eval not yet complete (vtable+8)
  char done = (*(char(**)(int*, int, int))(*thisReq + 8))(thisReq, pCharCtx, pProgress);
  if (done != 0) {
    return 0;
  }

  // Require live host object + nested payload @+0x250/+0x2b0
  if (*(int*)(pCharCtx + 0x250) == 0) {
    return 0;
  }
  if (*(int*)(*(int*)(pCharCtx + 0x250) + 0x2b0) == 0) {
    return 0;
  }

  // Optional give CBID @+0x28 before progress
  if (thisReq[10] != -1) {
    if (FUN_005310a0(thisReq[10], 1) == 0) {
      auto* nameNode = *(std::uint32_t**)(thisReq[1] + 0x14c);
      int base = *(int*)(*(int*)(pCharCtx + 4) + 4);
      FUN_007a4480(
          1,
          "Failed to give item %d to %I64d, objective %d mission: %S(%d)",
          thisReq[10],
          *(std::uint32_t*)(base + 0x164 + pCharCtx),
          *(std::uint32_t*)(base + 0x168 + pCharCtx),
          *(std::uint32_t*)(thisReq[1] + 0x10),
          nameNode + 1,
          *nameNode);
    }
  }

  // Slot float += 1.0  (slot index byte @ req+0x08; same as UseItem_Eval)
  unsigned slot = *(unsigned char*)((char*)thisReq + 8);
  float* pf = (float*)(pProgress + 4 + slot * 4);
  *pf = *pf + g_flOne;

  done = (*(char(**)(int*, int, int))(*thisReq + 8))(thisReq, pCharCtx, pProgress);

  // Optional primary remove / destroy world object
  if (((char)thisReq[7] != 0) && ((done != 0) || (*(char*)((int)thisReq + 0x25) == 0))) {
    if (*(char*)((int)thisReq + 0x1d) == 0) {
      CVOGReaction_RemoveInventoryItem(
          *(std::uint32_t*)(*(int*)(pWorldObj + 0xa8) + 0x34), 1);
    } else {
      *(std::uint32_t*)(pWorldObj + 0xcc) =
          (std::uint32_t)((*(char*)((int)thisReq + 0x26) != 0) + 1);
      FUN_004d0e90((void*)pWorldObj);
    }
  }

  // Optional secondary remove CBID @+0x2c when flag @+0x30
  if ((char)thisReq[0xc] != 0) {
    if ((done == 0) && (*(char*)((int)thisReq + 0x32) != 0)) {
      return 1;
    }
    CVOGReaction_RemoveInventoryItem(thisReq[0xb], 1);
  }

  // On eval complete: chain GiveMission + optional complete give
  if (done != 0) {
    if (thisReq[0x13] != -1) {
      CVOGReaction_GiveMission(thisReq[0x13]);
    }
    if ((thisReq[0x12] != -1) && (FUN_005310a0(thisReq[0x12], 1) == 0)) {
      auto* nameNode = *(std::uint32_t**)(thisReq[1] + 0x14c);
      int base = *(int*)(*(int*)(pCharCtx + 4) + 4);
      FUN_007a4480(
          1,
          "Failed to give item %d to %I64d, objective %d mission: %S(%d)",
          thisReq[0x12],
          *(std::uint32_t*)(base + 0x164 + pCharCtx),
          *(std::uint32_t*)(base + 0x168 + pCharCtx),
          *(std::uint32_t*)(thisReq[1] + 0x10),
          nameNode + 1,
          *nameNode);
    }
  }
  return 1;
}
