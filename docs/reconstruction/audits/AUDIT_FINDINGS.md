# Audit Findings — AUDIT-2026-08-05-01

Severity: **Critical** > **Major** > **Moderate** > **Minor**

Each finding: ID, severity, evidence, impact, corrective action pointer.

---

## Critical

### F-001 — Inventory `full` / `terminal_full_coverage` overstates reconstruction depth

| Field | Value |
|-------|-------|
| Severity | **Critical** |
| Evidence | `progress.json` `full_coverage`/`terminal_full_coverage` true; inventory full=17042; function-record head scan **15299/18800 (81.4%)** still say **Partial scaffold**; sample records (e.g. `aa_0048dde0`) explicitly “scaffold; refine for important units” |
| Confirmed | Three-rep artifacts usually exist (raw/annotated/clean + record) |
| Incorrect | Interpreting inventory terminal as dual-reviewed or behaviorally complete reconstruction |
| Impact | External readers / future agents treat ~17k functions as done; prioritization and confidence collapse |
| Related | F-002, F-003, SR-01 |
| Action | CAP-001 |

### F-002 — Dual depth not reflected in inventory `reviewed` status

| Field | Value |
|-------|-------|
| Severity | **Critical** |
| Evidence | Dual A∩B on disk **~2709–2724** during audit; inventory `reviewed` **121**; all 121 reviewed had duals, but **~2500+ duals** remain status=`full` |
| Impact | Cannot query “what was dual-reviewed” from inventory; progress dashboards lie by omission |
| Action | CAP-002 |

### F-003 — Progress metrics desync from filesystem (reproducible test failure)

| Field | Value |
|-------|-------|
| Severity | **Critical** |
| Evidence | `python -m unittest discover -s docs/reconstruction/experiments` → `test_progress_dual_matches_filesystem_A_and_B` **FAIL** (`2686 != 2705` at failure time; dual count continued rising with R13) |
| Impact | Automated honesty gate already red; CHANGE_LOG seals claiming exact dual counts are untrustworthy without re-count |
| Action | CAP-003 |

---

## Major

### F-027 — HasCompletedMission mode gate `this` is attach object, not character (porting footgun)

| Field | Value |
|-------|-------|
| Severity | **Major** |
| Evidence | Independent adversarial audit: at `0x0052aa72` / `0x0052aa98` assembly loads continent attach (`…+0xa8`) into **ECX** before `CALL 0x004ce340` (`WeaponAllowsKillXpBonus`). Same pattern at GiveMission / AddExperience sites. Clean `CVOGCharacter_HasCompletedMission.cpp` calls `WeaponAllowsKillXpBonus()` with no object — decompiler-elided thiscall. Fields `+0x100`/`+0xac` live on **attach**, not `CVOGCharacter`. |
| Confirmed | Dual-hash boolean structure still correct |
| Incorrect | Implicit character-as-mode-this in clean/docs plates |
| Impact | Any port that calls mode gate on character `this` is wrong |
| Related work | GiveMission, AddExperience, aa_004ce340 duals may share plate error |
| Action | CAP-019 — fix clean + function record + dual notes; re-verify siblings |

### F-004 — Residual dual waves prioritize STL / leaf `FUN_*` over unfinished user-facing verticals

| Field | Value |
|-------|-------|
| Severity | **Major** |
| Evidence | mtime sample of 80 recent dual A reviews: **67** STL/FUN/Inferred vs **12** user-facing-ish; R13 partition almost entirely `FUN_*` callees of dualed parents; WQ-001..008 still **partial** with runtime open |
| Impact | Dual count rises while DriveControlTick, mission runtime correlation, inventory wire live paths remain open |
| Action | CAP-004 |

### F-005 — Runtime / differential verification is effectively absent

| Field | Value |
|-------|-------|
| Severity | **Major** |
| Evidence | `RUNTIME_EXPERIMENTS.md` empty; VERIFICATION_MATRIX Runtime column **N** for listed units; experiments tests are structural/gate-model, not live client |
| Impact | No unit can honestly claim Confirmed external behavior; “sealed” is static-only |
| Action | CAP-005 (requires Launcher approval for live) |

