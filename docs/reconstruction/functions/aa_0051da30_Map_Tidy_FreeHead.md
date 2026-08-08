# Function record: Map_Tidy_FreeHead

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051da30` |
| **Canonical name** | `Map_Tidy_FreeHead` |
| **Ghidra name** | `FUN_0051da30` |
| **Address** | `0x0051da30`–`0x0051da5d` inclusive (**46 bytes** / exclusive end `0x0051da5e`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map tidy (host of dualed `Map_EraseRange`; isnil@+0x29) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9E-J OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC-style **map tidy**: full-range erase via dualed `Map_EraseRange`, free the sentinel head node, null `head` and `size`. Does **not** free the map facade object (outer caller may). Same 46 B template as `StdTree_Tidy_FreeHead_Bare_Val12`.

## Signature (byte-sealed)

```c
void __fastcall Map_Tidy_FreeHead(void *map); // ECX = map*; bare RET (C3)
// head @ map+4; size @ map+8
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051da30_FUN_0051da30.md`
- Annotated: `docs/reconstruction/raw/aa_0051da30_FUN_0051da30.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_Tidy_FreeHead.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051da30.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051da30_Map_Tidy_FreeHead.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051da30_Map_Tidy_FreeHead.md`
- Alias record: `docs/reconstruction/functions/aa_0051da30_FUN_0051da30.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_00518ec0` | object map slot `+0x68` @ `0x00518fd3` |
| Caller | `Unwind@009a8e4c` | SEH cleanup |
| Callee | `Map_EraseRange` `0x0051c7c0` | full-range erase (dualed WQ9D-H) |
| Callee | `operator_delete` | free sentinel head only |

## Confidence

| Claim | Level |
|---|---|
| Tidy CF (erase full + free head + null) | **Confirmed** (bytes for null) |
| ABI ECX=map; bare ret | **Confirmed** |
| Does not free map facade | **Confirmed** |
| Product host class English | Open |
| Runtime / image diff | Open |
