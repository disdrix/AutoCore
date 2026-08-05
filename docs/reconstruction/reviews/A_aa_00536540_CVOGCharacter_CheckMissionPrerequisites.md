# Review A (reconstruction fidelity): `aa_00536540` CVOGCharacter_CheckMissionPrerequisites

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536540` |
| **VA** | `0x00536540` |
| **Canonical name** | `CVOGCharacter_CheckMissionPrerequisites` |
| **Review date** | `2026-07-29` (dual residual edges strengthen) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00536540_CVOGCharacter_CheckMissionPrerequisites.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present — residual edges sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **character-side mission award bootstrap** (`__thiscall` on character):

1. Walk **active** mission hash at `char+0x540` for `missionId`.
2. If live-active (`node+8 != 0`): optional `CompleteMissionObjectives(id, 1)` when `autoComplete`, else return `0`.
3. Else: lookup mission def (`FUN_0053fff0` + `CNDHash_LookupByKey`).
4. When `checkLevel != 0`, require race (`def+0x90` == char race byte) and faction (`def+0x92` == `0xFFFF` or char faction).
5. When `def+0x124 == 0` (**`RequirementsNegative`**), **recursively** call self on up to 4 prereq IDs at `def+0x9c` with `autoComplete=1` (return discarded).
6. If char level (vtbl `+0x27c`) `<` min level (`def+0x94`): award XP via `Experience_XpToReachRelativeLevel` + `CVOGReaction_AddExperience(..., PacketOrNonKill)`.
7. Prep blob → `FUN_0052c700` → `CVOGReaction_GiveMission` → optional `CompleteMissionObjectives`.

Returns `1` on award / auto-complete success, `0` on reject. **Not a pure predicate** — side-effects grant, XP, and complete.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00536540_CVOGCharacter_CheckMissionPrerequisites.md` |
| Annotated | `docs/reconstruction/raw/aa_00536540_CVOGCharacter_CheckMissionPrerequisites.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_CheckMissionPrerequisites.cpp` |
| Function record | `docs/reconstruction/functions/aa_00536540_CVOGCharacter_CheckMissionPrerequisites.md` |
| Fresh decompile | Ghidra MCP `decompile_function` @ `0x00536540` (2026-07-29) — CF ≡ 2026-07-23 |
| Xrefs / asm context | Ghidra `get_xrefs_to` + `get_assembly_context` @ all 4 call sites |
| Caller decompiles | `FUN_00536740` @ `0x00536740`; `FUN_0052c700`; `FUN_0053fff0` |
| Sibling dual | `CheckMissionRequirements` `aa_005462b0` (RequirementsOred/Negative sealed) |
| WAD names | `src/AutoCore.Game/Mission/Mission.cs` (`Mission.Read`) |
| Offset cross-ref | `docs/missionState.md` §2.1–2.2 |
| System map | `docs/reconstruction/systems/missions-progression.md` |

**Not performed:** `disassemble_bytes`, Launcher, live award/XP matrix.

---

## 3. Evidence table (body-backed only)

| Claim | Width / shape | Raw evidence | Confidence |
|---|---|---|---|
| `__thiscall(char*, u32 id, char auto, char check) → char 0/1` | sig | Raw plate + returns `'\x01'`/`'\0'` | **High** |
| Active hash `this+0x540` | hash | Bucket walk first in body | **High** |
| Node key `+0x10`, next `+0xc`, payload `+8` | ptr/u32 | Chain compare + live gate | **High** |
| Live-active + autoComplete → complete, `1` | branch | Raw early return | **High** |
| Live-active + !autoComplete → `0` | branch | Raw | **High** |
| Null payload / miss → award path (`LAB_0053656f`) | CF | `goto LAB` | **High** |
| Def via `FUN_0053fff0` + `CNDHash_LookupByKey` | callees | Named; `FUN_0053fff0` = lazy table at obj `+0xf18` | **High** table; **Probable** table-owner name |
| Race `def+0x90` vs char `+0x532` when checkLevel | u16 vs u8 zext | Raw compare; **no** `0xFFFF` race skip | **High** |
| Faction `def+0x92`, `0xFFFF` any | u16 | Raw | **High** |
| Recurse prereqs only if `def+0x124 == 0` | i32 gate | Raw `if`; product **`RequirementsNegative`** | **High** CF + name |
| 4× prereq at `+0x9c`, empty `0xFFFFFFFF` | u32[4] | Loop count 4 | **High** |
| Child always `autoComplete=1` | arg | Literal `'\x01'` + asm `PUSH 1` @ `0x0053662c` | **High** |
| Recursive return ignored | dataflow | No use of return | **High** |
| Min level `def+0x94` signed `<` | i32 | Raw | **High** |
| Level via entity vtbl `+0x27c` | slot | 1–3 call sites | **High** slot; **Probable** GetLevel name |
| XP bridge + AddExperience | callees | Named | **High** |
| Prep: 8×`-1`, `def+0x88`=**NPC**, `def+0xfc`=**AutoAssign**, id, 0 | stack | Raw init + `Mission.Read` layout | **High** layout + names |
| `FUN_0052c700` = store 12-dword prep into char map near `+0x50c` | callees | Fresh decompile: copy 0xc dwords, keyed by missionId | **High** shape; product English open |
| `FUN_0052c700` then `GiveMission` | order | Sequential | **High** |
| Optional CompleteMissionObjectives reason `1` | cdecl | Two call sites | **High** |
| Distinct from Requirements | split | See §6 | **High** |

