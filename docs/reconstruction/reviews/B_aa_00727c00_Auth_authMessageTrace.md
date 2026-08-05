# Review B (skeptical / adversarial): `Auth_authMessageTrace` @ `0x00727c00`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727c00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00727c00_Auth_authMessageTrace.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on param roles |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Changes wire layout of Auth packets | **Falsified — vog_LogMessage only** |
| 2 | Receive and send share one function | **Falsified — two VAs** |
| 3 | Required for AutoCore server auth authority | **Falsified — client debug** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Sending format string | High | Wrong direction in logs |
| Log line 0xd | High | Source-map only |
| Call-site completeness | Medium | May miss a Send* path in docs |
| Clean is CF-preserving scaffold | High | Low for map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth/UI layout mistakes |

---

## 3. Cross-check against raw

```
authMessageTrace_Send(name?, peer?, ctx?):
  msg = format("Sending: %s -> %s(%s)", ...);
  vog_LogMessage(".../authMessageTrace.h", 0xd, 1, msg);
```

---

## 4. Surviving contract for AutoCore

```
Auth_authMessageTrace(param_1, param_2):
  log outbound auth message; no wire effects.
```

---

## 5. Open questions

1. Map each AuthClient_Send* call site to this helper.
2. Confirm log level 1 filtering in vog_LogMessage.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on param roles — safe as behavioral map for AutoCore client auth/login UX; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
