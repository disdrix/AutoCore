# Function record: CVOGObject_ComputeOutcomeRolls_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00515520` |
| **Canonical name** | `CVOGObject_ComputeOutcomeRolls_Inferred` |
| **Ghidra name** | `FUN_00515520` |
| **Address** | `0x00515520` |
| **Body** | `0x00515520`–`0x00516706` (**4583 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / combat-outcome virtual |
| **Completion status** | **Dual-sealed (W27-M)** — ABI/xref/phase seal; decompiler temps residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Classification** | worker (large; cyclomatic ~156) |

## Alias

- Ghidra: `FUN_00515520`

## Purpose

Large virtual on many CVOGObject subclasses: gate validity, gather combat/level inputs, 6-channel short outcome rolls, optional reaction-list application, return clamped int.

## Signature (sealed ABI; formals partial)

```c
int __thiscall CVOGObject_ComputeOutcomeRolls_Inferred(
    int* self, int* other, char flag_reaction_a, char flag_reaction_b,
    uint32_t param_5, int pRngOrTable, int pOutChannelFlags
    /* + residual stack through ret 0x28 */);
// ret 0x28
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00515520_FUN_00515520.md`
- Annotated: `docs/reconstruction/raw/aa_00515520_FUN_00515520.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGObject_ComputeOutcomeRolls_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00515520.cpp`
- Live dump: `docs/reconstruction/tmp/w27m_00515520_live_decomp.txt`
- Review A: `docs/reconstruction/reviews/A_aa_00515520_CVOGObject_ComputeOutcomeRolls_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00515520_CVOGObject_ComputeOutcomeRolls_Inferred.md`

## Callers / callees

| Direction | Symbols |
|---|---|
| Callers | none CODE — 26 DATA vtable installs |
| Callees | GetLinkedActorLevel, Theory, TFID_NotEquals, Object_ResolveFromTFID, RandomUnitScalar, CNDDoubleList helper, ResolveUseObjectPending, FUN_0056add0, FUN_0056b340, ceil |

## Confidence

| Claim | Level |
|---|---|
| Control-flow phases | **High** (spine) |
| ABI ret 0x28 / thiscall / virtual | **High** |
| Full 10-arg formal map | **Medium** |
| Product English | **Tentative** |

