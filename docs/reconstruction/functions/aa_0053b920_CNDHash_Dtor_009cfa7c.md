# Function record: CNDHash_Dtor_009cfa7c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b920` |
| **Canonical name** | `CNDHash_Dtor_009cfa7c` (Ghidra `FUN_0053b920`; **Inferred**) |
| **Address** | `0x0053b920` |
| **Body** | `0x0053b920`–`0x0053b98a` (**`ret`**, 107 B / `0x6B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (object vtbl `PTR_FUN_009cfa7c`, **owning**) |
| **Completion status** | **Dual sealed 2026-07-29 W24-M** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

**CNDHash destructor** for object family **`PTR_FUN_009cfa7c`**:

1. SEH frame (`LAB_009a3edb`).
2. Re-stamp object vtbl `009cfa7c`.
3. If lock `+0x1d` → NDError log Destructor-locked + `VOG_DEBUG_STOP` (non-fatal).
4. **`FUN_005390d0`** FreeBuckets owning: `count=0`; reclaim **`FUN_00538190`** (stamp `009cefe4`, **delete values**); free table `+0x10`.
5. **`FUN_0059c8a0`** freelist slab vector dtor with **ECX = this+0x20** (machine-sealed; decompiler bare call).
6. SEH restore; bare `ret`.

Scalar deleting dtor: `FUN_0053b900` (vtbl[0]) → this + optional `operator_delete`.

## Signature (sealed)

```c
// void __thiscall / __fastcall — bare ret
void CNDHash_Dtor_009cfa7c(void *thisHash);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0053b920_FUN_0053b920.md`
- Annotated: `docs/reconstruction/raw/aa_0053b920_FUN_0053b920.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDHash_Dtor_009cfa7c.cpp`
- Clean (FUN alias): `docs/reconstruction/reconstructed-exact/FUN_0053b920.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0053b920_CNDHash_Dtor_009cfa7c.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0053b920_CNDHash_Dtor_009cfa7c.md`

## Callers / callees

| Direction | Symbol | VA | Role |
|---|---|---|---|
| Caller | `FUN_0053b900` | `0x0053b900` | scalar deleting dtor (vtbl[0]) |
| Callee | `FUN_005390d0` | `0x005390d0` | FreeBuckets owning |
| Callee | `FUN_0059c8a0` | `0x0059c8a0` | freelist slabs @ `this+0x20` |
| Callee | `FUN_007a4480` | — | lock path log ×2 |

## Confidence

| Claim | Level |
|---|---|
| Object vtbl stamp `009cfa7c` | **Confirmed** |
| Owning FreeBuckets path (`005390d0` → `00538190`) | **Confirmed** |
| Freelist ECX = `this+0x20` | **Confirmed** (machine) |
| Lock log non-fatal | **Confirmed** |
| Product English name | **Open** |
| Runtime / bit-exact | **Open** |
