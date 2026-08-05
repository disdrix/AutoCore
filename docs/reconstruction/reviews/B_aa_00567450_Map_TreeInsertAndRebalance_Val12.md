# Review B (skeptical / adversarial): `aa_00567450` Map_TreeInsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00567450` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W27-R) |
| **Counterpart** | `reviews/A_aa_00567450_Map_TreeInsertAndRebalance_Val12.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This function walks keys / rejects duplicates | **Falsified** — parent `FUN_00567860` owns lower_bound; this always inserts |
| 2 | Max size is `0x1ffffffd` (SkillElementTypeMap) | **Falsified** — live uses **`0x15555553`** |
| 3 | Same VA as category-cooldown insert helper | **Falsified** — twin is **`0x0051c1c0`**; this is **`0x00567450`** |
| 4 | Allocates freelist / placement-new | **Falsified** — `FUN_005ae220` → `operator_new(0x1c)` |
| 5 | Color at +0x14 | **Falsified** — Val12 **+0x18** / isnil **+0x19** |
| 6 | `ret 4` or no stack cleanup | **Falsified** — **`ret 0x10`** |
| 7 | Many live callers | **Falsified** — **sole** `FUN_00567860` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert (no key compare) | **High** | double-insert if parent mis-ported |
| ABI ret 0x10 thiscall | **High** | stack smash |
| Val12 layout | **High** | map corruption |
| Max size constant | **High** | wrong throw threshold |
| Twin distinct from 0051c1c0 | **High** | merge bugs |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
SEH; if size > 0x15555553 → throw "map/set<T> too long"
n = Buynode_Val12(head, where, head, value, red=0); size++
link first | right | left (+ maybe leftmost/rightmost)
while parent red: recolor OR rotate; then root.black=1; *outIt=n; ret 0x10
```

Clean must **not** invent key compares, use SkillElementTypeMap max size, or merge with `0x0051c1c0`.

---

## 4. Surviving contract for AutoCore

```csharp
// Always-insert + rebalance for Val12 tree nodes
// Parent owns lower-bound / duplicate detection.
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

Uniqueness is **not** this unit's job — parent `FUN_00567860` compares int keys at `node+0x0C`.

---

## 5. Open questions

1. Exact demangled map type for the `FUN_00567860` owner.  
2. Buynode null OOM path.  
3. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps**
