// =============================================================================
// CVOGHBSkill_Virus_OnHeartBeat
// -----------------------------------------------------------------------------
// Stable ID: aa_0061fdf0
// Address:   0x0061fdf0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Ghidra:    FUN_0061fdf0
// Dual:      2026-08-04 WQ9R-B OWN-ONLY (WQ-009 residual)
//
// Class:     CVOGHBSkill_Virus  (RTTI Confirmed ".?AVCVOGHBSkill_Virus@@")
// Slot:      vtbl PTR_FUN_009d14bc +0x0C (OnHeartBeat; base TryFire dispatches)
// Ctor:      FUN_0061f940
//
// Purpose: Heartbeat body for Virus skill HB:
//   1) Shared skill pulse FUN_0061b6f0
//   2) Resolve primary target (FUN_00578270); require vtbl+0x198()==0
//   3) Gates: world+0x7e flag, period counter this+0x10
//   4) RNG: (u16%100) > 25 (~75%) else skip multi-spread
//   5) Owner RTTI: CVOGCreature(+0x250!=0) OR CVOGPhysicsBase
//   6) Skill_GatherTargetsInArea mode=1 filterA=-1 (ally)
//   7) For each TFID: new Virus HB, Enqueue(world+0xe4ec), Start
//
// ABI:     __thiscall; stack uint32_t *pOutStatus; ret 4
// Exactness: Behavior-preserving CF (live decompile + read_memory).
// Bit-for-bit / runtime: OPEN.
// =============================================================================

#include <cstdint>

struct TFID_16 {
  std::uint32_t dwCoidLo;
  std::uint32_t dwCoidHi;
  std::uint32_t uGlobalAndPad;
  std::uint32_t uPadTail;
};

// Forward decls — roles from duals / image symbols
extern "C" void  FUN_0061b6f0(void *thisHb, std::uint32_t *pStatus);
extern "C" void *FUN_00578270(void *thisHb);
extern "C" void *Object_GetWorldPositionPtr(void *obj); // FUN_00404c90
extern "C" void  Skill_GatherTargetsInArea(
    TFID_16 *outList, int startIndex, void *queryArg, void *pSource,
    float *origin4, float range, int maxTargets, int gatherMode,
    std::uint32_t filterA, int chainRefresh, int allowSelf,
    int filterB, int filterC, int sortByDist, float scoreArg);
extern "C" int   TFID_NotEquals(const TFID_16 *a, const void *b);
extern "C" void *Object_ResolveFromTFID(const TFID_16 *id);
extern "C" void *operator_new(std::size_t n);
extern "C" void *FUN_0061f940( // CVOGHBSkill_Virus_ctor
    void *thisHb, void *pPrimary, void *pSkillBlob, void *pWorld,
    void *pNewTarget, void *pTfidArg, std::uint32_t arg7,
    int remainBudget, int remainPeriod);
extern "C" void  CVOGHBList_Enqueue(void *list, void *pAction);
extern "C" void  CVOGHBBase_Start(void *pAction);
extern "C" void *CVOGReaction_RandomUnitScalar(void);
extern "C" void  FUN_0051b720(void *rngHost, int count, void *dst);
extern "C" void *__RTDynamicCast(void *obj, long, void *from, void *to, int);
extern "C" float g_flZero;
extern "C" float DAT_00a0f524;     // 50.0f
extern "C" std::uint32_t DAT_009e2df0, DAT_009e2df4, DAT_009e2df8, DAT_009e2dfc;
extern "C" TFID_16 DAT_00d02af0;
extern "C" void *ExceptionList;
extern "C" void CVOGClonedObjectBase_RTTI_Type_Descriptor;
extern "C" void CVOGCreature_RTTI_Type_Descriptor;
extern "C" void CVOGPhysicsBase_RTTI_Type_Descriptor;

