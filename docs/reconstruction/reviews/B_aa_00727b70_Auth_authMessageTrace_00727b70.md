# Review B (skeptical / adversarial): `Auth_authMessageTrace_00727b70` @ `0x00727b70`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727b70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00727b70_Auth_authMessageTrace_00727b70.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on param roles |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Authoritative auth wire codec | **Falsified — logging helper only** |
| 2 | Same function as send-side 0x00727c00 | **Falsified — parallel twin; Receiving vs Sending** |
| 3 | Bit-exact production port required for AutoCore auth | **Overstated — debug trace only** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Receiving format string | High | Wrong → mis-attributed log direction |
| Log line 0x12 in authMessageTrace.h | High | Source-map mismatch only |
| param semantic names | Tentative | Docs only |
| Clean is CF-preserving scaffold | High | Low for map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth/UI layout mistakes |

---

## 3. Cross-check against raw

```
authMessageTrace_Receive(name?, peer?, ctx?):
  s = FUN_0067b1b0(...);  // SSO string
  msg = format("Receiving: %s <- %s(%s)", param_1, param_2, s);
  vog_LogMessage(".../authMessageTrace.h", 0x12, 1, msg);
```

---

## 4. Surviving contract for AutoCore

```
Auth_authMessageTrace_00727b70(param_1, param_2):
  log inbound auth message; no wire effects.
```

---

## 5. Open questions

1. Name the two params from AuthClient On*/Send* call sites.
2. Confirm all AuthClient handlers call this vs send twin.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on param roles — safe as behavioral map for AutoCore client auth/login UX; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
