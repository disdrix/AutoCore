# Function record: Object_CompositeStopTypeF_MIEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d49e0` |
| **Canonical name** | `Object_CompositeStopTypeF_MIEntry_Inferred` |
| **Ghidra name** | `FUN_005d49e0` |
| **Address** | `0x005d49e0`–`0x005d4a01` inclusive (**34 B** / `0x22`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object stop / type-0xF reload (composite MI public entry) |
| **Completion status** | **Dual sealed W30-K** — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005d49e0_Object_CompositeStopTypeF_MIEntry_Inferred.md`, `reviews/B_aa_005d49e0_Object_CompositeStopTypeF_MIEntry_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W30-K) |

## Alias

- `FUN_005d49e0` (Ghidra)

## Purpose

Public multi-inheritance entry that sequences two stop helpers with fixed this-adjusts: optional nested stop at `this-0x90` (`FUN_0053d4b0`), then type-0xF stop/reload MI thunk at `this-0x10` (`FUN_00581500` / W29-O). Reached only via four MI JMP adjustors; is the sole direct CALL site of `00581500`.

## Signature (image-sealed)

```c
// __thiscall ECX=this_entry; stack (param); ret 4; void
void __thiscall Object_CompositeStopTypeF_MIEntry_Inferred(void *self, uint32_t param);
```

## Callers / callees

| Direction | Target |
|---|---|
| Direct CALL callers | **none** |
| JMP adjustor xrefs (4) | `0x004cc640`, `0x00506890`, `0x0051ec60`, `0x0053bc70` |
| Callees | `FUN_0053d4b0` (`0x0053d4b0`); `Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred` (`0x00581500`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005d49e0_FUN_005d49e0.md`
- Annotated: `docs/reconstruction/raw/aa_005d49e0_FUN_005d49e0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Object_CompositeStopTypeF_MIEntry_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005d49e0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_005d49e0_FUN_005d49e0.md`

## Confidence

| Claim | Level |
|---|---|
| Body size / this-adjusts / ret 4 | **High** |
| Callee targets | **High** |
| JMP-only entry model (4 adjustors) | **High** |
| Product method English | **Low** (open) |
