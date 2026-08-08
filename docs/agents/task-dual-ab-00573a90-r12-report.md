# Dual A/B report — R12-025 OWN-ONLY (`0x00573a90`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-025** (dual start **2646**)  
**Scope:** VA `0x00573a90` (`aa_00573a90`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-025**.  
**Work item:** Residual dual seal — ignore-list exact TFID-pair find (vector @+0x38, TFID @entry+8/+0xc).  
**Parent dual (evidence only):** `0x00573a30` `FriendsList_FindEntryByNameI_Inferred`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00573a90` IgnoreList_FindEntryByTfid_Inferred | **accept-with-gaps** — thiscall RET0x8 / vector+0x38+0x3c / TFID@+8/+0xc / 5 ignore-role callers sealed; product host class open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): cast-math / name-stricmp / binary-search / friends-merge(+0x8) / name-sibling-merge / index-return / mutate claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00573a90` — sealed facts

1. **Body:** `0x00573a90`–`0x00573ae7` exclusive (**87 B** / `0x57`); dual terminal **`C2 08 00`**; pad `CC` before `FUN_00573af0` @ `0x00573af0`.
2. **ABI:** **`__thiscall`** — **ECX=list host**, stack **`int tfid_lo, int tfid_hi`**; **RET 0x8**; EAX = entry* | 0.
3. **Semantics:** MSVC pointer-vector **linear find**:
   - begin=`*(this+0x38)`, end=`*(this+0x3c)`; count=`(end-begin)>>2` or 0 if begin==0.
   - For i in 0..count-1: match `entry+8==tfid_lo && entry+0xc==tfid_hi`; hit → return entry*.
   - Miss → 0.
4. **Callees:** **none** (leaf).
5. **Callers / xrefs (5):**
   - `FUN_0080eeb0` @ `0x0080eee1` — remove-from-ignore; English *"has been removed from your ignore list"* via `entry+0x10`.
   - `FUN_0080a170` @ `0x0080a2ac` — trade residual; hit → auto-refuse.
   - `FUN_0080fa50` @ `0x0080fabb` — convoy invite; hit → auto-decline `0x8006`.
   - `Client_RecvBroadcast` @ `0x00810ceb` — float-text only if **not** listed.
   - `FUN_005740f0` @ `0x00574101` — insert-if-missing residual.
6. **Sibling contrast:**
   - dualed `FriendsList_FindEntryByNameI_Inferred` `0x00573a30` — **+0x8**, name@**+0x1a** — **do not merge**.
   - dualed `NameTable_FindEntryByNameI_Inferred` `0x00573af0` — **same +0x38**, name@**+0x10** — **do not merge keys**.
   - undualed `FUN_005739d0` — friends TFID twin at **+0x8** — **do not merge**.
7. **Name:** `IgnoreList_FindEntryByTfid_Inferred` (Ghidra `FUN_00573a90`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; RET 0x8 + thiscall sealed via `disassemble_function` + `read_memory`.
9. **Partition parent** `0x00573a30` is dualed friends name find (score parent + same multi-list host family).
10. **Partition system tag** `skills-abilities` is residual nest only; live role is **UI/social ignore list**.

### Gaps

- Product / MSVC demangle for multi-list host (`DAT_00d1da2c`) and entry type.  
- Full entry layout beyond TFID@+8/+0xc and name@+0x10.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00573a90_IgnoreList_FindEntryByTfid_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00573a90_IgnoreList_FindEntryByTfid_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00573a90_FUN_00573a90.md` |
| Annotated | `docs/reconstruction/raw/aa_00573a90_FUN_00573a90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/IgnoreList_FindEntryByTfid_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00573a90.cpp` |
| Function | `docs/reconstruction/functions/aa_00573a90_FUN_00573a90.md` |
| Function named | `docs/reconstruction/functions/aa_00573a90_IgnoreList_FindEntryByTfid_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0080eeb0  remove-from-ignore residual
  └─ FUN_00573a90(tfid)  [OWN R12-025]
       hit → "has been removed from your ignore list" (entry+0x10)
       └─ FUN_00573ce0(...) table mutate residual

FUN_0080a170  trade residual
  └─ FUN_00573a90 → hit auto-refuse

FUN_0080fa50  convoy invite residual
  └─ FUN_00573a90 → hit auto-decline 0x8006 | miss invite UI

Client_RecvBroadcast (0x00810a80)  [dualed]
  └─ FUN_00573a90(object_tfid) → miss only → float-text bubble

FUN_005740f0  insert-if-missing residual
  └─ FUN_00573a90 → 0 then FUN_005746e0

Contrast (do not merge):
  FriendsList_FindEntryByNameI_Inferred @ 0x00573a30  (+0x8, name@+0x1a)
  FUN_005739d0  friends TFID twin (+0x8)
  NameTable_FindEntryByNameI_Inferred @ 0x00573af0  (+0x38, name@+0x10)
  UI_InteractionMenu_AddIgnoreToggle @ 0x0082f8d0  [dualed] uses name twin
```

Partition host "skills-abilities" names the **residual score nest**, not this leaf's product role (social ignore).

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00573a90-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00573a90` | Port as **ignore-list linear TFID find**: vector begin/end @ **+0x38/+0x3c**, TFID @ **entry+8/+0xc**, return entry* \| null. **`__thiscall` + RET 0x8**. |
| Distinct from | `00573a30` friends name (+0x8 / +0x1a); `005739d0` friends TFID (+0x8); `00573af0` ignore name (+0x38 / +0x10). |
| Pair with | remove-ignore `0080eeb0`; trade residual `0080a170`; convoy `0080fa50`; dualed broadcast `00810a80`; host `DAT_00d1da2c`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `IgnoreList_FindEntryByTfid_Inferred` @ `0x00573a90` / `aa_00573a90`.
- Verdict: **accept-with-gaps**; Terminal **false**.
- System retag suggestion: **UI/social** (not skill-cast core).

---

## Process

- OWN VA only (`0x00573a90`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + caller decompiles for role. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (thiscall RET 0x8; TFID@+8/+0xc).
- Odd behavior preserved: O(n) first-match; empty begin short-circuit; exact int equality only.
- `_Inferred` where product class unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
