# Dual A/B report — R13-039 OWN-ONLY (`0x005739d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-039** (dual start **2686**)  
**Scope:** VA `0x005739d0` (`aa_005739d0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-039**.  
**Work item:** Residual dual seal — friends-list exact TFID-pair find (vector @+0x8, TFID @entry+8/+0xc).  
**Parent dual (evidence only):** `0x00573a90` `IgnoreList_FindEntryByTfid_Inferred`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005739d0` FriendsList_FindEntryByTfid_Inferred | **accept-with-gaps** — thiscall RET0x8 / vector+0x8+0xc / TFID@+8/+0xc / 3 friends-role callers sealed; product host class open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): cast-math / name-stricmp / binary-search / ignore-merge(+0x38) / name-sibling-merge / index-return / mutate claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005739d0` — sealed facts

1. **Body:** `0x005739d0`–`0x00573a28` exclusive (**88 B** / `0x58`); dual terminal **`C2 08 00`**; pad `CC` before `FUN_00573a30` @ `0x00573a30`.
2. **ABI:** **`__thiscall`** — **ECX=list host**, stack **`int tfid_lo, int tfid_hi`**; **RET 0x8**; EAX = entry* | 0.
3. **Semantics:** MSVC pointer-vector **linear find**:
   - begin=`*(this+0x8)`, end=`*(this+0xc)`; count=`(end-begin)>>2` or 0 if begin==0.
   - For i in 0..count-1: match `entry+8==tfid_lo && entry+0xc==tfid_hi`; hit → return entry*.
   - Miss → 0.
4. **Callees:** **none** (leaf; `analyze_function_complete` classification `leaf`).
5. **Callers / xrefs (3):**
   - `FUN_0080f3b0` @ `0x0080f3f5` — friend presence residual; English *"Your friend"*; name via `entry+0x1a`; enemy branch uses `FUN_00573b50` + *"Your enemy"*.
   - `FUN_00574020` @ `0x00574031` — insert-if-missing residual; miss → `FUN_005746e0`.
   - `FUN_00574270` @ `0x00574281` — insert-if-missing residual twin; miss → `FUN_005746e0`.
6. **Sibling contrast:**
   - dualed `FriendsList_FindEntryByNameI_Inferred` `0x00573a30` — **same +0x8**, name@**+0x1a** — **do not merge keys**.
   - dualed `IgnoreList_FindEntryByTfid_Inferred` `0x00573a90` — **+0x38**, TFID@**+8/+0xc** — **do not merge vectors**.
   - dualed `NameTable_FindEntryByNameI_Inferred` `0x00573af0` — **+0x38**, name@**+0x10** — **do not merge**.
7. **Name:** `FriendsList_FindEntryByTfid_Inferred` (Ghidra `FUN_005739d0`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; RET 0x8 + thiscall sealed via `disassemble_function` + `read_memory`.
9. **Partition parent** `0x00573a90` is dualed ignore TFID find (score parent + algorithm twin on different vector).
10. **Partition system tag** `skills-abilities` is residual nest only; live role is **UI/social friends list**.

### Gaps

- Product / MSVC demangle for multi-list host (`DAT_00d1da2c`) and entry type.  
- Full entry layout beyond TFID@+8/+0xc and name@+0x1a.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005739d0_FriendsList_FindEntryByTfid_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005739d0_FriendsList_FindEntryByTfid_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005739d0_FUN_005739d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005739d0_FUN_005739d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FriendsList_FindEntryByTfid_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005739d0.cpp` |
| Function | `docs/reconstruction/functions/aa_005739d0_FUN_005739d0.md` |
| Function named | `docs/reconstruction/functions/aa_005739d0_FriendsList_FindEntryByTfid_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0080f3b0  friend/enemy presence residual
  flag==0 → FUN_00573b50(tfid)  [enemy twin; not OWN]
       hit → "Your enemy" + entry+0x23
  flag!=0 → FUN_005739d0(tfid)  [OWN R13-039]
       hit → "Your friend" + entry+0x1a
       └─ "come online." / "gone offline." floater

FUN_00574020  insert-if-missing residual
  └─ FUN_005739d0 → 0 then FUN_005746e0

FUN_00574270  insert-if-missing residual twin
  └─ FUN_005739d0 → 0 then FUN_005746e0

Contrast (do not merge):
  FriendsList_FindEntryByNameI_Inferred @ 0x00573a30  (+0x8, name@+0x1a)
  IgnoreList_FindEntryByTfid_Inferred @ 0x00573a90  (+0x38, TFID)  [partition parent]
  NameTable_FindEntryByNameI_Inferred @ 0x00573af0  (+0x38, name@+0x10)
  FUN_00573b50  enemy TFID twin (presence residual contrast)
```

Partition host "skills-abilities" names the **residual score nest**, not this leaf's product role (social friends).

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005739d0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005739d0` | Port as **friends-list linear TFID find**: vector begin/end @ **+0x8/+0xc**, TFID @ **entry+8/+0xc**, return entry* \| null. **`__thiscall` + RET 0x8**. |
| Distinct from | `00573a30` friends name (+0x8 / +0x1a); `00573a90` ignore TFID (+0x38); `00573af0` ignore name (+0x38 / +0x10). |
| Pair with | presence residual `0080f3b0`; insert helpers `00574020` / `00574270`; host `DAT_00d1da2c`; dualed friends name `00573a30`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `FriendsList_FindEntryByTfid_Inferred` @ `0x005739d0` / `aa_005739d0`.
- Verdict: **accept-with-gaps**; Terminal **false**.
- System retag suggestion: **UI/social** (not skill-cast core).

---

## Process

- OWN VA only (`0x005739d0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + caller decompiles for role. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (thiscall RET 0x8; TFID@+8/+0xc; vector@+0x8).
- Odd behavior preserved: O(n) first-match; empty begin short-circuit; exact int equality only.
- `_Inferred` where product class unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
