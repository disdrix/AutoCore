# Review A (reconstruction fidelity): `aa_005cc450` CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cc450` |
| **VA** | `0x005cc450`–`0x005cc45b` |
| **Canonical name** | `CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1` |
| **Ghidra name** | `FUN_005cc450` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-L) |
| **Counterpart** | `reviews/B_aa_005cc450_CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1.md` |
| **System** | npc-ai / HBAI / aim-offset dispatch |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + xrefs; sibling aim dual |
| **Verdict** | **accept** |

---

## 1. Purpose

HBAI leaf thunk that dispatches the stored aim-offset buffer at `this+0x40` through virtual slot **`+0x4c`** with enable/flag **1**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005cc450_FUN_005cc450.md` (+ 2026-07-29 W28-L append) |
| Annotated | `docs/reconstruction/raw/aa_005cc450_FUN_005cc450.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005cc450.cpp` |
| Function | `docs/reconstruction/functions/aa_005cc450_FUN_005cc450.md` |
| Named record | `docs/reconstruction/functions/aa_005cc450_CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1.md` |
| Live | decompile ≡ 12 B hex `8B016A018D514052FF504CC3` |
| Sibling | `CVOGHBAI_UpdateAimOffset_Inferred` stores aim vec4 at `this+0x40` |

---

## 3. Signature (sealed)

```c
// thiscall; 0 stack formals; RET 0
void CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1(void *this);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX | **High** |
| cleanup | `RET` (`C3`) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
fn = this->vtbl[+0x4c]
fn(this, this+0x40, 1)
return
```

| Stage | Match | Conf |
|---|---|---|
| Load vtbl | **Yes** `MOV EAX,[ECX]` | **High** |
| Push 1 | **Yes** `6A 01` | **High** |
| Lea +0x40 | **Yes** `8D 51 40` | **High** |
| Call [EAX+0x4C] | **Yes** | **High** |
| Bare RET | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

```
8b016a018d514052ff504cc3
```

---

## 6. Gaps

- Product English for **vtbl+0x4c** (path/move/aim apply).
- Semantic of flag **1** vs alternate formals at other call sites.
- Runtime / bit-exact — open.

---

## 7. Verdict

Entire body is 12 sealed bytes; ABI and formals unambiguous; aim storage role backed by sibling dual. Naming is structural (vtbl offset + aim field + flag). → **accept**.
