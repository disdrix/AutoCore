# Review A (reconstruction fidelity): `aa_00829b20` UI_MissionJournal_SelectMission_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829b20` |
| **VA** | `0x00829b20` |
| **Body** | `0x00829b20`–`0x00829ca5` (0x185 bytes) |
| **Canonical name** | `UI_MissionJournal_SelectMission_Inferred` |
| **Prior scaffold** | `FUN_00829b20` |
| **Review date** | `2026-07-29` (W24-J dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00829b20_UI_MissionJournal_SelectMission_Inferred.md` |
| **System** | client UI / missions-progression / mission journal |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Apply a **mission selection** onto the mission-journal UI: format title `"[level] name"`, invoke journal-ready check + list refresh helper, store selected mission id on the panel context.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00829b20` |
| Bytes | `read_memory` entry + ready-call site + epilog + string |
| Bounds | `get_function_by_address` body `00829b20`–`00829ca5` |
| Callees | IsMissionJournalReady, FUN_00829ac0, sprintf, string/color helpers |
| Callers | xrefs → `Client_UpdateMissionJournal` ×2 |
| Nested peer | sealed `CVOGCharacter_IsMissionJournalReady` @ `0x0052b3b0` |
| Raw / clean | `aa_00829b20_*`, named clean cpp |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Context EAX → ESI; mission EDI | **Confirmed** | entry bytes |
| Gate vtbl+0x3d8 + null mission | **Confirmed** | test al / test edi |
| Title `"[%d] %s"` | **Confirmed** | string @ `00a4abb4` |
| Level int16 @ mission+0x11c | **Confirmed** | `movsx` / decomp short cast |
| Name via +0x14c + string helpers | **High** | decomp + pushes |
| IsMissionJournalReady framing | **Confirmed** | rel32 `00829c5c`→`0052b3b0`; push EDI |
| selectedMissionId @ +0x500 | **Confirmed** | epilog store |
| Ready AL branched in this body | **Falsified** | unconditional FUN_00829ac0 when char live |
| Product English name | **Inferred** | role-sealed SelectMission |
| Color channel exact formula | **Open** | residual callees |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Gate virtual + mission null | Yes |
| Title sprintf + set text | Yes (string family) |
| Ready check + list helper | Yes (rel32) |
| Chrome color copy | Yes (order) |
| Store selected id | Yes |
| Color math details | Partial (residuals) |

---

## 5. Gaps / open

1. Product plate spelling of the method.
2. Product field names for mission +0x11c / +0x14c.
3. Whether `FUN_00829ac0` consumes ready AL (out of ownership).
4. Full color dual (`FUN_0092d580` / `FUN_006a3db0`).
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/string/ready framing sealed; color + list-helper contract residual.
