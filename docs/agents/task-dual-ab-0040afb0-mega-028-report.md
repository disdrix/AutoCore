# Dual A/B report — MEGA-028 OWN-ONLY (`0x0040afb0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-028**  
**Scope:** VA `0x0040afb0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — partition row MEGA-028 / interaction-activation residual under soft-cast parent `0x00925820`.  
**Hint consumed:** `resolve object* from soft-cast hit table` → **caller role** of this shared pair-table leaf (key 1 on hit host), not exclusive product identity.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040afb0` Host_LookupObjectByKey_PairTable30_Inferred | **accept-with-gaps** — CF/ABI/RET8/pair@+0x30/count@+0x34/13 xrefs/keys 1·3·4 sealed; product host English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): soft-cast-only / EAX=object / RET4 / map-tree / VOG_DEBUG product / table-mutate / TFID-resolve claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0040afb0` — sealed facts

1. **Body:** `0x0040afb0`–`0x0040afed` inclusive (**62 B** / `0x3E`); next unit `FUN_0040aff0` @ `0x0040aff0`.
2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = host with pair table  
   - stack `void **outObject`, `int key`  
   - **`RET 8`** both exits (`C2 08 00`)  
   - **EAX = outObject** (out-param return idiom; callers `mov reg, [eax]`)
3. **Semantics:** linear first-match lookup  
   ```text
   count = *(int*)(host + 0x34)
   table = *(Pair**)(host + 0x30)   // Pair { int key; void* value } stride 8
   for i in 0..count-1:
     if table[i].key == key: *out = table[i].value; return out
   *out = NULL; return out
   ```
4. **Callees:** **none** (leaf).
5. **Callers (7 functions / 13 UNCONDITIONAL_CALL sites):**  
   - `FUN_00925820` soft-cast / interaction @ `0x00925c8f` **key 1** (partition parent)  
   - `FUN_004ea350` GetObjectsInArea @ `0x004ea582` / `0x004ea876` / `0x004eaaee` **key 1**  
   - `FUN_005d9ea0` Drive contact prep @ `0x005d9feb` **key 3**, `0x005d9ffb` **key 4**  
   - `FUN_005da0a0` Contact @ `0x005da81a` / `0x005da846` **key 3**  
   - `FUN_005911b0` @ `0x00593160` **key 3**  
   - `FUN_00642b70` @ `0x00642bc8` **key 1**  
   - `FUN_00932c80` @ `0x00932eef` **key 1**  
   - additional sites `0x005dd718` / `0x005dd80d` **key 1**
6. **Xrefs:** 13 `UNCONDITIONAL_CALL`.
7. **Name:** `Host_LookupObjectByKey_PairTable30_Inferred` (Ghidra `FUN_0040afb0`).  
   Retired: `Named_CalleeOf_Named_VOG_DEBUG_STOP_0040afb0` (parent-seed misname; `VOG_DEBUG_STOP` is a distant string in `004ea350` failure path).
8. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product/PDB host type and pair-table English.  
- Full semantic catalog of key IDs beyond observed 1/3/4.  
- Duplicate-key policy beyond first-match (none in body).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040afb0_Host_LookupObjectByKey_PairTable30_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040afb0_Host_LookupObjectByKey_PairTable30_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040afb0_FUN_0040afb0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040afb0_FUN_0040afb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_LookupObjectByKey_PairTable30_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040afb0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_0040afb0.cpp` |
| Function | `docs/reconstruction/functions/aa_0040afb0_FUN_0040afb0.md` |
| Function named | `docs/reconstruction/functions/aa_0040afb0_Host_LookupObjectByKey_PairTable30_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00925820  soft-cast / interaction activation  [partition parent; not OWN]
  └─ FUN_0040afb0  Host_LookupObjectByKey_PairTable30_Inferred  [OWN MEGA-028]
       host ← hit-entry[+0x20] (nested); key=1 → object*

FUN_004ea350  GetObjectsInArea (modes 1/2/aabb)  [residual consumers]
  └─ FUN_0040afb0  ×3  key=1  [OWN MEGA-028]

FUN_005d9ea0  Drive_CollisionListener_PrepBodyContact  [dualed W25-K]
  └─ FUN_0040afb0  ×2  keys 3/4  [OWN MEGA-028]

FUN_005da0a0  Contact sibling
  └─ FUN_0040afb0  key 3  [OWN MEGA-028]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0040afb0-mega-028-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040afb0` | Port as **host pair-table int-key → object\* lookup**. **ECX=host**, stack `out**` + `key`, **RET 8**, **EAX=out**. Layout: pairs @ **+0x30**, count @ **+0x34**, stride **8**, first match, miss→NULL. Do **not** implement as soft-cast ray, TFID resolve, map/set tree, or VOG_DEBUG helper. Keep distinct from consumers (`00925820`, `004ea350`, contact prep). |
| Pair with | soft-cast `00925820`; GetObjectsInArea `004ea350`; dualed `Drive_CollisionListener_PrepBodyContact` `005d9ea0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (interaction-activation + shared host pair-table)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Not written by this agent.**

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0040afb0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; machine twin `FUN_0040afb0.cpp` kept; Named_CalleeOf scaffold **retired**.  
- Odd behavior preserved: decompiler void vs live EAX=out; first-match only; multi-system consumers.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