void __thiscall CVOGHBSkill_Virus_OnHeartBeat(int *thisHb, std::uint32_t *pOutStatus)
{
  std::uint32_t pulseStatus;
  void *const sehPrev = ExceptionList;
  // SEH: push -1 / scope table LAB_009a88b3 (omitted)

  FUN_0061b6f0(thisHb, &pulseStatus);

  int *pTarget = static_cast<int *>(FUN_00578270(thisHb));
  if (pTarget != nullptr) {
    using VFn0 = char(__thiscall *)(void *);
    auto **vtTarget = reinterpret_cast<void ***>(pTarget);
    char deadGate = reinterpret_cast<VFn0>((*vtTarget)[0x198 / 4])(pTarget);
    if (deadGate == 0) {
      void *pWorld = reinterpret_cast<void *>(thisHb[0x1a2]); // +0x688
      if (*reinterpret_cast<char *>(static_cast<char *>(pWorld) + 0x7e) != 0 &&
          thisHb[4] != 0) {
        // --- RNG unit sample ---
        void *rng = CVOGReaction_RandomUnitScalar();
        int *pIdx = reinterpret_cast<int *>(static_cast<char *>(rng) + 0xc);
        if (*pIdx > 0xfffff) {
          *pIdx = 0;
        }
        auto *table = *reinterpret_cast<std::uint16_t **>(
            static_cast<char *>(rng) + 8);
        std::uint16_t sample = table[*pIdx];
        *pIdx += 1;

        if ((static_cast<unsigned>(sample) % 100u) > 0x19u) {
          void *pOwner = reinterpret_cast<void *>(thisHb[6]); // +0x18

          void *asCre = __RTDynamicCast(
              pOwner, 0, &CVOGClonedObjectBase_RTTI_Type_Descriptor,
              &CVOGCreature_RTTI_Type_Descriptor, 0);
          bool hostOk = false;
          if (asCre != nullptr &&
              *reinterpret_cast<int *>(static_cast<char *>(asCre) + 0x250) != 0) {
            hostOk = true;
          } else {
            void *asPhys = __RTDynamicCast(
                pOwner, 0, &CVOGClonedObjectBase_RTTI_Type_Descriptor,
                &CVOGPhysicsBase_RTTI_Type_Descriptor, 0);
            hostOk = (asPhys != nullptr);
          }
          if (!hostOk) {
            *pOutStatus = 0;
            ExceptionList = sehPrev;
            return;
          }

          float *pos = static_cast<float *>(Object_GetWorldPositionPtr(pOwner));
          float origin[4] = {pos[0], pos[1], pos[2], pos[3]};

          TFID_16 outList[100];
          outList[0].dwCoidLo = DAT_009e2df0;
          outList[0].dwCoidHi = DAT_009e2df4;
          outList[0].uGlobalAndPad = DAT_009e2df8;
          outList[0].uPadTail = DAT_009e2dfc;

          float radius = DAT_00a0f524;
          float rField = *reinterpret_cast<float *>(&thisHb[0x17]); // +0x5c
          if (rField != g_flZero) {
            radius = rField;
          }

          int maxTargets =
              *reinterpret_cast<unsigned char *>(
                  reinterpret_cast<char *>(thisHb) + 0x102);
          if (maxTargets == 0) {
            maxTargets = 4;
          }

          Skill_GatherTargetsInArea(
              outList, /*start*/ 0, pWorld, pOwner, origin,
              static_cast<float>(static_cast<int>(radius)), maxTargets,
              /*mode*/ 1, /*filterA*/ 0xFFFFFFFFu,
              /*chain*/ 0, /*self*/ 0, /*B*/ 1, /*C*/ 0, /*sort*/ 0,
              /*score*/ -1.0f);

          if (static_cast<char>(TFID_NotEquals(&outList[0], &DAT_009e2df0)) != 0 &&
              thisHb[0x1b4] > 0) {
            std::uint32_t pad[401];
            void *rng2 = CVOGReaction_RandomUnitScalar();
            FUN_0051b720(rng2, 600, pad);

            thisHb[0x1b4] -= 1;
            thisHb[0x1b5] -= 1;

            int spawned = 0;
            TFID_16 *pA = &outList[0];
            std::uint32_t *pPadWrite = pad;

            if (static_cast<char>(TFID_NotEquals(pA, &DAT_009e2df0)) != 0) {
              do {
                // Prefer advancing pA (loop var). Decompiler may sticky-show
                // outList[0] as resolve arg — treat as noise.
                void *obj = Object_ResolveFromTFID(pA);
                if (obj != nullptr) {
                  void *mem = operator_new(0x6e0);
                  void *pAction = nullptr;
                  if (mem != nullptr) {
                    pAction = FUN_0061f940(
                        mem, pTarget, thisHb + 9, pWorld, obj, &DAT_00d02af0,
                        thisHb[0x1aa], thisHb[0x1b4], thisHb[0x1b5]);
                  }
                  // pOwnerObject @ +0x18
                  void *childOwner =
                      *reinterpret_cast<void **>(static_cast<char *>(pAction) +
                                                 0x18);
                  if (childOwner == nullptr) {
                    using Dtor = void(__thiscall *)(void *, int);
                    auto **vt = *reinterpret_cast<void ***>(pAction);
                    reinterpret_cast<Dtor>(vt[0])(pAction, 1);
                  } else {
                    void *list =
                        *reinterpret_cast<void **>(static_cast<char *>(pWorld) +
                                                   0xe4ec);
                    CVOGHBList_Enqueue(list, pAction);
                    CVOGHBBase_Start(pAction);
                    spawned += 1;
                    pPadWrite[0] = pA->dwCoidLo;
                    pPadWrite[1] = pA->dwCoidHi;
                    pPadWrite[2] = pA->uGlobalAndPad;
                    pPadWrite[3] = pA->uPadTail;
                    pPadWrite += 4;
                  }
                }
                pA += 1;
              } while (static_cast<char>(TFID_NotEquals(pA, &DAT_009e2df0)) != 0);
            }

            pad[spawned * 4 + 0] = DAT_009e2df0;
            pad[spawned * 4 + 1] = DAT_009e2df4;
            pad[spawned * 4 + 2] = DAT_009e2df8;
            pad[spawned * 4 + 3] = DAT_009e2dfc;
          }
        }
      }

      *pOutStatus = pulseStatus;
      ExceptionList = sehPrev;
      return;
    }
  }

  // Fail arm: vtbl+0x18(1,1)
  using VFail = void(__thiscall *)(void *, int, int);
  auto **vtThis = reinterpret_cast<void ***>(thisHb);
  reinterpret_cast<VFail>((*vtThis)[0x18 / 4])(thisHb, 1, 1);

  *pOutStatus = 0;
  ExceptionList = sehPrev;
}
