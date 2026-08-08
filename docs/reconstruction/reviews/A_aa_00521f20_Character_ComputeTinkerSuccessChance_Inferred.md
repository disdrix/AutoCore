# Review A (reconstruction fidelity): `aa_00521f20` Character_ComputeTinkerSuccessChance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521f20` |
| **VA** | `0x00521f20`–`0x00521fe7` inclusive (**200 B** / `0xC8`) |
| **Canonical name** | `Character_ComputeTinkerSuccessChance_Inferred` |
| **Ghidra name** | `FUN_00521f20` |
| **Prior scaffold** | `Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_00521f20` (**retired**) |
| **Review date** | `2026-08-05` (R10-035 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00521f20_Character_ComputeTinkerSuccessChance_Inferred.md` |
| **System** | inventory-transfer / tinker success chance |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `get_function_by_address` + full caller disasm `0x0085f660`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Worker that returns a **tinker success-chance fraction** for the apply-confirm dialog:

```text
Character_ComputeTinkerSuccessChance_Inferred(character, item, kit) -> float
  if character[+0x6b4] >= 1: return 1.0
  need = item.vtbl[+0x8c]() + 1
  if skillTier(character) < need: return 0.0
  base = table[need]  // 0.4, 0.35, 0.3, 0.25, 0.2 for need 1..5
  return (character[+0x59b] - 2*need + kit[+0xb0]) * 0.04 + base
```

Caller multiplies by 100.0 and shows  
`"You have a %.02f %% chance of success."`

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold raw CF (early exit / vfunc / tier / switch / linear) |
| Full body | `disassemble_function` + `read_memory` float pool + jump table 5 dwords |
| Fields | `character+0x6b4`, `character+0x59b`, item vtbl `+0x8c`, `kit+0xb0` |
| Callers | sole `FUN_0085f660` @ `0x0085f6c1` |
| ECX seal | caller `MOV ECX,[0x00d1b6d8]` = **character** |
| Stack seal | `PUSH kit; PUSH item` before call |
| Callees | item vfunc `+0x8c`; `FUN_00521eb0` |
| Xrefs | 1 UNCONDITIONAL_CALL |

---

## 3. Signature (sealed)

```c
// ECX = character; stack item*, kit*; float ST0; RET 8
float __thiscall Character_ComputeTinkerSuccessChance_Inferred(
    void *character, void *item, void *kit);
```

| Formal | Source | Conf |
|---|---|---|
| character | **ECX** (caller `DAT_00d1b6d8`; body `+0x6b4` / `+0x59b` / pass to `00521eb0`) | **Confirmed** |
| item | stack arg1 (vfunc `+0x8c` slots) | **Confirmed** |
| kit | stack arg2 (`+0xb0` int16 level) | **Confirmed** |
| return | **ST0** float | **Confirmed** |
| cleanup | **`RET 8`** all exits | **Confirmed** |

**Note:** Ghidra `analyze` signature `undefined FUN_00521f20(void)` is **incorrect**.

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| `character+0x6b4 >= 1` → FLD 1.0 / RET 8 | bytes + decompile | **Confirmed** |
| item vfunc `+0x8c` → need = slots+1 in DL/ESI | CALL + ADD DL,1 | **Confirmed** |
| `FUN_00521eb0(character)`; `CMP tier, need`; JL→0.0 | JGE formula path | **Confirmed** |
| switch need-1 in 0..4 → base floats | jump table @ `0x00521fe8` | **Confirmed** |
| linear `(rank - 2*need + kitLevel) * 0.04 + base` | FILD/FMUL/FADD | **Confirmed** |
| Product field English | open | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** |
| External callers | **1** UNCONDITIONAL_CALL |
| Site role | tinker apply UI success % after validate status 4 |
| Callees | item vfunc `+0x8c`; `FUN_00521eb0` |
| Parent system | inventory-transfer (partition R10; parent dual `0x00521eb0`) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Character ECX via sole caller | **Yes** |
| Success-chance math + UI percent string at caller | **Yes** |
| Kit `+0xb0` + item slot need parity with validate dual | **Yes** |
| In-body product string | **No** |
| Scaffold Named_CalleeOf skill-string plate is product name | **No** — retire |

**Decision:** promote **`Character_ComputeTinkerSuccessChance_Inferred`**. Keep `_Inferred` until field English sealed.

---

## 7. Gaps

- Product English for `character+0x59b`, `character+0x6b4`, item vfunc `+0x8c`.
- Sibling dual `0x00521eb0` labels ECX as item; this site passes character (aligns with validate dual `0x00513c10`) — not re-sealed here.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path accepts CF/ABI/float-pool/call-site/formula with only product-field English residual → **accept-with-gaps**.
