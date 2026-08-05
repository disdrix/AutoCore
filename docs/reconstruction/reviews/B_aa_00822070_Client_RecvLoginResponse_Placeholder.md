# Review B (skeptical / adversarial): `Client_RecvLoginResponse_Placeholder` @ `0x00822070`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00822070` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00822070_Client_RecvLoginResponse_Placeholder.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Empty stub despite name Placeholder | **Falsified — full UI fail path** |
| 2 | Only one error string | **Falsified** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Connection failure not credential failure | High | Wrong → protocol/UI mismatch risk |
| Double toast sequence | High | Wrong → protocol/UI mismatch risk |
| Name Placeholder understates — real handler | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
ConnectionFailed(code): log; optional UI reset; toast login+auth-connect errors
```

---

## 4. Open questions

1. DAT_00d1b1e4 flag meaning
2. FUN_007fc360 role

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
