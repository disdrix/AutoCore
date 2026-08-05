# Function record: CVOGSectorMap_Destructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d64d0` |
| **Canonical name** | `CVOGSectorMap_Destructor` |
| **Ghidra name** | `FUN_004d64d0` |
| **Address** | `0x004d64d0`–`0x004d6c77` (**1960 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / CVOGSectorMap |
| **Completion status** | **Human-refined** + dual A/B **accept-with-gaps** 2026-07-29 (W26-J) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004d64d0_CVOGSectorMap_Destructor.md`, `reviews/B_aa_004d64d0_CVOGSectorMap_Destructor.md` |
| **Last reviewed** | `2026-07-29` (W26-J) |

## Alias

- `FUN_004d64d0` (Ghidra)
- Prior scaffold: `Named_VOG_DEBUG_STOP_004d64d0` (string only; not product method name)

## Purpose

**CVOGSectorMap** C++ destructor body: reinstall vtbl `PTR_FUN_009cc770`, decrement `_DAT_00b037e4`, destroy primary CNDHash under traversal lock, virtual-delete owned members, drain embedded lists via `ThreadSafeObjectList_PopFront`, run subsystem teardown helpers, free buffer triples across the `0xE920` object.

## Signature (sealed)

```c
// Machine: __thiscall, ECX=this, frame sub/add esp 8, bare ret, void
// Ghidra: void __fastcall FUN_004d64d0(undefined4 *param_1)
void __thiscall CVOGSectorMap_Destructor(CVOGSectorMap* this);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=this | `8B F1` | **High** |
| bare ret | `C3` after `add esp,8` | **High** |
| vtbl `0x009cc770` | `C7 06 70 C7 9C 00` | **High** |
| product class | twin ctor + `@@new CVOGSectorMap` | **High** |
| counter `--` | `83 2D E4 37 B0 00 01` | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004d64d0_FUN_004d64d0.md` (+ W26-J append)
- Annotated: `docs/reconstruction/raw/aa_004d64d0_FUN_004d64d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGSectorMap_Destructor.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004d64d0.cpp`
- Scratch: `docs/reconstruction/tmp/a_004d64d0.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Caller** | `Catch@0094b325` @ `0x0094b34e` only (InitInstance failure: dtor + `operator_delete` on client+`0xe04`) |
| **Callees** | `FUN_0040b020`, `FUN_004bcbf0`, `FUN_004e3610`, `FUN_004e72xx` family, `FUN_00497360`, `FUN_004d2970`, `FUN_005b0680`, `FUN_005bf720`, `FUN_007a4480`, `operator_delete` |

## Related

- `aa_004d8a10` CVOGSectorMap_Constructor (vtbl + counter twin)
- `aa_004d6c80` CVOGSectorMap_StepTo
- `aa_0040b020` / `aa_004bcbf0` list primitives

## Confidence

| Claim | Level |
|---|---|
| ABI / vtbl / void / product class | **High** |
| Hash destroy + cascade structure | **High** |
| Sequential free model vs decompiler nesting | **High** (bytes) |
| Full 0xE920 field English | **Partial / Open** |
| Runtime / bit-exact | Open |
