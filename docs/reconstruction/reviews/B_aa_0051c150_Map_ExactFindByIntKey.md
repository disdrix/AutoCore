# Review B (skeptical / adversarial): `aa_0051c150` Map_ExactFindByIntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051c150` |
| **VA** | `0x0051c150` |
| **Canonical name** | `Map_ExactFindByIntKey` (structural only) |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0051c150_Map_ExactFindByIntKey.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is `std::map::lower_bound` (returns first ≥ key) | Post-check `cand.key <= key` rejects strict greater | **Falsified** as lower_bound API — **exact find** |
| 2 | Same helper as `Map_LowerBoundFindByIntKey` / `StdMap_LowerBound…` | Nil `+0x29` vs `+0x15` / `+0x1d`; key `+0x10` vs `[3]` | **Falsified** — distinct layout |
| 3 | Hash map / linear scan | Ordered tree walk left/right | **Falsified** |
| 4 | Mutates map / inserts on miss | Body only writes `*pOut`; no alloc/link writes | **Falsified** |
| 5 | Returns value TFID / builds binding | Returns **node pointer** (or end) only | **Falsified** value-return claim |
| 6 | Key is not skill id | Body is generic int*; callers pass skill id | **Attack fails** for body; skill-id is **caller** seal |
| 7 | Exclusive to LookupActiveCastBinding | Clear also calls (`0x0051a717`) | **Falsified** exclusive Lookup |
| 8 | Product name `Skill_CastBindingMap_Find` required | No string/RTTI; structural name sufficient | **Agree leave product** |
| 9 | Decompiler force would change CF | `force_decompile` ≡ first decompile | **Attack fails** — CF stable |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Exact-match semantics | **Confirmed** | Port as lower_bound → false hits on next key |
| Nil `+0x29` | **Confirmed** | Walk off tree / infinite |
| Key `+0x10` | **Confirmed** | Wrong slot compare |
| End = `*(map+4)` | **Confirmed** | Hit/miss inversion for Lookup/Clear |
| Leaf (no callees) | **Confirmed** | False dependency graph |
| Cast-binding **usage** | **High** | Not a product symbol |
| Map owner / header type | **Open** (sibling leave-FUN) | Wrong this for hooks |
| Full node after key | **Open** | Port value offsets from wrong dual |

---

## 3. Cross-check against raw / live / bytes

```
raw/clean scaffold CF ≡ live decompile ≡ force_decompile (2026-07-29).
read_memory @ 0x0051c150:
  cmp byte ptr [reg+0x29], 0   ; nil
  cmp [reg+0x10], key          ; key dword
  ret 8                        ; stdcall cleanup 8 → two stack formals + thiscall ECX
Xrefs: only 00518d07 (Lookup), 0051a717 (Clear).
```

### Lower_bound trap

Walk alone looks like lower_bound. **Do not stop there.** The exit gate:

```
if (cand != end && cand->key <= *pKey) hit; else end;
```

With walk invariant (candidate is first with key ≥ search), `<=` seals **equality**. Returning lower_bound without that gate is a **port bug**.

### Layout trap

Do **not** call `Map_LowerBoundFindByIntKey` or XP `StdMap_LowerBound` for this tree. Node size **0x30** / nil **+0x29** (map shell `FUN_00518c20` / factory `FUN_0058d9c0`) is a different family.

---

## 4. Surviving contract for AutoCore

```
Map_ExactFindByIntKey(mapHeader, &outNode, &intKey):
  // read-only exact find; int key @ node+0x10; nil @ node+0x29
  // end sentinel = *(mapHeader+4)
  // outNode = matching node OR end

Consumers (this image):
  Skill_LookupActiveCastBinding  — find then copy TFID16 from node+0x18..+0x24
  Skill_ClearCastBinding…        — find then erase/clear path (sibling unit)

AutoCore must NOT:
  - reuse +0x15 / +0x1d map find helpers on this tree
  - treat miss as "nearest key" (exact only)
  - invent insert/bind logic in this VA
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Exact find (not lower_bound API) | **Agree Confirmed** |
| Nil +0x29 / key +0x10 / L+0 / R+8 | **Agree Confirmed** |
| End = *(this+4) | **Agree Confirmed** |
| Two callers Lookup + Clear | **Agree Confirmed** |
| Structural name OK; product open | **Agree** |
| clean ≡ raw ≡ live ≡ force | **Agree** |
| accept-with-gaps | **Agree** |

Naming: reject promoting `Skill_*` product method without string/RTTI (same leave-FUN discipline as `FUN_00518c20`). Structural `Map_ExactFindByIntKey` is fine for reconstruction index.

---

## 6. Open questions

1. Optional: seal remaining 0x30 node bytes (color / pad) via factory `FUN_0058d9c0` dual — **not this VA's write**.
2. Runtime capture of find hit/miss on cast bind.
3. Bit-exact vs retail image.

**Verdict:** **accept-with-gaps** — agree with A; block lower_bound / cross-layout conflation and product over-name.
