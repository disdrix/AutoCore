# Function record: StdTree_EraseAll_Shell10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00441720` |
| **Canonical name** | `StdTree_EraseAll_Shell10_Inferred` |
| **Ghidra name** | `FUN_00441720` |
| **Address** | `0x00441720`–`0x004417d1` inclusive (**178 B** / `0xB2`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map-set (isnil@+0x1d Shell10); parent dual `gfxUIWindow_CompleteDtor` `0x00759de0` |
| **Completion status** | **Dual sealed MEGA-135** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (terminal false) |

## Purpose

Range erase shell for the **Shell10** red-black tree family:

- **isnil @ +0x1d**, **color @ +0x1c**, value payload **0x10** bytes at `+0x0c`.
- Full-clear fast path frees via `FUN_00440c90`, resets head, zeros size.
- Partial path: successor then `FUN_00442000`.
- Retail ABI: **EDI = tree**, stack `(outIt, first, last)`, **`RET 0xC`**.

## Signature

```c
// Portable: tree explicit. Retail: tree in EDI.
MapNode_Shell10 **StdTree_EraseAll_Shell10_Inferred(
    MapShell_Shell10 *tree,
    MapNode_Shell10 **outIt,
    MapNode_Shell10 *first,
    MapNode_Shell10 *last);
```

## Naming evidence

| Evidence | Result |
|---|---|
| Partition hint `StdTree_EraseAll_Shell10` | matched |
| Structural Shell10 from isnil@+0x1d | sealed |
| Product/PDB demangle | open → **`_Inferred`** |
| Scaffold `Named_CalleeOf_*` | none present for this VA |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00441720_FUN_00441720.md` |
| Annotated | `docs/reconstruction/raw/aa_00441720_FUN_00441720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAll_Shell10_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00441720.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00441720_FUN_00441720.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00441720_StdTree_EraseAll_Shell10_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00441720_StdTree_EraseAll_Shell10_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00441720-mega-135-report.md` |

## Callers / callees

- **Callers:** `FUN_004401d0`, `gfxUIWindow_CompleteDtor` (`0x00759de0`)
- **Callees:** `FUN_00440c90`, `FUN_00442000`

## Confidence

| Claim | Level |
|---|---|
| Name structural (EraseAll + Shell10 + isnil1d) | **High** |
| ABI / CF sealed | **High** |
| Product type English | Tentative / open |
