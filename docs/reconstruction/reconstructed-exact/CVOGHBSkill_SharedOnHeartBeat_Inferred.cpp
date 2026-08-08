// =============================================================================
// CVOGHBSkill_SharedOnHeartBeat_Inferred  (FUN_0061b6f0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0061b6f0
// Address:   0x0061b6f0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / CVOGHB skill heartbeat
// Generated: 2026-08-04 WQ9D-C dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Shared skill-HB OnHeartBeat pulse installed at vtbl+0x08 for many
// CVOGHBSkill_* classes (Chain, InverseChain, Aggregate, …) and called as a
// subroutine by specialized overrides (Virus OnHB, range-gated wrapper 0061ba80).
//
// High-level CF:
//   1) FUN_005787a0 → out status (reschedule / health gate path)
//   2) ++this[+0x6c8] pulse counter
//   3) if status != 0x10 (DAT_00af4bd0) && !flag@+0x20 &&
//         (state@+0x0c > 1 || state@+0x0c == -1000):
//        optional combat side-effects scaled by this[+0x6c4]:
//          - short@+0x74 damage via owner vtbl+0x214 → vtbl+0x88 + TFID@+0x668
//          - float@+0x114 heat (00589bc0) via Object_ResolveTargetViaReaction
//          - flag@+0x44 → flag8 self/linked gate → this.vtbl+0x18(1,1) hard stop
//          - bit2 @+0x648 → HP apply (00589c70)
//          - float@+0x144 → shield/pool (00589d90)
//          - bit7 @+0x649 → creature short apply + floater (0058cc40)
//          - bit0 @+0x648 → multi-arg apply (0058d8e0)
//          - float@+0x110 → phys impulse (0058c3b0) with DAT_00d02ac0
//        this.vtbl+0x50() post-pulse virtual
//   4) *pOutStatus = status; ret 4
//
// Not cast entry / RequestCast; post-cast HB tick residual.

#include <cstdint>

extern "C" void FUN_005787a0(std::uint32_t *pStatus /* thiscall ECX = HB */);
extern "C" void *FUN_00578270(/* owner + scaled args — resolve path */);
extern "C" void FUN_00589bc0(/* heat apply */);
extern "C" void FUN_00589c70(/* HP apply */);
extern "C" void FUN_00589d90(/* shield/pool apply */);
extern "C" void FUN_0058cc40(/* short apply + floater */);
extern "C" void FUN_0058d8e0(/* multi-arg combat apply */);
extern "C" void FUN_0058c3b0(/* phys impulse from hit */);
extern "C" char FUN_005134e0(/* Object_HasFlag8SelfOrLinked thiscall */);
extern "C" void *FUN_0061b960(/* thiscall: copy TFID_16 from this+0x668 */);

// Globals (image)
extern std::uint32_t DAT_00af4bd0;   /* status sentinel 0x10 */
extern float g_flZero;
extern void *DAT_00d02ac0;

// __thiscall: ECX = skill HB*; stack = uint32_t *pOutStatus; RET 4
void __thiscall CVOGHBSkill_SharedOnHeartBeat_Inferred(
    std::int32_t *thisHb, std::uint32_t *pOutStatus)
{
  char cFlag8;
  int iObj;
  int *piObj;
  std::uint32_t *puTfid;
  void *uResolved;
  std::uint32_t localStatus;
  int iImpulseScale;
  std::uint8_t auTfid[16];

  /* thiscall ECX = thisHb already; Ghidra shows FUN_005787a0(&localStatus) */
  FUN_005787a0(&localStatus);

  thisHb[0x1b2] = thisHb[0x1b2] + 1; /* +0x6c8 pulse counter */

  if ((localStatus != DAT_00af4bd0) &&
      ((char)thisHb[8] == '\0') && /* +0x20 */
      ((1 < thisHb[3] || (thisHb[3] == -1000)))) { /* +0x0c state */

    if ((short)thisHb[0x1d] != 0) { /* +0x74 */
      iObj = (**(int (**)())(*(int *)thisHb[6] + 0x214))();
      if (iObj != 0) {
        piObj = (int *)(**(int (**)())(*(int *)thisHb[6] + 0x214))();
        puTfid = (std::uint32_t *)FUN_0061b960(auTfid);
        (**(void (**)(int, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t))(
             *piObj + 0x88))(
            (int)((float)(int)(short)thisHb[0x1d] * (float)thisHb[0x1b1]),
            puTfid[0], puTfid[1], puTfid[2], puTfid[3]);
      }
    }

    if ((float)thisHb[0x45] != g_flZero) { /* +0x114 heat scale */
      uResolved = FUN_00578270(
          thisHb[6], (float)thisHb[0x1b1] * (float)thisHb[0x45]);
      FUN_00589bc0(uResolved);
    }

    if ((char)thisHb[0x11] != '\0') { /* +0x44 */
      iObj = (**(int (**)())(*(int *)thisHb[6] + 0x19c))();
      if (iObj == 0) {
        cFlag8 = FUN_005134e0();
        if (cFlag8 == '\0') {
          (**(void (**)(int, int))(*thisHb + 0x18))(1, 1);
        }
      } else {
        cFlag8 = FUN_005134e0();
        if (cFlag8 == '\0') {
          (**(void (**)(int, int))(*thisHb + 0x18))(1, 1);
        }
      }
    }

    if ((*(std::uint8_t *)(thisHb + 0x192) & 2) != 0) { /* +0x648 bit1 */
      uResolved = FUN_00578270(
          thisHb[6], (float)thisHb[0x1b1] * (float)thisHb[0x18], 0);
      FUN_00589c70(uResolved);
    }

    if ((float)thisHb[0x51] != g_flZero) { /* +0x144 */
      uResolved = FUN_00578270(
          thisHb[6], (float)thisHb[0x1b1] * (float)thisHb[0x51]);
      FUN_00589d90(uResolved);
    }

    if ((*(std::uint8_t *)((int)thisHb + 0x649) & 0x80) != 0) {
      uResolved = FUN_00578270(
          thisHb[6], (float)thisHb[0x1b1] * (float)thisHb[0x19]);
      FUN_0058cc40(uResolved);
    }

    if ((*(std::uint8_t *)(thisHb + 0x192) & 1) != 0) { /* +0x648 bit0 */
      uResolved = FUN_00578270(
          thisHb[6], thisHb + 9, thisHb[0x1a2], thisHb[0x1a8], thisHb[0x1b2]);
      FUN_0058d8e0(uResolved);
    }

    if ((float)thisHb[0x44] != g_flZero) { /* +0x110 impulse scale */
      iImpulseScale = thisHb[0x44];
      uResolved = FUN_00578270(thisHb[6], iImpulseScale, &DAT_00d02ac0);
      FUN_0058c3b0(uResolved);
    }

    (**(void (**)())(*thisHb + 0x50))(); /* post-pulse virtual */
  }

  *pOutStatus = localStatus;
  return;
}

// Ghidra alias
void __thiscall FUN_0061b6f0(std::int32_t *param_1, std::uint32_t *param_2)
{
  CVOGHBSkill_SharedOnHeartBeat_Inferred(param_1, param_2);
}
