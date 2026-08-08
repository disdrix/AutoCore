# Dual A/B report — MEGA-091 OWN-ONLY (`0x0059db80`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-091**  
**Scope:** VA `0x0059db80` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_xrefs_to` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — Nested eligibility probe; partition parent `0x0059dc50` Objective-node eligibility gate for tracker.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0059db80` CVOGObjective_ProbeEligibilityCode_Inferred | **accept-with-gaps** — CF/ABI/RET4/pending-hash/eval `+0x8`+`+0x58`/4 callers sealed; product code English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): Named_VOG_DEBUG_STOP / MatchTarget-merge / IsObjectiveReady-merge / parent-gate-merge / void-bare-RET / ECX=character / always-default / true-selects-override claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0059db80` — sealed facts

1. **Body:** `0x0059db80`–`0x0059dc40` inclusive (**193 B** / `0xC1`); pad `CC` before parent `FUN_0059dc50` @ `0x0059dc50`.
2. **ABI:** **ECX** = objective; stack `character*`; **EAX** = int code; **`RET 4`** ×3 exits.
3. **Semantics:** nested **eligibility / tracker-category probe**:
   - Default code `objective+0x120`; if `-1`, fallback `*(objective+0x14c)+0xfc`.
   - Inline pending CNDHash lookup at `character+0x55c` by key `objective+0x10` (mask`+0x8` / buckets`+0x10` / chain`+0xc` / value`+0x8`).
   - Pending miss → return default.
   - Walk evaluators `[objective+0x158, +0x15c)`: if `vtbl+0x8(character, pendingValue)==false` and `vtbl+0x58()` ∉ `{0,−1}`, return that code; else default.
4. **Callees:** none direct (leaf re: named); indirect eval slots only.
5. **Callers (4):** `FUN_0059dc50` @ `0x0059dc75` (`CMP EAX,-1`); `FUN_008a2670` @ `0x008a2703`; `FUN_008a2df0` @ `0x008a3029`; `FUN_008a5240` @ `0x008a546d` (UI category vs `+0x110`).
6. **Xrefs:** 4 UNCONDITIONAL_CALL.
7. **Name:** `CVOGObjective_ProbeEligibilityCode_Inferred` (Ghidra `FUN_0059db80`). Product code English open → `_Inferred`. Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_0059db80` **retired**.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product English for `+0x120` / `def+0xfc` / eval `+0x58` codes (category vs zone vs state).  
- Full requirement-type implementer matrix for `+0x8` / `+0x58`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0059db80_CVOGObjective_ProbeEligibilityCode_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0059db80_CVOGObjective_ProbeEligibilityCode_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0059db80_FUN_0059db80.md` |
| Annotated | `docs/reconstruction/raw/aa_0059db80_FUN_0059db80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObjective_ProbeEligibilityCode_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0059db80.cpp` |
| Function | `docs/reconstruction/functions/aa_0059db80_FUN_0059db80.md` |
| Function named | `docs/reconstruction/functions/aa_0059db80_CVOGObjective_ProbeEligibilityCode_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0059dc50  Objective-node eligibility gate for tracker  [MEGA-025 OWN residual]
  ├─ null character / def flag gates
  ├─ FUN_0059db80  CVOGObjective_ProbeEligibilityCode_Inferred  [OWN MEGA-091]
  │     return == -1 → ineligible
  └─ special def-id band 0xdfd..0xe02 + character level < 5 → ineligible

FUN_0092fd00  tracker active-mission path  [residual]
  └─ FUN_0059dc50(character)  [parent of OWN]

FUN_008a5240 / FUN_008a2670 / FUN_008a2df0  mission tracker UI rebuild
  └─ FUN_0059db80(DAT_00d1b6d8) → category id vs widget+0x110

Contrast (dualed elsewhere; not OWN):
  CVOGObjective_MatchTargetEvaluators  0x0059d9c0  [+0x40 OR]
  CVOGCharacter_IsObjectiveReady       0x0052a020  [char thiscall AND +0x8/+0xc]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0059db80-mega-091-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0059db80` | Port as **objective eligibility/category probe**: default `obj+0x120` (fallback `def+0xfc`), pending lookup `char+0x55c` by `obj+0x10`, evaluator override via false `vtbl+0x8` + non-trivial `vtbl+0x58`. **thiscall RET 4**. Parent treats **−1** as ineligible. Keep distinct from MatchTarget (`+0x40`) and IsObjectiveReady (character AND-walk). |
| Pair with | residual parent gate `0059dc50`; dualed MatchTarget `0059d9c0`; dualed IsObjectiveReady `0052a020`; tracker UI `008a5240` family. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (retire `Named_CalleeOf_Named_VOG_DEBUG_STOP_0059db80`)  
- `systems/*` missions-progression residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0059db80`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_0059db80.cpp` retired (replaced by named clean).  
