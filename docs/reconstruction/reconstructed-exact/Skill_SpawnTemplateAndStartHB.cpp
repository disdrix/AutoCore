// =============================================================================
// Skill_SpawnTemplateAndStartHB
// -----------------------------------------------------------------------------
// Stable ID: aa_00620480
// Address:   0x00620480  (autoassault.exe, image base 0x400000)
// Body:      0x00620480 – 0x00620a20
// System:    skills / HB action spawn
// Dual:      W19-E 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
//
// Install:   DATA dword @ 0x009d1598 = 0x00620480 (handler table)
// ABI:       6 stack dwords, epilogue ret 0x18; returns 0 | 1
// =============================================================================

#include <cstdint>

struct CVOGHBBase {
  void** pVTable;
  void* pOwnerObject;
  // ... remainder opaque
};

extern "C" void* operator_new(unsigned size);
extern "C" void operator_delete(void* p);
extern "C" void FUN_007a4480(int level, const char* fmt, ...);
extern "C" float* FUN_00404c90();
extern "C" float* FUN_00404a20();
extern "C" int FUN_004c9aa0(int flag);
extern "C" int* FUN_0058bf50(int templateId, int skillDef, int* source);
extern "C" void FUN_00404c60(void* dst);
extern "C" void FUN_00404c30(void* dst);
extern "C" void FUN_004e8bf0(void* a, void* b, void* c, void* d);
extern "C" void CVOGMap_CastTerrainHeight(std::uint32_t a, std::uint32_t b, float z, int d);
extern "C" void FUN_0058a1b0(int entityAdj, void* ctx, void* a, void* b, int flag);
extern "C" void FUN_004ca910(int slot, int flag);
extern "C" void Skill_EnsureLoadedInTree(void* entity, int skillId, int flag);
extern "C" void FUN_004e8a40(void* a, void* b);
extern "C" void FUN_004024d0(int adj);
extern "C" CVOGHBBase* FUN_006202f0(int* source, int skillDef, void* ctx,
                                    int entityAdj, std::uint32_t a5, std::uint32_t a6);
extern "C" void CVOGHBList_Enqueue(void* list, CVOGHBBase* action);
extern "C" void CVOGHBBase_Start(CVOGHBBase* action);
extern "C" std::uint32_t* CVOGReaction_ResolveSkillTargets(void* blob, std::uint32_t packed);
extern "C" void Skill_ApplyEffectsOnTarget_Inferred(void* targets, int* source, void* ctx,
                                                    void* poseBlock, void* fillBlock,
                                                    std::uint32_t flags);
extern float DAT_00aaa688; // 5.0f
extern float DAT_00aaa7ac; // 100.0f
extern std::uint32_t DAT_009e2e78, DAT_009e2e7c, DAT_009e2e80, DAT_009e2e84;
extern std::uint32_t DAT_00d02b00, DAT_00d02b04, DAT_00d02b08, DAT_00d02b0c;
extern void* ExceptionList;

