# Function record: Object_ApplyMaterialBank_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b310` |
| **Canonical name** | `Object_ApplyMaterialBank_Inferred` |
| **Ghidra name** | `FUN_0051b310` |
| **Address** | `0x0051b310`–`0x0051b34f` (**64 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / gfx material bank |
| **Completion status** | **Dual sealed** (A+B 2026-08-04 WQ9R-I) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

If the object material-parameter bank (`+0x148/+0x14C`, stride `0x10`) is non-empty, resolve gfx component via `vtbl+0x1CC` and commit bank entries through `FUN_005194f0(*(component+8), this+0x144)` (MatDiffuse/Ambient/Emissive path in callee).

## Signature (sealed)

```c
void __thiscall Object_ApplyMaterialBank_Inferred(void *self /* ECX */);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051b310_FUN_0051b310.md`
- Annotated: `docs/reconstruction/raw/aa_0051b310_FUN_0051b310.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_ApplyMaterialBank_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0051b310.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051b310_Object_ApplyMaterialBank_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051b310_Object_ApplyMaterialBank_Inferred.md`
- Report: `docs/agents/task-dual-ab-0051b310-0051b350-wq9ri-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callee | `FUN_005194f0` |
| Code callers | `FUN_004c5510` @ `0x004c5524`; site `0x004f3760` |
| DATA | 23 object vtable slots (e.g. `0x009ce3c8`) |
| Sibling | `FUN_0051b2a0` empty-bank fill (adjacent vtbl) |

## Confidence

| Claim | Level |
|---|---|
| Control flow / offsets / stride | **High** (bytes) |
| Apply (not fill) role | **High** |
| Product demangle | Open (`_Inferred`) |
| Bank element product type | Open (callee dual) |
