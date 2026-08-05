# Review A (reconstruction fidelity): `aa_005739b0` StdFill_DwordRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_005739b0` |
| **VA** | `0x005739b0` |
| **Body** | `0x005739b0`–`0x005739cd` (30 bytes) |
| **Canonical name** | `StdFill_DwordRange` |
| **Prior scaffold** | `FUN_005739b0` |
| **Review date** | `2026-07-29` (W19-B dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005739b0_StdFill_DwordRange.md` |
| **System** | `containers` / POD fill |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Leaf **`std::fill`-class** helper for **4-byte POD**:

```
for (p = first; p != last; ++p) *p = *value;
```

Half-open `[first, last)`. Template is a **pointer** to the dword (re-read each loop). Used after vector insert grow/shift to paint template values into the exposed range (e.g. `FUN_004507a0`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `decompile_function` @ `0x005739b0` |
| Bytes | `read_memory` 48 B — stack loads, `add eax,4`, bare `C3` |
| Callers | `get_function_callers` (29) |
| Callees | none |
| Parent context | decompile `FUN_004507a0` uses this for hole fill |
| Raw / clean | `aa_005739b0_*`, `StdFill_DwordRange.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__cdecl`, 3 stack pointers | **Confirmed** | `[esp+4/8/C]`; bare `ret` |
| `param_1`=first, `param_2`=last, `param_3`=value* | **Confirmed** | stores only through first; load from third |
| Stride 4 | **Confirmed** | `83 C0 04` |
| Half-open empty range no-op | **Confirmed** | early `je` when first==last |
| Leaf / POD assign only | **Confirmed** | no call, no ctor |
| Product `std::fill` name | **Inferred** | role-sealed |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load three pointers | Yes |
| Loop while first ≠ last | Yes |
| `*first = *value` | Yes |
| Advance first by 4 | Yes |
| Bare return | Yes |

```c
void StdFill_DwordRange(uint32_t *first, uint32_t *last, uint32_t const *value) {
  for (; first != last; first++) *first = *value;
}
```

---

## 5. Gaps / open

1. Product/PDB symbol.
2. Exhaustive catalog of element types behind the dword (always 4-byte storage width at this helper).
3. Runtime / differential.

**Verdict:** **accept**
