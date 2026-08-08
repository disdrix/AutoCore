# Dual A/B report — R13-040 OWN-ONLY (`0x00573ce0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-040** (dual start **2686**)  
**Scope:** VA `0x00573ce0` (`aa_00573ce0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent find `00573a90` re-dual, sibling erase `00573d50`, friends TFID `005739d0`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-040**.  
**System:** skills-abilities (partition assignment; live role is social ignore-list mutator).  
**Parent dual:** `0x00573a90` `IgnoreList_FindEntryByTfid_Inferred` (R12-025).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00573ce0` IgnoreList_EraseEntriesByTfid_Inferred | **accept-with-gaps** — thiscall RET0x10 / vector+0x38+0x3c / TFID@+8/+0xc / delete+compact multi-erase / sole remove-ignore caller sealed; product host class + unused-arg English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): cast-math / find-merge / first-only / friends-merge / +0x28-sibling-merge / RET0x8 / noreturn-delete / non-zero-return / name-stricmp claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00573ce0` — sealed facts

1. **Body:** `0x00573ce0`–`0x00573d4c` exclusive (**108 B** / `0x6c`); terminal **`C2 10 00`**; pad `CC` before `FUN_00573d50` @ `0x00573d50`.
2. **ABI:** **`__thiscall`** — **ECX=list host**, stack **`int unused1, int unused2, int tfid_lo, int tfid_hi`**; **RET 0x10**; EAX = **0** always.
3. **Semantics:** MSVC pointer-vector **linear erase-all-by-TFID**:
   - begin=`*(this+0x38)`, end=`*(this+0x3c)`; empty begin==end → return 0.
   - For each slot: match `entry+8==tfid_lo && entry+0xc==tfid_hi`.
   - Hit → `operator_delete(entry)` if non-null (cdecl, **returns**), `*slot=0`, `memmove` compact, `end-=4`, **do not advance cursor** (multi-match).
   - Miss → advance slot by one pointer.
4. **Callees:** `operator_delete` @ `0x00489822`; `memmove` via IAT `DAT_009c652c`.
5. **Callers / xrefs (1):**
   - `FUN_0080eeb0` @ `0x0080ef7c` — remove-from-ignore residual; after find `FUN_00573a90` + English *"has been removed from your ignore list"*; ECX multi-list host; optional `CDlgTabsSocial` refresh.
6. **Sibling contrast:**
   - dualed `IgnoreList_FindEntryByTfid_Inferred` `0x00573a90` — **same +0x38**, read-only, **RET 0x8** — **do not merge**.
   - undualed `FUN_00573d50` — same erase plate at **+0x28** — **do not merge**.
   - undualed `FUN_005739d0` — friends TFID find at **+0x8** — **do not merge**.
7. **Name:** `IgnoreList_EraseEntriesByTfid_Inferred` (Ghidra `FUN_00573ce0`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; RET 0x10 + false-noreturn correction sealed via `disassemble_function` + `read_memory`.
9. **Partition parent** `0x00573a90` is dualed ignore TFID find (same multi-list host family).
10. **Partition system tag** `skills-abilities` is residual nest only; live role is **UI/social ignore list**.

### Gaps

- Product / MSVC demangle for multi-list host and entry type.  
- Semantic origin of unused stack arg1/arg2 (caller still pushes them).  
- Full entry layout beyond TFID@+8/+0xc and name@+0x10 (from find sibling).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00573ce0_IgnoreList_EraseEntriesByTfid_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00573ce0_IgnoreList_EraseEntriesByTfid_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00573ce0_FUN_00573ce0.md` |
| Annotated | `docs/reconstruction/raw/aa_00573ce0_FUN_00573ce0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/IgnoreList_EraseEntriesByTfid_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00573ce0.cpp` |
| Function | `docs/reconstruction/functions/aa_00573ce0_FUN_00573ce0.md` |
| Function named | `docs/reconstruction/functions/aa_00573ce0_IgnoreList_EraseEntriesByTfid_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0080eeb0  remove-from-ignore residual
  ├─ IgnoreList_FindEntryByTfid_Inferred (0x00573a90)  [dualed R12-025 — parent]
  │    hit + entry+0x10 → "has been removed from your ignore list"
  └─ IgnoreList_EraseEntriesByTfid_Inferred (0x00573ce0)  [OWN R13-040]
       delete+compact all TFID matches on vector +0x38
       └─ optional CDlgTabsSocial refresh

Contrast (do not merge):
  FUN_00573d50  erase plate @ +0x28/+0x2c
  FUN_005739d0  friends TFID find @ +0x8
  NameTable_FindEntryByNameI_Inferred @ 0x00573af0  (+0x38, name@+0x10)
```

Partition host "skills-abilities" names the **residual score nest**, not this leaf's product role (social ignore erase).

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00573ce0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00573ce0` | Port as **ignore-list linear TFID erase-all**: vector begin/end @ **+0x38/+0x3c**, TFID @ **entry+8/+0xc**, free+compact, no cursor advance after erase. **`__thiscall` + RET 0x10** (four stack dwords; body uses only last two). Always returns 0. |
| Distinct from | `00573a90` find-only (RET 0x8); `00573d50` erase @ +0x28; `005739d0` friends TFID find @ +0x8. |
| Pair with | parent find `00573a90`; remove-ignore residual `0080eeb0`; host multi-list (`[client+0x31ec]` / `DAT_00d1da2c` family). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `IgnoreList_EraseEntriesByTfid_Inferred` @ `0x00573ce0` / `aa_00573ce0`.
- Verdict: **accept-with-gaps**; Terminal **false**.
- System retag suggestion: **UI/social** (not skill-cast core).

---

## Process

- OWN VA only (`0x00573ce0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + caller decompile/context for role. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (thiscall RET 0x10; unused args 1–2; false-noreturn fixed).
- Odd behavior preserved: always return 0; multi-match via no-advance; four-arg stack with two unread.
- `_Inferred` where product class unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
