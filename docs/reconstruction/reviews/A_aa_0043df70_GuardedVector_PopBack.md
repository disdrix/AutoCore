
# Review A (reconstruction fidelity): `aa_0043df70` GuardedVector_PopBack

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043df70` |
| **VA** | `0x0043df70`–`0x0043df86` (**23 B**) |
| **Canonical name** | `GuardedVector_PopBack` (**Inferred**) |
| **Ghidra name** | `FUN_0043df70` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-C) |
| **Counterpart** | `reviews/B_aa_0043df70_GuardedVector_PopBack.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live `decompile_function` + `analyze_function_complete` + `read_memory` (full 23 B); 5 SEH callers; leaf |
| **Verdict** | **accept** |

---

## 1. Purpose

Pop-back **bookkeeping** on GuardedVector: decrement size; if the container becomes empty, reset begin to 0. No destructor, no page free.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043df70_FUN_0043df70.md` (+ 2026-07-29 W30-C append) |
| Annotated | `docs/reconstruction/raw/aa_0043df70_FUN_0043df70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PopBack.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043df70.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043df70_FUN_0043df70.md` |
| Named record | `docs/reconstruction/functions/aa_0043df70_GuardedVector_PopBack.md` |
| Live | decompile ≡ raw ≡ full body hex; ECX this |
| Context | W29-A InsertN SEH names this pop_back; polarity twin of `FUN_0040d980` pop_front |

---

## 3. Signature (sealed)

```c
// ECX=container; plain RET; no stack formals
void GuardedVector_PopBack(GuardedVectorHeader* container /*ECX*/);
```

| Slot | Source | Conf |
|---|---|---|
| container | **ECX** (`MOV EAX,[ECX+0x10]`) | **High** |
| size | `[ECX+0x10]` | **High** |
| begin | `[ECX+0x0c]` (store 0 on empty) | **High** |
| cleanup | plain `RET` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
size = [ECX+0x10]
if size == 0: RET
size -= 1
[ECX+0x10] = size
if size == 0: [ECX+0x0c] = 0
RET
```

| Stage | Match | Conf |
|---|---|---|
| Non-empty gate | **Yes** | **High** |
| size-- | **Yes** | **High** |
| Empty begin reset | **Yes** | **High** |
| No free/dtor | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

```
8B 41 10 85 C0 74 0F 83 C0 FF 89 41 10 75 07 C7 41 0C 00 00 00 00 C3
```

Body length **23 B** (`0x0043df70`–`0x0043df86`). Pad `CC`.

---

## 6. Gaps

- Product/PDB English only (structural name sealed by family + SEH role).
- Runtime / bit-exact under multi-insert unwind (not required for CF seal).

---

## 7. Verdict

Fidelity pass: ABI + full CF + offsets sealed with decompile ≡ bytes. Residual is naming English only → **accept**.

