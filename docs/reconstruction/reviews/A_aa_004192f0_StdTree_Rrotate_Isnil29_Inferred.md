# Review A (reconstruction fidelity): `aa_004192f0` StdTree_Rrotate_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004192f0` |
| **VA** | `0x004192f0` |
| **Body** | `0x004192f0`–`0x00419341` exclusive (**81 B**); pad `CC` |
| **Canonical name** | `StdTree_Rrotate_Isnil29_Inferred` |
| **Ghidra symbol** | `FUN_004192f0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_004192f0_StdTree_Rrotate_Isnil29_Inferred.md` |
| **System** | MSVC `std::_Tree` right-rotate (isnil@+0x29) |
| **Agent** | WQ9D-D OWN-ONLY dual |
| **Live tools** | `decompile_function` / `batch_decompile`, `read_memory`, `analyze_function_complete`, callers/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept** — CF/ABI/isnil/leaf/callers sealed; product demangle open only |

---

## 1. Purpose

Right-rotate about node `x` in a red-black tree whose nodes use **isnil at +0x29**. Promote `x->left` to `x`'s place; hang `x` as `y->right`. Leaf pointer surgery.

```c
// __thiscall RET 4
void StdTree_Rrotate_Isnil29_Inferred(Tree* this, Node* x);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004192f0_FUN_004192f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004192f0_FUN_004192f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Rrotate_Isnil29_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004192f0.cpp` |
| Live decompile | ≡ raw 2026-07-23 |
| Body hex | `read_memory` 81 B; isnil opcode `80 7E 29 00` |
| Twin Lrotate | `FUN_004192a0` (WQ9D-C) |
| Peer Val12 | `StdTree_Rrotate_Val12` @ `0x00418c10` (isnil@+0x19) |

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body exclusive end | `0x00419341` (`CC` after last `C2 04 00`) |
| Size | **81** B |
| Epilogue | `RET 4` ×3 paths |
| isnil test | `80 7E 29 00` on `y->right` |
| Tree head | `this+4` / root @ `header+4` |
| Leaf | 0 callees; 10 callers; 25 UNCONDITIONAL_CALL xrefs |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size / pad | **pass** |
| `RET 4` / thiscall | **pass** |
| Rrotate CF (y = left) | **pass** |
| Nil-child parent link | **pass** (isnil@+0x29) |
| Root / right / left reattach | **pass** (3 exits) |
| Shared (not skill-only) | **pass** (rebalance/erase maps) |
| Product demangle | **gap** (`_Inferred`) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **Confirmed** | live ≡ raw; RET 4 sealed |
| Right-rotate identity | **Confirmed** | classical algorithm; twin Lrotate |
| isnil@+0x29 | **Confirmed** | `80 7E 29 00` |
| Name `StdTree_Rrotate_Isnil29_Inferred` | **High role / Inferred English** | structural family naming |
| Runtime / differential | Open | Terminal false |

---

## 6. Gaps

1. Product / MSVC demangle for each map type using this rotate.  
2. Exact value payload size (color likely @+0x28) — not needed for rotate.  
3. Bit-exact / differential — open.

**Verdict:** **accept**
