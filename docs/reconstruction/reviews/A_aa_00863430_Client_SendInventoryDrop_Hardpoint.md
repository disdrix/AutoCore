# Review A (reconstruction fidelity): `aa_00863430` Client_SendInventoryDrop_Hardpoint

| Field | Value |
|---|---|
| **Stable ID** | `aa_00863430` |
| **VA** | `0x00863430` |
| **Canonical name** | `Client_SendInventoryDrop_Hardpoint` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00863430_Client_SendInventoryDrop_Hardpoint.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

C2S drop / equip-from-cursor onto a hardpoint. Requires `DAT_00d1b6d8`; cursor item via `DAT_00d1b1f8` vtbl `+0x3ac`. Gates: `FUN_00862860`, optional `FUN_004fabc0` → `FUN_00931db0`. Clone type **`0x0E` paint** path with town checks (`FUN_004ce5f0` / char `+0x6b4`). Builds/sends hardpoint drop packet; town-only toast *“This item can only be changed in town.”* on reject. Related UI: `Client_UI_InventoryItemClickDispatch` when cursor held.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw / clean | `raw/aa_00863430_…`, `reconstructed-exact/Client_SendInventoryDrop_Hardpoint.cpp` |
| Function record | `functions/aa_00863430_…` |
| Equip S2C | `Client_RecvInventoryEquip` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Host + cursor item gates | **High** | |
| `FUN_00862860` required | **High** CF |
| Paint type 0x0E special path | **High** CF; paint label Probable |
| Town-only reject string | **High** | User-visible |
| Builds equip/drop hardpoint packet | **Probable** | Plate; exact opcode in body needs raw seal |
| Clean fully refined | **Tentative** | Scaffold + stub preamble |

---

## 4. Control flow: clean ≡ raw

Gates and paint/town branches present in width-normalized body; full packet constants should be verified against raw when refining further.

---

## 5. Gaps / open

Exact opcode/size of hardpoint drop packet; relationship to DropToGrid type=2; runtime equip-from-cursor.

**Verdict:** **accept-with-gaps.**
