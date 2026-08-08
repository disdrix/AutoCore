# Function record: Skill_ComputeEffectPresenceFlags_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00627be0` |
| **Canonical name** | `Skill_ComputeEffectPresenceFlags_Inferred` |
| **Ghidra name** | `FUN_00627be0` |
| **Address** | `0x00627be0`–`0x00627eb3` (211 B exclusive) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Dual A/B sealed** (WQ9D-E 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias / superseded

- Scaffold: `FUN_00627be0`
- Legacy: `Named_CalleeOf_Skill_ReevaluateForCurrentRank_00627be0`

## Purpose

Leaf scan of ranked skill-runtime effect fields. Builds a presence bitmask from non-zero int16/float/char banks, ORs with base dword `skill+0xc`, returns the combined mask. Rank-reeval path (`Skill_ReevaluateForCurrentRank`) and twin helper `FUN_0054fec0` store the result to `skill+0x624` (targeting/capability flags).

## Signature

```c
uint32_t __fastcall Skill_ComputeEffectPresenceFlags_Inferred(void *pSkill);
// ECX = skill runtime; EAX = *(skill+0xc) | presenceBits; ret
```

## Callers / callees

| Direction | Symbol | VA |
|---|---|---|
| Caller | `Skill_ReevaluateForCurrentRank` | `0x00553390` |
| Caller | `FUN_0054fec0` | `0x0054fec0` |
| Caller | `FUN_00627ec0` | `0x00627ec0` |
| Callee | *(none — leaf)* | |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00627be0_FUN_00627be0.md`
- Annotated: `docs/reconstruction/raw/aa_00627be0_FUN_00627be0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_ComputeEffectPresenceFlags_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00627be0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00627be0_Skill_ComputeEffectPresenceFlags_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00627be0_Skill_ComputeEffectPresenceFlags_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow / bit map from decompile ≡ bytes | **High** |
| ECX = skill runtime at sealed call sites | **High** |
| Result feeds `skill+0x624` (caller pattern) | **High** |
| Product English for each effect bank | **Open** (`_Inferred`) |
| Full `+0x624` targeting enum glossary | **Open** (consumer residual) |
