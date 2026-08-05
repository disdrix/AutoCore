# Review B (skeptical / adversarial): `AuthClient_OnLoginOk` @ `0x007280f0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007280f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007280f0_AuthClient_OnLoginOk.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Identical shell to all On* | **Partially true but unique null this check** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| String "LoginOk" | High | Wrong → protocol/UI mismatch risk |
| Extra null check unlike simple fail handlers | High | Wrong → protocol/UI mismatch risk |
| Shared shell pattern | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
OnLoginOk(this?, authClient/packet): log LoginOk; if valid listener notify success with session ids
```

---

## 4. Open questions

1. Exact callback slot and full payload field list
2. Relationship to Client_RecvLoginOk +0x50/+0x54

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
