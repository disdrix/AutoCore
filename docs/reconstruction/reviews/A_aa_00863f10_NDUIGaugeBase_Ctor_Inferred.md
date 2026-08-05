# Review A (reconstruction fidelity): `aa_00863f10` NDUIGaugeBase_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00863f10` |
| **VA** | `0x00863f10` |
| **Canonical name** | `NDUIGaugeBase_Ctor_Inferred` |
| **Ghidra** | `FUN_00863f10` |
| **Review date** | `2026-07-29` (OWN-ONLY dual — CreateChildWidgets nested) |
| **Counterpart** | `reviews/B_aa_00863f10_NDUIGaugeBase_Ctor_Inferred.md` |
| **System** | client UI / NDUI gauge |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Shared intermediate constructor** for gauge-class widgets:

1. `NDUIWindow_BaseCtor` (`FUN_007b5dd0(this, 0)`).
2. Install gauge-base vtbl `PTR_FUN_00a61a1c`.
3. Seed gauge-specific fields:

| Offset | Value | Notes |
|-------:|-------|------|
| +0x488 (`[0x122]`) | 0 | |
| +0x48c (`[0x123]`) | `DAT_00aaa8fc` ≈ **0.03f** | `read_memory` `8fc2f53c` |
| +0x490 (`[0x124]`) | `DAT_00aaa688` = **5.0f** | `0000a040` |
| +0x494 (`[0x125]`) | 0 | |
| +0x498 (`[0x126]`) | 0 | |
| +0x49c (`[0x127]`) | `g_flOne` (1.0f) | |
| +0x4a0 (`[0x128]`) | `g_flOne` | |
| +0xbf | 0 | flag byte |
| +0x4a4 (`[0x129]` as byte) | 1 | enable-ish |

**Callers:**

- `UI_DataGaugeWidget_ctor` / cooldown `0x0097dfe0` (size **0x4bc**)
- `UI_ExtendedGaugeWidget_ctor_Inferred` `0x0097ffa0` (size **0x4f8**, Trade balance + many)

**Not** XML load / attach — pure ctor chain.

---

## 2. ABI

```c
// this via stack/reg param_1; returns this
// entry: mov esi, [esp+0x14]; push 0; push esi; call 007b5dd0
undefined4 * NDUIGaugeBase_Ctor_Inferred(undefined4 *this);
```

SEH `LAB_009b383d`. Single basic block, CC 1.

---

## 3. Confidence

| Claim | Conf |
|---|---|
| Role = gauge base after NDUIWindow | **High** |
| Shared by cooldown + extended gauges | **High** (callers) |
| Float constants 0.03 / 5.0 / 1.0 | **High** (read_memory) |
| Product class English | **Inferred** |

**Verdict:** **accept-with-gaps**
