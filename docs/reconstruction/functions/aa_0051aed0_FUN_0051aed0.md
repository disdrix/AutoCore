# Function record: FUN_0051aed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051aed0` |
| **Canonical name** | `FUN_0051aed0` (scaffold; prefer `Object_PlayPickupSpecialFX`) |
| **Address** | `0x0051aed0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / special-fx / item-pickup |
| **Completion status** | **Superseded scaffold** — dual A/B W25-J on named record `aa_0051aed0_Object_PlayPickupSpecialFX` |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Canonical: `Object_PlayPickupSpecialFX` → `functions/aa_0051aed0_Object_PlayPickupSpecialFX.md`
- Prior parent-seed: `Named_CalleeOf_…_CVOGCreature_Setup_0051aed0`

## Purpose

Client pickup SpecialFX attach (type/rarity script map). See named record + clean plate.

## Signature (decompiler-derived)

```c
void __thiscall FUN_0051aed0(int *param_1,char param_2,char param_3)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051aed0_FUN_0051aed0.md`
- Annotated: `docs/reconstruction/raw/aa_0051aed0_FUN_0051aed0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0051aed0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
