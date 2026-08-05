// =============================================================================
// Skill_RangeCheckTargetForResolveList_Inferred  (was FUN_0058c0a0)
// Address:  0x0058c0a0  Stable: aa_0058c0a0
// System:   skills-abilities
// Sole caller: Skill_ResolveTargetList @ 0x00550300
// Role: range helper AFTER Skill_FilterTargetForResolveList_Inferred.
//   Returns float10: g_flZero = fail (caller ORs outFlags bit 2);
//                    non-zero = pass (measured dist in band, or g_flOne auto-pass).
// Name INFERRED from sole caller + bit2 contract — not original symbol.
// Dual: reviews/A|B_aa_0058c0a0_Skill_RangeCheckTargetForResolveList_Inferred.md
// =============================================================================
// Exactness: Behavior-preserving rewrite of Ghidra decompile control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Signature (decompiler-derived; ResolveTargetList call site):
 *
 *   float10 Skill_RangeCheckTargetForResolveList_Inferred(
 *       int *pTarget,      // candidate object (post vehicle remap)
 *       int *pSource,      // caster / source (ResolveTargetList param_4)
 *       float flRangeMin,  // skill+0x2c
 *       float flRangeMax,  // skill+0x28
 *       uint32_t skillArg34, // skill+0x34 → into pTarget vtbl+0x1c8
 *       char skillFlag5e7);  // skill+0x5e7
 *
 * Call site (ResolveTargetList):
 *   dist = Skill_RangeCheckTargetForResolveList_Inferred(
 *            piVar6, pSource,
 *            *(float*)(skill+0x2c), *(float*)(skill+0x28),
 *            *(uint32*)(skill+0x34), *(char*)(skill+0x5e7));
 *   if (dist == g_flZero) *outFlags |= 2;
 */

extern float g_flOne;
extern float g_flZero;
extern uint32_t DAT_00af32a0, DAT_00af32a4, DAT_00af32a8, DAT_00af32ac;
extern int DAT_00b04dd0, DAT_00b04dd4, DAT_00b04dd8, DAT_00b04ddc;
extern uint32_t DAT_00af3290;

// Callees kept as FUN_* until individually sealed.
extern "C" uint32_t FUN_00404a20(...);
extern "C" void FUN_004e8a40(...);
extern "C" int *FUN_00404c90(...);
extern "C" void FUN_004cb590(...);
extern "C" long double FUN_004e9aa0(...);
extern "C" char FUN_004f70f0(...);
extern "C" void FUN_00567ce0(...);

