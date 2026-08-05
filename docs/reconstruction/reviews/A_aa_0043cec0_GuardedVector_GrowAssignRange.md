# Review A (reconstruction fidelity): `aa_0043cec0` GuardedVector_GrowAssignRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cec0` |
| **VA** | `0x0043cec0`–`0x0043ceef` (**48 B**) |
| **Canonical name** | `GuardedVector_GrowAssignRange` (**Inferred**) |
| **Ghidra name** | `FUN_0043cec0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-C) |
| **Counterpart** | `reviews/B_aa_0043cec0_GuardedVector_GrowAssignRange.md` |
| **System** | STL / guarded ring-vector container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; sole caller `FUN_0043c730`; callee `FUN_0043cf40` |
| **Verdict** | **accept** |

---

## 1. Purpose

Thin stdcall trampoline for the **grow** path of `GuardedVector_CopyAssign`:

```
FUN_0043cf40(p1, p2, p3, p4, p5, p6, p7, p1);
```

Duplicates `param_1` (dest) as the eighth formal. No other logic.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043cec0_FUN_0043cec0.md` (+ 2026-07-29 W27-C append) |
| Annotated | `docs/reconstruction/raw/aa_0043cec0_FUN_0043cec0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_GrowAssignRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043cec0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043cec0_FUN_0043cec0.md` |
| Named record | `docs/reconstruction/functions/aa_0043cec0_GuardedVector_GrowAssignRange.md` |
| Live | decompile ≡ raw; full 48 B hex; sole xref `0x0043c7c5` |
| Context | parent grow args from sealed `GuardedVector_CopyAssign` |

---

## 3. Signature (sealed)

```c
// stdcall 7 args; RET 0x1c
void GuardedVector_GrowAssignRange(uint32_t p1, uint32_t p2, uint32_t p3,
                                   uint32_t p4, uint32_t p5, uint32_t p6,
                                   uint32_t p7);
```

| Slot | Source | Conf |
|---|---|---|
| 7 formals | Stack | **High** |
| 8th to callee | `param_1` re-push | **High** |
| cleanup | `RET 0x1c` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
push packed args → CALL FUN_0043cf40 → RET 0x1c
```

| Stage | Match | Conf |
|---|---|---|
| Single call only | **Yes** | **High** |
| 8th arg = p1 | **Yes** | **High** |
| No other side effects | **Yes** | **High** |
| Nested grow free | out of body | n/a (unowned) |

---

## 5. Machine bytes (`read_memory`)

Full body (48 B):

```
8B 44 24 04 8B 4C 24 1C 8B 54 24 18 50 …
E8 53 00 00 00    ; CALL 0x0043cf40 @ 0x0043cee8
C2 1C 00          ; RET 0x1c
```

---

## 6. Gaps

- Nested grow/construct/destroy inside unowned `FUN_0043cf40` (not this unit's body).
- Product/PDB English.
- Runtime golden for full assign-grow path.

Body itself has **no** residual control-flow gaps.

---

## 7. Verdict

Trampoline ABI + 8-arg forward fully sealed from live decompile + complete body hex + sole caller → **accept**.