// ---------------------------------------------------------------------------
// Skill_SpawnTemplateAndStartHB @ 0x00620480
// arg0 source object*, arg1 skillDef*, arg2 world/ctx*, arg3 unused surface,
// arg4/arg5 forwarded into HB ctor + effect apply.
// ---------------------------------------------------------------------------
std::uint32_t Skill_SpawnTemplateAndStartHB(
    int* param_1,
    int param_2,
    void* param_3,
    std::uint32_t /*param_4*/,
    std::uint32_t param_5,
    std::uint32_t param_6)
{
  // SEH: LAB_009a88fc
  if (!((*(char*)((int)param_3 + 0x7e) != '\0') &&
        (param_1 != nullptr) &&
        ({
          int related = (**(int(**)())(*param_1 + 0x214))();
          related != 0;
        }))) {
    return 1; // gate miss: no-op success
  }

  int iVar1 = (**(int(**)())(*param_1 + 0x214))();
  std::uint32_t* puVar8 = nullptr;

  // Pose sample (both +0x250 arms call FUN_00404c90 in live decomp)
  std::uint32_t* puVar2;
  if (*(int*)(iVar1 + 0x250) == 0) {
    puVar2 = (std::uint32_t*)FUN_00404c90();
  } else {
    puVar2 = (std::uint32_t*)FUN_00404c90();
  }
  std::uint32_t uStack_90 = puVar2[0];
  std::uint32_t uStack_8c = puVar2[1];
  std::uint32_t uStack_88 = puVar2[2];
  std::uint32_t uStack_84 = puVar2[3];

  puVar2 = (std::uint32_t*)FUN_00404a20();
  std::uint32_t uStack_80 = puVar2[0];
  std::uint32_t uStack_7c = puVar2[1];
  float fStack_78 = *(float*)&puVar2[2];
  std::uint32_t uStack_74 = puVar2[3];

  int iVar4;
  if (*(char*)(param_2 + 0x22) == '\0') {
    // Direct entity spawn path
    void* pvVar3 = operator_new(0x690);
    if (pvVar3 == nullptr) {
      iVar4 = 0;
    } else {
      iVar4 = FUN_004c9aa0(1);
    }
    // vcall init(templateId @ skillDef+0x14c, ctx, 1) on MI-adjusted entity
    int base = *(int*)(*(int*)(iVar4 + 4) + 4) + 4 + iVar4;
    (**(void(**)(std::uint32_t, void*, int))(*(int*)base + 8))(
        *(std::uint32_t*)(param_2 + 0x14c), param_3, 1);
  } else {
    // Template lookup path
    int* piVar5 = FUN_0058bf50(*(std::uint32_t*)(param_2 + 0x14c), param_2, param_1);
    if (piVar5 == nullptr) {
      FUN_007a4480(1, "Skill %d had invalid template %d.",
                   *(std::uint32_t*)(param_2 + 0x5fc),
                   *(std::uint32_t*)(param_2 + 0x14c));
      return 0;
    }
    puVar8 = (std::uint32_t*)(**(int(**)())(*piVar5 + 0x1d4))();
    FUN_00404c60(&uStack_90);
    FUN_00404c30(&uStack_80);
    (**(void(**)(void*, std::uint32_t*, std::uint32_t*, int))**puVar8)(
        param_3, &uStack_90, &uStack_80, 0);
    int adj = *(int*)(puVar8[1] + 4) + 0xb0 + (int)puVar8;
    iVar4 = (**(int(**)())(**(int**)adj + 0x1d8))();
  }

  // Post-spawn placement / skill load / HB start
  std::uint32_t uStack_64 = *(std::uint32_t*)&DAT_00aaa688; // 5.0f payload
  *(std::uint8_t*)(iVar4 + 0x309) = 0;
  std::uint32_t uStack_6c = 0, uStack_68 = 0, uStack_60 = 0;
  std::uint32_t stack_pose[4];
  FUN_004e8bf0(stack_pose, &uStack_8c, &uStack_6c, &uStack_7c);
  uStack_90 = 0; // uStack_70 surface in decomp
  CVOGMap_CastTerrainHeight(uStack_7c, uStack_74, fStack_78 + DAT_00aaa7ac /*100.f*/, 0);

  if (puVar8 == nullptr) {
    int entityAdj = *(int*)(*(int*)(iVar4 + 4) + 4) + 4 + iVar4;
    FUN_0058a1b0(entityAdj, param_3, stack_pose, &uStack_8c, 1);
  }

  FUN_004ca910(*(int*)(*(int*)(iVar1 + 4) + 4) + 0x164 + iVar1, 1);
  int iVar6 = (**(int(**)(int))(*(int*)(*(int*)(*(int*)(iVar1 + 4) + 4) + 4 + iVar1) + 0x210))(0);
  *(bool*)(iVar4 + 0x206) = (iVar6 != 0);

  int entityRoot = *(int*)(*(int*)(iVar4 + 4) + 4) + 4 + iVar4;
  if (*(int*)(param_2 + 0x154) != 0) {
    Skill_EnsureLoadedInTree((void*)entityRoot, *(int*)(param_2 + 0x154), 1);
  }
  if (*(int*)(param_2 + 0x158) != 0) {
    Skill_EnsureLoadedInTree((void*)entityRoot, *(int*)(param_2 + 0x158), 1);
  }
  if (*(int*)(param_2 + 0x15c) != 0) {
    Skill_EnsureLoadedInTree((void*)entityRoot, *(int*)(param_2 + 0x15c), 1);
  }

  FUN_004e8a40(&uStack_90, stack_pose);
  (**(void(**)(std::uint32_t))(*(int*)entityRoot + 0x2a4))(
      *(std::uint32_t*)(*(int*)(*(int*)(*(int*)(iVar1 + 4) + 4) + 0xa8 + iVar1) + 0xe4e8));
  FUN_004024d0(*(int*)(*(int*)(iVar4 + 4) + 4) + iVar4 + 4);
  if (puVar8 != nullptr) {
    FUN_004024d0(*(int*)(puVar8[1] + 4) + 4 + (int)puVar8);
  }
  (**(void(**)())(*(int*)(*(int*)(*(int*)(iVar4 + 0x44) + 4) + 0x44 + iVar4) + 0x28))();

  void* pvHB = operator_new(0x6c0);
  CVOGHBBase* pAction;
  if (pvHB == nullptr) {
    pAction = nullptr;
  } else {
    pAction = FUN_006202f0(param_1, param_2, param_3, entityRoot, param_5, param_6);
  }

  std::uint16_t uVar7 = 0;
  if (pAction->pOwnerObject == nullptr) {
    (**(void(**)(int))*pAction->pVTable)(1);
  } else {
    CVOGHBList_Enqueue(*(void**)((int)param_3 + 0xe4ec), pAction);
    CVOGHBBase_Start(pAction);
  }

  if (*(void**)(param_2 + 0x150) != nullptr) {
    std::uint32_t* puTargets = CVOGReaction_ResolveSkillTargets(
        *(void**)(param_2 + 0x150),
        (std::uint32_t)(*(std::uint16_t*)(param_2 + 0x5f6)));
    // pose/fill blocks from entity +0x164 and globals
    std::uint32_t poseBlock[4];
    std::uint32_t* puSlot = (std::uint32_t*)(*(int*)(*(int*)(iVar4 + 4) + 4) + 0x164 + iVar4);
    poseBlock[0] = puSlot[0];
    poseBlock[1] = puSlot[1];
    poseBlock[2] = puSlot[2];
    poseBlock[3] = puSlot[3];
    std::uint32_t fillA[4] = {DAT_009e2e78, DAT_009e2e7c, DAT_009e2e80, DAT_009e2e84};
    std::uint32_t fillB[4] = {DAT_00d02b00, DAT_00d02b04, DAT_00d02b08, DAT_00d02b0c};
    (void)fillA;
    (void)uVar7;
    Skill_ApplyEffectsOnTarget_Inferred(puTargets, param_1, param_3, poseBlock, fillB, param_6);
    if (puTargets != nullptr) {
      operator_delete(puTargets);
    }
  }

  return 1;
}
