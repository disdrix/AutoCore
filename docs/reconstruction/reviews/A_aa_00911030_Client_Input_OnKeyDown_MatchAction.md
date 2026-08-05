# Review A (reconstruction fidelity): `aa_00911030` Client_Input_OnKeyDown_MatchAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_00911030` |
| **VA** | `0x00911030` |
| **Canonical name** | `Client_Input_OnKeyDown_MatchAction` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00911030_Client_Input_OnKeyDown_MatchAction.md` |
| **System tag** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_Input_OnKeyDown_MatchAction.cpp` |
| Raw | `docs/reconstruction/raw/aa_00911030_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** WM key-down matcher. ESC (0x1b) special when client vtbl+0x3d8 allows UI cancel. Else normalize key FUN_00790020; sample Shift via GetAsyncKeyState(0x10/0xA0/0xA1) → DIK_LSHIFT 0x2A modifier. Scan action-slot table (~DAT_00d1bc18 / DAT_00d1bbee, stride 0x34) for DIK match; on hit set held(+4) and edge(+5), FUN_0093a5c0(1). Optional slot override FUN_007f6db0.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ESC path gated by vtbl+0x3d8 | High | Section 1 |
| Shift → 0x2a modifier | High | GetAsyncKeyState |
| Table scan stride 0x34 | High | Plate + loop |
| Match sets held +4 and edge +5 | High | Plate |
| FUN_0093a5c0(1) on match | High | Call |
| Optional FUN_007f6db0 override | Medium | Branch |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| ESC special else normalize+shift+scan | Yes |

---

## 4. Gaps

1. Full table base symbols and entry count.
2. FUN_0093a5c0 / FUN_00790020 names.
3. Repeat-key / lParam packing details.

**Verdict:** **accept-with-gaps**
