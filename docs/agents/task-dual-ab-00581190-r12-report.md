# Dual A/B report — R12-027 OWN-ONLY (`0x00581190`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-027**  
**Scope:** VA `0x00581190` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** HTTP `127.0.0.1:8089` — `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_xrefs_to` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R12 residual dual seal — query-object base **sub-init** (leaf); partition parent `0x005eb210` `VOGPhysics_QueryObject_BaseCtor_Inferred`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` row R12-027.  
**Dual start:** **2646**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00581190` VOGPhysics_QueryObject_SubInit_Inferred | **accept-with-gaps** — CF/ABI/RET8/leaf/header-layout/1 caller mode-2 sealed; product English + mode dictionary + linked type + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): spawn-scaffold / full-query-merge / TtPhantom-merge / multi-caller / non-leaf / exclusive-vtbl / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00581190` — sealed facts

1. **Body:** `0x00581190`–`0x005811e7` inclusive (**88 B** / `0x58`); pad `CC` from `0x005811e8` (next `FUN_005811f0` @ `0x005811f0`).
2. **ABI:** **ECX** = self; stack `linked_obj*`, `mode`; **EAX** = self at RET (preserved via `MOV EAX,ECX`); **`RET 8`**.
3. **Semantics:** leaf **query-object / shared base header sub-init**:
   - refcount word @ **`+0x06` = 1**;
   - provisional vtbl `PTR_FUN_009cd99c`;
   - `linked_obj*` @ **`+0x0C`**; if non-null, `linked_obj->refcount(+0x06)++`;
   - sentinel **`0xFFFFFFFF`** @ **`+0x10`**;
   - `mode` @ **`+0x24`** (sole caller passes **2**);
   - self-ptr @ **`+0x2C`**;
   - empty-vector capacity sentinel **`0x80000000`** @ **`+0x38`**;
   - mid-fields cleared (`+0x08`, `+0x14..+0x20`, `+0x28`, `+0x30..+0x34`).
4. **Parent contract:** dualed `FUN_005eb210` calls this first (`PUSH 2; PUSH params[1]; CALL`), then overwrites vtbl with **`009dcde0`** and continues 0xC0 query-core init (triads, float block, +0x80 copy).
5. **Callees:** **none** (leaf; analyze `classification=leaf`).
6. **Callers / xrefs:** **1** UNCONDITIONAL_CALL:
   - `FUN_005eb210` @ `0x005eb21e` (dualed R11-008 `VOGPhysics_QueryObject_BaseCtor_Inferred`)
7. **Peers (evidence only):** same-vtbl DATA writers `FUN_005f5760` (near-identical field init) and `FUN_00507350` (dtor release path); nearby TtPhantom ctor `FUN_00581220` (different vtbl/size).
8. **Name:** `VOGPhysics_QueryObject_SubInit_Inferred` (Ghidra `FUN_00581190`). Product class English open → `_Inferred`. Scaffold `Named_CalleeOf_*CVO*00581190` **retired**.
9. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + parent call-site context.

### Gaps

- Product/PDB class name for vtbl `009cd99c` (shared; no RTTI sealed here).  
- Full `mode` dictionary beyond parent-passed **2**.  
- Exact `linked_obj*` type English (parent later vcalls it).  
- Public return-this vs void contract (EAX preserved; sole caller ignores).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00581190_VOGPhysics_QueryObject_SubInit_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00581190_VOGPhysics_QueryObject_SubInit_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00581190_FUN_00581190.md` |
| Annotated | `docs/reconstruction/raw/aa_00581190_FUN_00581190.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGPhysics_QueryObject_SubInit_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00581190.cpp` |
| Function | `docs/reconstruction/functions/aa_00581190_FUN_00581190.md` |
| Function named | `docs/reconstruction/functions/aa_00581190_VOGPhysics_QueryObject_SubInit_Inferred.md` |

**Retired scaffold clean (do not promote):**  
`docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00581190.cpp`

---

## Chain context (not dualled; evidence only)

```text
FUN_004ea350  CVOGPhysicsUtils::GetObjectsInArea  [partition grandparent]
  param_5 == 2  → sphere path:
    ├─ FUN_006c7fa0   sphere-shape setup                   [residual]
    ├─ alloc 0xD0 / tag 0x2C
    ├─ FUN_005ebec0   VOGPhysics_SphereQueryCollect_Ctor   [dualed MEGA-070]
    │    └─ FUN_005eb210  VOGPhysics_QueryObject_BaseCtor  [dualed R11-008]
    │         └─ FUN_00581190  VOGPhysics_QueryObject_SubInit  [OWN R12-027]
    └─ FUN_00560c90(this+0xC, …)  collect hits

FUN_005eb210  [dualed R11-008]
  ├─ FUN_00581190  SubInit(self, params[1], mode=2)       [OWN]
  ├─ vcall [*(self+0xC)].vtbl[+0x14]
  └─ FUN_005eb040  16-dword copy to +0x80                 [residual]

Same-vtbl peers (not dualled):
  FUN_005f5760  near-identical header init + follow-on
  FUN_00507350  dtor path (temp vtbl + linked release)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00581190-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00581190` | Port as **leaf header sub-init** for query-object construction. **thiscall RET 8**: ECX=self, stack=`linked_obj*`, `mode`; EAX=self preserved. Sets provisional vtbl `009cd99c`, refcount=1, link @ +0x0C (optional refcount++), mode @ +0x24, self-ptr @ +0x2C, empty cap `0x80000000` @ +0x38. Production path mode **2** from parent. |
| Do **not** | Treat as full query base ctor; install query vtbl `009dcde0` here; merge with TtPhantom `00581220` or collect ctors; claim exclusive ownership of vtbl `009cd99c`; invent spawn-point domain; claim Runtime Confirmed. |
| Pair with | dualed parent `VOGPhysics_QueryObject_BaseCtor_Inferred` `005eb210`; dualed sphere collect `005ebec0`; residual copy `005eb040`; residual same-vtbl peers `005f5760` / `00507350`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER.md` / progress / WORK_QUEUE as applicable
- system map `interaction-activation.md` entry for `aa_00581190`
- retire scaffold `Named_CalleeOf_*CVO*00581190` inventory aliases

**Terminal:** false.
