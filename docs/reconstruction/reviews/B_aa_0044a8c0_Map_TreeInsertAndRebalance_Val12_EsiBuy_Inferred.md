# Review B (skeptical / adversarial): `aa_0044a8c0` Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044a8c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W27-P) |
| **Counterpart** | `reviews/A_aa_0044a8c0_Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This function walks keys / rejects duplicates | **Falsified** — parent `FUN_0044a730` owns walk; this always inserts |
| 2 | Same body as `Map_TreeInsertAndRebalance_Val12` `0x0051c1c0` | **Falsified** — different VA, buynode (`0046c6c0` vs `005ae220`), this in **EDI** not ECX |
| 3 | Max size is `0x1ffffffd` (SkillElementTypeMap) | **Falsified** — live uses **`0x15555553`** |
| 4 | Node color at +0x14 / non-Val12 size | **Falsified** — color@**+0x18**, isnil@**+0x19**, `new(0x1c)` |
| 5 | Standard ECX thiscall only | **Falsified for this** — no `mov edi,ecx`; caller `mov edi,ebx` |
| 6 | Decompiler 3-arg signature is complete | **Falsified** — `ret 0x10` + `mov esi,[esp+…]` prove **value*** 4th arg |
| 7 | Uses `StdTree_Buynode_Val12` `0x005ae220` | **Falsified** — calls `FUN_0046c6c0` (ESI value convention) |
| 8 | Scaffold `undefined4` plate is sufficient dual | **Falsified** — ABI + Val12 + throw + ESI buy needed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert (no key compare) | **High** | double-insert if parent mis-ported |
| ABI ret 0x10 + EDI map | **High** | stack smash / wrong map |
| Val12 layout | **High** | map corruption |
| Max size constant | **High** | wrong throw threshold |
| ESI buynode identity | **High** | wrong node payload copy |
| Sole live caller | **High** | missing specialization |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
SEH; if size > 0x15555553 → throw "map/set<T> too long"
ESI = value*; n = FUN_0046c6c0(head, where, head, red=0); size++
link first | right | left (+ leftmost/rightmost)
while parent red: recolor OR rotate (ECX=map); root.black=1; *outIt=n; ret 0x10
```

Clean must **not** invent key compares, use `0x005ae220` as this unit's buy, assume ECX this without EDI, or SkillElementTypeMap's `0x1ffffffd` / color@+0x14.

Parent `FUN_0044a730` compares two uints at node `+0xc`/`+0x10` — third Val12 dword is payload, not part of key order in the walk.

---

## 4. Surviving contract for AutoCore

```csharp
// Always-insert + rebalance for Val12 tree (ESI-buy specialization)
// Parent owns lower-bound / duplicate detection (FUN_0044a730).
Node InsertAndRebalance_EsiBuy(MapShell map, bool addLeft, Node where, in Val12 value)
{
    if (map.Size > 0x15555553) throw new InvalidOperationException("map/set<T> too long");
    var n = BuynodeVal12_Esi(map.Head, where, map.Head, value, color: 0); // FUN_0046c6c0
    map.Size++;
    Link(map, where, addLeft, n);
    RbFixup(map, n); // L/R rotate Val12 helpers
    return n; // *outIt
}
```

Do not merge this binary with `0x0051c1c0` without proving identical call convention — EDI-this + ESI-value vs ECX-this + stack-value.

---

## 5. Open questions

1. Exact demangled MSVC map type (2×uint key + 1 dword mapped).  
2. Whether buynode null is undefined behavior in retail.  
3. Full dual of parent `FUN_0044a730` and of `FUN_0046c6c0` (not OWN).

**Verdict:** **accept-with-gaps**
