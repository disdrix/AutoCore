# Function record: Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00581500` |
| **Canonical name** | `Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred` |
| **Ghidra name** | `FUN_00581500` |
| **Address** | `0x00581500`–`0x00581517` (**24 B** / `0x18`; pad `CC` after) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-fx / type-0xF stop + event-variant reload (MI public entry) |
| **Completion status** | **Dual A/B complete** (2026-07-29 OWN-ONLY W29-O) — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_00581500`
- W28-H referred as "public MI thunk `FUN_00581500`" for impl `Object_StopTypeF_ReloadEventVariant_Inferred`

## Purpose

MSVC multi-inheritance / vb **this-adjustor** public entry: rewrite ECX via `*(this-0x8C)` and dword at `+4`, then call `Object_StopTypeF_ReloadEventVariant_Inferred` (`0x00514d80`). Epilogue **`ret 4`**.

## Signature (image-sealed)

```c
// __thiscall ECX=subobject this; stack (ignored dword); ret 4; void
void Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred(void *self_sub);
```

## Artifacts

| Role | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00581500_FUN_00581500.md` |
| Annotated | `docs/reconstruction/raw/aa_00581500_FUN_00581500.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred.cpp` |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_00581500.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00581500_Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00581500_Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00581500_FUN_00581500.md` |
| Dual report | `docs/agents/task-dual-ab-00581500-00626530-w29o-report.md` |

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Caller (CALL) | `0x005d49e0` / site `0x005d49f8` | `FUN_005d49e0` (not OWN) |
| Flow JMP peers | 7 sites | MSVC adjustors → this entry |
| Callee | `0x00514d80` | `Object_StopTypeF_ReloadEventVariant_Inferred` (W28-H) |

## Layout / constants

| Item | Value | Conf |
|---|---|---|
| Adjust base offset | `-0x8C` (`0xFFFFFF74`) | **High** |
| Vb dword index | `+4` | **High** |
| Epilogue | `ret 4` | **High** |
| Product subobject English | open | **Inferred name only** |

## Confidence

| Claim | Level |
|---|---|
| Bytes / this-adjust math / call target | **High** |
| ABI ret 4 | **High** |
| Role as public entry for W28-H impl | **High** |
| Product/PDB method spelling | **Tentative / Inferred** |
