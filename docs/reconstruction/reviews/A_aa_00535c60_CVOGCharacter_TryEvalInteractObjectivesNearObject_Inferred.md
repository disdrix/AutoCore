# Review A (reconstruction fidelity): `aa_00535c60` CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00535c60` |
| **VA** | `0x00535c60`–`0x00535ec1` |
| **Canonical name (proposed)** | `CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred` |
| **Ghidra name** | `FUN_00535c60` |
| **Prior aliases** | `Named_VOG_DEBUG_STOP_00535c60` (misleading — hash assert string) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A) |
| **Counterpart** | `reviews/B_aa_00535c60_CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred.md` |
| **System tag** | `missions-progression` |
| **Agent** | W24-K OWN-ONLY |
| **Verdict** | **accept** on inventory/range/hash/type0xC/kind9 CF; **accept-with-gaps** on static callers + product enum names |

**Tools:** Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + `get_bulk_xrefs` + `audit_global`. No `disassemble_bytes`. No Launcher. No parent ledger edits.

---

## 1. Purpose

Character-side probe: given a **target object**, if it is **in inventory by COID** or **within 20.0f adjusted range**, search active hash for **type 0xC** evaluators that match the target; on first success fire **`EvaluatePendingObjectives` kind 9**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `FUN_00535c60` @ `0x00535c60` (≡ raw CF) |
| Image | prologue `0x00535c60`; range cmp ~`0x00535d70`; success `0x00535e80`; epilogue `0x00535eb0` |
| Float | `DAT_00aaa6e8` = `00 00 A0 41` = **20.0f** (Ghidra `g_nInferredThreatDefault`) |
| Xrefs to VA | **empty** (gap) |
| Sibling | `FUN_00535ed0` kind **10** use-object TFID path (contrast only; not owned) |
| Kind owner | `CVOGCharacter_EvaluatePendingObjectives` dual — lists this as kind **9** caller |
| FindByCoid | sealed residual `a_00571010.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body end before `0x00535ed0` | **High** | pad `CC` + sibling entry |
| `__thiscall` + `ret 4` | **High** | `C2 04 00` |
| ECX=character | **High** | `mov esi,ecx`; uses `+0x548` / `+0x250` |
| FindByCoid keys object `+0x160/164` | **High** | prologue + callee dual |
| Inventory hit skips range | **High** | `test eax; jnz skip` |
| Threshold 20.0f | **High** | comiss `[0x00aaa6e8]` + float bytes |
| Active hash `+0x548` lock `+0x1d` | **High** | HashError strings |
| Evaluator type `0xC` | **High** | `== 0xc` then match vcall |
| Kind **9** EvaluatePending | **High** | image `6A 09` + float cbid |
| p2 = `(float)*(clonebase+0x34)` | **High** | `object+0xa8` then `+0x34` |
| Live ≡ raw CF | **High** | re-decompile 2026-07-29 |
| Static callers | **Open** | no CODE/DATA xrefs recovered |
| Product name / type-0xC English | **Probable / Tentative** | interact family inferred |
| `g_nInferredThreatDefault` English | **Tentative** | value High; plate may be misnamed for this use |

---

## 4. Sealed control flow

```
TryEvalInteractNearObject(char, object) -> bool
  grid = *( *(char+0x250) + 0x2b0 )
  if !FindItemByCoid(grid, object.coidLo(+0x160), object.coidHi(+0x164)):
    dist = distance_or_nested(char, object)  // subtract radius +0x34 when simple path
    if dist > 20.0f: return false
  lock(char.activeHash+0x548)
  for each node in hash:
    def = node.value(+8)
    for eval in def.evaluators[+0x158,+0x15c):
      if eval.type(vtbl+0x50)==0xC and eval.match(vtbl+0x40, char, object):
        unlock
        EvaluatePendingObjectives(char, 9, (float)object.clonebase(+0xa8).id(+0x34), 0, 0)
        return true
  unlock; return false
```

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Inventory skip | **Yes** |
| Distance / nested branch | **Yes** |
| 20.0f early-out | **Yes** |
| Hash lock/traverse/unlock | **Yes** |
| Type 0xC + match | **Yes** |
| Kind 9 EvaluatePending | **Yes** |
| Invented static caller | **None claimed** |

---

## 6. Gaps / open questions

1. **Static / dynamic entry** — no xrefs; may be vtable/reaction registration not typed in Ghidra.
2. Product enum names for type `0xC` and context kind `9`.
3. Whether inventory path is “deliver item held” vs “world object also in bag”.
4. Alternate distance `FUN_0053e510` full contract (not owned).
5. Runtime / bit-diff.

**Verdict:** CF spine **accept High**. **accept-with-gaps** for callers + product naming.
