# Review A (reconstruction fidelity): `aa_0052e1d0` Character_ComputeReverseEngineerRequiredLevel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052e1d0` |
| **VA** | `0x0052e1d0`–`0x0052e636` inclusive (**1127 B** / `0x467`) |
| **Canonical name** | `Character_ComputeReverseEngineerRequiredLevel_Inferred` |
| **Ghidra name** | `FUN_0052e1d0` |
| **Prior scaffold** | `Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_0052e1d0` (**retired**) |
| **Review date** | `2026-08-05` (R11-002 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0052e1d0_Character_ComputeReverseEngineerRequiredLevel_Inferred.md` |
| **System** | `inventory-transfer` (Reverse Engineer client skill math) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Compute the **integer Reverse Engineer skill level required** for `(character, item)`:

```text
need = Character_ComputeReverseEngineerRequiredLevel(character, item)
// Used only when twin success fraction <= 0:
//   sprintf("%s %d %s", "Requires At Least", need, "Reverse Engineering")
// Free path character+0x6b4 > 0 → 0 (twin returns 1.0 so parent never prints this)
// primary material cost 0 → 0
```

Not a tooltip presenter — dualed parent `Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` (`0x0085ce20`) **consumes** this int in mode 0.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF (gates / primary cost / ceil / secondary / max) |
| Body bounds | `get_function_by_address` → `0052e1d0`–`0052e636` |
| Prologue | `SUB ESP,38`; `MOV ESI,[ESP+44]`; `MOV EDI,ECX` (`read_memory`) |
| Epilogue | dual `ADD ESP,38` + `RET 4` (`C2 04 00`) @ `0052e629` / `0052e634` |
| Constants | `read_memory` 4 B LE on `009cdff4` / `009cefcc` / `009cefc8` / `00aaa7c4` / `009cefc4` |
| Caller | sole xref `0085cfe9` in `FUN_0085ce20` |
| Twin | dualed `0052e640` success **fraction** (float / ST0) |
| Level helper | `FUN_005206d0` inv-mult table (same floats) |
| Dualed deps | `00599dd0` slots; `00404d70` CloneBase; `004ce940` lootgen |

---

## 3. Signature (sealed)

```c
// ECX=character*; stack item*; EAX=int required level; RET 4
int __thiscall Character_ComputeReverseEngineerRequiredLevel_Inferred(
    void* character,
    void* item);
```

| Formal | Source | Conf |
|---|---|---|
| character (this) | ECX → EDI | **Confirmed** (prologue) |
| item | stack → ESI | **Confirmed** (`MOV ESI,[ESP+0x44]`) |
| return | EAX int | **Confirmed** (consumer `%d`; no FSTP at call site) |
| cleanup | `RET 4` (`C2 04 00`) | **Confirmed** both exits |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Null item / slots&lt;1 → 0 | Yes | **Confirmed** |
| `character+0x6b4 > 0` → 0 | Yes (differs from twin free→1.0) | **Confirmed** |
| Primary cost loop def `+0x498` | Yes; type **0x1a**, rank `+0x4c8`−1 | **Confirmed** |
| Base `ceil(cost * 1/3.5)` | Yes (`DAT_009cdff4`) | **Confirmed** |
| Secondary vtbl+0x60/+0x5c + `005097b0` | Yes; 5×4 B CBIDs | **Confirmed** |
| Max over `FUN_005206d0` aggregate + tiers 1..5 | Yes | **Confirmed** |
| primary_cost==0 → 0 | Yes (`if (iVar7 != 0)`) | **Confirmed** |

Decompiler artifacts corrected: unaff_EBX/FPU CW noise; signature void; free-path vs twin.

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Parent formats `"Requires At Least %d Reverse Engineering"` | **Yes** (`0085ce20`) |
| Twin supplies success **fraction**; this supplies **level** | **Yes** (MEGA-117 residual callout) |
| Inv capacity mults mirror dualed `00520520` | **Yes** (`read_memory`) |
| PDB / RTTI product method name | **No** → keep **`_Inferred`** |
| Tinkering scaffold name | **No** — tinkering strings are parent modes 4/5 |

**Name accepted:** `Character_ComputeReverseEngineerRequiredLevel_Inferred`.

---

## 6. Gaps

1. Product English for free flag `+0x6b4` and material rank `+0x4c8`.
2. Dual of helpers `FUN_005206d0` / `FUN_005097b0` / `FUN_00522950` (unowned here).
3. Exact per-row EBX zeroing bytes (decompiler FPU CW noise).
4. Whether server enforces same required level (client sealed only).
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
