# Review B (skeptical / adversarial): `aa_00573510` StdTree_InsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W27-S) |
| **Counterpart** | `reviews/A_aa_00573510_StdTree_InsertAndRebalance_Val12.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This function walks keys / rejects duplicates | **Falsified** — parent `FUN_00573810` owns lower-bound; this always inserts |
| 2 | Max size is `0x1ffffffd` like SkillElementTypeMap | **Falsified** — live uses **`0x15555553`** |
| 3 | Node color at +0x14 | **Falsified** — Val12 color @ **+0x18**, isnil @ **+0x19** |
| 4 | Unique body; not related to `0x0051c1c0` | **Falsified** — same algorithm / buynode / max size class (separate VA) |
| 5 | Legacy Named_CalleeOf Client_ShowInventory is structural name | **Narrow** — xref seed only |
| 6 | Allocates via freelist | **Falsified** — `FUN_005ae220` → CRT `operator_new(0x1c)` |
| 7 | `void` only; no useful out | **Weakened** — `*outIt` written; caller reads inserted node |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert (no key compare) | **High** | double-insert bugs if parent mis-ported |
| ABI ret 0x10 thiscall | **High** | stack smash |
| Val12 layout | **High** | map corruption |
| Max size constant | **High** | wrong throw threshold |
| Sole live caller | **High** | missing specialization |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
SEH; if size > 0x15555553 → throw "map/set<T> too long"
n = Buynode_Val12(head, where, head, value, red=0); size++
link first | right | left (+ maybe leftmost/rightmost)
while parent red: recolor OR rotate; then root.black=1; *outIt=n; ret 0x10
```

Clean must **not** invent key compares or SkillElementTypeMap's `0x1ffffffd` / color@+0x14.

---

## 4. Surviving contract for AutoCore

```csharp
// Always-insert + rebalance for Val12 tree nodes
Node InsertAndRebalance(MapShell map, bool addLeft, Node where, in Val12 value)
{
    if (map.Size > 0x15555553) throw new InvalidOperationException("map/set<T> too long");
    var n = BuynodeVal12(map.Head, where, map.Head, value, color: 0);
    map.Size++;
    Link(map, where, addLeft, n);
    RbFixup(map, n);
    return n; // *outIt
}
```

Parent must own uniqueness (lower-bound / find). This unit alone will duplicate keys if misused.

---

## 5. Open questions

1. Exact demangled MSVC map type for `FUN_00573810`.  
2. Whether buynode null is UB in retail (no check).  
3. Runtime golden.

---

## 6. Verdict

**accept-with-gaps** — adversarial checks align with W25-G twin; residual gaps are product English and full clean RB loop expansion only.
