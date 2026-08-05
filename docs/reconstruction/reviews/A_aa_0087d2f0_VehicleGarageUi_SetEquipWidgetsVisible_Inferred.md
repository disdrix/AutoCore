# Review A (reconstruction fidelity): `aa_0087d2f0` VehicleGarageUi_SetEquipWidgetsVisible_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0087d2f0` |
| **VA** | `0x0087d2f0` |
| **Canonical name** | `VehicleGarageUi_SetEquipWidgetsVisible_Inferred` |
| **Ghidra name** | `FUN_0087d2f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0087d2f0_VehicleGarageUi_SetEquipWidgetsVisible_Inferred.md` |
| **System** | client UI / vehicle & garage sheet |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Show/hide a fixed bank of **equip / slot widgets** on a vehicle-garage dialog (`this` in **ESI**).

```c
// thiscall; stack arg char show
void VehicleGarageUi_SetEquipWidgetsVisible(Dlg* this, char show) {
  if (show == 0 || *(int*)(this + 0x514) == 0) {
    // HIDE order: 5a0, 5a8, 5a4, 588, 58c, 590
    for each non-null widget: widget->vtbl[+0xcc](0);
  } else {
    // SHOW order: 588, 58c, 590, 5a0, 5a8, 5a4
    for each non-null widget: widget->vtbl[+0xcc](1);
  }
}
```

- Visibility method: **`vtbl+0xcc`** with arg 0/1 (same family as other UI set-visible).
- Gate: hide path also taken when `this+0x514 == 0` even if `show!=0` (no selection / no vehicle context).
- Decompiler marks last call as jumptable tail-call; still `vtbl+0xcc` with show/hide arg.

### Parent context (`FUN_008801b0`)

Large vehicle/garage refresh:

- Strings `"Vehicle - \"…"` / `"Garage - \"…"` / `"<No Vehicle Selected>"`.
- Mount/weapon kit labels, race icon path `i_d_v_2d_icon_race`.
- Ends with `FUN_0087d2f0(0 or 1)` then `FUN_008800e0`.
- `show=0` when no vehicle selection (`param_1[0x145]==0` or `DAT_00d1b6d8==0` path); else `show=1`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0087d2f0_*`, `reconstructed-exact/FUN_0087d2f0.cpp` |
| Function record | `functions/aa_0087d2f0_FUN_0087d2f0.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x0087d2f0` (2026-07-29) |
| Bytes | `read_memory` 64 B — `cmp [esp+4],0` / `cmp [esi+0x514],0` / `push 1; call [eax+0xcc]` |
| Parent | `FUN_008801b0` decompile (Vehicle/Garage strings) |
| Caller | only `FUN_008801b0` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| this in ESI; arg = show bool | **Confirmed** | bytes + parent call |
| Widget slots 0x588,58c,590,5a0,5a4,5a8 | **Confirmed** | both branches |
| Method `vtbl+0xcc` | **Confirmed** | |
| Hide if `+0x514==0` | **Confirmed** | |
| Vehicle/garage UI domain | **High** | parent strings |
| Exact widget product names | **Open** | offsets only |
| clean ≡ raw ≡ live | **High** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Branch show vs hide (`param` / `+0x514`) | Yes |
| Null-check each widget before vcall | Yes |
| Opposite order hide vs show | Yes (cosmetic order) |

### Recovered CF

```c
void SetEquipWidgetsVisible(Dlg* self, bool show) {
  bool on = show && self->ptr_514 != nullptr;
  // apply self->widgets[{0x588,0x58c,0x590,0x5a0,0x5a4,0x5a8}]->SetVisible(on)
}
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_008801b0` | vehicle/garage sheet refresh |
| Callee | widget `vtbl+0xcc` | set visible |

---

## 6. Gaps / open

1. Map offsets 0x588..0x5a8 to named child widgets (front/turret/kit slots from parent).
2. Meaning of `+0x514` (selected vehicle object?).
3. Dual full `008801b0` if not already covered.
4. Runtime deferred.

**Verdict:** **accept-with-gaps** — visibility bank CF sealed; child names Open.
