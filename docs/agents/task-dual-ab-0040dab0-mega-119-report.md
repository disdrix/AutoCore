# Dual A/B report — MEGA-119 OWN-ONLY (`0x0040dab0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-119**  
**Scope:** VA `0x0040dab0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** HTTP bridge `decompile_function` + `disassemble_function` + `read_memory` + callers/xrefs + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — float XP to int for reward toast (parent `Client_ShowMissionRewardChatToast` `0x008ac540`).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` row MEGA-119 P74.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040dab0` Math_RoundFloatToInt_MissionXpBias_Inferred | **accept** — CF/ABI/plain-RET/SSE body/bias 0.5001f/20 call sites sealed; product demangle open only |

Path A (fidelity): `0040dab0` **accept**.  
Path B (adversarial): grant-authority / toast-only / trunc-only / 0.5f / thiscall / RET4 / banker's / Mission_Bulk claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0040dab0` — sealed facts

1. **Body:** `0x0040dab0`–`0x0040dad7` inclusive (**40 B** / `0x28`); pad `CC` from `0x0040dad8`.
2. **ABI:** stack **float** @ `[ESP+4]`; **EAX** int; plain **`RET`** (`C3`) ×2; **not** thiscall (ECX unused).
3. **Semantics:** signed **half-away-from-zero** float→int:
   - `value < 0` → `(int)(value - g_flMissionXpRoundBias)` via `SUBSS` + `CVTTSS2SI`
   - `value >= 0` → `(int)(value + g_flMissionXpRoundBias)` via `ADDSS` + `CVTTSS2SI`
4. **Bias:** `g_flMissionXpRoundBias` @ **`0x00aaa6d0`** = **0.5001f** (`8e 06 00 3f`).
5. **Callees:** **none** (leaf SSE).
6. **Callers / xrefs:** **20** UNCONDITIONAL_CALL:
   - `Client_ShowMissionRewardChatToast` @ `0x008ac624` (primary dual parent)
   - `FUN_0087d810` ×8; `FUN_00503780` ×4; `FUN_0056a680` @ `0x0056a744`
   - `FUN_0049aa60`, `FUN_005d9290`, `FUN_0054cb10`
   - orphan sites `0x009005dd`, `0x0090063a`, `0x008a45e3`
7. **Name:** `Math_RoundFloatToInt_MissionXpBias_Inferred` (Ghidra `FUN_0040dab0`). Product demangle open → `_Inferred`. **Retired:** `Mission_Bulk_0040dab0`.
8. **Decompile ≡ raw CF**; ABI/bias sealed via `disassemble_function` + `read_memory`.

### Gaps

- Product English name of shared helper.  
- Host fn boundaries for three orphan call sites.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040dab0_Math_RoundFloatToInt_MissionXpBias_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0040dab0_Math_RoundFloatToInt_MissionXpBias_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040dab0_FUN_0040dab0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040dab0_FUN_0040dab0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_RoundFloatToInt_MissionXpBias_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040dab0.cpp` |
| Function | `docs/reconstruction/functions/aa_0040dab0_FUN_0040dab0.md` |
| Function named | `docs/reconstruction/functions/aa_0040dab0_Math_RoundFloatToInt_MissionXpBias_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
Client_ShowMissionRewardChatToast  [0x008ac540 dualed parent]
  ├─ Mission_ComputeObjectiveXp          // gate / already-received branch
  ├─ Mission_ComputeObjectiveXpAsFloat   [0x0051f510]
  │     └─ Mission_ComputeObjectiveXp    [0x0059dde0]
  └─ Math_RoundFloatToInt_MissionXpBias_Inferred  [OWN MEGA-119 0x0040dab0]
        → "Awarded %d ..." + Client_EnqueueCombatFloater

CVOGReaction_CompleteObjective  [grant — not this unit]
  └─ Mission_ComputeObjectiveXp
        then inline ± g_flMissionXpRoundBias + CVOGReaction_AddExperience
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0040dab0-mega-119-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040dab0` | Port as **signed float→int round** with bias **0.5001f** (`g_flMissionXpRoundBias`). Stack float, **EAX** int, plain **RET**. Do **not** use bare `(int)x`. Keep distinct from grant-path inline ±bias + `AddExperience`. Shared utility — not toast-only. |
| Pair with | dualed toast parent `008ac540`; dualed float wrapper `0051f510`; dual residual `Mission_ComputeObjectiveXp` `0059dde0`; constant `0x00aaa6d0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may lockstep:

- `VERIFICATION_MATRIX.md` / coverage ledgers for `aa_0040dab0` → **accept**
- Retire any residual `Mission_Bulk_0040dab0` / `Named_CalleeOf_*0040dab0` index rows
- Terminal remains **false** until runtime Confirmed
