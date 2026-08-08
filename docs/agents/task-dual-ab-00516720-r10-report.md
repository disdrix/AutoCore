# Dual A/B report — R10-031 OWN-ONLY (`0x00516720`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-031**  
**Scope:** VA `0x00516720` only. Dual A/B + raw re-verify append + annotated refresh + clean named + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent dual rewrite.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `read_memory` + `get_function_by_address` + callee `batch_decompile`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual seal — partition row R10-031 / skills-abilities residual under dualed parent `0x0051b230`.  
**Name sealed:** **`Object_SetDisplayName_Inferred`** (role yes; product demangle open).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00516720` Object_SetDisplayName_Inferred | **accept-with-gaps** — CF/ABI/thiscall-RET4/`+0x158`/compose-vs-custom/callers sealed; product English + vtbl+0x60 name + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): skill-only / creature-only / cdecl / null-clears-field / always-store / wrong-offset claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00516720` — sealed facts

1. **Body:** `0x00516720`–`0x00516899` exclusive (**377 B** / `0x179`).
2. **ABI:** **`__thiscall`**; `ECX = object*`; stack `char* nameOrNull`; return void; epilogue **`RET 4`** (two sites).
3. **Semantics:** Object **display-name assigner** at `*(self+0x158)`:
   - `nameOrNull == NULL` → no-op (**does not** free/clear `+0x158`).
   - Else free prior `+0x158`, clear to NULL.
   - **Compose path** if `vtbl+0x60() != 0` && `*(self+0xA4) != 0` && `FUN_004ce940() != 0`:
     - `FUN_005146a0` compose (cap `0x5A`) → `strdup` → `+0x158`; return.
   - **Fallback:** template default via `FUN_004eb240(*(self+0xA8))` + wide→MB; `strncmp(name, default, 0x41)`; store input only if differs and `strlen > 1`.
4. **Fields:** `+0x158` name*; `+0xA4` host gate; `+0xA8` template/descriptor.
5. **Callees:** `operator_delete[]`/`operator_new[]`, vtbl+0x60, `FUN_004ce940`, `FUN_007a69d0`, `FUN_007a6880`, `FUN_005146a0`, `FUN_004eb240`, `PTR_FUN_00af8c9c`/`FUN_00403450`, `strncmp`, `free`.
6. **Callers / xrefs (16 UNCONDITIONAL_CALL):**  
   `FUN_004cf120` @ `0x004cf1b2`, `FUN_0051b230` @ `0x0051b282`, `CVOGCreature_PostCreateFromPacket` @ `0x004c5dd0`, `Vehicle_applyCreatePacket` @ `0x005053a0`, `FUN_004f3e40`, `FUN_00503780`, `FUN_004c82b0`, `FUN_00563ab0`, `FUN_00568250`, `FUN_00569bc0`, `FUN_005feb50`, `FUN_005fecb0`, plus `0x005a6d32`, `0x006097d5`, `0x0086b82e`, `0x0086d316`.
7. **Name:** `Object_SetDisplayName_Inferred` (Ghidra `FUN_00516720`). Scaffold `Named_CalleeOf_CVOGCreature_PostCreateFromPacket_00516720` superseded as final English.
8. **Decompile CF ≡ prior raw CF**; ABI/offsets sealed by `read_memory`. Fallback alloc-size decompiler expression is a **trap** — assembly uses saved entry strlen.

### Gaps

- Product English for this VA and vtbl `+0x60`.  
- Concrete type of `FUN_004ce940` singleton / full CString SSO typing.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00516720_Object_SetDisplayName_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00516720_Object_SetDisplayName_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00516720_FUN_00516720.md` |
| Annotated | `docs/reconstruction/raw/aa_00516720_FUN_00516720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_SetDisplayName_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00516720.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_00516720_FUN_00516720.md` |
| Function named | `docs/reconstruction/functions/aa_00516720_Object_SetDisplayName_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0051b230  Object_CreateFromEmbeddedCbid_Inferred  [parent dual; not OWN]
  └─ FUN_00516720  Object_SetDisplayName_Inferred     [OWN R10-031]
        ├─ FUN_005146a0  compose display name (mods/[$swap])
        ├─ FUN_004ce940  name/manager singleton gate
        └─ FUN_004eb240  template default name

FUN_004cf120  AllocateNewObjectFromCbid
  └─ FUN_00516720  [OWN R10-031]

CVOGCreature_PostCreateFromPacket / Vehicle_applyCreatePacket
  └─ FUN_00516720  [OWN R10-031]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00516720-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00516720` | Port as **object display-name setter**. **`__thiscall`**, one stack `char*`, **`RET 4`**. Field **`+0x158`**. Null name = no-op (no clear). Compose when vtbl+0x60 + host `+0xA4` + manager; else store custom only if ≠ template default and len>1. Do **not** treat as skill-only or creature-only. Do **not** trust decompiler fallback alloc-size expression. |
| Pair with | parent `Object_CreateFromEmbeddedCbid` `0x0051b230`; `AllocateNewObjectFromCbid` `0x004cf120`; compose `FUN_005146a0` `0x005146a0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` (object display-name / skills residual tables as applicable)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Not written by this agent.**

**Terminal:** false (runtime open; dual seal complete for OWN VA).
