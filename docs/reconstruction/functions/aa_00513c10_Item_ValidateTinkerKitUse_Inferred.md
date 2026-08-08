# Function record: Item_ValidateTinkerKitUse_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513c10` |
| **Canonical name** | `Item_ValidateTinkerKitUse_Inferred` |
| **Ghidra name** | `FUN_00513c10` |
| **Address** | `0x00513c10`–`0x00513cde` (**207 B** / `0xCF`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B) MEGA-036 2026-08-05 |
| **Verdict** | **accept-with-gaps** |
| **Terminal** | **false** (runtime open) |

## Purpose

**Tinkering Kit apply-eligibility validator.** Given target **item** (ECX), local **character**, and **`CVOGTinkeringKit*`**, returns status **0..4**:

| Code | Caller message / path |
|-----:|------------------------|
| 0 | `"The object has no available slots to open."` (Broken also returns 0 here; dualed UI re-checks Broken first) |
| 1 | `"You do not possess the Tinkering skill to work on this object."` |
| 2 | `"This Tinkering Kit is too primitive to use on this object."` |
| 3 | `"This Tinkering Kit can only be used on %s."` (category) |
| 4 | OK — success-chance / green path |

Read-only; no packets; no mutation.

## Signature

```c
char __thiscall Item_ValidateTinkerKitUse_Inferred(
    void* item,        /* ECX */
    void* character,   /* stack+4  — DAT_00d1b6d8 at known sites */
    void* kit);        /* stack+8  — CVOGTinkeringKit* after RTTI cast */
// RET 8; status in EAX
```

## Evidence summary

- Live decompile ≡ raw (MEGA-036).
- Assembly: all exits `RET 8`; prologue `MOV ESI,ECX`; kit null → 3; Broken bit19 → 0; maxSlots@def+0x4b4 vs vtbl+0x8c; skill tier via `FUN_00521eb0`; kit level@+0xb0 → 4/2.
- Callers dualed for string map: `Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` (`0x0085ce20`).
- Sibling category leaf `FUN_00513bc0`; skill-tier leaf `FUN_00521eb0`.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00513c10_FUN_00513c10.md` |
| Annotated | `docs/reconstruction/raw/aa_00513c10_FUN_00513c10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_ValidateTinkerKitUse_Inferred.cpp` |
| Leave-FUN twin | `docs/reconstruction/reconstructed-exact/FUN_00513c10.cpp` |
| Leave-FUN record | `docs/reconstruction/functions/aa_00513c10_FUN_00513c10.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00513c10_Item_ValidateTinkerKitUse_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00513c10_Item_ValidateTinkerKitUse_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00513c10-mega-036-report.md` |

## Gaps

1. Product/PDB symbol.
2. Lexicon for `character+0x6b4`, vtbl `+0x8c`, def `+0x4b4`.
3. Unowned callees `FUN_00513bc0`, `FUN_00521eb0` full dual.
4. Orphan gate caller @ `0x0085d767`.
5. Runtime / bit-exact / differential.

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET 8 | **High / Sealed** |
| Status code map | **High / Sealed** |
| Role = tinker kit use validator | **High** |
| Product name | **Inferred** |
| Overall | **accept-with-gaps** |
