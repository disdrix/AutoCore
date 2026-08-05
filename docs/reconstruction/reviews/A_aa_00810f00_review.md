# Review A (reconstruction fidelity): `aa_00810f00` Client_RecvCharacterLevel

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810f00` |
| **VA** | `0x00810f00` |
| **Canonical name** | `Client_RecvCharacterLevel` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00810f00_Client_RecvCharacterLevel.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvCharacterLevel.cpp` |
| Caller | `Client_PacketDispatch` case `0x2017` |
| Prior art | `docs/XP.md` CharacterLevel wire / login restore |

---

## 2. Signature & CF

| Stage | Raw | Clean | Match |
|---|---|---|---|
| `__fastcall (pGameClient, pPacket)` | Present | Present | **Yes** |
| TFID lookup via EAX framing +8/+0xc/+0x10 | Present | Present | **Yes** |
| Object vtable `+0xcc` apply | Present | Present | **Yes** |
| Local TFID match → RefreshLocalCharacterLevelUi | Present | Present | **Yes** |
| HUD `+0x1034` visible → vtable refresh | Present | Present | **Yes** |
| RefreshOpenMissionUiWindows | Present | Present | **Yes** |
| Secondary HUD `+0x10b0` → FUN_008a05a0 | Present | Present | **Yes** |

---

## 3. State mutations

| Target | Mutation |
|---|---|
| Target character (via Apply vfunc) | Absolute level/XP/currency/points snapshot |
| Local level UI / mission windows | Refresh only |

---

## 4. Gaps

1. Packet body arrives via `pPacketInEax` (EAX) — formal `pPacket` often unused; ABI incomplete.
2. Apply vfunc body (`+0xcc`) not expanded in this unit.
3. Secondary HUD `FUN_008a05a0` purpose not named.

**Verdict:** Snapshot-apply CF faithful. **accept-with-gaps.**
