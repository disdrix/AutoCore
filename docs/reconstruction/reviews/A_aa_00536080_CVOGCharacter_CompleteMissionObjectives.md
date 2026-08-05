# Review A (reconstruction fidelity): `aa_00536080` CVOGCharacter_CompleteMissionObjectives

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536080` |
| **VA** | `0x00536080` |
| **Canonical name** | `CVOGCharacter_CompleteMissionObjectives` |
| **Review date** | `2026-07-29` (dual residual strengthen; prior spot-check same day; raw `2026-07-23`) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00536080_CVOGCharacter_CompleteMissionObjectives.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present and strengthened** (A + B modern pair; residual pass) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Character-side **bulk force-complete of every objective on a mission def** (`missions-progression`):

1. Save `this` (character); resolve mission def via `FUN_0053fff0(DAT_00b041fc)` + `CNDHash_LookupByKey(*root, missionId)`.
2. Read objective **count** = `byte(def+0x130)`, **array** = `*(def+0x13c)` (ptr table, stride 4).
3. For each index `i`: `CVOGReaction_CompleteObjective(this, *(array[i]+0x10), -1, -1, forceFlag)`.
4. Return **1** if def found (even if count 0); **0** if missing table/def.

Convention: MSVC **`__thiscall`** (character in `ECX`; two stack formals; **`RET 8`**). **Sole Ghidra xrefs:** two sites in `CVOGCharacter_CheckMissionPrerequisites` (`0x005365ae`, `0x00536722`), both `PUSH 1; PUSH missionId; MOV ECX,ESI; CALL` with **forceFlag = 1**.

Does **not** itself insert completed-mission hashes — that is callee-owned (`CompleteObjective` final path). Body only sequences per-objective force completes.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00536080_CVOGCharacter_CompleteMissionObjectives.md` |
| Annotated | `docs/reconstruction/raw/aa_00536080_CVOGCharacter_CompleteMissionObjectives.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_CompleteMissionObjectives.cpp` |
| Function record | `docs/reconstruction/functions/aa_00536080_CVOGCharacter_CompleteMissionObjectives.md` |
| Fresh decompile | Ghidra MCP `decompile_function` @ `0x00536080` (2026-07-29 residual) — CF ≡ 2026-07-23 raw |
| Full analysis | `analyze_function_complete` — 2 xrefs, 3 callees, 46 insns |
| Function listing | `disassemble_function` @ `0x00536080` (not `disassemble_bytes`) |
| Call-site asm | `get_assembly_context` @ `0x005365ae`, `0x00536722`, `0x005360da` |
| Memory | `read_memory` body `0x00536080` len 128; `DAT_00b041fc` (bss zero at rest) |
| Callee boundary | decompile `FUN_0053fff0` `0x0053fff0`, `CVOGReaction_CompleteObjective` `0x00533f90` (arg roles only) |
| Caller dual | `A/B_aa_00536540_CVOGCharacter_CheckMissionPrerequisites` |
| Callee dual | `A/B_aa_00533f90_CVOGReaction_CompleteObjective` |
| System map | `docs/reconstruction/systems/missions-progression.md` |
| Scratch | `tmp/a_00536080.md` |

**Not performed:** `disassemble_bytes`, Launcher, live bulk-complete capture, binary diff.

---

## 3. Sealed facts (body + listing)

### 3.1 Signature / convention (corrects prior dual)

