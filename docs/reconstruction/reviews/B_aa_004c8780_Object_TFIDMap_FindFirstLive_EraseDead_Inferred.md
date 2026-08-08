# Review B (skeptical / adversarial): `aa_004c8780` Object_TFIDMap_FindFirstLive_EraseDead_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8780` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9F-C) |
| **Counterpart** | `reviews/A_aa_004c8780_Object_TFIDMap_FindFirstLive_EraseDead_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + assembly_context on erase site (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Pure STL erase helper (no domain) | **Falsified** — resolve + vtbl gates + target clear; returns object* |
| 2 | Same as range erase `004cbaa0` | **Falsified** — different VA/ABI/role; only *calls* single erase |
| 3 | Erase ECX is host object (not map) | **Falsified** — `LEA ECX,[EBP+0x154]` sealed |
| 4 | Always erases every node | **Falsified** — live path keeps nodes; only dead erased |
| 5 | Returns bool / void | **Falsified** — object* or 0; mov eax,ebx path |
| 6 | `vtbl+0x210` is max-speed driver leaf only | **Narrow** — shared slot; here used as non-null gate |
| 7 | Null TFID is zeros | **Falsified** — `DAT_009cb8c0` all-ones coid pair |
| 8 | Scaffold “unknown system” is final | **Narrow** — TFID map peer + isnil29 tree family |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Walk + scrub + first-live | **High** | wrong AI/target selection |
| Map +0x154 erase thiscall | **High** | erase wrong shell |
| Bare ret / frame | **High** | stack smash |
| Zero callers = dead code | Med | missing vtable wire |
| Product English | Low–Med | naming only |

---

## 3. Cross-check

```
for it in map[this+0x154]:
  obj = ResolveFromTFID(it.tfid)
  if !obj:
    if it.tfid == selected_target_tfid: clear via vtbl+0x258(nullTFID)
    erase(map, it)  // lea ecx, this+0x154; 004cb740
  else:
    if obj.v210(0): return obj
    if related=obj.v214() and ResolveVtbl1dc(related.tfid228): return obj
    // keep node; successor
return 0
```

Clean must **not** claim Confirmed product names, invent callers, or erase on live skip path.

---

## 4. Surviving contract for AutoCore

```csharp
// Find first live mapped object; scrub dead TFID entries
object? FindFirstLiveMapped(Host self)
{
    var map = self.TfidMap; // +0x154
    for (var it = map.Begin; it != map.End; ) {
        var obj = Resolve(it.Tfid);
        if (obj is null) {
            if (MatchesSelected(self, it.Tfid)) ClearSelectedNullTfid(self);
            var succ = Successor(it);
            EraseAndRebalance(map, it);
            it = succ;
            continue;
        }
        if (obj.V210(0) != null) return obj;
        if (RelatedResolves(obj)) return obj;
        it = Successor(it);
    }
    return null;
}
```

---

## 5. Open questions

1. Who calls this (vtable slot / dead)? Sibling `004c8610` is live from `FUN_00638ac0`.  
2. Exact selected-target clear API English (`vtbl+0x258`).  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
