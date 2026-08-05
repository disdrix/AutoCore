# Function record: Map_EraseRange_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053a260` |
| **Canonical name** | `Map_EraseRange_Val12` |
| **Ghidra name** | `FUN_0053a260` |
| **Address** | `0x0053a260` |
| **Body** | `0x0053a260`–`0x0053a314` exclusive (**180** B / `0xB4`); **`ret 0x0c`**; pad `CC` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `_Tree` range erase (Val12 / isnil@+0x19) |
| **Completion status** | **Dual-sealed (W28-S)** |
| **Bit-for-bit / runtime / diff** | Open |
| **Classification** | worker |

## Alias

- Ghidra: `FUN_0053a260`
- Role peer of single-node `Map_EraseNode_Val12` (`aa_005399f0`)

## Purpose

MSVC-style map/set **range erase**:

1. **Full range** (`first == *head && last == head`): `FUN_00538690(head->parent)` free all; reset head links; `size=0`; `*outIt = *head`.
2. **Partial**: in-order successor (isnil@+0x19) + `Map_EraseNode_Val12` per node; `*outIt = last`.

Map facade: `head @ +4`, `size @ +8`.

## Signature (sealed)

```c
void __thiscall Map_EraseRange_Val12(
    void *map,       // ECX
    void **outIt,    // receives end iterator after erase
    void *first,
    void *last);     // exclusive
// ret 0x0c
```

## Node layout (Val12)

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0c | value (12 bytes payload family) |
| +0x18 | color |
| +0x19 | isnil |

## Artifacts

- See twin FUN record for full path table.

## Callers / callees

| Direction | Symbols |
|---|---|
| Callers | `FUN_0053ba50` (map clear + delete head) |
| Callees | `FUN_00538690` (subtree free), `FUN_005399f0` |

## Confidence

| Claim | Level |
|---|---|
| Range erase contract | **High** |
| ABI ret 0x0c | **High** |
| Val12 family | **High** |
| Product demangle | **Low–Med** |
