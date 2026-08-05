# Function record: COList_Destructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbc70` |
| **Canonical name** | `COList_Destructor` |
| **Ghidra name** | `FUN_004bbc70` |
| **Address** | `0x004bbc70`–`0x004bbea4` (**565 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / COList |
| **Completion status** | **Human-refined** + dual A/B **accept** 2026-07-29 (W26-J) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004bbc70_COList_Destructor.md`, `reviews/B_aa_004bbc70_COList_Destructor.md` |
| **Last reviewed** | `2026-07-29` (W26-J) |

## Alias

- `FUN_004bbc70` (Ghidra)
- Prior scaffold: `Named_VOG_DEBUG_STOP_004bbc70` (string only)

## Purpose

**COList** C++ destructor: reinstall vtbl `PTR_FUN_009cb448`, construct stack `ThreadSafeObjectList`, traverse two hash members collecting objects with `+0xac≠0`, drain via `PopFront` + `ClonedObjectList_TakeByCoid`, virtual-delete owned slots, dtor stack list, free vector buffers.

## Signature (sealed)

```c
// Machine: __thiscall, ECX=this, frame 0x44, bare ret, void
// Ghidra: void __fastcall FUN_004bbc70(undefined4 *param_1)
void __thiscall COList_Destructor(COList* this);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=this | `8B F1` | **High** |
| frame `0x44` | `83 EC 44` / `83 C4 44` | **High** |
| vtbl `0x009cb448` | `C7 06 48 B4 9C 00` | **High** |
| product class COList | rdata `COList::Insert` at vtbl adjacency | **High** |
| stack list vtbl `0x009cb368` | dword store before ICS | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bbc70_FUN_004bbc70.md` (+ W26-J append)
- Annotated: `docs/reconstruction/raw/aa_004bbc70_FUN_004bbc70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/COList_Destructor.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004bbc70.cpp`
- Scratch: `docs/reconstruction/tmp/a_004bbc70.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Caller** | `FUN_004bd1b0` scalar-deleting dtor only |
| **Callees** | `FUN_004024d0`, `FUN_0040b020`, `FUN_004bb970`, `FUN_004bcbf0`, `FUN_007a4480`, `InitializeCriticalSection`, `operator_delete` |

## Related

- `FUN_004bbfb0` COList ctor (same vtbl; `DAT_00b04830`)
- `aa_004bb970` ClonedObjectList_TakeByCoid_Inferred
- `aa_0040b020` / `aa_004bcbf0` / `aa_004024d0` list primitives

## Confidence

| Claim | Level |
|---|---|
| ABI / vtbl / COList class / stack list CF | **High** |
| TakeByCoid drain args from payload fields | **High** |
| Slot English beyond indices | **Partial** |
| Runtime / bit-exact | Open |
