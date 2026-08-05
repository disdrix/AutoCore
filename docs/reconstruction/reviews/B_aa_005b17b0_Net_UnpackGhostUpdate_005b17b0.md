# Review B (skeptical / adversarial): `aa_005b17b0` Net_UnpackGhostUpdate_005b17b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b17b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005b17b0_Net_UnpackGhostUpdate_005b17b0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Same function as 0060a820 | Falsified — different VA/body |
| 2 | Pack-only path | Falsified — readBits |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| VA sibling split | High | Wrong unpack entry |
| Type dispatch | Medium | Missed object class |

---

## 3. Cross-check against raw

```
UnpackGhostUpdate_005b17b0: BitStream read + GhostObject helpers.
Distinct from aa_0060a820.
```

---

## 4. Surviving contract for AutoCore

```
Base ghost unpack entry; keep separate from character pack/unpack VAs.
```

---

## 5. Open questions

1. Call-graph: who vtbl-dispatches here vs 0060a820.

**Verdict:** **accept-with-gaps**
