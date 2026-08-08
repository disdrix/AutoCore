// =============================================================================
// CVOGHBSkill_Master_Execute  (FUN_00614c80)
// -----------------------------------------------------------------------------
// Stable ID: aa_00614c80
// Address:   0x00614c80–0x00614d87  (autoassault.exe, image base 0x400000)
// Body size: 264 bytes (0x108), ret 0x18
// System:    skills-abilities / CVOGHB skill element type id 3
// Generated: 2026-07-23 scaffold as FUN_00614c80; dual A/B R11-011 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler + entry-byte CF.
//            Not modernization. Bit-for-bit vs retail: DEFERRED. Runtime: OPEN.
// =============================================================================
//
// PURPOSE
//   Virtual execute (vtbl+0x2c) for RTTI class CVOGHBSkill_Master
//   (".?AVCVOGHBSkill_Master@@", vtbl PTR_FUN_009d0e6c).
//   Walk a 16-byte target-descriptor table (max 100 entries), resolve each
//   object via CVOGReaction_ResolveObjectTarget, and for every hit allocate a
//   0x6c0 child skill HB, run CVOGHBSkillBase_ctor with the resolved target,
//   stamp the Master vtbl, then Enqueue+Start on map+0xe4ec (or destroy if
//   owner slot +0x18 is null). Always returns 1.
//
// ABI (retail, sealed)
//   uint32_t __thiscall (ECX=this Master*, 6 stack dwords) → EAX = 1
//   ret 0x18
//
// RTTI / CATALOG
//   COL 0x00aadb2c → type_info 0x00af28ac ".?AVCVOGHBSkill_Master@@"
//   SkillElementFactory_RegisterCatalog type id 3: new(0x6c0)+DefaultCtor+vtbl
//
// CALLEES
//   CVOGReaction_ResolveObjectTarget  0x004bae70
//   operator_new                      0x00489892
//   CVOGHBSkillBase_ctor              0x005788d0
//   CVOGHBList_Enqueue                0x005078f0
//   CVOGHBBase_Start                  0x005081c0
//   (indirect) vtbl[0] = FUN_00651190 scalar deleting dtor
//
// XREFS
//   DATA only: vtbl slot 0x009d0e98. No direct CALL sites.
//

#include <cstdint>

struct CVOGHBBase {
  void *pVTable;       // +0x00
  // ...
  // void *pOwnerObject at +0x18
};

extern "C" void *operator_new(unsigned size);
extern "C" void *__thiscall CVOGHBSkillBase_ctor(
    void *self,
    void *skillOrSource,
    void *a2,
    void *mapWorld,
    void *target,
    void *a5,
    void *a6);
extern "C" void *__thiscall CVOGReaction_ResolveObjectTarget(
    void *ctx,
    char type,
    unsigned id0,
    unsigned id1);
extern "C" unsigned CVOGHBList_Enqueue(void *list, CVOGHBBase *action);
extern "C" void CVOGHBBase_Start(CVOGHBBase *action);
extern "C" void *PTR_FUN_009d0e6c;

// Target table entry (stride 0x10) as consumed by this body.
struct MasterTargetEntry {
  int id0;       // +0x00
  int id1;       // +0x04
  char type;     // +0x08
  char pad[7];
};

uint32_t __thiscall CVOGHBSkill_Master_Execute(
    void * /*self*/,
    void *skillOrSource,
    void *a2,
    int mapWorld,
    MasterTargetEntry *targetTable,
    void *a5,
    void *a6)
{
  // SEH frame (LAB_009a862b) omitted.

  for (char i = 0; i < 100; ++i) {
    MasterTargetEntry *entry = &targetTable[i];

    if (entry->id0 == -1 && entry->id1 == -1 && entry->type == 0) {
      return 1;
    }

    void *resolveCtx = *reinterpret_cast<void **>(
        reinterpret_cast<uint8_t *>(mapWorld) + 0xe4e8);
    void *resolved = CVOGReaction_ResolveObjectTarget(
        resolveCtx, entry->type,
        static_cast<unsigned>(entry->id0),
        static_cast<unsigned>(entry->id1));

    if (resolved == nullptr) {
      continue;
    }

    auto *child = static_cast<CVOGHBBase *>(operator_new(0x6c0));
    if (child != nullptr) {
      CVOGHBSkillBase_ctor(child, skillOrSource, a2,
                           reinterpret_cast<void *>(mapWorld),
                           resolved, a5, a6);
      child->pVTable = &PTR_FUN_009d0e6c;
    }

    void *owner = *reinterpret_cast<void **>(
        reinterpret_cast<uint8_t *>(child) + 0x18);
    if (owner == nullptr) {
      using Dtor = void *(__thiscall *)(void *, unsigned char);
      auto **vt = reinterpret_cast<void ***>(child->pVTable);
      // vtbl[0](1) — scalar deleting dtor
      reinterpret_cast<Dtor>(vt[0])(child, 1);
    } else {
      void *hbList = *reinterpret_cast<void **>(
          reinterpret_cast<uint8_t *>(mapWorld) + 0xe4ec);
      CVOGHBList_Enqueue(hbList, child);
      CVOGHBBase_Start(child);
    }
  }

  return 1;
}
