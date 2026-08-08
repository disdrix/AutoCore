# Function record: StdMap_StringKey_InsertOrFind_Via401db0_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401c50` |
| **Canonical name** | `StdMap_StringKey_InsertOrFind_Via401db0_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_00401c50` |
| **Address** | `0x00401c50`–`0x00401d26` inclusive (**215 B** / `0xD7`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body pad** | `CC` from `0x00401d27` |
| **System** | MSVC std::map unique insert-or-find (string key, isnil2D) |
| **Host context** | missions-progression — sole caller nested under Mission null-dialog string path |
| **Agent** | MEGA-064 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

Unique **insert-or-find** for **isnil@+0x2d** maps keyed by **`std::basic_string`**. Lower-bound walk via IAT `operator<`; optional dualed predecessor; miss → undualed insert worker `FUN_00401db0`; hit → `inserted=0` without value rewrite.

## Signature

```c
struct InsertPair_StringKey {
  MapNode_StringKey_Isnil2D* it;  // +0x00
  uint8_t inserted;               // +4
};

// stack[0] = map shell* (head@+4, size@+8)
// EAX      = const basic_string* key
// EBX      = InsertPair* out
// return   = EBX; RET 4
InsertPair_StringKey* StdMap_StringKey_InsertOrFind_Via401db0_Inferred(
    MapShell_StringKey_Isnil2D* map /*stack*/,
    const BasicString_Char* key /*EAX*/,
    InsertPair_StringKey* out /*EBX*/);
```

## Node layout

| Off | Field |
|----:|-------|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C | `basic_string` key |
| +0x2C | color |
| +0x2D | isnil |

## Call graph

| Role | Target |
|---|---|
| **Caller** | `FUN_00980160` @ `0x009801dd` (1 site) |
| Compare | IAT `0x009c62e8` → `std::operator<` basic_string (`0x006eadd0`) |
| Predecessor | `StdTree_IteratorDecrement` (`0x004313d0`) dualed W22-O — **EDX** ABI |
| Insert worker | `FUN_00401db0` (**undualed**) |
| Twin (do not merge) | `StdMap_StringKey_InsertOrFind` (`0x004309c0`) insert via `0x00430b60` |

## Evidence summary

- Live decompile ≡ raw CF; body 215 B; **RET 4** ×3 sealed.
- isnil@+0x2d on all walk guards; key @+0x0C; IAT string `<`.
- Call-site: EBX=out, EAX=key, stack=map@host+0x0C.
- Pred dualed; insert worker residual.
- Reject Mission null-dialog Named_CalleeOf scaffold as product name.
- Product demangle open → `_Inferred`.
- Monomorph twin `004309c0` same ABI/CF; different insert monomorph.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdMap_StringKey_InsertOrFind_Via401db0_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00401c50.cpp`
- Raw: `docs/reconstruction/raw/aa_00401c50_FUN_00401c50.md`
- Annotated: `docs/reconstruction/raw/aa_00401c50_FUN_00401c50.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00401c50_StdMap_StringKey_InsertOrFind_Via401db0_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00401c50_StdMap_StringKey_InsertOrFind_Via401db0_Inferred.md`
- Report: `docs/agents/task-dual-ab-00401c50-mega-064-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + ABI stack/EAX/EBX RET 4 | **High** |
| isnil@+0x2d / key@+0x0C / string `<` | **High** |
| Role unique insert-or-find | **High** |
| Name `_Inferred` + Via401db0 | **Inferred** |
| Mapped value layout / product map | Open |
| Runtime | Open |
