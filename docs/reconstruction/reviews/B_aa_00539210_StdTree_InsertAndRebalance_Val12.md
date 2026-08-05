# Review B (skeptical / adversarial): `aa_00539210` StdTree_InsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539210` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W27-Q) |
| **Counterpart** | `reviews/A_aa_00539210_StdTree_InsertAndRebalance_Val12.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This function walks keys / rejects duplicates | **Falsified** — no key compare; always inserts after buynode |
| 2 | Max size is `0x1ffffffd` (SkillElementTypeMap) | **Falsified** — live uses **`0x15555553`** |
| 3 | Node color at +0x14 | **Falsified** — Val12 color @ **+0x18**, isnil @ **+0x19** |
| 4 | Same address as `Map_TreeInsertAndRebalance_Val12` | **Falsified** — peer at `0x0051c1c0`; this is multi-caller clone |
| 5 | Legacy CVOGCharacter_Appl name is product | **Narrow** — scaffold chain; structural insert is the role |
| 6 | `void` means no useful return | **Weakened** — `*outIt` written; callers consume holder |
| 7 | Allocates without CRT new | **Falsified** — `FUN_005ae220` → `operator_new(0x1c)` |
| 8 | Scaffold `undefined4` plate is dual-ready | **Falsified** — ABI + Val12 + throw seal required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert (no key compare) | **High** | double-insert if parent mis-ported |
| ABI ret 0x10 thiscall | **High** | stack smash |
| Val12 layout | **High** | map corruption |
| Max size constant | **High** | wrong throw threshold |
| Multi-caller shared | **High** | wrong specialization |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
SEH; if size > 0x15555553 → throw "map/set<T> too long"
n = Buynode_Val12(head, where, head, value, red=0); size++
link first | right | left (+ maybe leftmost/rightmost)
while parent red: recolor OR rotate (incl. inlined Lrotate); root.black=1; *outIt=n; ret 0x10
```

Clean must **not** invent key compares or SkillElementTypeMap's `0x1ffffffd` / color@+0x14.

---

## 4. Surviving contract for AutoCore

```csharp
// Always-insert + rebalance for Val12 tree nodes (shared multi-caller clone)
// Parent owns lower-bound / duplicate detection.
Node InsertAndRebalance(MapShell map, bool addLeft, Node where, in Val12 value)
{
    if (map.Size > 0x15555553) throw new InvalidOperationException("map/set<T> too long");
    var n = BuynodeVal12(map.Head, where, map.Head, value, color: 0);
    map.Size++;
    Link(map, where, addLeft, n);
    RbFixup(map, n);
    return n;
}
```

Server ports must keep parent insert-or-find for uniqueness; this unit alone will duplicate keys.

---

## 5. Open questions

1. Exact demangled map types for the two callers.  
2. Whether buynode null is UB.  
3. Product names of rotate helpers (sealed structural elsewhere).

**Verdict:** **accept-with-gaps**
