# Review B (skeptical / adversarial): `AuthClient_OnServerListEx` @ `0x00727d70`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727d70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00727d70_AuthClient_OnServerListEx.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Parses server list fully here | **Falsified — forwards blob** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Name from string "ServerListEx" | High | Wrong → protocol/UI mismatch risk |
| Shared auth inbound shell (scratch+log+callback) | High | Wrong → protocol/UI mismatch risk |
| unaff_EDI / param is AuthClient this | Medium | Wrong → protocol/UI mismatch risk |
| Payload starts packet+0x10 | High | Wrong → protocol/UI mismatch risk |
| Listener vtable slot +0x1c | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
OnServerListEx: if listener: listener->vt+0x1c(packet+0x10)
```

---

## 4. Open questions

1. Server list payload layout
2. Listener concrete type

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
