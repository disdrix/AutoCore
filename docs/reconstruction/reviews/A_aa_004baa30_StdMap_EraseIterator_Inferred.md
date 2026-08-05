# Review A (reconstruction fidelity): `aa_004baa30` StdMap_EraseIterator_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004baa30` |
| **VA** | `0x004baa30`–`0x004bace5` (694 B sealed) |
| **Canonical name** | `StdMap_EraseIterator_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004baa30` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W23-I) |
| **Counterpart** | `reviews/B_aa_004baa30_StdMap_EraseIterator_Inferred.md` |
| **System** | CRT / MSVC STL `_Tree` erase |
| **Verdict** | **accept-with-gaps** on CF / throw string / ABI / layout; product symbol + K/V **open** |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC **`map`/`set` single-iterator erase**: reject nil iterators with `"invalid map/set<T> iterator"`, unlink node from RB tree, rebalance if black, free node, decrement size.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_004baa30_FUN_004baa30.md` |
| Named record | `docs/reconstruction/functions/aa_004baa30_StdMap_EraseIterator_Inferred.md` |
| Raw | `docs/reconstruction/raw/aa_004baa30_FUN_004baa30.md` (+ W23-I live seal) |
| Annotated | `docs/reconstruction/raw/aa_004baa30_FUN_004baa30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_EraseIterator_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004baa30.cpp` |
| Live decompile | Ghidra `decompile_function` `0x004baa30` |
| Live body | `read_memory` entry + epilogue through `ret 8` |
| Throw string | `read_memory` `0x00a152f0` → `invalid map/set<T> iterator` |
| Callers | `FUN_004bacf0` only |
| Parent dual | `A_aa_004bacf0_StdMap_EraseRange_Inferred` |
| Sibling | `StdMap_FreeSubtree_Isnil15_Inferred` @ `0x004ba770` |

**Not performed:** Launcher, runtime golden, bit-exact, parent ledger edits, dual of rotation helpers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Nil gate `node+0x15` → throw string | **Confirmed** | decomp + string bytes |
| Body continues past `operator_delete` to `ret 8` | **Confirmed** | `read_memory` epilogue `C2 08 00` |
| Size-- at `map+8` when size > 0 | **Confirmed** | epilogue bytes after delete |
| ABI thiscall + 2 stack args + `ret 8` | **Confirmed** | call site + epilogue |
| Color at `+0x14` / black==1 fixup | **Confirmed** | decomp `(char)node[5]` / `+0x14` |
| Head `@map+4`, size `@map+8` | **Confirmed** | body + parent dual |
| Sole caller = range erase | **Confirmed** | analyze callers + call-site bytes |
| MSVC map/set erase identity | **High** | throw string + isnil layout |
| Product / PDB / K-V types | **Open** | structural `_Inferred` |
| Rotation helper product names | **Tentative** | residual FUN_* |
| Runtime / bit-exact | **Open** | deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| SEH register `LAB_009a16a2` | Yes |
| isnil throw path | Yes |
| Splice replacement + parent rewire | Yes |
| begin/rbegin head fixups | Yes |
| Black-node RB fixup loop + rotates | Yes |
| `operator_delete(node)` | Yes |
| size-- + out-it + `ret 8` | Yes (bytes; decomp truncated) |
| Not subtree free / not list unlink | Yes |

### Recovered CF (summary)

```c
void __thiscall StdMap_EraseIterator_Inferred(void *map, void *out_it, void *node)
{
    if (isnil(node)) throw "invalid map/set<T> iterator";
    // unlink + rebalance (see clean)
    operator_delete(node);
    if (map->size > 0) map->size--;
    // *out_it = …; ret 8
}
```

---

## 5. Assembly contract (from `read_memory`)

Key path:

```
cmp byte [node+0x15], 0 ; jz ok else throw
…
push node
call operator_delete
mov eax, [map+8]       ; ebp=this
add esp, 4
test eax, eax
… jbe skip
add eax, -1
mov [map+8], eax
…
ret 8
```

---

## 6. Gaps

1. Product / PDB symbol.  
2. Key/value types of NDSpecialFX map instantiation.  
3. Full dual of `FUN_00673070` / rotate helpers.  
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
