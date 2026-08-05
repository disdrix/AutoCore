# Review B (skeptical / adversarial): `aa_00418890` SkillDefMap_ExactFindByIntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418890` |
| **VA** | `0x00418890` |
| **Canonical name** | `SkillDefMap_ExactFindByIntKey` (INFERRED) |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00418890_SkillDefMap_ExactFindByIntKey.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Pure `lower_bound` (first ≥ key is success) | Post-check requires `cand.key <= *key` after lower-bound walk | **Falsified** as open lower_bound — **exact find** |
| 2 | Same helper as `Map_LowerBoundFindByIntKey` / `0x0050f940` | Nil **`+0x641`** vs `+0x15`/`+0x1d`/`+0x29` | **Falsified** — skill-def node family only |
| 3 | Hash / linear scan | Ordered tree via `00418c70` left/right | **Falsified** |
| 4 | Mutates map / inserts on miss | Body only stores `*pOut` | **Falsified** |
| 5 | Returns skill object / value blob | Returns **node** (or end); value is `node+0x10` for callers | **Falsified** value-return |
| 6 | Three stack formals as some Ghidra dumps | Bytes end **`ret 8`** | **Falsified** — **two** stack args |
| 7 | Only callee of status-effect path | 6 callers / 6 xrefs including materialize + install | **Falsified** exclusive-caller |
| 8 | Alias `Named_CalleeOf_Client_RecvSkillStatusEffect` is product role | One of several call sites | **Agree** alias is **xref evidence only** |
| 9 | Plate/parent “already cached” when miss | Equality to end = **map miss**, not cache hit | **Agree with parent dual** — miss semantics sealed |
| 10 | Product name required for seal | No string at this VA | **Agree leave structural** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Exact-match semantics | **Confirmed** | Port lower_bound bare → false hits |
| Nil `+0x641` | **Confirmed** | Walk off tree / hang |
| Key int `+0x0C` | **Confirmed** | Wrong width/slot |
| End = `*(map+4)` | **Confirmed** | Hit/miss inversion |
| `ret 8` ABI | **Confirmed** | Stack imbalance |
| Map = skill def table (`DAT_00b04734`) in main path | **High** | Wrong this on other maps |
| Payload at `node+0x10` size `0x630` | **High** (caller) | Truncated materialize |
| Full node schema | **Open** | Field ports wrong |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live decompile (2026-07-29).
read_memory @ 0x00418890:
  push ecx/esi/edi
  call FUN_00418c70
  cmp eax, [this+4]          ; end
  cmp *key, [node+0x0C]; jl miss
  ret 8                      ; C2 08 00
FUN_00418c70:
  root = *(*(this+4)+4)
  nil test: cmp byte [node+0x641], 0
  ret 4
xrefs: 6 (ResolveSkillTargets, RecvSkillStatusEffect, 0054a290 install, …)
```

### Lower_bound trap

`00418c70` alone is lower-bound-shaped. **Do not port without** the `cand≠end && key_node ≤ *key` gate in `00418890`.

### Layout trap

Never call `0x0050f940` / `0x004054f0` / `0x0051c150` on this map. Nil **`0x641`** is unique to skill-def nodes.

### Parent trap

`CVOGReaction_ResolveSkillTargets`: `*it == DAT_00b04738` → **null** means **miss**, not “already cached”.

---

## 4. Surviving contract for AutoCore

```
// Skill def map exact find
Node* Find(SkillDefMap* map, int skillId) {
  Node* end = map->head;                 // *(map+4), often DAT_00b04738
  Node* cand = LowerBoundWalk(map, skillId); // nil @ +0x641, key @ +0x0C
  if (cand != end && cand->key <= skillId) return cand; // equality under walk
  return end; // miss
}
// Callers: if (node == end) fail; else use (node+0x10) as 0x630-byte template
```

---

## 5. Open questions

1. STL / product type name for map + node.
2. Are all 6 callers the same map instance?
3. Node fields beyond key / children / nil / `+0x10` template.
4. Runtime capture.

**Verdict:** **accept-with-gaps**
