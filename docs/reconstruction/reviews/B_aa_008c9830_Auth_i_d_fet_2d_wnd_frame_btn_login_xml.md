# Review B (skeptical / adversarial): `Auth_i_d_fet_2d_wnd_frame_btn_login_xml` @ `0x008c9830`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c9830` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008c9830_Auth_i_d_fet_2d_wnd_frame_btn_login_xml.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on SendInput intent |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Implements AuthServer login check | **Falsified — client UI builder** |
| 2 | Always synthesizes keys | **Falsified — gated on keyboard state bit** |
| 3 | fesh and fet are the same screen | **Falsified — different XML packs and controls** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| fet password + login/options/create/remember/quit set | High | Wrong entry UX |
| SendInput gate | Medium | Odd focus bug if misread |
| Slot indices | Medium | Dialog wiring |
| Clean is CF-preserving scaffold | High | Low for map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth/UI layout mistakes |

---

## 3. Cross-check against raw

```
BuildFetLoginFrame(dialog):
  GetKeyboardState; if keystate bit: SendInput(2 keys)
  DAT_00d1a980 = 0
  allocate/bind children (password, login, options, create, remember, cinematic, quit)
  load i_d_fet_2d_*.xml; version label
```

---

## 4. Surviving contract for AutoCore

```
Auth_i_d_fet_2d_wnd_frame_btn_login_xml(param_1):
  client account/password login frame builder; no auth packets in-body.
```

---

## 5. Open questions

1. Trace btn_login → RequireAccountName → SendLoginInsecure.
2. Explain SendInput purpose (CapsLock/NumLock/focus).

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on SendInput intent — safe as behavioral map for AutoCore client auth/login UX; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
