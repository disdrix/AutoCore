# Review B (skeptical / adversarial): `AuthClient_OnOpenedTcpConnection` @ `0x00729200`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00729200` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00729200_AuthClient_OnOpenedTcpConnection.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | UDP auth | **Falsified — SOCK_STREAM** |
| 2 | Reuses existing socket without check | **Falsified — +0x1c early fail** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Refuses double-open via +0x1c | High | Wrong → protocol/UI mismatch risk |
| Allocates SOCKET heap cell at +0x30 | High | Wrong → protocol/UI mismatch risk |
| TCP stream socket | High | Wrong → protocol/UI mismatch risk |
| Connect helper FUN_0046e2a0 | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
OnOpenedTcpConnection(auth, hostInfo): if not connected, create TCP socket, connect, mark open
```

---

## 4. Open questions

1. Address resolution / host string source
2. Success flag write to +0x1c details

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
