# Function record: UiSelectWidget_ApplySelectChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00837d50` |
| **Canonical name** | `UiSelectWidget_ApplySelectChrome_Inferred` |
| **Address** | `0x00837d50` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `interaction-activation` |
| **Completion status** | **Dual-sealed** (A/B 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_00837d50` |

## Purpose

Select-widget chrome applicator: `ESI=widget*`, `EAX` → `widget+0x518`; vtbl `+0xd0/+0xcc/+0x444/+0xcc`; optional child `+0x53c` float path; tail `vtbl+0x34c`.

## Signature (assembly-derived)

```c
// custom: ESI = widget*, EAX = select/state
void UiSelectWidget_ApplySelectChrome_Inferred(void);
```

## Callers / callees

- Callers: `FUN_00893580`, `FUN_008b2470`, `FUN_008b27f0`, `FUN_00944d50`, orphan xrefs
- Callees: indirect vtbl only (`+0xd0`, `+0xcc`, `+0x444`, child `+0x3c8/+0x3b0`, tail `+0x34c`)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00837d50_FUN_00837d50.md`
- Annotated: `docs/reconstruction/raw/aa_00837d50_FUN_00837d50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_00837d50.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00837d50_UiSelectWidget_ApplySelectChrome_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00837d50_UiSelectWidget_ApplySelectChrome_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + assembly | High |
| Register ABI | High (assembly) |
| Product English names | Inferred / Open where marked |
