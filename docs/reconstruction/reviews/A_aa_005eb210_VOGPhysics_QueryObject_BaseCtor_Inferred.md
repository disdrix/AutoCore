# Review A (reconstruction fidelity): `aa_005eb210` VOGPhysics_QueryObject_BaseCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005eb210` |
| **VA** | `0x005eb210`–`0x005eb2ac` |
| **Canonical name (Ghidra)** | `FUN_005eb210` |
| **Proposed name** | `VOGPhysics_QueryObject_BaseCtor_Inferred` |
| **Review date** | `2026-08-05` (R11-008 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_005eb210_VOGPhysics_QueryObject_BaseCtor_Inferred.md` |
| **System** | interaction-activation (partition parent `0x005ebec0` sphere collect ctor) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Base **thiscall constructor** for the **0xC0-byte physics query-object core**:

1. Sub-init via `FUN_00581190(self, params[1], 2)` (thiscall on self).
2. Empty-init two internal buffer triads at `+0x3C` and `+0x48` (`0, 0, 0x80000000`).
3. Install base vtbl `PTR_FUN_009dcde0`; self-ptr at `+0x2C`.
4. Init float block at `+0x60` (zeros + `DAT_009dcddc` ~1e30 at `+0x6C/+0x7C`).
5. Store `params[0]` @ `+0x28`; pointer to float block @ `+0x14`.
6. Virtual call on object* at `+0xC` (vtbl slot `+0x14`) → store @ `+0x54`.
7. Copy 0x40 bytes from `params+0x20` into `this+0x80` via `FUN_005eb040`.
8. Return `this` in EAX; `RET 4`.

Shared by both **0xD0 derived collect** ctors (`FUN_005ebec0` sphere, `FUN_005eb790` sibling). Does **not** install the derived collect triad at `+0xC0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005eb210` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/locals) |
| Assembly | `disassemble_function` (full body; **not** `disassemble_bytes`) |
| Bytes | `read_memory` 160 B @ entry — hex seal + `CC` pad; RET `C2 04 00` |
| Constants | `read_memory` @ `0x009dcddc` (float ~1e30), `0x009dcde0` (vtbl) |
| Callers / xrefs | `get_function_callers` (2) + `get_function_xrefs` (2 UNCONDITIONAL_CALL) |
| Call-site ABI | `get_assembly_context` on `005eb798`, `005ebec8` |
| Vtbl xrefs | `get_xrefs_to` `009dcde0` — sole DATA from this ctor |
| Parent context | dualed `VOGPhysics_SphereQueryCollect_Ctor_Inferred` (MEGA-070); sibling `FUN_005eb790` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_005eb210` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledgers, dual of callees / sibling / parent.

---

## 3. Signature

```c
uint32_t * __thiscall VOGPhysics_QueryObject_BaseCtor_Inferred(
    uint32_t *self /* ECX */,
    uint32_t *params /* stack */);
// RET 4; EAX = self
```

| Item | Evidence |
|---|---|
| Convention | `MOV ESI,ECX`; `MOV EDI,[ESP+0xC]` params; `RET 4` |
| Vtbl | `MOV dword ptr [ESI], 0x9dcde0` |
| Triads | stores at `+0x3C/+0x40/+0x44` and `+0x48/+0x4C/+0x50` |
| Float block | `LEA EAX,[ESI+0x60]`; MOVSS zeros; `DAT_009dcddc` @ `+0x6C/+0x7C` |
| Tail copy | `LEA ECX,[ESI+0x80]`; `PUSH params+0x20`; `CALL FUN_005eb040` |
| Body size | 157 B (`0x9D`); pad `CC` from `0x005eb2ad` |
| Derived size | call-site family: base 0xC0 + collect triad → **0xD0** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Sub-init `00581190(self, params[1], 2)` | **Yes** (asm thiscall; decompiler drops this) |
| Two empty triads + self-ptr + base vtbl | **Yes** |
| Float block zero + ~1e30 W-slots | **Yes** |
| params[0] / float-block ptr / vcall / +0x54 | **Yes** |
| 0x40-byte copy to +0x80 | **Yes** |
| Return this / RET 4 | **Yes** |
| No branches / no loops | **Yes** (straight-line) |

### Call-site samples

| Site | ECX / stack | Follow-on |
|---|---|---|
| `0x005ebec8` `FUN_005ebec0` | this=fresh 0xD0; stack=params | derived vtbl `009dce90` + collect triad `+0xC0` |
| `0x005eb798` `FUN_005eb790` | same pattern | derived vtbl `009dce20` + collect triad `+0xC0` |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI + RET 4 + return this | **High** | bytes + disasm + decompile identical |
| Base query-object ctor (0xC0 core) | **High** | both 0xD0 derived wrap this then add +0xC0 |
| Vtbl `009dcde0` install | **High** | sole DATA xref = this write |
| Two triads + float block + copy offsets | **High** | asm absolute offsets |
| Distinct from derived collect / shape / AABB | **High** | different VAs and sizes |
| Product class English | **Open** | `_Inferred` hygiene |
| Full field semantics / params type | **Open** | residual callees |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps / open

1. Product/PDB class name for vtbl `009dcde0`.
2. Semantic labels for triad A/B and float-block (beyond empty-init + ~1e30 sentinel).
3. Exact `params*` struct (field0, object* at +4, 0x40 blob at +0x20).
4. Callee duals `FUN_00581190` / `FUN_005eb040` and vcall target type.
5. Runtime Confirmed / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/layout/callers High; product English + full type map + residual callees + runtime open.
