# Function record: COList_ScalarDeletingDestructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bd1b0` |
| **Canonical name** | `COList_ScalarDeletingDestructor` |
| **Ghidra name** | `FUN_004bd1b0` |
| **Address** | `0x004bd1b0`–`0x004bd1cd` (**30 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / COList |
| **Completion status** | **Human-refined** + dual A/B **accept** 2026-07-29 (W27-L) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004bd1b0_COList_ScalarDeletingDestructor.md`, `reviews/B_aa_004bd1b0_COList_ScalarDeletingDestructor.md` |
| **Last reviewed** | `2026-07-29` (W27-L) |

## Alias

- `FUN_004bd1b0` (Ghidra)
- MSVC scalar-deleting destructor (vtbl[0] of `PTR_FUN_009cb448`)

## Purpose

**COList** scalar-deleting destructor: run body destructor `COList_Destructor`, optionally `operator_delete(this)` when `(flags & 1)`, return `this`. Standard MSVC `ret 4` pattern.

## Signature (sealed)

```c
void* __thiscall COList_ScalarDeletingDestructor(void* self, uint8_t flags);
// ECX=this; stack flags; ret 4; EAX=this
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=this | `8B F1` | **High** |
| ret 4 | `C2 04 00` | **High** |
| Body call | relative `E8` → `FUN_004bbc70` | **High** |
| flags bit0 | `F6 44 24 08 01` | **High** |
| vtbl[0] | `read_memory` `@0x009cb448` = `B0 D1 4B 00` | **High** |

## Control flow (sealed)

```
ESI = this
call COList_Destructor          // FUN_004bbc70
if (flags & 1):
  operator_delete(this)
EAX = this
ret 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bd1b0_FUN_004bd1b0.md`
- Annotated: `docs/reconstruction/raw/aa_004bd1b0_FUN_004bd1b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/COList_ScalarDeletingDestructor.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004bd1b0.cpp`

## Callers / callees

| Direction | Notes |
|---|---|
| **Xrefs** | DATA `0x009cb448` (vtbl[0]) only |
| **Callees** | `COList_Destructor` (`0x004bbc70`), `operator_delete` |

## Related

- `aa_004bbc70` COList_Destructor
- `aa_004bbfb0` COList_Constructor
- InitInstance log adjacency: `"before CVOGClonedObjectList"` then `operator_new(0x58)` + ctor(5,10) → `DAT_00b04830`

## Confidence

| Claim | Level |
|---|---|
| ABI / CF / scalar-delete contract | **High** |
| Product class COList | **High** |
| Runtime / bit-exact | Open |
