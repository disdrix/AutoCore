# Function record: StdUninitCopy_Pod28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045f360` |
| **Canonical name** | `StdUninitCopy_Pod28` |
| **Ghidra name** | `FUN_0045f360` |
| **Address** | `0x0045f360`–`0x0045f3AC` exclusive (**76 B** / `0x4C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC trivial uninitialized_copy for POD elem size 0x1c |
| **Classification** | leaf |
| **Completion status** | **Dual A/B filed** (W35-K 2026-07-29) — ABI/stride sealed; product T open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `StdUninitCopy_Pod28` (**Inferred** structural; family with W34-P `StdVector_InsertN_Pod28`)
- Ghidra: `FUN_0045f360`
- Reject scaffold: `Named_CalleeOf_*anmTrackMaster*`

## Purpose

Leaf range copy: for each element in `[src_begin, src_end)`, POD-copy 0x1c bytes to `dst` (if non-null) and advance both by 0x1c. Returns advanced destination end in EAX. Implements the trivial `_Ucopy` / `uninitialized_copy` helper used by Pod28 vector insert-n.

## Signature (sealed)

```c
// EAX=dst, ECX=src_begin, EDI=src_end; bare RET; EAX = dst_end
Pod28* StdUninitCopy_Pod28(Pod28* dst, const Pod28* src_begin, const Pod28* src_end);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0045f360_FUN_0045f360.md` (+ W35-K append)
- Annotated: `docs/reconstruction/raw/aa_0045f360_FUN_0045f360.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdUninitCopy_Pod28.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0045f360.cpp`
- Function (Ghidra id): `docs/reconstruction/functions/aa_0045f360_FUN_0045f360.md`
- Review A/B: `reviews/A_aa_0045f360_StdUninitCopy_Pod28.md`, `reviews/B_aa_0045f360_StdUninitCopy_Pod28.md`

## Callers / callees

| Callers | Callees |
|---|---|
| `StdVector_InsertN_Pod28` (`0x0045cd30`) ×4 | none |

## Confidence

| Claim | Level |
|---|---|
| Register ABI + 0x1c stride | **High** |
| Leaf / sole parent Pod28 insert-n | **High** |
| Product element type name | **Low** |
