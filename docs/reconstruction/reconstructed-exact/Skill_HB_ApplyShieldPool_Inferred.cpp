// =============================================================================
// Skill_HB_ApplyShieldPool_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00589d90
// Address:   0x00589d90  (autoassault.exe, image base 0x400000)
// Body:      0x00589d90–0x00589e5c inclusive (0xCD / 205 B); pad CC after
// System:    skills-abilities
// Agent:     MEGA-007 OWN-ONLY dual (2026-08-05)
// Exactness: Behavior-preserving rewrite of decompiler + sealed assembly CF.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Runtime:   not Confirmed (Terminal false; no Launcher).
// =============================================================================
//
// PURPOSE
//   Skill HB helper: resolve a combat host to a vehicle combat pool, then apply
//   a shield-pool delta (absolute int trunc of float, or fraction of max when
//   amount is in [-1, 1]). Clamps current shield to [0, max], stores at +0x144,
//   returns the actual applied delta (new - old) or 0 if unchanged / unresolved.
//
// ABI (sealed via disassemble_function + call-site ADD ESP,0xC)
//   cdecl; no ECX this.
//   arg0  void* fallbackHost     [ESP+4]
//   arg1  void* preferredHost    [ESP+8]
//   arg2  float amount           [ESP+0xC]
//   return int delta in EAX
//   epilogue: bare RET (C3) — caller cleans 0xC
//
// CONSTANTS (read_memory)
//   DAT_00aaa668 @ 0x00aaa668 = -1.0f
//   g_flOne      @ 0x00a0f2a0 =  1.0f
//
// FIELD PLATE (matches Vehicle_SetCurrentShield 0x00419140)
//   pool+0x144 = nCurrentShield
//   pool+0x148 = nMaxShield
//
// VIRTUALS
//   host+vtbl+0x19c  resolve owner / combat graph entry
//   component+vtbl+0x1d4  get vehicle combat pool*
//   preferredHost+0xAC (param_2[0x2b]) secondary host fallback
//
// CALLERS (3 UNCONDITIONAL_CALL)
//   FUN_0061b6f0 @ 0x0061b88f  (skill HB tick; period*shieldAmount)
//   FUN_00618270 @ 0x006185fb  (peer apply path)
//   site 0x0061be96             (orphan; no bound function)
//
// SIBLINGS (not dualled here)
//   0x00589bc0 Skill_HB_ApplyHeatDelta family
//   0x00589c70 Skill_HB_ApplyHpDelta family
//   0x0058cc40 Skill_HB_ApplyShortAndFloater family
// =============================================================================

extern "C" float DAT_00aaa668; // -1.0f @ 0x00aaa668
extern "C" float g_flOne;      //  1.0f @ 0x00a0f2a0

// Ghidra FUN_00589d90
int Skill_HB_ApplyShieldPool_Inferred(int *param_1, int *param_2, float param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;

  if (param_2 != (int *)0x0) {
    // preferred host: vtbl+0x19c
    iVar3 = (**(code **)(*param_2 + 0x19c))();
    if ((iVar3 != 0) &&
       (piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3),
        piVar5 != (int *)0x0))
      goto LAB_00589de7;
    // secondary object at +0xAC
    param_1 = (int *)param_2[0x2b];
  }
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar3 = (**(code **)(*param_1 + 0x19c))();
  if (iVar3 == 0) {
    return 0;
  }
  piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);
  if (piVar5 == (int *)0x0) {
    return 0;
  }
LAB_00589de7:
  // component vtbl+0x1d4 → combat pool (shield ints)
  iVar3 = (**(code **)(*piVar5 + 0x1d4))();
  if (iVar3 != 0) {
    iVar4 = (int)param_3; // CVTTSS2SI absolute
    if ((DAT_00aaa668 <= param_3) && (param_3 <= g_flOne)) {
      // fraction of max shield
      iVar4 = (int)((float)*(int *)(iVar3 + 0x148) * param_3);
    }
    iVar1 = *(int *)(iVar3 + 0x144); // current
    iVar2 = *(int *)(iVar3 + 0x148); // max
    iVar4 = iVar4 + iVar1;
    iVar6 = iVar4;
    if (iVar2 <= iVar4) {
      iVar6 = iVar2;
    }
    if (iVar6 < 1) {
      iVar4 = 0;
    }
    else if (iVar2 <= iVar4) {
      iVar4 = iVar2;
    }
    *(int *)(iVar3 + 0x144) = iVar4;
    if (iVar1 != iVar4) {
      return iVar4 - iVar1;
    }
  }
  return 0;
}
