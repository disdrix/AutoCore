# Function record: Phys_IslandHost_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006295f0` |
| **Canonical name** | `Phys_IslandHost_Ctor_Inferred` |
| **Ghidra name** | `FUN_006295f0` |
| **Address** | `0x006295f0`–`0x006296a2` (**178 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | phys / island host construct |
| **Completion status** | **Dual-sealed** (W30-J 2026-07-29) — A **accept**, B **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

**Thiscall constructor** for the 0xa8 physics island/host object used when `WorldObj_AttachRegisterHost_Inferred` creates a new host (island path or first host on empty manager list). Also used by island-split (`FUN_00560110`).

Sealed behavior:

1. Clear header dwords `+0x08..+0x18`.
2. Install primary vtbl `009e331c` at `+0`, secondary `009e3310` at `+0x1c`.
3. Store **manager** at `+0x20`.
4. Flag bytes: `+0x28=0`, `+0x29=1`, `+0x2c=0`, `+0x30=1`.
5. Init empty list descriptors with capacity sentinels `0x80000000` / `0x80000001` through `+0x94`.

Caller then writes `host+0x24 = manager.count` (host list index). Sibling `FUN_006296c0` is dtor-like (frees lists, tag `0x12`).

## Signature

```c
// RET 4
void __thiscall Phys_IslandHost_Ctor_Inferred(uint32_t *host, uint32_t manager);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006295f0_FUN_006295f0.md` |
| Annotated | `docs/reconstruction/raw/aa_006295f0_FUN_006295f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phys_IslandHost_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006295f0.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_006295f0_FUN_006295f0.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_006295f0_Phys_IslandHost_Ctor_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_006295f0_Phys_IslandHost_Ctor_Inferred.md` |

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Caller | `WorldObj_AttachRegisterHost_Inferred` (`0055e760`) | island + empty ×2 |
| Caller | `FUN_00560110` | island split |
| Caller | `FUN_00561e20` | related manager path |
| Callee | none | |

## Confidence

| Claim | Level |
|---|---|
| CF + ABI sealed | **Confirmed** |
| Vtbl / manager / list layout | **Confirmed** |
| Product type name | Open / `_Inferred` |
