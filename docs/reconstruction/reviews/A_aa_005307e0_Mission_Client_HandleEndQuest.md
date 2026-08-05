# Review A (reconstruction fidelity): `aa_005307e0` Mission_Client_HandleEndQuest

| Field | Value |
|---|---|
| **Stable ID** | `aa_005307e0` |
| **VA** | `0x005307e0` |
| **Canonical name (claim)** | `Mission_Client_HandleEndQuest` (Ghidra still `FUN_005307e0`) |
| **Review date** | `2026-07-29` (dual residual after RecvFailMission / FailMission seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005307e0_Mission_Client_HandleEndQuest.md` |
| **Chain** | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** — product role as **shared end-quest drain / fail teardown** **High**; LogicUI ids / `+0xd6c` English open |

---

## 1. Purpose

Client **shared end-quest drain** on a **character** (`missions-progression`):

1. Walk the **u32 mission-id vector** at `char+0x564` / `+0x568` / `+0x56c` (begin / end / cap). FailMission enqueues via `CVOGReaction_FailMissionNotify` with `ECX = char+0x560`.
2. For each id: lookup live mission payload in **active hash `char+0x540`** (bucket/mask/chain family).
3. If hit: **remove** the mission key from **`+0x540` and sibling `+0x544`** (hash-remove free-list path via `FUN_004e2ca0` + list unlink).
4. For each objective on the mission def (`byte def+0x130` count, list `def+0x13c`):
   - When `char+0xd6c == 1`: lookup obj in **`+0x548`**, walk skill/element vector `obj+0x158..+0x15c`; if vtbl-class **`0xe`** and float at `elem+0xA0` (`[0x28]`) `> g_flZero` → set local flag and `Client_SendLogicUiPacket` with type **`0x30`**.
   - Optional destroy on pending hash **`+0x55c`** (`FUN_00538000` when live).
   - Remove from active-objectives **`+0x548`**.
5. Destroy mission state blob in **`+0x530`** (`FUN_00537f30`).
6. If local-player identity gate matches **and** (`flag` **or** `char+0xd6c == 0`):
   - `Client_SendLogicUiPacket` type **`0xd`** with mission id.
   - Toast `sprintf("%s %s", localize("Failed"), title_from def+0x14c)` via `FUN_0040c5c0`.
   - Audio: `Client_GetMissionCompleteAudioTable("gen_end_quest", …)` + `Client_PlayNamedInterfaceSound`.
7. `FUN_004de9f0()` then `FUN_0052d8b0(0, 0xffffffff)` (tree/list cleanup helper, `param_3 == -1` whole walk).
8. After all ids: `operator_delete` vector storage; zero `+0x564/568/56c`; clear **`+0xd6c`** and **`+0xd68`**.

**Does not** award XP/credits, send C2S/S2C fail packets, or push the id list (upstream owns enqueue). **Not** the same toast/audio path as `CVOGReaction_CompleteObjective` (`"Completed"` / `mission_complete_3`).

**Role after RecvFailMission:** S2C `0x20B2` → `CVOGReaction_FailMission` (push id + dirty `0x10`) → **this unit** (drain + hash erase + "Failed" presentation).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `decompile_function` `0x005307e0` (2026-07-29 residual) |
| Callers (xrefs) | `get_function_xrefs` → `00534b97`, `0080b11c`, `00650c69`, `0088640d` |
| Asm call sites | `get_assembly_context` on those four |
| RecvFailMission | dual `aa_0080b100` + body image |
| FailMission / Notify | dual `aa_0052da30` / `aa_004149d0` |
| Raw | `raw/aa_005307e0_FUN_005307e0.md` |
| Annotated | `raw/aa_005307e0_FUN_005307e0.annotated.md` |
| Clean | `reconstructed-exact/Mission_Client_HandleEndQuest.cpp` (+ `FUN_005307e0.cpp`) |
| Function record | `functions/aa_005307e0_FUN_005307e0.md` |

---

## 3. Rename claim: `Mission_Client_HandleEndQuest`

| Evidence | Strength |
|---|---|
| Literal `"gen_end_quest"` audio table key | **High** |
| Literal toast stem `"Failed"` + mission title | **High** |
| Drains FailMission enqueue vector `+0x564` | **High** (Notify + this body) |
| Shared post-complete safety drain after `EvaluatePendingObjectives` | **High** (call) |
| Name implies complete-only UX | **Overstated** — toast is **Failed**; complete UX lives in CompleteObjective |

**Rename recommendation:** keep `Mission_Client_HandleEndQuest` as **Probable/High** product alias (end-of-quest teardown). Leave Ghidra `FUN_005307e0` until broader rename pass; do **not** invent a fail-only name (also used off complete path).

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__fastcall`/`thiscall` **ECX = character** | **High / Confirmed** | Recv site `MOV ECX,[EDI+0xe98]`; Eval `MOV ECX,EBP`; HB `MOV ECX,EBX`; 4th `MOV ECX,[DAT_00d1b6d8]` |
| Vector triple `+0x564/568/56c` drain + free | **High** | Loop exit zeros all three |
| Empty/done path clears `+0xd6c` and `+0xd68` | **High** | Explicit stores before `return` |
| Mission lookup on active `+0x540` | **High** | Same hash walk as FailMission |
| Remove from **`+0x540` and `+0x544`** pair | **High** | Symmetric to GiveMission dual-insert residual |
| Per-obj walk `def+0x130` / `+0x13c` | **High** | Byte count + dword list |
| Obj remove `+0x548`; pending destroy `+0x55c` | **High** CF | Callee product names Probable |
| Mission blob destroy `+0x530` via `FUN_00537f30` | **High** CF | Pair with GiveMission insert to `+0x530` |
| Local-player gate before toast/audio | **High** | Same identity compare family as CompleteObjective |
| Toast `"Failed" + title`; audio `gen_end_quest` | **High** | Literals |
| LogicUI type **`0xd`** (mission id) / **`0x30`** (skill `0xe` branch) | **High** (values) / **Tentative** (product English) | Stack tags in decomp |
| Toast when `bVar4 \|\| char+0xd6c==0` | **High** | Explicit |
| Skill class `0xe` + float@`+0xA0` gate | **High** CF | Product class name open |
| Not XP/credit calculator | **High** | No ComputeObjective* |
| Does not send 0x20B2 | **High** | No sector packet callees |
| Always runs after every FailMission caller | **Falsified** | Only Recv / HB / one site / Eval; not Patrol_Fn3 etc. |
| Bit-exact / runtime | **Open** | Deferred |

---

## 5. Control flow: clean ≡ raw ≡ live Ghidra

| Stage | Match |
|---|---|
| Index loop over `+0x564` until end | **Yes** |
| Empty → free + zero vector + clear `+0xd6c/+0xd68` → return | **Yes** |
| Active `+0x540` lookup; miss → skip body, next id | **Yes** |
| Hash remove `+0x540` then `+0x544` | **Yes** |
| Objective loop → optional `0xd6c==1` skill scan → destroy `+0x55c` → remove `+0x548` | **Yes** |
| Destroy `+0x530` | **Yes** |
| Conditional toast/audio + LogicUI `0xd` | **Yes** |
| `FUN_004de9f0` + `FUN_0052d8b0(0,-1)` | **Yes** |
| Infinite `do` until empty-exit (decompiler form) | **Yes** |
| Invented reward math / complete toast | **None** |

**Result:** CF sealed. Residual pass seals product role after FailMission + offset map.

---

## 6. Call-site context (sealed residual)

| Caller | Call VA | Role | Precedes with FailMission? |
|---|---:|---|---|
| `Client_RecvFailMission` `FUN_0080b100` | `0x0080b11c` | S2C **0x20B2** post-apply drain | **Yes** (immediate) |
| `FUN_006508d0` (mission HB fail arm) | `0x00650c69` | Local fail when target/objective lost | **Yes** |
| `CVOGCharacter_EvaluatePendingObjectives` | `0x00534b97` | After bulk `CompleteObjective` | **No** (safety drain) |
| Site `0x0088640d` (fn undefined in Ghidra) | `0x0088640d` | `FailMission` then drain on `DAT_00d1b6d8` | **Yes** |

RecvFailMission asm (product-critical):

```
0080b103  MOV ECX,[EDI+0xe98]     ; character
0080b10d  MOV EDX,[EAX+0x10]      ; missionId from packet
0080b110  PUSH EDX
0080b111  CALL 0x0052da30         ; FailMission
0080b116  MOV ECX,[EDI+0xe98]
0080b11c  CALL 0x005307e0         ; this unit
```

---

## 7. Gaps / open

1. Product English for `char+0xd6c` / `+0xd68` (shared with credits floater suppress — not fail-exclusive).
2. LogicUI product names for types `0xd` and `0x30`.
3. Skill/element class **`0xe`** identity (vtbl type).
4. Full roles of `FUN_004de9f0` and `FUN_0052d8b0(0,-1)` (tree at `+0x50c` family).
5. Who **writes** `+0xd6c` before drain (only clear observed here).
6. Identity / plate for caller at `0x0088640d` (no function bound in Ghidra).
7. Runtime abandon → S2C → FailMission → this unit capture.
8. Whether EvaluatePendingObjectives path ever has non-empty `+0x564` without prior FailMission.

**Verdict:** **accept-with-gaps** — drain / dual-hash remove / Failed toast / RecvFailMission product role sealed; UI opcode English + `+0xd6c` + runtime open.
