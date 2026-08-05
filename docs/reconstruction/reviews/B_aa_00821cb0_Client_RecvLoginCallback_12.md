# Review B (skeptical / adversarial): `Client_RecvLoginCallback_12` @ `0x00821cb0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821cb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00821cb0_Client_RecvLoginCallback_12.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Parses server rows here | **Falsified — only state+send** |
| 2 | phase values arbitrary | **Weak — 2 then 3 sequence is solid** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Login phase state at +0x4a (3=post server list) | High | Wrong → protocol/UI mismatch risk |
| Chains to SendAboutToPlay | High | Wrong → protocol/UI mismatch risk |
| Uses session ids from LoginOk at +0x50/+0x54 | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
RecvServerList(ui): phase=3; SendAboutToPlay(auth, sessA, sessB, flag)
```

---

## 4. Open questions

1. byte +0x74 meaning
2. Server list data not stored in this small function

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
