# Function record: Map_Tidy_FreeHead_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e180` |
| **Canonical name** | `Map_Tidy_FreeHead_B` |
| **Ghidra name** | `FUN_0051e180` |
| **Address** | `0x0051e180`–`0x0051e1ad` inclusive (**46 bytes** / exclusive end `0x0051e1ae`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map tidy (host of dualed `Map_EraseRange_B`; isnil@+0x29) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9F-H OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC-style **map tidy**: full-range erase via dualed `Map_EraseRange_B`, free the sentinel head node, null `head` and `size`. Does **not** free the map facade object. Same 46 B template as `Map_Tidy_FreeHead` (different erase callee).

## Signature (byte-sealed)

```c
void __fastcall Map_Tidy_FreeHead_B(void *map); // ECX = map*; bare RET (C3)
// head @ map+4; size @ map+8
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051e180_FUN_0051e180.md`
- Annotated: `docs/reconstruction/raw/aa_0051e180_FUN_0051e180.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_Tidy_FreeHead_B.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051e180.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051e180_Map_Tidy_FreeHead_B.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051e180_Map_Tidy_FreeHead_B.md`
- Alias record: `docs/reconstruction/functions/aa_0051e180_FUN_0051e180.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_009c3970` | atexit: `MOV ECX,0xb0427c` / `JMP` |
| Callee | `Map_EraseRange_B` `0x0051d880` | full-range erase (dualed) |
| Callee | `operator_delete` | free sentinel head only |

## Confidence

| Claim | Level |
|---|---|
| Tidy CF (erase full + free head + null) | **Confirmed** (bytes for null) |
| ABI ECX=map; bare ret | **Confirmed** |
| Does not free map facade | **Confirmed** |
| Product host class English | Open |
| Runtime / image diff | Open |
