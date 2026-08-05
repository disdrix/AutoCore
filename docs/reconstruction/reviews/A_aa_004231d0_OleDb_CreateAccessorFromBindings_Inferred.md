# Review A (reconstruction fidelity): `aa_004231d0` OleDb_CreateAccessorFromBindings_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004231d0` |
| **VA** | `0x004231d0` (0x004231d0-~0x00423260) |
| **Canonical name** | `OleDb_CreateAccessorFromBindings_Inferred` |
| **Ghidra name** | `FUN_004231d0` |
| **Prior alias** | `Named_CalleeOf_Mission_bActiveObjectiveOverride_004231d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004231d0_OleDb_CreateAccessorFromBindings_Inferred.md` |
| **System** | COM / OLE DB IAccessor |
| **Live tools** | Ghidra HTTP `batch_decompile` / `read_memory` / callers / callees / xrefs (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Parent ensure** | `Skill_DbLoadSkillsCharacters` `aa_007e34b0` nested (or shared DbLoad plumbing) |

---

## 1. Purpose

**Create** an accessor from a binding descriptor (inverse of release helpers).

1. Init com_ptr; QI `param_2` for IID_IAccessor.
2. Fail -> cleanup + return hr.
3. `FUN_004232c0` binding prep.
4. Mark binding entry active (`*(slot+4)=1`).
5. Call `vtbl+0x10` (**CreateAccessor** slot on IAccessor).
6. Decompiler `operator_delete` noreturn tail is residual/SEH noise.

Heavy use from DB column-bind sites (`FUN_007c0350` many xrefs).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x004231d0` (2026-07-29) ≡ raw |
| Raw / annotated / clean | `raw/aa_004231d0_*`, `reconstructed-exact/FUN_004231d0.cpp` |
| Function record | `functions/aa_004231d0_*.md` |
| Parent dual | `reviews/A_aa_007e34b0_Skill_DbLoadSkillsCharacters.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| IID_IAccessor shared with release path | **Confirmed** | DAT_00a860ac |
| vtbl+0x10 is CreateAccessor slot | **High** | IAccessor layout |
| Fail QI returns hr after cleanup | **High** | early return |
| Marks binding entry active (byte=1) | **High** | store 1 at slot+4 |
| Decompiler noreturn delete is residual | **Medium** | WARNING in raw |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Body CF from scaffold clean | **Yes** |
| Live batch_decompile ≡ raw 2026-07-23 | **Yes** |
| No modernization | **Yes** |

---

## 5. Gaps

1. Full stack formals (decompiler unaff_retaddr noise).
2. FUN_004232c0 body dual not in this batch.
3. operator_delete tail bit-exact cleanup.

**Verdict:** Structural contract sealed from live decompile + xrefs. Product type names remain inferred. **accept-with-gaps.**
