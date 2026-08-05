# Review A (reconstruction fidelity): `aa_004205e0` OleDb_WalkActiveBindings_Vtbl10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004205e0` |
| **VA** | `0x004205e0` (0x004205e0–0x00420623) |
| **Canonical name** | `OleDb_WalkActiveBindings_Vtbl10_Inferred` |
| **Ghidra name** | `FUN_004205e0` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride_004205e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-F) |
| **Counterpart** | `reviews/B_aa_004205e0_OleDb_WalkActiveBindings_Vtbl10_Inferred.md` |
| **System** | COM / OLE DB accessor bind |
| **Live tools** | Ghidra MCP `decompile_function` / `read_memory` / callers / callees (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Parent ensure** | `Skill_DbLoadSkillsCharacters` nested (shared DbLoad / `OleDb_RebindAccessor` `aa_0041c000`) |

---

## 1. Purpose

Post-bind **active-binding walk** over ESI context:

1. `count = *(ESI[2] + 4)`; `hr = 0`.
2. For `i = 0 .. count-1`:
   - If byte at `*table + i*8 + 4 == 0`: skip.
   - Else `hr = (iface->vtbl+0x10)(iface, ESI[3], *(entry+0), table[2])`.
   - If `hr < 0`: return `hr` immediately.
3. Return `hr` (0 if no active entries or all non-negative).

Sole caller `FUN_0041c000` (`OleDb_RebindAccessor_Inferred`): after CreateAccessor-shaped `vtbl+0x14` succeeds, if this returns `< 0` and handle still set → ReleaseAccessor (`vtbl+0x18`) again.

On standard `IAccessor`, slot `+0x10` is **CreateAccessor** (aligned with dual `aa_004231d0`); exact product method remains inferred if vtbl is a project shim.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `decompile_function` @ `0x004205e0` (2026-07-29) ≡ raw |
| Raw / annotated / clean | `raw/aa_004205e0_*`, `reconstructed-exact/FUN_004205e0.cpp` |
| Function record | `functions/aa_004205e0_FUN_004205e0.md` |
| Live bytes | `read_memory` @ `0x004205e0` length 80 — starts `mov ecx,[esi+8]`; ends `ret` + `CC` pad |
| Parent dual | `reviews/A_aa_0041c000_OleDb_RebindAccessor_Inferred.md` |
| Related dual | `reviews/A_aa_004231d0_OleDb_CreateAccessorFromBindings_Inferred.md` (vtbl+0x10 CreateAccessor) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ESI-ambient context; no stack formals; plain `ret` | **High** | entry `mov ecx,[esi+8]`; epilogue `c3` |
| Binding table at `ESI+8`; count at `table+4` | **High** | |
| Entry stride 8; active flag at +4 | **High** | matches mark-active in `004231d0` |
| Indirect call `vtbl+0x10` with 4 args | **High** | |
| Early-out on first `hr < 0` | **High** | |
| Only caller is rebind helper `0041c000` | **High** | callers API |
| Product method name at +0x10 | **Medium** | IAccessor CreateAccessor layout |
| Full ESI struct product type | **Tentative** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Body CF from refined clean | **Yes** |
| Live `decompile_function` ≡ raw 2026-07-23 | **Yes** |
| No modernization | **Yes** |

---

## 5. Gaps

1. Product name of ESI bind/holder struct (shared ambient with rebind path).
2. Confirm live whether `vtbl+0x10` is always CreateAccessor vs custom validation.
3. Semantics of inactive entries (permanently skipped vs staged elsewhere).

**Verdict:** Structural contract sealed from live decompile + `read_memory` + sole-caller context. Product names remain inferred. **accept-with-gaps.**
