# Review A (reconstruction fidelity): `aa_005fdf20` hkDefaultAnalogDriverInput_FilterSteer_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fdf20` |
| **VA** | `0x005fdf20`–`0x005fdf97` inclusive (**120 B** / `0x78`) |
| **Canonical name** | `hkDefaultAnalogDriverInput_FilterSteer_Inferred` |
| **Ghidra name** | `FUN_005fdf20` |
| **Review date** | `2026-08-05` (MEGA-026 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_005fdf20_hkDefaultAnalogDriverInput_FilterSteer_Inferred.md` |
| **System** | input-drive-control (Havok analog driver input filtered steer) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **piecewise-linear steer filter** on `hkDefaultAnalogDriverInput`:

```text
abs = |this.+0x1c|                          // raw signed steer
if abs < this.+0x38: return 0               // deadzone
sign = (raw > 0) ? +1 : −1
if abs < this.+0x28:
    return (abs − deadzone) * slope_inner(+0x2c) * sign
else:
    return ((abs − inner) * slope_outer(+0x30) + base(+0x34)) * sign
```

Sole consumer: dualed parent-ish `hkDefaultAnalogDriverInput_calcStatus` stores ST0 → **status `+0x14` (steer)**. Sibling reverse helper `calcReverse` fills `+0x19`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-026 append) | `docs/reconstruction/raw/aa_005fdf20_FUN_005fdf20.md` |
| Annotated | `docs/reconstruction/raw/aa_005fdf20_FUN_005fdf20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkDefaultAnalogDriverInput_FilterSteer_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005fdf20.cpp` |
| Function record | `docs/reconstruction/functions/aa_005fdf20_FUN_005fdf20.md` |
| Named record | `docs/reconstruction/functions/aa_005fdf20_hkDefaultAnalogDriverInput_FilterSteer_Inferred.md` |
| Live | decompile ≡ CF; body hex 0x78; callers/xrefs=1; call-site ECX/FSTP; constants −1/0/1 |

---

## 3. Signature (sealed)

```c
// ECX = this (hkDefaultAnalogDriverInput*); no stack args; plain RET; float on ST0
float __thiscall hkDefaultAnalogDriverInput_FilterSteer_Inferred(
    hkDefaultAnalogDriverInput *this);
```

| Slot | Source | Conf |
|---|---|---|
| this | **ECX** (`MOV ECX,ESI` @ call site) | **High** |
| stack args | **none** | **High** |
| cleanup | plain **`RET`** ×3 exits | **High** |
| return | FPU **ST0** → caller `FSTP [ESI+0x14]` | **High** |
| convention label | decompiler `__fastcall`; machine thiscall (ECX only) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| abs = \|+0x1c\| via FLD/FABS/FST | **Yes** | **High** |
| deadzone compare vs +0x38 → return 0 | **Yes** | **High** |
| sign +1 / −1 via COMISS + g_flOne / DAT_00aaa668 | **Yes** | **High** |
| inner branch: (abs−dz)*slope2c*sign | **Yes** | **High** |
| outer branch: (abs−28)*slope30+base34 * sign | **Yes** | **High** |
| Leaf (no callees) | **Yes** | **High** |
| Product English for helper symbol | open | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | **leaf** |
| External callers | `hkDefaultAnalogDriverInput_calcStatus` @ `0x005fe520` (**1** site `0x005fe58d`) |
| Xref count | **1** UNCONDITIONAL_CALL |
| Site role | status.steer (`+0x14`) after pedal accel/brake fill |
| Callees | **none** |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Sole caller is sealed-named `hkDefaultAnalogDriverInput_calcStatus` | **Yes** |
| Parent plate: `+0x14 steer via FUN_005fdf20` | **Yes** |
| Piecewise deadzone/inner/outer filter CF sealed | **Yes** |
| Distinct from pedal path (+0x20 → +0xc/+0x10) and calcReverse | **Yes** |
| Product/PDB/Havok SDK English for this exact leaf | **No** |

**Decision:** promote **`hkDefaultAnalogDriverInput_FilterSteer_Inferred`**. Reject accel/brake mislabel; reject full calcStatus merge; reject non-leaf claims. Scaffold `FUN_005fdf20` retained as twin only.

---

## 7. Gaps / open

1. Product / Havok SDK English (may be inlined in SDK `calcStatus`) → `_Inferred`.
2. Tuning-field product names for `+0x28..+0x38` beyond structural roles.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
