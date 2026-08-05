# Review B (skeptical / adversarial): `aa_005ae0b0` StdTree_Inc_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae0b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-N) |
| **Counterpart** | `reviews/A_aa_005ae0b0_StdTree_Inc_Val12.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is skill-status-specific | **Falsified** — 9 callers across Val12 erase family; legacy seed is narrow |
| 2 | isnil at different offset (e.g. +0x15 / +0x29 peers) | **Falsified for this body** — all gates use `+0x19` |
| 3 | Returns successor in EAX | **Falsified** — void; mutates `*ECX` only; bare `C3` |
| 4 | Has callees / throws | **Falsified** — leaf; no throw path |
| 5 | Advances past nil end | **No** — if `*it` isnil, no-op (does not walk) |
| 6 | Can merge with other node sizes | **Do not** — Val12-only offsets; peers use different isnil |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Successor algorithm | **High** | Wrong erase iterator / skip nodes |
| Val12 isnil@+0x19 | **High** | Corrupt wrong node family |
| ECX it** ABI | **High** | Clobber wrong register |
| Shared helper | **High** | Over-specialize port |
| Product demangle | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against erase consumers

W27-T `StdTree_EraseNode_Val12` (`0x005ae990`):

```
if node.isnil: throw "invalid map/set<T> iterator"
succ = successor via FUN_005ae0b0   // this unit
unlink + RB fixup + delete + size--
*outIt = succ
```

Same pattern on peer erase clones (`004e4130`, `005399f0`, `00573250`). Confirms **generic Val12 _Inc**, not a skill-only helper.

---

## 4. Surviving contract for AutoCore

```
// Port as shared Val12 tree iterator++:
StdTree_Inc_Val12(&nodePtr);
// after: nodePtr is in-order successor (or nil header if was last)
// isnil @ +0x19; left/parent/right @ 0/4/8
// do NOT use for isnil@+0x15 or isnil@+0x29 families
```

---

## 5. Verdict

Adversarial pass **confirms** A; rejects skill-narrow naming → **accept**.
