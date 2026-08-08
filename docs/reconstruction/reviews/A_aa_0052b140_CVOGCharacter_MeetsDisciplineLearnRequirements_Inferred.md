# Review A (reconstruction fidelity): `aa_0052b140` CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b140` |
| **VA** | `0x0052b140`–`0x0052b2d0` |
| **Canonical name (Ghidra)** | `FUN_0052b140` |
| **Proposed name** | `CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred` |
| **Review date** | `2026-08-05` (R13-036 OWN-ONLY dual A; dual start 2686) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0052b140_CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred.md` |
| **System** | `skills-abilities` (partition parent `0x0052b040`) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`CVOGCharacter` **discipline learn-requirements gate** (bool):

1. Exact-find `disciplineId` on process-global **DisciplineDef map** `0x00b045b0` via `FUN_00538ab0`; miss (`node == DAT_00b045b4`) → `AL=0`.
2. Copy payload **0x1FC** (`REP MOVSD` × `0x7f`) from `node+0x10` into a stack scratch.
3. **Min level:** nested character vtbl slot **`+0x27c`** return ≥ signed short payload **`+0x26`** (else fail).
4. **Prereq alternatives (OR):** for each of five slots `i=0..4`:
   - id at payload `+0x08+4*i` (sentinel **`-1`** = empty);
   - if id ≠ `-1` and `DisciplineDefMap_TryCopyPayloadById_Inferred(id, scratch)` and `CVOGCharacter_GetResourceBalanceByType(id) >= short threshold at +0x1C+2*i` → **success**.
5. If **all five** ids are **`-1`** (no prereq alternatives) and level OK → **success**.
6. Else → `AL=0`.

Domain sealed by caller string at `FUN_00931cf0`:  
`"You do not meet the requirements to learn this Discipline"`.  
UI tooltip path `FUN_0084d220` pairs the same payload fields with `"Requires Minimum Level of"` / `"Requires: "`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0052b140` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/locals/completeness) |
| Assembly | `disassemble_function` (body through dual `RET 4`; **not** `disassemble_bytes`) |
| Bytes | `read_memory` 256 B @ entry + 32 B @ dual exits — hex seal + `CC` pad |
| Callers / xrefs | `get_function_callers` (5) + `get_function_xrefs` (5 UNCONDITIONAL_CALL) |
| Call-site context | `get_assembly_context` on all five sites |
| Parent dual | `aa_0052b040` `DisciplineDefMap_TryCopyPayloadById_Inferred` (R12-020) |
| Resource balance | `aa_0052ada0` `CVOGCharacter_GetResourceBalanceByType` (dualed) |
| Caller domain | `decompile_function` @ `0x00931cf0`, `0x0052d180`, `0x0084d220`, `0x0084dc10` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact|functions` for `aa_0052b140` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledger edits, other VAs dualled.

---

## 3. Signature

```c
uint8_t __thiscall CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred(
    CVOGCharacter *this /* ECX */,
    int disciplineId /* stack0 */);
