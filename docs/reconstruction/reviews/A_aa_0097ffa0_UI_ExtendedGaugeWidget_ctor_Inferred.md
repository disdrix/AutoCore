# Review A (reconstruction fidelity): `aa_0097ffa0` UI_ExtendedGaugeWidget_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0097ffa0` |
| **VA** | `0x0097ffa0` |
| **Canonical name** | `UI_ExtendedGaugeWidget_ctor_Inferred` |
| **Prior alias** | `FUN_0097ffa0`, Named callee of xp-bonus / trade balance factories |
| **Review date** | `2026-07-29` (OWN-ONLY dual — CreateChildWidgets nested) |
| **Counterpart** | `reviews/B_aa_0097ffa0_UI_ExtendedGaugeWidget_ctor_Inferred.md` |
| **System** | client UI / NDUI gauge |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct **extended multi-field gauge** widget (factory size **`0x4f8`**):

```text
SEH LAB_009b4ab6
NDUIGaugeBase_Ctor(this)              // FUN_00863f10
*this = PTR_FUN_00a61e44              // extended gauge vtbl (≠ cooldown 00a62454)
// zero/flag block at +0x4a8..+0x4f4:
  +0x4a9 = 0
  +0x4ac [299] = 0
  +0x4b4..+0x4bc [0x12d..0x12f] = 0
  +0x4a8 byte = 1; +0x4aa = 1; +0x4ab = 1
  +0x4b0 [300] = 1
  multiple dword pairs zeroed (+0x130..+0x13d region)
return this
```

**CreateChildWidgets path:** `CDlgTrade2d_CreateChildWidgets` allocates `operator_new(0x4f8)` → this → skin `"i_d_t_2d_gauge_balance.xml"` at host `+0x590`.

**Sibling:** `UI_DataGaugeWidget_ctor` `0x0097dfe0` (0x4bc cooldown) shares base `00863f10` but different final vtbl + smaller tail.

Many other UI factories (xp bonus, hazard, etc.) also call this ctor.

---

## 2. ABI

```c
// this via [esp+0x14] / param_1; returns this
undefined4 * UI_ExtendedGaugeWidget_ctor_Inferred(undefined4 *this);
```

Entry: `mov esi,[esp+0x14]; push esi; call 00863f10`.

---

## 3. Confidence

| Claim | Conf |
|---|---|
| Extended gauge ctor after gauge base | **High** |
| Trade balance uses size 0x4f8 + this | **High** (Trade dual) |
| Distinct vtbl from Data/Cooldown gauge | **High** |
| Full field English of multi-slot zeros | **Open** |
| Product name | **Inferred** |

**Verdict:** **accept-with-gaps**
