# Review B (skeptical / adversarial): `Auth_i_d_fesh_2d_wnd_frame_btn_login_xml` @ `0x008cb9c0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008cb9c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008cb9c0_Auth_i_d_fesh_2d_wnd_frame_btn_login_xml.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on dialog class layout |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | This is the credentials login form (account/password) | **Falsified — fesh = shard/character select chrome; password lives in fet twin** |
| 2 | Sends PlayOk / LoginInsecure | **Falsified — UI build** |
| 3 | Server list authority | **Falsified — client widgets only** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| fesh XML set | High | Wrong skin pack |
| 0x488 child size | High | Alloc mismatch if wrong |
| Widget slot map 0x249.. | Medium | Broken dialog state |
| Version DAT sources | Tentative | Wrong version string |
| Clean is CF-preserving scaffold | High | Low for map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth/UI layout mistakes |

---

## 3. Cross-check against raw

```
BuildFeshLoginFrame(dialog):
  for each chrome/list control:
    child = new(0x488); FUN_007b5dd0; bind vtbl setup; load i_d_fesh_2d_*.xml
  sprintf version "v.%i.%i.%i.%i"
  sort + listboxes + shard scrollbar
```

---

## 4. Surviving contract for AutoCore

```
Auth_i_d_fesh_2d_wnd_frame_btn_login_xml(param_1):
  client shard/character select frame builder; no auth packets.
```

---

## 5. Open questions

1. Map btn_login click → which AuthClient Send* / Play path.
2. Document fesh vs fet screen flow (select after login vs entry).

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on dialog class layout — safe as behavioral map for AutoCore client auth/login UX; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
