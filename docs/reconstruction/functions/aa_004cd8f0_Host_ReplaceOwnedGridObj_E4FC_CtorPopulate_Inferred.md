# Function record: Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd8f0` |
| **Canonical name** | `Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_004cd8f0` |
| **Address** | `0x004cd8f0` |
| **Body** | `0x004cd8f0`–`0x004cd991` exclusive (**161 B** / `0xA1`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | host owned 0x30 grid-list object replace + populate |
| **Completion status** | **Dual A/B complete (W38-S)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

On a large **host**, replace the owned **0x30** list object at **`+0xe4fc`**: destroy old, `new`+default-ctor, store, then **scaled grid populate** with dims from stack, scale from nested `*(host+0xe4f8)+0x18`, and stack context.

## Signature

```c
// __thiscall; ECX = host*; stack (dim_a, dim_b, dim_c, ctx); void; ret 0x10
void Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred(
    void *host, uint32_t dim_a, uint32_t dim_b, uint32_t dim_c, uint32_t ctx);
```

## Callers / callees

| Direction | Detail |
|---|---|
| Callers | **none** static CODE/DATA xrefs in Ghidra (orphan) |
| Callees | `operator_new`; `FUN_005b3f60` (W30-O); `FUN_005b3fa0` (W37-L); owned scalar dtor |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cd8f0_FUN_004cd8f0.md`
- Annotated: `docs/reconstruction/raw/aa_004cd8f0_FUN_004cd8f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004cd8f0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004cd8f0_Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004cd8f0_Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred.md`
- Scaffold alias: `docs/reconstruction/functions/aa_004cd8f0_FUN_004cd8f0.md`

## Related (not owned)

| VA | Role |
|---|---|
| `0x005b3f60` | default ctor of 0x30 object (W30-O) |
| `0x005b3fa0` | scaled grid populate (W37-L) |
| `0x005b4260` | dead convenience ctor+populate |
| `0x004cd9a0` | sibling host path also writing `+0xe4fc` (different populate) |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / `ret 0x10` / 161 B | **Confirmed** |
| Slot `+0xe4fc` / scale from `+0xe4f8+0x18` | **Confirmed** |
| Populate this = new object | **Confirmed** (bytes) |
| Product host English / live callers | **Open** |

## Gaps

1. Product host class name.  
2. Why zero static xrefs.  
3. OOM populate-with-null-this behavior.  
4. Runtime / bit-exact / differential.
