# Review A (reconstruction fidelity): `aa_005327c0` CVOGReaction_GiveMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_005327c0` |
| **VA** | `0x005327c0` |
| **Canonical name** | `CVOGReaction_GiveMission` |
| **Review date** | `2026-07-29` (dual residual; prior `2026-07-28` / `2026-07-23`) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005327c0_CVOGReaction_GiveMission.md` |
| **Residual scratch** | `reviews/a_005327c0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client-side **grant mission** on a character (`missions-progression`):

1. Resolve mission def (`FUN_0053fff0` + `CNDHash_LookupByKey`); require **byte objCount `def+0x130` ≥ 1** (dword-index `+0x4c` on `undefined4*`).
2. `FUN_00547920` **EnsureXmlLoaded**(def): ECX=def; stack 1 then maybe 0 when `byte def+0x168==0`.
3. **Outer already-active** lookup `char+0x540`: if hit, skip grant body → **return 0**.
4. Optional completed / instance-completed rejects (`+0x538` / `+0x53c`) when `word def+0xAC != -1`, gated by mode on entity `+0xa8` object (`WeaponAllowsKillXpBonus` — historical name).
5. Ensure first objective (`def+0x13c`) active via `AddActiveObjective(char, objDef)` if not in `+0x548`; else log `"Already had objective..."`.
6. Always `UnlockContinentObject(char, firstObj+0x120)` after objective branch.
7. Re-check `+0x540`: if free → `CNDHash_Insert` **`+0x540`**, optional sibling **`+0x544`**, strip completed, 0x30 blob on **`+0x530`**, notify; toast when `word def+0xF8==0`. If re-check hits → log `"Already had mission..."` still **return 1**.
8. Successful inner grant path returns **1**; outer reject / missing def returns **0**.

Does **not** open volume gates itself. Server mirror / `OnMissionStateChanged` is external prose only. Callers: `SearchAutoMissions`, reaction dispatch **0x1e**. Residual: `reviews/a_005327c0.md`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005327c0_CVOGReaction_GiveMission.md` |
| Annotated | `docs/reconstruction/raw/aa_005327c0_CVOGReaction_GiveMission.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_GiveMission.cpp` |
| Function record | `docs/reconstruction/functions/aa_005327c0_CVOGReaction_GiveMission.md` |
| System map | `docs/reconstruction/systems/missions-progression.md` |
| Layout | `docs/missionState.md` hashes +0x538/53c/540/548 |
| Callee | `CVOGMission_AddActiveObjective` `aa_00531b00` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(char*, missionId) → 0/1` | **High** | Raw + asm `RET 4` / AL 0\|1 |
| Def table lookup + **obj-count byte `def+0x130` ≥ 1** | **High** | Asm `CMP byte [def+0x130],1` / `JC` reject — **not** separate awardable bit |
| Outer already-active (`+0x540` hit) → **return 0** | **High** | Nested miss-only body; asm `XOR AL,AL` |
| Completed rejects +0x538 / +0x53c when `word def+0xAC != -1` | **High** | Dual mode gates; early `return 0` |
| AddActiveObjective if objective not active | **High** | Else log “Already had objective” |
| `AddActiveObjective` arity `__thiscall(char*, objDef)` | **High** | Asm `MOV ECX,EBP; PUSH firstObj; CALL 00531b00` — raw 1-arg is this-elision |
| Always UnlockContinentObject after objective branch | **High** | Call order fixed in raw |
| `FUN_0053c360` = **CNDHash_Insert** into `+0x540` then optional `+0x544` | **High** | Strings + asm ECX; **not** same-hash double |
| `FUN_0053c660` = hash insert of 0x30 blob into `+0x530` | **High** | Twin insert body; asm `MOV ECX,[EBP+0x530]` |
| `FUN_00538b20` = **CNDHash_Remove** from completed `+0x538` | **High** | Remove string + re-grant strip |
| `FUN_00547920` = mission def **XML ensure-load** (ECX=def) | **High** | Body parses Objective/Title/…; stack 0/1 nuance Tentative |
| `FUN_00538a40` lower_bound on tree at `char+0x508` | **High** | Asm `LEA ECX,[EBP+0x508]` |
| Toast only when `word def+0xF8 == 0` | **High** | Byte offset sealed (was dword-index `+0x3e`) |
| Inner re-check hit → log “Already had mission” → **return 1** | **High** | Distinct from outer already-active |
| Hash offsets 538/53c/540/544/548/530 (+0x50c sentinel) | **High** | missionState + residual asm; **+0x544/+0x530** newly sealed |
| Mode gate via `WeaponAllowsKillXpBonus` on entity `+0xa8` object | **High** framing / **Probable** product | Name historical; `this` is **not** character |

