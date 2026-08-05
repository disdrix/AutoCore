// =============================================================================
// FUN_005ccff0  — twin of CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005ccff0
// Address:   0x005ccff0 – 0x005cd220  (autoassault.exe, image base 0x400000)
// Wave:      W29-L OWN dual 2026-07-29
// Canonical: docs/reconstruction/reconstructed-exact/CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred.cpp
// Exactness: Decompiler CF + sealed callee VAs; avoid bare undefined4.
// =============================================================================

#include <stdint.h>
#include <windows.h>

struct TFID_16 {
  uint32_t dwCoidLo;
  uint32_t dwCoidHi;
  uint32_t field_8;
  uint32_t field_c;
};

extern void *__thiscall Object_ResolveFromTFID(void *mgr_ctx, TFID_16 *tfid);
extern void __thiscall Object_SetMode278_SelectFromTFID228_Inferred(void *owner, char mode);
extern void __thiscall Object_SetSelectedTarget(void *self_mi, void *target);
extern int FUN_004c8970(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
extern void FUN_004294f0(void *list_lock_ctx);
extern uint32_t __thiscall LockedList_TryAdvanceIterator_Inferred(
    void *list, void *cursor_state, void **out_elem);
extern void *__cdecl __RTDynamicCast(void *in, long vfDelta, void *srcType,
                                     void *targetType, int isRef);
extern void *CVOGHBBase_RTTI_Type_Descriptor;
extern void *CVOGHBLinkedDeath_RTTI_Type_Descriptor;

static void *owner_mi_self(void *owner)
{
  int mid = *(int *)(*(int *)((char *)owner + 4) + 4);
  return (char *)owner + mid + 4;
}

void __fastcall FUN_005ccff0(void *param_1 /* HBAI this */)
{
  void *owner = *(void **)((char *)param_1 + 0x64);
  TFID_16 local_10;
  int *piVar3;
  void *candidate;
  char cVar2;
  void *list_ctx;
  uint32_t uStack_14;
  void *iStack_18;
  uint32_t iVar5;
  void *linked;
  void *partner;
  int *piVar1;
  void *pEntity;

  local_10.dwCoidLo = *(uint32_t *)((char *)owner + 0x228);
  local_10.dwCoidHi = *(uint32_t *)((char *)owner + 0x22c);
  local_10.field_8 = *(uint32_t *)((char *)owner + 0x230);
  local_10.field_c = *(uint32_t *)((char *)owner + 0x234);

  {
    int mid = *(int *)(*(int *)((char *)owner + 4) + 4);
    void *slot = *(void **)((char *)owner + mid + 0xA8);
    void *mgr = *(void **)((char *)slot + 0xE4E8);
    piVar3 = (int *)Object_ResolveFromTFID(mgr, &local_10);
  }

  if (piVar3 == 0) {
    Object_SetMode278_SelectFromTFID228_Inferred(owner, 0);
    return;
  }

  candidate = (void *)piVar3[0x28];
  if (candidate != 0) {
    void *omi = owner_mi_self(owner);
    cVar2 = (**(char(__thiscall ***)(void *, void *))(*(int *)omi + 0x298))(omi, candidate);
    if (cVar2 != 0) {
      if ((**(int(__thiscall ***)(void *))(*(int *)candidate + 0x1c8))(candidate) != 0) {
        Object_SetSelectedTarget(omi, candidate);
      }
      return;
    }
  }

  {
    int mid = *(int *)(*(int *)((char *)owner + 4) + 4);
    int *field_a4 = *(int **)((char *)owner + mid + 0xA4);
    if (field_a4 != 0) {
      if ((**(int(__thiscall ***)(void *))(*field_a4 + 0x214))(field_a4) != 0) {
        if (FUN_004c8970(*(uint32_t *)((char *)owner + 0x228),
                         *(uint32_t *)((char *)owner + 0x22c),
                         *(uint32_t *)((char *)owner + 0x230),
                         *(uint32_t *)((char *)owner + 0x234)) != 0) {
          return;
        }
      }
    }
  }

  {
    void *hb = (**(void *(__thiscall ***)(void *))(*piVar3 + 0x19c))(piVar3);
    int mid = *(int *)(*(int *)((char *)hb + 4) + 4);
    list_ctx = *(void **)((char *)hb + mid + 0xB4);
    FUN_004294f0(list_ctx);
    uStack_14 = 0;
    iVar5 = LockedList_TryAdvanceIterator_Inferred(list_ctx, &uStack_14, &iStack_18);
    while (iVar5 == 0) {
      if (*(int *)((char *)iStack_18 + 0x1c) == 2) {
        linked = __RTDynamicCast(iStack_18, 0, &CVOGHBBase_RTTI_Type_Descriptor,
                                 &CVOGHBLinkedDeath_RTTI_Type_Descriptor, 0);
        partner = *(void **)((char *)linked + 0x24);
        if (partner != 0 &&
            *(char *)((char *)linked + 0x20) == 0 &&
            *(char *)((char *)partner + 0x20) == 0) {
          piVar1 = *(int **)((char *)partner + 0x18);
          if (piVar1 != 0 &&
              (**(int(__thiscall ***)(void *))(*piVar1 + 0x214))(piVar1) != 0) {
            cVar2 = (**(char(__thiscall ***)(void *, void *))(*piVar1 + 0x298))(piVar1, piVar3);
            if (cVar2 != 0) {
              if (*(char *)((char *)list_ctx + 0x28) != 0) {
                *(char *)((char *)list_ctx + 0x28) = 0;
                LeaveCriticalSection((LPCRITICAL_SECTION)((char *)list_ctx + 4));
              }
              pEntity = (**(void *(__thiscall ***)(void *))(*piVar1 + 0x19c))(piVar1);
              if (pEntity != 0) {
                int emid = *(int *)(*(int *)((char *)pEntity + 4) + 4);
                pEntity = (char *)pEntity + emid + 4;
              }
              Object_SetSelectedTarget(owner_mi_self(owner), pEntity);
              return;
            }
          }
        }
      }
      iVar5 = LockedList_TryAdvanceIterator_Inferred(list_ctx, &uStack_14, &iStack_18);
    }
    if (*(char *)((char *)list_ctx + 0x28) != 0) {
      *(char *)((char *)list_ctx + 0x28) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)((char *)list_ctx + 4));
    }
  }
}
