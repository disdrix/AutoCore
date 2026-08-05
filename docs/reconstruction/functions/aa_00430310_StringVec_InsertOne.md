# Function record: StringVec_InsertOne

| Field | Value |
|---|---|
| **Stable ID** | `aa_00430310` |
| **Canonical name** | `StringVec_InsertOne` |
| **Ghidra name** | `FUN_00430310` |
| **Address** | `0x00430310`–`0x00430383` exclusive (**115 B** / `0x73`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `vector<basic_string>` insert (elem stride 0x1c) |
| **Classification** | worker |
| **Completion status** | **Dual A/B filed** (W32-A 2026-07-29) — CF/ABI/index rebuild sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `StringVec_InsertOne` (**Inferred** structural)
- Ghidra: `FUN_00430310`
- **Reject**: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00430310`

## Purpose

Insert one `basic_string` (stride `0x1c`) at a byte-iterator position in a `StringVecShell`, then store a post-insert iterator in an out-parameter. Index is snapshotted before the nested grow/insert (`FUN_004306b0`) so the out-iterator remains correct after reallocation.

## Signature (sealed)

```c
// __thiscall; RET 12; void
void StringVec_InsertOne(StringVecShell* self,
                         uint8_t** out_iterator,
                         uint8_t* pos,
                         const void* value_string);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00430310_FUN_00430310.md` (+ W32-A append)
- Annotated: `docs/reconstruction/raw/aa_00430310_FUN_00430310.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StringVec_InsertOne.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00430310.cpp`
- Function (Ghidra id): `docs/reconstruction/functions/aa_00430310_FUN_00430310.md`
- Review A/B: `reviews/A_aa_00430310_StringVec_InsertOne.md`, `reviews/B_aa_00430310_StringVec_InsertOne.md`
- Parent dual: `aa_00969830` (W31-E); nested grow: `FUN_004306b0` (W32-B)

## Callers / callees

| Callers | Callees |
|---|---|
| `FUN_004301f0`, `FUN_00969830` | `FUN_004306b0` |

## Confidence

| Claim | Level |
|---|---|
| thiscall + RET 12 | **High** |
| stride 0x1c + index math | **High** |
| out-iter rebuild after insert | **High** |
| count always 1 | **High** |
| Nested grow product plate | **Med** (unowned W32-B) |
| Product vector English | **Low** (open) |
