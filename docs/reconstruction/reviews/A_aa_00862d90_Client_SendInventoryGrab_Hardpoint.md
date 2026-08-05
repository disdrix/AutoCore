# Review A (reconstruction fidelity): `aa_00862d90` Client_SendInventoryGrab_Hardpoint

| Field | Value |
|---|---|
| **Stable ID** | `aa_00862d90` |
| **VA** | `0x00862d90` |
| **Canonical name** | `Client_SendInventoryGrab_Hardpoint` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00862d90_Client_SendInventoryGrab_Hardpoint.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

C2S InventoryGrab for equipped/hardpoint items: opcode **`0x2034` size `0x20`**, **`inventoryType = 2`** at `+0x18`, TFID from item `+0x160/+0x164/+0x168`. Sends via `Client_SendSectorPacket(&DAT_00d1a840, 0x20, buf)`. On success: item vtbl `+0x3bc(1)` and `+0x34c()`. Returns 1 on send path, 0 on gate fail. Caller: `Client_UI_InventoryItemClickDispatch` when store cursor empty.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw / clean | `raw/aa_00862d90_…`, `reconstructed-exact/Client_SendInventoryGrab_Hardpoint.cpp` |
| Function record | `functions/aa_00862d90_…` |
| Sibling | `Client_SendInventoryGrab_FromGrid` (type from window, not hardpoint) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Opcode 0x2034 size 0x20 | **High** | Explicit |
| Type byte = 2 hardpoint | **High** | Plate + body |
| `FUN_007fbbb0` first | **High** | Same helper as grid grab |
| Space/block via `FUN_004f6a80` → toast path | **High** CF |
| Send via `Client_SendSectorPacket` | **High** | Differs from FromGrid connection vcall |
| Post-send item vcalls | **High** CF; meaning Tentative |
| `unaff_EBX` = item/widget | **Probable** | Register input |
| Clean fully refined | **Tentative** | Scaffold body |

---

## 4. Control flow: clean ≡ raw

Helper → host gate → resolve → optional fail → pack 0x2034 type=2 → send → success vcalls. Match.

---

## 5. Gaps / open

Register this identity; full 0x20 layout vs FromGrid; runtime hardpoint grab.

**Verdict:** **accept-with-gaps.**
