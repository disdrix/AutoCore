# Function record: StdMap_OperatorIndex_Tfid_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cc400` |
| **Canonical name** | `StdMap_OperatorIndex_Tfid_Isnil29_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_004cc400` |
| **Address** | `0x004cc400` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x004cc400`–`0x004cc469` exclusive (**105 B** / `0x69`) |
| **System** | MSVC `std::map::operator[]` |
| **Agent** | WQ9G-C OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style unique **operator[]** for trees with **color @ +0x28** / **isnil @ +0x29**. TFID-shaped pair key (hi signed @ node+0x14, lo unsigned @ +0x10). On miss, insert via dualed `StdTree_InsertHint_Isnil29_Inferred` (`0x004cc220`) with mapped default **0**. Always returns pointer to **mapped @ node+0x20**.

## Signature

```c
int32_t *__thiscall StdMap_OperatorIndex_Tfid_Isnil29_Inferred(
    MapShell_Isnil29 *map,    // ECX  head@+4
    const uint32_t *key16);   // 4 dwords
// RET 4
```

## Layout / constants

| Item | Value |
|---|---|
| Key compare | hi signed primary @ +0x14; lo unsigned secondary @ +0x10 |
| Key storage | 16 B @ +0x10..+0x1C (pair order + ext) |
| Mapped | int @ +0x20 |
| isnil / color | +0x29 / +0x28 |
| Default mapped on insert | `0` |

## Call graph

| Role | Target |
|---|---|
| **Callers** | `FUN_004ca760` (writes score into returned mapped*); `FUN_004ea350` ×3; `0x005dd869` |
| lower_bound | `StdMap_LowerBound_Tfid_Isnil29` `0x004cb4b0` (W31-N) |
| insert-hint | `StdTree_InsertHint_Isnil29_Inferred` `0x004cc220` (WQ9F-E; **this is sole caller**) |

## Evidence summary

- Live decompile ≡ CF; **RET 4** + `ADD EAX,0x20` sealed via `read_memory`.
- Sole xref call into dualed insert-hint.
- Peer aggro layout (TFID@+0x10, score@+0x20) matches return slot.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdMap_OperatorIndex_Tfid_Isnil29_Inferred.cpp`
- Raw: `docs/reconstruction/raw/aa_004cc400_FUN_004cc400.md`
- Annotated: `docs/reconstruction/raw/aa_004cc400_FUN_004cc400.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_004cc400_StdMap_OperatorIndex_Tfid_Isnil29_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004cc400_StdMap_OperatorIndex_Tfid_Isnil29_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_004cc400_FUN_004cc400.md`
