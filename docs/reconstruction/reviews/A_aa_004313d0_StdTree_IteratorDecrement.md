# Review A (reconstruction fidelity): `aa_004313d0` StdTree_IteratorDecrement

| Field | Value |
|---|---|
| **Stable ID** | `aa_004313d0` |
| **VA** | `0x004313d0` |
| **Body** | `0x004313d0`–`0x00431420` (80 bytes) |
| **Canonical name** | `StdTree_IteratorDecrement` |
| **Prior scaffold** | `FUN_004313d0` |
| **Review date** | `2026-07-29` (W22-O dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004313d0_StdTree_IteratorDecrement.md` |
| **System** | shared `client::stdtree` |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

In-place **MSVC tree/map iterator decrement** (predecessor). Updates `*it` where `it` is a `node**` in **EDX**. Classic RB-tree predecessor with header-nil special case (`*it = right` when current is nil).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x004313d0` |
| Bytes | `read_memory` 80 B + epilogue `89 02 C3` |
| Bounds | `get_function_by_address` body `004313d0`–`00431420` |
| Callees | none |
| Callers | `get_function_xrefs` → 4 sites including `StdMap_StringKey_InsertOrFind` |
| Call site bytes | `lea edx,[esp+disp]; call` @ insert path |
| Raw / clean | `aa_004313d0_*`, `StdTree_IteratorDecrement.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EDX = `node**`; in-place update | **Confirmed** | `8B 02` / `89 02`; call `lea edx` |
| Nil at `+0x2d` | **Confirmed** | `80 78 2D 00` throughout |
| left/parent/right @ +0/+4/+8 | **Confirmed** | decomp ≡ bytes |
| Nil → right (rightmost) | **Confirmed** | first path |
| Left subtree → rightmost walk | **Confirmed** | second path |
| Parent climb while left-child | **Confirmed** | third path |
| Not successor | **Confirmed** | dual of `004cb270` which walks right→leftmost |
| Product C++ name | **Inferred** | role-sealed |
| Runtime / bit-exact | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Nil header → right | Yes |
| Left non-nil → rightmost | Yes |
| Parent climb while left | Yes |
| No invented recolor/rotate | Yes |
| No stack args / plain ret | Yes |

---

## 5. Gaps / open

1. Exact MSVC template symbol string.
2. Payload layout beyond tree header (owned by map node duals).
3. Runtime / differential.

**Verdict:** **accept**
