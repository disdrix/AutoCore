# Review B (skeptical / adversarial): `Client_RecvLoginCallback_10` @ `0x00821aa0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821aa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00821aa0_Client_RecvLoginCallback_10.md` |
| **Verdict** | **needs-more-evidence** (incomplete body / trampoline) |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Sealed complete reconstruction | **Falsified — jumptable not recovered** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| String RecvBlockedAccountMsg | High | Wrong → protocol/UI mismatch risk |
| Body may be incomplete (jumptable warning) | High | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
Callback_10: at least logs RecvBlockedAccountMsg; full body uncertain
```

---

## 4. Open questions

1. Possible missing switch/body due to decompiler jumptable failure
2. Re-decompile recommended

**Verdict:** **needs-more-evidence** (incomplete body / trampoline) — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