---

## 4. Call-site matrix (residual edge — sealed)

Ghidra `get_xrefs_to` `0x00536540` → four sites. Asm args = push order last→first for stack formals (thiscall ECX separate).

| # | Call site VA | Container | ECX (`this`) | `missionId` | `autoComplete` | `checkLevel` | Role |
|---|---|---|---|---|---|---|---|
| 1 | `0x00536631` | self (recurse) | character (`ESI`) | prereq `*slot` | **1** | **parent's** `checkLevel` | Internal prereq force-award when `+0x124==0` |
| 2 | `0x005368ef` | `FUN_00536740` | character (`EBX`) | def id | **1** | **1** | Bulk auto-award after completed-hash skip at `char+0x538` |
| 3 | `0x00950915` | client cmd path (~`0x0095084f`–`0x0095095b`, undefined as named fn) | `*(client+0xe98)` | prereq id | **1** | **0** | External prereq walk after GiveMission miss path; same `+0x124==0` + 4×`+0x9c` shape |
| 4 | `0x00954575` | client debug cmd @ `0x00954510` | `*(client+0xe98)` | forced id | **0** | **0** | **"Forced add mission (%i)"** (`0x00a28af4`) — award without race/faction or bulk-complete |

### Sealed residual answers

| Prior open residual | Seal |
|---|---|
| Sole external caller is `FUN_00536740`? | **Falsified** — two additional client-side sites at `0x00950915` / `0x00954575` |
| Call sites with `checkLevel=0`? | **Yes** — sites 3 and 4 |
| Call sites with `autoComplete=0`? | **Yes** — site 4 only (debug force-add) |
| Body reads completed `+0x538`? | **No** — only site 2's **caller** walks `+0x538` before invoking this unit |

### Site 2 caller contract (`FUN_00536740`)

- Traverses mission-def table (`FUN_0053fff0` lock/walk).
- Filters defs by continent/region-ish fields + race/faction.
- Skips if completed hash `char+0x538` has live payload for that id.
- Then `CheckMissionPrerequisites(char, id, 1, 1)` — return **ignored** (fire-and-forget award cascade).

### Site 3 notes (asm-only; Ghidra function boundary gap)

- Nearby `CALL GiveMission` (`0x005327c0`) on character.
- On alternate arm: `FUN_0053fff0` + def lookup; if `def+0x124==0`, 4-slot prereq loop with `PUSH 0` / `PUSH 1` / `PUSH id` → **auto=1, check=0**.
- Post-loop: refresh UI `client+0x107c` vtbl `+0x3d8` (same journal surface as other mission UI).
- **Not** re-owned here beyond call-arg edge; outer cmd English open.

### Site 4 notes

- Entry `0x00954510` (`SUB ESP,0x104`; `MOV ESI,ECX` client; ChatLog RTTI casts).
- `PUSH 0; PUSH 0; PUSH EDI; CALL 0x00536540` → auto=0, check=0.
- Toast format string **`Forced add mission (%i)`** @ `0x00a28af4` after success path when `game+0xe04` flag `+0x7e` set.

---

## 5. Control flow: clean ≡ raw

| Stage | Raw | Clean | Match |
|---|---|---|---|
| Active-hash do/while + key compare | Present | Present | **Yes** |
| Live payload → autoComplete branch | Present | Present | **Yes** |
| Null payload / chain end → award | Present | Present (`award_path`) | **Yes** |
| Def lookup + null fail → `0` | Present | Present | **Yes** |
| `checkLevel` race/faction gate | Present | Present | **Yes** |
| Race strict (no `0xFFFF` skip) | Present | Present | **Yes** |
| Recursive prereq when `+0x124==0` | Present | Present | **Yes** |
| XP bridge when level < min | Present | Present | **Yes** |
| Triple GetLevel call shape on XP path | Present | Present | **Yes** |
| Prep blob 12 dwords + FUN_0052c700 | Present | Present (`prep[12]`) | **Yes** |
| GiveMission + optional complete | Present | Present | **Yes** |
| Returns `1` / `0` only | Present | Present | **Yes** |
| No invented max/currency/flag gates | N/A | None added | **Yes** |
| Restored `this` on GiveMission / FUN_0052c700 | Dropped by Ghidra | Explicit thiscall | **Yes** (corrects omission; CF same) |

