# Review A (reconstruction fidelity): `aa_00423170` OleDb_ReleaseAccessorHandle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423170` |
| **VA** | `0x00423170` (0x00423170-0x004231c8) |
| **Canonical name** | `OleDb_ReleaseAccessorHandle_Inferred` |
| **Ghidra name** | `FUN_00423170` |
| **Prior alias** | `Named_CalleeOf_Mission_bActiveObjectiveOverride_00423170` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00423170_OleDb_ReleaseAccessorHandle_Inferred.md` |
| **System** | COM / OLE DB IAccessor |
| **Live tools** | Ghidra HTTP `batch_decompile` / `read_memory` / callers / callees / xrefs (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Parent ensure** | `Skill_DbLoadSkillsCharacters` `aa_007e34b0` nested (or shared DbLoad plumbing) |

---

## 1. Purpose

Release a **single** accessor handle on owner (`ESI`: `[0]=IUnknown*`, `[1]=handle`):

1. If handle and iface set: init com_ptr; QI IID_IAccessor; on success `ReleaseAccessor` at vtbl+0x18; clear handle; Release pAcc.
2. If owner iface still set: null and Release via vtbl+8.

Sibling of array releaser `00422de0`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x00423170` (2026-07-29) ≡ raw |
| Raw / annotated / clean | `raw/aa_00423170_*`, `reconstructed-exact/FUN_00423170.cpp` |
| Function record | `functions/aa_00423170_*.md` |
| Parent dual | `reviews/A_aa_007e34b0_Skill_DbLoadSkillsCharacters.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Same IID_IAccessor as 00422de0 | **Confirmed** | DAT_00a860ac |
| Releases one handle then owner iface | **High** | body order |
| vtbl+0x18 ReleaseAccessor | **High** | same slot as array path |
| No-op when handle or iface null | **High** | outer guards |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Body CF from scaffold clean | **Yes** |
| Live batch_decompile ≡ raw 2026-07-23 | **Yes** |
| No modernization | **Yes** |

---

## 5. Gaps

1. Owner product type.
2. Decompiler param_1 / local_4 reuse as QI out.

**Verdict:** Structural contract sealed from live decompile + xrefs. Product type names remain inferred. **accept-with-gaps.**