// RET 4; bool in AL
```

| Item | Evidence |
|---|---|
| Convention | entry `MOV EBX,ECX`; exits `RET 4` @ `0x0052b2c3` / `0x0052b2ce` |
| Stack arg | `MOV EAX,[EBP+8]` → find key; single stack formal |
| this | `MOV ECX,EBX` before every `CALL 0x0052ada0`; call sites load `DAT_00d1b6d8` / `*(client+0xe98)` into ECX |
| Map hardcode | `MOV ECX,0xb045b0` before `CALL FUN_00538ab0` |
| End compare | `CMP EAX,[0xb045b4]` → miss path `XOR AL,AL` |
| Copy | `LEA ESI,[EAX+0x10]` / `MOV ECX,0x7f` / `REP MOVSD` |
| Level vcall | nested `CALL dword ptr [EDX+0x27c]`; `MOVSX` threshold from payload `+0x26`; `JL` fail |
| Nested try-copy | `PUSH scratch; PUSH id; CALL 0x0052b040; ADD ESP,8; TEST AL,AL` |
| Balance | `PUSH id; MOV ECX,EBX; CALL 0x0052ada0`; `MOVSX` thr; `CMP EAX,ECX; JGE` success |
| Body size | **401 B** (`0x191`); pad `CC` from `0x0052b2d1` before `FUN_0052b2e0` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Find discipline id on map `0x00b045b0` | **Yes** |
| Miss if node == `DAT_00b045b4` → AL=0 | **Yes** |
| Hit → stack-copy 0x1FC from node+0x10 | **Yes** |
| Level via vtbl+0x27c ≥ payload+0x26 | **Yes** |
| Five prereq slots OR-chain + all-`-1` pass | **Yes** |
| Nested `0052b040` cdecl + `ADD ESP,8` | **Yes** |
| Nested `0052ada0` thiscall on this | **Yes** |
| thiscall + `RET 4` + bool AL | **Yes** |

### Payload layout (DisciplineDef, offsets from `node+0x10`)

| Off | Type | Role |
|----:|------|------|
| `+0x08` | int | prereq discipline id slot 0 (`-1` empty) |
| `+0x0C` | int | prereq id slot 1 |
| `+0x10` | int | prereq id slot 2 |
| `+0x14` | int | prereq id slot 3 |
| `+0x18` | int | prereq id slot 4 |
| `+0x1C` | i16 | balance threshold slot 0 |
| `+0x1E` | i16 | threshold slot 1 |
| `+0x20` | i16 | threshold slot 2 |
| `+0x22` | i16 | threshold slot 3 |
| `+0x24` | i16 | threshold slot 4 |
| `+0x26` | i16 | min character level |

### Callers (5)

| Site | Caller | Role |
|---|---|---|
| `0x0052d1ce` | `FUN_0052d180` | train/validate residual — fail code **4** if this returns 0 |
| `0x0082bb36` | `FUN_0082b990` | UI path; ECX=`DAT_00d1b6d8` local character |
| `0x0084d277` | `FUN_0084d220` | discipline tooltip stats; `"Requires Minimum Level of"` / `"Requires: "` |
| `0x0084df78` | `FUN_0084dc10` | `i_w_skill_2d_wnd_*` discipline window color/chrome |
| `0x00931cfa` | `FUN_00931cf0` | learn request; string **requirements to learn this Discipline**; opcode `0x2097` on pass |

### Callees

| VA | Name | Role |
|---|---|---|
| `0x00538ab0` | map exact-find helper | key on `0x00b045b0` |
| `0x0052b040` | `DisciplineDefMap_TryCopyPayloadById_Inferred` | nested prereq def existence |
| `0x0052ada0` | `CVOGCharacter_GetResourceBalanceByType` | character resource/rank balance |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + thiscall + RET 4 + bool AL | **High** | disasm + bytes + call-site ECX/TEST AL |
| Map/end globals same as parent dual | **High** | immediate operands |
| Copy size/source 0x1FC from node+0x10 | **High** | `0x7f`/`REP MOVSD`/`+0x10` |
| Five-slot OR prereq + all-`-1` pass | **High** | dual exits + `JGE` success + all-`-1` tail |
| Min level short @ `+0x26` vs vtbl+0x27c | **High** | `MOVSX`/`JL` |
| Domain = discipline learn requirements | **High** | explicit UI string + Discipline map |
| Product method English | **Open** | `_Inferred` hygiene |
| vtbl+0x27c product name (GetLevel) | **Open** | sealed slot; English from other duals only |
| Whether balance unit is “rank” vs resource count | **Med** | uses dualed GetResourceBalanceByType; product word open |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps / open

1. Product/PDB method English for this gate and for vtbl `+0x27c`.  
2. Full DisciplineDef `0x1FC` schema beyond prereq/level fields used here (name `@+0x2A` sealed on parent dual).  
3. Semantic English for balance thresholds (rank vs points).  
4. Runtime Confirmed / differential / live map contents.  
5. Scaffold alias `Named_CalleeOf_Skill_i_w_skill_2d_wnd_description_xml_0052b140` — UI window is a consumer, not the unit identity.

**Verdict:** **accept-with-gaps** — CF/ABI/map/prereq-OR/level/domain High; product English + full schema + runtime open.
