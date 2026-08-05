# Function record: Mission_ComputeObjectiveXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059dde0` |
| **Canonical name** | `Mission_ComputeObjectiveXp` |
| **Address** | `0x0059dde0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__fastcall` (objective in ECX) |
| **Completion status** | **Human-refined partial** — formula + map-node + caller residual sealed (2026-07-29 strengthen); table payloads / runtime open |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual residual** | **accept-with-gaps** (`reviews/A_aa_0059dde0_review.md`, `B_aa_0059dde0_review.md`) |
| **Last refined** | 2026-07-29 (dual residual strengthen) |

## Purpose

Pure mission-complete XP calculator: lookup quest-XP fraction by objective `wXPIndex`, multiply by balance/scaler floats, scale the tExperienceLevel span for mission `TargetLevel`. Returns truncated int XP.

**Grant path:** `CVOGReaction_CompleteObjective` final only (not advance). Caller applies `± g_flMissionXpRoundBias` (0.5001f @ `0x00aaa6d0`) then `CVOGReaction_AddExperience(..., PacketOrNonKill)`.

**Presentation callers:** `Client_ShowMissionRewardChatToast` (×2 call sites) and thin float wrapper `FUN_0051f510` — display only; no character XP write.

## Signature

```c
int __fastcall Mission_ComputeObjectiveXp(void* pObjective /* CVOGObjective* */);
```

Returns `0` if mission def null, quest-XP map miss/end, or experience-level map miss/end.

## Behavioral summary

1. Bail if `obj+0x14c` (mission def) is null.
2. Lazy-load `tQuestXPLookup`; **exact-key** find by `short` at `obj+0x13c` (`wXPIndex`); read float frac at node `+0x10`.
3. `spanMult = fXPBalanceScaler(+0x144) * frac * fXPScaler(+0x140)` (image mulss order).
4. Lazy-load `tExperienceLevel`; exact-key find by mission `TargetLevel` (`missionDef+0x11c`); read `intExperience` at node `+0x10`.
5. If `TargetLevel > 1`, subtract previous level's cumulative threshold (if L-1 row exists).
6. Return `(int)((float)levelSpan * spanMult)` — trunc toward zero.

## Map protocol (sealed)

| Item | Value |
|---|---|
| Quest helper | `Map_LowerBoundFindByIntKey` `0x0050f940` — nil flag **+0x15** |
| Level helper | `StdMap_LowerBoundByIntKey_INFERRED` `0x004054f0` — nil flag **+0x1d** |
| ABI | `__thiscall(map*, node** out, int* key)` + `ret 8` (`C2 08 00`) |
| After call | EAX = out-it address; `*EAX` = **node*** (or end sentinel) — body `8B 38` |
| Node key | `+0xc` |
| Node payload | `+0x10` |
| Match policy | Exact key: lower_bound walk + `key < node.key → end`; miss → 0 |
| Decompiler `unaff_EDI` / 4th arg | Noise |

### Global VAs (body immediates)

| Label | VA |
|---|---|
| `g_pExperienceLevelMap_INFERRED` | `0x00b04240` |
| `g_pExperienceLevelMapEnd` | `0x00b04244` |
| `g_nExperienceLevelTableReady` | `0x00b04248` |
| `g_pQuestXpLookupMap_INFERRED` | `0x00b0424c` |
| `g_pQuestXpLookupMapEnd` | `0x00b04250` |
| `g_nQuestXpLookupReady` | `0x00b04254` |
| `g_flMissionXpRoundBias` (caller) | `0x00aaa6d0` = **0.5001f** (`8e 06 00 3f`) |

## Offsets (this unit)

| Location | Role |
|---|---|
| `obj+0x13c` | short XPIndex |
| `obj+0x140` | float XPScaler |
| `obj+0x144` | float XPBalanceScaler |
| `obj+0x14c` | mission def* |
| `mission+0x11c` | short TargetLevel |
| map node `+0x10` | frac (float) or intExperience (int) |

## Callers (xrefs sealed)

| Site | Function | Role |
|---|---|---|
| `0x005341c0` | `CVOGReaction_CompleteObjective` | **Grant** — post-call ±bias then AddExperience |
| `0x008ac594` | `Client_ShowMissionRewardChatToast` | Presentation (already-received branch gate) |
| `0x008ac5e9` | `Client_ShowMissionRewardChatToast` | Presentation (Awarded XP chat + floater path) |
| `0x0051f521` | `FUN_0051f510` | Thin float wrapper → re-calls calculator for toast floater |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | High | Named; sole mission XP calc body |
| Control flow | High | Raw + clean + live decompile agree |
| Formula product order | High | Balance * frac * Scaler (mulss sequence) |
| Trunc toward zero here | High | int cast of float product |
| Bias applied by caller not here | High | CompleteObjective asm + image float |
| Map node / L-1 payload shape | **High** | Image seal + helper `ret 8` |
| Exact-key miss → 0 | **High** | Map body exact-match gate |
| Caller set (grant vs presentation) | **High** | Fresh xrefs |
| Global VAs | **High** | Body immediates |
| Table load helper names | Probable | `_INFERRED` loaders |
| Table row payloads | Open | R2 — XP.md supporting only |
| Overall | **High (static formula)** | Dual residual strengthened; economy data open |

## Open questions

- Exact float/int payloads in tQuestXPLookup / tExperienceLevel rows (WAD/runtime).
- Negative/zero scaler edge cases.
- Runtime complete XP measurement vs calculator + bias.
- Bit-exact harness.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0059dde0_Mission_ComputeObjectiveXp.md` |
| Annotated | `raw/aa_0059dde0_Mission_ComputeObjectiveXp.annotated.md` |
| Clean | `reconstructed-exact/Mission_ComputeObjectiveXp.cpp` |
| Reviews | `reviews/A_aa_0059dde0_review.md`, `reviews/B_aa_0059dde0_review.md` |
| Scratch | `tmp/a_0059dde0.md` |
| Caller grant | `functions/aa_00533f90_CVOGReaction_CompleteObjective.md` |
| Prior art | `docs/XP.md` (Mission XP section) |
