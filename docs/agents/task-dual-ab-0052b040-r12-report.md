# Dual A/B report — R12-020 OWN-ONLY (`0x0052b040`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-020** (dual start **2646**)  
**Scope:** VA `0x0052b040` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_xrefs_to` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R12 residual dual seal — DisciplineDef map try-copy by id; partition parent `0x00846820`.  
**System:** `skills-abilities`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0052b040` DisciplineDefMap_TryCopyPayloadById_Inferred | **accept-with-gaps** — CF/ABI/RET0/map/copy/domain sealed; product English + full schema + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): VOG stub / SkillDefMap merge / GetResourceBalance identity / thiscall-or-stdcall / always-copy / mutate-map / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0052b040` — sealed facts

1. **Body:** `0x0052b040`–`0x0052b078` inclusive (**57 B** / `0x39`); pad `CC` before `FUN_0052b080` @ `0x0052b080`.
2. **ABI:** **`__cdecl`** — stack `int key`, `void *out`; **bare RET**; callers **`ADD ESP,8`**; return **bool in AL**.
3. **Semantics:** global DisciplineDef ordered-map **try-copy**:
   - `MOV ECX,0x00b045b0` → `FUN_00538ab0` exact-find (nil `@node+0x20d`, key `@+0x0C`, helper `RET 8`).
   - Miss if node == **`DAT_00b045b4`** → `AL=0` (no store).
   - Hit: **`REP MOVSD`** **0x7f** dwords (**0x1FC** B) from **`node+0x10`** → out → `AL=1`.
4. **Callees:** `FUN_00538ab0` only.
5. **Callers:** **19** functions; **41** UNCONDITIONAL_CALL xrefs (incl. partition parent `FUN_00846820` @ `0x00846c34` with `operator_new(0x1fc)` + key from `item+0x4ac` + UI `"Discipline: "` + name `out+0x2A`).
6. **Distinct tables:**
   - **This:** map `0x00b045b0` / end `DAT_00b045b4` / payload `0x1FC` / nil `+0x20d`.
   - **SkillDefMap:** `DAT_00b04734` / nil `+0x641` / larger materialize payload (dualed elsewhere).
   - **Char resource map:** `character+0x584` via `CVOGCharacter_GetResourceBalanceByType` (`0x0052ada0`) — balance query, not def copy.
7. **Name:** `DisciplineDefMap_TryCopyPayloadById_Inferred` (Ghidra `FUN_0052b040`). Product method English open → `_Inferred`. Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_0052b040` **retired**.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site `ADD ESP,8`.

### Gaps

- Product/PDB DisciplineDef / map method English.  
- Full `0x1FC` field schema beyond name consumer `@+0x2A`.  
- Runtime / bit-exact / differential / live map contents.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0052b040_DisciplineDefMap_TryCopyPayloadById_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0052b040_DisciplineDefMap_TryCopyPayloadById_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0052b040_FUN_0052b040.md` |
| Annotated | `docs/reconstruction/raw/aa_0052b040_FUN_0052b040.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DisciplineDefMap_TryCopyPayloadById_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0052b040.cpp` |
| Function | `docs/reconstruction/functions/aa_0052b040_FUN_0052b040.md` |
| Function named | `docs/reconstruction/functions/aa_0052b040_DisciplineDefMap_TryCopyPayloadById_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00846820  item tooltip / requirements residual  [partition parent]
  id = *(itemClone + 0x4ac)
  buf = operator_new(0x1fc)
  ├─ FUN_0052b040  DisciplineDefMap_TryCopyPayloadById_Inferred  [OWN R12-020]
  ├─ FUN_0052ada0  CVOGCharacter_GetResourceBalanceByType       [dualed aa_0052ada0]
  └─ UI "Discipline: " + FUN_00403450(buf + 0x2a)

FUN_0052b140  prereq / eligibility helper
  find skill/def on same map 0x00b045b0
  for each nested id field != -1:
    ├─ FUN_0052b040 (out scratch 0x1FC)
    └─ FUN_0052ada0 threshold compare

SkillDefMap_ExactFindByIntKey  0x00418890  [DISTINCT — DAT_00b04734 / nil+0x641]
SkillDefMap_GetGlobal          0x0054b480  [DISTINCT]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0052b040-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0052b040` | Port as **global DisciplineDef try-copy by int id**: exact-find map `@0x00b045b0`, miss if end `DAT_00b045b4`, else memcpy **0x1FC** from `node+0x10`. **`__cdecl`**, bool `AL`, bare RET. Do **not** merge with SkillDefMap or character resource-balance map. Out buffer must be ≥ `0x1FC` (parent uses `new(0x1fc)`). Name field consumer at **`out+0x2A`** for UI. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (retire `Named_CalleeOf_Named_VOG_DEBUG_STOP_0052b040`)  
- `systems/skills-abilities.md` residual table  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0052b040`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; twin `FUN_0052b040.cpp` retained.  
- Odd behavior preserved: miss leaves out buffer untouched (no zero-fill).  
- `_Inferred` for product method English. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
