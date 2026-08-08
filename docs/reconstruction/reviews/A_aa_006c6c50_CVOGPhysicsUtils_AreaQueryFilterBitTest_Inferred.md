# Review A (reconstruction fidelity): `aa_006c6c50` CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c6c50` |
| **VA** | `0x006c6c50`–`0x006c6c98` inclusive (**73 B** / `0x49`) |
| **Canonical name** | `CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred` |
| **Ghidra name** | `FUN_006c6c50` |
| **Prior scaffold** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_006c6c50` (**retired**) |
| **Review date** | `2026-08-05` (MEGA-039 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_006c6c50_CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred.md` |
| **System** | interaction-activation / CVOGPhysicsUtils area-query filter |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `analyze_control_flow`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **filter bit test** for the default AABB path of dualed `CVOGPhysicsUtils_GetObjectsInArea` (`0x004ea350`). For each broadphase hit, writes a pass/fail byte by probing a 32×32 bit matrix on `this` using the hit object's type dword and the query filter flags.

```text
CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred(this, out, object_type, filter_flags)
  if same non-zero high-16(object_type, filter_flags): *out = 0; return
  *out = (this->bit_rows[object_type & 31] & (1 << (filter_flags & 31))) != 0
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold CF (early-out + bit test) |
| Full body | `disassemble_function` + `read_memory` 80 B; size **73 B** |
| CF metrics | 4 BB, cyclomatic 2, 0 loops, 0 calls, 2× `RET 0xC` |
| Sole caller | dualed `CVOGPhysicsUtils_GetObjectsInArea` `0x004ea350` @ `0x004ea560` |
| Call-site context | `get_assembly_context` — push filterFlags, object+0x1c, out*; ECX=EBX |
| Parent dual | `A_aa_004ea350_CVOGPhysicsUtils_GetObjectsInArea.md` (filter last-arg) |
| Raw re-verify | `raw/aa_006c6c50_FUN_006c6c50.md` MEGA-039 append |

---

## 3. Signature (sealed)

```c
// ECX=this; stack out*, object_type, filter_flags; RET 0xC; void (result in *out)
void __thiscall CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred(
    AreaQueryFilterBitMatrix_Inferred *this,
    uint8_t *out,
    uint32_t object_type,
    uint32_t filter_flags);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX → EDX | **Confirmed** |
| out | stack `[ESP+4]`; both paths write `BYTE PTR [EAX]` | **Confirmed** |
| object_type (`a`) | stack `[ESP+8]`; caller `MOV EAX,[ESI+0x1c]` | **Confirmed** |
| filter_flags (`b`) | stack `[ESP+0xC]`; caller `MOV ECX,[EBP+0x1c]` (parent param_6) | **Confirmed** |
| cleanup | **`RET 0xC`** (`C2 0C 00`) ×2 | **Confirmed** |
| return channel | `*out`; EAX left as `out*` (parent `CMP [EAX],0`) | **Confirmed** |
| callees | **none** | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| `(a^b) & 0xFFFF0000 == 0` then `(a & 0xFFFF0000) != 0` → `*out=0` | bytes + decompile | **Confirmed** |
| Else `row=a&0x1F`, `bit=b&0x1F` | AND/SHL | **Confirmed** |
| Load `[this + 0x1C + row*4]` | `MOV ECX,[EDX+EAX*4+0x1C]` | **Confirmed** |
| `*out = (dword & (1<<bit)) != 0` via SETNZ | bytes | **Confirmed** |
| Two exits, both `RET 0xC` | epilogues | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf worker (area-query filter gate) |
| External callers | **1** UNCONDITIONAL_CALL (`FUN_004ea350`) |
| Site role | gate hits before object resolve / list append |
| Parent product | `CVOGPhysicsUtils::GetObjectsInArea` (AABB path string dualed) |
| Gather flag samples (parent dual) | `1` / `0x11` / `0x0a` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Sole caller dualed GetObjectsInArea | **Yes** |
| Role = filter bit test on query flags | **Yes** (body + call site) |
| Partition hint "area-query filter bit test" | **Yes** |
| Product demangle / RTTI for this leaf | **No** |
| Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_*` | **Reject** — parent fail string only |

**Decision:** promote **`CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred`**. `_Inferred` retained: this-object English + high-16 gate product rule + per-bit meanings open.

---

## 7. Gaps

- Product type/name of filter bit-matrix object (caller EBX).
- High-16 early-out product packing rule.
- Per-bit gameplay meanings for filter flags.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path seals CF/ABI/caller/filter role; residual product English only → **accept-with-gaps**.
