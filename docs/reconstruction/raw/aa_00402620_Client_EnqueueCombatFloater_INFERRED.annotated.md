# Annotated low-level: Client_EnqueueCombatFloater_INFERRED

| Field | Value |
|---|---|
| Stable ID | `aa_00402620` |
| VA | `0x00402620` |
| System | missions-progression |
| Date | 2026-07-23 |
| Refine | Human pass after named_hl_000 industrial emit |

## Machine-level notes

- Source: raw capture for `aa_00402620` (Ghidra `batch_decompile`).
- Queue is a std-vector-like buffer of **0x38-byte** elements:
  - `this+4` begin, `this+8` end, `this+0xc` capacity end.
- Fast path gate: `begin != 0` **and** `(end-begin)/0x38 < (cap-begin)/0x38`.
- Fast path: `FUN_00404600(end, 1, value, this, value)` then `end += 0x38`.
- Slow path: `FUN_00402e20(&value, end, value)` — grow when empty/full.
- Plate: XP floaters use type field **3** (`CombatFloaterType::XP`); kill-award success also enqueues.
- Prefer assembly if decompiler conflicts; element fields still untyped.

## Pseudocode (annotated copy of raw)

```c
/* Client_EnqueueCombatFloater_INFERRED

   INFERRED: queues a combat floater message on the local vehicle.
   XP path builds stack blob with type field = CombatFloaterType::XP (3).
   Also used by kill-award success path.
   Dependency of session XP RE only — full floater layout not fully typed. */

void __thiscall Client_EnqueueCombatFloater_INFERRED(int param_1,undefined4 param_2)

{
  int iVar1;

  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) &&
     ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x38) <
      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 0x38))) {
    iVar1 = *(int *)(param_1 + 8);
    FUN_00404600(iVar1,1,param_2,param_1,param_2);
    *(int *)(param_1 + 8) = iVar1 + 0x38;
    return;
  }
  FUN_00402e20(&param_2,*(undefined4 *)(param_1 + 8),param_2);
  return;
}
```

## Open questions

- Full 0x38-byte floater struct fields (type, amounts, TFID, duration).
- Map `FUN_00404600` / `FUN_00402e20` (construct vs reallocate).
- Confirm all callers beyond kill-award / XP (Ghidra xrefs).

## Human refine (2026-07-23, priority_010)

- already refined named_hl_000; confirmed CF: vector triad +0x04/+0x08/+0x0C elem 0x38
- Clean: docs/reconstruction/reconstructed-exact/Client_EnqueueCombatFloater_INFERRED.cpp
- Dual review: open

