# Review A (reconstruction fidelity): `aa_005ebf00` VOGPhysics_SphereQueryCollect_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ebf00` |
| **VA** | `0x005ebf00`–`0x005ebf67` |
| **Canonical name (Ghidra)** | `FUN_005ebf00` |
| **Proposed name** | `VOGPhysics_SphereQueryCollect_Dtor_Inferred` |
| **Review date** | `2026-08-05` (R12-038 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_005ebf00_VOGPhysics_SphereQueryCollect_Dtor_Inferred.md` |
| **System** | interaction-activation (partition parent `0x005eb210` base ctor) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete-object **thiscall destructor** for the **0xD0-byte physics sphere query collect** object (vtbl `009dce90`):

1. Reinstall derived vtbl `PTR_FUN_009dce90`.
2. Reverse-walk collect buffer at `+0xC0` (count at `+0xC4`, stride **8**); for each entry, thiscall vtbl slot **`+0x14`** release on the embedded object*.
3. Zero count at `+0xC4`.
4. If capacity at `+0xC8` is non-negative, free buffer via `DAT_00b05060` allocator vfunc **`+0x14`** with size `(cap & 0x7fffffff)*8` and tag **`0x12`**.
5. Tail-jump base dtor `FUN_006343d0(self)` (destroys 0xC0 query core).

Does **not** free the outer 0xD0 object (that is residual scalar-deleting dtor `FUN_005ebf70` when `flags&1`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005ebf00` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/locals) |
| Assembly | `disassemble_function` (full body; **not** `disassemble_bytes`) |
| Bytes | `read_memory` 104 B @ entry — hex seal + `CC` pad; tail `E9 …` → `006343d0` |
| Vtbl | `read_memory` @ `0x009dce90` (slot0 = `005ebf70`); `get_xrefs_to` DATA from ctor + this dtor |
| Callers / xrefs | `get_function_callers` (1) + `get_function_xrefs` (1 UNCONDITIONAL_CALL from `005ebf70`) |
| Parent context | dualed ctor `VOGPhysics_SphereQueryCollect_Ctor_Inferred`; dualed base ctor `VOGPhysics_QueryObject_BaseCtor_Inferred` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_005ebf00` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledgers, dual of scalar dtor / base dtor / sibling.

---

## 3. Signature

```c
void __thiscall VOGPhysics_SphereQueryCollect_Dtor_Inferred(
    uint32_t *self /* ECX */);
// no stack args; retail ends in JMP FUN_006343d0
```

| Item | Evidence |
|---|---|
| Convention | `MOV EDI,ECX`; no stack loads; tail `MOV ECX,EDI; JMP 006343d0` |
| Vtbl reinstall | `MOV dword ptr [EDI], 0x9dce90` |
| Triad | `+0xC0` begin, `+0xC4` count, `+0xC8` capacity |
| Stride | `ESI*8` addressing in element loop |
| Free | `AND EAX,0x7fffffff` then three `ADD EAX,EAX` (=×8); `PUSH 0x12` |
| Body size | 104 B (`0x68`); pad `CC` from `0x005ebf68` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load count; reinstall derived vtbl | **Yes** |
| Reverse element release loop (stride 8, vcall +0x14) | **Yes** |
| Zero count | **Yes** |
| Conditional buffer free (cap>=0, tag 0x12) | **Yes** (asm AND before ×8) |
| Tail JMP base dtor thiscall | **Yes** (decompiler shows call/return; asm JMP) |
| No outer object free | **Yes** (scalar dtor peer owns free) |

### Call-site sample

| Site | ECX / follow-on |
|---|---|
| `0x005ebf73` `FUN_005ebf70` | this=collect object; then if `(flags&1)` free size@+4 tag `0x2C` |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + thiscall + no stack args + tail JMP | **High** | bytes + disasm + decompile CF identical |
| Sphere-collect complete dtor (vtbl `009dce90`) | **High** | same vtbl as dualed ctor; triad inverse of empty-init |
| Collect triad offsets / stride 8 / tag 0x12 | **High** | absolute offsets in asm |
| Distinct from scalar dtor / base dtor | **High** | different VAs and roles |
| Product class English | **Open** | `_Inferred` hygiene |
| Element payload type / release slot meaning | **Open** | residual |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps / open

1. Product/PDB class name for vtbl `009dce90`.
2. Exact 8-byte element layout beyond first-dword object*.
3. Semantic of element vtbl[+0x14] (release / decref / destroy).
4. Dual residual `FUN_006343d0` / `FUN_005ebf70`.
5. Runtime Confirmed / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/layout/caller High; product English + element type + residual base/scalar + runtime open.
