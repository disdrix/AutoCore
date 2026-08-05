# Review B (skeptical / adversarial): `aa_005ae990` StdTree_EraseNode_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae990` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W27-T) |
| **Counterpart** | `reviews/A_aa_005ae990_StdTree_EraseNode_Val12.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Intrusive list erase | **Falsified** — RB parent/left/right + color@+0x18 + isnil@+0x19; rotates |
| 2 | Full tree free (no single erase) | **Falsified** — one node + rebalance; range erase is parent `FUN_005af3a0` |
| 3 | Not STL | **Falsified** — throw `"invalid map/set<T> iterator"` |
| 4 | Decompiler body end is complete | **Falsified as complete** — false noreturn truncates; size-- exists in bytes |
| 5 | Same node family as Map_EraseNode (isnil@+0x29) | **Falsified** — Val12 isnil@**+0x19** |
| 6 | Same as insert helper | **Distinct** — erase vs insert; different ABI ret 8 vs ret 0x10 |
| 7 | cdecl / plain ret | **Falsified** — **`ret 8`** |
| 8 | Product name sealed | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Throw string identity | **Confirmed** | Mis-label as custom container |
| isnil `+0x19` | **Confirmed** | Crash vs throw contract wrong |
| `ret 8` thiscall | **Confirmed** | Stack imbalance in port |
| size-- epilogue | **Confirmed** | map size drift |
| RB rebalance present | **High** | Corruption on black erase |
| Rotation helper semantics | **High** (sealed duals) | wrong dual if ported alone |
| Product C++ name | **Open** | docs only |

---

## 3. Surviving contract for AutoCore

```
// __thiscall  ret 8
// map: head* @+4, size @+8
// node: left/parent/right, color@+0x18, isnil@+0x19  (Val12 / 0x1c)
StdTree_EraseNode_Val12(map, out_it, node):
  if isnil(node): throw "invalid map/set<T> iterator"
  succ = successor(node)
  unlink + RB fixup if black
  operator_delete(node)
  if map.size > 0: map.size--
  *out_it = succ; ret 8

// NOT range erase. NOT subtree free. NOT list erase.
// NOT Map_EraseNode (different isnil offset).
// Port: prefer std::map::erase or bit-exact tree.
```

---

## 4. Falsification notes

### 4.1 Trusting Ghidra body end

Ghidra body ends at `0x005aec16` mid/post-delete. Live `read_memory` through `0x005aec44` seals size--, *outIt, and `ret 8`.

### 4.2 Merging with Map_EraseNode

`Map_EraseNode` (`0x0051cb40`) uses isnil@+0x29 / color@+0x28. This unit is Val12 isnil@+0x19 — same algorithm family, different instantiation.

---

## 5. Open questions

1. Product/PDB demangle for map type.
2. Whether payload needs non-trivial dtor (buynode is POD 3-dword copy — erase only operator_delete).
3. Runtime / bit-exact / differential.

---

## 6. Verdict

**accept-with-gaps** — STL erase CF/ABI/size-- sealed for Val12. Product symbol open.
