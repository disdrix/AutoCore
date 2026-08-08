# Review A (reconstruction fidelity): `aa_0052b040` DisciplineDefMap_TryCopyPayloadById_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b040` |
| **VA** | `0x0052b040`–`0x0052b078` |
| **Canonical name (Ghidra)** | `FUN_0052b040` |
| **Proposed name** | `DisciplineDefMap_TryCopyPayloadById_Inferred` |
| **Review date** | `2026-08-05` (R12-020 OWN-ONLY dual A; dual start 2646) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0052b040_DisciplineDefMap_TryCopyPayloadById_Inferred.md` |
| **System** | `skills-abilities` (partition parent `0x00846820`) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Process-global **DisciplineDef map try-copy by int id**:

1. Exact-find `key` in map header **`0x00b045b0`** via **`FUN_00538ab0`** (nil `@node+0x20d`, key `@+0x0C`, `RET 8`).
2. If node == end **`DAT_00b045b4`** → `AL=0`, return (no write).
3. Else **`REP MOVSD`** **0x7f** dwords (**0x1FC** B) from **`node+0x10`** into caller out-buffer → `AL=1`.

Leaf used by tooltip/requirements UI (parent `"Discipline: "`), prereq helpers (`FUN_0052b140`), and many train/UI paths. **Not** SkillDefMap.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0052b040` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/locals/completeness) |
| Assembly | `disassemble_function` (body through dual `RET`; **not** `disassemble_bytes`) |
| Bytes | `read_memory` 64 B @ entry — hex seal + `CC` pad |
| Find callee | `decompile_function` + `disassemble_function` @ `FUN_00538ab0` |
| Callers / xrefs | `get_function_callers` (19) + `get_xrefs_to` (41 UNCONDITIONAL_CALL) |
| Parent context | `decompile_function` @ `0x00846820` site `0x00846c34` |
| Sibling contrast | SkillDefMap family (`DAT_00b04734`, duals `aa_00418890` / `aa_0054b480`); `CVOGCharacter_GetResourceBalanceByType` (`aa_0052ada0`) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact|functions` for `aa_0052b040` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledger edits.

---

## 3. Signature

```c
uint8_t __cdecl DisciplineDefMap_TryCopyPayloadById_Inferred(
    int disciplineId /* stack0 */,
    void *outPayload0x1FC /* stack1 */);
// bare RET; bool in AL
```

| Item | Evidence |
|---|---|
| Convention | bare `RET` @ `0x0052b078` / miss `0x0052b062`; call sites `ADD ESP,8` (e.g. `0x0052b1c0`) |
| Map hardcode | `MOV ECX,0xb045b0` before `CALL FUN_00538ab0` |
| End compare | `CMP EAX,[0xb045b4]` |
| Copy size | `MOV ECX,0x7f` + `REP MOVSD` from `LEA ESI,[EAX+0x10]` |
| Body size | 57 B (`0x39`); pad `CC` before `0x0052b080` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Find via `FUN_00538ab0` on global map | **Yes** |
| Miss if node == `DAT_00b045b4` → AL=0 | **Yes** |
| Hit → copy 0x1FC from node+0x10 → AL=1 | **Yes** |
| No insert/erase/alloc inside unit | **Yes** |
| cdecl (not thiscall/stdcall on this leaf) | **Yes** |

### Layout (sealed)

| Off | Role |
|----:|------|
| map `0x00b045b0` | header; head/end ptr at `+4` (= `DAT_00b045b4` symbol) |
| node `+0x0C` | int key |
| node `+0x10` | payload copy source |
| node `+0x20D` | isnil (via find helper) |
| out `+0x2A` | name source (parent UI evidence) |

### Call-site samples

| Site | Args | Follow-on |
|---|---|---|
| `0x00846c34` `FUN_00846820` | key=`*(item+0x4ac)`, out=`operator_new(0x1fc)` | `"Discipline: "` + `FUN_00403450(out+0x2a)` + `GetResourceBalanceByType` |
| `0x0052b1bb`…`0x0052b281` `FUN_0052b140` | key=prereq id fields; out=stack `0x1FC` scratch | `TEST AL,AL`; on hit `GetResourceBalanceByType` threshold compare |
| `0x0084acb7` `UI_BuildItemTooltipStats` | tooltip discipline line | (consumer UI) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI cdecl + bool AL | **High** | disasm + bytes + call-site cleanup |
| Map/end globals | **High** | immediate operands |
| Copy size/source | **High** | `0x7f`/`REP MOVSD`/`+0x10` |
| Distinct from SkillDefMap | **High** | different header/nil/size |
| Role = DisciplineDef try-copy | **High** | UI string + id field + resource pairing |
| Product method English | **Open** | `_Inferred` hygiene |
| Full payload schema | **Open** | only `+0x2A` name consumer sealed |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps / open

1. Product/PDB DisciplineDef / map method English.  
2. Full 0x1FC field schema beyond name `@+0x2A`.  
3. Runtime Confirmed / differential / cold map contents.  
4. Whether find helper alone enforces exact key (yes — lower_bound + `key <= search` pattern sealed on `FUN_00538ab0`; this leaf does not re-compare key).

**Verdict:** **accept-with-gaps** — CF/ABI/map/copy/domain High; product English + full schema + runtime open.
