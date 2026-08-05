// =============================================================================
// CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred  (Ghidra: FUN_005ccff0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005ccff0
// Address:   0x005ccff0 – 0x005cd220  (autoassault.exe, image base 0x400000)
// System:    CVOGHB AI engage / target select from owner TFID
// Generated: 2026-07-29 W29-L OWN-ONLY dual (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed callees/ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Engage-path target selection for HBAI (thiscall, ECX = AI).
 * Owner object @ this+0x64; TFID_16 @ owner+0x228.
 * Resolve fail → Object_SetMode278_SelectFromTFID228_Inferred(owner, 0).
 * Prefer candidate resolved+0xA0 via owner vtbl+0x298 + candidate vtbl+0x1c8.
 * Else walk resolved HB list (type==2 → CVOGHBLinkedDeath) for partner promote.
 * Sole caller: CVOGHBAICreatureBase_OnHeartBeat engage arm.
 *
 * No invented product English for vtbl slots; offsets from bytes/decompile.
 */

#include <stdint.h>
#include <windows.h>

struct TFID_16 {
  uint32_t dwCoidLo;
  uint32_t dwCoidHi;
  uint32_t field_8;
  uint32_t field_c;
};

/* sealed dual callees */
extern void *__thiscall Object_ResolveFromTFID(void *mgr_ctx /* ECX */, TFID_16 *tfid);
extern void __thiscall Object_SetMode278_SelectFromTFID228_Inferred(void *owner, char mode);
extern void __thiscall Object_SetSelectedTarget(void *self_mi, void *target);
extern int FUN_004c8970(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
extern void FUN_004294f0(void *list_lock_ctx /* ECX */);
extern uint32_t __thiscall LockedList_TryAdvanceIterator_Inferred(
    void *list, void *cursor_state, void **out_elem);
extern void *__cdecl __RTDynamicCast(void *in, long vfDelta, void *srcType,
                                     void *targetType, int isRef);

/* RTTI symbols present in image */
extern void *CVOGHBBase_RTTI_Type_Descriptor;
extern void *CVOGHBLinkedDeath_RTTI_Type_Descriptor;

static void *owner_mi_self(void *owner)
{
  int *p = (int *)owner;
  int mid = *(int *)(*(int *)((char *)owner + 4) + 4);
  return (char *)owner + mid + 4;
}

void __thiscall CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred(void *hbai)
{
  void *owner = *(void **)((char *)hbai + 0x64);
  TFID_16 local_tfid;
  int *resolved;
  void *candidate;
  char ok;
  void *list_ctx;
  uint32_t cursor;
  void *elem;
  uint32_t adv;
  void *linked;
  void *partner;
  int *partner_obj;
  void *entity;

  local_tfid.dwCoidLo = *(uint32_t *)((char *)owner + 0x228);
  local_tfid.dwCoidHi = *(uint32_t *)((char *)owner + 0x22c);
  local_tfid.field_8 = *(uint32_t *)((char *)owner + 0x230);
  local_tfid.field_c = *(uint32_t *)((char *)owner + 0x234);

  /* rebuild resolve-manager ECX: MI[+0xA8] then [+0xE4E8] (same pattern as 004c3c80) */
  {
    int mid = *(int *)(*(int *)((char *)owner + 4) + 4);
    void *slot = *(void **)((char *)owner + mid + 0xA8);
    void *mgr = *(void **)((char *)slot + 0xE4E8);
    resolved = (int *)Object_ResolveFromTFID(mgr, &local_tfid);
  }

  if (resolved == 0) {
    Object_SetMode278_SelectFromTFID228_Inferred(owner, 0);
    return;
  }

  candidate = (void *)resolved[0x28]; /* +0xA0 */
  if (candidate != 0) {
    void *omi = owner_mi_self(owner);
    ok = (**(char(__thiscall ***)(void *, void *))(*(int *)omi + 0x298))(omi, candidate);
    if (ok != 0) {
      int alive = (**(int(__thiscall ***)(void *))(*(int *)candidate + 0x1c8))(candidate);
      if (alive != 0) {
        Object_SetSelectedTarget(omi, candidate);
        return;
      }
      return;
    }
  }

  /* fallback: optional FUN_004c8970 gate via owner field +0xA4 / vtbl+0x214 */
  {
    int mid = *(int *)(*(int *)((char *)owner + 4) + 4);
    int *field_a4 = *(int **)((char *)owner + mid + 0xA4);
    if (field_a4 != 0) {
      int ready = (**(int(__thiscall ***)(void *))(*field_a4 + 0x214))(field_a4);
      if (ready != 0) {
        int r = FUN_004c8970(
            *(uint32_t *)((char *)owner + 0x228),
            *(uint32_t *)((char *)owner + 0x22c),
            *(uint32_t *)((char *)owner + 0x230),
            *(uint32_t *)((char *)owner + 0x234));
        if (r != 0)
          return;
      }
    }
  }

  /* walk resolved object's HB list for LinkedDeath partner */
  {
    void *hb = (**(void *(__thiscall ***)(void *))(*resolved + 0x19c))(resolved);
    int mid = *(int *)(*(int *)((char *)hb + 4) + 4);
    list_ctx = *(void **)((char *)hb + mid + 0xB4);
    FUN_004294f0(list_ctx);
    cursor = 0;
    adv = LockedList_TryAdvanceIterator_Inferred(list_ctx, &cursor, &elem);
    while (adv == 0) {
      if (*(int *)((char *)elem + 0x1c) == 2) {
        linked = __RTDynamicCast(elem, 0, &CVOGHBBase_RTTI_Type_Descriptor,
                                 &CVOGHBLinkedDeath_RTTI_Type_Descriptor, 0);
        partner = *(void **)((char *)linked + 0x24);
        if (partner != 0 &&
            *(char *)((char *)linked + 0x20) == 0 &&
            *(char *)((char *)partner + 0x20) == 0) {
          partner_obj = *(int **)((char *)partner + 0x18);
          if (partner_obj != 0) {
            int r214 = (**(int(__thiscall ***)(void *))(*partner_obj + 0x214))(partner_obj);
            if (r214 != 0) {
              ok = (**(char(__thiscall ***)(void *, void *))(*partner_obj + 0x298))(
                  partner_obj, resolved);
              if (ok != 0) {
                if (*(char *)((char *)list_ctx + 0x28) != 0) {
                  *(char *)((char *)list_ctx + 0x28) = 0;
                  LeaveCriticalSection((LPCRITICAL_SECTION)((char *)list_ctx + 4));
                }
                entity = (**(void *(__thiscall ***)(void *))(*partner_obj + 0x19c))(partner_obj);
                if (entity != 0) {
                  int emid = *(int *)(*(int *)((char *)entity + 4) + 4);
                  entity = (char *)entity + emid + 4;
                }
                Object_SetSelectedTarget(owner_mi_self(owner), entity);
                return;
              }
            }
          }
        }
      }
      adv = LockedList_TryAdvanceIterator_Inferred(list_ctx, &cursor, &elem);
    }
    if (*(char *)((char *)list_ctx + 0x28) != 0) {
      *(char *)((char *)list_ctx + 0x28) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)((char *)list_ctx + 4));
    }
  }
}
