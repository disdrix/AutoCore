# Review B (skeptical / adversarial): `AuthClient_CloseTcpConnection` @ `0x007290e0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007290e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007290e0_AuthClient_CloseTcpConnection.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Only nulls pointer without closesocket | **Falsified — SOCKET API path** |
| 2 | Closes sector connection | **Falsified — AuthServer scope** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Socket pointer at +0x34 | High | Wrong → protocol/UI mismatch risk |
| Connected flag related to +0x1c | High | Wrong → protocol/UI mismatch risk |
| Called from RecvPlayOk path | Medium | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
CloseTcpConnection(auth): if open, log, close SOCKET at +0x34, clear connected state
```

---

## 4. Open questions

1. Full close sequence (shutdown vs closesocket order)
2. +0x30 vs +0x34 socket ownership

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
