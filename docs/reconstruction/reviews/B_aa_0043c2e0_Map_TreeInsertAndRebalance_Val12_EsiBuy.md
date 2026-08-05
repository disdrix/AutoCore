# Review B (skeptical / adversarial): `aa_0043c2e0` Map_TreeInsertAndRebalance_Val12_EsiBuy

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c2e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W29-D) |
| **Counterpart** | `reviews/A_aa_0043c2e0_Map_TreeInsertAndRebalance_Val12_EsiBuy.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This function walks keys / rejects duplicates | **Falsified** — no key compare; always inserts; parents own walk |
| 2 | Same body as `aa_0044a8c0` / merge as one symbol | **Falsified** — different VA (383 vs 390 B) and rotate targets (`00446b10`/`0040b910` vs `00573170`/`00418c10`) |
| 3 | Same as `Map_TreeInsertAndRebalance_Val12` `0x0051c1c0` | **Falsified** — buynode `0046c6c0` vs `005ae220`; EDI vs ECX this |
| 4 | Max size is `0x1ffffffd` (SkillElementTypeMap family) | **Falsified** — live uses **`0x15555553`** |
| 5 | Node color at +0x14 / non-Val12 | **Falsified** — color@**+0x18**, isnil@**+0x19**, buy `new(0x1c)` |
| 6 | Decompiler 3-arg signature is complete | **Falsified** — `ret 0x10` + `mov esi,[esp+…]` prove **value*** 4th arg |
| 7 | Uses stack-value buynode `0x005ae220` | **Falsified** — calls `FUN_0046c6c0` (ESI value) |
| 8 | Scaffold plate is sufficient dual | **Falsified** — ABI + Val12 + throw + ESI buy + rotate pair needed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert (no key compare) | **High** | double-insert if parent mis-ported |
| ABI ret 0x10 + EDI map | **High** | stack smash / wrong map |
| Val12 layout | **High** | map corruption |
| Max size constant | **High** | wrong throw threshold |
| ESI buynode identity | **High** | wrong node payload copy |
| Rotate pair vs twin | **High** | wrong helper if merged with 0044a8c0 |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
SEH; if size > 0x15555553 → throw "map/set<T> too long"
ESI = value*; n = FUN_0046c6c0(head, where, head, red=0); size++
link first | right | left (+ leftmost/rightmost)
while parent red: recolor OR rotate (00446b10 L / 0040b910 R); root.black=1; *outIt=n; ret 0x10
```

Clean must **not** invent key compares, use `0x005ae220` as this unit's buy, assume ECX this without EDI, use SkillElementTypeMap's `0x1ffffffd` / color@+0x14, or call the W26-Q rotate pair belonging to `aa_0044a8c0`.

---

## 4. Surviving contract for AutoCore

```csharp
// Always-insert + rebalance for Val12 tree (ESI-buy specialization, alt rotates)
// Parent owns lower-bound / duplicate detection.
Node InsertAndRebalance_EsiBuy(MapShell map, bool addLeft, Node where, in Val12 value)
{
    if (map.Size > 0x15555553) throw new InvalidOperationException("map/set<T> too long");
    var n = BuynodeVal12_Esi(map.Head, where, map.Head, value, color: 0); // FUN_0046c6c0
    map.Size++;
    Link(map, where, addLeft, n);
    RbFixup(map, n); // L=FUN_00446b10, R=FUN_0040b910
    return n; // *outIt
}
```

Do not merge this binary with `0x0044a8c0` or `0x0051c1c0` without proving identical call convention and rotate targets.

---

## 5. Open questions

1. Exact demangled MSVC map type for each of the six callers.  
2. Whether buynode null is undefined behavior in retail.  
3. Dual of rotate helpers `FUN_00446b10` / `FUN_0040b910` (not OWN).  
4. Whether any caller is the same domain as `FUN_0044a730` twin.

**Verdict:** **accept-with-gaps**