Label renames (`award_path` vs `LAB_0053656f`) and typed locals do not change branch order.

---

## 6. Residual vs Requirements split

| Residual / open | Owned by this unit? | Notes |
|---|---|---|
| Pure eligibility for SearchAutoMissions | **No** | Requirements + GiveMission path |
| Max level / currency / flag gates | **No** | Requirements only |
| Prereq mode matrix `+0x120` Ored / `+0x124` Negative **query** | **No** (query) | Requirements dual owns truth table |
| `+0x124` as recursive-**award** gate | **Yes** | Here: recurse only when **Negative==0** |
| Completed-hash skip | **Caller** site 2 (`FUN_00536740`) | Not in this body |
| Award + XP + auto-complete cascade | **Yes** | This unit |
| English name “Check…Prerequisites” as pure check | **Misleading** | Documented; body mutates |
| Debug force-add / chat cmd outer bodies | **Edge only** | Args sealed; full cmd dual out of scope |

Do **not** fold Requirements gaps into this dual. Do **not** re-dual GiveMission / Requirements here.

---

## 7. Field seals (WAD / `Mission.Read`)

Anchored Id@0 → race@`+0x90` (shared with Requirements dual):

| Offset | Product name | Use in this unit |
|---|---|---|
| `+0x88` | **NPC** (giver CBID) | Copied into prep `uStack_10` |
| `+0x90` | `ReqRace` | Strict == when `checkLevel` |
| `+0x92` | `ReqClass` (client plate “faction”) | `0xFFFF` = any when `checkLevel` |
| `+0x94` | `ReqLevelMin` | XP bridge threshold |
| `+0x9c` | `ReqMissionId[4]` | Recursive award slots |
| `+0xfc` | **AutoAssign** (`i16`, dword copy) | Copied into prep `uStack_c` |
| `+0x120` | `RequirementsOred` | **Not read** in this body |
| `+0x124` | **`RequirementsNegative`** | Recurse award iff `== 0` |

**English for award-gate:** when `RequirementsNegative != 0`, inverted prereq sense applies on the Requirements path — this unit **skips** force-awarding the prereq chain (would otherwise grant missions the player is required *not* to hold).

---

## 8. Gaps / open questions

1. Formal product name of `FUN_0052c700` (shape sealed: 12-dword prep store keyed by missionId near `char+0x50c`).
2. Formal owner name of `FUN_0053fff0` table (`+0xf18` lazy alloc sealed).
3. Third GetLevel call on XP path — pure re-read vs side effect (shape sealed; intent open).
4. Server parity of client XP bridge before GiveMission.
5. Full dual of client cmd functions at `0x0095084f` / `0x00954510` (out of OWN scope; **args sealed**).
6. Runtime observation of award cascade and prereq force-complete.
7. `missionState.md` claim that this function reads completed `+0x538` remains **body-false** (caller site 2 only).

---

## 9. Relation to prior reviews

| Review | Date | Verdict | Notes |
|--------|------|---------|-------|
| Dual A thin | 2026-07-23 | accept-with-gaps | CF yes; thin evidence |
| Dual B thin | 2026-07-23 | accept-with-gaps / needs-more-evidence if pure API | Correct attacks on name |
| Dual A strengthen | 2026-07-29 (earlier) | accept-with-gaps | Fresh decompile; Requirements split |
| **This dual A residual edges** | **2026-07-29** | **accept-with-gaps** | Call-site matrix; `RequirementsNegative`; prep NPC/AutoAssign; `FUN_0052c700` shape |

---

## 10. Verdict

### **accept-with-gaps**

**Accept because:** Fresh decompile matches 2026-07-23 raw CF. Clean preserves every branch, offset, recursive shape, XP bridge, and grant order; only corrects Ghidra-dropped `this` on thiscall callees. Annotated widths/signedness body-backed. Split from Requirements is explicit. **Residual edges sealed:** full 4-site call matrix (including `checkLevel=0` and `autoComplete=0`), `+0x124` product name, prep field names, prep-helper shape.

**Gaps:** helper English names, XP server authority, runtime matrix, outer client-cmd duals.

**Porting rule:** Do not treat return as eligibility-only without side effects; do not use as SearchAutoMissions gate (use Requirements). Honor `autoComplete`/`checkLevel` per caller — debug force-add uses `(0,0)`.

---

## Checklist

| Check | Result |
|---|---|
| Raw + annotated + clean + function record exist | **Yes** |
| Fresh decompile 2026-07-29 | **Yes** |
| Clean CF ≡ raw | **Pass** |
| Offsets body-backed | **Pass** |
| No invented Requirements gates | **Pass** |
| Call-site arg matrix sealed | **Pass** |
| Dual A/B residual edges strengthened | **Yes** |
| Verdict | **accept-with-gaps** |
