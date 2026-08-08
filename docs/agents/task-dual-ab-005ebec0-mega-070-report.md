# Dual A/B report — MEGA-070 OWN-ONLY (`0x005ebec0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-070**  
**Scope:** VA `0x005ebec0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `get_assembly_context` + `read_memory` + `search_strings`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — sphere query collect ctor; partition parent `0x004ea350` CVOGPhysicsUtils::GetObjectsInArea.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005ebec0` VOGPhysics_SphereQueryCollect_Ctor_Inferred | **accept** — CF/ABI/RET4/return-this/vtbl+collect-triad/3 sphere call sites sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): VOG_DEBUG_STOP scaffold / shape-merge (`006c7fa0`) / AABB-merge / full collect-loop / wrong ABI / void-return claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005ebec0` — sealed facts

1. **Body:** `0x005ebec0`–`0x005ebef0` inclusive (**49 B** / `0x31`); pad `CC` from `0x005ebef1`.
2. **ABI:** **ECX** = self (query object*); stack `params*`; **EAX** = self; **`RET 4`**.
3. **Semantics:** derived **sphere-query collect object ctor**:
   - Base-init via `FUN_005eb210(params)` (thiscall; ECX remains self).
   - Install derived vtbl `PTR_FUN_009dce90`.
   - Empty-init collect buffer triad at **`this+0xC0 / +0xC4 / +0xC8`** (`0, 0, 0x80000000`).
4. **Alloc contract (call sites):** size **0xD0**, pool tag **0x2C** via `DAT_00b05060` allocator.
5. **Callees:** `FUN_005eb210` only.
6. **Callers / xrefs:** **3** UNCONDITIONAL_CALL:
   - `FUN_004ea350` @ `0x004ea770` (GetObjectsInArea **sphere** mode `param_5==2`)
   - `FUN_005dd080` @ `0x005dd368` (sphere branch; store at `obj+0xD0`)
   - factory @ `0x005ebfcf` (alloc + construct)
7. **Peers (evidence only):** dtor `FUN_005ebf00` releases `+0xC0` triad; shape setup `FUN_006c7fa0` (MEGA-071); parent string `CVOGPhysicsUtils::GetObjectsInArea::aabb` @ `0x009ccbe8`.
8. **Name:** `VOGPhysics_SphereQueryCollect_Ctor_Inferred` (Ghidra `FUN_005ebec0`). Product class English open → `_Inferred`. Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_005ebec0` **retired**.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product/PDB class name for vtbl `009dce90` (no RTTI on vtbl DATA xrefs).  
- Full 0xD0 field map (base ctor `FUN_005eb210` residual, not OWN).  
- Exact `params*` composite type.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005ebec0_VOGPhysics_SphereQueryCollect_Ctor_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005ebec0_VOGPhysics_SphereQueryCollect_Ctor_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005ebec0_FUN_005ebec0.md` |
| Annotated | `docs/reconstruction/raw/aa_005ebec0_FUN_005ebec0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGPhysics_SphereQueryCollect_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005ebec0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_005ebec0.cpp` |
| Function | `docs/reconstruction/functions/aa_005ebec0_FUN_005ebec0.md` |
| Function named | `docs/reconstruction/functions/aa_005ebec0_VOGPhysics_SphereQueryCollect_Ctor_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_004ea350  CVOGPhysicsUtils::GetObjectsInArea  [partition parent]
  param_5 == 1  → AABB path (FUN_00581220 / 0x90)          [not this VA]
  param_5 == 2  → sphere path:
    ├─ FUN_006c7fa0   sphere-shape setup                   [MEGA-071 residual]
    ├─ alloc 0xD0 / tag 0x2C
    ├─ FUN_005ebec0   VOGPhysics_SphereQueryCollect_Ctor   [OWN MEGA-070]
    └─ FUN_00560c90(this+0xC, …)  collect hits into query
  else          → default AABB + string "…::aabb"

FUN_005dd080  (sphere when *(obj+0xdd)!=0)
  ├─ FUN_006c7fa0
  ├─ FUN_005ebec0   [OWN]
  └─ *(obj+0xD0) = constructed query

FUN_005ebf00 / FUN_005ebf70  dtor / scalar-deleting dtor   [residual]
  └─ release collect triad +0xC0 then base teardown
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005ebec0-mega-070-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005ebec0` | Port as **derived ctor** for a **0xD0 sphere-query collect** object. **thiscall RET 4**: ECX=self, stack=params*, EAX=self. After base ctor, set vtbl `009dce90` and empty collect buffer at **+0xC0/+0xC4/+0xC8** (`0,0,0x80000000`). Alloc at sites: size **0xD0**, tag **0x2C**. Do **not** implement the collect loop or sphere shape here. Keep distinct from AABB query ctor (`00581220` / 0x90) and shape setup (`006c7fa0`). Pair with dtor `005ebf00` and parent `GetObjectsInArea` sphere mode. |
| Pair with | residual shape `006c7fa0` (MEGA-071); residual parent `004ea350`; residual base `005eb210`; residual dtor `005ebf00`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming registry / system map entries for `aa_005ebec0`
- retire any remaining `Named_CalleeOf_*VOG_DEBUG_STOP*005ebec0` inventory aliases
