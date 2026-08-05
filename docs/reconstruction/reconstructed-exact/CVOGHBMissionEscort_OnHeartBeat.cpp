// =============================================================================
// CVOGHBMissionEscort_OnHeartBeat
// -----------------------------------------------------------------------------
// Stable ID: aa_006508d0
// Address:   0x006508d0–0x00650cf6  (autoassault.exe, image base 0x400000)
// System:    missions-progression / heartbeat
// Generated: 2026-08-04 WQ7R-H dual seal (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Verdict:   accept-with-gaps
// Terminal:  false
// Bit-for-bit / runtime / differential: DEFERRED / OPEN
// =============================================================================
//
// PURPOSE:
//   Escort mission OnHeartBeat (CVOGHBBase vtable+0x0C):
//     - RTTI cast owner → CVOGCharacter
//     - Lookup mission hash @ char+0x548 by missionKey (+0x28)
//     - Resolve escort TFID (scan char TFID list if cache invalid)
//     - Distance gate vs max escort range (+0x48 as float)
//     - lost  → FailMission + FUN_005307e0 (HandleEndQuest drain) [+ destroy target]
//       zone  → CompleteObjective(missionKey, -1, -1, force=1)
//       else  → RescheduleAfterFire
//     - *out = DAT_00af514c (16 = EHBStatus Remove)
//
// CLASS:  CVOGHBMissionEscort
//   RTTI TD 0x00af4a10  .?AVCVOGHBMissionEscort@@
//   COL     0x00ab1e9c
//   Vtable  PTR_FUN_009e52c4; this method = slot +0x0C (DATA bind only; TryFire virtual)
//   Ctor    FUN_006507c0 installs vtable
// NOT:    CVOGHBOutpost (separate RTTI; nearby "outpost" string is litter)
//
// ABI:    MSVC __thiscall (ECX = this)
//         stack: EHBStatus* pOutStatus
//         ret 4; returns pOutStatus
//
// CALLEES:
//   CNDHash_LookupByKey, Object_ResolveFromTFID, FUN_004bb070,
//   FUN_004c3f10, CVOGReaction_ResolveObjectTarget,
//   CVOGReaction_FailMission, FUN_005307e0 (drain YES),
//   CVOGReaction_CompleteObjective, CVOGHBBase_RescheduleAfterFire,
//   FUN_004d0e90
//
// GAPS (accept-with-gaps):
//   - Product English for max-range / complete-zone dual object fields
//   - Exact Escort subclass field overlay vs Ghidra CVOGHBBase array view
//   - Runtime / bit-exact distance capture
//
// Dual A/B:
//   reviews/A_aa_006508d0_CVOGHBMissionEscort_OnHeartBeat.md
//   reviews/B_aa_006508d0_CVOGHBMissionEscort_OnHeartBeat.md
// =============================================================================

#include <cstdint>
#include <cmath>

// EHBStatus: Continue=0, Inactive=2, Remove=0x10
// DAT_00af514c == 16 → Remove (TryFire dual: not combat period)
extern std::uint32_t DAT_00af514c;
extern float         g_flZero;
extern float         DAT_009e52b0[4];  // default TFID pad (near "outpost" litter)

// CVOGHBBase sizeof 0x28 (sealed aa_00508200). Ghidra types escort fields as
// param_1[1] / param_1[2] overlays of that size. Byte map used below:
//
//   +0x18  pOwnerObject
//   +0x28  missionKey
//   +0x2C  targetMatchRef          (CBID or host-ref)
//   +0x30  matchByObjRefMode       (char; 0 = CBID path)
//   +0x38  cachedEscortTfid[4]     (TFID_16)
//   +0x48  maxEscortRange          (float; 0 → no range fail)
//   +0x50  completeZoneKeyA_lo/hi
//   +0x58  completeZoneRadius      (float)
//   +0x60  completeZoneKeyB_lo/hi
//   +0x6C  pDestroyFlagHost        (ptr; host[+0x21] gates destroy-on-complete)

