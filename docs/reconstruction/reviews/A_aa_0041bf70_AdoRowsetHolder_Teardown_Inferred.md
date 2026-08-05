# Review A (reconstruction fidelity): `aa_0041bf70` AdoRowsetHolder_Teardown_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041bf70` |
| **VA** | `0x0041bf70` (0x0041bf70-0x0041bff4) |
| **Canonical name** | `AdoRowsetHolder_Teardown_Inferred` |
| **Ghidra name** | `FUN_0041bf70` |
| **Prior alias** | `Named_CalleeOf_Skill_IDSkillBattleMode1_0041bf70` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0041bf70_AdoRowsetHolder_Teardown_Inferred.md` |
| **System** | COM / ADO-OLEDB DB load teardown |
| **Live tools** | Ghidra HTTP `batch_decompile` / `read_memory` / callers / callees / xrefs (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Parent ensure** | `Skill_DbLoadSkillsCharacters` `aa_007e34b0` nested (or shared DbLoad plumbing) |

---

## 1. Purpose

**Tear down** a DB rowset/command holder (decompiler `EDI` = this):

1. If `this[4] != 0` (binding/status slab):
   - If `this[0]`: `FUN_00422a90(*this)` then **`FUN_00422de0`** (release accessor handle array).
   - `FUN_0041b9f0()`; `operator_delete(this[4])`; `this[4]=0`.
2. If `this[0]` (primary COM iface):
   - If `this[3]` handle: `(*iface->vtbl+0x18)(iface,1,&this[3],0,0,0)` then clear - **ReleaseAccessor-shaped**.
   - Release `this[0]` and `this[1]` via vtbl+8.

Shared cleanup across many DbLoad* units (including peers of `007e34b0`, `007cea40`, skill-element loaders).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x0041bf70` (2026-07-29) ≡ raw |
| Raw / annotated / clean | `raw/aa_0041bf70_*`, `reconstructed-exact/FUN_0041bf70.cpp` |
| Function record | `functions/aa_0041bf70_*.md` |
| Parent dual | `reviews/A_aa_007e34b0_Skill_DbLoadSkillsCharacters.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Releases COM ifaces via vtbl+8 | **High** | IUnknown::Release shape |
| Calls FUN_00422de0 for handle array | **Confirmed** | direct callee |
| this[3] cleared via vtbl+0x18 | **High** | ReleaseAccessor slot pattern |
| this[4] is owned heap buffer | **High** | operator_delete |
| Shared by many DbLoad* units | **Confirmed** | dozens of callers |
| Product class name | **Open** | no strings in unit |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Body CF from scaffold clean | **Yes** |
| Live batch_decompile ≡ raw 2026-07-23 | **Yes** |
| No modernization | **Yes** |

---

## 5. Gaps

1. Exact product type of holder (ADO vs custom ND wrapper).
2. Register ABI (EDI) vs __thiscall needs caller seal.
3. FUN_00422a90 / FUN_0041b9f0 full semantics.

**Verdict:** Structural contract sealed from live decompile + xrefs. Product type names remain inferred. **accept-with-gaps.**
