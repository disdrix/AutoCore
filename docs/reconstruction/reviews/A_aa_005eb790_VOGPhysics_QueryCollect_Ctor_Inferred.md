# Review A (reconstruction fidelity): `aa_005eb790` VOGPhysics_QueryCollect_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005eb790` |
| **VA** | `0x005eb790`–`0x005eb7c0` |
| **Canonical name (Ghidra)** | `FUN_005eb790` |
| **Proposed name** | `VOGPhysics_QueryCollect_Ctor_Inferred` |
| **Review date** | `2026-08-05` (R12-037 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_005eb790_VOGPhysics_QueryCollect_Ctor_Inferred.md` |
| **System** | interaction-activation (partition parent `0x005eb210` base query-object ctor) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

Derived **thiscall constructor** for the **0xD0-byte query-collect object**:

1. Base-init via `FUN_005eb210(params)`.
2. Install derived vtbl `PTR_FUN_009dce20`.
3. Empty-init result collect triad at `this+0xC0 / +0xC4 / +0xC8` (`0, 0, 0x80000000`).
4. Return `this` in EAX; `RET 4`.

Sibling of dualed sphere collect `FUN_005ebec0` (vtbl `009dce90`) — identical control-flow skeleton, different derived vtbl. Used by placement/probe helpers after optional sphere-shape setup; does **not** perform the collect loop itself.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005eb790` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/locals/completeness) |
| Assembly | `disassemble_function` (13 insns; **not** `disassemble_bytes`) |
| Bytes | `read_memory` 80 B @ entry — hex seal + `CC` pad |
| Callers / xrefs | `get_function_callers` (2 named) + `get_function_xrefs` (4 UNCONDITIONAL_CALL) |
| Call-site ABI | `get_assembly_context` on `004e97fb`, `004e9f93`, `004ea0f2`, `005eb8bf` |
| Parent context | dualed base `FUN_005eb210` (R11-008); dualed sphere sibling `FUN_005ebec0` (MEGA-070) |
| Dtor peers | decompile `FUN_005eb7d0`, `FUN_005eb810` (vtbl DATA xrefs) |
| Vtbl | `read_memory` @ `0x009dce20`; `get_xrefs_to` (DATA from ctor + dtor pair only) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_005eb790` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledgers, dual of dtor / callers / shape.

---

## 3. Signature

```c
uint32_t * __thiscall VOGPhysics_QueryCollect_Ctor_Inferred(
    uint32_t *self /* ECX */,
    uint32_t params /* stack */);
// RET 4; EAX = self
```

| Item | Evidence |
|---|---|
| Convention | `MOV ESI,ECX`; `PUSH [ESP+4]`; `CALL base`; `RET 4` |
| Vtbl | `MOV dword ptr [ESI], 0x9dce20` |
| Collect triad | stores at `ESI+0xC0`, `+0xC4`, `+0xC8` |
| Body size | 49 B (`0x31`); pad `CC` from `0x005eb7c1` |
| Alloc size | call sites: `PUSH 0xD0` / size word `0xD0` / tag `0x2C` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Base ctor call with stack params | **Yes** |
| Derived vtbl install (`009dce20`) | **Yes** |
| Collect triad zero/sentinel init | **Yes** |
| Return this / RET 4 | **Yes** |
| No branches / no loops | **Yes** (straight-line leaf wrapper) |

### Layout (sealed writes)

| Off | Role |
|----:|------|
| `+0x00` | derived vtbl `009dce20` |
| `+0xC0` | collect begin = 0 |
| `+0xC4` | collect count = 0 |
| `+0xC8` | capacity sentinel `0x80000000` |

### Call-site samples

| Site | ECX / stack | Follow-on |
|---|---|---|
| `0x004e97fb` `FUN_004e9720` | this = fresh 0xD0; stack = shape/params | `FUN_0055ff20` + vcall slot `+0x30` |
| `0x004e9f93` / `0x004ea0f2` `FUN_004e9aa0` | same 0xD0 construct | placement/probe continuation |
| `0x005eb8bf` factory | alloc then construct | RET constructed this |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI + RET 4 + return this | **High** | bytes + disasm + decompile identical |
| Collect triad +0xC0 role | **High** | dtor `FUN_005eb7d0` frees same triad |
| Query-collect derived ctor role | **High** | 0xD0 + base wrap + triad; parallel to sphere sibling |
| Distinct from sphere collect `005ebec0` | **High** | different VA + vtbl `009dce20` ≠ `009dce90` |
| Distinct from base `005eb210` | **High** | writes +0xC0; overwrites base vtbl |
| Reject spawn-point scaffold | **High** | no spawn strings; pure ctor |
| Product class English | **Open** | `_Inferred` hygiene (no RTTI on vtbl) |
| Full 0xD0 field map | **Open** | base dual sealed; derived method set open |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps / open

1. Product/PDB class name for vtbl `009dce20`.  
2. Exact semantic product label vs sphere sibling (method-set / element-type English).  
3. Exact `params*` struct shape.  
4. Runtime Confirmed / differential.

**Verdict:** **accept** — CF/ABI/callers/collect-buffer High; only product English + full type layout + runtime open.
