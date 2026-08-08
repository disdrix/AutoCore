# Dual A/B report — R12-024 OWN-ONLY (`0x00560c90`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-024**  
**Scope:** VA `0x00560c90` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R12 residual dual seal — LthkWorld getPenetrations (collect + narrowphase dispatch); partition parent `0x005eb210` `VOGPhysics_QueryObject_BaseCtor_Inferred`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` row R12-024.  
**Dual start:** **2646**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00560c90` LthkWorld_GetPenetrations_Inferred | **accept-with-gaps** — CF/ABI/RET0xC/strings/2 callers/loop+dispatch sealed; product class English + residual vcall types + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): spawn/DEBUG_STOP scaffold / query-ctor merge / sub-init merge / unaff_EBX filter / thiscall dispatch / always-free / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00560c90` — sealed facts

1. **Body:** `0x00560c90`–`0x00560e33` inclusive (**420 B** / `0x1A4`); pad `CC` from `0x00560e34`.
2. **ABI:** **ECX** = self (Lthk/world object*); stack `query_obj*`, `user_ctx`, `dispatch_table*`; **`RET 0xC`**.
3. **Semantics:** **penetration collect + narrowphase type-pair dispatch**:
   - Profiler open `"LthkWorld::getPenetrations"` (`0x009d2840`).
   - If `dispatch_table == null` → `self+0xCC`.
   - Shape extents: `vcall(query.inner, +0x18)(query[2]+0x20, dispatch[2], &ext12)`.
   - Stack triad `{buf, 0, 0x80000080}`; broadphase `vcall(*(self+0xC4), +0x24)`.
   - Query type id: `vcall(query.inner, +0x14)`.
   - Profiler `"Stnarrowphase"` (`0x009d2830`).
   - Loop candidates (8 B stride, ptr at +4, −0x10 header): skip self; pair-filter via `*(self+0xD0)+8`; cdecl dispatch `dispatch.vtbl[+0x118c + (typeA*0x20+typeB)*4](query, cand, dispatch, user_ctx)` then `ADD ESP,0x10`.
   - Profiler close `"lt"` (`0x009d282c`); free heap triad via `DAT_00b05060` vtbl `+0x14` when capacity high-bit clear (size `(cap&0x7fffffff)*8`, tag `0x12`).
4. **Decompiler correction:** filter path uses **saved self** (`[ESP+0x1c]`), **not** `unaff_EBX`.
5. **Callees:** no direct `FUN_*` (indirect vcalls only; analyze `classification=leaf`).
6. **Callers / xrefs:** **2** UNCONDITIONAL_CALL:
   - `FUN_004ea350` @ `0x004ea7e3` (`CVOGPhysicsUtils::GetObjectsInArea` collect)
   - `FUN_005dae50` @ `0x005daf65` (`CVOGHBRecreateObject::OnHeartBeat`)
7. **Peers (evidence only):** query base ctor `005eb210`; sphere collect ctor `005ebec0`; sub-init `00581190`; copy `005eb040`; dtor `005ebf00`.
8. **Name:** `LthkWorld_GetPenetrations_Inferred` (Ghidra `FUN_00560c90`). Method English from plate; class ownership of `self` open → `_Inferred`. Scaffold `Named_CalleeOf_*VOG_DEBUG_STOP*00560c90` **retired**. Prior alias `Named_LthkWorld_getPenetrations` **promoted**.
9. **Decompile ≡ raw CF** with assembly corrections for filter host + free predicate; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product/PDB class of `self` beyond method plate.  
- Exact `query_obj` / `dispatch_table` types and type-id domain.  
- Residual vcall targets (`+0xC4` broadphase, `+0xD0` filter, shape slots, matrix handlers).  
- Full `0x118c` matrix product map.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00560c90_LthkWorld_GetPenetrations_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00560c90_LthkWorld_GetPenetrations_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00560c90_FUN_00560c90.md` |
| Annotated | `docs/reconstruction/raw/aa_00560c90_FUN_00560c90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LthkWorld_GetPenetrations_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00560c90.cpp` |
| Function | `docs/reconstruction/functions/aa_00560c90_FUN_00560c90.md` |
| Function named | `docs/reconstruction/functions/aa_00560c90_LthkWorld_GetPenetrations_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_004ea350  CVOGPhysicsUtils::GetObjectsInArea  [caller]
  param_5 == 2  → sphere path:
    ├─ FUN_006c7fa0   sphere-shape setup                   [residual]
    ├─ alloc 0xD0 / tag 0x2C
    ├─ FUN_005ebec0   VOGPhysics_SphereQueryCollect_Ctor   [dualed MEGA-070]
    │    └─ FUN_005eb210  VOGPhysics_QueryObject_BaseCtor  [dualed R11-008]
    │         └─ FUN_00581190  SubInit                     [dualed R12-027]
    └─ FUN_00560c90(this+0xC, …)  collect hits              [OWN R12-024]

FUN_005dae50  CVOGHBRecreateObject::OnHeartBeat            [caller]
  └─ FUN_00560c90(phys+0xC, …)  penetration pass           [OWN]

FUN_00560c90  [OWN R12-024]
  ├─ vcall query shape +0x18 / +0x14
  ├─ vcall *(self+0xC4) +0x24     broadphase
  ├─ vcall *(self+0xD0)+8         pair filter
  └─ cdecl matrix @ dispatch+0x118c
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00560c90-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00560c90` | Port as **world getPenetrations**: broadphase collect candidates, pair-filter, then **cdecl** type-pair collision/handler matrix. **thiscall RET 0xC**: ECX=self, stack=`query*`, `user_ctx`, `dispatch*` (null → `self+0xCC`). Uses `self+0xC4` collector, `self+0xD0` filter host. |
| Do **not** | Treat as query/collect ctor; trust decompiler `unaff_EBX`; treat matrix CALL as thiscall; always free triad (high-bit capacity = stack/empty); invent DEBUG_STOP domain; claim Runtime Confirmed. |
| Pair with | dualed query base `005eb210`; dualed sphere collect `005ebec0`; dualed sub-init `00581190`; callers `004ea350` / `005dae50`; residual filter/collector/matrix handlers. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER.md` / progress / WORK_QUEUE as applicable
- system map `interaction-activation.md` entry for `aa_00560c90`
- retire scaffold `Named_CalleeOf_*VOG_DEBUG_STOP*00560c90`; promote `LthkWorld_GetPenetrations_Inferred`

**Terminal:** false.
