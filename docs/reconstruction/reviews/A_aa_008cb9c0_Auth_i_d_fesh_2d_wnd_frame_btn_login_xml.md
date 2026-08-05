# Review A (reconstruction fidelity): `aa_008cb9c0` Auth_i_d_fesh_2d_wnd_frame_btn_login_xml

| Field | Value |
|---|---|
| **Stable ID** | `aa_008cb9c0` |
| **VA** | `0x008cb9c0` |
| **Canonical name** | `Auth_i_d_fesh_2d_wnd_frame_btn_login_xml` |
| **System** | auth-login |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008cb9c0_Auth_i_d_fesh_2d_wnd_frame_btn_login_xml.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_008cb9c0_*.md` (or FUN_ twin) |
| Clean | `docs/reconstruction/reconstructed-exact/Auth_i_d_fesh_2d_wnd_frame_btn_login_xml.cpp` |
| String / plate evidence | From clean header + body |

---

## 2. Purpose (from unit)

Build character/shard-select (fesh) login-frame UI: operator_new(0x488)+FUN_007b5dd0 children, load i_d_fesh_2d_* XML (frame_inner, btn_back, logo, version, label_select, btn_login, btn_back, sort_name, sort_capacity, lb_name, lb_capacity, sb_shards). Version sprintf v.%i.%i.%i.%i from DAT_00b047e*. Slot stores ~param_1[0x249..0x254]. UI construct only — not auth wire.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| XML family i_d_fesh_2d_* | **High** | Multiple literals |
| Child widget size 0x488 + FUN_007b5dd0 | **High** | Repeated pattern |
| Version format v.%i.%i.%i.%i | **High** | sprintf |
| Shard list UI: sort name/capacity + listboxes + scrollbar | **High** | XML names |
| Login + back buttons present | **High** | btn_login / btn_back |
| No AuthClient Send* in body | **High** | construct/load only |
| Slots around +0x249..+0x254 (dword indices) | **Medium** | param_1 stores |
| Control flow preserved clean ≡ raw scaffold | **High** | No modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Init → allocate/bind children → load XML skins → version label → sort/list/scroll | **Yes** |
| Large scaffold body preserved from decomp | **Yes** |

---

## 5. Gaps

1. param_1 concrete type (dialog root) open.
2. Click handlers for login/back not in this unit (separate).
3. DAT_00b047e* version components source open.
4. Address-suffixed twin clean file is same VA — dual once.

**Verdict:** **accept-with-gaps**
