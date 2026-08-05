# Function record: NDResource_GetDefaultTypeToken_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423b10` |
| **Canonical name** | `NDResource_GetDefaultTypeToken_Inferred` |
| **Address** | `0x00423b10` |
| **Body** | `0x00423b10`–`0x00423b3f` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | ND resource cache / type token |
| **Completion status** | **Dual A/B complete** (2026-07-29 W18-D) — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_00423b10` |

## Purpose

One-shot initialize the default ND resource type-token singleton (`DAT_00d1f734` ← `PTR_FUN_00a95ae8`), register `atexit(LAB_009c3070)`, return `&DAT_00d1f734` for `NDResourceCache_LookupOrCreate`.

## Signature

```c
void *NDResource_GetDefaultTypeToken_Inferred(void);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00423b10_FUN_00423b10.md`
- Annotated: `docs/reconstruction/raw/aa_00423b10_FUN_00423b10.annotated.md`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00423b10.cpp`
- Named clean: `docs/reconstruction/reconstructed-exact/NDResource_GetDefaultTypeToken_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00423b10_NDResource_GetDefaultTypeToken_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00423b10_NDResource_GetDefaultTypeToken_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00423b10_FUN_00423b10.md`

## Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller (sole) | `NDResource_LoadByKey` `0x00423ac0` | type token arg |
| Callee | `_atexit` | process teardown |
| Data | `LAB_009c3070` | atexit destructor thunk |
| Data | `PTR_FUN_00a95ae8` | type vtable |

## Confidence

| Claim | Level |
|---|---|
| Control flow | High / Confirmed |
| Return = address of singleton | Confirmed |
| Role as type token in LoadByKey | High (parent dual) |
| Product class English | Open |
| Dual review | Present |
