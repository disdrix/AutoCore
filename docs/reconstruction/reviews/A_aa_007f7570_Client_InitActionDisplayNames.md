# Review A (reconstruction fidelity): `aa_007f7570` Client_InitActionDisplayNames

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f7570` |
| **VA** | `0x007f7570` |
| **Canonical name** | `Client_InitActionDisplayNames` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007f7570_Client_InitActionDisplayNames.md` |
| **System tag** | `input-drive-control` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_InitActionDisplayNames.cpp` |
| Raw | `docs/reconstruction/raw/aa_007f7570_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Pure string copies into ActionMap name fields (pActionMap via EAX). No DIK codes. Sections: system (Slash Command, Screenshot), inventory/mission/character/locker/medals/skills/research/memorization toggles, drive axes: +0x27d Accelerate, +0x2b1 Reverse, +0x2e5/0x319 Steer L/R, +0x34d/0x381 soft steer, +0x3b5 Brake. UI options labels only.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| No key codes written | High | String stores only |
| Drive name offsets +0x27d..+0x3b5 | High | Plate |
| Toggle Inventory/Mission/Profile/etc. strings | High | Body |
| pActionMap from register EAX | High | ABI note |
| Pairs ActionMap_Init caller | High | Call graph |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Sequential string field fills | Yes |

---

## 4. Gaps

1. Complete offset map for all action name slots.
2. String table vs inline copy variance in decomp.

**Verdict:** **accept**
