# Review B (skeptical / adversarial): `Client_RecvLoginCallback_8` @ `0x00821c30`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821c30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00821c30_Client_RecvLoginCallback_8.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Keeps auth TCP for sector | **Falsified — closes on PlayOk** |
| 2 | No state store | **Falsified** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stores two session dwords at +0x6c/+0x70 | High | Wrong → protocol/UI mismatch risk |
| Sets ready flag +0x4b | High | Wrong → protocol/UI mismatch risk |
| Closes auth TCP after PlayOk | High | Wrong → protocol/UI mismatch risk |
| Matches Auth OnPlayOk payload shape | Medium | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
RecvPlayOk(ui, a, b): save a/b; flag; advance; close auth TCP
```

---

## 4. Open questions

1. FUN_009332b0 state machine role
2. DAT_00d1a90c identity

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
