# Review B (skeptical / adversarial): `aa_005816a0` AnimHost_SelectBlendSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_005816a0` |
| **VA** | `0x005816a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005816a0_AnimHost_SelectBlendSlot.md` |
| **Evidence** | Body bytes + call sites; parent Respawn/Teleport duals |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Loads `.anm` files | **Falsified** | No strings; only weights on existing slots (`FUN_005828b0` loads) |
| 2 | Free function two-arg only | **Falsified** | thiscall + `ret 8` (mode, blend) |
| 3 | Additive blend without clearing others | **Falsified** | Clears all 19 first at weight 0 |
| 4 | Weight on select is caller blend alone | **Falsified** | Select uses **1.0f** as third arg; blend is second |
| 5 | Null target errors hard | **Falsified** | Returns 0 silently |
| 6 | Clean diverges | **Falsified** | ≡ image |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Clear-all then select-one CF | **High** | Overlapping anims in port |
| ABI ret 8 | **High** | Stack corruption |
| Return polarity | **Probable** | Phase machine off-by-bool |
| Product names | **Open** | — |

---

## 3. Surviving contract

```
SelectBlendSlot(host, mode, blend):
  for i in 0..18:
    if host.slots[i]: mixer.setWeight(slots[i], blend, 0.0)
  if host.slots[mode]:
    stampTime(); mixer.setWeight(slots[mode], blend, 1.0)
    return vfunc==0 ? 1 : 0
  return 0
```

**Verdict:** **accept-with-gaps**
