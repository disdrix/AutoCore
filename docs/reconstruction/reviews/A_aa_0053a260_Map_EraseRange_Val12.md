# Review A (reconstruction fidelity): `aa_0053a260` Map_EraseRange_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053a260` |
| **VA** | `0x0053a260` |
| **Body** | `0x0053a260`–`0x0053a314` exclusive (**180** B / `0xB4`) |
| **Canonical name** | `Map_EraseRange_Val12` (inferred) |
| **Ghidra name** | `FUN_0053a260` |
| **Review date** | `2026-07-29` (W28-S OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0053a260_Map_EraseRange_Val12.md` |
| **System** | MSVC `_Tree` range erase (Val12) |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Erase `[first, last)` on a Val12 map/set shell: full-tree fast path (recursive free + head reset) or per-node erase via `Map_EraseNode_Val12` with in-order successor advance.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0053a260_FUN_0053a260.md` (+ W28-S append) |
| Annotated | `docs/reconstruction/raw/aa_0053a260_FUN_0053a260.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_EraseRange_Val12.cpp` |
| Twin | `reconstructed-exact/FUN_0053a260.cpp` |
| Function records | `functions/aa_0053a260_{FUN_0053a260,Map_EraseRange_Val12}.md` |
| Live decompile | ≡ raw CF 2026-07-29 |
| Single-node peer | `aa_005399f0` Map_EraseNode_Val12 (W27-R) |
| Full-clear parent | live `FUN_0053ba50` |
| Layout peer family | isnil@+0x19 Val12 (not +0x29 / +0x15) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | `53 8b 5c 24 10 56 8b 74 24 10 57 8b f9` — thiscall `mov edi,ecx` |
| Epilogue | `5f 89 30 5e 5b c2 0c 00` — `*outIt=cur`; **`ret 0x0c`** |
| Pad | `CC` from `0x0053a314` |
| Body size | **180** B |
| Sole CODE xref | `0x0053ba62` in `FUN_0053ba50` |
| Callees | `FUN_00538690` (isnil@+0x19 recursive free), `FUN_005399f0` |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw surface | **pass** |
| `ret 0x0c` / 3 stack args | **pass** |
| Full-range gate `first==*head && last==head` | **pass** |
| Partial loop + successor + single erase | **pass** |
| isnil@+0x19 | **pass** |
| head@+4 size@+8 | **pass** |
| Clean avoids bare `undefined4` | **pass** |

---

## 5. Surviving contract for AutoCore

```csharp
// Val12 map/set range erase
void EraseRange(MapShell map, out Node it, Node first, Node last)
{
    if (first == map.Begin && last == map.End) {
        FreeSubtree(map.Root);
        map.ResetEmpty();
        it = map.Begin;
        return;
    }
    while (first != last) {
        var succ = Successor(first); // isnil@+0x19
        EraseNode(map, out first, first); // Map_EraseNode_Val12
        first = succ;
    }
    it = first;
}
```

Do not use isnil@+0x29 or isnil@+0x15 node families for this clone.

---

## 6. Gaps (non-blocking)

1. Exact demangled map type for sole parent `FUN_0053ba50`.  
2. Product English.  
3. Runtime / bit-exact open.

**Verdict:** **accept**