| Claim | Evidence | Conf |
|---|---|---|
| **`__thiscall`**, not `__cdecl` | Prologue `PUSH ECX; MOV [ESP],ECX`; epilogue **`RET 8`** both success and miss paths | **High** |
| Stack formals: `uMissionID` @ `[ESP+4]` after ret, forceFlag @ `[ESP+8]` | `MOV EAX,[ESP+0xC]` after one push = missionId; `MOV EBP,[ESP+0x1C]` in loop = forceFlag | **High** |
| `this` (character) is **live** | Saved at entry; reloaded `MOV ECX,[ESP+0x10]` immediately before `CALL CompleteObjective` | **High** |
| Call-site `MOV ECX,ESI` is **not dead** | Both prereq sites: `PUSH 1; PUSH EBX; MOV ECX,ESI; CALL 0x00536080` — ECX feeds saved this | **High** |
| Return `1` if def found (count may be 0) | `MOV AL,1` after optional loop; zero-count takes `JLE` skip | **High** |
| Return `0` if table null or lookup miss | `XOR AL,AL` then `RET 8` | **High** |

**Falsifies prior dual residual:** “`MOV ECX,ESI` is dead leftover from thiscall siblings” and “`__cdecl` static helper / no this.”

### 3.2 Control flow (clean ≡ raw ≡ live decomp ≡ listing)

```
this_saved = ECX
rootObj = FUN_0053fff0(DAT_00b041fc)     // ECX := [0x00b041fc]; lazy *(owner+0xf18)
table = *rootObj
if table == 0 → return 0
def = CNDHash_LookupByKey(table, missionId)
if def == 0 → return 0
count = MOVZX u8(def+0x130)
array = *(def+0x13c)
for i in 0 .. count-1:                 // TEST/JLE; then CMP/JL
  objId = *(*(array + i*4) + 0x10)
  CompleteObjective(this_saved, objId, -1, -1, forceFlag)  // return ignored
return 1
```

| Stage | Raw | Clean | Listing | Match |
|---|---|---|---|---|
| Dual null gate (table / def) | Yes | Yes | Yes | **Yes** |
| Byte count + counted loop | Yes | Yes | MOVZX + JLE/JL | **Yes** |
| Obj id at `objDef+0x10` | Yes | Yes | `MOV EAX,[EDX+0x10]` | **Yes** |
| Args `id, -1, -1, forceFlag` + ECX this | Yes (decomp drops this) | Yes (thiscall corrected) | 4× PUSH + MOV ECX | **Yes** |
| No abort on callee fail | Yes | Yes | no TEST AL after CALL | **Yes** |
| No invented filters | — | None | — | **Yes** |
| `RET 8` both exits | hidden by decomp “cdecl” | corrected | both paths | **Yes** |

Ghidra **plate / decomp prototype still say `__cdecl`** and plate step 5 still says CompleteObjective “reason 0xffffffff” — **body+listing win**.

### 3.3 Offsets (body-backed)

| Offset | Shape | Role | Conf |
|---|---|---|---|
| `def+0x130` | **u8** (MOVZX) | Objective count; loop bound 0..255 | **High** |
| `def+0x13c` | **ptr** | Base of objective-def pointer table (stride 4) | **High** |
| `objDef+0x10` | **u32** | Objective id → CompleteObjective arg0 | **High** |
| `DAT_00b041fc` | global ptr | Owner passed to `FUN_0053fff0` as ECX | **High** |
| owner `+0xf18` | ptr slot | Lazy mission-table object (inside FUN) | **High** CF; product name **open** |

Cross-note: GiveMission dual treats dword-index `def+0x4c` → byte `+0x130` as non-zero “awardable” gate — same **count** field, not a second flag.

### 3.4 CompleteObjective arg packing (boundary)

| Slot | Value from this unit | Callee role (sealed at dual of `0x00533f90`) | Conf |
|---|---|---|---|
| ECX | saved character `this` | `__thiscall` this | **High** |
| arg0 | `*(objDef+0x10)` | objectiveId | **High** |
| arg1 | `0xFFFFFFFF` | reward COID lo wildcard | **High** |
| arg2 | `0xFFFFFFFF` | reward COID hi wildcard | **High** |
| arg3 | stack formal (prereqs: **1**) | **forceComplete** (char; non-zero skips failed req evals) | **High** |

