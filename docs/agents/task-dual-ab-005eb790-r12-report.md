# Dual A/B report — R12-037 OWN-ONLY (`0x005eb790`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-037**  
**Scope:** VA `0x005eb790` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R12 residual dual seal — query-collect derived ctor; partition parent `0x005eb210` `VOGPhysics_QueryObject_BaseCtor_Inferred`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` row R12-037.  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005eb790` VOGPhysics_QueryCollect_Ctor_Inferred | **accept** — CF/ABI/RET4/return-this/vtbl+collect-triad/4 call sites sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): spawn scaffold / sphere-merge (`005ebec0`) / base-merge / shape-merge / AABB-merge / wrong ABI / void-return / collect-loop claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005eb790` — sealed facts

1. **Body:** `0x005eb790`–`0x005eb7c0` inclusive (**49 B** / `0x31`); pad `CC` from `0x005eb7c1`.
2. **ABI:** **ECX** = self (query object*); stack `params*`; **EAX** = self; **`RET 4`**.
3. **Semantics:** derived **query-collect object ctor**:
   - Base-init via `FUN_005eb210(params)` (thiscall; ECX remains self).
   - Install derived vtbl `PTR_FUN_009dce20`.
   - Empty-init collect buffer triad at **`this+0xC0 / +0xC4 / +0xC8`** (`0, 0, 0x80000000`).
4. **Alloc contract (call sites):** size **0xD0**, pool tag **0x2C** via `DAT_00b05060` allocator.
5. **Callees:** `FUN_005eb210` only (dualed R11-008).
6. **Callers / xrefs:** **4** UNCONDITIONAL_CALL:
   - `FUN_004e9720` @ `0x004e97fb` (sphere-shape peer `006c7fa0` + 0xD0 construct)
   - `FUN_004e9aa0` @ `0x004e9f93`
   - `FUN_004e9aa0` @ `0x004ea0f2`
   - factory @ `0x005eb8bf` (alloc + construct; orphan code near dtor cluster)
7. **Peers (evidence only):** sphere sibling `FUN_005ebec0` (vtbl `009dce90`); dtor `FUN_005eb7d0` / scalar `FUN_005eb810`; shape `FUN_006c7fa0`; GetObjectsInArea uses sphere collect not this VA.
8. **Name:** `VOGPhysics_QueryCollect_Ctor_Inferred` (Ghidra `FUN_005eb790`). Product class English open → `_Inferred`. Scaffold `Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature_005eb790` **retired**.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product/PDB class name for vtbl `009dce20` (no RTTI on vtbl DATA xrefs).  
- Full product English vs sphere sibling method-set / element type.  
- Exact `params*` composite type.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005eb790_VOGPhysics_QueryCollect_Ctor_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005eb790_VOGPhysics_QueryCollect_Ctor_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005eb790_FUN_005eb790.md` |
| Annotated | `docs/reconstruction/raw/aa_005eb790_FUN_005eb790.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGPhysics_QueryCollect_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005eb790.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature_005eb790.cpp` |
| Function | `docs/reconstruction/functions/aa_005eb790_FUN_005eb790.md` |
| Function named | `docs/reconstruction/functions/aa_005eb790_VOGPhysics_QueryCollect_Ctor_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_005eb210  VOGPhysics_QueryObject_BaseCtor_Inferred  [partition parent; dualed R11-008]
  └─ shared by:
       ├─ FUN_005ebec0  SphereQueryCollect (vtbl 009dce90)  [dualed MEGA-070]
       └─ FUN_005eb790  QueryCollect (vtbl 009dce20)        [OWN R12-037]

FUN_004e9720  placement/probe helper
  ├─ FUN_006c7fa0   sphere-shape setup                     [residual]
  ├─ alloc 0xD0 / tag 0x2C
  ├─ FUN_005eb790   VOGPhysics_QueryCollect_Ctor           [OWN]
  └─ FUN_0055ff20 / vcall +0x30  collect hits

FUN_004e9aa0  placement/probe helper
  └─ FUN_005eb790 ×2                                       [OWN]

FUN_005eb790  [OWN R12-037]
  └─ FUN_005eb210  base                                    [dualed]

FUN_005eb7d0 / FUN_005eb810  dtor / scalar dtor            [residual]
  └─ release collect triad +0xC0 then base teardown
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005eb790-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005eb790` | Port as **derived ctor** for a **0xD0 query-collect** object. **thiscall RET 4**: ECX=self, stack=params*, EAX=self. After base ctor, set vtbl `009dce20` and empty collect buffer at **+0xC0/+0xC4/+0xC8** (`0,0,0x80000000`). Alloc at sites: size **0xD0**, tag **0x2C**. Do **not** implement the collect loop or sphere shape here. Keep distinct from sphere collect (`005ebec0` / vtbl `009dce90`), base (`005eb210`), shape (`006c7fa0`), and AABB query ctor (`00581220` / 0x90). Pair with dtor `005eb7d0` / scalar `005eb810`. |
| Do **not** | Treat as spawn-point helper; merge with sphere collect; install base vtbl only; drop thiscall on `005eb210`. |
| Pair with | dualed base `005eb210`; dualed sphere sibling `005ebec0`; residual dtor `005eb7d0`; residual callers `004e9720` / `004e9aa0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER.md` / progress / WORK_QUEUE as applicable
- system map `interaction-activation.md` entry for `aa_005eb790`
- retire scaffold `Named_CalleeOf_*CVOGSpawnPoint*005eb790` inventory aliases

**Terminal:** false.
