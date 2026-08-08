# Review A (reconstruction fidelity): `aa_0051be90` Map_FreeSubtree_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051be90` |
| **VA** | `0x0051be90`–`0x0051bec5` (**53 B**) |
| **Canonical name** | `Map_FreeSubtree_B` |
| **Ghidra name** | `FUN_0051be90` |
| **Review date** | `2026-08-04` (WQ9E-I OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0051be90_Map_FreeSubtree_B.md` |
| **System** | STL / map-set (WQ-009 skill residual; free helper for Map_EraseRange_B) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` + `read_memory` (full body + pad) + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **subtree free** for the large-node family (`isnil@+0x29`). Sole external caller is dualed **`Map_EraseRange_B`** full-clear path (`FUN_0051be90(head->parent)`). Byte CF matches established free-subtree pattern (`MapFloatTfid_FreeSubtree_Isnil29_Inferred`): recurse right, delete node, walk left.

Discriminator for `Map_EraseRange_B` vs `Map_EraseRange` (which frees via `FUN_0051bbc0`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `0x0051be90` (2026-08-04) |
| Bytes | 53 B; `ret 4`; isnil `+0x29` immediates; left load `mov esi,[esi]` after right free |
| Caller | `Map_EraseRange_B` / `0x0051d880` @ `0x0051d89c` |
| Twin CF | `MapFloatTfid_FreeSubtree_Isnil29_Inferred` `0x0058da00`; sibling free `FUN_0051bbc0` |
| Peer free isnil@+0x1d | `FUN_0051be10` (same shape; used by `Map_EraseRange_Isnil1d_Inferred`) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 53 B; `ret 4` | **Confirmed** | bytes / Ghidra body end |
| Stack `node*`; ECX threaded unused | **Confirmed** | entry + call site |
| isnil@+0x29 | **Confirmed** | `cmp [edi+0x29],0` |
| Right recurse + left walk + delete | **Confirmed** | bytes restore left walk decomp dropped |
| Sole external caller Map_EraseRange_B | **Confirmed** | xrefs |
| Name `Map_FreeSubtree_B` | **High** | free helper of sealed Map_EraseRange_B |
| Value dtor / map type English | Open | delete-only surface |
| Runtime / bit-exact | Open | |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| isnil early-out | **Yes** |
| Right-child free | **Yes** (decomp + bytes) |
| Left-walk after delete | **Yes bytes** / decomp plate incomplete (false-noreturn) |
| `ret 4` | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Free-subtree for Map_EraseRange_B | **Yes** |
| Twin isnil@+0x29 free pattern | **Yes** |
| Product/PDB English | **No** |
| Collapse into MapFloatTfid free | **No** — different VA / caller map |

**Decision:** promote **`Map_FreeSubtree_B`** (pairs with `Map_EraseRange_B`; keep distinct from `FUN_0051bbc0` / MapFloatTfid free).

---

## 6. Gaps

1. Exact map instantiation / why second isnil@+0x29 free exists vs `FUN_0051bbc0`.
2. Twin free `FUN_0051bbc0` dual (WQ9E-H OWN).
3. Runtime / image diff / bit-exact.

**Verdict:** **accept-with-gaps**
