# Function record: UiTargetPanel_PaintSlotChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e9290` |
| **Canonical name** | `UiTargetPanel_PaintSlotChrome_Inferred` |
| **Address** | `0x008e9290` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `interaction-activation` |
| **Completion status** | **Dual-sealed** (A/B 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_008e9290` |

## Purpose

4-slot target-panel chrome painter. `EAX=panel*`, `EBX=selected index or -1`. Paints selected slot color `0xFF32FF32` vs unselected `0xFFAFAFAF` via slot `vtbl+0x164`, redraw `+0x34c`, clears linked `+0x184`.

## Signature

```c
void UiTargetPanel_PaintSlotChrome_Inferred(void);
// EAX = panel*, EBX = selected slot index 0..3 or -1
```

## Callers / callees

- Callers: `FUN_008e9690` (always), xref `0x008eb467`
- Callees: indirect slot vtbl `+0x164`, `+0x34c`, `+0x1a0`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008e9290_FUN_008e9290.md`
- Annotated: `docs/reconstruction/raw/aa_008e9290_FUN_008e9290.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_008e9290.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_008e9290_UiTargetPanel_PaintSlotChrome_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_008e9290_UiTargetPanel_PaintSlotChrome_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow + color dwords | High (assembly) |
| Product slot English | Open |
