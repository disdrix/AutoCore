# Dual A/B report — R11-008 OWN-ONLY (`0x005eb210`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-008**  
**Scope:** VA `0x005eb210` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `get_xrefs_to`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R11 residual dual seal — base query-object ctor; partition parent `0x005ebec0` `VOGPhysics_SphereQueryCollect_Ctor_Inferred`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` row R11-008.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005eb210` VOGPhysics_QueryObject_BaseCtor_Inferred | **accept-with-gaps** — CF/ABI/RET4/return-this/base-vtbl+0xC0-layout/2 callers sealed; product English + full field map + residual callees + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): spawn-scaffold / derived-collect-merge / shape-merge / AABB-merge / wrong ABI / void-return / decompiler-dropped-thiscall claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005eb210` — sealed facts

1. **Body:** `0x005eb210`–`0x005eb2ac` inclusive (**157 B** / `0x9D`); pad `CC` from `0x005eb2ad`.
2. **ABI:** **ECX** = self (query object*); stack `params*`; **EAX** = self; **`RET 4`**.
3. **Semantics:** base **query-object constructor** (0xC0 core):
   - Sub-init via `FUN_00581190(self, params[1], 2)` (thiscall on self; decompiler drops this).
   - Empty-init internal buffer triads at **`+0x3C` and `+0x48`** (`0, 0, 0x80000000`).
   - Install base vtbl `PTR_FUN_009dcde0`; self-ptr at **`+0x2C`**.
   - Float block at **`+0x60`**: zeros + `DAT_009dcddc` (~1e30 / `0x7149F2CA`) at **`+0x6C/+0x7C`**.
   - `params[0]` @ **`+0x28`**; ptr to float block @ **`+0x14`**.
   - Virtual call on object* at **`+0xC`** (vtbl slot **`+0x14`**) → store @ **`+0x54`**.
   - Copy **0x40** bytes from `params+0x20` into **`this+0x80`** via `FUN_005eb040`.
4. **Derived contract:** both collect ctors wrap this then set derived vtbl + collect triad at **`+0xC0/+0xC4/+0xC8`** → object **0xD0**.
5. **Callees:** `FUN_00581190`, `FUN_005eb040`, + one virtual CALL.
6. **Callers / xrefs:** **2** UNCONDITIONAL_CALL:
   - `FUN_005ebec0` @ `0x005ebec8` (dualed sphere collect; vtbl `009dce90`)
   - `FUN_005eb790` @ `0x005eb798` (sibling collect; vtbl `009dce20`)
7. **Peers (evidence only):** shape `FUN_006c7fa0`; AABB ctor `FUN_00581220` (0x90); parent `FUN_004ea350` GetObjectsInArea; dtor `FUN_005ebf00`.
8. **Name:** `VOGPhysics_QueryObject_BaseCtor_Inferred` (Ghidra `FUN_005eb210`). Product class English open → `_Inferred`. Scaffold `Named_CalleeOf_*CVOGSpawnPoint*005eb210` **retired**.
9. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product/PDB class name for vtbl `009dcde0` (no RTTI on sole DATA xref).  
- Full field English (triad A/B vs collect; float-block meaning).  
- Exact `params*` composite type.  
- Residual callees `00581190` / `005eb040` / vcall target.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005eb210_VOGPhysics_QueryObject_BaseCtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005eb210_VOGPhysics_QueryObject_BaseCtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005eb210_FUN_005eb210.md` |
| Annotated | `docs/reconstruction/raw/aa_005eb210_FUN_005eb210.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGPhysics_QueryObject_BaseCtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005eb210.cpp` |
| Function | `docs/reconstruction/functions/aa_005eb210_FUN_005eb210.md` |
| Function named | `docs/reconstruction/functions/aa_005eb210_VOGPhysics_QueryObject_BaseCtor_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_004ea350  CVOGPhysicsUtils::GetObjectsInArea  [partition grandparent]
  param_5 == 2  → sphere path:
    ├─ FUN_006c7fa0   sphere-shape setup                   [residual]
    ├─ alloc 0xD0 / tag 0x2C
    ├─ FUN_005ebec0   VOGPhysics_SphereQueryCollect_Ctor   [dualed MEGA-070]
    │    └─ FUN_005eb210  VOGPhysics_QueryObject_BaseCtor  [OWN R11-008]
    └─ FUN_00560c90(this+0xC, …)  collect hits

FUN_005eb790  sibling collect ctor (vtbl 009dce20)        [residual]
  └─ FUN_005eb210  [OWN]

FUN_005eb210  [OWN R11-008]
  ├─ FUN_00581190  base sub-init (mode 2)                 [residual]
  ├─ vcall [*(self+0xC)].vtbl[+0x14]
  └─ FUN_005eb040  16-dword copy to +0x80                 [residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005eb210-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005eb210` | Port as **base ctor** for a **0xC0 query-object core**. **thiscall RET 4**: ECX=self, stack=params*, EAX=self. After sub-init mode **2**, set base vtbl `009dcde0`, two empty triads (`0x80000000` cap), float block with ~1e30 W-slots, copy **0x40** from params+0x20 → +0x80. Derived add collect triad at **+0xC0** (object **0xD0**). |
| Do **not** | Treat as derived collect ctor; install +0xC0 triad here; merge with shape `006c7fa0` or AABB `00581220`; drop thiscall on `00581190`/`005eb040`; invent spawn-point domain. |
| Pair with | dualed `VOGPhysics_SphereQueryCollect_Ctor_Inferred` `005ebec0`; residual sibling `005eb790`; residual sub-init `00581190`; residual copy `005eb040`; residual dtor `005ebf00`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER.md` / progress / WORK_QUEUE as applicable
- system map `interaction-activation.md` entry for `aa_005eb210`
- retire scaffold `Named_CalleeOf_*CVOGSpawnPoint*005eb210` inventory aliases

**Terminal:** false.