struct CVOGHBBase {
  void*         pVTable;            // +0x00
  std::int32_t  nRefOrFlags;        // +0x04
  std::int32_t  nPeriodMs;          // +0x08
  std::int32_t  nPeriodSentinel;    // +0x0C
  std::int32_t  nPeriodCounter;     // +0x10
  std::uint32_t dwLastFireTickMs;   // +0x14
  void*         pOwnerObject;       // +0x18
  std::int32_t  nTypeTag;           // +0x1C
  char          cStopped;           // +0x20
  bool          fDormant;           // +0x21
};

struct TFID_16 {
  std::uint32_t w[4];
};

extern void* CVOGClonedObjectBase_RTTI_Type_Descriptor;
extern void* CVOGCharacter_RTTI_Type_Descriptor;

extern "C" void* __RTDynamicCast(void* obj, int vfDelta, void* srcType,
                                 void* targetType, int isRef);
extern "C" void* CNDHash_LookupByKey(void* hash, std::uint32_t key);
extern "C" int   FUN_004c3f10(char mode);
extern "C" void* FUN_004bb070(TFID_16* tfid);
extern "C" void* Object_ResolveFromTFID(TFID_16* tfid);
extern "C" void* CVOGReaction_ResolveObjectTarget(
    char mode, std::uint32_t keyLo, std::uint32_t keyHi);
extern "C" std::uint8_t __thiscall CVOGReaction_FailMission(
    void* thisCharacter, std::uint32_t missionId);
extern "C" void __thiscall FUN_005307e0(void* thisCharacter);  // HandleEndQuest
extern "C" std::uint32_t __thiscall CVOGReaction_CompleteObjective(
    void* thisCharacter,
    std::uint32_t objectiveOrMissionKey,
    std::uint32_t rewardCoidLo,
    std::uint32_t rewardCoidHi,
    std::uint32_t forceComplete);
extern "C" void __thiscall CVOGHBBase_RescheduleAfterFire(
    CVOGHBBase* pThis, std::uint32_t* pOutStatus);
extern "C" void FUN_004d0e90(void* obj);

// Field accessors (byte offsets; product English residual — see plate)
static inline std::uint32_t& MissionKey(void* self) {
  return *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(self) + 0x28);
}
static inline std::int32_t& TargetMatchRef(void* self) {
  return *reinterpret_cast<std::int32_t*>(reinterpret_cast<char*>(self) + 0x2C);
}
static inline char& MatchByObjRefMode(void* self) {
  return *reinterpret_cast<char*>(reinterpret_cast<char*>(self) + 0x30);
}
static inline TFID_16* CachedEscortTfid(void* self) {
  return reinterpret_cast<TFID_16*>(reinterpret_cast<char*>(self) + 0x38);
}
static inline float& MaxEscortRange(void* self) {
  return *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x48);
}
static inline std::uint32_t& ZoneKeyA_Lo(void* self) {
  return *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(self) + 0x50);
}
static inline std::uint32_t& ZoneKeyA_Hi(void* self) {
  return *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(self) + 0x54);
}
static inline float& CompleteZoneRadius(void* self) {
  return *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x58);
}
static inline std::uint32_t& ZoneKeyB_Lo(void* self) {
  return *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(self) + 0x60);
}
static inline std::uint32_t& ZoneKeyB_Hi(void* self) {
  return *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(self) + 0x64);
}
static inline char*& DestroyFlagHost(void* self) {
  return *reinterpret_cast<char**>(reinterpret_cast<char*>(self) + 0x6C);
}

static void CacheTfidFromObject(void* self, void* obj)
{
  int o = reinterpret_cast<int>(obj);
  int base = *reinterpret_cast<int*>(*reinterpret_cast<int*>(o + 4) + 4);
  auto* src = reinterpret_cast<std::uint32_t*>(base + 0x164 + o);
  TFID_16* dst = CachedEscortTfid(self);
  dst->w[0] = src[0];
  dst->w[1] = src[1];
  dst->w[2] = src[2];
  dst->w[3] = src[3];
}

