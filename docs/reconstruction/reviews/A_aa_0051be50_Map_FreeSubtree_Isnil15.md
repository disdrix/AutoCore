# Review A (reconstruction fidelity): `aa_0051be50` Map_FreeSubtree_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051be50` |
| **VA** | `0x0051be50`–`0x0051be85` exclusive (**53 B** / `0x35`) |
| **Canonical name** | `Map_FreeSubtree_Isnil15` |
| **Ghidra name** | `FUN_0051be50` |
| **Review date** | `2026-08-04` (WQ9F-F OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0051be50_Map_FreeSubtree_Isnil15.md` |
| **System** | STL / map-set (WQ-009 skill residual; free helper for Map_EraseRange_Isnil15) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` + `read_memory` (full body + pad) + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **subtree free** for the **isnil@+0x15** node family. Sole external caller is dualed **`Map_EraseRange_Isnil15`** (`0x0051d7c0`) full-clear path (`FUN_0051be50(head->parent)`).

Byte CF matches established free-subtree template (53 B, `ret 4`): recurse right @+8, delete node, walk left @+0 until isnil. Decompiler plate omits left walk (false-noreturn on `operator_delete`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `0x0051be50` (2026-08-04) |
| Bytes | 53 B; isnil `+0x15`; left load `mov esi,[esi]`; loop; `ret 4` |
| Caller external | `Map_EraseRange_Isnil15` / `0x0051d7c0` @ `0x0051d7dc` |
| Caller self | right-child recurse @ `0x0051be67` |
| Twin CF | `StdMap_FreeSubtree_Isnil15_Inferred` `0x004ba770` (different VA/callers) |
| Peer frees | `Map_FreeSubtree_Isnil29` `0x0051bbc0`; `Map_FreeSubtree_B` `0x0051be90`; isnil1d free `FUN_0051be10` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 53 B; `ret 4` (`C2 04 00`) | **Confirmed** | bytes / Ghidra inclusive end `0x0051be84` |
| Stack `node*`; ECX threaded unused | **Confirmed** | entry `push ebx/esi/edi`; `mov ebx,ecx` unused for loads |
| isnil@+0x15 | **Confirmed** | `cmp [edi+0x15],0` |
| Right recurse + left walk + delete | **Confirmed** | bytes restore left walk decomp dropped |
| Sole external caller Map_EraseRange_Isnil15 | **Confirmed** | xrefs |
| Name `Map_FreeSubtree_Isnil15` | **High** | free helper of sealed Map_EraseRange_Isnil15 |
| Collapse into StdMap free @ `004ba770` | **Rejected** | different VA / skill-neighborhood callers |
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
| Free-subtree for Map_EraseRange_Isnil15 | **Yes** |
| Twin isnil@+0x15 free pattern | **Yes** |
| Product/PDB English | **No** |
| Collapse into StdMap_FreeSubtree_Isnil15_Inferred | **No** — different VA / caller map |

**Decision:** promote **`Map_FreeSubtree_Isnil15`** (pairs with `Map_EraseRange_Isnil15`; keep distinct from `0x004ba770` / isnil29 frees).

---

## 6. Gaps

1. Exact map instantiation / value type English (delete-only).
2. Why a separate clone of `StdMap_FreeSubtree_Isnil15_Inferred` exists (compilation unit / map type).
3. Runtime / image diff / bit-exact.

**Verdict:** **accept-with-gaps**
