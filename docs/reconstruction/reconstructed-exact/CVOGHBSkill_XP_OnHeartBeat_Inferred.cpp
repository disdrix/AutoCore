// =============================================================================
// CVOGHBSkill_XP_OnHeartBeat_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0061c940
// Address:   0x0061c940–0x0061caf0  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0061c940
// System:    skills-abilities
// Class:     CVOGHBSkill_XP  (RTTI Confirmed ".?AVCVOGHBSkill_XP@@")
// Generated: 2026-08-05 R12-004 dual (clean named)
// Exactness: Behavior-preserving rewrite of decompiler + byte-sealed thiscalls.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Specialized CVOGHBSkill_XP OnHeartBeat (vtbl+0x0C). Dynamic-casts the skill
//   source object to CVOGCharacter. If character[+0xcb0] is null (personal):
//   when float this[+0x104] != 0, spawn one CVOGHBSkill_XPAdder (0x6d0) targeting
//   self. Else (multi-target table host): for slots 0..3, spawn an XPAdder per
//   live slot after MI adjustor. Accept → Enqueue(world+0xe4ec)+Start; reject →
//   vtbl[0](1). Tail: Skill_HB_RescheduleStatus_Inferred; return pOutStatus.
//
// ABI: __thiscall ECX=this; one stack dword; ret 0x04; EAX = pOutStatus.
// Vtbl: PTR_FUN_009d119c slot +0x0C (sole DATA xref).

#include <cstdint>

struct CVOGHBBase {
  void **pVTable;       // +0x00
  // void *pOwnerObject; // +0x18  (ValidateTarget accept polarity)
};

using ScalarDtorFn = void(__thiscall *)(CVOGHBBase *self, int flags);

extern "C" {
void *operator_new(unsigned size);
void *__cdecl __RTDynamicCast(void *in, long vfDelta, void *srcType, void *targetType,
                              int isReference);
CVOGHBBase *CVOGHBSkill_XPAdder_ctor(void *self, void *pSource, void *pSkillBlob,
                                     void *pWorld, void *pTarget, void *pTfid16,
                                     std::uint32_t arg7);
// Slot table get: __thiscall ECX=tableHost; returns *(host + (index+0x1a)*0x10)
void *FUN_00574760(void *tableHost, int index);
void CVOGHBList_Enqueue(void *list, CVOGHBBase *action);
void CVOGHBBase_Start(CVOGHBBase *action);
std::uint32_t *Skill_HB_RescheduleStatus_Inferred(void *thisHb, std::uint32_t *pOut);
}

// g_flZero @ DAT_00a0f518
extern "C" float g_flZero;

// RTTI descriptors (image)
extern "C" void CVOGClonedObjectBase_RTTI_Type_Descriptor;
extern "C" void CVOGCharacter_RTTI_Type_Descriptor;

static void *OwnerAt18(void *hb) {
  return *reinterpret_cast<void **>(static_cast<char *>(hb) + 0x18);
}

static void AcceptOrDelete(void *world, CVOGHBBase *hb) {
  void *owner = *reinterpret_cast<void **>(reinterpret_cast<char *>(hb) + 0x18);
  if (owner == nullptr) {
    auto dtor = reinterpret_cast<ScalarDtorFn>(hb->pVTable[0]);
    dtor(hb, 1);
  } else {
    void *list = *reinterpret_cast<void **>(static_cast<char *>(world) + 0xe4ec);
    CVOGHBList_Enqueue(list, hb);
    CVOGHBBase_Start(hb);
  }
}

static void *MiAdjustSlot(void *slot) {
  if (slot == nullptr)
    return nullptr;
  // *( *(slot+4) + 4 ) + slot + 4
  int adj = *reinterpret_cast<int *>(
      *reinterpret_cast<char **>(static_cast<char *>(slot) + 4) + 4);
  return static_cast<char *>(slot) + adj + 4;
}

std::uint32_t *CVOGHBSkill_XP_OnHeartBeat_Inferred(void *thisHb,
                                                   std::uint32_t *pOutStatus) {
  // SEH frame LAB_009a87bb — omitted in clean port shape

  void *character = __RTDynamicCast(
      OwnerAt18(thisHb), 0, &CVOGClonedObjectBase_RTTI_Type_Descriptor,
      &CVOGCharacter_RTTI_Type_Descriptor, 0);

  void *slotTable =
      *reinterpret_cast<void **>(static_cast<char *>(character) + 0xcb0);
  void *world = *reinterpret_cast<void **>(static_cast<char *>(thisHb) + 0x688);
  void *source = OwnerAt18(thisHb);
  void *skillBlob = static_cast<char *>(thisHb) + 0x24;
  void *tfid16 = static_cast<char *>(thisHb) + 0x690;
  std::uint32_t arg7 =
      *reinterpret_cast<std::uint32_t *>(static_cast<char *>(thisHb) + 0x6a8);

  if (slotTable == nullptr) {
    float residual =
        *reinterpret_cast<float *>(static_cast<char *>(thisHb) + 0x104);
    if (residual != g_flZero) {
      void *mem = operator_new(0x6d0);
      CVOGHBBase *hb = nullptr;
      if (mem != nullptr) {
        hb = CVOGHBSkill_XPAdder_ctor(mem, source, skillBlob, world, source,
                                      tfid16, arg7);
      }
      // Retail does not null-check hb before pOwner — exact port preserves path.
      AcceptOrDelete(world, hb);
    }
  } else {
    for (int i = 0; i < 4; ++i) {
      void *slot = FUN_00574760(slotTable, i);
      if (slot == nullptr)
        continue;
      (void)FUN_00574760(slotTable, i); // redundant pure read (retail)

      void *mem = operator_new(0x6d0);
      CVOGHBBase *hb = nullptr;
      if (mem != nullptr) {
        void *target = MiAdjustSlot(FUN_00574760(slotTable, i));
        hb = CVOGHBSkill_XPAdder_ctor(mem, source, skillBlob, world, target,
                                      tfid16, arg7);
      }
      AcceptOrDelete(world, hb);
    }
  }

  return Skill_HB_RescheduleStatus_Inferred(thisHb, pOutStatus);
}
