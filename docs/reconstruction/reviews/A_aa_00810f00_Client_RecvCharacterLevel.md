# Review A (reconstruction fidelity): `aa_00810f00` Client_RecvCharacterLevel

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810f00` |
| **VA** | `0x00810f00` |
| **Canonical name** | `Client_RecvCharacterLevel` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00810f00_Client_RecvCharacterLevel.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C CharacterLevel (plate opcode **0x2017**): resolve target by TFID (coidLo@+8, coidHi@+0xc, bGlobal@+0x10), apply absolute money/XP/level snapshot via vtable **+0xcc** (`CVOGCharacter_ApplyCharacterLevelPacket`), then refresh local level UI / HUD / mission windows when local char TFID matches.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00810f00_Client_RecvCharacterLevel.md` |
| Annotated | `docs/reconstruction/raw/aa_00810f00_Client_RecvCharacterLevel.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvCharacterLevel.cpp` |
| Function record | `docs/reconstruction/functions/aa_00810f00_Client_RecvCharacterLevel.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Lookup by TFID triple from packet framing` | **High** | coid @+8/+0xc, global @+0x10 |
| `Apply via vtbl+0xcc ApplyCharacterLevelPacket` | **High** | Call only if object found |
| `Local TFID match → Client_RefreshLocalCharacterLevelUi` | **High** | Compare packet vs char dual-base +0x164 |
| `HUD widget game+0x1034 refresh +0x448/+0x34c` | **High** | Visible-gate via +0x3d8 |
| `Always Client_RefreshOpenMissionUiWindows` | **High** | Unconditional after apply |
| `Secondary HUD game+0x10b0 → FUN_008a05a0` | **High** | Visible-gate |
| `Opcode 0x2017` | **Probable** | Plate/dispatch; body does not self-check |
| `Packet body in EAX (pPacketInEax)` | **Probable** | Dispatch residual |
| `Absolute snapshot (not additive)` | **High** | Contrast GiveCredits/GiveXP; Apply sibling |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| TFID lookup + conditional apply | **Yes** |
| Local UI match branch | **Yes** |
| Mission + secondary HUD refresh | **Yes** |
| No invented modernizations | **Yes** |

---

## 5. Gaps / open

1. Full snapshot field map owned by ApplyCharacterLevelPacket sibling.
2. pPacket formal often unused; EAX framing not portable C ABI.
3. FUN_008a05a0 exact UI identity open.
4. Runtime / differential open.

**Verdict:** **accept-with-gaps**
