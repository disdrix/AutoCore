# Review B (skeptical / adversarial): `aa_005e13b0` StdTree_InsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e13b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W37-K) |
| **Counterpart** | `reviews/A_aa_005e13b0_StdTree_InsertAndRebalance_Val12.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This function walks keys / rejects duplicates | **Falsified** — no key compare; always inserts after buynode |
| 2 | Max size is `0x1ffffffd` (Val8 / SkillElement family) | **Falsified** — live uses **`0x15555553`** |
| 3 | Node color at +0x14 / isnil +0x15 | **Falsified** — Val12 color @ **+0x18**, isnil @ **+0x19** |
| 4 | Same address as other InsertAndRebalance clones | **Falsified** — distinct VA; peer set listed in A |
| 5 | Mission product name is structural role | **Narrow** — scaffold chain; structural insert is the role |
| 6 | Buynode is ESI twin `0046c6c0` | **Falsified** — this clone uses stack **`005ae220`** |
| 7 | `void` means no useful output | **Weakened** — `*outIt` written; parent consumes holder |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert (no key compare) | **High** | double-insert if parent mis-ported |
| ABI ret 0x10 thiscall | **High** | stack smash |
| Val12 layout | **High** | map corruption |
| Max size constant | **High** | wrong throw threshold |
| Sole-caller coupling | **High** | wrong specialization if merged with multi-caller clone carelessly |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
SEH; if size > 0x15555553 → throw "map/set<T> too long"
n = Buynode_Val12(head, where, head, value, red=0); size++
link first | right | left (+ maybe leftmost/rightmost)
while parent red: recolor OR rotate (incl. inlined Lrotate); root.black=1; *outIt=n; ret 0x10
```

Clean must **not** invent key compares or Val8's `0x1ffffffd` / color@+0x14.

---

## 4. Surviving contract for AutoCore

```csharp
// Always-insert + rebalance for Val12 tree nodes
// Parent owns lower-bound / duplicate detection (FUN_005e18d0).
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

1. Exact demangled map type for sole consumer `FUN_005e18d0` / `FUN_005e0610`.  
2. Whether buynode null is UB.  
3. Whether all peer clones are bit-identical (length 490–491 B; treat as family, not one VA).
