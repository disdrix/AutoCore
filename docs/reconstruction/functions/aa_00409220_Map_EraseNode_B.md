# Function record: Map_EraseNode_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409220` |
| **Canonical name** | `Map_EraseNode_B` |
| **Ghidra symbol** | `FUN_00409220` |
| **Address** | `0x00409220`–`0x004094b4` exclusive (**660 B** by bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x29 family) |
| **Wave** | WQ9E-G OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_00409220`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Client_CreateVehicleObjectApply_00409220` (**narrow** — reject)
- Twin: `Map_EraseNode` (`aa_0051cb40` / `0x0051cb40`, W19-I)

## Purpose

Erase one non-nil node from an MSVC-style map/set tree (isnil@+0x29). Writes successor into `*outIt`; decrements `map->size` after free. Structural twin of dualed `Map_EraseNode` — same L/R rotates, Min, Max, successor callees; different length of throw construction.

## Signature

```c
void __thiscall Map_EraseNode_B(
    /*ECX*/ MapShell* map,
    Node** outIt,
    Node* pNode);
// RET 8; *outIt = successor; size-- if >0 after operator_delete
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x0051cb40` | `Map_EraseNode` | primary twin |
| `0x004192a0` | `StdTree_Lrotate_Isnil29` | left rotate |
| `0x004192f0` | `StdTree_Rrotate_Isnil29_Inferred` | right rotate |
| `0x0051b5d0` | `StdTree_Min_Isnil29` | leftmost |
| `0x00421b50` | `StdTree_Max_Isnil29_Inferred` | rightmost |
| `0x004cb270` | iterator successor | ++ |
| `0x0051c7c0` / `0x0051d880` | `Map_EraseRange` / `_B` | range wrappers (other VA) |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00409220_FUN_00409220.md`
- Annotated: `docs/reconstruction/raw/aa_00409220_FUN_00409220.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Map_EraseNode_B.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00409220.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00409220_Map_EraseNode_B.md`
- Review B: `docs/reconstruction/reviews/B_aa_00409220_Map_EraseNode_B.md`
- Scaffold record: `docs/reconstruction/functions/aa_00409220_FUN_00409220.md`

## Callers / callees

| **Callers (5)** | `FUN_00407d70`, `FUN_005a0470`, `FUN_005a3750`, `FUN_00807550`, `FUN_008078b0` |
| **Xrefs** | 6 UNCONDITIONAL_CALL |
| **Callees** | successor, Min, Max, L/R rotate, `operator_delete`, throw |

## Confidence

| Claim | Level |
|---|---|
| Role single-node erase | High / structural Confirmed |
| ABI RET 8 + post-delete commit | Confirmed (bytes) |
| isnil@+0x29 color@+0x28 | Confirmed |
| Product English | Open (structural name without `_Inferred`, peer of `Map_EraseNode`) |
