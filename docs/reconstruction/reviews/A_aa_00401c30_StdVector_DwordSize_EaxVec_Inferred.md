# Review A (reconstruction fidelity): `aa_00401c30` StdVector_DwordSize_EaxVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401c30` |
| **VA** | `0x00401c30`–`0x00401c42` inclusive (**19 B** / `0x13`) |
| **Canonical name** | `StdVector_DwordSize_EaxVec_Inferred` |
| **Ghidra name** | `FUN_00401c30` |
| **Prior scaffold** | `FUN_00401c30` / `Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_00401c30` |
| **Rejected misname** | `Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_00401c30` (xref-seed false) |
| **Review date** | `2026-08-05` (MEGA-082 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00401c30_StdVector_DwordSize_EaxVec_Inferred.md` |
| **System** | containers / shared dword-vector size |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + parent decompile `FUN_008d4910`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Thin **`vector<uint32_t|T*>::size()`** helper with **EAX** = container:

```text
if (*(vec+4) == 0) return 0;          // begin null
return (*(vec+8) - *(vec+4)) >> 2;    // (end - begin) / 4
```

Layout: **begin @ +4**, **end @ +8** (capacity not read). Leaf — no callees.

Multi-domain callers (sample): `FUN_008b6eb0` (list size vs scroll), `FUN_008d4910` case `0x9c45` (char-create / vehicle panel; plate parent of `"Your Vehicle Name Is Invalid!  Please Choose Another!"`), orphan UI loop hosts at `+0x5a0` / `DAT_00d1ad2c+0x14`.

**Not** capacity, not floater 0x38 size, not skill-set 0x18 size (`SkillSet_GetEntryCount` @ `0x00402d80`), **not** the ECX twin `StdVector_DwordSize` @ `0x004024b0`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold CF (null begin → 0; else SAR 2) |
| Full body | `disassemble_function` + `read_memory` 19 B body + CC pad |
| Twin | dualed `StdVector_DwordSize` `0x004024b0` (ECX ABI) |
| Callers | 11 UNCONDITIONAL_CALL; `FUN_008b6eb0`, `FUN_008d4910`, orphan sites |
| Call-site ABI | all sites `MOV EAX,<vec>` before CALL |
| Plate string | `"Your Vehicle Name Is Invalid!  Please Choose Another!"` @ `0x00a3fba4` (parent only) |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Signature (sealed)

```c
// EAX=vec; bare RET; size in EAX
int StdVector_DwordSize_EaxVec_Inferred(void *vec /*EAX*/);
```

| Formal | Source | Conf |
|---|---|---|
| vec | **EAX** → loads `[EAX+4]` / `[EAX+8]` | **Confirmed** |
| return | EAX = count | **Confirmed** |
| cleanup | bare `RET` (`C3`) ×2 | **Confirmed** |
| begin / end | +4 / +8 | **Confirmed** |
| stride | `SAR EAX,2` → 4 | **Confirmed** |
| null begin | `TEST ECX; JNZ; XOR EAX,EAX; RET` | **Confirmed** |
| callees | none | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Load begin from `[EAX+4]` into ECX | bytes `8B 48 04` | **Confirmed** |
| Null → 0 early exit | `TEST` / `XOR` / `RET` | **Confirmed** |
| Load end, SUB, SAR 2 | `8B 40 08 2B C1 C1 F8 02` | **Confirmed** |
| No invent capacity field | no `[EAX+0xC]` | **Confirmed** |
| Decompile ≡ raw ≡ live | yes | **Confirmed** |

```c
int StdVector_DwordSize_EaxVec_Inferred(void *vec) {
  int begin = *(int *)((char *)vec + 4);
  if (begin == 0) return 0;
  return (*(int *)((char *)vec + 8) - begin) >> 2;
}
```

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf (shared container helper) |
| External xrefs | **11** UNCONDITIONAL_CALL |
| Named enclosing | `FUN_008b6eb0`, `FUN_008d4910` (+ orphan sites) |
| Site role | size query / loop upper bound / remainder divisor |
| Callees | **none** |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Structural size formula (begin/end >> 2) | **Yes** |
| EAX ABI distinct from dualed ECX twin `004024b0` | **Yes** |
| Multi-domain callers (not plate-string-only) | **Yes** |
| Product element / host English demangle | **No** → `_Inferred` |
| Drive vehicle-name plate in **this** body | **No** (parent only) |

**Decision:** promote **`StdVector_DwordSize_EaxVec_Inferred`**. Retire Named_CalleeOf plate scaffold.

---

## 7. Gaps

- Product English for element type / host container maps — open (structural name).
- Orphan xref sites without Ghidra function bounds — evidence via assembly context only.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path accepts CF/ABI/formula with only low-priority product-English residual → **accept**.
