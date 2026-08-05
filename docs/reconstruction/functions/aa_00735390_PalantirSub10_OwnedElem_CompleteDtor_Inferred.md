# Function record: PalantirSub10_OwnedElem_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00735390` |
| **Canonical name** | `PalantirSub10_OwnedElem_CompleteDtor_Inferred` |
| **Ghidra name** | `FUN_00735390` |
| **Address** | `0x00735390`–`0x00735403` exclusive (**115 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir |
| **Completion status** | **Dual A/B complete (W37-N)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Complete dtor for owned elements of Palantir nested subobject `+0x10` pointer vector (consumer `PalantirSub10_DestroyOwnedPtrVecAndComUninit`, W35-J).

## Signature

```c
void __stdcall PalantirSub10_OwnedElem_CompleteDtor_Inferred(void* elem);
```

## Layout (elem*)

| Off | Role |
|-----|------|
| +0x00 | `std::string` |
| +0x1C | `std::string` |
| +0x48 | COM iface* (Release) |
| +0x70C | vector host (EBX this for `FUN_00465d70`; stride 0x24) |
| span | ≥ 0x71C |

## Artifacts

See `aa_00735390_FUN_00735390.md`.

## Confidence

| Claim | Level |
|---|---|
| Structural name + ABI + layout | **High** |
| Product class English | **Open** |
