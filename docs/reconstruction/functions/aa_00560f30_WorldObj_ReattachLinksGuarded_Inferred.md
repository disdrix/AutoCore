# Function record: WorldObj_ReattachLinksGuarded_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560f30` |
| **Canonical name** | `WorldObj_ReattachLinksGuarded_Inferred` |
| **Ghidra name** | `FUN_00560f30` |
| **Address** | `0x00560f30`–`0x00560f60` (**48 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world-object / phys rebind |
| **Completion status** | **Dual-sealed** (W27-O 2026-07-29) — A **accept**, B **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Under manager reentrancy flag `+0x12c`, attach object (`FUN_0055e760`) then bind links (`FUN_0055fa40`). SwitchHBAI post-path when **entering** mode code **7**.

## Signature

```c
// RET 4
void __thiscall WorldObj_ReattachLinksGuarded_Inferred(Manager *m, WorldObj *obj);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00560f30_FUN_00560f30.md` |
| Annotated | `docs/reconstruction/raw/aa_00560f30_FUN_00560f30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_ReattachLinksGuarded_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00560f30.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_00560f30_FUN_00560f30.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_00560f30_WorldObj_ReattachLinksGuarded_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00560f30_WorldObj_ReattachLinksGuarded_Inferred.md` |

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Caller | `FUN_005d4440` | 1 site; new mode == 7 |
| Callee | `FUN_0055e760` | attach/register |
| Callee | `FUN_0055fa40` | `WorldObj_BindLinks_Inferred` |

## Confidence

| Claim | Level |
|---|---|
| CF + ABI sealed | **Confirmed** |
| Product names | Open / `_Inferred` |
