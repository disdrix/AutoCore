# Function record: CSoundManager_AppendOggOrLxxExt_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00722790` |
| **Canonical name** | `CSoundManager_AppendOggOrLxxExt_Inferred` |
| **Ghidra name** | `FUN_00722790` |
| **Address** | `0x00722790` |
| **Body range** | `0x00722790`–`0x007227de` (78 / `0x4E` bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client audio / sound path extension |
| **Classification** | worker (leaf) |
| **Completion status** | **partial** — dual A/B **accept**; CF/ABI/strings sealed; product English open |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_00722790_CSoundManager_AppendOggOrLxxExt_Inferred.md`, `reviews/B_aa_00722790_CSoundManager_AppendOggOrLxxExt_Inferred.md` |
| **Last reviewed** | `2026-08-04` (W38-AG) |
| **Partition** | `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-AG) |

## Purpose

Mutating path helper: append **`.ogg`** or **`_lxx.ogg`** to a caller-owned C-string buffer, selected by a byte flag at **`host+0x308`**.

## Signature

```c
void __thiscall CSoundManager_AppendOggOrLxxExt_Inferred(
    void *host,     /* ECX; *(char*)(host+0x308) selects suffix */
    char *pathBuf); /* stack; must have room for +9 max incl NUL */
// RET 4
```

## Flag contract

| `*(char*)(host+0x308)` | Suffix | Image VA |
|---|---|---|
| `0` | `".ogg"` | `0x00A9D9A4` |
| nonzero | `"_lxx.ogg"` | `0x00AA91A0` |

## See also

Full artifacts table and callers: `aa_00722790_FUN_00722790.md`.
