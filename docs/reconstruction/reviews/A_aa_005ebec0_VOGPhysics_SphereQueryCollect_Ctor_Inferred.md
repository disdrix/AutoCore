# Review A (reconstruction fidelity): `aa_005ebec0` VOGPhysics_SphereQueryCollect_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ebec0` |
| **VA** | `0x005ebec0`–`0x005ebef0` |
| **Canonical name (Ghidra)** | `FUN_005ebec0` |
| **Proposed name** | `VOGPhysics_SphereQueryCollect_Ctor_Inferred` |
| **Review date** | `2026-08-05` (MEGA-070 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_005ebec0_VOGPhysics_SphereQueryCollect_Ctor_Inferred.md` |
| **System** | interaction-activation (partition parent `0x004ea350` GetObjectsInArea) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

Derived **thiscall constructor** for the **0xD0-byte sphere-query collect object**:

1. Base-init via `FUN_005eb210(params)`.
2. Install derived vtbl `PTR_FUN_009dce90`.
3. Empty-init result collect triad at `this+0xC0 / +0xC4 / +0xC8` (`0, 0, 0x80000000`).
4. Return `this` in EAX; `RET 4`.

Used exclusively on **sphere** paths of area object queries (GetObjectsInArea mode-2 / peer sphere branch), after sphere-shape setup `FUN_006c7fa0`. Does **not** perform the collect loop itself.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005ebec0` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/locals/completeness) |
| Assembly | `disassemble_function` (15 insns; **not** `disassemble_bytes`) |
| Bytes | `read_memory` 64 B @ entry — hex seal + `CC` pad |
| Callers / xrefs | `get_function_callers` (2 named) + `get_function_xrefs` (3 UNCONDITIONAL_CALL) |
| Call-site ABI | `get_assembly_context` on `004ea770`, `005dd368`, `005ebfcf` |
| Parent context | decompile `FUN_004ea350`, `FUN_005dd080`, dtor `FUN_005ebf00` |
| Strings | `search_strings` `GetObjectsInArea` / `sphere` |
| Vtbl | `read_memory` @ `0x009dce90`; `get_xrefs_to` (DATA from ctor + dtor only) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_005ebec0` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledgers, dual of base ctor / shape / parent loop.

---

## 3. Signature

```c
uint32_t * __thiscall VOGPhysics_SphereQueryCollect_Ctor_Inferred(
    uint32_t *self /* ECX */,
    uint32_t params /* stack */);
// RET 4; EAX = self
```

| Item | Evidence |
|---|---|
| Convention | `MOV ESI,ECX`; `PUSH [ESP+4]`; `CALL base`; `RET 4` |
| Vtbl | `MOV dword ptr [ESI], 0x9dce90` |
| Collect triad | stores at `ESI+0xC0`, `+0xC4`, `+0xC8` |
| Body size | 49 B (`0x31`); pad `CC` from `0x005ebef1` |
| Alloc size | call sites: `PUSH 0xD0` / size word `0xD0` / tag `0x2C` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Base ctor call with stack params | **Yes** |
| Derived vtbl install | **Yes** |
| Collect triad zero/sentinel init | **Yes** |
| Return this / RET 4 | **Yes** |
| No branches / no loops | **Yes** (straight-line leaf wrapper) |

### Layout (sealed writes)

| Off | Role |
|----:|------|
| `+0x00` | derived vtbl `009dce90` |
| `+0xC0` | collect begin = 0 |
| `+0xC4` | collect count = 0 |
| `+0xC8` | capacity sentinel `0x80000000` |

### Call-site samples

| Site | ECX / stack | Follow-on |
|---|---|---|
| `0x004ea770` `FUN_004ea350` mode-2 | this = fresh 0xD0; stack = shape/params | `FUN_00560c90(this+0xC, …)` collect |
| `0x005dd368` `FUN_005dd080` sphere | same 0xD0 construct | store at `obj+0xD0` |
| `0x005ebfcf` factory | alloc then construct | RET constructed this |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI + RET 4 + return this | **High** | bytes + disasm + decompile identical |
| Collect triad +0xC0 role | **High** | dtor `FUN_005ebf00` walks/frees same triad |
| Sphere-query collect ctor role | **High** | only sphere branches + 0xD0 + shape peer |
| Distinct from shape setup `006c7fa0` | **High** | different VA; shape is input to this |
| Reject VOG_DEBUG_STOP scaffold | **High** | no string; pure ctor |
| Product class English | **Open** | `_Inferred` hygiene (no RTTI on vtbl) |
| Full 0xD0 field map | **Open** | base ctor residual |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps / open

1. Product/PDB class name for vtbl `009dce90`.  
2. Base ctor `FUN_005eb210` full layout (not OWN).  
3. Exact `params*` struct shape (from `006c7fa0` + center/radius).  
4. Runtime Confirmed / differential.

**Verdict:** **accept** — CF/ABI/callers/collect-buffer High; only product English + full type layout + runtime open.
