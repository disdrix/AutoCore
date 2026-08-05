// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: ceil×9, ROUND×3, CVOGReaction_AddExperience×2, CombatFloaterType::XP×2, Experience_LevelDiffBaseXp×2, XP×2, max×2, AddExperience.
//  - Return sites: 1.

// =============================================================================
// CVOGCombat_CalculateAndAwardKillXP
// -----------------------------------------------------------------------------
// Purpose:  Final kill XP amount = level-diff base × global scalar × participation,
//           plus spree stacks, then award via AddExperience(KillPath) and optional
//           combat floater for the local player.
//
// Address:  0x004d80b0  (autoassault.exe, image base 0x400000)
// Stable:   aa_004d80b0
// System:   missions-progression / combat XP
//
// Convention: MSVC __cdecl
//   nPlayerLevel         killer character level
//   nVictimLevel         dead creature/vehicle level
//   flParticipationMult  XPPercent * damage share (* convoy product at call site)
//   pCharacter           character receiving XP (reads spree byte +0x738)
//   nConvoyMemberCount   >0 enables multi-recipient blend (0.1 constant)
//   nUnused_INFERRED     present in signature; not referenced in body
//
// Returns:  void (side effects: XP mutate + floater)
//
// Algorithm (docs/XP.md § Final kill amount):
//   1) Prep-clamp: if (victim - player) > 3, victim = player + 3
//      (decompiler also has dead "victim < player → victim = player" after clamp)
//   2) base = Experience_LevelDiffBaseXp(victim, player, grey=true)
//   3) if convoyCount > 0:
//        base = ceil((base + trunc(count * 0.1 * base)) / count)
//   4) raw = ceil(base * g_flGlobalKillXpScalar * flParticipationMult)
//      NOTE: g_flGlobalKillXpScalar @ 0x00B037F8 is BSS 0 in retail image → raw=0
//   5) if raw < 1: xp = 0
//      else stacks = max(0, spreeByte-1); xp = raw + ceil(stacks * raw * 0.05)
//   6) ok = CVOGReaction_AddExperience(pCharacter, xp, KillPath)
//   7) if ok && localPlayerFlag(+0x7e): vtable prep + combat floater type 3 (XP)
//
// Globals (image):
//   g_flMultiKillCountBlend      @ 0x00A0F730 = 0.1f
//   g_flGlobalKillXpScalar       @ 0x00B037F8 = 0.0f (BSS, no writers found)
//   g_flKillSpreeBonusPerStack   @ 0x009CBF80 = 0.05f
//
// Callees (addresses known from siblings / headers):
//   Experience_LevelDiffBaseXp        level-diff base table (grey=true)
//   CVOGReaction_AddExperience        KillPath award
//   Client_EnqueueCombatFloater_INFERRED  type-3 XP floater
// Callers: CVOGCombat_OnDeathAwardKillXp and related death/kill pipelines
//
// Exactness: Human-refined, behavior-preserving rewrite of raw decompile (2026-07-23).
// Dual reviews: reviews/A_aa_004d80b0_review.md, reviews/B_aa_004d80b0_review.md
// =============================================================================

#include <cmath>
#include <cstdint>

enum XpIsKillPath { PacketOrNonKill = 0, KillPath = 1 };

unsigned Experience_LevelDiffBaseXp(int nVictimLevel, int nPlayerLevel, bool bGreyCheck);
bool     CVOGReaction_AddExperience(void* character, int amount, XpIsKillPath isKillPath);
void     Client_EnqueueCombatFloater_INFERRED(/* floater blob / empty in decompiler */);

extern float g_flMultiKillCountBlend;    // 0.1f @ 0x00A0F730
extern float g_flGlobalKillXpScalar;     // BSS 0 @ 0x00B037F8
extern float g_flKillSpreeBonusPerStack; // 0.05f @ 0x009CBF80

// ROUND / ceil match decompiler surface (x87 ROUND after ceil).
static inline int RoundToInt(float x)
{
    return (int)(x >= 0.0f ? (x + 0.5f) : (x - 0.5f));
}

