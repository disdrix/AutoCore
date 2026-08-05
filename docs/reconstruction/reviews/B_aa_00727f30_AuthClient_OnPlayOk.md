# Review B (skeptical / adversarial): `AuthClient_OnPlayOk` @ `0x00727f30`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727f30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00727f30_AuthClient_OnPlayOk.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Only one session id | **Falsified — two dwords + byte** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Name from string "PlayOk" | High | Wrong → protocol/UI mismatch risk |
| Shared auth inbound shell (scratch+log+callback) | High | Wrong → protocol/UI mismatch risk |
| unaff_EDI / param is AuthClient this | Medium | Wrong → protocol/UI mismatch risk |
| PlayOk triple payload (2 dwords + byte) | High | Wrong → protocol/UI mismatch risk |
| vt+0x28 | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
OnPlayOk: listener->vt+0x28(dw0,dw1,b2)
```

---

## 4. Open questions

1. Semantic of three fields — see Client_RecvLoginCallback_8 stores

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
