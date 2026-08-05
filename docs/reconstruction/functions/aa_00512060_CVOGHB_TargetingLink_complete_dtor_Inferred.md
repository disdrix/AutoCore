# Function record: CVOGHB_TargetingLink_complete_dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512060` |
| **Canonical name** | `CVOGHB_TargetingLink_complete_dtor_Inferred` |
| **Ghidra name** | `FUN_00512060` |
| **Address** | `0x00512060` |
| **Body range** | `0x00512060`–`0x0051206a` (11 B; exclusive end `0x0051206b`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | heartbeat / targeting-link |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes sealed; product mangled / runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00512060_CVOGHB_TargetingLink_complete_dtor_Inferred.md`, `reviews/B_aa_00512060_CVOGHB_TargetingLink_complete_dtor_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W20-A) |

## Alias

- `FUN_00512060` (Ghidra)
- Complete-dtor body shared by `thunk_FUN_00512060` @ `0x0051b890` (JMP alias)

## Purpose

**MSVC complete object destructor** for base targeting-link heartbeat family (`PTR_FUN_009cdfb0`):

1. Restore family vtbl `*this = 0x009cdfb0`.
2. Tail into base HB dtor `FUN_00508390` (sets `009cdab0`, optional owner-list detach via `FUN_005085b0`).

Not the scalar-deleting wrapper (`FUN_00512070` — that calls this then maybe `operator_delete`).

## Signature

```c
void __fastcall CVOGHB_TargetingLink_complete_dtor_Inferred(void *thisHb /* ECX */);
// retail: mov [ecx], 009cdfb0; jmp FUN_00508390
```

## Algorithm

1. `*thisHb = PTR_FUN_009cdfb0`
2. `FUN_00508390(thisHb)` (tail)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00512060_FUN_00512060.md`
- Annotated: `docs/reconstruction/raw/aa_00512060_FUN_00512060.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHB_TargetingLink_complete_dtor_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00512060.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00512060-0094b520-w20a-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00508390` only (tail jmp) |
| **Callers** | `FUN_00512070` CALL @ `0x00512073`; `thunk_FUN_00512060` JMP @ `0x0051b890` |
| **DATA** | family vtbl symbol `PTR_FUN_009cdfb0` |

## Confidence

| Claim | Level |
|---|---|
| Body = vtbl write + tail to base dtor | **High** (bytes + decompile) |
| Vtbl imm `0x009cdfb0` | **High** (`read_memory`) |
| Role = complete dtor (not scalar) | **High** (sibling scalar dual) |
| Class family targeting-link | **High** (ctor dual / vtbl family) / product RTTI **Open** |
| Product/PDB mangled name | Open |

## Related

- `aa_00512070` CVOGHB_TargetingLink_scalar_dtor_Inferred (calls this)
- `aa_0051b870` CVOGHBPlayerTargetingLink_scalar_dtor (uses thunk → this body)
- `aa_00604d40` CVOGHB_TargetingLink_ctor_Inferred (installs same vtbl)
- `aa_00508390` / `aa_005085b0` base detach path (not owned this dual)
