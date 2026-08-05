# Function record: Experience_LevelDiffBaseXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9800` |
| **Canonical name** | `Experience_LevelDiffBaseXp` |
| **Address** | `0x004c9800` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / combat XP |
| **Completion status** | **Human-refined** — raw + clean + dual A/B reviews |
| **Bit-for-bit / runtime / diff** | Open; constants cited from XP.md / image addresses |

## Purpose

Compute integer kill XP **base** from player/victim levels against `tCreatureExperienceLevel`: grey/easy reduction when player is above victim; hard boosted-row + 0.005 interpolate when victim is far above player.

## Signature

```c
unsigned __cdecl Experience_LevelDiffBaseXp(
    int nVictimLevel, int nPlayerLevel, bool bEnableGreyCheck);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c9800_Experience_LevelDiffBaseXp.md`
- Annotated: `docs/reconstruction/raw/aa_004c9800_Experience_LevelDiffBaseXp.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Experience_LevelDiffBaseXp.cpp`
- Reviews: `reviews/A_aa_004c9800_review.md`, `reviews/B_aa_004c9800_review.md`

## Callers / callees

| Role | Name |
|---|---|
| Caller | `CVOGCombat_CalculateAndAwardKillXP` (`grey=true`) |
| Callee | `Experience_GetCreatureXpForLevel` |
| Callee | `ROUND` (x87 / CRT) |

## Confidence

| Claim | Level |
|---|---|
| Hard/easy control flow | High |
| Grey ≥10 → 0 when enabled | High |
| Hard clamp −9 / extra only beyond clamp | High |
| Worked CreatureXP numeric examples | Tentative (table not re-dumped) |
