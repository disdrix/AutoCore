# Annotated low-level: FUN_004bb0d0

| Field | Value |
|---|---|
| Stable ID | `aa_004bb0d0` |
| VA | `0x004bb0d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bb0d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_004bb0d0(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)CVOGReaction_ResolveObjectTarget(*(undefined1 *)(param_1 + 2),*param_1,param_1[1])
  ;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x1dc))();
    return uVar2;
  }
  return 0;
}
```

## Machine-level notes (2026-08-04 dual seal)

- **ABI:** ECX = resolve context (caller; body never loads ECX). Stack `TFID_Head*`. `RET 4`.
- **Blob:** `+0` lo, `+4` hi, `+8` bGlobal only (same as `004bb010`).
- **Virtual:** `CALL [EDX+0x1dc]` after `MOV ECX,EAX` (resolved object as this).
- **Twin of** `Object_ResolveTfIdVtbl1d4_Inferred` except slot `0x1d4`→`0x1dc`.
- **Not** `Client_LookupObjectByTfid_Inferred` (`004bb0a0`): same slot, free 3-arg `RET 0xc`.
- **Body hex:** `8b4424048b5004528b108a40085250e88cfdffff85c0740d8b108bc8ff92dc010000c2040033c0c20400`

## Open questions

- Product/PDB name of `vtbl+0x1dc`.
- Whether return is always identity-equal to resolved object.
- Runtime / bit-exact / per-caller ECX provenance.
