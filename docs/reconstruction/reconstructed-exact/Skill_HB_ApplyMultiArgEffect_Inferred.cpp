// =============================================================================
// Skill_HB_ApplyMultiArgEffect_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0058d8e0
// Address:   0x0058d8e0  (autoassault.exe, image base 0x400000)
// Body:      0x0058d8e0–0x0058d95d inclusive (126 B / 0x7E); pad CC CC after ret
// System:    skills-abilities
// Ghidra:    FUN_0058d8e0
// Dual:      2026-08-05 MEGA-009 OWN-ONLY
//
// Purpose: Heartbeat multi-arg combat effect wrapper. When the object pointer
//          is non-null, builds a 2-slot TFID list (object identity @ +0x160 plus
//          global null terminator DAT_009d4d28..) and forwards to
//          Skill_ApplyMultiTargetHits_Inferred. Returns summed damage.
//
// ABI:     __cdecl
//          6 stack formals; bare ret (caller ADD ESP,0x18)
//          EAX = damage sum (or 0 on null object early-out)
//
// Callers: CVOGHBSkill_SharedOnHeartBeat_Inferred (0x0061b6f0) @ 0x0061b8f9
//            gated by bit0 of skill-HB +0x648
//          FUN_00618270 @ 0x0061866e (same pack shape)
//          orphan UNCONDITIONAL_CALL @ 0x0061e922 / 0x0061ea7b
//
// Callee:  Skill_ApplyMultiTargetHits_Inferred (0x0058c850) [dualed W20-Q]
//
// Exactness: Behavior-preserving rewrite of decompiler CF + live disasm /
//            read_memory (MEGA-009). Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN (no Launcher).
// =============================================================================

#include <cstdint>

// Dualed multi-target apply (aa_0058c850). Decl for documentation only.
extern int Skill_ApplyMultiTargetHits_Inferred(
    void *combatSource,
    std::uint32_t *tfidListHead,
    void *damageSource,
    std::uint32_t /*unused_param4*/,
    void *rollTable,
    int rollSeedIndex);

// Global null TFID terminator (image: 0x009d4d28..0x009d4d37)
// Bytes: ff ff ff ff  ff ff ff ff  00 00 00 00  00 00 00 00
extern std::uint32_t DAT_009d4d28;
extern std::uint32_t DAT_009d4d2c;
extern std::uint32_t DAT_009d4d30;
extern std::uint32_t DAT_009d4d34;

// Returns damage sum (EAX). Decompiler may show void.
int Skill_HB_ApplyMultiArgEffect_Inferred(
    void *combatSource,          // param_1 — parent: Object_ResolveTargetViaReaction result
    void *objectWithTfidAt160,   // param_2 — null-checked; TFID_16 copied from +0x160
    void *damageEffectBlob,      // param_3 — multi-hit damage fields (+0x54..)
    std::uint32_t unusedParam4,  // param_4 — forwarded; unused by multi-hit body
    void *rollTable,             // param_5 — ushort roll table base
    int rollSeedIndex)           // param_6 — parent packs skill pulse counter @ +0x6c8
{
  // Retail: sub esp, 0x20 — 32 B = one TFID_16 entry + null terminator entry
  std::uint32_t tfidList[8];

  // 0058d8e0  mov eax, [esp+8] ; test; jz early ret
  if (objectWithTfidAt160 == nullptr) {
    return 0;
  }

  // Entry 0: copy object TFID_16 at +0x160..+0x16f
  const auto *src = reinterpret_cast<const std::uint32_t *>(
      reinterpret_cast<const char *>(objectWithTfidAt160) + 0x160);
  tfidList[0] = src[0]; // +0x160
  tfidList[1] = src[1]; // +0x164
  tfidList[2] = src[2]; // +0x168
  tfidList[3] = src[3]; // +0x16c

  // Entry 1: global null terminator (end when (lo & hi) == 0xffffffff)
  tfidList[4] = DAT_009d4d28; // 0xffffffff
  tfidList[5] = DAT_009d4d2c; // 0xffffffff
  tfidList[6] = DAT_009d4d30; // 0
  tfidList[7] = DAT_009d4d34; // 0

  // 0058d952  call Skill_ApplyMultiTargetHits_Inferred
  // 0058d957  add esp, 0x18
  // 0058d95a  add esp, 0x20
  // 0058d95d  ret
  return Skill_ApplyMultiTargetHits_Inferred(
      combatSource,
      tfidList,
      damageEffectBlob,
      unusedParam4,
      rollTable,
      rollSeedIndex);
}
