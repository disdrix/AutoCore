// =============================================================================
// Skill_HB_SpawnEntities_Execute_Inferred  (FUN_00615020)
// -----------------------------------------------------------------------------
// Stable ID: aa_00615020
// Address:   0x00615020  (autoassault.exe, image base 0x400000)
// Body:      0x00615020 – 0x00615e59
// System:    skills / HB spawn effect
// Generated: 2026-07-29 W18-S dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving CF plate. Not a full line-by-line port of
//            3.5KB decompiler noise. See raw/annotated for full pseudocode.
//            Bit-for-bit: DEFERRED. Runtime: OPEN.
// =============================================================================
//
// PURPOSE
//   CVOGHBSkillBase subclass virtual at vtbl+0x2c (PTR_FUN_009d0ec4 from
//   FUN_00614dc0). Multi-spawn creatures or templates near caster/mount pose,
//   terrain-snap Y, orientation modes, arm per-spawn HB via Enqueue+Start,
//   optional excess cull when skill+0x16c == 100.0f.
//
// ABI (sealed from epilogue `ret 0x18` + ECX save in prologue)
//   int __thiscall (ECX=this, 6 stack args) → EAX status/count
//
// STRINGS
//   "Skill %d had invalid creature %d."
//   "Skill %d had invalid template %d."
//

#include <cstdint>

// ---- external symbols (Ghidra names; not linked here) ----
struct CVOGHBBase;
extern "C" int __RTDynamicCast(void *, int, void *, void *, int);
extern "C" void *FUN_0058ab60(void *seed);
extern "C" char FUN_00589b80(int startIndex, unsigned short first);
extern "C" float CVOGReaction_RandomUnitScalar(void);
extern "C" void FUN_004e8bf0(void *basisPos, void *basisQuat, void *offsetIn, void *outPos);
extern "C" float CVOGMap_CastTerrainHeight(float x, float z, float yProbe, int flags);
extern "C" void FUN_004e8ad0(void *quat, void *outRight);
extern "C" void FUN_005a5970(void *out, float x, float z);
extern "C" void FUN_004e9060(void *a, void *b, void *quat);
extern "C" void *FUN_0058be30(void);
extern "C" void *FUN_0058bf50(int templateId, int skillDef, void *caster);
extern "C" void FUN_007a4480(int level, const char *fmt, ...);
extern "C" void FUN_0058a1b0(void *creature, int map, float *pos, int *quat, int flag);
extern "C" void FUN_004ca910(void *slot, int flag);
extern "C" void *operator_new(unsigned int);
extern "C" CVOGHBBase *FUN_00614dc0(void *mem, void *caster, void *skill, void *map,
                                    void *spawned, void *a5, void *a6);
extern "C" unsigned CVOGHBList_Enqueue(void *list, CVOGHBBase *action);
extern "C" void CVOGHBBase_Start(CVOGHBBase *action);
extern "C" void FUN_004024d0(void *p);
extern "C" unsigned FUN_004c3f10(int);
extern "C" void *Object_ResolveFromTFID(void *tfid);
extern "C" void FUN_004d0e90(void *obj);
extern "C" void operator_delete__(void *p);
extern "C" void FUN_00567ce0(void *tbl, float angle);
extern "C" void FUN_004e8dc0(void *dir, void *quat);
extern "C" void FUN_00512460(void *id);
extern "C" void FUN_004c3c80(int);

// Memory-verified constants
static constexpr float kInv32768 = 3.051804378628731e-05f; // _DAT_009cc4a8
static constexpr float kDiskRadius = 10.0f;                // DAT_00a110d8
static constexpr float kTerrainYBias = 50.0f;              // DAT_00a0f524
static constexpr float kNegOne = -1.0f;                    // DAT_00aaa668
static constexpr float kSpecialNeg1000 = -1000.0f;         // DAT_00aaaaa0
static constexpr float kCullMode100 = 100.0f;              // DAT_00aaa7ac
static constexpr float kTwoPiOver65536 = 9.587525710230693e-05f; // _DAT_009e1cb4

// -----------------------------------------------------------------------------
// Control-flow summary (authoritative detail remains in raw decompile).
// This clean plate documents sealed ABI, gates, and stage order for ports.
// -----------------------------------------------------------------------------
int __thiscall Skill_HB_SpawnEntities_Execute_Inferred(
    void * /*this*/,
    int *pCasterObj,
    int pSkillDef,
    int pMapWorld,
    unsigned /*a4*/,
    unsigned /*a5*/,
    unsigned /*a6*/)
{
  // SEH frame omitted.

  // Gate: map active flag + RTTI cast caster → CVOGCreature
  // if (!(char)(pMapWorld+0x7e) || !creature) return 1;

  // Pose: creature+0x250 mount else self; copy pos/quat + radius(+0x34)

  // rng = FUN_0058ab60(a6);
  // count = skill.byte[0xde] ? skill.byte[0xde] : 1;
  // start = skill.int[0xe4];
  // if (FUN_00589b80(start, *rng) != 0) { delete[] rng; return 0; } // stream busy

  // success = 0;
  // for (i = 0; i < count; ++i) {
  //   restore base pose;
  //   if (this->vtbl[0x1c/4](caster, skill) != 0) continue; // gate fail skip
  //   ++success;
  //   if (skill.float[0x160] == 0) random XZ disk *10 ± radius;
  //   else directed offset via FUN_004e8bf0;
  //   y = CVOGMap_CastTerrainHeight(x, z, y + 50, 0);
  //   orient mode (int)skill.float[0x168] in {1,2,3};
  //   if (skill.char[0x22] == 0) creature spawn path;
  //   else template spawn path;
  //   on null: log "Skill %d had invalid creature/template %d." return 0;
  //   hb = new(0x6d0) / FUN_00614dc0(...);
  //   if (!hb->owner) hb->dtor(1); else Enqueue(map+0xe4ec), Start(hb);
  //   if (skill.float[0x16c] == 100.f) cull excess matching template id;
  // }
  // operator_delete__(rng);
  // return success;

  (void)pCasterObj;
  (void)pSkillDef;
  (void)pMapWorld;
  return 1; // plate stub — full body in raw FUN_00615020 / scaffold cpp
}

// Full expanded decompiler body retained in:
//   reconstructed-exact/FUN_00615020.cpp
//   reconstructed-exact/Skill_Skill_d_had_invalid_creature_d_00615020.cpp
