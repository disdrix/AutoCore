// =============================================================================
// Client_CycleHostileTarget_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00943340
// Address:   0x00943340  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / client-input / target selection
// Generated: 2026-08-04 WQ9R-C dual seal (from live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra name: FUN_00943340
// =============================================================================

// PURPOSE:
// Cycle the client's hostile target selection within `range`.
// Sole caller: Client_Input_PollBoundActions — two key edges with range 110.0f
// and stepDir 0 (next) / 1 (prev) when a prior target slot (DAT_00d1d888) is set;
// otherwise sibling FUN_00943520 first-picks.
//
// Stages:
//   1. Early-out if local player flag +0x4f1.
//   2. Skill_GatherTargetsInArea mode=2 (hostile), max=50, score=-1.0f.
//   3. FUN_00930360 view-angle sort of TFID list.
//   4. Find current client+0x3048 in list; step ±1 with wrap.
//   5. Object_ResolveFromTFID + FUN_0093e120 to apply selection.

// ABI (sealed):
//   EAX = ClientShell* (custom; not ECX thiscall)
//   stack: float range, char stepDir
//   RET 8 (stdcall)
//   void

#include <cstdint>

struct TFID_16 {
  uint32_t dwCoidLo;
  uint32_t dwCoidHi;
  uint8_t bGlobal;
  uint8_t bPad0, bPad1, bPad2, bPad3, bPad4, bPad5, bPad6;
};

extern "C" uint32_t Skill_GatherTargetsInArea(
    TFID_16 *outList, int p2, uint32_t typeOrClone, int playerInterior,
    void *origin4, float range, int maxTargets, int gatherMode, int filterA,
    int chainRefresh, int allowSelfMode1, int filterB, int filterC,
    int sortByDistance, uint32_t scoreArg);

extern "C" void FUN_00930360(int client, TFID_16 *list, uint32_t *countInOut);
extern "C" void *Object_ResolveFromTFID(TFID_16 *tfid);
extern "C" void FUN_0093e120(void *object); // apply client selection
extern "C" uint8_t g_abTfidInvalid_A15870[16];

extern "C" void Client_CycleHostileTarget_Inferred(float range, char stepDir)
{
  // Register convention: client shell arrives in EAX (PollBoundActions call sites).
  int in_EAX; // ClientShell* — decompiler phantom; set by caller before CALL
  int iVar1;
  uint32_t uVar2;
  uint32_t *puVar3;
  uint32_t uVar4;
  TFID_16 *pTVar5;
  void *pvVar6;
  int iVar7;
  uint32_t uVar8;
  uint32_t uStack_354;
  uint32_t uStack_350;
  uint32_t uStack_34c;
  int local_344;
  uint32_t uStack_340;
  uint32_t uStack_33c;
  uint32_t uStack_338;
  uint32_t uStack_334;
  TFID_16 aTStack_330[50];

  iVar7 = *(int *)(in_EAX + 0xe98);
  if (*(char *)(iVar7 + 0x4f1) != 0) {
    return;
  }
  iVar1 = *(int *)(in_EAX + 0x3048); // current selection
  local_344 = iVar1;

  // Player interior + vtbl+0x1a0 → origin float4
  puVar3 = (uint32_t *)(**(int (**)())(
      *(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0x1a0))();
  uStack_340 = *puVar3;
  uStack_33c = puVar3[1];
  uStack_338 = puVar3[2];
  uStack_334 = puVar3[3];

  // Seed first TFID slot with invalid sentinel (byte-wise as decompiler)
  aTStack_330[0].dwCoidLo =
      (uint32_t)g_abTfidInvalid_A15870[0] |
      ((uint32_t)g_abTfidInvalid_A15870[1] << 8) |
      ((uint32_t)g_abTfidInvalid_A15870[2] << 16) |
      ((uint32_t)g_abTfidInvalid_A15870[3] << 24);
  aTStack_330[0].dwCoidHi =
      (uint32_t)g_abTfidInvalid_A15870[4] |
      ((uint32_t)g_abTfidInvalid_A15870[5] << 8) |
      ((uint32_t)g_abTfidInvalid_A15870[6] << 16) |
      ((uint32_t)g_abTfidInvalid_A15870[7] << 24);
  aTStack_330[0].bGlobal = g_abTfidInvalid_A15870[8];
  aTStack_330[0].bPad0 = g_abTfidInvalid_A15870[9];
  aTStack_330[0].bPad1 = g_abTfidInvalid_A15870[10];
  aTStack_330[0].bPad2 = g_abTfidInvalid_A15870[11];
  aTStack_330[0].bPad3 = g_abTfidInvalid_A15870[12];
  aTStack_330[0].bPad4 = g_abTfidInvalid_A15870[13];
  aTStack_330[0].bPad5 = g_abTfidInvalid_A15870[14];
  aTStack_330[0].bPad6 = g_abTfidInvalid_A15870[15];

  if (*(int *)(in_EAX + 0xe98) == 0) {
    iVar7 = 0;
  } else {
    iVar7 = *(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 4 +
            *(int *)(in_EAX + 0xe98);
  }

  uStack_354 = Skill_GatherTargetsInArea(
      aTStack_330, 0,
      *(uint32_t *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 0xa8 +
                    *(int *)(in_EAX + 0xe98)),
      iVar7, &uStack_340, range,
      /*maxTargets*/ 0x32, /*gatherMode hostile*/ 2, /*filterA*/ 0,
      /*chainRefresh*/ 0, /*allowSelfMode1*/ 1, /*filterB*/ 0, /*filterC*/ 0,
      /*sortByDistance*/ 0, /*scoreArg -1.0f*/ 0xbf800000);

  FUN_00930360(in_EAX, aTStack_330, &uStack_354);
  uVar2 = uStack_354;
  if (uStack_354 == 0) {
    return;
  }

  uVar4 = 0;
  uStack_354 = 0;
  if (iVar1 != 0) {
    uVar8 = 0;
    if (uVar2 != 0) {
      uStack_350 = *(uint32_t *)(iVar1 + 0x160);
      uStack_34c = *(uint32_t *)(iVar1 + 0x164);
      pTVar5 = aTStack_330;
      do {
        if ((pTVar5->dwCoidLo == uStack_350) &&
            (pTVar5->dwCoidHi == uStack_34c) &&
            (pTVar5->bGlobal == *(uint8_t *)(local_344 + 0x168))) {
          // stepDir==0 → +1 (next); stepDir!=0 → -1 (prev)
          uVar4 = (uint32_t)(stepDir == 0) * 2 + (uint32_t)-1 + uVar8;
          if ((int)uVar4 < 0) {
            uVar4 = uVar4 + uVar2;
          }
          goto found_step;
        }
        uVar8 = uVar8 + 1;
        pTVar5 = pTVar5 + 1;
      } while (uVar8 < uVar2);
      uVar4 = 0;
    found_step:
      if (uVar4 < uVar2)
        goto select_idx;
    }
    uVar4 = uVar4 - uVar2; // wrap high
  }
select_idx:
  if ((((aTStack_330[uVar4].dwCoidLo & aTStack_330[uVar4].dwCoidHi) !=
        0xffffffff) ||
       (aTStack_330[uVar4].bGlobal != 0)) &&
      (pvVar6 = Object_ResolveFromTFID(aTStack_330 + uVar4),
       pvVar6 != (void *)0x0)) {
    FUN_0093e120(pvVar6);
  }
}

// Compatibility alias
extern "C" void FUN_00943340(float range, char stepDir)
{
  Client_CycleHostileTarget_Inferred(range, stepDir);
}
