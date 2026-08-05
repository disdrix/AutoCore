// =============================================================================
// SkillDefMap_GetGlobal
// -----------------------------------------------------------------------------
// Stable ID: aa_0054b480
// Address:   0x0054b480  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-29 W18-C dual A/B seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Lazy-get the global skill-definition map header at DAT_00b04734.
//   If once-flag DAT_00b04724 is clear, run FUN_0054b2c0 (load/reset tree),
//   then always return &DAT_00b04734.
//
// ABI: leaf — no this, no stack args, pure ret; EAX = map header*.
//
// DISTINCT FROM:
//   Skill_GetCategoryCooldownMap — per-entity map at owner+0x6c (not this global).
//
// CONSUMERS (examples):
//   Client_RecvSkillStatusEffect 0x00811170  → then SkillDefMap_ExactFindByIntKey
//   FUN_005408f0 / FUN_00541aa0 / FUN_00542790
//
// SEALED: 20-byte body; cmp/jne/call/mov eax,imm/ret; live ≡ raw 2026-07-23.
// =============================================================================

#include <cstdint>

// BSS / data (autoassault.exe)
extern "C" uint8_t DAT_00b04724;           // once-init flag
extern "C" uint8_t DAT_00b04734;           // SkillDefMap header (address-of returned)

// Init loader (not dualed in this unit) — sets DAT_00b04724 = 1 and builds tree.
extern "C" void FUN_0054b2c0(void);

// Map header is the object at &DAT_00b04734 (layout owned by SkillDefMap_* family).
// Structural name only — product STL/RTTI Open.
struct SkillDefMapHeader;

SkillDefMapHeader* SkillDefMap_GetGlobal(void)
{
  if (DAT_00b04724 == 0) {
    FUN_0054b2c0();
  }
  return reinterpret_cast<SkillDefMapHeader*>(&DAT_00b04734);
}
