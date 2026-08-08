# Review A (reconstruction fidelity): `aa_0051c880` Map_EraseNode_Isnil1d_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051c880` |
| **VA** | `0x0051c880`–`0x0051cb36` exclusive (**694 B** / `0x2B6`) |
| **Canonical name** | `Map_EraseNode_Isnil1d_Inferred` |
| **Ghidra name** | `FUN_0051c880` |
| **Review date** | `2026-08-04` (WQ9F-F OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0051c880_Map_EraseNode_Isnil1d_Inferred.md` |
| **System** | STL / map-set (WQ-009 skill residual; single erase for isnil@+0x1d) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` / `analyze_function_complete` + `read_memory` (entry + full epilogue through `ret 8`) + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **single-node erase** for the **isnil@+0x1d** / **color@+0x1c** node family. Same role and post-delete size--/`*out` shape as dualed `Map_EraseNode` (`0x0051cb40`, isnil@+0x29), but different isnil/color immediates and callees.

Sole static caller: dualed **`Map_EraseRange_Isnil1d_Inferred`** (`0x0051d700`) partial-path erase loop.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `0x0051c880` (2026-08-04) |
| Bytes | entry SEH + isnil `+0x1d`; post-delete size-- / out-it / `C2 08 00` @ `0x0051cb33` |
| String | `"invalid map/set<T> iterator"` @ `0x00a152f0` |
| Successor | `FUN_0051b690` (isnil@+0x1d in-order) |
| Min / max | `FUN_0051b670` / `FUN_00421b90` |
| Rotates | `FUN_00420130` / `FUN_00420180` |
| Caller | `Map_EraseRange_Isnil1d_Inferred` @ `0x0051d79f` only (`xref_count=1`) |
| Twin isnil@+0x29 | `Map_EraseNode` `0x0051cb40` (694 B peer) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 694 B exclusive end `0x0051cb36`; `CC` pad; next `Map_EraseNode` @ `0x0051cb40` | **Confirmed** | `read_memory` supersedes Ghidra end `0x0051cb06` |
| `__thiscall` ECX=map (`mov ebp,ecx`); stack `(pOutIt, pNode)`; **`ret 8`** | **Confirmed** | entry + `C2 08 00` |
| isnil gate `@node+0x1d` → throw string | **Confirmed** | `cmp [eax+0x1d],0` + string push |
| Unlink + RB rebalance (color `@+0x1c`) | **Confirmed** | decomp + rotate callees + color immediates `0x1c` |
| `operator_delete` falls through | **Confirmed** | size-- + `*pOutIt` after call (decomp false-noreturn) |
| `map+0x08` size-- if >0 | **Confirmed** | post-delete bytes |
| `*pOutIt = successor` | **Confirmed** | tail store from local after `FUN_0051b690` |
| Sole caller range-erase isnil1d | **Confirmed** | xrefs |
| Name `Map_EraseNode_Isnil1d_Inferred` | **High** | structural + isnil discriminator; pairs with range dual |
| K/V / product English | Open | |
| Runtime / bit-exact | Open | |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| isnil → throw | **Yes** |
| successor + unlink + rebalance | **Yes** (raw/live) |
| delete → size-- → out it → ret 8 | **Yes** (bytes seal; decomp plate incomplete) |
| No invent key compare in body | **Yes** (erase-by-node only) |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| STL throw string | **Yes** |
| RB single-node erase structure | **Yes** |
| isnil@+0x1d discriminator vs Map_EraseNode | **Yes** |
| Product/PDB English | **No** |
| Collapse into Map_EraseNode / Map_EraseNode_B | **No** — different isnil/color/callees |

**Decision:** promote **`Map_EraseNode_Isnil1d_Inferred`** (structural; `_Inferred` for missing product English; isnil offset discriminates family).

---

## 6. Gaps

1. Product/PDB symbol; exact `map<K,V>` / value size for isnil@+0x1d family.
2. Full rotation-case algebra residual (CF sealed; every branch not line-proven).
3. Host class English beyond range-erase caller chain.
4. Runtime / image diff / bit-exact.

**Verdict:** **accept-with-gaps**
