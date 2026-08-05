# Function record: TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c6720` |
| **Canonical name** | `TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_005c6720` |
| **Address** | `0x005c6720` |
| **Body** | `0x005c6720`–`0x005c6788` exclusive (**104 B** / `0x68`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | track-manager payload ↔ object match |
| **Completion status** | **Dual A/B complete (W38-S)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Leaf predicate: does this **track-list payload** refer to the given **object**?

- Both TFIDs fully invalid (`lo & hi == 0xFFFFFFFF`) → pointer identity via `payload+0x10`.
- Else → TFID triple compare (i32/i32/i8) against object TFID at `object+*(*(object+4)+4)+0x164`.

## Signature

```c
// __thiscall; ECX = payload*; stack (object*); returns bool; ret 4
uint8_t TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred(void *payload, void *object);
```

## Callers / callees

| Direction | Detail |
|---|---|
| Callers | `FUN_004bfd10` (TrackMgr untrack, W37-T); `FUN_004bfdb0` (set `payload+0x51`) |
| Callees | none (leaf) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005c6720_FUN_005c6720.md`
- Annotated: `docs/reconstruction/raw/aa_005c6720_FUN_005c6720.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005c6720.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005c6720_TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005c6720_TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred.md`
- Scaffold alias: `docs/reconstruction/functions/aa_005c6720_FUN_005c6720.md`

## Rejected names

- Scaffold `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvInvento_005c6720`
- Bare `TFID_EqualsObjectId` (that is `0x00404aa0`, different ABI and no pointer fallback)

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / `ret 4` / 104 B body | **Confirmed** |
| Dual-mode invalid→ptr / else TFID | **Confirmed** |
| Call sites = untrack + flag-set | **Confirmed** |
| Product payload class English | **Open** |

## Gaps

1. Product class name for payload / track entry.  
2. Product type of `*(object+4)` MI adjustment.  
3. Runtime / bit-exact / differential.
