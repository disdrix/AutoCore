# Function record: Client_AwardKillExperience

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080ae70` |
| **Canonical name** | `Client_AwardKillExperience` |
| **Address** | `0x0080ae70` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / client net |
| **Completion status** | **Human-refined** — raw + clean + dual A/B reviews |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

S2C GiveXP (0x205F) handler. Historical name — applies **all** packet XP via `AddExperience(..., PacketOrNonKill)`, optional level-hint stamp, optional XP combat floater.

## Signature

```c
void __cdecl Client_AwardKillExperience(GiveXpPacketBody* pGiveXp);
// Dispatch also uses EDI+0xe98 local char, ESI+4 amount, ESI+8 levelHint
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0080ae70_Client_AwardKillExperience.md`
- Annotated: `docs/reconstruction/raw/aa_0080ae70_Client_AwardKillExperience.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_AwardKillExperience.cpp`
- Reviews: `reviews/A_aa_0080ae70_review.md`, `reviews/B_aa_0080ae70_review.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow | High |
| Register dispatch contract | Probable / INFERRED |
| “Kill-only” naming | Low (misnomer) |
