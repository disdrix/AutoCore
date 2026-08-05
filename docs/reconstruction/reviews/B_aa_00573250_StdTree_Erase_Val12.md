# Review B (skeptical / adversarial): `aa_00573250` StdTree_Erase_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573250` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W27-S) |
| **Counterpart** | `reviews/A_aa_00573250_StdTree_Erase_Val12.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Function is void and ends at `operator_delete` | **Falsified** — bytes continue: size--, *outIt, `ret 8` |
| 2 | Same layout as `Map_EraseNode` (isnil@+0x29) | **Falsified** — isnil @ **+0x19**, color @ **+0x18** (Val12) |
| 3 | `ret 4` single stack arg | **Falsified** — `ret 8` (outIt + node) |
| 4 | Erase destroys value with custom dtor | **Unproven** — only `operator_delete` after unlink; Val12 POD copy in buynode |
| 5 | Domain-only name from `FUN_00572ab0` | **Narrow** — also used by range erase `FUN_00573700` |
| 6 | Decomp unreachable blocks mean dead code forever | **Weakened** — two-child erase path may be real; seal unlink via callees + MSVC pattern |
| 7 | Scaffold `undefined4` is enough | **Falsified** — ABI + post-delete tail required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| isnil throw + string | **High** | crash vs throw mismatch |
| ABI ret 8 thiscall | **High** | stack smash |
| Val12 layout | **High** | map corruption |
| size-- after delete | **High** | size drift |
| *outIt = successor | **High** | iterator UAF |
| Full two-child CF | Medium | rare erase bug |
| Product English | Low–Med | naming only |

---

## 3. Cross-check against raw + bytes

```
SEH; if node.isnil → throw "invalid map/set<T> iterator"
successor(outIt); unlink + maybe L/R rotate; operator_delete(node)
if size>0 size--; *outIt = succ; ret 8
```

Clean must **not** use isnil@+0x29, omit size--, or stop at delete.

---

## 4. Surviving contract for AutoCore

```csharp
// Val12 map/set erase (isnil@+0x19)
Node Erase(MapShell map, Node node)
{
    if (node.IsNil) throw new InvalidOperationException("invalid map/set<T> iterator");
    var succ = Successor(node);
    UnlinkAndRbFixup(map, node); // L/R rotate helpers shared with insert
    Free(node);
    if (map.Size > 0) map.Size--;
    return succ;
}
```

---

## 5. Open questions

1. Exact demangled MSVC map type for sole domain maps.  
2. Whether Ghidra-"unreachable" transplant is ever taken on live data.  
3. Runtime golden.

---

## 6. Verdict

**accept-with-gaps** — adversarial checks kill the false noreturn / wrong-layout stories; residual risk is two-child path fidelity and product names only.
