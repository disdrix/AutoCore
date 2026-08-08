# Review A (reconstruction fidelity): `aa_0051b5d0` StdTree_Min_Isnil29

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b5d0` |
| **VA** | `0x0051b5d0`–`0x0051b5ea` |
| **Canonical name (Ghidra)** | `FUN_0051b5d0` |
| **Proposed name** | `StdTree_Min_Isnil29` |
| **Review date** | `2026-08-04` (WQ9D-B OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0051b5d0_StdTree_Min_Isnil29.md` |
| **System** | MSVC `std::_Tree` / map (isnil @ +0x29) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf **leftmost non-nil** walk (`_Tree_min`) for red-black map/set nodes with **isnil @ +0x29**. Erase helpers recompute `head->left` after unlink.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `decompile_function` @ `0x0051b5d0` |
| Bytes | `read_memory` 64 B @ entry; body 27 B |
| Meta | `get_function_by_address` body `0051b5d0`–`0051b5ea` |
| Callers | `get_function_xrefs` / `analyze_function_complete` (5 CALL) |
| Erase peer | `Map_EraseNode` `aa_0051cb40` uses this for Lmost |
| Twin | `StdTree_Min_Val12` `aa_005adfa0` (isnil @ +0x19) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_0051b5d0` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, `disassemble_bytes`.

---

## 3. Signature

```c
StdTreeNode_Isnil29* StdTree_Min_Isnil29(StdTreeNode_Isnil29 *node);
// __cdecl; bare ret; EAX = leftmost non-nil
```

| Item | Evidence |
|---|---|
| Convention | bare `C3`; stack arg `[esp+4]` |
| isnil | `cmp byte ptr [ecx+0x29], 0` |
| Left link | `mov ecx, [eax]` / `mov ecx, [eax]` in loop |
| Return | EAX holds node when left isnil; Ghidra `void` **wrong** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load left; if isnil return node | Yes (bytes) |
| Else walk left while child !isnil | Yes |
| Return last non-nil | Yes (bytes; not decompiler void) |
| Leaf (no callees) | Yes |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Algorithm = `_Tree_min` | **High** | bytes + erase call sites |
| isnil @ +0x29 | **High** | `80 79 29 00` |
| EAX return | **High** | callers assign result |
| Map/set domain | **High** | `"invalid map/set<T> iterator"` erase |
| Product English / PDB | **Open** | role name sealed |

---

## 6. Gaps / open

1. Product/PDB symbol.  
2. Exact value payload width for this node class.  
3. Runtime / bit-exact.

**Verdict:** **accept** — CF/ABI/isnil High; decompiler void hazard documented and corrected in clean.
