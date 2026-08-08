# Dual A/B report — R11-005 OWN-ONLY (`0x00573a30`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-005**  
**Scope:** VA `0x00573a30` (`aa_00573a30`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-005**.  
**Work item:** Residual dual seal — friends-list case-insensitive name find (vector @+0x8, name @entry+0x1a).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00573a30` FriendsList_FindEntryByNameI_Inferred | **accept-with-gaps** — thiscall RET0x4 / vector+0x8+0xc / name@+0x1a / `_stricmp` / 3 friends callers sealed; product host class open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): cast-math / strcmp / binary-search / sibling-merge(+0x10) / index-return / mutate claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00573a30` — sealed facts

1. **Body:** `0x00573a30`–`0x00573a8b` exclusive (**91 B** / `0x5B`); dual terminal **`C2 04 00`**; pad `CC` before `FUN_00573a90` @ `0x00573a90`.
2. **ABI:** **`__thiscall`** — **ECX=list host**, stack **`char *name`**; **RET 0x4**; EAX = entry* | 0.
3. **Semantics:** MSVC pointer-vector **linear find**:
   - begin=`*(this+0x8)`, end=`*(this+0xc)`; count=`(end-begin)>>2` or 0 if begin==0.
   - For i in 0..count-1: `_stricmp(entry+0x1a, name)`; hit → return entry*.
   - Miss → 0.
4. **Callee:** `_stricmp` via IAT `[0x009c6678]` (`MOV EBP,[IAT]; CALL EBP; ADD ESP,8`).
5. **Callers / xrefs (3):**
   - `FUN_0082f9a0` `UI_InteractionMenu_AddFriendsToggle` @ `0x0082f9de` (dualed; `DAT_00d1da2c`).
   - `FUN_0094d900` @ `0x0094d9d5` (`/friend`; already-friend vs add).
   - `FUN_00830010` case `0x1117a` @ `0x008304fe` (Remove Friends → TFID `entry+8/+0xc`).
6. **Sibling contrast:** dualed `NameTable_FindEntryByNameI_Inferred` `0x00573af0` uses **+0x38/+0x3c** and name@**+0x10** — **do not merge**.
7. **Name:** `FriendsList_FindEntryByNameI_Inferred` (Ghidra `FUN_00573a30`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; RET 0x4 + thiscall sealed via `disassemble_function` + `read_memory`.
9. **Partition parent** `0x0082f9a0` is both wave score parent and live structural caller.
10. **Partition system tag** `skills-abilities` is residual nest only; live role is **UI/social friends list**.

### Gaps

- Product / MSVC demangle for friends-list host (`DAT_00d1da2c`) and entry type.  
- Full entry layout before name@+0x1a.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00573a30_FriendsList_FindEntryByNameI_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00573a30_FriendsList_FindEntryByNameI_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00573a30_FUN_00573a30.md` |
| Annotated | `docs/reconstruction/raw/aa_00573a30_FUN_00573a30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FriendsList_FindEntryByNameI_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00573a30.cpp` |
| Function | `docs/reconstruction/functions/aa_00573a30_FUN_00573a30.md` |
| Function named | `docs/reconstruction/functions/aa_00573a30_FriendsList_FindEntryByNameI_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
UI_InteractionMenu_PopulateTargetButtons (0x0082fe20)  [dualed]
  └─ UI_InteractionMenu_AddFriendsToggle (0x0082f9a0)  [dualed MEGA-075]
        └─ FUN_00573a30 (DAT_00d1da2c, name)  [OWN R11-005]
              └─ _stricmp(entry+0x1a, name)

FUN_00830010  interaction button dispatcher
  case 0x11177 Add Friends → FUN_0094d900
  case 0x1117a Remove Friends → FUN_00573a30 → FUN_0094c680(entry+8,+0xc)
  case 0x1117c Ignore path → FUN_00573af0 (sibling; different vector)

FUN_0094d900  /friend residual
  └─ FUN_00573a30 → already-friend msg | add packet 0x801f

Contrast (do not merge):
  NameTable_FindEntryByNameI_Inferred @ 0x00573af0  (+0x38, name@+0x10)
  FUN_00573a90  TFID pair scan @ +0x38
```

Partition host "skills-abilities" names the **residual score nest**, not this leaf's product role (social friends).

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00573a30-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00573a30` | Port as **friends-list linear name find**: vector begin/end @ **+0x8/+0xc**, name @ **entry+0x1a**, **`_stricmp`**, return entry* \| null. **`__thiscall` + RET 0x4**. |
| Distinct from | `00573af0` NameTable find (+0x38 / +0x10); `00573a90` TFID scan. |
| Pair with | dualed friends toggle `0082f9a0`; residual `/friend` `0094d900`; button dispatcher `00830010`; host `DAT_00d1da2c`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `FriendsList_FindEntryByNameI_Inferred` @ `0x00573a30` / `aa_00573a30`.
- Verdict: **accept-with-gaps**; Terminal **false**.
- System retag suggestion: **UI/social** (not skill-cast core).

---

## Process

- OWN VA only (`0x00573a30`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + caller decompiles for role. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (thiscall RET 0x4; name@+0x1a).
- Odd behavior preserved: O(n) first-match; empty begin short-circuit; case-insensitive only.
- `_Inferred` where product class unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
