# Dual A/B report — R12-038 OWN-ONLY (`0x005ebf00`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-038**  
**Scope:** VA `0x005ebf00` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_xrefs_to` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R12 residual dual seal — sphere-query collect complete dtor; partition parent `0x005eb210` `VOGPhysics_QueryObject_BaseCtor_Inferred`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` row R12-038.  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005ebf00` VOGPhysics_SphereQueryCollect_Dtor_Inferred | **accept-with-gaps** — CF/ABI/thiscall/tail-JMP/triad+0xC0/stride-8/tag-0x12/1 caller sealed; product English + element type + residual base/scalar duals + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): scalar-merge / base-merge / ctor-merge / sibling-merge / wrong ABI / outer-free / stride-4 claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005ebf00` — sealed facts

1. **Body:** `0x005ebf00`–`0x005ebf67` inclusive (**104 B** / `0x68`); pad `CC` from `0x005ebf68`.
2. **ABI:** **ECX** = self (0xD0 sphere-query collect object*); **no stack args**; ends in **JMP** `FUN_006343d0` with ECX=self (not RET).
3. **Semantics:** complete-object **destructor** for dualed sphere collect type:
   - Reinstall derived vtbl `PTR_FUN_009dce90`.
   - Reverse-walk collect buffer **`+0xC0`** with count **`+0xC4`**, element stride **8**; per entry thiscall vtbl slot **`+0x14`** release.
   - Zero count; if capacity **`+0xC8` ≥ 0**, free buffer via `DAT_00b05060` vfunc **`+0x14`**, size `(cap&0x7fffffff)*8`, tag **`0x12`**.
   - Tail-jump base dtor `FUN_006343d0` (0xC0 core teardown).
4. **Does not** free outer object (scalar-deleting peer `FUN_005ebf70` does free size@+4 tag **0x2C** when `flags&1`).
5. **Callees:** dynamic element vcall; allocator free; tail `FUN_006343d0`.
6. **Callers / xrefs:** **1** UNCONDITIONAL_CALL:
   - `FUN_005ebf70` @ `0x005ebf73` (scalar-deleting dtor; vtbl `009dce90` slot0)
7. **Peers (evidence only):** dualed ctor `FUN_005ebec0` / `VOGPhysics_SphereQueryCollect_Ctor_Inferred`; dualed base ctor `FUN_005eb210`; residual scalar `FUN_005ebf70`; residual base dtor `FUN_006343d0`; sibling ctor `FUN_005eb790` (vtbl `009dce20`).
8. **Name:** `VOGPhysics_SphereQueryCollect_Dtor_Inferred` (Ghidra `FUN_005ebf00`). Product class English open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` (assembly corrects `__fastcall` display and free-size mask).

### Gaps

- Product/PDB class name for vtbl `009dce90`.  
- Exact 8-byte collect element type beyond first-dword object*.  
- Semantic of element release slot `+0x14`.  
- Residual duals `006343d0` / `005ebf70`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005ebf00_VOGPhysics_SphereQueryCollect_Dtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005ebf00_VOGPhysics_SphereQueryCollect_Dtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005ebf00_FUN_005ebf00.md` |
| Annotated | `docs/reconstruction/raw/aa_005ebf00_FUN_005ebf00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGPhysics_SphereQueryCollect_Dtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005ebf00.cpp` |
| Function | `docs/reconstruction/functions/aa_005ebf00_FUN_005ebf00.md` |
| Function named | `docs/reconstruction/functions/aa_005ebf00_VOGPhysics_SphereQueryCollect_Dtor_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_004ea350  CVOGPhysicsUtils::GetObjectsInArea  [grandparent residual]
  param_5 == 2  → sphere path:
    ├─ FUN_006c7fa0   sphere-shape setup                   [residual]
    ├─ alloc 0xD0 / tag 0x2C
    ├─ FUN_005ebec0   VOGPhysics_SphereQueryCollect_Ctor   [dualed MEGA-070]
    │    └─ FUN_005eb210  VOGPhysics_QueryObject_BaseCtor  [dualed R11-008]
    └─ FUN_00560c90(this+0xC, …)  collect hits

destroy path:
  vtbl[0] = FUN_005ebf70  scalar-deleting dtor             [residual]
    ├─ FUN_005ebf00  VOGPhysics_SphereQueryCollect_Dtor    [OWN R12-038]
    │    └─ JMP FUN_006343d0  base query dtor              [residual]
    └─ if (flags&1) free(self, size@+4, tag 0x2C)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005ebf00-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005ebf00` | Port as **complete-object dtor** for **0xD0 sphere-query collect**. **thiscall**: ECX=self, no stack args; reinstall vtbl `009dce90`; reverse-walk `+0xC0` stride **8** with per-entry release; free buffer tag **0x12** when capacity ≥ 0; **JMP** base dtor for 0xC0 core. |
| Do **not** | Free outer object here; merge with scalar `005ebf70` or base `006343d0`; treat as sibling-collect dtor (vtbl `009dce20`); assume stride-4 pointer vector; invent product class English. |
| Pair with | dualed ctor `VOGPhysics_SphereQueryCollect_Ctor_Inferred` `005ebec0`; dualed base ctor `005eb210`; residual scalar `005ebf70`; residual base dtor `006343d0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER.md` / progress / WORK_QUEUE as applicable
- system map `interaction-activation.md` entry for `aa_005ebf00`
- pair note on dualed ctor `aa_005ebec0` dtor residual → dualed

**Terminal:** false.
