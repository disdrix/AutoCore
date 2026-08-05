# Review A (reconstruction fidelity): `aa_0041c000` OleDb_RebindAccessor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041c000` |
| **VA** | `0x0041c000` (0x0041c000-~0x0041c090) |
| **Canonical name** | `OleDb_RebindAccessor_Inferred` |
| **Ghidra name** | `FUN_0041c000` |
| **Prior alias** | `Named_CalleeOf_Mission_bActiveObjectiveOverride_0041c000` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0041c000_OleDb_RebindAccessor_Inferred.md` |
| **System** | COM / OLE DB accessor bind |
| **Live tools** | Ghidra HTTP `batch_decompile` / `read_memory` / callers / callees / xrefs (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Parent ensure** | `Skill_DbLoadSkillsCharacters` `aa_007e34b0` nested (or shared DbLoad plumbing) |

---

## 1. Purpose

Rebind an **accessor handle** on a COM holder (`in_EAX`):

1. If `h[3] != 0`: call `vtbl+0x18` to clear prior handle (ReleaseAccessor shape).
2. `hr = (vtbl+0x14)(*h, 0, param_1, flag? +1 : -1, &status, &handleSlot)`.
3. If `hr==0` and `FUN_004205e0() < 0` and handle still set: ReleaseAccessor again.
4. Return hr.

`FUN_004205e0` walks binding table and invokes `vtbl+0x10` per entry (validation follow-up).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x0041c000` (2026-07-29) ≡ raw |
| Raw / annotated / clean | `raw/aa_0041c000_*`, `reconstructed-exact/FUN_0041c000.cpp` |
| Function record | `functions/aa_0041c000_*.md` |
| Parent dual | `reviews/A_aa_007e34b0_Skill_DbLoadSkillsCharacters.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Prior handle released via vtbl+0x18 before rebind | **High** | guard on h[3] |
| param_2 maps to ±1 third arg | **High** | (param_2!=0)*2-1 |
| Failure path re-releases handle | **High** | FUN_004205e0 < 0 gate |
| Shared DB-load helper | **Confirmed** | many DbLoad callers |
| Exact method names at +0x14/+0x18 | **Medium** | +0x18 ReleaseAccessor-shaped; +0x14 tentative |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Body CF from scaffold clean | **Yes** |
| Live batch_decompile ≡ raw 2026-07-23 | **Yes** |
| No modernization | **Yes** |

---

## 5. Gaps

1. Product names for vtbl +0x14 / +0x10 methods.
2. Type of param_1 (bindings blob vs column id).
3. Holder layout beyond [0] iface / [3] handle.

**Verdict:** Structural contract sealed from live decompile + xrefs. Product type names remain inferred. **accept-with-gaps.**
