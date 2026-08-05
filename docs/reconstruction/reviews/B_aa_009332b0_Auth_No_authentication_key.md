# Review B (skeptical / adversarial): `Auth_No_authentication_key` @ `0x009332b0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_009332b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_009332b0_Auth_No_authentication_key.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on 0x6900 / state codes |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Generates cryptographic auth key | **Falsified — reports missing key** |
| 2 | Always shows the message | **Falsified — dual flag gate** |
| 3 | 0x6900 is sealed Auth opcode 0x6900 | **Overstated — second arg opaque without FUN_00807490** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Message string | High | Wrong UX |
| Flag gate +0x113/+0xa6 | High | Spam or silence wrong |
| State 2/3 stores | Medium | Wrong login state machine |
| FUN_00807490(…, 0x6900) | Tentative | Wrong follow-up action |
| Clean is CF-preserving scaffold | High | Low for map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth/UI layout mistakes |

---

## 3. Cross-check against raw

```
NoAuthenticationKey(obj@EAX):
  FUN_0092f360()
  obj+0xc0 = 2; obj+0xc4 = 3
  if !obj+0x113 && !obj+0xa6: FUN_007a4480(1, "No authentication key")
  FUN_00807490(obj+0x730, 0x6900)
```

---

## 4. Surviving contract for AutoCore

```
Auth_No_authentication_key():
  client missing-auth-key UX + state poke; seal FUN_00807490 arg before treating as opcode.
```

---

## 5. Open questions

1. Decompile FUN_00807490 and name 0x6900.
2. Identify when +0x113/+0xa6 suppress the toast.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on 0x6900 / state codes — safe as behavioral map for AutoCore client auth/login UX; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