void __cdecl CVOGCombat_CalculateAndAwardKillXP(
    int   nPlayerLevel,
    int   nVictimLevel,
    float flParticipationMult,
    void* pCharacter,
    int   nConvoyMemberCount,
    int   /* nUnused_INFERRED */)
{
    unsigned char cSpreeStacks;
    bool          bAwardOk;
    int           pLocalPlayerCtx_INFERRED; // decompiler unaff / global; used for +0x7e
    int           nAwardXp;
    double        dCeil;
    unsigned      nLevelDiffBase;

    // -------------------------------------------------------------------------
    // 1) Prep-clamp level pair before LevelDiffBase
    //    if victim is more than 3 above player, clamp victim to player+3.
    //    Second clause (victim < player after clamp → set victim = player) is
    //    unreachable for normal int levels (player+3 < player is never true).
    // -------------------------------------------------------------------------
    if ((3 < nVictimLevel - nPlayerLevel) &&
        (nVictimLevel = nPlayerLevel + 3, nVictimLevel < nPlayerLevel)) {
        nVictimLevel = nPlayerLevel;
    }

    // -------------------------------------------------------------------------
    // 2) Level-diff base from tCreatureExperienceLevel (grey/hard branches)
    // -------------------------------------------------------------------------
    nLevelDiffBase = Experience_LevelDiffBaseXp(nVictimLevel, nPlayerLevel, true);

    // -------------------------------------------------------------------------
    // 3) Convoy multi-recipient blend when count > 0
    //    eff = ceil( (base + trunc(count * 0.1 * base)) / count )
    // -------------------------------------------------------------------------
    if (0 < nConvoyMemberCount) {
        dCeil = ceil((double)((float)(int)((int)((float)nConvoyMemberCount *
                                                 g_flMultiKillCountBlend *
                                                 (float)(int)nLevelDiffBase) +
                                           nLevelDiffBase) /
                              (float)nConvoyMemberCount));
        nLevelDiffBase = (unsigned)RoundToInt((float)dCeil);
    }

    // -------------------------------------------------------------------------
    // 4) raw = ceil(base * GLOBAL_KILL_SCALAR * participation)
    //    GLOBAL_KILL_SCALAR is 0 in this client image → awards always 0 locally.
    // -------------------------------------------------------------------------
    dCeil = ceil((double)((float)(int)nLevelDiffBase * g_flGlobalKillXpScalar *
                          flParticipationMult));
    nAwardXp = (int)RoundToInt((float)dCeil);

    // -------------------------------------------------------------------------
    // 5) Spree stacks: max(0, char+0x738 - 1); +5% per stack via ceil
    // -------------------------------------------------------------------------
    if (nAwardXp < 1) {
        nAwardXp = 0;
    } else {
        if (*(unsigned char*)((int)pCharacter + 0x738) < 2) {
            cSpreeStacks = 0;
        } else {
            cSpreeStacks = *(unsigned char*)((int)pCharacter + 0x738) - 1;
        }
        dCeil = ceil((double)((float)cSpreeStacks * (float)nAwardXp *
                              g_flKillSpreeBonusPerStack));
        nAwardXp = nAwardXp + (int)RoundToInt((float)dCeil);
    }

    // -------------------------------------------------------------------------
    // 6) Award through kill path of AddExperience
    // -------------------------------------------------------------------------
    bAwardOk = CVOGReaction_AddExperience(pCharacter, nAwardXp, KillPath);

    // -------------------------------------------------------------------------
    // 7) Local player combat floater (type CombatFloaterType::XP = 3)
    //    Gate: award succeeded AND local flag at pLocalPlayerCtx+0x7e.
    //    Vtable +0x19c on character dual-base chain runs before enqueue.
    // -------------------------------------------------------------------------
    if ((bAwardOk) && (*(char*)(pLocalPlayerCtx_INFERRED + 0x7e) != '\0')) {
        (**(int (**)())(
            *(int*)(*(int*)(*(int*)((int)pCharacter + 4) + 4) + 4 + (int)pCharacter) +
            0x19c))();
        Client_EnqueueCombatFloater_INFERRED();
    }
}
