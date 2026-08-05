# Review B (skeptical / adversarial): `StdMap_EraseIterator_Inferred` / `FUN_004baa30` @ `0x004baa30`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004baa30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004baa30_StdMap_EraseIterator_Inferred.md` |
| **Verdict** | **accept-with-gaps** on STL erase CF/ABI; **needs-more-evidence** only on product symbol + K/V |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Intrusive list erase | **Falsified** — RB parent/left/right + color + isnil; rotations |
| 2 | Full tree free (no single erase) | **Falsified** — one node + rebalance; sibling `004ba770` is subtree free |
| 3 | Not STL | **Falsified** — throw `"invalid map/set<T> iterator"` |
| 4 | cdecl / plain ret | **Falsified** — epilogue **`ret 8`** |
| 5 | Decompiler body end is complete | **Falsified as complete** — false noreturn truncates; size-- exists in bytes |
| 6 | Erases host map object | **Falsified** — only `operator_delete(node)` |
| 7 | Same as range erase | **Distinct** — this is single-node; range loops this |
| 8 | Product name sealed | **Open** |
| 9 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Throw string identity | **Confirmed** | Mis-label as custom container |
| isnil `+0x15` | **Confirmed** | Crash vs throw contract wrong |
| `ret 8` thiscall | **Confirmed** | Stack imbalance in port |
| size-- epilogue | **Confirmed** | map size drift |
| RB rebalance present | **High** | Corruption on black erase |
| Rotation helper semantics | **Medium** | wrong dual if ported alone |
| K/V product types | **Open** | docs only |
| Product C++ name | **Open** | docs only |

---

## 3. Surviving contract for AutoCore

```
// __thiscall  ret 8
// map: head* @+4, size @+8
// node: left/parent/right, color@+0x14, isnil@+0x15
StdMap_EraseIterator(map, out_it, node):
  if isnil(node): throw "invalid map/set<T> iterator"
  unlink + RB fixup if black
  operator_delete(node)
  if map.size > 0: map.size--
  write out_it; ret 8

// NOT range erase. NOT subtree free. NOT list erase.
// Port: prefer std::map::erase or bit-exact tree; do not invent payload dtor unless typed.
```

---

## 4. Falsification notes

### 4.1 “Custom game map”

Throw string is CRT-standard MSVC `_Tree` message — seals STL family with sibling range erase dual.

### 4.2 Trusting Ghidra body end

`get_function_by_address` ends at `004bacb6` mid-post-delete path. Bytes prove `ret 8` at `004bace3`. Ports that omit size-- diverge from CRT.

### 4.3 List/FX-list confusion

FX teardown uses this **through** range erase on a map facade — the leaf is still tree erase, not `list::erase`.

### 4.4 Decompiler unreachable blocks

Many “Removing unreachable block” warnings around mid-function — do not invent extra live CF from those; main erase CF is live and matches raw.

---

## 5. Open questions

1. PDB / decorated name.  
2. Mapped type at each call-site map.  
3. Whether node payload needs non-trivial dtor (none visible beyond `operator_delete` of node shell).

**Verdict:** **accept-with-gaps**
