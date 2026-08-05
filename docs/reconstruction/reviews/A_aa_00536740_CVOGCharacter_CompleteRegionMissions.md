# Review A (reconstruction fidelity): `aa_00536740` CVOGCharacter_CompleteRegionMissions

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536740` |
| **VA** | `0x00536740` |
| **Body** | `0x00536740`–`0x0053691f` (**`ret 8`**) |
| **Canonical name** | `CVOGCharacter_CompleteRegionMissions` (Ghidra `FUN_00536740`; **Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00536740_CVOGCharacter_CompleteRegionMissions.md` |
| **System** | missions-progression |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Bulk award/complete cascade for a region (± pocket).** Character `this` in ECX; stack formals **region** and **pocket** (`0xFFFFFFFF` = any pocket):

1. Snapshot every mission def from the global region-missions hash (`FUN_0053fff0` / `Mission_EnsureRegionMissions` → `*wrapper`) into a temporary list while holding hash lock `+0x1d`.
2. Unlock; walk snapshot.
3. Keep defs where `def+0x128 == region` and (`pocket == -1` OR `def+0x12c == pocket`).
4. Keep when `u16 def+0x90 == u8 game+0x532` and (`u16 def+0x92 == 0xFFFF` OR `== u8 game+0x531`), with game blob via nested `this+4` chain + `0xac` + `+0x3c`.
5. Skip if completed hash `char+0x538` has matching key with **live** payload (`node+8 != 0`).
6. Else `CVOGCharacter_CheckMissionPrerequisites(this, missionId, 1, 1)` (return ignored).
7. Destroy temp list; **return 1**.

Sole caller: client debug chat `0x009544aa` formatting `"Completing region: %i, pocket: %i"` (`0x00a28a18`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | `decompile_function` @ `0x00536740` ≡ 2026-07-23 raw |
| Machine | `read_memory` 480 B @ `0x00536740` ends `c2 08 00` |
| Caller context | `get_assembly_context` @ `0x009544aa` |
| Toast string | `read_memory` @ `0x00a28a18` → `Completing region: %i, pocket: %i` |
| Prereq dual | `A_aa_00536540_CVOGCharacter_CheckMissionPrerequisites` (site 2) |
| Ensure wrapper | `Mission_EnsureRegionMissions` / `aa_0053fff0` |
| Raw / annotated / clean | `raw/aa_00536740_*`, `reconstructed-exact/CVOGCharacter_CompleteRegionMissions.cpp`, `FUN_00536740.cpp` |

**Not performed:** `disassemble_bytes`, Launcher, CE runtime, bit-exact image diff.

---

## 3. ABI / CF seals

| Claim | Evidence | Conf |
|---|---|---|
| `__thiscall` character ECX | `8b d9` | **High** |
| Two stack args; `ret 8` | `c2 08 00` | **High** |
| Always return 1 | `b0 01` | **High** |
| region @ `def+0x128` | `39 a8 28 01 00 00` | **High** |
| pocket @ `def+0x12c`, `-1` any | `83 ff ff` / `39 b8 2c 01 00 00` | **High** |
| race-ish `def+0x90` vs `game+0x532` | `66 39 88 90 00 00 00` + `0f b6 … 532` | **High** |
| class-ish `def+0x92` vs `game+0x531` | `66 8b 88 92…` / `0f b6 … 531` | **High** |
| completed skip `+0x538` | decompile bucket walk + live payload test | **High** |
| prereq `(1,1)` | `6a 01 6a 01 51 8b cb e8 4c fc ff ff` | **High** |
| Sole xref | `get_function_xrefs` → only `0x009544aa` | **High** |
| Live ≡ raw | byte-identical surface | **High** |

---

## 4. Contrast with SearchAutoMissions

| | This unit | `SearchAutoMissions` `0x00532b60` |
|---|---|---|
| Filter | region/pocket + race/class | AutoAssign `def+0xF8` |
| Award path | `CheckMissionPrerequisites(1,1)` | Requirements → GiveMission |
| Args | region, pocket | none |
| Role | debug bulk complete | normal auto-grant |

Do **not** merge identities.

---

## 5. Gaps / open

1. Product PDB symbol string (Inferred from debug toast only).
2. Authoritative English for `def+0x128`/`+0x12c` in Mission.Read / WAD (region/pocket Probable).
3. Precise product names for `game+0x531` / `+0x532`.
4. Full outer debug command dual (entry ~`0x00954400`, undefined as named fn).
5. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
