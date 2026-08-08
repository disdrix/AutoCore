# Dual A/B report — R13-036 OWN-ONLY (`0x0052b140`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-036** (dual start **2686**)  
**Scope:** VA `0x0052b140` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R13 residual dual seal — character discipline learn-requirements gate; partition parent `0x0052b040`.  
**System:** `skills-abilities`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0052b140` CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred | **accept-with-gaps** — CF/ABI/RET4/map/level/prereq-OR/domain sealed; product English + full schema + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): skill-window identity / SkillDefMap merge / AND-prereq / cdecl-bare-RET / pure try-copy / always-require-prereq / mutate / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0052b140` — sealed facts

1. **Body:** `0x0052b140`–`0x0052b2d0` inclusive (**401 B** / `0x191`); pad `CC` from `0x0052b2d1` before `FUN_0052b2e0`.
2. **ABI:** **`__thiscall`** — `ECX` = `CVOGCharacter*`, stack `int disciplineId`; **`RET 4`**; return **bool in AL**.
3. **Semantics:** character **meets discipline learn requirements**:
   - `MOV ECX,0x00b045b0` → `FUN_00538ab0` exact-find; miss if node == **`DAT_00b045b4`** → `AL=0`.
   - Hit: **`REP MOVSD`** **0x7f** dwords (**0x1FC** B) from **`node+0x10`** → stack def.
   - Level: nested vtbl **`+0x27c`** ≥ signed short def **`+0x26`** (else fail).
   - Prereqs: **OR** of five alternate slots — id `@+0x08+4*i` ≠ `-1`, nested **`DisciplineDefMap_TryCopyPayloadById_Inferred`**, **`GetResourceBalanceByType`** ≥ short thr `@+0x1C+2*i`.
   - All five ids **`-1`** + level OK → pass (no prereq alternatives).
4. **Callees:** `FUN_00538ab0`, `FUN_0052b040` (parent dual), `FUN_0052ada0` (dualed balance).
5. **Callers:** **5** functions / **5** UNCONDITIONAL_CALL xrefs:
   - `FUN_0052d180` @ `0x0052d1ce` — train residual fail code **4**
   - `FUN_0082b990` @ `0x0082bb36` — UI; ECX=`DAT_00d1b6d8`
   - `FUN_0084d220` @ `0x0084d277` — tooltip `"Requires Minimum Level of"` / `"Requires: "`
   - `FUN_0084dc10` @ `0x0084df78` — `i_w_skill_2d_wnd_*` chrome
   - `FUN_00931cf0` @ `0x00931cfa` — **`"You do not meet the requirements to learn this Discipline"`**; pass packs opcode **0x2097**
6. **Distinct from:**
   - Parent try-copy leaf `0x0052b040` (cdecl, no character/level/balance).
   - SkillDefMap (`DAT_00b04734` / nil `+0x641`).
   - Balance query alone (`0x0052ada0`).
7. **Name:** `CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred` (Ghidra `FUN_0052b140`). Product method English open → `_Inferred`. Scaffold `Named_CalleeOf_Skill_i_w_skill_2d_wnd_description_xml_0052b140` **retired as identity** (window is a consumer).
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site `MOV ECX` / `TEST AL` / no caller `ADD ESP` cleanup of the discipline arg (callee `RET 4`).

### Gaps

- Product/PDB method English; vtbl `+0x27c` product name.  
- Full `0x1FC` DisciplineDef schema beyond prereq/level fields used here.  
- Balance threshold English (rank vs resource points).  
- Runtime / bit-exact / differential / live map contents.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0052b140_CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0052b140_CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0052b140_FUN_0052b140.md` |
| Annotated | `docs/reconstruction/raw/aa_0052b140_FUN_0052b140.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0052b140.cpp` |
| Function | `docs/reconstruction/functions/aa_0052b140_FUN_0052b140.md` |
| Function named | `docs/reconstruction/functions/aa_0052b140_CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00931cf0  client learn Discipline residual
  ECX = *(client + 0xe98)   // character
  arg = disciplineId (EDI)
  ├─ FUN_0052b140  MeetsDisciplineLearnRequirements  [OWN R13-036]
  │    ├─ FUN_00538ab0  find on map 0x00b045b0
  │    ├─ vtbl+0x27c    level query
  │    ├─ FUN_0052b040  DisciplineDefMap_TryCopyPayloadById  [parent dual R12-020]
  │    └─ FUN_0052ada0  GetResourceBalanceByType             [dualed]
  └─ fail → chat "You do not meet the requirements to learn this Discipline"
     pass → sector opcode 0x2097

FUN_0052d180  train/validate residual
  FUN_0052b140 → fail code 4

FUN_0084d220 / FUN_0084dc10  discipline tooltip / 2d skill window
  same gate for chrome / "Requires …" lines

SkillDefMap_ExactFindByIntKey  0x00418890  [DISTINCT — DAT_00b04734]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0052b140-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0052b140` | Port as **`CVOGCharacter` discipline learn-requirements bool**: exact-find DisciplineDef by id on map `@0x00b045b0`, require level ≥ def`+0x26` (via nested vtbl `+0x27c`), then **OR** of up to five alternate prereq slots (def exists + `GetResourceBalanceByType` ≥ thr) **or** all slots `-1`. **`__thiscall`**, one stack int, **`RET 4`**, bool `AL`. Do **not** AND the five slots. Do **not** merge with SkillDefMap. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (retire scaffold window-callee alias as identity)  
- `systems/skills-abilities.md` residual table  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0052b140`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; twin `FUN_0052b140.cpp` retained.  
- Odd behavior preserved: prereq slots are **OR alternatives**, not AND; empty slots pass after level.  
- `_Inferred` for product method English. Terminal **false**. Never Runtime Confirmed.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
