# Dual A/B report — R13-032 OWN-ONLY (`0x0051f910`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-032**  
**Scope:** VA `0x0051f910` (`aa_0051f910`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including English twin re-dual, class short `0051fa10`, caller `00871150`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-032**.  
**System:** skills-abilities.  
**Parent dual:** `0x0051f8e0` LookupRaceDisplayName_Inferred (R12-017).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).  
**Hint retired:** `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGClient_0051f910` chain plate.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051f910` LookupRaceShortCode_Inferred | **accept-with-gaps** — cdecl leaf / 0·1·2·else short codes / sole UI caller sealed; product method English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): VOG-chain / thiscall / English-merge / class-short-merge / path-suffix-merge / ring / stdcall / Runtime Confirmed claims **falsified**; scaffold VOG name **retired**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0051f910` — sealed facts

1. **Body:** `0x0051f910`–`0x0051f93b` exclusive (**43 B** / `0x2B`); terminal RETs at HUM/MUT/BIO/Unknown arms; pad `CC` before dualed class leaf `FUN_0051f940` @ `0x0051f940`.
2. **ABI:** **cdecl**; stack **raceId**; plain **`RET`** (`c3`); EAX = `const char*` (static rodata). **Not** thiscall / stdcall.
3. **Semantics:** pure **race id → 3-letter short code** leaf (no allocation, no callees):
   - 0 → `"HUM"` @ `0x009cef04`
   - 1 → `"MUT"` @ `0x009cef08`
   - 2 → `"BIO"` @ `0x009cef0c`
   - else → `"Unknown"` @ `0x00a37c4c` (shared with English twin)
4. **Callers (1):** residual UI host `FUN_00871150` @ `0x00871273` — formats `"%d/%s/%s"` @ `0x00a5caf8` as level / class-short (`FUN_0051fa10`) / race-short (this unit).
5. **Xrefs:** 1 UNCONDITIONAL_CALL (same).
6. **Callees:** none (leaf).
7. **Family:** twin of dualed `LookupRaceDisplayName_Inferred` `0x0051f8e0` (English Human/Mutant/Biomek — **do not merge**); peer of dualed `LookupClassDisplayName_Inferred` `0x0051f940`; class short residual `0x0051fa10`; path suffix dualed `0x0051f550` (`_h/_m/_b` — different API).
8. **Name:** `LookupRaceShortCode_Inferred` (Ghidra `FUN_0051f910`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI + strings sealed via `disassemble_function` + `read_memory` (Ghidra analyze signature `undefined (void)` incomplete, not CF conflict).
10. **Partition parent** `0x0051f8e0` is English race display twin (same cascade shape, different strings).

### Gaps

- Product / MSVC demangle for short-code helper.  
- Host English name / dual of sole caller `FUN_00871150`.  
- Dual of class-short peer `FUN_0051fa10` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051f910_LookupRaceShortCode_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051f910_LookupRaceShortCode_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051f910_FUN_0051f910.md` |
| Annotated | `docs/reconstruction/raw/aa_0051f910_FUN_0051f910.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LookupRaceShortCode_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051f910.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGClient_0051f910.cpp` |
| Function | `docs/reconstruction/functions/aa_0051f910_FUN_0051f910.md` |
| Function named | `docs/reconstruction/functions/aa_0051f910_LookupRaceShortCode_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00871150  UI host (residual)
  ├─ packed byte @+0x1e  (high nibble class / low nibble race)
  ├─ FUN_0051fa10  class short COM/ENG/…×race  [residual]
  ├─ FUN_0051f910  LookupRaceShortCode_Inferred  [OWN R13-032]
  │     └─ "HUM" / "MUT" / "BIO" / "Unknown"
  └─ sprintf("%d/%s/%s", level, classShort, raceShort)

LookupRaceDisplayName_Inferred (0x0051f8e0)  [partition parent; dualed R12-017]
  └─ same 0/1/2 cascade → "Human" / "Mutant" / "Biomek" / "Unknown"  — do not merge

LookupClassDisplayName_Inferred (0x0051f940)  [dualed]
BuildRaceClassSuffix_Inferred (0x0051f550)    [dualed; path tokens _h/_m/_b]
Character_GetRaceDisplayName_Inferred (0x00521800)  [dualed; thiscall + ring]
```

Partition system **skills-abilities** matches client race/class presentation helpers (short codes for compact UI lines; English twin for craft/item requirement text).

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0051f910-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0051f910` | Port as pure **`raceId → const char*`** short table: 0 HUM / 1 MUT / 2 BIO / else Unknown. cdecl; no free; no ring. |
| Distinct from | English twin `0051f8e0`; class short `0051fa10`; path suffix `0051f550`; character wrapper `00521800`. |
| Pair with | dualed English twin `0051f8e0`; residual UI host `00871150`; residual class short `0051fa10`. |
| Naming caution | **Not** English display. **Not** class short. **Not** path suffix. **Not** VOGClient method. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Name to register:** `LookupRaceShortCode_Inferred` @ `0x0051f910` / `aa_0051f910`.  
**Verdict:** **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x0051f910`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + get_assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (cdecl; static return).  
- Odd behavior preserved: cascade uses successive sub/jz (not switch table); Unknown covers all non-{0,1,2}; shared Unknown rodata with English twin.  
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
