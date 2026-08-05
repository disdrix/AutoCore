# Review A (reconstruction fidelity): `aa_0052da30` CVOGReaction_FailMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052da30` |
| **VA** | `0x0052da30` |
| **Canonical name** | `CVOGReaction_FailMission` |
| **Review date** | `2026-07-29` (dual residual body strengthen, pass 2) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0052da30_CVOGReaction_FailMission.md` |
| **Chain** | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| **Scratch** | `tmp/a_0052da30.md` |
| **Scope** | **Body only** — not Recv path `aa_0080b100` dual residual |
| **Verdict** | **accept** on kernel CF + Notify contract + xref/drain table; **accept-with-gaps** on full fail lifecycle / dirty readers / orphan host names |

---

## 1. Purpose

Client **fail-apply kernel** for an **active** mission on a character (`missions-progression`):

1. Lookup `missionId` in active-missions hash `char+0x540` (mask at `+8`, bucket table at `+0x10`, chain via node `+0xc`, key at node `+0x10`).
2. Require live node (`node+8 != 0`).
3. Log `"Player %I64d failed mission %d"` (`0x009cfa28`) with character COID from entity chain base+`0x164`/`0x168`.
4. `CVOGReaction_FailMissionNotify` with **`ECX = char+0x560`**, arg `&missionId` — **u32 vector push** onto end-quest id list (`char+0x564/+0x568/+0x56c`).
5. `char+0x634 |= 0x10` (mission dirty / refresh bit family).
6. Return `1` on success; `0` on miss / dead node (return value in **`AL`**, `RET 4`).

**Does not** erase the active hash node, strip cargo, or show the "Failed …" toast — those live in follow-on cleanup (notably `FUN_005307e0` on paths that drain the vector).

**Role in abandon chain:** local apply only after S2C `0x20B2` (`FUN_0080b100`) or reaction/HB callers. **Not** invoked directly from abandon UI confirm (that path only C2S-sends `0x20B2`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `decompile_function` / `analyze_function_complete` `0x0052da30` |
| Live image | `read_memory 0x0052da30` len `0x8A`; format string `0x009cfa28` |
| Notify body | decompile `0x004149d0`; grow `0x0040dbf0` |
| End-quest drain | decompile `FUN_005307e0` `0x005307e0` |
| Xrefs | `get_xrefs_to` → **11** `UNCONDITIONAL_CALL` sites |
| Named callers | `get_function_callers` → 5 functions (one with 2 sites) |
| Orphan site bytes | `read_memory` at `0060caa2`, `0060ec36`, `00612970`, `00886402`, `0057f44c` |
| Raw / clean / record | `raw/`, `reconstructed-exact/`, `functions/aa_0052da30_*` |
| Residual scratch | `tmp/a_0052da30.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(char*, missionId) → 0/1` (`AL`, `RET 4`) | **High** | Image + decomp |
| Active hash `+0x540` walk | **High** | Image offsets |
| Live node requires `node+8 != 0` | **High** | Explicit gate |
| Log + COID `+0x164/+0x168` + format `@0x009cfa28` | **High** | Literal + dual-base load |
| Notify `ECX = char+0x560` | **High / Confirmed** | `LEA ECX,[ESI+0x560]` @ `0x0052da9f` |
| Notify = u32 vector push (no hash erase) | **High** | Body `0x004149d0` |
| Vector triple `char+0x564/568/56c` | **High** | Notify offsets + `FUN_005307e0` drain |
| `char+0x634 \|= 0x10` then return 1 | **High** | Image order after Notify |
| Hash node **not** removed in this unit | **High** | No erase callees |
| **11** call sites total | **High** | `get_xrefs_to` + image `E8` verify |
| Drain always after every caller | **Falsified** | 3 yes / 8 no (static) |
| MissionId family `**([obj+4]+0x14c)` for HB/req class | **High** | Multiple decomp + orphan bytes |
| Dirty bit product English | **Probable** | Shared writer family; readers open |
| Orphan host function names | **Open** | Ghidra undef bodies |
| Bit-exact / runtime | **Open** | Deferred |

---

## 4. Control flow: clean ≡ raw ≡ live Ghidra ≡ image

| Stage | Match |
|---|---|
| Bucket + chain walk on `+0x540` | **Yes** |
| Early return 0 on chain miss (`XOR AL,AL` / `RET 4`) | **Yes** |
| Dead / null value node → return 0 | **Yes** |
| Log → Notify → OR `0x10` → `MOV AL,1` / `RET 4` | **Yes** |
| No invented branches / no hash erase | **Yes** |

**Result:** Kernel CF sealed. Residual pass sealed Notify register + body contract + full xref/drain table.

---

## 5. Call-site context (strengthened)

### Named functions

| Caller | Role | Sites | Drains via `FUN_005307e0`? |
|---|---|---:|---|
| `FUN_0080b100` (`Client_RecvFailMission`) | S2C `0x20B2` | 1 | **Yes** |
| `FUN_006508d0` | Mission HB fail arm | 1 | **Yes** |
| `CVOGHBMissionPatrol_Fn3` | Patrol resolve fail | 1 | **No** |
| `CVOGObjectiveRequirement_Kill_Precheck` | Kill precheck; gate `req+0x1c` | 1 | **No** |
| `FUN_0060e800` | Requirement helper (`param_4` 0xb/0xc arms) | **2** | **No** (both); return masks AL |

### Orphan CALL sites (no Ghidra function container)

| Site | Framing (static) | Drain? |
|---|---|---|
| `0x0060caa2` | `**([+4]+0x14c)`; char `@[ESP+4]`; `RET 0x1C` | **No** |
| `0x0060ec36` | `**([ESI+4]+0x14c)`; `ECX=EDI`; `RET 0x1C` | **No** |
| `0x00612970` | gate `byte[ESI+0x34]`; same `+0x14c`; `RET 0x1C` → `AL=1` | **No** |
| `0x00886402` | id `[ESI+0x540]`; `ECX=DAT_00d1b6d8`; next CALL `FUN_005307e0` | **Yes** |
| `0x0057f44c` | id `[ESI+0x25C]`; `ECX=EDI` from vtbl resolve | **No** |

**Drain yes (3):** Recv, HB `006508d0`, orphan `00886402`.  
**Drain no (8):** all other sites.

Abandon UI confirm (`FUN_00911840` case `0x4e46`) **does not** call this function — C2S `0x20B2` only.

---

## 6. Gaps (after residual pass 2)

1. ~~Exact `this` for FailMissionNotify~~ **Sealed:** `char+0x560`.
2. ~~Notify body vs teardown~~ **Sealed:** vector push only.
3. ~~Who drains / full xref set~~ **Sealed static table** (11 sites; 3 drain).
4. Full readers of `char+0x634` bit `0x10` (product English remains Probable).
5. Dual review of `FUN_005307e0` as its own unit.
6. Orphan host function recovery (create_function / name) — out of OWN body.
7. Runtime observation of abandon → S2C → this unit.
8. Optional: rename `0x004149d0` away from fail-specific name (generic multi-caller push).

---

## 7. Verdict

**FailMission kernel is sealed** for lookup / log / notify-push / dirty-bit / 0–1 return, with **Notify `this` and body High**, and **caller drain inventory High (static)** including previously missing orphan sites.

Full “mission gone from journal + toast” lifecycle remains caller-owned (`FUN_005307e0` when present).

**Verdict: accept** (kernel + Notify contract + xref/drain table) / **accept-with-gaps** (lifecycle completeness, dirty readers, orphan host names, runtime).
