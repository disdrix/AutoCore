# Review A (reconstruction fidelity): `aa_004e5120` StdMap_EraseRange_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e5120` |
| **VA** | `0x004e5120` |
| **Canonical name** | `StdMap_EraseRange_Val12` (**Inferred**) |
| **Ghidra** | `FUN_004e5120` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W28-P) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile + bytes) |
| **Counterpart** | `reviews/B_aa_004e5120_StdMap_EraseRange_Val12.md` |
| **System** | STL map/set range erase Val12 |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style red-black **range erase** `[first, last)` on a Val12 map facade (`head@+4`, `size@+8`, **isnil@+0x19**). Full-tree path frees via `FUN_004e2940` and resets the sentinel; partial path uses in-order successor + `StdTree_EraseAndRebalance_Val12` (`0x004e4130`, W27-Q).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x004e5120` |
| Body bytes | `read_memory` 200 B @ entry (180 B body + pad) |
| Meta | `get_function_by_address` / `analyze_function_complete` |
| Single erase | W27-Q sealed `aa_004e4130` |
| Sole caller | `FUN_004e7350` live decompile (clear + delete head) |
| Peer | `aa_004bacf0` isnil@+0x15 range erase |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, `disassemble_bytes`.

---

## 3. Signature

```c
void __thiscall StdMap_EraseRange_Val12(
    void *map, void **out_it, void *first, void *last);
// RET 0x0C
```

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Full-range `first==*head && last==head` | Yes |
| `004e2940` + head reset + size 0 | Yes |
| Successor + `004e4130` loop | Yes |
| `*out_it` write | Yes |
| `ret 0x0c` both exits | Yes (bytes) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| MSVC map/set range erase | **High** | peer shape + Val12 erase callee + isnil |
| Head@+4 size@+8 | **High** | body |
| Val12 isnil@+0x19 | **High** | successor loads |
| Sole caller map destroy/clear | **High** | `004e7350` |
| Product type / demangle | **Tentative** | open |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product mangled name for the map instantiation.
2. Full left-recurse proof inside `FUN_004e2940` (false-noreturn residual).
3. Runtime / bit-exact / differential — open.

---

## 7. Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e5120_FUN_004e5120.md` |
| Annotated | `docs/reconstruction/raw/aa_004e5120_FUN_004e5120.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_EraseRange_Val12.cpp` |
| Function | `docs/reconstruction/functions/aa_004e5120_StdMap_EraseRange_Val12.md` |

**Verdict:** **accept-with-gaps**
