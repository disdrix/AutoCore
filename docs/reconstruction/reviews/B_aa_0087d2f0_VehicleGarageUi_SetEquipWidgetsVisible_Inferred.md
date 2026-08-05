# Review B (skeptical / adversarial): `aa_0087d2f0` VehicleGarageUi_SetEquipWidgetsVisible_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0087d2f0` |
| **VA** | `0x0087d2f0` |
| **Canonical name** | `VehicleGarageUi_SetEquipWidgetsVisible_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0087d2f0_VehicleGarageUi_SetEquipWidgetsVisible_Inferred.md` |
| **System** | client UI / vehicle & garage sheet |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Drive physics / steer input | No phys; only UI vcalls | **Falsified** drive merge |
| 2 | `show=1` always shows | Also requires `this+0x514 != 0` | **Falsified** |
| 3 | Destroys widgets | Only `vtbl+0xcc(0/1)` | **Falsified** destroy |
| 4 | Updates text/icons | Parent `008801b0` does labels; this VA only visibility | **Attack fails** — separation |
| 5 | Free function no this | ESI host; parent passes this | **Falsified** |
| 6 | Same bank as death UI widgets | Different offsets (death uses 114c/1150/…) | **Falsified** merge |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Show/hide via +0xcc bank | **Confirmed** | Wrong UI state |
| Gate +0x514 | **Confirmed** | Show without selection |
| Vehicle/garage parent | **High** | Wrong system tag |
| Widget English names | **Open** | Docs |
| Order difference hide/show | **Confirmed** | unlikely semantic |

---

## 3. Cross-check against raw / live / bytes

```
batch_decompile ≡ raw.
bytes head: cmp [esp+4],0; je hide; cmp [esi+0x514],0; je hide; push 1; call [vtbl+0xcc]
Parent 008801b0: FUN_0087d2f0(0) on empty selection; FUN_0087d2f0(1) after fill.
```

### Merge trap

Do **not** merge with:

- Drive vehicle tick / physics
- Death UI sequence `00802170`
- Dialog table open `007fef20`

### Show trap

`SetEquipWidgetsVisible(true)` with null `+0x514` must **hide**, matching retail.

---

## 4. Surviving contract for AutoCore

```
VehicleGarageUi_SetEquipWidgetsVisible(dlg, show):
  on = show && dlg->field_514 != null
  for w in equipWidgetBank:
    if w: w->SetVisible(on)   // vtbl+0xcc

Called at end of vehicle/garage sheet refresh (008801b0).

AutoCore must NOT:
  - treat as drive input
  - free widgets
  - ignore +0x514 gate
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Visibility bank +0xcc | **Agree Confirmed** |
| +0x514 hide gate | **Agree Confirmed** |
| Vehicle/garage domain High | **Agree High** |
| Child names Open | **Agree** |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Name each of the six child pointers from dialog XML/RTTI.
2. Confirm `+0x514` == selected vehicle entity.
3. Dual `008801b0` residual if missing.

**Verdict:** **accept-with-gaps** — agree with A; block drive/death merge and show-without-514.
