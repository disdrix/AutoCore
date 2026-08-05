# Review B (skeptical / adversarial): `AuthClient_OnAccountKicked` @ `0x007284b0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007284b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007284b0_AuthClient_OnAccountKicked.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Disconnects socket inside | **Needs-more-evidence — may only notify** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Name from string "AccountKicked" | High | Wrong → protocol/UI mismatch risk |
| Shared auth inbound shell (scratch+log+callback) | High | Wrong → protocol/UI mismatch risk |
| unaff_EDI / param is AuthClient this | Medium | Wrong → protocol/UI mismatch risk |
| String AccountKicked | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
OnAccountKicked: log; notify listener
```

---

## 4. Open questions

1. Exact vtable offset in scaffold
2. Whether disconnect is in callee

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