### F-006 — Ghidra database types lag reconstruction docs

| Field | Value |
|-------|-------|
| Severity | **Major** |
| Evidence | `analyze_function_complete` on `0x004f5620`: signature `undefined VehicleEntity_SetSteerInput(void)`, `return_type_resolved=false`, params still `int`/`undefined4` despite High docs and byte-sealed body |
| Impact | Future decompiles reintroduce weak types; docs and Ghidra diverge |
| Action | CAP-006 |

### F-007 — Verification matrix integrity broken for some rows

| Field | Value |
|-------|-------|
| Severity | **Major** |
| Evidence | Truncated rows e.g. `aa_006070e0`, `aa_005711c0` (only priority fragment); ≥7 short rows; mid-file confidence table for `aa_004f5620` interrupts the matrix then more rows append |
| Impact | Matrix cannot be machine-parsed; claims for those IDs are incomplete |
| Action | CAP-007 |

### F-008 — “Sealed” language used for static dual accept-with-gaps

| Field | Value |
|-------|-------|
| Severity | **Major** |
| Evidence | CHANGE_LOG / system maps: “sealed”, “dual residual sealed”, “High” while same units Runtime N, product English open, names `*_Inferred` |
| Impact | Agents treat static dual as completion; uncertainty is easy to skip |
| Action | CAP-008 |

### F-009 — Industrial clean sources remain decompiler pseudocode, not maintainable product-like code

| Field | Value |
|-------|-------|
| Severity | **Major** |
| Evidence | Random full cleans retain `FUN_*`, auto CF headers, tentative types; purpose often “Scaffold unit”; not vertical readable modules |
| Impact | Fails requirement “maintainable source-like code rather than polished Ghidra pseudocode” for bulk |
| Action | CAP-009 (scope: HP only first) |

### F-010 — ACTIVE_WORK / RESUME claim R13 wave state without durable dual accounting

| Field | Value |
|-------|-------|
| Severity | **Major** |
| Evidence | ACTIVE_WORK: R13 in flight, dual start 2686; mid-audit R13 dual complete **23/40** and global dual already **>2700**; progress.json not refreshed |
| Impact | Parallel agents can double-dual or under-count |
| Action | CAP-003, CAP-010 |

### F-011 — Experiment corpus stale vs current scale

| Field | Value |
|-------|-------|
| Severity | **Major** |
| Evidence | `unittest_discover_output.txt` preflight cites function_records=55, reviews=42 — orders of magnitude below current; live suite has stronger tests but still fails dual match |
| Impact | Historical “all tests pass” notes are misleading |
| Action | CAP-011 |

---

## Moderate

### F-012 — Encoding corruption in durable ledgers

| Field | Value |
|-------|-------|
| Severity | **Moderate** |
| Evidence | WORK_QUEUE / COVERAGE_LEDGER / system maps show `Ã¢â‚¬â€`, `â†’`, mojibake arrows/dashes |
| Impact | Human readability and some string searches fail |
| Action | CAP-012 |

### F-013 — Naming registry incomplete relative to dual/inferred mass renames

| Field | Value |
|-------|-------|
| Severity | **Moderate** |
| Evidence | NAMING_REGISTRY large but dual A `*_Inferred` ≈ 1202; many dual names never enter registry rows |
| Impact | Canonical name conflicts / drift |
| Action | CAP-013 |

### F-014 — Type registry thin vs claimed object-layout recovery

| Field | Value |
|-------|-------|
| Severity | **Moderate** |
| Evidence | TYPE_REGISTRY ~14 lines (drive axes focus); OBJECT_LAYOUTS partial Vehicle/InventoryGrid/Client skill region only |
| Impact | Acceptable if scoped; not “foundational types before mass rename” at program scale |
| Action | CAP-014 |

### F-015 — Inventory system tags almost unused

| Field | Value |
|-------|-------|
| Severity | **Moderate** |
| Evidence | inventory.jsonl systems Counter: **None for 25664 / 25671** |
| Impact | Cannot filter work by system from inventory |
| Action | CAP-015 |

