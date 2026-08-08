# Dual A/B report — R13-037 OWN-ONLY (`0x00538ab0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-037** (dual start **2686**)  
**Scope:** VA `0x00538ab0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent `0x0052b040` re-dual, sibling residual callers).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_xrefs_to` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-037**.  
**System:** `skills-abilities`.  
**Parent dual:** `0x0052b040` DisciplineDefMap_TryCopyPayloadById_Inferred (R12-020).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00538ab0` DisciplineDefMap_ExactFindByIntKey_Inferred | **accept-with-gaps** — CF/ABI/RET8/nil+0x20d/key+0x0C/domain sealed; product English + full schema + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): open-lower_bound / SkillDefMap-merge / nearby-00538a40-merge / hash-scan / mutate-map / value-return / cdecl-on-find / exclusive-try-copy-caller / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00538ab0` — sealed facts

1. **Body:** `0x00538ab0`–`0x00538b17` inclusive (**104 B** / `0x68`); pad `CC` from `0x00538b18`.
2. **ABI:** **`__thiscall`** ECX=`MapHeader*`; stack `Node **pOut`, `int *pKey`; dual exits **`RET 8`** (`C2 08 00` @ `0x00538b00` / `0x00538b15`). EAX returns `pOut` (callers `MOV EAX,[EAX]` for node*).
3. **Semantics:** MSVC-style **ordered-map exact find**:
   - head = `*(this+4)`; root = `head[1]`; lower_bound walk.
   - Nil byte **`@node+0x20d`**; signed int key **`@+0x0C`**; left `*node`; right `node+8`.
   - Exact gate: `cand != head && cand.key <= *pKey` (walk invariant ⇒ equality).
   - Miss → `*pOut = head` (image end **`DAT_00b045b4`** on global table).
   - Hit → `*pOut = cand`.
4. **Callees:** none (leaf; read-only aside from `*pOut` store).
5. **Callers:** **9** functions; **9** UNCONDITIONAL_CALL xrefs — all `MOV ECX,0x00b045b0` before CALL:
   - `FUN_0052b040` @ `0x0052b050` (parent try-copy — dualed R12-020)
   - `FUN_0052b140` @ `0x0052b167` (prereq / eligibility residual)
   - `FUN_0052d030` @ `0x0052d054`
   - `FUN_0052d0b0` @ `0x0052d0dc`
   - `FUN_0052d180` @ `0x0052d1a7`
   - `FUN_0052d280` @ `0x0052d2b0`
   - `FUN_0052d450` @ `0x0052d6fd`
   - `FUN_0052dff0` @ `0x0052e01b`
   - `FUN_0052e0e0` @ `0x0052e0ff`
6. **Distinct tables / helpers:**
   - **This:** map `0x00b045b0` / end `DAT_00b045b4` / nil `+0x20d` / key `+0x0C` / payload `+0x10` size **0x1FC** (caller).
   - **SkillDefMap exact find:** `0x00418890` / nil `+0x641` / header `DAT_00b04734`.
   - **Nearby** `0x00538a40` Map_FindByIntKey: nil `+0x49` / key `+0x10` — **different tree**.
   - **Cast-binding** `0x0051c150`: nil `+0x29` / key `+0x10`.
7. **Name:** `DisciplineDefMap_ExactFindByIntKey_Inferred` (Ghidra `FUN_00538ab0`). Product method English open → `_Inferred`. Scaffold `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00538ab0` **retired**.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + parent/sibling call-site hardcodes.

### Gaps

- Product/PDB DisciplineDef / map method English.  
- Full node field schema beyond key / links / nil / payload base.  
- Runtime / bit-exact / differential / live map contents.  
- Residual dual of sibling callers (`0052b140`, `0052d*`, …) — out of OWN scope.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00538ab0_DisciplineDefMap_ExactFindByIntKey_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00538ab0_DisciplineDefMap_ExactFindByIntKey_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00538ab0_FUN_00538ab0.md` |
| Annotated | `docs/reconstruction/raw/aa_00538ab0_FUN_00538ab0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DisciplineDefMap_ExactFindByIntKey_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00538ab0.cpp` |
| Function | `docs/reconstruction/functions/aa_00538ab0_FUN_00538ab0.md` |
| Function named | `docs/reconstruction/functions/aa_00538ab0_DisciplineDefMap_ExactFindByIntKey_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0052b040  DisciplineDefMap_TryCopyPayloadById_Inferred  [parent dual R12-020]
  MOV ECX, 0x00b045b0
  ├─ FUN_00538ab0  DisciplineDefMap_ExactFindByIntKey_Inferred  [OWN R13-037]
  └─ on hit: REP MOVSD 0x7f dwords from node+0x10 → out (0x1FC)

FUN_0052b140  prereq / eligibility residual
  same map find → copy 0x1FC scratch → nested FUN_0052b040 + GetResourceBalanceByType

FUN_0052d030 / 0052d0b0 / 0052d180 / 0052d280 / 0052d450 / 0052dff0 / 0052e0e0
  DisciplineDef map accessors (same header hardcode)  [residual]

SkillDefMap_ExactFindByIntKey  0x00418890  [DISTINCT — DAT_00b04734 / nil+0x641]
Map_FindByIntKey               0x00538a40  [DISTINCT — nil+0x49 / key+0x10]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00538ab0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00538ab0` | Port as **global DisciplineDef map exact find by int id**: thiscall on map `@0x00b045b0`, nil `@node+0x20d`, key `@+0x0C`, miss if end `*(map+4)` / `DAT_00b045b4`. **`RET 8`**, result via `*pOut` (EAX=`pOut`). Do **not** treat as open lower_bound. Do **not** merge with SkillDefMap find or nearby `0x00538a40`. Payload materialize is **caller** (`node+0x10`, **0x1FC**). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (retire `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00538ab0`)  
- `systems/skills-abilities.md` residual table  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00538ab0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; twin `FUN_00538ab0.cpp` retained.  
- Odd behavior preserved: miss writes end only (no zero-fill of caller buffers — that is parent responsibility).  
- `_Inferred` for product method English. Terminal **false**. Never Runtime Confirmed.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
