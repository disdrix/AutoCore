# Function record: FUN_004bd1b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bd1b0` |
| **Canonical name** | `COList_ScalarDeletingDestructor` |
| **Ghidra name** | `FUN_004bd1b0` |
| **Address** | `0x004bd1b0`–`0x004bd1cd` (**30 B / `0x1E`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / COList |
| **Completion status** | **Human-refined** + dual A/B **accept** 2026-07-29 (W27-L) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004bd1b0_COList_ScalarDeletingDestructor.md`, `reviews/B_aa_004bd1b0_COList_ScalarDeletingDestructor.md` |
| **Last reviewed** | `2026-07-29` (W27-L) |

## Alias

- Ghidra: `FUN_004bd1b0`
- Named: `COList_ScalarDeletingDestructor`
- Structural: MSVC scalar-deleting dtor (vtbl[0])

## Purpose

Scalar-deleting destructor for **COList**: call body `COList_Destructor` (`FUN_004bbc70`); if `(flags & 1)` free heap with `operator_delete`; return `this`. Published as `PTR_FUN_009cb448[0]`.

## Signature (sealed)

```c
// Machine: __thiscall, ECX=this, stack flags, ret 4, returns this*
void* __thiscall COList_ScalarDeletingDestructor(void* self, uint8_t flags);
// Ghidra: void * __thiscall FUN_004bd1b0(void *param_1, byte param_2)
```

| Item | Evidence | Conf |
|---|---|---|
| Body size 30 B | `get_function_by_address` + full `read_memory` | **High** |
| `ret 4` | exit `C2 04 00` | **High** |
| Call body dtor | `E8` → `0x004bbc70` | **High** |
| flags&1 → delete | `F6 44 24 08 01` + `operator_delete` | **High** |
| vtbl[0] | DATA xref `0x009cb448` | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bd1b0_FUN_004bd1b0.md` (+ W27-L append)
- Annotated: `docs/reconstruction/raw/aa_004bd1b0_FUN_004bd1b0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/COList_ScalarDeletingDestructor.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004bd1b0.cpp`
- Named record: `docs/reconstruction/functions/aa_004bd1b0_COList_ScalarDeletingDestructor.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Xrefs** | DATA from `PTR_FUN_009cb448` slot 0 only (virtual) |
| **Callees** | `FUN_004bbc70` (`COList_Destructor`), `operator_delete` |

## Related

- `aa_004bbc70` `COList_Destructor` (body) — dual **accept** W26-J
- `aa_004bbfb0` `COList_Constructor` (ctor twin) — this wave
- `Client_InitInstance` / `FUN_0094a6a0` publishes host via ctor → `DAT_00b04830`

## Confidence

| Claim | Level |
|---|---|
| ABI / CF / vtbl[0] scalar pattern | **High** |
| Product class COList | **High** (twin + rdata) |
| Runtime / bit-exact | Open |
