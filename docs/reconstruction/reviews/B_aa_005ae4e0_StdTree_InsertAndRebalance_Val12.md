# Review B (skeptical / adversarial): `aa_005ae4e0` StdTree_InsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae4e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W27-T) |
| **Counterpart** | `reviews/A_aa_005ae4e0_StdTree_InsertAndRebalance_Val12.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This function walks keys / rejects duplicates | **Falsified** — parent `FUN_005aed20` owns walk; this always inserts |
| 2 | Max size is `0x1ffffffd` (SkillElementTypeMap family) | **Falsified** — live uses **`0x15555553`** |
| 3 | Node color lives at +0x14 (smaller node family) | **Falsified** — Val12 color @ **+0x18**, isnil @ **+0x19** |
| 4 | Same VA as category-cooldown insert helper | **Falsified** — peer is `0x0051c1c0`; this is `0x005ae4e0` |
| 5 | MissionStopLimit-specific logic | **Falsified** — generic `_Tree` insert; legacy name is xref chain only |
| 6 | Allocates via freelist / placement-new | **Falsified** — calls sealed `FUN_005ae220` → CRT `operator_new(0x1c)` |
| 7 | cdecl / plain ret | **Falsified** — thiscall + **`ret 0x10`** |
| 8 | Product English sealed | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert (no key compare) | **High** | Double-insert bugs if parent mis-ported |
| ABI ret 0x10 thiscall | **High** | stack smash |
| Val12 layout | **High** | map corruption |
| Max size constant | **High** | wrong throw threshold |
| Sole live caller | **High** | missing specialization |
| Distinct from 0051c1c0 | **High** | wrong merge of clones |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
SEH LAB_009a65a2; if size > 0x15555553 -> throw "map/set<T> too long"
n = Buynode_Val12(head, where, head, value, red=0); size++
link first | right | left (+ maybe leftmost/rightmost)
while parent red: recolor OR rotate; then root.black=1; *outIt=n; ret 0x10
```

Clean must **not** invent key compares, value ctors beyond buynode's 3-dword copy, or SkillElementTypeMap's `0x1ffffffd` / color@+0x14.

---

## 4. Surviving contract for AutoCore

```
// Always-insert + rebalance for Val12 tree nodes
// Parent owns lower-bound / duplicate detection.
Node InsertAndRebalance(MapShell map, bool addLeft, Node where, Val12 value)
{
    if (map.Size > 0x15555553) throw ...; // "map/set<T> too long"
    var n = BuynodeVal12(map.Head, where, map.Head, value, color: 0);
    map.Size++;
    Link(map, where, addLeft, n);
    RbFixup(map, n); // recolor/rotate; root black
    return n; // *outIt
}
```

Port uniqueness only via parent insert-or-find (`FUN_005aed20`); this unit alone will duplicate keys if misused.

---

## 5. Open questions

1. Exact demangled MSVC map type for sole caller map.
2. Whether buynode null is undefined behavior in retail (no check).
3. Runtime / bit-exact / differential.

---

## 6. Verdict

**accept-with-gaps** — structural role, ABI, Val12, throw, and peer-clone distinction sealed. Product demangle and runtime open.
