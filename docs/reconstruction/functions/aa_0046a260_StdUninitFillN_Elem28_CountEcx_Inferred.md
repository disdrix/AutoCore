# Function record: StdUninitFillN_Elem28_CountEcx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046a260` |
| **Canonical name** | `StdUninitFillN_Elem28_CountEcx_Inferred` |
| **Ghidra name** | `FUN_0046a260` |
| **Address** | `0x0046a260`–`0x0046a281` (**34 B** / `0x22`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | stl-helpers / POD uninit fill-n (elem 0x1c) |
| **Wave** | W36-M OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept** |
| **Dual A/B** | `reviews/A_aa_0046a260_StdUninitFillN_Elem28_CountEcx_Inferred.md`, `reviews/B_aa_0046a260_StdUninitFillN_Elem28_CountEcx_Inferred.md` |

## Purpose

Null-safe uninit fill-n for 28-byte POD on register ABI (**ECX count / EAX dest* / EBX template***). Uses **REP MOVSD** ×7 per element. Closes the fill residual under `StdVector_InsertN_Elem28_ValueEdx_Inferred` (W34-Q) and `FUN_00469c80`.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `StdVector_InsertN_Elem28_ValueEdx_Inferred` | `0x00469f50` | parent (W34-Q) — 2 call sites |
| `FUN_00469c80` | `0x00469c80` | parent — 1 call site (count=1 push-end) |
| `StdUninitFillN_Elem28_CountEax_Inferred` | `0x0045f150` | sibling fill-n, **different ABI** (W35-L) |
| `StdCopyBackward_Elem28_Inferred` | `0x0046a240` | prior symbol (copy_backward); pad then this |
| `Pod28_FillAssign_Forward` | `0x0045efe0` | assign-fill cousin (range end, not count-n) |

## Signature

```c
// ECX=count, EAX=dest*, EBX=template*; bare RET; leaf
void StdUninitFillN_Elem28_CountEcx_Inferred(
    uint32_t count, Elem28* dest, const Elem28* tmpl);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0046a260_FUN_0046a260.md` |
| Annotated | `docs/reconstruction/raw/aa_0046a260_FUN_0046a260.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitFillN_Elem28_CountEcx_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0046a260.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_0046a260_FUN_0046a260.md` |
| Dual report | `docs/agents/task-dual-ab-00459750-0046a260-w36m-report.md` |

## Confidence

| Claim | Level |
|---|---|
| Register ABI ECX/EAX/EBX + bare RET | **High** |
| Stride 0x1c + null-safe + always-advance | **High** |
| Leaf / 0 callees | **High** |
| Product demangle / concrete T English | **Open** |
| Runtime / bit-exact | **Open** |