---

## 4. Control flow: clean ≡ raw (spot-check)

| Stage | Raw present? | Clean match? |
|---|---|---|
| Outer triple guard (table / def / awardable) | Yes | **Yes** |
| `FUN_00547920(1)` then conditional `(0)` on def+0x5a | Yes | **Yes** |
| Outer `+0x540` miss-only enters grant body; hit → fall to **return 0** | Yes | **Yes** |
| Completed / instance-completed early **return 0** | Yes | **Yes** |
| Objective `+0x548` add vs “Already had objective” log | Yes | **Yes** |
| UnlockContinentObject after objective branch | Yes | **Yes** |
| Inner `+0x540` re-check: insert path vs “Already had mission” | Yes | **Yes** |
| Double `FUN_0053c360` under mode + short/dword gate | Yes | **Yes** |
| Repeatable strip via `FUN_00538b20` when short@0x2b==-1 | Yes | **Yes** |
| `operator_new(0x30)` / null blob / `FUN_004111f0` | Yes | **Yes** |
| Prior-state copy 0xC dwords when node ≠ +0x50c sentinel | Yes | **Yes** |
| `FUN_0053c660(*def, blob, 0)` + `FUN_0052d8b0(0, *def)` | Yes | **Yes** |
| Toast+audio only short@0x3e==0; early **return 1** | Yes | **Yes** |
| Fall-through **return 1** after insert/no-toast or already-had-mission | Yes | **Yes** |
| Final **return 0** | Yes | **Yes** |
| Invented clamps / deleted branches | — | **None** |

**Result:** Clean CF ≡ raw. No deleted branches observed in spot-check.

---

## 5. Param / local renames (evidence only)

| Raw | Clean | Evidence |
|---|---|---|
| `param_1` | `thisCharacter` | `__thiscall`; used as character base for hashes +0x538..+0x548 / +0x50c; plate “to character” |
| `param_2` | `missionId` | Mission hash key into def table + active/completed lookups; plate “grant mission param_2” |
| `local_1a4` | `local_stateBlob` | Receives `operator_new(0x30)` / `FUN_004111f0`; passed to `FUN_0053c660` |
| `local_1a0` | `local_priorNode` | Out-arg of `FUN_00538a40`; compared to `this+0x50c` |
| `local_19c` | `local_missionId` | Copy of `param_2` for `FUN_00538a40` in/out |
| `local_198` | `local_toastTitle` | 128-byte buffer → `FUN_0040c5c0` |
| `local_100` | `local_toastBody` | 256-byte `sprintf` dest before `strncpy` into title |

Callee names already present in raw (not invented by clean): `CNDHash_LookupByKey`, `CVOGCharacter_WeaponAllowsKillXpBonus`, `CVOGMission_AddActiveObjective`, `CVOGReaction_UnlockContinentObject`, `Client_GetMissionCompleteAudioTable`, `Client_PlayNamedInterfaceSound`, `g_flLevelUpUiBase_Inferred`. Remaining helpers stay `FUN_*`.

---

## 6. Gaps / open questions

1. ~~Insert helpers~~ **Sealed residual 2026-07-29** — roles High; product English for `+0x544` / `+0x530` open.
2. Mode object at entity `+0xa8`: identity + meaning of `+0xac==2` / `+0x100` flag (shared with other duals).
3. ~~AddActiveObjective arity~~ **Sealed High** from GiveMission call site (2-arg thiscall).
4. ~~Def byte gates~~ **Sealed** as offsets; product words for `+0xf8` / `+0x100` still open.
5. Runtime grant / re-grant / outer already-active / toast capture not observed.
6. Whether callers treat return-0 as hard error (recovered callers ignore return).
7. `FUN_00547920` stack arg 0/1 full semantics (Tentative).

**Verdict:** Grant kernel CF faithful; residual callee/`this` map High. **accept-with-gaps.**
