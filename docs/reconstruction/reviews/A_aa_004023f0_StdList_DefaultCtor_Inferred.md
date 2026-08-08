# Review A (reconstruction fidelity): `aa_004023f0` StdList_DefaultCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004023f0` |
| **VA** | `0x004023f0`–`0x00402405` inclusive (**22 B** / `0x16`) |
| **Canonical name** | `StdList_DefaultCtor_Inferred` |
| **Ghidra name** | `FUN_004023f0` |
| **Prior scaffold** | `Named_CalleeOf_CVOGReaction_Dispatch_004023f0` (**retired**) |
| **Rejected misname** | reaction/mission packet helper; full list insert/copy; vector ctor itself |
| **Review date** | `2026-08-05` (MEGA-052 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004023f0_StdList_DefaultCtor_Inferred.md` |
| **System** | shared MSVC `std::list` (partition seed: missions-progression / `CVOGReaction_Dispatch`) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **default constructor** for an empty MSVC circular `std::list` object:

```text
StdList_DefaultCtor_Inferred(this) -> this
  head = StdList_AllocEmptySentinel_Inferred()   // 0x0040fb90; new(0xc) self-linked
  this->_Myhead (+4) = head
  this->_Mysize (+8) = 0
  return this
```

Not domain logic — used as stack-local list ctor and as **element ctor** for arrays of list objects (`_eh_vector_constructor_iterator_` with element size **0xC**).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ original raw CF (alloc → head@+4 → size@+8=0 → return this) |
| Full body | `disassemble_function` + `read_memory` 22 B code + `CC` pad |
| Callee | dualed `StdList_AllocEmptySentinel_Inferred` `0x0040fb90` |
| Pair destroy | dualed `StdList_Destroy_FreeHead_Inferred` `0x00403430` |
| Sibling copy | `FUN_00402410` (same head/size init + range insert) |
| Sample callers | `CVOGReaction_Dispatch` @ `0057c9c7`; `CVOGVariable_EvaluateComputed` @ `005afe6c` |
| DATA sites | `FUN_004e80c0` PUSH ctor+dtor; `FUN_008a5c90` PUSH ctor |

---

## 3. Signature (sealed)

```c
// ECX=this list*; no stack args; EAX=this; RET
void* /*list**/ __fastcall StdList_DefaultCtor_Inferred(void* /*list**/ this);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX → ESI | **Confirmed** |
| stack args | none | **Confirmed** |
| return | EAX = this | **Confirmed** |
| cleanup | `RET` (`C3`) | **Confirmed** |
| head store | `MOV [ESI+4], EAX` after alloc | **Confirmed** |
| size store | `MOV [ESI+8], 0` | **Confirmed** |
| callee | `CALL 0x0040fb90` (relok `E8 98 D7 00 00`) | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Save this in ESI | `PUSH ESI; MOV ESI,ECX` | **Confirmed** |
| Alloc empty sentinel | sole CALL | **Confirmed** |
| `_Myhead = EAX` | dword store +4 | **Confirmed** |
| `_Mysize = 0` | imm0 store +8 | **Confirmed** |
| Return this | `MOV EAX,ESI; POP ESI; RET` | **Confirmed** |
| No branches / no SEH in this unit | linear 8-insn body | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | wrapper / empty-list default ctor |
| UNCONDITIONAL_CALL | **5** (`CVOGReaction_Dispatch`, `CVOGVariable_EvaluateComputed`, `FUN_0089bc30`, `FUN_008edc80`, `FUN_008a8770`) |
| DATA (ctor ptr) | **2** (`FUN_004e80c0`, `FUN_008a5c90`) — vector of 0xC list objects |
| Site pattern | `LEA ECX, [stack_list]; CALL 004023f0` |
| Callees | `FUN_0040fb90` only |
| Object stride | **0xC** (vector PUSH `0xc`) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Dualed sentinel alloc + destroy pair (head@+4) | **Yes** |
| Empty size store @+8 | **Yes** |
| Vector element size 0xC matching list object | **Yes** |
| Broad non-domain xref surface | **Yes** |
| Reaction/mission product English in body | **No** |
| RTTI / decorated product name | **No** → `_Inferred` |

**Decision:** promote **`StdList_DefaultCtor_Inferred`**. Retire `Named_CalleeOf_CVOGReaction_Dispatch_004023f0`.

---

## 7. Gaps

- Unwritten `list+0` (allocator / `_Container_base`) — residual, not this unit's job.
- Element type `T` of each consuming list (site-specific).
- Runtime / bit-exact / differential (no Launcher).

---

## 8. Verdict

Fidelity path accepts CF/ABI/layout with only residual +0 / element-`T` gaps → **accept-with-gaps**.
