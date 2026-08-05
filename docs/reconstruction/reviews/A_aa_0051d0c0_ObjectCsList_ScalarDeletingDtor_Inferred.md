# Review A (reconstruction fidelity): `aa_0051d0c0` ObjectCsList_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d0c0` |
| **VA** | `0x0051d0c0`–`0x0051d0de` exclusive (**30 B** / `0x1E`) |
| **Canonical name** | `ObjectCsList_ScalarDeletingDtor_Inferred` |
| **Ghidra name** | `FUN_0051d0c0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-O) |
| **Counterpart** | `reviews/B_aa_0051d0c0_ObjectCsList_ScalarDeletingDtor_Inferred.md` |
| **System** | object core / CS-owned list teardown |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + xrefs + vtbl `read_memory`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **scalar deleting destructor** for **derived** CS-list vtbl `PTR_FUN_009ce154` (slot0):

1. `FUN_0051d0e0(this)` — sealed complete dtor (derived→base vtbl phases, drain, DeleteCS).
2. If `flags & 1`: `operator_delete(this)` (cdecl).
3. Return `this` (`RET 4`).

**Not skill.** Accuracy priority under skill-adjacent partition note: body and vtbl prove object CS-list teardown only.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-O) | `docs/reconstruction/raw/aa_0051d0c0_FUN_0051d0c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051d0c0_FUN_0051d0c0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/ObjectCsList_ScalarDeletingDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051d0c0.cpp` |
| Function records | `functions/aa_0051d0c0_FUN_0051d0c0.md`, `functions/aa_0051d0c0_ObjectCsList_ScalarDeletingDtor_Inferred.md` |
| Complete twin | `FUN_0051d0e0` / `ObjectCsList_CompleteDtor_Inferred` (W31-R) |
| Live | decompile ≡ raw; DATA vtbl slot0; body hex 30 B; vtbl dword `c0d05100` @ `009ce154` |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=list*; stack flags; RET 4; returns this
void * __thiscall ObjectCsList_ScalarDeletingDtor_Inferred(void *list, uint8_t flags);
```

| Formal | Source | Conf |
|---|---|---|
| list | ECX (`56 8B F1`) | **High** |
| flags | stack; `TEST [ESP+8],1` after push ESI | **High** |
| return | EAX=`this`; `C2 04 00` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
MOV ESI,ECX
CALL FUN_0051d0e0          // +0x20 → complete
TEST [ESP+8],1
JZ skip
  PUSH ESI; CALL operator_delete; ADD ESP,4
skip:
MOV EAX,ESI; POP ESI; RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Complete then optional free | **Yes** | **High** |
| flags bit0 only | **Yes** | **High** |
| Fall-through after delete | **Yes** (bytes; decompiler noreturn false) | **High** |
| No inline DeleteCS / clear | **Yes** — delegated to `0051d0e0` | **High** |
| DATA vtbl only | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Entry | `56 8B F1 E8 18 00 00 00` → call `0051d0e0` |
| Flag / free | `F6 44 24 08 01 74 09 56 E8 … 83 C4 04` |
| Epilogue | `8B C6 5E C2 04 00` |
| Size | **30 B** exclusive end `0x0051d0de` |
| Vtbl | `@009ce154` first dword = `0x0051d0c0` |
| Full hex | raw W37-O append |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product derived class English for `PTR_FUN_009ce154`.
- No `flags&2` array path in body (normal for scalar-only thunk).
- Runtime / bit-exact / differential.

---

## 7. Verdict

CF, ABI, complete-then-free, vtbl slot0 sealed; product English residual → **accept-with-gaps**.
