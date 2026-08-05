# Review B (skeptical / adversarial): `aa_0051c1c0` Map_TreeInsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051c1c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W25-G) |
| **Counterpart** | `reviews/A_aa_0051c1c0_Map_TreeInsertAndRebalance_Val12.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This function walks keys / rejects duplicates | **Falsified** — parent `Skill_CategoryCooldownMap_Insert` owns walk; this always inserts |
| 2 | Max size is `0x1ffffffd` like SkillElementTypeMap | **Falsified** — live uses **`0x15555553`** |
| 3 | Node color lives at +0x14 (IntPtr map style) | **Falsified** — Val12 color @ **+0x18**, isnil @ **+0x19** |
| 4 | Allocates via freelist / placement-new | **Falsified** — calls sealed `FUN_005ae220` → CRT `operator_new(0x1c)` |
| 5 | `void` only; no useful return | **Weakened** — decomp is void but epilogue leaves EAX=outIt*; caller `*return` reads new node |
| 6 | Domain-only name CategoryCooldown is the structural type | **Narrow** — sole caller yes, but CF is generic `_Tree` insert; structural name preferred |
| 7 | Same body as `SkillElementTypeMap_TreeInsertAndRebalance` | **Falsified** — different VA, max-size, node size, buynode, rotates |
| 8 | Scaffold `undefined4` plate is sufficient dual | **Falsified** — ABI + Val12 + throw constant needed seal |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert (no key compare) | **High** | Double-insert bugs if parent mis-ported |
| ABI ret 0x10 thiscall | **High** | stack smash |
| Val12 layout | **High** | map corruption |
| Max size constant | **High** | wrong throw threshold |
| Sole live caller | **High** | missing specialization |
| Rotate helper names | Low–Med | naming only |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
SEH; if size > 0x15555553 → throw "map/set<T> too long"
n = Buynode_Val12(head, where, head, value, red=0); size++
link first | right | left (+ maybe leftmost/rightmost)
while parent red: recolor OR rotate; then root.black=1; *outIt=n; ret 0x10
```

Clean must **not** invent key compares, value ctors beyond buynode's 3-dword copy, or SkillElementTypeMap's `0x1ffffffd` / color@+0x14.

---

## 4. Surviving contract for AutoCore

```csharp
// Always-insert + rebalance for Val12 tree nodes (category-cooldown map shell)
// Parent owns lower-bound / duplicate detection.
Node InsertAndRebalance(MapShell map, bool addLeft, Node where, in Val12 value)
{
    if (map.Size > 0x15555553) throw new InvalidOperationException("map/set<T> too long");
    var n = BuynodeVal12(map.Head, where, map.Head, value, color: 0);
    map.Size++;
    Link(map, where, addLeft, n);
    RbFixup(map, n); // recolor/rotate; root black
    return n; // *outIt
}
```

Server / AutoCore skill cooldown maps must use **parent insert-or-find** for uniqueness; this unit alone will duplicate keys if misused.

---

## 5. Open questions

1. Exact demangled MSVC map type for category-cooldown.  
2. Whether buynode null is undefined behavior in retail (no check).  
3. Product names of rotate helpers.

**Verdict:** **accept-with-gaps**
