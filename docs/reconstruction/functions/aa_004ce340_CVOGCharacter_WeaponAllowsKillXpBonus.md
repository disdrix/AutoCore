# Function record: CVOGCharacter_WeaponAllowsKillXpBonus

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce340` |
| **Canonical name** | `CVOGCharacter_WeaponAllowsKillXpBonus` |
| **Address** | `0x004ce340` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / combat XP gate |
| **Completion status** | **Human-refined** — raw + clean + dual A/B reviews |
| **Bit-for-bit / runtime / diff** | Open (listing verified; no CE) |

## Purpose

Boolean gate on object fields `+0x100` (must be 0) and `+0xac` (must not be 2). Despite the retail name, the body has no weapon lookup. Callers include kill-path spree scaling in `AddExperience` and mission dual-hash policy.

## Signature

```c
bool __thiscall CVOGCharacter_WeaponAllowsKillXpBonus(void* thisObject);
// Assembly: ECX this; returns AL 0/1. 11 instructions, no callees.
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004ce340_CVOGCharacter_WeaponAllowsKillXpBonus.md`
- Annotated: `docs/reconstruction/raw/aa_004ce340_CVOGCharacter_WeaponAllowsKillXpBonus.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGCharacter_WeaponAllowsKillXpBonus.cpp`
- Reviews: `reviews/A_aa_004ce340_review.md`, `reviews/B_aa_004ce340_review.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from listing | High |
| Field offsets | High |
| Object type / mode semantics | Tentative |
| Retail name accuracy | Low (misnomer) |