long double Skill_RangeCheckTargetForResolveList_Inferred(
    int *pTarget,
    int *pSource,
    float flRangeMin,
    float flRangeMax,
    uint32_t skillArg34,
    char skillFlag5e7)
{
  float fMeasured;
  char cTfidGate;
  int pSourcePhys;
  int iTmp;
  uint32_t uFlagOrXform;
  int *pParent;
  int *pVehicleBodyAsObj;
  int pVehicleLink;
  long double ldDist;
  float fVehicleOrScale;
  int iPos0, iPos1, iPos2, iPos3;
  uint32_t uX0, uX1, uX2, uX3;
  uint8_t auXformScratch[28];

  // --- Auto-pass: self or source is target's parent ---
  if ((pSource == pTarget) || (pSource == (int *)pTarget[0x2b])) {
LAB_auto_pass:
    return (long double)g_flOne;
  }

  pSourcePhys = (**(code **)(*pSource + 0x1c8))();
  pVehicleLink = 0;
  fVehicleOrScale = 0.0f;
  iTmp = (**(code **)(*pSource + 0x214))();
  if (iTmp != 0) {
    fVehicleOrScale = (float)(**(code **)(*pSource + 0x214))();
    pVehicleLink = *(int *)((int)fVehicleOrScale + 0x250);
    // Same vehicle body / occupant → auto-pass
    if ((((pVehicleLink != 0) &&
          (iTmp = (**(code **)(*pTarget + 0x1d4))(), iTmp != 0)) &&
         (iTmp = (**(code **)(*pTarget + 0x1d4))(), iTmp == pVehicleLink)) ||
        (iTmp = (**(code **)(*pTarget + 0x1d8))(),
         (float)iTmp == fVehicleOrScale))
      goto LAB_auto_pass;
  }

  // --- Parent/hardpoint ownership gate (type 0xe or parent==source) ---
  pParent = (int *)pTarget[0x2b];
  if ((pParent != (int *)0x0) &&
      ((*(int *)(pParent[0x2a] + 0x38) == 0xe || (pParent == pSource)))) {
    if (pVehicleLink == 0) {
      pVehicleBodyAsObj = (int *)0x0;
    } else {
      pVehicleBodyAsObj =
          (int *)(*(int *)(*(int *)(pVehicleLink + 4) + 4) + 4 + pVehicleLink);
    }
    if ((pParent == pVehicleBodyAsObj) &&
        (cTfidGate = FUN_004f70f0(pTarget[0x58], pTarget[0x59]),
         cTfidGate == '\0'))
      goto LAB_auto_pass;
    goto LAB_fail;
  }

  // No usable physics on source and no vehicle handle → auto-pass
  if (((pSourcePhys == 0) || (*(int *)(pSourcePhys + 8) == 0)) &&
      (pVehicleLink == 0))
    goto LAB_auto_pass;

  // Seed transform + position quads from globals
  uX0 = DAT_00af32a0;
  uX1 = DAT_00af32a4;
  uX2 = DAT_00af32a8;
  uX3 = DAT_00af32ac;
  iPos0 = DAT_00b04dd0;
  iPos1 = DAT_00b04dd4;
  iPos2 = DAT_00b04dd8;
  iPos3 = DAT_00b04ddc;

  if (((pVehicleLink == 0) || (fVehicleOrScale == 0.0f)) ||
      (*(char *)((int)fVehicleOrScale + 0x30c) == '\0')) {
    if (pSourcePhys != 0) {
      uFlagOrXform = FUN_00404a20(&uX0);
      FUN_004e8a40(uFlagOrXform);
      // Optional vehicle matrix when skill flag clear
      if (((fVehicleOrScale != 0.0f) &&
           (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)((int)fVehicleOrScale + 4) + 4) +
                                       0xac + (int)fVehicleOrScale) +
                             0x3c) +
                     0x4e8) == 1)) &&
          (skillFlag5e7 == '\0')) {
        FUN_00567ce0(&DAT_00af3290,
                     *(uint32_t *)((int)fVehicleOrScale + 0x11c));
        uFlagOrXform = FUN_00404a20();
        FUN_004cb590(uFlagOrXform);
        FUN_004e8a40(auXformScratch, &uX0);
      }
      goto LAB_extract_pos;
    }
  } else {
    uFlagOrXform = FUN_00404a20(&uX0);
    FUN_004e8a40(uFlagOrXform);
  LAB_extract_pos:
    pParent = (int *)FUN_00404c90();
    iPos0 = *pParent;
    iPos1 = pParent[1];
    iPos2 = pParent[2];
    iPos3 = pParent[3];
  }

  // Scale from source phys + presence flag for distance helper
  fVehicleOrScale = g_flOne;
  if (pSourcePhys == 0) {
  LAB_no_phys_flag:
    uFlagOrXform = 0;
  } else {
    pVehicleLink =
        (**(code **)(*(int *)(*(int *)(*(int *)(pSourcePhys + 4) + 4) + 4 +
                              pSourcePhys) +
                     0x19c))();
    if (pVehicleLink != 0) {
      pVehicleLink =
          (**(code **)(*(int *)(*(int *)(*(int *)(pSourcePhys + 4) + 4) + 4 +
                                pSourcePhys) +
                       0x19c))();
      fVehicleOrScale = *(float *)(pVehicleLink + 0x34);
    }
    pVehicleLink =
        (**(code **)(*(int *)(*(int *)(*(int *)(pSourcePhys + 4) + 4) + 4 +
                              pSourcePhys) +
                     0x210))(0);
    if (pVehicleLink == 0)
      goto LAB_no_phys_flag;
    uFlagOrXform = 1;
  }

  // Target-side transform prep, then distance measure
  uFlagOrXform =
      (**(code **)(*pTarget + 0x1c8))(&uX0, skillArg34, uFlagOrXform);
  ldDist = (long double)FUN_004e9aa0(&iPos0, fVehicleOrScale, flRangeMax,
                                    uFlagOrXform);
  fMeasured = (float)ldDist;
  if ((flRangeMin <= fMeasured) && (fMeasured <= flRangeMax)) {
    return (long double)fMeasured;
  }

LAB_fail:
  return (long double)g_flZero;
}
