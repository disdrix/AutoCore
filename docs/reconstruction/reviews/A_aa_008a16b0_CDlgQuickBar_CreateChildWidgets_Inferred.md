# Review A (reconstruction fidelity): `aa_008a16b0` CDlgQuickBar_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a16b0` |
| **VA** | `0x008a16b0` |
| **Canonical name** | `CDlgQuickBar_CreateChildWidgets_Inferred` |
| **Ghidra name** | `FUN_008a16b0` |
| **Review date** | `2026-07-29` (W21-R OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw CF) |
| **Counterpart** | `reviews/B_aa_008a16b0_CDlgQuickBar_CreateChildWidgets_Inferred.md` |
| **System** | `skills-abilities` / client QuickBar UI |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**CreateChildWidgets** for the QuickBar dialog host (`CDlgQuickBar` Probable):

1. SEH frame; base prep `FUN_00792600`.
2. Allocate/ctor/parent-attach a bank of chrome widgets into host dword slots (`+0x624`…`+0x684` family).
3. Two **page/hazard buttons** via sealed `UI_QuickBar_CreateSlotButton` (`0x00825bf0`) at `host[0x19b]/[0x19c]` (`+0x66c`/`+0x670`): stamp `+0x500` = 0/1; label children `"1"`/`"2"`.
4. Load hazard skins (`i_d_qb_2d_wnd_hazard_*`) + gauge (`FUN_0097ffa0`).
5. Y-reposition `FUN_008a0370`; build/rebind page columns (`FUN_008a1110` / `FUN_008a0e10`); restore or auto-pick selection (`FUN_00826780` / `FUN_008a0210`).

**Not** skill cast, **not** wire send, **not** `QuickBar_SelectPage` (sibling `0x008a0ed0` owns pure page switch).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw + W21-R append | `raw/aa_008a16b0_FUN_008a16b0.md` |
| Annotated | `raw/aa_008a16b0_FUN_008a16b0.annotated.md` |
| Clean named | `reconstructed-exact/CDlgQuickBar_CreateChildWidgets_Inferred.cpp` |
| Clean scaffold | `reconstructed-exact/FUN_008a16b0.cpp` |
| Function record | `functions/aa_008a16b0_CDlgQuickBar_CreateChildWidgets_Inferred.md` |
| Live decompile | Ghidra `decompile_function(0x008a16b0)` — **≡** 2026-07-23 raw |
| Entry bytes | `read_memory` 96 B — SEH `LAB_009b98c0`, `mov edi,ecx` |
| Vtable | `read_memory` @ `0x00a4d320` → `0x008a16b0`; strings `Show/Hide Quick Menu` @ `0x00a4d338` |
| Scale floats | `DAT_00aaa678` ≈ 0.000833f; `DAT_00aaa67c` ≈ 0.000625f |
| Sibling duals | `UI_QuickBar_CreateSlotButton`, `UI_QuickBarSlotButton_SetSelected`, `QuickBar_SelectPage_Inferred`, `UI_HostRepositionAnchoredChild_Y_Inferred` |

**Not performed:** `disassemble_bytes`, Launcher, live UI golden.

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH + `FUN_00792600` | **Yes** |
| `new(0x580)` → `+0x664` | **Yes** |
| Two `new(0x488)` + z-order → `+0x624`/`+0x628` | **Yes** |
| Two `new(0x4cc)` → `+0x62c`/`+0x630` | **Yes** |
| `new(0x520)` → `+0x668` | **Yes** |
| Inc btn XML + 0.5f scale → `+0x634` | **Yes** |
| Two `CreateSlotButton` 0/1 labels | **Yes** |
| Hazard bar/inc/gauge/label | **Yes** |
| `new(0x58c)` → `+0x684` + z-order | **Yes** |
| Tail rebind + selection gate on `+0x548` | **Yes** |
| Optional `DAT_00d1b6d8` path | **Yes** |
| Final `vtbl+0x34c` | **Yes** |

---

## 4. Confidence table

| Area | Confidence | Notes |
|---|---|---|
| Role = QB host child build | **High** | qb XML + CreateSlotButton duals + page rebind |
| Host ECX thiscall | **High** | `mov edi,ecx` |
| Slot map for 0x19b/0x19c/hazard | **High** | body + sibling duals |
| `+0x500` index stamps 0/1 | **High** | body |
| Tail uses `DAT_00d1da38` / `FUN_008a0e10` | **High** | same globals as SelectPage |
| Host class `CDlgQuickBar` | **Probable** | RTTI on SetSelected path |
| Product method name CreateChildWidgets | **Inferred** | pattern matches other `CDlg*_CreateChildWidgets` |
| Early 0x488/0x4cc English roles | **Open** | no plate strings |
| `FUN_00826780` ECX on restore | **Tentative** | decomp residual; sibling seal = column thiscall |
| Runtime golden | **Open** | |

---

## 5. Gaps / open (do not block accept-with-gaps)

1. Product C++ method name.
2. Full product names for early chrome children.
3. Exact ECX recovery for SetSelected on tail restore.
4. `FUN_008a1110` / `FUN_008a04b0` dual ownership (not OWN this wave).
5. Runtime / bit-exact.

### **accept-with-gaps**
