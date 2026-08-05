// =============================================================================
// Client_RefreshInteractPromptTarget_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_009210e0
// Address:   0x009210e0–0x00921355  (autoassault.exe, image base 0x400000)
// System:    interaction-activation
// Generated: 2026-07-29 W18-L dual A/B seal; supersedes scaffold FUN_009210e0.cpp
// Exactness: Behavior-preserving rewrite of decompiler + sealed constants. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Periodic proximity interact refresh: pick a nearby world object (prefer
//   current select DAT_00d1d888 within 15 units, else gather cascade) and update
//   the "Press <key> to …" prompt host via FUN_008a81a0.
//   Does NOT send UseObject (0x2072) — chrome/target only.
//
// ABI: stack formal cleaned by RET 4 (caller pushes client this; body unused).
//      Selected object left in ESI for FUN_008a81a0 (ESI-this convention).
// Sole caller: FUN_009216e0 (timer tick after vtbl+0x478).
//
// Dual: reviews/A|B_aa_009210e0_Client_RefreshInteractPromptTarget_Inferred.md
// =============================================================================

#include <cstdint>

struct TFID_16 {
  std::uint32_t dwCoidLo;
  std::uint32_t dwCoidHi;
  std::uint8_t  bGlobal;
  std::uint8_t  bPad0, bPad1, bPad2, bPad3, bPad4, bPad5, bPad6;
};

// Globals (Ghidra names)
extern int *DAT_00d1b8c8;          // prompt / UI host
extern int  DAT_00d1b6d8;          // local character base
extern int *DAT_00d1d888;          // current interact select
extern int  DAT_00d1b644;          // world / client mgr
extern std::uint32_t DAT_00a158b8; // null TFID lo
extern std::uint32_t DAT_00a158bc; // null TFID hi
extern std::uint32_t DAT_00a158c0;
extern std::uint32_t DAT_00a158c4;
extern float DAT_00aaaca4;         // 225.0f = 15^2

// Callees
extern "C" void *Object_ResolveFromTFID(TFID_16 *pTfid);
extern "C" void  Client_MaybeShowFirstTimeTip(int tipId);
extern "C" void  FUN_0058cd60(TFID_16 *out, int a, int world, int selfAdj,
                              float *origin, float radius, int f1, int mode,
                              int fa, int fb, int fc);
extern "C" void  Skill_GatherTargetsInArea(TFID_16 *out, int a, int world, int selfAdj,
                                           float *origin, float radius, int f1, int mode,
                                           int filterA, int b, int c, int d, int e, int f,
                                           float g);
extern "C" void *Client_FindFirstObjectInRadius(float radius); // FUN_009197a0
extern "C" void  FUN_008a81a0(int *promptHost); // uses ESI = target object*

// Stack formal present (RET 4) but unused — matches FUN_009216e0 PUSH ESI.
extern "C" void Client_RefreshInteractPromptTarget_Inferred(void * /*client_unused*/)
{
  char cVar1;
  float *pfVar2;
  int iVar3;
  int *piVar4;
  void *pvVar5;
  float fStack_50, fStack_4c, fStack_48, fStack_44;
  TFID_16 aTStack_40[3];

  if (DAT_00d1b8c8 == (int *)0x0) {
    return;
  }
  cVar1 = (**(code **)(*DAT_00d1b8c8 + 0x3d8))();
  if (cVar1 == '\0') {
    return;
  }

  // Seed null TFID template
  aTStack_40[0].dwCoidLo = DAT_00a158b8;
  aTStack_40[0].bGlobal  = (std::uint8_t)DAT_00a158c0;
  aTStack_40[0].bPad0    = (std::uint8_t)(DAT_00a158c0 >> 8);
  aTStack_40[0].bPad1    = (std::uint8_t)(DAT_00a158c0 >> 16);
  aTStack_40[0].bPad2    = (std::uint8_t)(DAT_00a158c0 >> 24);
  aTStack_40[0].bPad3    = (std::uint8_t)DAT_00a158c4;
  aTStack_40[0].bPad4    = (std::uint8_t)(DAT_00a158c4 >> 8);
  aTStack_40[0].bPad5    = (std::uint8_t)(DAT_00a158c4 >> 16);
  aTStack_40[0].bPad6    = (std::uint8_t)(DAT_00a158c4 >> 24);
  aTStack_40[0].dwCoidHi = DAT_00a158bc;

  // Local player position (adj-this + vtbl+0x1a0)
  pfVar2 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +
                                         DAT_00d1b6d8) + 0x1a0))();
  fStack_50 = *pfVar2;
  fStack_4c = pfVar2[1];
  fStack_48 = pfVar2[2];
  fStack_44 = pfVar2[3];

  // Prefer current select if valid and within 15 units (dist² ≤ 225)
  if ((((DAT_00d1d888 == (int *)0x0) ||
       (iVar3 = (**(code **)(*DAT_00d1d888 + 0x210))(0), iVar3 == DAT_00d1b6d8)) ||
      (pfVar2 = (float *)(**(code **)(*DAT_00d1d888 + 0x1a0))(),
       DAT_00aaaca4 <
       (pfVar2[2] - fStack_48) * (pfVar2[2] - fStack_48) +
       (pfVar2[1] - fStack_4c) * (pfVar2[1] - fStack_4c) +
       (*pfVar2 - fStack_50) * (*pfVar2 - fStack_50))) ||
     (piVar4 = DAT_00d1d888, DAT_00d1d888 == (int *)0x0)) {
    if (DAT_00d1b6d8 == 0) {
      iVar3 = 0;
    } else {
      iVar3 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8;
    }
    FUN_0058cd60(aTStack_40, 0, DAT_00d1b644, iVar3, &fStack_50,
                 15.0f /*0x41700000*/, 1, /*mode*/ 6, 0, 0, 0);
    piVar4 = (int *)Object_ResolveFromTFID(aTStack_40);
    if (piVar4 != (int *)0x0) goto LAB_have_candidate;
  } else {
LAB_have_candidate:
    Client_MaybeShowFirstTimeTip(3);
    if (piVar4 != (int *)0x0) goto LAB_update_prompt;
  }

  // Fallback cascade: living interactables → special character filter → hash pick
  iVar3 = DAT_00d1b6d8;
  if (DAT_00d1b6d8 != 0) {
    iVar3 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8;
  }
  Skill_GatherTargetsInArea(aTStack_40, 0, DAT_00d1b644, iVar3, &fStack_50,
                            15.0f, 1, /*mode*/ 3, 0, 0, 0, 1, 0, 0, -1.0f /*0xbf800000*/);
  pvVar5 = Object_ResolveFromTFID(aTStack_40);
  if (pvVar5 == (void *)0x0) {
    pvVar5 = (void *)0x0;
    if (*(char *)(DAT_00d1b644 + 0xf5) != '\0') {
      iVar3 = DAT_00d1b6d8;
      if (DAT_00d1b6d8 != 0) {
        iVar3 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8;
      }
      Skill_GatherTargetsInArea(aTStack_40, 0, DAT_00d1b644, iVar3, &fStack_50,
                                15.0f, 1, /*mode*/ 7, /*filterA*/ 0x14, 0, 0, 1, 0, 0,
                                -1.0f);
      pvVar5 = Object_ResolveFromTFID(aTStack_40);
    }
    if (pvVar5 == (void *)0x0) {
      pvVar5 = Client_FindFirstObjectInRadius(15.0f);
    }
  }
  // ESI = pvVar5 at call site (decompiler folds into FUN_008a81a0 unaff_ESI)

LAB_update_prompt:
  FUN_008a81a0(DAT_00d1b8c8);
}