**Naming residual sealed:** formal historically called `uReason` in raw/plate; at callee it is **forceComplete**, not a multi-value reason enum. Sole static value observed: **1**.

### 3.5 Sole callers

| Site | Function | Asm shape | forceFlag |
|---|---|---|---|
| `0x005365ae` | `CheckMissionPrerequisites` (live-active + autoComplete) | `PUSH 1; PUSH EBX; MOV ECX,ESI; CALL` | **1** |
| `0x00536722` | same (post-GiveMission + autoComplete) | same | **1** |

- `get_function_callers` / `get_function_xrefs` → **only** Prerequisites (2 unconditional calls).
- Caller itself `RET 0xC` (its own thiscall); does **not** clean the 8 bytes of CompleteMissionObjectives formals (callee `RET 8` does).

### 3.6 Callees

| Callee | VA | Role from this body | Conf |
|---|---|---|---|
| `FUN_0053fff0` | `0x0053fff0` | Lazy table object at owner `+0xf18`; ECX=`DAT_00b041fc` | **High** CF; product name **open** |
| `CNDHash_LookupByKey` | `0x005b0920` | Key = mission id; table = `*FUN()` | **High** |
| `CVOGReaction_CompleteObjective` | `0x00533f90` | Force each objective; return discarded | **High** call shape |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall (this, missionId, forceFlag) → 0/1` | **High** | Listing prologue/epilogue + call sites |
| Def table + lookup gates | **High** | Dual null checks |
| Count byte `+0x130`, ptr array `+0x13c` | **High** | Loop bounds; max 255 after zext |
| Obj id at `objDef+0x10` | **High** | Same as sibling mission units |
| CompleteObjective `id, -1, -1, force` + this | **High** | Listing 4 pushes + MOV ECX |
| forceFlag=1 at sole sites | **High** | asm `PUSH 1` |
| Return 1 on empty count | **High** | JLE skip, still `MOV AL,1` |
| CompleteObjective return ignored | **High** | No test of AL |
| Clean CF ≡ raw ≡ live decomp | **High** | Convention/this corrected vs decomp lie |
| Mission-level complete side effects | **Out of body** | Callee-owned |
| Full forceFlag / “reason” enum | **Tentative** | Only `1` observed statically |
| Product name `FUN_0053fff0` / `DAT_00b041fc` | **Tentative** | Shared global; English open |

---

## 5. Param / local renames (evidence only)

| Raw | Clean | Evidence |
|---|---|---|
| (missing this) | `thisCharacter` | Listing save/restore ECX |
| `uMissionID` | `uMissionID` | Mission def key |
| `uReason` | `forceComplete` | Forwarded as CompleteObjective force; prereqs push `1` |
| `bVar1` | `bCount` | `*(byte*)(def+0x130)` |
| `puVar2` | `puTableRoot` | Result of `FUN_0053fff0` then `*root` |
| `pvVar3` | `missionDef` | Lookup result |
| `iVar4` | `i` | Loop index |

Callee names already in raw: `CNDHash_LookupByKey`, `CVOGReaction_CompleteObjective`. Table getter stays `FUN_0053fff0`.

---

## 6. Gaps / open questions

1. CompleteObjective returns ignored — partial bulk failure invisible at this layer.
2. Ghidra plate still: `__cdecl`, “reason 0xffffffff” for CompleteObjective (false — that is args 2/3; arg 4 is force; this in ECX).
3. No runtime bulk-complete capture; bit-exact / diff open.
4. Whether count-0 success is intentional for empty defs (GiveMission also gates non-zero `+0x130`).
5. Product name for `FUN_0053fff0` / owner of `DAT_00b041fc` (+0xf18 lazy slot).
6. Mission-level wrap-up after bulk force is callee-side only.
7. Whether any non-prereq caller exists outside static image (dynamic / script) — **no static xref**.

**Verdict:** Bulk-loop CF faithful; convention/`this`/forceFlag sealed by listing. **accept-with-gaps.**
