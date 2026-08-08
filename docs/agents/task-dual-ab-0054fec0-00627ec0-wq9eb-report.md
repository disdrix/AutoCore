# Dual A/B report — WQ9E-B OWN-ONLY (`0x0054fec0`, `0x00627ec0`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9E-B**  
**Scope:** VAs `0x0054fec0`, `0x00627ec0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + xrefs/callers + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth2_partition_map.md` → **WQ9E-B**.  
**Work item:** WQ-009 depth-2 residual dual seal (presence-flag store helper + score consumer of dualed `Skill_ComputeEffectPresenceFlags`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0054fec0` Skill_StoreEffectPresenceFlags_Inferred | **accept-with-gaps** — CF/ABI/store/|4|/0x100000 sealed; zero static callers open |
| `aa_00627ec0` Skill_ComputeEffectScore_Inferred | **accept-with-gaps** — CF/ABI/presence gates/float pool/dual-score callers sealed; product score English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; Evaluate-merge, always-|4, store-vs-score, all-banks confusions falsified.

---

## VA `0x0054fec0` — sealed facts

1. **Body:** `0x0054fec0`–`0x0054fef8` inclusive of final `ret` (**57 B** / `0x39`); pad `CC`.
2. **ABI:** **`__fastcall`/`__thiscall`**; ECX = skill*; void; plain **RET**.
3. **Semantics (presence-flag store helper):**
   - `mask = Skill_ComputeEffectPresenceFlags_Inferred(skill)` (`0x00627be0`, dual WQ9D-E).
   - if `skill+0x620 == 0`: `skill+0x624 = mask`.
   - else: `skill+0x624 = mask | 4`; if `skill+0x148 == 0`: `skill+0x620 |= 0x100000`.
4. **Bytes:** `push esi; mov esi,ecx; call 00627be0; test [esi+0x620]; … or al,4 …`.
5. **Classification:** worker store helper (does **not** Evaluate).
6. **Callers (static):** **none** (xrefs/bulk/data pattern empty). Store tail **duplicated** (inlined) in `Skill_ReevaluateForCurrentRank` (`0x00553390`) after Evaluate — CF-identical twin.
7. **Callee:** `Skill_ComputeEffectPresenceFlags_Inferred` only.
8. **Name:** `Skill_StoreEffectPresenceFlags_Inferred` (Ghidra `FUN_0054fec0`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF** (live 2026-08-04 ≡ raw 2026-07-23).

### Gaps

- Product English for bit `4`, bit `0x100000`, gate `+0x148`.  
- Why this VA has zero static callers (dead extract vs dynamic).  
- Full `+0x624` targeting enum glossary (shared residual).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0054fec0_Skill_StoreEffectPresenceFlags_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0054fec0_Skill_StoreEffectPresenceFlags_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0054fec0_FUN_0054fec0.md` |
| Annotated | `docs/reconstruction/raw/aa_0054fec0_FUN_0054fec0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_StoreEffectPresenceFlags_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0054fec0.cpp` |
| Function | `docs/reconstruction/functions/aa_0054fec0_FUN_0054fec0.md` |
| Function named | `docs/reconstruction/functions/aa_0054fec0_Skill_StoreEffectPresenceFlags_Inferred.md` |

---

## VA `0x00627ec0` — sealed facts

1. **Body:** `0x00627ec0`–`0x00628516` exclusive (**1878 B** / `0x756`); epilogue `add esp,0x10; ret`; pad `CC`.
2. **ABI:** **`__fastcall`/`__thiscall`**; ECX = skill*; **EAX = (int)ceil(score)**; plain **RET**.
3. **Semantics (score consumer):**
   - Call presence leaf; gate weighted terms on bits `1`, `0x100`, `0x40`, `8`, `2`, `0x800`, `0x10`, `0x1000`.
   - Pair weights **0.35/0.5**, slot weights **1.2 / +0.2**, scales with sealed 2.0 / 0.1 / 0.001 / 0.125 / 5.0 / 0.8 / 10000 / ~1/3.
   - Duration/charge post-scales; floor score ≥ **1.0**; return **ceil**.
   - Bits `0x800`/`0x1000` come from base `skill+0xc` (presence leaf ORs them through), not the field-scan portion.
4. **Classification:** pure score worker (no `+0x624` store).
5. **Callers (11 UNCONDITIONAL_CALL):** `FUN_00625b00`×2, `FUN_00618bf0`×2, plus sites `@0x00578730/39`, `@0x0059a0f7/126/163`, `@0x0061fa12/1b`. Pattern: score skillA (often `obj+0x24`) then skillB; compare for HB conflict priority.
6. **Callees:** presence leaf + CRT `ceil`.
7. **Name:** `Skill_ComputeEffectScore_Inferred` (Ghidra `FUN_00627ec0`). Product metric English open → `_Inferred`.
8. **Decompile ≡ raw CF**; floats sealed by `read_memory`.

### Gaps

- Product English for score metric (threat / priority / DPS).  
- Combat labels for each effect bank.  
- Full named dual of every caller host.  
- Runtime / bit-exact / float ulp differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00627ec0_Skill_ComputeEffectScore_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00627ec0_Skill_ComputeEffectScore_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00627ec0_FUN_00627ec0.md` |
| Annotated | `docs/reconstruction/raw/aa_00627ec0_FUN_00627ec0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ComputeEffectScore_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00627ec0.cpp` |
| Function | `docs/reconstruction/functions/aa_00627ec0_FUN_00627ec0.md` |
| Function named | `docs/reconstruction/functions/aa_00627ec0_Skill_ComputeEffectScore_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0054fec0` | Port as **shared store helper** after presence recompute: write `+0x624`; `|4` only when `+0x620!=0`; `|0x100000` on `+0x620` only when `+0x148==0`. Pair with Evaluate inside rank reeval (`Skill_ReevaluateForCurrentRank` may inline). **Do not** Evaluate inside the store helper. **Do not** always OR 4. |
| `00627ec0` | Port as **pure score** of skill fields gated by presence mask; keep float pool + ceil + floor(1.0) stable for dual compares. **Do not** write `+0x624`. Keep bit map locked to `Skill_ComputeEffectPresenceFlags_Inferred`. |
| Pair with | `Skill_ComputeEffectPresenceFlags_Inferred` (`0x00627be0`); `Skill_ReevaluateForCurrentRank` (`0x00553390`); HB dual-score callers (`FUN_00625b00`, `FUN_00618bf0`, …). |

---

## Process

- OWN VAs only (`0x0054fec0`, `0x00627ec0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: store helper zero static callers; Reevaluate inlines twin store; score uses base-flag bits 0x800/0x1000.  
- `_Inferred` where English unproven; Terminal **false**.

### Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md`  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0054fec0-00627ec0-wq9eb-report.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
