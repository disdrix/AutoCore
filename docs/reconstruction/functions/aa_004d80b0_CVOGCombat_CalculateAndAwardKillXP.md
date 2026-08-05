# Function record: CVOGCombat_CalculateAndAwardKillXP

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d80b0` |
| **Canonical name** | `CVOGCombat_CalculateAndAwardKillXP` |
| **Address** | `0x004d80b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / combat XP |
| **Completion status** | **Human-refined** — raw + clean + dual A/B reviews |
| **Bit-for-bit / runtime / diff** | Open; GLOBAL scalar image-verified 0 |

## Purpose

Compute kill XP (level-diff base, convoy blend, global scalar, participation, spree stacks) and award via `CVOGReaction_AddExperience(..., KillPath)`; optional local combat floater type 3.

## Signature

```c
void __cdecl CVOGCombat_CalculateAndAwardKillXP(
    int nPlayerLevel, int nVictimLevel, float flParticipationMult,
    void* pCharacter, int nConvoyMemberCount, int nUnused_INFERRED);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004d80b0_CVOGCombat_CalculateAndAwardKillXP.md`
- Annotated: `docs/reconstruction/raw/aa_004d80b0_CVOGCombat_CalculateAndAwardKillXP.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGCombat_CalculateAndAwardKillXP.cpp`
- Reviews: `reviews/A_aa_004d80b0_review.md`, `reviews/B_aa_004d80b0_review.md`

## Confidence

| Claim | Level |
|---|---|
| Formula structure | High |
| GLOBAL=0 in image | High (`read_memory`) |
| Floater local gate typing | Tentative |
