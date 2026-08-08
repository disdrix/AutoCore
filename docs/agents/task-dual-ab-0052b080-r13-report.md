# Dual A/B report — R13-035 OWN-ONLY (`0x0052b080`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-035** (dual start **2686**)  
**Scope:** VA `0x0052b080` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_xrefs_to` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R13 residual dual seal — character object difficulty score from resource gap; partition parent `0x0052b040`.  
**System:** `skills-abilities`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0052b080` CVOGCharacter_ComputeObjectDifficultyScore_Inferred | **accept-with-gaps** — CF/ABI/RET4/score/constants/map/domain sealed; product English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): balance-merge / UI-tier-merge / DisciplineDef-adjacency / cdecl / float-stack-arg / rising-with-overlevel / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0052b080` — sealed facts

1. **Body:** `0x0052b080`–`0x0052b13b` inclusive (**188 B** / `0xBC`); pad `CC` before `FUN_0052b140` @ `0x0052b140`.
2. **ABI:** **`__thiscall`** — ECX = **character\***; stack = **target object\***; **`RET 4`**; return **float on x87 ST0** (`FLD`). Decompiler `float` stack type / `undefined` signature is noise.
3. **Semantics:** difficulty **score** from resource gap:
   - null target / null `target+0xa8` → `0.0` (`g_flZero` @ `0x00a0f518`)
   - `clone = *(*(target+0xa8)+0x3c)`; `typeId=@+0x4ac`; `required=@+0x4b0`
   - find on **`character+0x584`** via `FUN_00418b80`; player = `node+0x10` or **−1** if end `character+0x588`
   - player < required → `0.0`
   - player == required → **`100.0`** (`DAT_00aaa7ac`)
   - gap = player − required; gap > **`15.0`** (`DAT_00aaa7a4`) → `0.0`
   - else → **`100.0 − gap × 6.0`** (`DAT_00aaa8dc`)
4. **Callees:** `FUN_00418b80` only.
5. **Callers:** **1** function / **1** UNCONDITIONAL_CALL xref — `FUN_008e4430` (`UI_FormatObjectDifficultyTier_Inferred`) @ `0x008e4484` with `ECX=[DAT_00d1b6d8]`, `PUSH target`, `FSTP` score.
6. **Distinct helpers:**
   - **This:** float score; thiscall character + target; gap formula.
   - **`CVOGCharacter_GetResourceBalanceByType` (`0x0052ada0`):** same map; returns **int** balance / −1.
   - **`UI_FormatObjectDifficultyTier_Inferred` (`0x008e4430`):** maps score + separate balance check → Impossible/Trivial…Very Hard + packed color.
   - **`DisciplineDefMap_TryCopyPayloadById_Inferred` (`0x0052b040`):** partition parent VA only (adjacent residual); global DisciplineDef POD copy — **not** a call parent.
7. **Name:** `CVOGCharacter_ComputeObjectDifficultyScore_Inferred` (Ghidra `FUN_0052b080`). Product method English open → `_Inferred`. Scaffold `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_0052b080` **retired**.
8. **Decompile ≡ raw CF** for score branches; ABI sealed via `disassemble_function` + `read_memory` + call-site `MOV ECX` / `RET 4` / `FSTP`.

### Gaps

- Product/PDB method English.  
- Formal schema names for `clone+0x4ac` / `+0x4b0` beyond UI requirement pairing.  
- Runtime / bit-exact / differential / live balances.  
- Full dual of shared find helper `FUN_00418b80` (not OWN).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0052b080_CVOGCharacter_ComputeObjectDifficultyScore_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0052b080_CVOGCharacter_ComputeObjectDifficultyScore_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0052b080_FUN_0052b080.md` |
| Annotated | `docs/reconstruction/raw/aa_0052b080_FUN_0052b080.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_ComputeObjectDifficultyScore_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0052b080.cpp` |
| Function | `docs/reconstruction/functions/aa_0052b080_FUN_0052b080.md` |
| Function named | `docs/reconstruction/functions/aa_0052b080_CVOGCharacter_ComputeObjectDifficultyScore_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_008e4430  UI_FormatObjectDifficultyTier_Inferred  [dualed W29J]
  ECX = DAT_00d1b6d8 (global character)
  target in EAX/EBX
  player = FUN_0052ada0(clone+0x4ac)          [dualed aa_0052ada0]
  score  = FUN_0052b080(character, target)    [OWN R13-035]
  if player < required → "Impossible"
  else tier by score vs {90,70,50,30,0}

FUN_0052ada0  CVOGCharacter_GetResourceBalanceByType  [dualed]
  same map character+0x584 / FUN_00418b80 → int @ node+0x10 or -1

FUN_00418b80  ordered-map find  [shared helper; not OWN]
  nil @ node+0x19; key @ +0x0C

FUN_0052b040  DisciplineDefMap_TryCopyPayloadById_Inferred  [dualed R12-020]
  partition parent VA only — NOT a caller of 0052b080
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0052b080-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0052b080` | Port as **character thiscall difficulty score**: lookup `character+0x584` by `clone+0x4ac`, compare to `clone+0x4b0`, return float `100 − 6·max(0, player−required)` with hard zeros for under-level, null, and gap>15. **`RET 4`**, float ST0. Do **not** merge with GetResourceBalanceByType (int) or UI tier formatter. Do **not** treat as DisciplineDef map leaf. Share resource-map access with balance helper. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (retire scaffold `Named_CalleeOf_*_0052b080`)  
- `systems/skills-abilities.md` residual table  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0052b080`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; twin `FUN_0052b080.cpp` retained.  
- Odd behavior preserved: gap>15 returns **0.0** (same numeric as under-level); Impossible distinction lives in caller.  
- `_Inferred` for product method English. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
