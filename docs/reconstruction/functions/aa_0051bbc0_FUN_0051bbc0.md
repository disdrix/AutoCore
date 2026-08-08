# Function record: FUN_0051bbc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bbc0` |
| **Canonical name** | `Map_FreeSubtree_Isnil29` |
| **Ghidra name** | `FUN_0051bbc0` |
| **Address** | `0x0051bbc0`–`0x0051bbf4` (**53 B** / `0x35`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` (STL map helper residual) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (WQ9E-H 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Canonical: `Map_FreeSubtree_Isnil29`
- Reject scaffold: `Named_CalleeOf_Named_CalleeOf_CVOGHBAIBase_GetTargetFromAggro_0051bbc0`

## Purpose

Map free-subtree (isnil@+0x29). Bytes seal left-walk omitted by decompiler. See named record.

## Signature (sealed)

```c
void __fastcall FUN_0051bbc0(void *tree_base, void *node);
// RET 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051bbc0_FUN_0051bbc0.md`
- Annotated: `docs/reconstruction/raw/aa_0051bbc0_FUN_0051bbc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Map_FreeSubtree_Isnil29.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0051bbc0.cpp`
- Named record: `docs/reconstruction/functions/aa_0051bbc0_Map_FreeSubtree_Isnil29.md`
- Dual A/B: `reviews/A_aa_0051bbc0_Map_FreeSubtree_Isnil29.md`, `reviews/B_aa_0051bbc0_Map_FreeSubtree_Isnil29.md`

## Callers / callees

- Callers: `Map_EraseRange` (`FUN_0051c7c0`), self
- Callees: self, `operator_delete`

## Confidence

| Claim | Level |
|---|---|
| Free-subtree CF (bytes) | High |
| ABI ECX + RET 4 | High |
| isnil@+0x29 | High |
| Product map type English | Open |
