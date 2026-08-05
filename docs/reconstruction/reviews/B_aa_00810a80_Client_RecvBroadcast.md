# Review B (skeptical / adversarial): `Client_RecvBroadcast` @ `0x00810a80`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810a80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00810a80_Client_RecvBroadcast.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Only system chat | **Overstated — multi-type switch** |
| 2 | Fully typed packet struct | **Falsified — scaffold offsets only** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type discriminator at packet+4 | High | Wrong → protocol/UI mismatch risk |
| Large ~1K stack workspace | High | Wrong → protocol/UI mismatch risk |
| Optional global chat sink DAT_00d1d8c8 | Medium | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
Client_RecvBroadcast(pkt, clientCtx):
  if broadcast subsystem live: dispatch on type at +4; present message / side effects
```

---

## 4. Open questions

1. Full type enum table
2. Message string offsets in packet
3. Many FUN_* UI callees

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
