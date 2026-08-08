# Dual A/B report — R12-017 OWN-ONLY (`0x0051f8e0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-017**  
**Scope:** VA `0x0051f8e0` (`aa_0051f8e0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-017**.  
**Work item:** Residual dual seal — skills-abilities race display name leaf under craft requirements parent.  
**Hint retired:** `Named_CalleeOf_Named_Combat_0051f8e0` chain plate.  
**Terminal:** **false** (no runtime Confirmed).  
**Dual start:** 2646.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051f8e0` LookupRaceDisplayName_Inferred | **accept-with-gaps** — cdecl leaf / 0·1·2·else product strings / 2 UI callers sealed; product method English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): combat-callee / thiscall / TLS-ring / class-table / stdcall / Runtime Confirmed claims **falsified**; scaffold combat name **retired**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0051f8e0` — sealed facts

1. **Body:** `0x0051f8e0`–`0x0051f90b` exclusive (**43 B** / `0x2B`); terminal RETs at Human/Mutant/Biomek/Unknown arms; pad `CC` before short-code twin `FUN_0051f910` @ `0x0051f910`.
2. **ABI:** **cdecl**; stack **raceId**; plain **`RET`** (`c3`); EAX = `const char*` (static rodata). **Not** thiscall / stdcall.
3. **Semantics:** pure **race id → English display name** leaf (no allocation, no callees):
   - 0 → `"Human"` @ `0x00a40958`
   - 1 → `"Mutant"` @ `0x00a40950`
   - 2 → `"Biomek"` @ `0x00a40948`
   - else → `"Unknown"` @ `0x00a37c4c`
4. **Callers (2):** dualed craft UI `FUN_00846820` @ `0x00846d8c` (**Required Faction** line); item UI `FUN_00845360` @ `0x00845520`.
5. **Xrefs:** 2 UNCONDITIONAL_CALL.
6. **Callees:** none (leaf).
7. **Family:** peer of dualed `LookupClassDisplayName_Inferred` `0x0051f940`; map arms match dualed `Character_GetRaceDisplayName_Inferred` `0x00521800` (wrapper embeds cascade + ring — **do not merge**); short codes `0x0051f910` HUM/MUT/BIO undualed.
8. **Name:** `LookupRaceDisplayName_Inferred` (Ghidra `FUN_0051f8e0`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI + strings sealed via `disassemble_function` + `read_memory` (Ghidra analyze signature `undefined (void)` incomplete, not CF conflict).
10. **Partition parent** `0x00846820` is wave score parent and a live structural caller (craft Required Faction).

### Gaps

- Product / MSVC demangle for race-name helper.  
- Short-code twin `FUN_0051f910` undualed (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051f8e0_LookupRaceDisplayName_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051f8e0_LookupRaceDisplayName_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051f8e0_FUN_0051f8e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051f8e0_FUN_0051f8e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LookupRaceDisplayName_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051f8e0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_Combat_0051f8e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0051f8e0_FUN_0051f8e0.md` |
| Function named | `docs/reconstruction/functions/aa_0051f8e0_LookupRaceDisplayName_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
UI_AppendCraftRequirements_Inferred (0x00846820)  [partition parent; dualed R11-028]
  ├─ def vfunc +0x14 → race id (−1 = none)
  ├─ FUN_0051f8e0  LookupRaceDisplayName_Inferred  [OWN R12-017]
  │     └─ "Human" / "Mutant" / "Biomek" / "Unknown"
  └─ FUN_0051f940  LookupClassDisplayName_Inferred  [dualed WQ9G-E]
        └─ class × race English table

UI_AppendItemRequirements (0x00845360)  [dualed peer]
  └─ FUN_0051f8e0  [same race line]

Character_GetRaceDisplayName_Inferred (0x00521800)  [dualed]
  └─ thiscall + @+0x532 + TLS ring; embeds same 0/1/2 map — do not merge

FUN_0051f910  short race codes HUM/MUT/BIO  [sibling; residual]
```

Partition host "skills-abilities" matches craft/item requirement presentation of race as **"Required Faction"** (product UI string), not a separate faction-id dictionary inside this leaf.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0051f8e0-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0051f8e0` | Port as pure **`raceId → const char*`** table: 0 Human / 1 Mutant / 2 Biomek / else Unknown. cdecl; no free; no ring. |
| Distinct from | Character wrapper `00521800` (thiscall + ring); class table `0051f940`; short codes `0051f910`. |
| Pair with | dualed craft UI `00846820`; dualed item UI `00845360`; dualed class leaf `0051f940`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `LookupRaceDisplayName_Inferred` @ `0x0051f8e0` / `aa_0051f8e0`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x0051f8e0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (cdecl; static return).
- Odd behavior preserved: cascade uses successive sub/jz (not switch table); Unknown covers all non-{0,1,2}.
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
