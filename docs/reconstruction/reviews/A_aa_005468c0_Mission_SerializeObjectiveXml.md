# Review A (reconstruction fidelity): `aa_005468c0` Mission_SerializeObjectiveXml

| Field | Value |
|---|---|
| **Stable ID** | `aa_005468c0` |
| **VA** | `0x005468c0` |
| **Canonical name** | `Mission_SerializeObjectiveXml` (role-sealed from format strings) |
| **Ghidra name** | `FUN_005468c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005468c0_Mission_SerializeObjectiveXml.md` |
| **System** | `missions-progression` |
| **Parent chain** | Evidence nested from EvaluatePending threshold getter `FUN_0059d880` (XML dump uses same getter for `<CompleteCount>`) |
| **Dual status** | **Present** (first full A+B dual) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Write one objective definition to an open `FILE*` as XML**:

1. Stack0 / arg0 = `ObjectiveDef*`.
2. Stack1 / arg1 = `FILE*`.
3. Emit opening tag with wide name/map strings and id/sequence.
4. Emit optional `ExternalText` / `Title` / `DefaultText` (empty tags if null pointers).
5. Emit **`<CompleteCount>%i</CompleteCount>`** via **`FUN_0059d880(obj)`** → `*(obj+0x164)`.
6. For each evaluator in `[obj+0x158, obj+0x15c)`: vtable **`+0x54`** serialize into same file.
7. Emit closing `</Objective>`.

Primary reconstruction value for EvaluatePending dual: **proves CompleteCount field name and getter**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005468c0_FUN_005468c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005468c0_FUN_005468c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005468c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005468c0_FUN_005468c0.md` |
| Live decompile | ≡ raw |
| Threshold dual | `A/B_aa_0059d880_CVOGObjective_GetCompleteCount` |
| Parent dual | `A/B_aa_00534920_CVOGCharacter_EvaluatePendingObjectives` |
| Caller | `FUN_00546ad0` (mission XML dump parent) |

**Not performed:** full mission dump writer dual, Launcher.

---

## 3. ObjectiveDef fields sealed by format strings

| Access | Offset | XML / role | Conf |
|---|---|---|---|
| `*param_1` | `+0x0` | ExternalText (char*) | **High** |
| `param_1[1]` | `+0x4` | Title | **High** |
| `param_1[2]` | `+0x8` | DefaultText | **High** |
| `param_1[4]` | `+0x10` | ID | **High** |
| `*(byte*)(param_1+5)` | `+0x14` | sequence | **High** |
| wide name | `+0x16` area | name `%S` | **High** (pointer math) |
| wide map | `param_1+0x26` | map `%S` | **High** |
| `FUN_0059d880` | body `+0x164` | **CompleteCount** | **High** |
| `param_1[0x56]/[0x57]` | `+0x158/+0x15c` | evaluator vector | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| XML serializer for Objective | **High** | strings |
| CompleteCount via getter | **High** | same as EvaluatePending |
| Evaluator dump vtbl `+0x54` | **High** | loop |
| Side-effect free aside from FILE writes | **High** | |
| cdecl-ish two pointer args | **High** | decompile formals |
| Product PDB name | **Open** | strings give structural name |

---

## 5. Gaps

1. Exact wide-string buffer layouts at `+0x16` / `+0x26`.
2. Parent dump orchestrator dual (`FUN_00546ad0`) not this unit.
3. Runtime file capture open.

**Verdict:** Field map + CompleteCount evidence High. **accept-with-gaps.**
