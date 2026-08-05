# Review B (skeptical / adversarial): `aa_00438140` StdTree_InsertAndRebalance_Val8_Isnil15_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00438140` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W38-L) |
| **Counterpart** | `reviews/A_aa_00438140_StdTree_InsertAndRebalance_Val8_Isnil15_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This function rejects duplicate keys / walks compare | **Falsified** — no key compare; always inserts after buynode |
| 2 | Max size is Val12's `0x15555553` | **Falsified** — live **`0x1ffffffd`** (`81 7F 08 FE FF FF 1F`) |
| 3 | Node color at +0x18 / isnil +0x19 (Val12) | **Falsified** — color **@+0x14**, isnil **@+0x15**; buynode `0x18` |
| 4 | ECX-thiscall like Val12 `005e13b0` | **Falsified** — **EDI=map**; epilogue `RET 0x10` only |
| 5 | Rotates are W24-O sealed VAs `004e22d0`/`006753b0` | **Falsified** — this clone calls **`004219b0`/`0046f030`** (same family, different VAs) |
| 6 | Mission product name is structural role | **Narrow** — scaffold Named_CalleeOf; structural insert is the role |
| 7 | `void` means no useful output | **Weakened** — `*out` written; parents consume iterator |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert (no key compare) | **High** | double-insert if parent mis-ported |
| ABI EDI + ret 0x10 | **High** | stack smash / wrong map |
| Val8 layout + max size | **High** | map corruption |
| Shared multi-caller helper | **High** | wrong specialization if inlined per map type |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
SEH; if size > 0x1ffffffd → throw "map/set<T> too long"
n = Buynode_Val8(head, where, head, value, red=0); size++
link first | right | left (+ maybe leftmost/rightmost)
while parent red (color@+0x14): recolor OR rotate L/R isnil15 clones
root.black=1; *out=n; ADD ESP,0x50; RET 0x10
```

Clean must **not** invent key compares, Val12 max/color, or thiscall ECX map.

---

## 4. Surviving contract for AutoCore

```csharp
// Always-insert + rebalance for Val8 / isnil15 tree nodes
// Parent owns lower-bound / duplicate detection (e.g. FUN_00458510).
// Map in EDI-equivalent register, not ECX.
Node InsertAndRebalance(MapShell map, bool addLeft, Node where, in Val8 value)
{
    if (map.Size > 0x1ffffffd) throw new InvalidOperationException("map/set<T> too long");
    var n = BuynodeVal8(map.Head, where, map.Head, value, color: 0);
    map.Size++;
    Link(map, where, addLeft, n);
    RbFixup(map, n); // color@+0x14; rotates 004219b0 / 0046f030 family
    return n;
}
```

Server ports must keep parent insert-or-find for uniqueness; this unit alone will duplicate keys.

---

## 5. Open questions

1. Exact demangled map types for six multi-site callers.  
2. Whether buynode null is UB.  
3. Whether `004219b0`/`0046f030` are bit-identical to W24-O rotate pair (treat as family, dual separately if needed).