### F-016 — Dual reviews often “OWN-ONLY” same partition agent for A and B roles

| Field | Value |
|-------|-------|
| Severity | **Moderate** |
| Evidence | Recent dual headers: “OWN-ONLY dual R12-013 Path A” with counterpart B same wave owner pattern; text independent but same agent chain |
| Impact | Independence weaker than two fully separate reasoners; still better than single review |
| Action | CAP-016 |

### F-017 — Test failure: industrial clean with `undefined4` without scaffold note

| Field | Value |
|-------|-------|
| Severity | **Moderate** |
| Evidence | `test_sampled_records_resolve_raw_and_clean_by_address` fail on `aa_00922270_Input_TryFirePrimaryWeapons_Inferred` |
| Impact | Clean policy inconsistency |
| Action | CAP-017 |

### F-018 — Callers/callees empty on industrial function records

| Field | Value |
|-------|-------|
| Severity | **Moderate** |
| Evidence | Scaffold records: “Populate from Ghidra xrefs in follow-up.” |
| Impact | Vertical behavior not reconstructed for those units |
| Action | CAP-009 |

### F-019 — High dual confidence without instruction evidence on some older units

| Field | Value |
|-------|-------|
| Severity | **Moderate** |
| Evidence | Matrix older rows claim CF Y / Ind.rev Y while open issues still list major ABI/name gaps; not all duals have `read_memory` seals |
| Impact | Confidence inflation risk outside byte-sealed set |
| Action | CAP-008 |

### F-020 — Parallel residual waves create dual-count race

| Field | Value |
|-------|-------|
| Severity | **Moderate** |
| Evidence | Dual count moved 2686→2705→2709→2724 during single audit session |
| Impact | Sealed numbers in CHANGE_LOG immediately stale |
| Action | CAP-010 |

---

## Minor

### F-021 — Comment on clean InventoryGrab misstates refresh vtbl in prose header

| Field | Value |
|-------|-------|
| Severity | **Minor** |
| Evidence | Header step “UI refresh … (vtbl+0x3ac)” but body correctly uses +0x3ac for GetObject and **+4** for `DAT_00d1d8dc` refresh — matches live decompile/bytes |
| Impact | Comment drift only; code OK |
| Action | CAP-018 (doc fix) |

### F-022 — `get_function_count` vs `list_functions_enhanced` confusion remains in docs

| Field | Value |
|-------|-------|
| Severity | **Minor** |
| Evidence | Ledger correctly warns 26263 inflated vs 25671; still easy to misuse |
| Action | CAP-001 note |

### F-023 — Physics verified corpus large while priority says physics last

| Field | Value |
|-------|-------|
| Severity | **Minor** |
| Evidence | Extensive `physics/verified/` prior art retained (allowed) but can pull attention |
| Action | Keep deferred; no mass rework |

### F-024 — Named_CalleeOf_* clean proliferation

| Field | Value |
|-------|-------|
| Severity | **Minor** |
| Evidence | Many `Named_CalleeOf_*` cpp files for DriveControlTick/CompleteObjective trees |
| Impact | Namespace noise; not necessarily wrong |
| Action | CAP-013 |

### F-025 — Trivial-batch appears legitimate (Unwind@/Catch@)

| Field | Value |
|-------|-------|
| Severity | **Minor** (positive finding) |
| Evidence | Random trivial samples are SEH Unwind/Catch — appropriate for batch accounting |
| Action | None |

### F-026 — Dual A/B text independence is real

| Field | Value |
|-------|-------|
| Severity | **Minor** (positive) |
| Evidence | Jaccard mean ~0.31; 0 pairs >0.85 in 100 recent |
| Action | Retain dual format; strengthen true independence (CAP-016) |

---

## Finding counts

| Severity | Count |
|----------|------:|
| Critical | 3 |
| Major | 9 |
| Moderate | 9 |
| Minor | 6 |
| **Total** | **27** |

Positive / mitigating: F-025, F-026, plus deep HP sample accuracy (see SAMPLED_ITEMS).
