# Review B (skeptical / adversarial): `Auth_Client_RequireAccountName` @ `0x008c92b0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c92b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008c92b0_Auth_Client_RequireAccountName.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on form layout |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Server validates account name here | **Falsified — client UI gate only** |
| 2 | Sends LoginInsecure when non-empty | **Falsified — returns 1 only** |
| 3 | Password also validated | **Falsified — account name only** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Empty-name toast string | High | Wrong UX |
| +0x590 widget slot | High | Gate reads wrong control |
| Return 0/1 contract | High | Login may proceed when it should not |
| unaff_ESI object | Medium | May be wrong dialog type |
| Clean is CF-preserving scaffold | High | Low for map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth/UI layout mistakes |

---

## 3. Cross-check against raw

```
RequireAccountName(form@ESI):
  w = form+0x590
  if w && vtbl(w)+0x1dc() && *text != 0: return 1
  toast("You need to specify your Account Name!")
  return 0
```

---

## 4. Surviving contract for AutoCore

```
Auth_Client_RequireAccountName():
  client login form validation; 1=ok 0=block; no auth wire.
```

---

## 5. Open questions

1. Confirm caller is login button handler and uses return as gate.
2. Seal whether password field has a sibling validator.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on form layout — safe as behavioral map for AutoCore client auth/login UX; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
