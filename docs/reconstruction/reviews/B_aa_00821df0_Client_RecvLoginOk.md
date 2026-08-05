# Review B (skeptical / adversarial): `Client_RecvLoginOk` @ `0x00821df0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821df0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00821df0_Client_RecvLoginOk.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Enters world immediately | **Falsified — only requests server list** |
| 2 | Does not need auth ptr at +4 | **Falsified — send gated on +4** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Phase 2 after login ok | High | Wrong → protocol/UI mismatch risk |
| Immediately requests server list | High | Wrong → protocol/UI mismatch risk |
| Session pair stored for later AboutToPlay | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
RecvLoginOk(ui, sessA, sessB): phase=2; store; SendServerListEx
```

---

## 4. Open questions

1. Session field names (account id / session key)

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
