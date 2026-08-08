# Dual A/B report — MEGA-124 OWN-ONLY (`0x004111d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-124**  
**Scope:** VA `0x004111d0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `analyze_function_completeness`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md`  
**Role hint:** Level-cap clamp for XP toast.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004111d0` Character_GetXpRemainingToMaxLevelSoftCap_Inferred | **accept-with-gaps** — CF/ABI/formula/2 toast sites/callee sealed; product English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): authority-grant / current-level / thiscall / scaffold-name claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004111d0` — sealed facts

1. **Body:** `0x004111d0`–`0x004111e9` inclusive (**26 B** / `0x1A`); pad `CC`×6 before `FUN_004111f0` @ `0x004111f0`.
2. **ABI:** **ESI** = character\*; **EAX** = int; bare **`RET`** (`C3`). No stack formals.
3. **Semantics:** max-level soft-cap **remaining XP**:
   - `threshold = Experience_GetCumulativeThreshold(*(ushort*)(char + 0xc50))`  // maxLevel
   - `return threshold − *(int*)(char + 0x730) − 1`  // totalXp, soft-cap policy
4. **Callees:** `Experience_GetCumulativeThreshold` @ `0x0052c860` only (cdecl; `ADD ESP,4`).
5. **Callers (2 UNCONDITIONAL_CALL):** `Client_ShowMissionRewardChatToast` @ `0x008ac63d`, `0x008ac64c`.
6. **Caller use:** when `char+0x6b4 < 1` and scaled award ≥ remaining → clamp award to remaining (toast display only).
7. **Name:** `Character_GetXpRemainingToMaxLevelSoftCap_Inferred` (Ghidra `FUN_004111d0`). **Retire** `Named_CalleeOf_Client_ShowMissionRewardChatToast_004111d0`.
8. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.

### Full body hex (26 B)

```
668b86500c000050e883b611002b863007000083c40483e801c3
```

### Gaps

- Product English for caller gate `char+0x6b4` (specialMode/GM — parent inference).  
- Negative remaining if total already above soft-cap (no floor in body).  
- Product demangle open → `_Inferred`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004111d0_Character_GetXpRemainingToMaxLevelSoftCap_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004111d0_Character_GetXpRemainingToMaxLevelSoftCap_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004111d0_FUN_004111d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004111d0_FUN_004111d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_GetXpRemainingToMaxLevelSoftCap_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004111d0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_ShowMissionRewardChatToast_004111d0.cpp` |
| Function | `docs/reconstruction/functions/aa_004111d0_FUN_004111d0.md` |
| Function named | `docs/reconstruction/functions/aa_004111d0_Character_GetXpRemainingToMaxLevelSoftCap_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_ShowMissionRewardChatToast  (0x008ac540)  [dualed parent]
  ├─ Mission_ComputeObjectiveXp
  ├─ FUN_0051f510  scaler
  ├─ FUN_0040dab0  float→int
  ├─ if char+0x6b4 < 1:
  │     remaining = FUN_004111d0  Character_GetXpRemainingToMaxLevelSoftCap_Inferred  [OWN MEGA-124]
  │     if remaining <= award: award = remaining
  ├─ sprintf "Awarded %d …" + chat/floater
  └─ Mission_ComputeObjectiveCredits path

FUN_004111d0
  └─ Experience_GetCumulativeThreshold (0x0052c860)  [dualed table helper]

Soft-cap twin (writes totalXp = threshold−1 when at max):
  CVOGReaction_AddExperience
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004111d0-mega-124-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004111d0` | Port as **register customcall**: **ESI=character**, bare ret, returns `threshold(maxLevel) − totalXp − 1`. Use for **display clamp** of mission XP toast, not authority grant. Pair with `Experience_GetCumulativeThreshold` and parent gate `char+0x6b4 < 1`. |
| Pair with | dualed toast `Client_ShowMissionRewardChatToast` (`008ac540`); dualed table `Experience_GetCumulativeThreshold` (`0052c860`); soft-cap write twin `CVOGReaction_AddExperience`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `COVERAGE_LEDGER.md` / coverage JSON if used
- `NAMING_REGISTRY.md` entry for `Character_GetXpRemainingToMaxLevelSoftCap_Inferred`
- Retire any `Named_CalleeOf_*` ledger alias for `aa_004111d0`
