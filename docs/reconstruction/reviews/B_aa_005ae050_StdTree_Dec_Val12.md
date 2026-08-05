# Review B (skeptical / adversarial): `aa_005ae050` StdTree_Dec_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae050` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-E) |
| **Counterpart** | `reviews/A_aa_005ae050_StdTree_Dec_Val12.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is “tree insert” / allocates nodes | **Falsified** — leaf; mutates iterator only; prior mis-role in a_0051d2f0 residual texts rejected |
| 2 | isnil at different offset (e.g. +0x15 / +0x29 peers) | **Falsified for this body** — all gates use `+0x19` |
| 3 | Returns predecessor in EAX | **Falsified** — void; mutates `*ECX` only; bare `C3` |
| 4 | Same body as Inc (`005ae0b0`) | **Falsified** — Inc walks right→leftmost; Dec walks left→rightmost; nil path differs |
| 5 | Product-specific to one map | **Falsified** — 7 callers across insert-or-find / hint-insert family |
| 6 | Can merge with other node sizes | **Do not** — Val12-only offsets |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Predecessor algorithm | **High** | Wrong insert neighbor / false unique hits |
| Val12 isnil@+0x19 | **High** | Corrupt wrong node family |
| ECX it** ABI | **High** | Clobber wrong register |
| Shared helper | **High** | Over-specialize port |
| Product demangle | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against insert consumer

W28-T `StdMap_InsertOrFind_Val12_UintKey` (`0x00573810`):

```
walk by uint key
if goLeft && not leftmost: Predecessor(parent)  // this unit @ 0x00573881
if parent.key < key: InsertAndRebalance
else equal: out {parent,0}
```

Confirms **generic Val12 _Dec / Prevnode**, not an insert helper.

---

## 4. Surviving contract for AutoCore

```
// Port as shared Val12 tree iterator--:
StdTree_Dec_Val12(&nodePtr);
// after: nodePtr is in-order predecessor
// isnil @ +0x19; left/parent/right @ 0/4/8
// end (nil header): *it = header.right (rightmost)
// do NOT use for isnil@+0x15 or isnil@+0x29 families
// do NOT confuse with always-insert (005ae4e0 / 00573510 / 0051c1c0)
```

---

## 5. Verdict

Adversarial pass **confirms** A; rejects insert mis-role → **accept**.
