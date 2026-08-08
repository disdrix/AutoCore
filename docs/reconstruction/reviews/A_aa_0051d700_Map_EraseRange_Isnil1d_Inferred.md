# Review A (reconstruction fidelity): `aa_0051d700` Map_EraseRange_Isnil1d_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d700` |
| **VA** | `0x0051d700`–`0x0051d7b4` (**180 B**) |
| **Canonical name** | `Map_EraseRange_Isnil1d_Inferred` |
| **Ghidra name** | `FUN_0051d700` |
| **Review date** | `2026-08-04` (WQ9E-I OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0051d700_Map_EraseRange_Isnil1d_Inferred.md` |
| **System** | STL / map-set (WQ-009 skill residual helper; isnil@+0x1d) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` + `read_memory` (full body + pad) + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **map/set range erase** for the **isnil@+0x1d** node family. Same CF/ABI as dualed `Map_EraseRange` / `Map_EraseRange_B` (180 B, `ret 0x0c`, full-clear vs partial successor loop) but:

- isnil offset **`+0x1d`** (not `+0x29`)
- full-clear free **`FUN_0051be10`**
- partial single erase **`FUN_0051c880`** (throws `invalid map/set<T> iterator`)

Sole static caller: map host complete dtor `FUN_0051e120`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `0x0051d700` (2026-08-04) |
| Bytes | 180 B; tails `C2 0C 00`; isnil `+0x1d` immediates |
| Free subtree | live `FUN_0051be10` (isnil@+0x1d; twin shape of Map_FreeSubtree_B) |
| Single erase | live `FUN_0051c880` (map/set throw string) |
| Caller | `FUN_0051e120` only |
| Peer range-erases | `Map_EraseRange` / `_B` isnil@+0x29; `0x0051d7c0` isnil@+0x15 |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 180 B; `ret 0x0c` both exits | **Confirmed** | bytes |
| `__thiscall` ECX=map; stack `(out, first, last)` | **Confirmed** | entry + ret 12 |
| Full clear: first==*head && last==head | **Confirmed** | decomp ≡ bytes |
| Free via FUN_0051be10(head->parent) + head reset + size 0 | **Confirmed** | rel call target |
| Partial: successor isnil@+0x1d + FUN_0051c880 | **Confirmed** | decomp + call |
| Distinct from Map_EraseRange family | **Confirmed** | isnil + callees differ |
| Name Map_EraseRange_Isnil1d_Inferred | **High** | structural; isnil discriminator |
| K/V payload English | Open | |
| Runtime / bit-exact | Open | |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Full-range detection | **Yes** |
| Free + head reset + size 0 + out | **Yes** |
| Successor walk isnil@+0x1d | **Yes** |
| FUN_0051c880 with ECX=map | **Yes** |
| `*out_it` + `ret 0x0c` | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| STL range-erase structure | **Yes** |
| isnil@+0x1d discriminator | **Yes** |
| Product/PDB English | **No** |
| Collapse into Map_EraseRange | **No** — different isnil + free + erase-node |

**Decision:** promote **`Map_EraseRange_Isnil1d_Inferred`**.

---

## 6. Gaps

1. Exact `map<K,V>` / value size for isnil@+0x1d family.
2. Dual of free `FUN_0051be10` and erase-node `FUN_0051c880` (not OWN).
3. Host class English for `FUN_0051e120`.
4. Runtime / image diff / bit-exact.

**Verdict:** **accept-with-gaps**
