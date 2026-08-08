# Review A (reconstruction fidelity): `aa_00581190` VOGPhysics_QueryObject_SubInit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00581190` |
| **VA** | `0x00581190`–`0x005811e7` |
| **Canonical name (Ghidra)** | `FUN_00581190` |
| **Proposed name** | `VOGPhysics_QueryObject_SubInit_Inferred` |
| **Review date** | `2026-08-05` (R12-027 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00581190_VOGPhysics_QueryObject_SubInit_Inferred.md` |
| **System** | interaction-activation (partition parent `0x005eb210` query base ctor) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf **thiscall sub-init** for the physics query-object / shared base-object header:

1. Set self refcount word `@ +0x06 = 1`.
2. Install provisional vtbl `PTR_FUN_009cd99c`.
3. Store `linked_obj*` @ `+0x0C`; if non-null, `linked_obj->refcount(+0x06)++`.
4. Store `mode` @ `+0x24` (sole caller passes **2**).
5. Clear mid-fields; self-ptr @ `+0x2C`; empty-vector capacity sentinel `0x80000000` @ `+0x38`.
6. **RET 8**; EAX holds self (preserved).

Parent `FUN_005eb210` then overwrites vtbl with `009dcde0` and continues full 0xC0 query-core init. Does **not** itself perform float-block init, triads at +0x3C/+0x48, or +0x80 params copy.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra HTTP `127.0.0.1:8089` `decompile_function` @ `0x00581190` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/disasm/locals) |
| Assembly | `disassemble_function` (full body; **not** `disassemble_bytes`) |
| Bytes | `read_memory` 128 B @ entry — hex seal + `CC` pad; RET `C2 08 00` |
| Vtbl | `read_memory` @ `0x009cd99c`; `get_xrefs_to` (this + peers `00507350` / `005f5760`) |
| Callers / xrefs | `get_function_callers` (1) + `get_function_xrefs` (1 UNCONDITIONAL_CALL) |
| Call-site ABI | parent `disassemble_function` @ `005eb219`–`005eb21e` |
| Parent context | dualed `VOGPhysics_QueryObject_BaseCtor_Inferred` (R11-008) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_00581190` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledgers, dual of peers / parent.

---

## 3. Signature

```c
void __thiscall VOGPhysics_QueryObject_SubInit_Inferred(
    uint32_t *self /* ECX */,
    uint32_t *linked_obj /* stack */,
    uint32_t mode /* stack */);
// RET 8; EAX = self at RET (preserved)
```

| Item | Evidence |
|---|---|
| Convention | `MOV EAX,ECX`; stack loads `[ESP+4]` / post-PUSH `[ESP+0xC]`; **`RET 8`** |
| Vtbl | `MOV dword ptr [EAX], 0x9cd99c` |
| Refcount | `MOV word ptr [EAX+6], 1`; optional `ADD word ptr [EDX+6], 1` |
| Mode / link | stores at `+0x0C` and `+0x24` |
| Empty cap | `MOV dword ptr [EAX+0x38], 0x80000000` |
| Body size | 88 B (`0x58`); pad `CC` from `0x005811e8` |
| Leaf | analyze `classification=leaf`; callees empty |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Refcount + provisional vtbl | **Yes** |
| Clear + link + mode + self-ptr + cap | **Yes** |
| Conditional linked refcount++ | **Yes** (`JZ` over ADD) |
| No callees / no loops | **Yes** (leaf; single branch) |
| RET 8 | **Yes** (`C2 08 00`) |
| Decompile ≡ original raw CF | **Yes** (identical pseudocode) |

### Call-site sample

| Site | ECX / stack | Follow-on |
|---|---|---|
| `0x005eb21e` `FUN_005eb210` | this=query self; stack=`params[1]`, mode=`2` | parent installs query vtbl `009dcde0` + rest of 0xC0 core |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI + RET 8 + leaf | **High** | bytes + disasm + decompile identical |
| Sole caller parent mode-2 | **High** | 1 UNCONDITIONAL_CALL + parent PUSH 2 |
| Header offset map through +0x38 | **High** | asm absolute offsets |
| Sub-init role (not full query ctor) | **High** | parent overwrites vtbl; continues past +0x38 |
| Distinct from TtPhantom / collect ctors | **High** | different VAs, vtbls, sizes |
| Product class English | **Open** | `_Inferred` hygiene |
| Full mode dictionary / linked type English | **Open** | residual peers |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps / open

1. Product/PDB class name for vtbl `009cd99c`.
2. Semantic labels for `mode` values beyond parent-passed 2.
3. Exact type of `linked_obj*` (parent uses as vcall target at +0x0C).
4. Intentional public return-this vs void (EAX preserved; sole caller ignores).
5. Runtime Confirmed / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/layout/caller High; product English + mode dictionary + runtime open.
