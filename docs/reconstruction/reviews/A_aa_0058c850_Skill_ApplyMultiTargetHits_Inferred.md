# Review A (reconstruction fidelity): `aa_0058c850` Skill_ApplyMultiTargetHits_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058c850` |
| **VA** | `0x0058c850`–`0x0058cc3f` (**1008** bytes) |
| **Canonical name** | `Skill_ApplyMultiTargetHits_Inferred` |
| **Prior scaffold** | `FUN_0058c850`, `Named_CalleeOf_Named_VOG_DEBUG_STOP_0058c850` |
| **Review date** | `2026-07-29` (W20-Q dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0058c850_Skill_ApplyMultiTargetHits_Inferred.md` |
| **System** | `skills-abilities` / combat multi-target apply |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher. Own VA only.

---

## 1. Purpose

**Multi-target skill hit apply** over a TFID list:

1. Null list → 0.
2. Build CS-guarded object list (`PTR_FUN_009cb368`, dual `InitializeCriticalSection`).
3. Walk list nodes stride **16** until `(coidLo & coidHi) == 0xffffffff`; `CVOGReaction_ResolveObjectTarget` + push (`FUN_004024d0`).
4. For each listed object (`FUN_0040b020`):
   - Index 0: **skip** accuracy.
   - Index ≥1: `Skill_AccuracyHitCheck_Inferred` with roll from `param_5[(rollIndex % 600)*2]`.
   - Hit: load damage min/max from `param_3+0x54..+0x68`; either vtbl+0x4c method (`+0x140==0`) or modular range roll; scale via `FUN_004cf080` if `> g_flOne`; optional `target[0x33]=4`; `Client_Combat_ApplySingleHitMaybeDefer_Inferred`; accumulate.
   - Miss: pack floater (attacker TFID `+0x160` or `DAT_009d4d28`, target TFID `+0x160`-class at `[0x58..]`) → `Client_EnqueueCombatFloater_INFERRED`.
   - `rollIndex += 6`.
5. Teardown (`FUN_004bcbf0`); return total damage.

**Not** target gather (`Skill_GatherTargetsInArea`), not single-hit primitive alone (`004d7e30`), not accuracy alone (`00553240`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0058c850` |
| Body range | `get_function_by_address` → `0058c850`–`0058cc3f` |
| Entry/exit bytes | `read_memory` 64 B entry; 16 B @ `0x0058cc30` |
| Callers | `get_xrefs_to` / `get_function_callers` → 3 sites |
| Callees | `get_function_callees` |
| Sibling duals | AccuracyHitCheck; ApplySingleHitMaybeDefer |
| Raw / annotated / clean | `aa_0058c850_*`, `Skill_ApplyMultiTargetHits_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, full dual of list helpers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 1008 B, bare `ret` | **Confirmed** | Ghidra body + exit `c3` |
| SEH frame | **Confirmed** | entry `fs:[0]` + `LAB_009a5758` |
| TFID stride 16 / end mask | **Confirmed** | decompile while |
| First target skips accuracy | **Confirmed** | `local_c4 < 1 \|\|` |
| Roll index `*6` / `%600` | **Confirmed** | decompile |
| Return = sum damage | **Confirmed** | `return local_bc` |
| param_4 unused | **Confirmed** | never referenced |
| 3 callers | **Confirmed** | xrefs |
| Role name product English | **Inferred** | no plate string |
| Damage field marketing names | **Tentative** | offsets sealed only |
| Accuracy thiscall arg packing vs sibling dual | **High CF** | live shows `FUN_00553240(param_1,piVar5,roll,&out)` |
| Runtime | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null list → 0 | Yes |
| CS list construct + TFID walk + resolve/push | Yes |
| Empty list teardown → 0 | Yes |
| Per-target accuracy gate (skip first) | Yes |
| Damage load / method vs modular | Yes |
| Scale + apply hit / floater miss | Yes |
| rollIndex += 6; iterate | Yes |
| Return total | Yes |

---

## 5. Gaps / open

1. Product/PDB symbol.
2. Exact C++ type of `param_1` / `param_3` (skill vs effect blob).
3. List object class behind `PTR_FUN_009cb368` / `FUN_0040b020` / `FUN_004bcbf0` (out of owned dual).
4. Full floater block layout English.
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — multi-target damage apply CF, accuracy skip-first, roll table, apply/floater arms, 3 callers, body size sealed; product English / list class residual open.
