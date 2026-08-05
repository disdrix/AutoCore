# Review A (reconstruction fidelity): `aa_007b8910` Com_BstrPropertyEquals_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b8910` |
| **VA** | `0x007b8910` (0x007b8910-0x007b8a5c) |
| **Canonical name** | `Com_BstrPropertyEquals_Inferred` |
| **Ghidra name** | `FUN_007b8910` |
| **Prior alias** | `Named_CalleeOf_Skill_DbLoadSkillsCharacters_007b8910` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_007b8910_Com_BstrPropertyEquals_Inferred.md` |
| **System** | COM / ADO field compare (DB load filters) |
| **Live tools** | Ghidra HTTP `batch_decompile` / `read_memory` / callers / callees / xrefs (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Parent ensure** | `Skill_DbLoadSkillsCharacters` `aa_007e34b0` nested (or shared DbLoad plumbing) |

---

## 1. Purpose

Compare a COM object's string property to an input **BSTR**; free/release both sides.

1. SEH; null obj -> `_com_issue_error(E_POINTER=0x80004003)`.
2. `FUN_00419f60` get property; if null -> Release obj, free rhs, return **false**.
3. Extract OLECHAR*; `SysAllocString` (OOM -> throw `FUN_004048e0`).
4. `FUN_00423620` -> **`VarBstrCmp(lhs, rhsCopy, 0x400, 0) == 1`**.
5. Free temps; Release prop+obj; free rhs; return bool.

Callers: `Skill_DbLoadSkillsCharacters`, many DbLoad*, `VehicleDb_LoadCloneBase`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x007b8910` (2026-07-29) ≡ raw |
| Raw / annotated / clean | `raw/aa_007b8910_*`, `reconstructed-exact/FUN_007b8910.cpp` |
| Function record | `functions/aa_007b8910_*.md` |
| Parent dual | `reviews/A_aa_007e34b0_Skill_DbLoadSkillsCharacters.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Equality via VarBstrCmp locale 0x400 | **High** | FUN_00423620 body |
| Null obj -> E_POINTER | **High** | 0x80004003 |
| Frees rhs BSTR always | **High** | both paths SysFreeString(param_2) |
| Returns false when property missing | **High** | null prop path |
| Shared across DB loaders | **Confirmed** | includes 007e34b0 + VehicleDb |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Body CF from scaffold clean | **Yes** |
| Live batch_decompile ≡ raw 2026-07-23 | **Yes** |
| No modernization | **Yes** |

---

## 5. Gaps

1. Which property ID FUN_00419f60 reads.
2. com_ptr helpers 00419ca0/00419e90 duals.
3. Locale 0x400 intentional vs invariant.

**Verdict:** Structural contract sealed from live decompile + xrefs. Product type names remain inferred. **accept-with-gaps.**
