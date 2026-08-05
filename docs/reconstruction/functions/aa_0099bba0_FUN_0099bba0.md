# Function record: FUN_0099bba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099bba0` |
| **Canonical name** | `CNDAssetStringTable_Unserialize` (preferred) |
| **Ghidra name** | `FUN_0099bba0` |
| **Address** | `0x0099bba0`–`0x0099BED5` exclusive (**821 B** / `0x335`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `CNDAssetStringTable` stream unserialize |
| **Classification** | worker |
| **Completion status** | **Dual A/B filed** (W34-J 2026-07-29) — plate/ABI/outer stages sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `CNDAssetStringTable_Unserialize` (product plate)
- Ghidra: `FUN_0099bba0`
- Pair: `CNDAssetStringTable_Serialize` @ `0x0099b8e0`

## Purpose

Deserialize a `CNDAssetStringTable` from a stream: load string table entries, then pyramid structures with name→index resolution; return success.

## Signature (sealed)

```c
// 3 stack formals; RET 0x0C; AL = 1 success
uint8_t CNDAssetStringTable_Unserialize(void* host_table,
                                        void* scratch,
                                        void* stream_reader);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0099bba0_FUN_0099bba0.md` (+ W34-J append)
- Annotated: `docs/reconstruction/raw/aa_0099bba0_FUN_0099bba0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDAssetStringTable_Unserialize.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0099bba0.cpp`
- Function named: `docs/reconstruction/functions/aa_0099bba0_CNDAssetStringTable_Unserialize.md`
- Review A/B: `reviews/A_aa_0099bba0_CNDAssetStringTable_Unserialize.md`, `reviews/B_aa_0099bba0_CNDAssetStringTable_Unserialize.md`

## Callers / callees

| Callers | Callees |
|---|---|
| `FUN_0099c1c0` @ `0x0099c23a` | `FUN_007a4480`, string ctor/dtor, `FUN_00766fb0`, `FUN_00989e00`, `StringVec_PushBack`, `FUN_00430540`, `FUN_00430600`, `FUN_0044ff40`, `_stricmp`, `operator_delete` |

## Confidence

| Claim | Level |
|---|---|
| Product plate Unserialize | **High** |
| RET 12 + return 1 | **High** |
| String-table stage order | **High** |
| Nested pyramid row schema | **Med** (decompiler noise) |
| Full host object layout | **Open** |
