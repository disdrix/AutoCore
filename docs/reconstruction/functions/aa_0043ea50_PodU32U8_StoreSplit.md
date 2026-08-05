# Function record: PodU32U8_StoreSplit

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ea50` |
| **Canonical name** | `PodU32U8_StoreSplit` |
| **Ghidra name** | `FUN_0043ea50` |
| **Address** | `0x0043ea50`–`0x0043ea5f` (**16 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | POD store helper (split-source u32+u8) |
| **Completion status** | **partial** — dual A/B **accept** (W32-M 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Store `*pU32` and `*pU8` into `dest` at +0 / +4 with no null check. Split-source ABI (not a single contiguous POD pointer).

## Signature

```c
void PodU32U8_StoreSplit(void* dest /*EAX*/,
                         const uint32_t* pU32 /*ECX*/,
                         const uint8_t* pU8 /*stack*/);
// RET 0x4
```

## Artifacts

- Scaffold record: `docs/reconstruction/functions/aa_0043ea50_FUN_0043ea50.md`
- Clean: `docs/reconstruction/reconstructed-exact/PodU32U8_StoreSplit.cpp`
- Raw / annotated / A/B / report: see scaffold record
