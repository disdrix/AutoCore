# Review A (reconstruction fidelity): `aa_00401bc0` Std_OutOfRange_CtorFromString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401bc0` |
| **VA** | `0x00401bc0`–`0x00401c10` inclusive (**81 B** / `0x51`) |
| **Canonical name** | `Std_OutOfRange_CtorFromString` |
| **Ghidra name** | `FUN_00401bc0` |
| **Prior scaffold** | `FUN_00401bc0` |
| **Rejected misname** | `Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect_00401bc0` |
| **Review date** | `2026-08-05` (WQ9L-B OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00401bc0_Std_OutOfRange_CtorFromString.md` |
| **System** | MSVC STL / `std::out_of_range` |
| **Verdict** | **accept** |

**Tools:** Ghidra `batch_decompile` + `disassemble_function` + `analyze_function_complete` + `read_memory` + `search_strings` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **constructor** for `std::out_of_range` from a `std::string` message. Parents construct a temporary string (`"invalid map/set<T> iterator"`, …), call this, then `_CxxThrowException` with ThrowInfo `DAT_00acc34c`.

```text
Std_OutOfRange_CtorFromString(this, msg) -> this
  SEH install
  logic_error(msg)   // FUN_00401aa0
  this->vtbl = out_of_range_vtbl  // PTR_FUN_009c7640
  return this
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold CF (SEH → base → vtbl) |
| Full body | `disassemble_function` + `read_memory` 80 B |
| Base | `FUN_00401aa0` — exception + string@+0x0c + logic_error vtbl `009c7628` |
| RTTI | `.?AVout_of_range@std@@` @ `0x00af8b98` |
| ThrowInfo | `DAT_00acc34c` catchable `pType` → out_of_range TD; size **0x28** |
| Sample caller | dualed erase isnil31 `0x00408ed0` @ `0x00408f17` |
| Twin | dualed `Std_LengthError_CtorFromString` `0x00401a40` |

---

## 3. Signature (sealed)

```c
// ECX=this; stack msg*; EAX=this; RET 4
std::out_of_range* __thiscall Std_OutOfRange_CtorFromString(
    std::out_of_range* this,
    const std::string* msg);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX → ESI | **Confirmed** |
| msg | stack `[ESP+4]` after entry | **Confirmed** |
| return | EAX = this | **Confirmed** |
| cleanup | `RET 4` (`C2 04 00`) | **Confirmed** |
| base | `CALL FUN_00401aa0` | **Confirmed** |
| vtbl | `MOV [ESI], 0x009c7640` | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| SEH install FS:[0] / LAB_009bc828 | bytes | **Confirmed** |
| logic_error base | sole CALL | **Confirmed** |
| out_of_range vtbl install | dword store | **Confirmed** |
| Unlink SEH; return this | epilog | **Confirmed** |
| No throw inside body | no `_CxxThrowException` | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (STL ctor) |
| External callers | **25** UNCONDITIONAL_CALL |
| Site role | nil-iterator / out-of-range throw prep |
| Callees | `FUN_00401aa0` only |
| Shared message | `"invalid map/set<T> iterator"` @ `0x00a152f0` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| RTTI `.?AVout_of_range@std@@` | **Yes** |
| Twin of dualed length_error ctor pattern | **Yes** |
| ThrowInfo catchable → out_of_range | **Yes** |
| Skill/mission product English | **No** (not product-specific) |

**Decision:** promote **`Std_OutOfRange_CtorFromString`**. Reject skill-seed plate.

---

## 7. Gaps

- Full vtable slot English (`what`, dtor, …) — low priority.
- Runtime throw golden / bit-exact / differential.

---

## 8. Verdict

Fidelity path accepts CF/ABI/RTTI with only low-priority vtable residual → **accept**.
