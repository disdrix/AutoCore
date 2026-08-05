# Function record: CNDAssetStringTable_Unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099bba0` |
| **Canonical name** | `CNDAssetStringTable_Unserialize` |
| **Ghidra name** | `FUN_0099bba0` |
| **Address** | `0x0099bba0`–`0x0099BED5` exclusive (**821 B** / `0x335`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `CNDAssetStringTable` stream load |
| **Classification** | worker |
| **Completion status** | **Dual A/B filed** (W34-J 2026-07-29) — plate/ABI/outer stages sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `CNDAssetStringTable_Unserialize` (product string @ `0x00a9b728`)
- Ghidra: `FUN_0099bba0`
- Serialize twin: `CNDAssetStringTable_Serialize` (`0x0099b8e0`, NAMING_REGISTRY)

## Purpose

Stream-load the ND asset string table: read string count and C-strings (intern via `FUN_00989e00`, stage in temp `vector<basic_string>`), read pyramid count and nested rows (resize stride `0x10`, lower_bound + `_stricmp` name resolve), destroy temp vector, return success (`1`).

## Signature (sealed)

```c
// cdecl-style 3 stack args; RET 0x0C; returns success in AL
uint8_t CNDAssetStringTable_Unserialize(void* host_table,
                                        void* scratch,
                                        void* stream_reader);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0099bba0_FUN_0099bba0.md` (+ W34-J append)
- Annotated: `docs/reconstruction/raw/aa_0099bba0_FUN_0099bba0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDAssetStringTable_Unserialize.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0099bba0.cpp`
- Function (Ghidra id): `docs/reconstruction/functions/aa_0099bba0_FUN_0099bba0.md`
- Review A/B: `reviews/A_aa_0099bba0_CNDAssetStringTable_Unserialize.md`, `reviews/B_aa_0099bba0_CNDAssetStringTable_Unserialize.md`

## Callers / callees

| Callers | Callees |
|---|---|
| `FUN_0099c1c0` @ `0x0099c23a` | debug log, stream read C-string, string intern, `StringVec_PushBack`, pyramid resize helpers, lower_bound, `_stricmp`, delete |

## Confidence

| Claim | Level |
|---|---|
| Product plate | **High** |
| ABI RET 12 / AL=1 | **High** |
| String-table load stage | **High** |
| Pyramid nested detail | **Med** |
| Runtime | **Open** |
