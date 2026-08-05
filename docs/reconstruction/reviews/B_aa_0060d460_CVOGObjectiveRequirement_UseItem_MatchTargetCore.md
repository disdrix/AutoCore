# Review B (skeptical / adversarial): `aa_0060d460` UseItem_MatchTargetCore

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d460` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0060d460_CVOGObjectiveRequirement_UseItem_MatchTargetCore.md` |
| **Residual scratch** | `reviews/a_0060d460.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on CF + keys + grid ECX; **reject** “MatchTarget is only a trampoline with open criteria” |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Match criteria still unknown (2026-07-23 trampoline gap) | **Falsified** — this body is fully CF-mapped |
| 2 | Matches only by CBID | **Falsified** — COID path first when pair not all-ones |
| 3 | Matches only by COID | **Falsified** — CBID fallback `req+0x18` |
| 4 | FindItemByCoid compares CBID | **Falsified** — sibling dual; args are obj+0x160/164 |
| 5 | `+0x1D` is “must own item” always | **Partial** — flag **inverts**; 1 means must **not** find COID in cargo |
| 6 | Secondary `+0x2C` is same as primary identity CBID | **Falsified** — separate gate after identity; InitActive can give it independently |
| 7 | ECX into Find* is character | **Falsified** — ECX = `*(*(ch+0x250)+0x2B0)` grid |
| 8 | Three stack args / `ret 0xC` | **Falsified** — bytes `C2 08 00` |
| 9 | Mutates inventory | **Falsified** — predicate only |
| 10 | Ready for bit-exact seal | **Fail** — runtime/diff open |

---

## 2. Decisive dataflow (SEALED)

```
ECX = UseItemRequirement*
EBX = character*
EAX = target*

if !char || !target: return 0

identity =
  if (req.lo & req.hi) != 0xFFFFFFFF:
    target.coid == (req.lo, req.hi)
  else false
if !identity:
  if req.cbid(+0x18) == -1: return 0
  if *(target.clonebase+0x34) != req.cbid: return 0

grid = *(*(char+0x250)+0x2B0); if !grid: return 0
found = FindItemByCoid(grid, target.coid)
if (found==0) XOR (req+0x1D != 0): return 0   // presence vs absence

if req+0x2C != -1:
  if !FindItemByCbid(grid, req+0x2C, 0, 0): return 0

if req+0x54 >= 1:
  if req+0x54 != char.clonebase[+0xFC]: return 0

return 1
```

Live decompile body ≡ raw 2026-07-23. Bytes confirm grid loads, `call 00571010` / `005710c0`, invert, `ret 8`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Identity COID\|CBID OR | **High** | Wrong mission target accepts |
| Cargo FindByCoid + invert | **High** | Broken “use item you don’t have” / opposite |
| Grid at mgr+0x2B0 | **High** | Wrong inventory thiscall |
| Secondary CBID independent | **High** | Confuse give-item CBID with target |
| Field +0x54 product meaning | **Tentative** | Misnamed gate |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `+0x160` is CBID | Compatible? | **No** — CBID is clonebase+0x34; FindByCoid dual seals COID |
| All-ones COID means match any | Compatible? | **No** — skips COID path; needs CBID or fails |
| `+0x1D` always require owned | Compatible? | **No** — xor invert |
| FindByCbid uses skipGate=1 | Compatible? | **No** — pushes 0,0 (gate on, addQty 0) |
| `ret` stack size wrong | Compatible? | **No** — `C2 08 00` all exits |

---

## 5. Cross-unit relations

| Unit | Relation |
|------|----------|
| `aa_0060d7f0` MatchTarget | **Caller trampoline** — now sealed by this dual |
| `aa_0060d540` InitActive | Shares `+0x18` / `+0x2C` CBID fields (give) |
| `aa_00571010` FindItemByCoid | Cargo instance presence |
| `aa_005710c0` FindItemByCbid | Secondary CBID presence |
| `aa_00524520` / ForPick | Different objective match path (evaluator vtbl) — **do not conflate** |

---

## 6. Verdict

**accept-with-gaps.** Match criteria, inventory ECX, and invert flag are **sealed**. Runtime/diff/PDB and product name of `+0x54` remain open. Parent trampoline dual’s “helper open” gap is **closed by this unit**.
