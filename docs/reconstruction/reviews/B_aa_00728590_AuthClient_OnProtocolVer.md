# Review B (skeptical / adversarial): `AuthClient_OnProtocolVer` @ `0x00728590`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00728590_AuthClient_OnProtocolVer.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Client ignores version | **Overstated — dedicated handler exists** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| String "ProtocolVer" | High | Wrong → protocol/UI mismatch risk |
| fastcall framing | Medium | Wrong → protocol/UI mismatch risk |
| Shared shell pattern | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
OnProtocolVer: log ProtocolVer; process negotiated version via auth client state
```

---

## 4. Open questions

1. Version compare constants
2. Accept/reject path details in full body

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
