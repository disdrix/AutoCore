# Review A (reconstruction fidelity): `aa_0043c8c0` GuardedVector_EraseRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c8c0` |
| **VA** | `0x0043c8c0`–`0x0043c9af` (**240 B**) |
| **Canonical name** | `GuardedVector_EraseRange` (**Inferred**) |
| **Ghidra name** | `FUN_0043c8c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-C) |
| **Counterpart** | `reviews/B_aa_0043c8c0_GuardedVector_EraseRange.md` |
| **System** | STL / guarded ring-vector container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; callers `0043c550`/`0043c730`/`0043c7e0`; callees `0043d300`/`0043d390` shape |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Erase absolute index range `[erase_from, erase_to)` in a ring/vector container:

1. `prefix = erase_from - begin`; `erase_cnt = erase_to - erase_from`.
2. If `prefix < suffix_len` → reverse-side move (`FUN_0043d300`) then advance `begin` (wrap at `capacity*4`) and shrink `size` per erased slot.
3. Else → forward-side move (`FUN_0043d390`) then shrink `size` only (zero `begin` when emptied).
4. Write out-iterator `{container, begin+prefix}` and return it.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043c8c0_FUN_0043c8c0.md` (+ 2026-07-29 W27-C append) |
| Annotated | `docs/reconstruction/raw/aa_0043c8c0_FUN_0043c8c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_EraseRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c8c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043c8c0_FUN_0043c8c0.md` |
| Named record | `docs/reconstruction/functions/aa_0043c8c0_GuardedVector_EraseRange.md` |
| Live | decompile ≡ raw; `read_memory` 240 B; xrefs 3; body end before `FUN_0043c9b0` |
| Context | parent fit path `GuardedVector_CopyAssign`; shrink `FUN_0043c7e0`; erase-one `FUN_0043c550` |

---

## 3. Signature (sealed)

```c
// EAX=container; stdcall 5 stack args; RET 0x14
int* GuardedVector_EraseRange(int* out_pair, uint32_t seed2, int erase_from,
                              uint32_t seed4, int erase_to);
```

| Slot | Source | Conf |
|---|---|---|
| container | **EAX** (`MOV ESI, EAX`) | **High** |
| out_pair | Stack[+4] | **High** |
| erase_from / erase_to | Stack[+0xc]/[+0x14] | **High** |
| cleanup | `RET 0x14` | **High** |
| return | out_pair in EAX | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
prefix = erase_from - [EAX+0xc]
erase_cnt = erase_to - erase_from
suffix = ([EAX+0x10]+[EAX+0xc]) - erase_to
if prefix < suffix:
  CALL FUN_0043d300
  loop erase_cnt: advance begin (wrap capacity*4), size--
else:
  CALL FUN_0043d390
  loop erase_cnt: size-- (begin=0 if empty)
out = {EAX_container, begin+prefix}; RET 0x14
```

| Stage | Match | Conf |
|---|---|---|
| Shorter-side branch | **Yes** | **High** |
| begin wrap `capacity*4` | **Yes** | **High** |
| size commit both arms | **Yes** | **High** |
| out iterator write | **Yes** | **High** |
| Nested move free | shape only | **Medium** |

---

## 5. Machine bytes (`read_memory`)

Entry:

```
83 EC 10 8B 54 24 1C 8B 4C 24 20 53 55 56 8B F0 …
```

Epilogue: `8B C1 5B 83 C4 10 C2 14 00` @ end of body.  
Callee targets: `0x0043c91e→0043d300`, `0x0043c96e→0043d390`.  
Body length **240 B** (`0x0043c8c0`–`0x0043c9af`).

---

## 6. Gaps

- Product/PDB class English (`GuardedVector_*` structural from parent dual family).
- Exact stack packing / element type inside unowned `FUN_0043d300` / `FUN_0043d390`.
- Runtime / bit-exact / differential.

---

## 7. Verdict

ABI, shorter-side erase CF, begin wrap, size update, and out-iterator sealed from live decompile + bytes + three callers. Nested element-move residual → **accept-with-gaps**.
