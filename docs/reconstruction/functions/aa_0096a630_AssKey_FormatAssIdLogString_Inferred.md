# Function record: AssKey_FormatAssIdLogString_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096a630` |
| **Canonical name** | `AssKey_FormatAssIdLogString_Inferred` |
| **Ghidra name** | `FUN_0096a630` |
| **Prior aliases** | `Named_CalleeOf_Named_gfxBody_0096a630` (**rejected** — multi-caller; not gfxBody-owned) |
| **Address** | `0x0096a630`–`0x0096a6e1` exclusive (**177 B** / `0xB1`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | asset / ass-key logging (`client::ass`) |
| **Completion status** | **Dual-sealed 2026-08-04 W38-B** — format/ABI/null-fallback **High**; key product type **Inferred** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Build a log-facing `std::basic_string` of the form **`assId: [<name>]`** from a key object whose first dword is a `char*` name (null treated as empty). Heavy AssPreloader / asset-load diagnostic helper — not a preload orchestrator.

## Signature

```c
// __thiscall; ECX = key*; stack out basic_string*; RET 4; returns out*
basic_string<char>* __thiscall AssKey_FormatAssIdLogString_Inferred(
    int* key /*ECX*/,
    basic_string<char>* out /*stack*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0096a630_FUN_0096a630.md`
- Annotated: `docs/reconstruction/raw/aa_0096a630_FUN_0096a630.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AssKey_FormatAssIdLogString_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0096a630.cpp`
- Reviews: `reviews/A_aa_0096a630_AssKey_FormatAssIdLogString_Inferred.md`, `reviews/B_aa_0096a630_AssKey_FormatAssIdLogString_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0096a630_FUN_0096a630.md`
- Agent report: `docs/agents/task-dual-ab-00457cc0-0096a630-w38b-report.md`

## Constants

| VA / symbol | Value | Confidence |
|---|---|---|
| `0x00aa1c18` | `"assId: [%s]"` | **High** (read_memory) |
| `PTR_DAT_00afa2bc` → `0x00a1419b` | empty `""` for null names | **High** |
| SEH | `LAB_009ab872` | **High** |
| Stack frame | `SUB ESP,0x124` + SEH; epilogue `ADD ESP,0x130` | **High** |

## Callers / callees (representative)

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `FUN_00970e50` AssPreloader_RetireStale… | key@node+0xC |
| Caller | `FUN_00971050` | AssPreloader |
| Caller | `FUN_00971280` TryPreloadChild… | unable-to-preload log |
| Caller | `FUN_00971480` DrainSuccessResults… | tally log |
| Caller | `FUN_00581e20` CVOGGraphicsBase_LoadNextChildAsset | asset name |
| Caller | `FUN_00583fa0`, `FUN_0058f780`, `FUN_005911b0`, `FUN_005f44c0` | load paths |
| Caller | `FUN_0048edc0` | dual-site format |
| Caller | geometry/media helpers (`00764830`, `0073d9b0`, …) | 39 xrefs total |
| Callee | `sprintf` | format into 260-byte stack buf |
| Callee | `std::basic_string` ctor / `operator=` / copy / dtor | IAT |

## Confidence

| Claim | Level |
|---|---|
| Format string + sprintf + assign/copy out | **High** |
| thiscall key + stack out + RET 4 | **High** |
| Null name → empty string | **High** |
| Role = log formatter (not load engine) | **High** |
| Product key class / PDB name | **Inferred** |
