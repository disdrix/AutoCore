# Function record: CVOGCombat_OnDeathAwardKillXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_004da630` |
| **Canonical name** | `CVOGCombat_OnDeathAwardKillXp` |
| **Address** | `0x004da630` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / combat XP + loot |
| **Completion status** | **Human-refined** — raw + clean + dual A/B reviews |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Death handler: resolve killer, build participation mult, award kill XP solo/convoy/TFID-list, then credits and loot side paths.

## Signature

```c
void* __thiscall CVOGCombat_OnDeathAwardKillXp(
    int pLootCtx, int* pKillerObj, int* pVictimObj);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004da630_CVOGCombat_OnDeathAwardKillXp.md`
- Annotated: `docs/reconstruction/raw/aa_004da630_CVOGCombat_OnDeathAwardKillXp.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGCombat_OnDeathAwardKillXp.cpp`
- Reviews: `reviews/A_aa_004da630_review.md`, `reviews/B_aa_004da630_review.md`

## Confidence

| Claim | Level |
|---|---|
| Award fan-out structure | High |
| FUN_* credit/loot callees | Tentative |
| Template 0xe/0x12 kinds | Probable |
