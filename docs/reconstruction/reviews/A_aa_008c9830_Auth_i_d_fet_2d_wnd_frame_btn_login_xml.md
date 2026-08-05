# Review A (reconstruction fidelity): `aa_008c9830` Auth_i_d_fet_2d_wnd_frame_btn_login_xml

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c9830` |
| **VA** | `0x008c9830` |
| **Canonical name** | `Auth_i_d_fet_2d_wnd_frame_btn_login_xml` |
| **System** | auth-login |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008c9830_Auth_i_d_fet_2d_wnd_frame_btn_login_xml.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_008c9830_*.md` (or FUN_ twin) |
| Clean | `docs/reconstruction/reconstructed-exact/Auth_i_d_fet_2d_wnd_frame_btn_login_xml.cpp` |
| String / plate evidence | From clean header + body |

---

## 2. Purpose (from unit)

Build account-entry (fet) login frame: GetKeyboardState + optional SendInput(2) key synthesize when local_104 bit0 set; operator_new(0x488)+FUN_007b5dd0 children; XML i_d_fet_2d_* (password edit, btn_login, options, create, remember, cinematic, quit); version sprintf. Slots ~param_1[0x155], [0x159..0x15e]. UI construct — not Auth wire codec.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| XML family i_d_fet_2d_* incl password edit | **High** | Literals |
| Buttons: login, options, create, remember, cinematic, quit | **High** | XML names |
| GetKeyboardState + conditional SendInput(2, ..., 0x1c) | **High** | Win32 calls |
| SendInput when (local_104 & 1) after keyboard state dump | **High** | bit test |
| Child alloc 0x488 + FUN_007b5dd0 | **High** | Same pattern as fesh |
| Version sprintf v.%i.%i.%i.%i / %i.%i.%i.%i | **High** | Strings |
| No AuthClient_SendLoginInsecure body here | **High** | construct only |
| Control flow preserved clean ≡ raw scaffold | **High** | No modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Keyboard probe/SendInput → zero DAT_00d1a980 → allocate frame children → load XML skins | **Yes** |
| Large decomp body preserved | **Yes** |

---

## 5. Gaps

1. Why SendInput(dx=0x14 / type=1) — focus/tab synthesize? open.
2. param_1 layout slots 0x155/0x159.. not fully named.
3. Remember-password persistence path not in this unit.
4. Address-suffixed twin is same VA.

**Verdict:** **accept-with-gaps**
