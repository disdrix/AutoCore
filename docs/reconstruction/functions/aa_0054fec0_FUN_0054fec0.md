# Function record: FUN_0054fec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054fec0` |
| **Canonical name** | `FUN_0054fec0` |
| **Named alias** | `Skill_StoreEffectPresenceFlags_Inferred` |
| **Address** | `0x0054fec0`–`0x0054fef8` (57 B inclusive of ret) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Dual A/B sealed** (WQ9E-B 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Presence-flag **store helper**: call `Skill_ComputeEffectPresenceFlags_Inferred`, write result to `skill+0x624`, with `|4` and optional `skill+0x620 |= 0x100000` when `+0x620` already non-zero. Twin of Reevaluate store tail (duplicated, not called).

## Signature

```c
void __fastcall FUN_0054fec0(void *pSkill);
// ECX = skill runtime; void; plain ret
```

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0054fec0_FUN_0054fec0.md`
- Annotated: `docs/reconstruction/raw/aa_0054fec0_FUN_0054fec0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Skill_StoreEffectPresenceFlags_Inferred.cpp`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_0054fec0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0054fec0_Skill_StoreEffectPresenceFlags_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0054fec0_Skill_StoreEffectPresenceFlags_Inferred.md`

## Callers / callees

| Direction | Symbol | VA |
|---|---|---|
| Callee | `Skill_ComputeEffectPresenceFlags_Inferred` | `0x00627be0` |
| Static callers | *(none found)* | — |
| Logical twin | `Skill_ReevaluateForCurrentRank` store tail | `0x00553390` |

## Confidence

| Claim | Level |
|---|---|
| Control flow / offsets from decompile ≡ bytes | **High** |
| ECX = skill runtime | **High** |
| Zero static callers | **High** (xref gap; dead or dynamic) |
| Product English for bit 4 / 0x100000 / +0x148 | **Open** |
