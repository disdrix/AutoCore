# Annotated low-level: CVOGCombat_CalculateAndAwardKillXP

| Field | Value |
|---|---|
| Stable ID | `aa_004d80b0` |
| VA | `0x004d80b0` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004d80b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* CVOGCombat_CalculateAndAwardKillXP — kill XP formula + award (docs/XP.md)
   
   Parameters:
     nPlayerLevel         - killer character level
     nVictimLevel         - dead creature/vehicle level
     flParticipationMult  - XPPercent * damage share (and convoy product terms)
     pCharacter           - character receiving XP (spree at +0x738)
     nConvoyMemberCount   - >0 enables multi-recipient blend (0.1)
     nUnused_INFERRED     - present in signature; not used in body (INFERRED)
   
   Algorithm:
     1) Prep-clamp: if victim-player > 3, clamp victim toward player+3
     2) base = Experience_LevelDiffBaseXp(victim, player, grey=true)
     3) if nConvoyMemberCount > 0:
          base = ceil((base + trunc(count * 0.1 * base)) / count)
     4) raw = ceil(base * g_flGlobalKillXpScalar * flParticipationMult)
        NOTE: g_flGlobalKillXpScalar is BSS 0 → client kills award 0 XP
     5) stacks = max(0, spreeByte-1); xp = raw + ceil(stacks * raw * 0.05)
     6) CVOGReaction_AddExperience(pCharacter, xp, KillPath)
     7) If local player (+0x7e): combat floater type CombatFloaterType::XP (3)
   
   Returns: void
   AutoCore: ExperienceService.ComputeKillXp + GiveXp(source=Kill) */

void __cdecl
CVOGCombat_CalculateAndAwardKillXP
          (int nPlayerLevel,int nVictimLevel,float flParticipationMult,void *pCharacter,
          int nConvoyMemberCount,int nUnused_INFERRED)

{
  byte cSpreeStacks;
  bool bAwardOk;
  int pLocalPlayerCtx_INFERRED;
  int nAwardXp;
  double dVar1;
  uint nLevelDiffBase;
  
                    /* Prep-clamp level pair (high within low+3) before LevelDiffBase */
  if ((3 < nVictimLevel - nPlayerLevel) &&
     (nVictimLevel = nPlayerLevel + 3, nVictimLevel < nPlayerLevel)) {
                    /* Resolve level-diff base XP (grey/hard) */
    nVictimLevel = nPlayerLevel;
  }
                    /* // Resolve effective distance */
  nLevelDiffBase = Experience_LevelDiffBaseXp(nVictimLevel,nPlayerLevel,true);
                    /* // Scale base XP by kill count */
  if (0 < nConvoyMemberCount) {
                    /* Convoy multi-recipient blend when count > 0 */
    dVar1 = ceil((double)((float)(int)((int)((float)nConvoyMemberCount * g_flMultiKillCountBlend *
                                            (float)(int)nLevelDiffBase) + nLevelDiffBase) /
                         (float)nConvoyMemberCount));
    nLevelDiffBase = (uint)ROUND((float)dVar1);
  }
                    /* // Calculate base XP = ceil(effectiveDist * 0.1 * multiplier) */
                    /* raw = ceil(base * g_flGlobalKillXpScalar * mult) — scalar is BSS 0 */
                    /* FMUL g_flGlobalKillXpScalar — BSS 0 in this build */
  dVar1 = ceil((double)((float)(int)nLevelDiffBase * g_flGlobalKillXpScalar * flParticipationMult));
                    /* Spree stacks: max(0, char+0x738 - 1); +5% per stack */
  nAwardXp = (int)ROUND((float)dVar1);
                    /* // Calculate level bonus: ceil((targetLevel-1) * baseXP * 0.25) */
  if (nAwardXp < 1) {
    nAwardXp = 0;
  }
  else {
    if (*(byte *)((int)pCharacter + 0x738) < 2) {
      cSpreeStacks = 0;
    }
    else {
      cSpreeStacks = *(byte *)((int)pCharacter + 0x738) - 1;
    }
    dVar1 = ceil((double)((float)cSpreeStacks * (float)nAwardXp * g_flKillSpreeBonusPerStack));
                    /* Award via AddExperience(isKillPath=KillPath) */
    nAwardXp = nAwardXp + (int)ROUND((float)dVar1);
  }
                    /* // Award total XP to character */
                    /* Local player: enqueue CombatFloaterType::XP (3) */
  bAwardOk = CVOGReaction_AddExperience(pCharacter,nAwardXp,KillPath);
                    /* // Check target flag +0x7e and send XP notification packet */
  if ((bAwardOk) && (*(char *)(pLocalPlayerCtx_INFERRED + 0x7e) != '\0')) {
    (**(code **)(*(int *)(*(int *)(*(int *)((int)pCharacter + 4) + 4) + 4 + (int)pCharacter) + 0x19c
                ))();
                    /* // Send XP notification packet (packet type 0x3) */
    Client_EnqueueCombatFloater_INFERRED();
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
