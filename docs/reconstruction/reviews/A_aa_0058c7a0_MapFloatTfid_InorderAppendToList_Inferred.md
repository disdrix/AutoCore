# Review A (reconstruction fidelity): `aa_0058c7a0` MapFloatTfid_InorderAppendToList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058c7a0` |
| **VA** | `0x0058c7a0` |
| **Canonical name** | `MapFloatTfid_InorderAppendToList_Inferred` (was `FUN_0058c7a0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0058c7a0_MapFloatTfid_InorderAppendToList_Inferred.md` |
| **System** | `skills-abilities` (sort dump for `Skill_GatherTargetsInArea`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**In-order walk** of a float-keyed map/tree of TFID payloads and **append** each node’s **0x10-byte** value into a flat out-list (stride **0x10**), starting at index `param_4`, until tree end, hard cap **99**, or optional **maxTargets countdown** (`param_3`) hits 0.

Used only when `Skill_GatherTargetsInArea` **`param_14` (sort-by-distance) ≠ 0**: targets were inserted into a local distance map via `FUN_0058def0`; this unit dumps sorted order into the gather out-list.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0058c7a0_FUN_0058c7a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0058c7a0_FUN_0058c7a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0058c7a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0058c7a0_FUN_0058c7a0.md` |
| Parent dual | `reviews/A_aa_0058d330_Skill_GatherTargetsInArea.md` |
| Insert sibling | `FUN_0058def0` @ `0x0058def0` (own dual this batch) |
| Ghidra | `batch_decompile` + `analyze_function_complete` + callers |

**Live re-decompile 2026-07-29 ≡ raw.** Sole caller: `Skill_GatherTargetsInArea` @ `0x0058d82a`.

---

## 3. Signature

```c
// __cdecl (4 stack args); return = final written count (see note)
int MapFloatTfid_InorderAppendToList_Inferred(
    void* outListBase,   /* param_1: TFID[i] at base + i*0x10 */
    void* treeOrWrap,    /* param_2: has +4 → head node* */
    int maxCountdown,    /* param_3: 0 = unlimited; else decrement per append, stop <1 */
    int startIndex);     /* param_4: first slot index; also running count */
```

| Item | Notes | Conf |
|---|---|---|
| Stride **0x10** | `param_4 * 0x10 + param_1`; `piVar5 += 4` dwords | **High** |
| Cap **99** | `if (param_4 == 99) return` | **High** |
| Node value at **+0x18..+0x27** | stores `node[6..9]` → 4 dwords | **High** |
| MSVC-style successor | `+0x29` isnil; left=`[0]`, parent=`[1]`, right=`[2]` | **High** CF |
| Return count | Caller assigns `local_d4 = FUN_0058c7a0(...)`; decompiler shows `void` — **EAX residual High from call site** | **High** use / **Probable** exact epilogue |

### Node layout (family, CF)

| Off | Role |
|---:|---|
| +0x00 / +0x04 / +0x08 | left / parent / right |
| +0x10 | float key (used by insert; not copied here) |
| +0x18..+0x27 | TFID payload (4×u32) — **copied** |
| +0x29 | isnil (head/sentinel) |

Start: `node = **(int**)(param_2+4)` = leftmost under head; end when `node == head`.

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Empty tree → no writes | **Yes** |
| Copy 4 dwords payload; ++index | **Yes** |
| Stop at index==99 | **Yes** |
| Optional countdown `param_3` | **Yes** |
| Inorder successor via isnil / right-min / parent climb | **Yes** |
| Loop until back at head | **Yes** |
| No distance recompute / no filter | **Yes** |

### Parent call site (sort path)

```
if (param_14 != 0):
  local_d4 = FUN_0058c7a0(param_1, local_b0, param_7, (int)(short)local_d4)
// then write invalid terminator at local_d4 * 0x10
```

When sort flag clear, gather already wrote TFIDs directly; this unit is **sort dump only**.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Sole caller GatherTargetsInArea | **High** | single xref |
| Inorder dump sorted by prior float inserts | **High** | parent inserts with dist key then dump |
| Out-list stride 0x10 + cap 99 | **High** | matches gather contract |
| Does not allocate / free tree | **High** | leaf walk only |
| Product / STL symbol | **Inferred** | MSVC tree shape Probable; no RTTI |
| Exact return in EAX | **Probable** | call-site assign; decomp void |

---

## 6. Gaps / open

1. Exact ABI return (does epilogue mov EAX,param_4 on all exit paths?).
2. Whether `param_2` is tree object vs `{head*}` wrapper (`local_b0` shape).
3. Runtime multi-target sort order verification.
4. Product name.

**Verdict:** **accept-with-gaps**
