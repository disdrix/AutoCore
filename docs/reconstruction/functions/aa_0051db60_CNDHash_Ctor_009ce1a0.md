# Function record: CNDHash_Ctor_009ce1a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051db60` |
| **Canonical name** | `CNDHash_Ctor_009ce1a0` |
| **Ghidra name** | `FUN_0051db60` |
| **Address** | `0x0051db60`–`0x0051dbd2` (**115 B** / `0x73`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (medal family; object vtbl `009ce1a0`) |
| **Completion status** | **Dual A/B present** (2026-07-29 W26-P) — accept-with-gaps |
| **Name status** | Role + vtbl stamp inferred; no body string |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `FUN_0051db60` | Ghidra scaffold |

## Purpose

Construct medal-family CNDHash:

1. Install vtbl **`009ce1a0`**
2. Zero fields; set `+0x08 = 1<<log2` (count), `+0x1C = log2`
3. Call **`CNDHash_AllocBucketTable_009ce090`** → table + sentinels + mask
4. Return `this`

## Signature

```c
void *__thiscall CNDHash_Ctor_009ce1a0(void *this, uint8_t log2); // ret 4; returns this
```

## Callers / callees

| Direction | Symbol | VA / note |
|---|---|---|
| Caller | static init | `0x009c0b57` (`log2=2`, `this=0x00b042e0`) |
| Callee | `CNDHash_AllocBucketTable_009ce090` (`FUN_0051ba40`) | `@ 0x0051dbba` |

## Family

| Sibling | Role |
|---|---|
| `CNDHash_AllocBucketTable_009ce090` `0x0051ba40` | alloc (also Recreate) |
| `CNDHash_FreeBuckets` `0x0051d150` | free twin |
| `FUN_0051dfe0` dtor | same vtbl family |
| `CNDHash_Recreate` `0x0051d230` | re-init (not ctor) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051db60_FUN_0051db60.md`
- Annotated: `docs/reconstruction/raw/aa_0051db60_FUN_0051db60.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_Ctor_009ce1a0.cpp`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_0051db60.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0051db60_CNDHash_Ctor_009ce1a0.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0051db60_CNDHash_Ctor_009ce1a0.md`
- FUN_ record: `docs/reconstruction/functions/aa_0051db60_FUN_0051db60.md`

## Confidence

| Claim | Level |
|---|---|
| vtbl `009ce1a0` + field init + Alloc call | **Confirmed** |
| thiscall; ret 4; returns this | **Confirmed** |
| N = 1≪log2 at +0x08 pre-Alloc | **Confirmed** |
| +0x24 not written | **Confirmed** |
| Role Ctor | **High** |
| Product/PDB symbol | **Open** |
| Runtime / bit-exact / diff | **Open** |
