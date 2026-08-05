# Function record: AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00985390` |
| **Canonical name** | `AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred` |
| **Ghidra name** | `FUN_00985390` |
| **Address** | `0x00985390`–`0x0098545e` exclusive (**206 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assets / assPack free-map |
| **Wave** | W33-P |
| **Completion status** | **Dual-sealed** accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Pack free-map **release**: erase live map node for `block`, then coalesce/insert free range `(block+0x18, block+0x1c)` into sorted vector. AL=`1` if map count hits 0.

## Signature

```c
uint8_t AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred(
    void* host /*ecx*/, void* block /*eax*/);
```

## Artifacts

See `aa_00985390_FUN_00985390.md` for full artifact table.

## Naming

**Inferred** from free-map + free-range coalesce CF next to AssPackManager packer VAs. No PDB plate. Reject gfxIndexBuff scaffold alias.