static bool ObjectMatchesEscortRef(void* self, void* obj)
{
  int o = reinterpret_cast<int>(obj);
  if (MatchByObjRefMode(self) == '\0') {
    int nest = *reinterpret_cast<int*>(
        *reinterpret_cast<int*>(*reinterpret_cast<int*>(o + 4) + 4) + 0xac + o);
    return *reinterpret_cast<int*>(nest + 0x34) == TargetMatchRef(self);
  }
  int host = *reinterpret_cast<int*>(o + 0x250);
  if (host == 0) {
    return false;
  }
  return *reinterpret_cast<int*>(host + 0x14c) == TargetMatchRef(self);
}

// this = CVOGHBMissionEscort* (ECX)
// pOutStatus = EHBStatus* (stack+4)
// returns pOutStatus; ret 4
std::uint32_t* __thiscall CVOGHBMissionEscort_OnHeartBeat(
    CVOGHBBase* self,
    std::uint32_t* pOutStatus)
{
  bool inCompleteZone = false;
  float playerX = 0.f;
  float playerY = 0.f;
  float playerZ = 0.f;
  // local_14 exists in decomp (TFID.w[3] scratch during scan); unused after

  void* pCharacter = __RTDynamicCast(
      self->pOwnerObject,
      0,
      &CVOGClonedObjectBase_RTTI_Type_Descriptor,
      &CVOGCharacter_RTTI_Type_Descriptor,
      0);

  if (pCharacter != nullptr) {
    void* missionNode = CNDHash_LookupByKey(
        *reinterpret_cast<void**>(reinterpret_cast<int>(pCharacter) + 0x548),
        MissionKey(self));

    bool lost = (missionNode == nullptr);

    // TFID cache invalid? (d0 & d1) == -1 and low byte of d2 == 0
    TFID_16* pTfid = CachedEscortTfid(self);
    if (((pTfid->w[0] & pTfid->w[1]) == 0xffffffffu) &&
        (*reinterpret_cast<char*>(&pTfid->w[2]) == '\0')) {
      int listCount = FUN_004c3f10(1);
      if (listCount > 0) {
        int charBase = reinterpret_cast<int>(pCharacter);
        int vecBegin = *reinterpret_cast<int*>(charBase + 0x1bc);
        int vecEnd   = *reinterpret_cast<int*>(charBase + 0x1c0);
        int byteOff  = 0;
        for (std::uint32_t i = 0; static_cast<int>(i) < listCount; ++i) {
          float* pWords;
          if (vecBegin == 0 ||
              static_cast<std::uint32_t>((vecEnd - vecBegin) >> 4) <= i) {
            pWords = DAT_009e52b0;
          } else {
            pWords = reinterpret_cast<float*>(vecBegin + byteOff);
          }
          TFID_16 probe;
          probe.w[0] = *reinterpret_cast<std::uint32_t*>(&pWords[0]);
          probe.w[1] = *reinterpret_cast<std::uint32_t*>(&pWords[1]);
          probe.w[2] = *reinterpret_cast<std::uint32_t*>(&pWords[2]);
          probe.w[3] = *reinterpret_cast<std::uint32_t*>(&pWords[3]);

          void* candidate = FUN_004bb070(&probe);
          if (candidate != nullptr && ObjectMatchesEscortRef(self, candidate)) {
            CacheTfidFromObject(self, candidate);
            break;
          }
          byteOff += 0x10;
        }
      }
    }

    void* pEscortTarget = Object_ResolveFromTFID(CachedEscortTfid(self));

    if (pEscortTarget == nullptr) {
      lost = true;
    } else if (!lost) {
      // Refresh target — vtable+0x144
      {
        auto** vt = *reinterpret_cast<void***>(pEscortTarget);
        using Fn144 = void(__thiscall*)(void*);
        reinterpret_cast<Fn144>(vt[0x144 / 4])(pEscortTarget);
      }

      // Player world position — character nested vcall +0x1a0
      {
        int c = reinterpret_cast<int>(pCharacter);
        int host =
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(c + 4) + 4) + 4 + c;
        auto** nestedVt = *reinterpret_cast<void***>(host);
        using GetPosFn = float*(__thiscall*)(void*);
        float* pos = reinterpret_cast<GetPosFn>(nestedVt[0x1a0 / 4])(
            reinterpret_cast<void*>(host));
        playerX = pos[0];
        playerY = pos[1];
        playerZ = pos[2];
      }

      // Distance gate: maxRange<=0 OR dist(player,target) <= maxRange
      {
        int t = reinterpret_cast<int>(pEscortTarget);
        float tx = *reinterpret_cast<float*>(t + 0x80);
        float ty = *reinterpret_cast<float*>(t + 0x84);
        float tz = *reinterpret_cast<float*>(t + 0x88);
        float dx = tx - playerX;
        float dy = ty - playerY;
        float dz = tz - playerZ;
        float dist = std::sqrt(dx * dx + dy * dy + dz * dz);

        if (MaxEscortRange(self) <= g_flZero || dist <= MaxEscortRange(self)) {
          // Complete-zone arm A
          if ((ZoneKeyA_Lo(self) & ZoneKeyA_Hi(self)) != 0xffffffffu) {
            void* zoneA = CVOGReaction_ResolveObjectTarget(
                0, ZoneKeyA_Lo(self), ZoneKeyA_Hi(self));
            if (zoneA != nullptr) {
              int z = reinterpret_cast<int>(zoneA);
              float fdx = *reinterpret_cast<float*>(z + 0x80) - playerX;
              float fdy = *reinterpret_cast<float*>(z + 0x84) - playerY;
              float fdz = *reinterpret_cast<float*>(z + 0x88) - playerZ;
              if (std::sqrt(fdx * fdx + fdy * fdy + fdz * fdz) <
                  CompleteZoneRadius(self)) {
                inCompleteZone = true;
              }
            }
          }
        } else {
          lost = true;
        }
      }
    }

    // Complete-zone arm B (always considered after target block; uses player pos
    // locals — only defined if the resolved-target path ran)
    {
      std::uint32_t keyB_hi = ZoneKeyB_Hi(self);
      if ((ZoneKeyB_Lo(self) & keyB_hi) != 0xffffffffu) {
        void* zoneB = CVOGReaction_ResolveObjectTarget(
            0, ZoneKeyB_Lo(self), keyB_hi);
        if (zoneB != nullptr) {
          int z = reinterpret_cast<int>(zoneB);
          float fdx = *reinterpret_cast<float*>(z + 0x80) - playerX;
          float fdy = *reinterpret_cast<float*>(z + 0x84) - playerY;
          float fdz = *reinterpret_cast<float*>(z + 0x88) - playerZ;
          if (std::sqrt(fdx * fdx + fdy * fdy + fdz * fdz) <
              CompleteZoneRadius(self)) {
            inCompleteZone = true;
          }
        }
      }
    }

    if (lost) {
      if (missionNode != nullptr) {
        std::uint32_t missionId =
            **reinterpret_cast<std::uint32_t**>(
                reinterpret_cast<int>(missionNode) + 0x14c);
        CVOGReaction_FailMission(pCharacter, missionId);
        FUN_005307e0(pCharacter);  // end-quest drain (drain-YES site)
      }
      if (pEscortTarget != nullptr) {
        // Mark destroy: obj[+0xcc] = 1
        reinterpret_cast<std::int32_t*>(pEscortTarget)[0x33] = 1;
        FUN_004d0e90(pEscortTarget);
        *pOutStatus = DAT_00af514c;  // Remove (16)
        return pOutStatus;
      }
    } else {
      if (!inCompleteZone) {
        CVOGHBBase_RescheduleAfterFire(self, pOutStatus);
        return pOutStatus;
      }

      CVOGReaction_CompleteObjective(
          pCharacter,
          MissionKey(self),
          0xffffffffu,
          0xffffffffu,
          1);  // force=1

      if (DestroyFlagHost(self) != nullptr &&
          DestroyFlagHost(self)[0x21] != '\0') {
        reinterpret_cast<std::int32_t*>(pEscortTarget)[0x33] = 1;
        FUN_004d0e90(pEscortTarget);
      }
    }
  }

  *pOutStatus = DAT_00af514c;  // Remove (16)
  return pOutStatus;
}
