# Review A (reconstruction fidelity): `aa_004bcc40` ThreadSafeObjectList_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcc40` |
| **VA** | `0x004bcc40`–`0x004bcc5d` |
| **Body** | **30** bytes |
| **Canonical name** | `ThreadSafeObjectList_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004bcc40` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-I) |
| **Counterpart** | `reviews/B_aa_004bcc40_ThreadSafeObjectList_ScalarDeletingDtor.md` |
| **System** | client::util / lock-protected object list |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC **scalar deleting destructor** for `ThreadSafeObjectList` (list vtbl slot 0):

1. Always call complete body dtor `ThreadSafeObjectList_Dtor` (`FUN_004bcbf0`).
2. If `(flags & 1)` → `operator_delete(this)`.
3. Return `this` in EAX.

Distinct from complete body @ `0x004bcbf0` (no free, no flags formal).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004bcc40_FUN_004bcc40.md` (+ W26-I append) |
| Annotated | `docs/reconstruction/raw/aa_004bcc40_FUN_004bcc40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ThreadSafeObjectList_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bcc40.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bcc40_FUN_004bcc40.md` |
| Named record | `docs/reconstruction/functions/aa_004bcc40_ThreadSafeObjectList_ScalarDeletingDtor.md` |
| Sibling dual | W25-C `ThreadSafeObjectList_Dtor` |
| Live | decompile ≡ raw; `read_memory` 30 B; vtbl slot0 |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX = this; stack flags; RET 4; EAX = this
void *ThreadSafeObjectList_ScalarDeletingDtor(void *thisList, uint8_t flags);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX | **High** |
| flags | Stack[0x4] (after push esi: `[esp+8]`) | **High** |
| return | EAX = this | **High** |
| cleanup | `RET 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
esi = this
call ThreadSafeObjectList_Dtor(this)
if (flags & 1): operator_delete(this)
return this
```

| Stage | Match | Conf |
|---|---|---|
| Body dtor first | **Yes** | **High** |
| Free only bit0 | **Yes** | **High** |
| EAX = this | **Yes** | **High** |
| RET 4 | **Yes** | **High** |
| Vtbl[0] placement | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body (30 B):
```
568bf1e8a8fffffff644240801740956e8cdcbfcff83c4048bc65ec20400
```

Epilogue: `8B C6 5E C2 04 00`. Relative CALL from `0x004bcc43` → `0x004bcbf0`.

---

## 6. Gaps

- Product English / PDB mangled name on this VA.
- Runtime free path / differential — open.

---

## 7. Verdict

CF, ABI, free gate, and family naming are sealed against complete-dtor sibling dual. → **accept**.
