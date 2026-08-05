// =============================================================================
// Object_SetSelectedTarget
// -----------------------------------------------------------------------------
// Stable ID: aa_005172d0
// Address:   0x005172d0  (autoassault.exe, image base 0x400000)
// Body:      0x005172d0 – 0x005173f9  (ret 4; int3 pad @ 0x005173fa)
// System:    object / combat-target / HB
// Generated: 2026-07-29 dual A/B refine (supersedes scaffold FUN_005172d0.cpp)
// Exactness: Behavior-preserving rewrite of retail control flow from
//            decompile + read_memory. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Set entity selected-target pointer at +0xA0 when changed, if world and
//   world HB list exist. Dirty net mask bit 4; purge CVOGHBPlayerTargetingLink
//   entries from entity+0xB0; for non-null non-self targets, allocate dual
//   HB pair, cross-link partners (+0x24), enqueue on world+0xE4EC (self first).
//
// ABI: void __thiscall (entity ECX, newTarget stack); ret 4
// Name: INFERRED (RTTI CVOGHBPlayerTargetingLink + field role; no product string).
//
// ASM SEALS (decomp corrections):
//   - List this for purge = entity+0xB0 (decomp omitted ECX setup).
//   - FUN_00604db0 is binary partner-link; both directions after dual new.
//   - Missing world / missing world+0xE4EC => no +0xA0 write.
//
// CALLEES (not owned):
//   NetObject_SetMaskBits, CNDDoubleList_InvokePredicateAndRemove_Inferred (0x004e2600),
//   operator_new, FUN_00512090 (PlayerTargetingLink ctor), FUN_00604d40 (target HB ctor),
//   FUN_00604db0 (partner +0x24), CVOGHBList_Enqueue, predicate FUN_005121d0.
// =============================================================================

#include <cstdint>

// Forward decls — retail symbols / prior renames
struct CVOGHBBase;
extern "C" void __thiscall NetObject_SetMaskBits(void *net, uint32_t maskBits, uint32_t arg2);
extern "C" void __thiscall CNDDoubleList_InvokePredicateAndRemove_Inferred(
    void *list, void *predicate, void *ctx, int stopFlagArg);
extern "C" void *operator_new(uint32_t size);
extern "C" CVOGHBBase *__thiscall FUN_00512090(void *selfMem, void *attachEntity);
extern "C" CVOGHBBase *__thiscall FUN_00604d40(void *selfMem, void *attachEntity);
extern "C" void __thiscall FUN_00604db0(CVOGHBBase *self, CVOGHBBase *partner);
extern "C" uint32_t __thiscall CVOGHBList_Enqueue(void *list, CVOGHBBase *action);
extern "C" int FUN_005121d0(CVOGHBBase *hb); // RTTI CVOGHBPlayerTargetingLink destroy

void __thiscall Object_SetSelectedTarget(void *entity, void *newTarget)
{
  void *world;
  void *net;
  void *hbList;
  void *mem;
  CVOGHBBase *selfLink;
  CVOGHBBase *targetHb;

  // if (newTarget == entity->selectedTarget) return;
  if (newTarget == *reinterpret_cast<void **>(reinterpret_cast<char *>(entity) + 0xA0)) {
    return;
  }

  world = *reinterpret_cast<void **>(reinterpret_cast<char *>(entity) + 0xA4);
  if (world == nullptr) {
    return;
  }
  hbList = *reinterpret_cast<void **>(reinterpret_cast<char *>(world) + 0xE4EC);
  if (hbList == nullptr) {
    return;
  }

  net = *reinterpret_cast<void **>(reinterpret_cast<char *>(entity) + 0x14);
  if (net != nullptr) {
    NetObject_SetMaskBits(net, 4, 0);
  }

  // Early write only when previous target non-null.
  if (*reinterpret_cast<void **>(reinterpret_cast<char *>(entity) + 0xA0) != nullptr) {
    *reinterpret_cast<void **>(reinterpret_cast<char *>(entity) + 0xA0) = newTarget;
  }

  // Purge PlayerTargetingLink HB nodes from entity's action list (+0xB0).
  CNDDoubleList_InvokePredicateAndRemove_Inferred(
      *reinterpret_cast<void **>(reinterpret_cast<char *>(entity) + 0xB0),
      reinterpret_cast<void *>(&FUN_005121d0),
      nullptr,
      0);

  *reinterpret_cast<void **>(reinterpret_cast<char *>(entity) + 0xA0) = newTarget;

  if (newTarget == nullptr || newTarget == entity) {
    return;
  }

  selfLink = nullptr;
  mem = operator_new(0x28);
  if (mem != nullptr) {
    selfLink = FUN_00512090(mem, entity);
  }

  mem = operator_new(0x28);
  if (mem == nullptr) {
    targetHb = nullptr;
  } else {
    targetHb = FUN_00604d40(mem, newTarget);
  }

  // Mutual partner link at HB+0x24 (see FUN_00604db0 gate on +0x18).
  FUN_00604db0(selfLink, targetHb);
  FUN_00604db0(targetHb, selfLink);

  // Enqueue order: self link, then target HB.
  CVOGHBList_Enqueue(hbList, selfLink);
  CVOGHBList_Enqueue(hbList, targetHb);
}
