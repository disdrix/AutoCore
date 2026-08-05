# Review B (skeptical / adversarial): `AuthClient_SendSCCCheck` @ `0x00728700`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00728700_AuthClient_SendSCCCheck.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Same logger as inbound | **Falsified — Send uses FUN_00727c00** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Outbound string "SCCCheck" | High | Wrong → protocol/UI mismatch risk |
| Uses send-scope logger 00727c00 not inbound 00727b70 | High | Wrong → protocol/UI mismatch risk |
| Outbound counterpart to OnSCCCheckReq | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
AuthClient_SendSCCCheck(...): scope log SCCCheck; enqueue outbound auth packet
```

---

## 4. Open questions

1. Packet opcode/body layout
2. param roles

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
