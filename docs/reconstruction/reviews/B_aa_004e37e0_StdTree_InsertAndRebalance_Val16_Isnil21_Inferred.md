# Review B (skeptical / adversarial): `aa_004e37e0` StdTree_InsertAndRebalance_Val16_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e37e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-012 OWN-ONLY) |
| **Counterpart** | `reviews/A_aa_004e37e0_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md` |
| **Parent dual** | `0x005a27f0` `StdTree_Rrotate_Isnil21_Inferred` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + callers/xrefs + `read_memory` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This function walks keys / rejects duplicates | **Falsified** — no key compare; always inserts after buynode |
| 2 | Max size is `0x1ffffffd` (SkillElementTypeMap) or `0x15555553` (Val12) | **Falsified** — live uses **`0x0FFFFFFE`** (`81 7f 08 fe ff ff 0f`) |
| 3 | Node color at +0x14 / +0x18 (other families) | **Falsified** — color @ **+0x20**, isnil @ **+0x21** |
| 4 | Same address / same clone as peer `00407200` | **Falsified** — peer uses buynode `00408990`; this uses `004e2b80`; different VA/body |
| 5 | Legacy CVOGReaction_UpdateRepairStation* name is product insert role | **Narrow** — scaffold chain only; structural role is shared always-insert |
| 6 | `void` means no useful return | **Weakened** — `*out` written; parent consumes holder |
| 7 | Allocates without CRT new | **Falsified** — `FUN_004e2b80` → `operator_new(0x28)` |
| 8 | `RET 0x0C` like InsertHint shells | **Falsified** — **`RET 0x10`** (4 stack args) |
| 9 | isnil@+0x29 / node 0x30 family | **Falsified** — isnil@+0x21; node 0x28 |
| 10 | Runtime Confirmed | **Forbidden / Open** — no runtime this wave |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert (no key compare) | **High** | double-insert if parent mis-ported |
| ABI ret 0x10 thiscall | **High** | stack smash |
| Val16 / isnil21 layout | **High** | map corruption |
| Max size constant `0x0FFFFFFE` | **High** | wrong throw threshold |
| Sole-caller via `004e48b0` | **High** | wrong specialization / merge |
| Product English | Medium | naming only |
| Runtime | Open | matrix policy |

---

## 3. Cross-check against raw + bytes

```
SEH; if size >= 0x0FFFFFFE → throw "map/set<T> too long"
n = FUN_004e2b80(head, where, head, value, red=0); size++
link first | right | left (+ maybe leftmost/rightmost)
while parent red: recolor OR rotate (0050e9f0 L / 005a27f0 R + inlined L); root.black=1; *out=n; ret 0x10
```

Clean must **not** invent key compares, SkillElementTypeMap's `0x1ffffffd`, Val12's `0x15555553`, or color@+0x14/+0x18.

Do **not** merge with peer always-insert `0x00407200` (same CF family, different buynode clone / call graph).

---

## 4. Surviving contract for AutoCore

```csharp
// Always-insert + rebalance for Val16 / isnil@+0x21 tree nodes
// (clone used under FUN_004e48b0 insert-or-find; CVOGReaction repair-station path)
// Parent owns lower-bound / duplicate detection.
Node InsertAndRebalance(MapShell map, bool addLeft, Node where, in Val16 value)
{
    if (map.Size >= 0x0FFFFFFE) throw new InvalidOperationException("map/set<T> too long");
    var n = BuynodeVal16_004e2b80(map.Head, where, map.Head, value, color: 0);
    map.Size++;
    Link(map, where, addLeft, n);
    RbFixup(map, n); // L=0050e9f0, R=005a27f0, colors at +0x20
    return n;
}
```

Server ports must keep parent insert-or-find for uniqueness; this unit alone will duplicate keys.

---

## 5. Open questions

1. Exact demangled map type for sole caller `FUN_004e48b0`.  
2. Whether buynode null is UB.  
3. Whether residual buynode `004e2b80` is bit-identical to dualed `00408990` (layout yes; identity of helper open).

**Verdict:** **accept-with-gaps**
