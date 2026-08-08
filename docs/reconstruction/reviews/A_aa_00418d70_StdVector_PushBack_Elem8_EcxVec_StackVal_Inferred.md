# Review A (reconstruction fidelity): `aa_00418d70` StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418d70` |
| **VA** | `0x00418d70`–`0x00418dc6` exclusive (**86 B** / `0x56`) |
| **Canonical name** | `StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred` |
| **Ghidra name** | `FUN_00418d70` |
| **Prior scaffold** | `FUN_00418d70` + misname `Named_CalleeOf_Named_VOG_DEBUG_STOP_00418d70` |
| **Rejected misname** | permanent bare `FUN_*`; parent-string `Named_CalleeOf_*`; domain-locked CrewCoidPush |
| **Review date** | `2026-08-05` (R10-025 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00418d70_StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred.md` |
| **System** | util / container (partition residual under skills-abilities parent `0x005755b0`) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `force_decompile` + `analyze_function_complete` + `get_function_callers` + `get_function_xrefs` + `read_memory` (body + parent site). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **`vector::push_back`** for **8-byte POD** elements (two dwords):

```text
StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred(vec/*ECX*/, value/*stack T**/)
  begin = vec+4
  size  = begin ? (end-begin)>>3 : 0
  if begin && size < capacity:
    *end = value[0]; *(end+4) = value[1]; end += 8; return
  else:
    FUN_00418e10(vec, &scratch, end, value)   // grow / insert-one
```

Multi-domain util (13 call sites). Parent crew insert pushes COID lo/hi into `host+0x1F4` — evidence only, not a product lock.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | force_decompile 2026-08-05 ≡ raw scaffold CF |
| Bytes | `read_memory` 96 B — SAR 3, ADD 8, dual `C2 04 00`, CALL `00418e10` |
| Parent site | `0x00575670`: `LEA ECX,[ESI+0x1F4]` then CALL |
| Callers | 8 named + 3 orphan UNCONDITIONAL_CALL |
| Callee | `FUN_00418e10` insert-one/rebind |
| Prior misname | Named_CalleeOf VOG_DEBUG_STOP (parent false path only) |

---

## 3. Signature (sealed)

```c
// __thiscall; RET 4
void StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred(
    void *vec /*ECX*/,
    const uint32_t *value /*[ESP+4]*/);
```

| Formal | Source | Conf |
|---|---|---|
| vec | ECX host begin@+4 end@+8 cap@+0xC | **Confirmed** |
| value | stack pointer to 8-byte POD | **Confirmed** |
| return | void | **Confirmed** |
| cleanup | `RET 4` both exits | **Confirmed** |
| convention | **thiscall** (1 stack arg) | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| PUSH ESI / load begin | bytes | **Confirmed** |
| size via SAR 3 | bytes | **Confirmed** |
| begin null → slow | JZ | **Confirmed** |
| capacity SAR 3 compare | CMP/JAE | **Confirmed** |
| fast POD copy 2×u32 | MOV/MOV | **Confirmed** |
| end += 8 store | ADD EAX,8 | **Confirmed** |
| slow CALL 00418e10 | E8 +0x4E → 00418e10 | **Confirmed** |
| dual RET 4 | C2 04 00 | **Confirmed** |
| Live decompile ≡ raw body | force_decompile | **Confirmed** |

---

## 5. Gaps

- Product element English beyond 8-byte POD / parent COID pair usage.
- Dual seal of grow engine `00418e10` / `00418e60`.
- Orphan site plates `00564eab` / `00564f4b` / `005ad471`.
- Runtime / bit-exact / differential.

---

## 6. Verdict

**accept-with-gaps** — CF/ABI/thiscall-ECX/stack-val/stride-8/fast-copy/slow-grow/callers sealed via decompile + bytes + parent site; product type English + grow dual + runtime open.
