# Function record: TNL_GroupReactionCall_UnpackData

| Field | Value |
|---|---|
| **Stable ID** | `aa_006374f0` |
| **Canonical name** | `TNL_GroupReactionCall_UnpackData` |
| **Ghidra name** | `FUN_006374f0` |
| **Address** | `0x006374f0`–`0x0063774d` (**605 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-net / TNL special-message (`GroupReactionCall` `0x206C`) |
| **Completion status** | **Dual A/B sealed** (W22-N 2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Unpack TNL special-message opcode **`0x206C`** into a heap ByteBuffer: u8 count, per-entry type-discriminated bitfields (stride **`0x28`**), rebuild with vtbl `PTR_LAB_009d7b00`, size `count*0x28+1`.

## Signature (decompiler + bytes)

```c
// cdecl
undefined4 * FUN_006374f0(undefined4 *out, int *inRefBuf);
// epilogue: add esp, 0x2940; ret
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006374f0_FUN_006374f0.md` (+ W22-N append)
- Annotated: `docs/reconstruction/raw/aa_006374f0_FUN_006374f0.annotated.md`
- Clean (named): `docs/reconstruction/reconstructed-exact/TNL_GroupReactionCall_UnpackData.cpp`
- Clean (scaffold): `docs/reconstruction/reconstructed-exact/FUN_006374f0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_006374f0_TNL_GroupReactionCall_UnpackData.md`
- Review B: `docs/reconstruction/reviews/B_aa_006374f0_TNL_GroupReactionCall_UnpackData.md`
- Scaffold record: `docs/reconstruction/functions/aa_006374f0_FUN_006374f0.md`

## Callers / callees

| Role | Name | VA / note |
|---|---|---|
| Caller | `Client_UnpackSpecialMessage` | only `param_2 == 0x206c` |
| Callee | `FUN_0042b3a0` BitStream bind | `0x0042b3a0` |
| Callee | `BitStream_readBits` / `BitStream_readInt` | wire |
| Callee | `FUN_0042b250` / `FUN_0042b270` | list head |
| Callee | `operator_new` / `malloc` / `free` | heap |

## Confidence

| Claim | Level |
|---|---|
| Opcode `0x206c` + cdecl + ByteBuffer rebuild | **High** |
| Wire: u8 count, type branch, stride 0x28, size formula | **High** |
| type==1 float via movss | **High** |
| Field English names / full consumer mapping | **Probable / Tentative** |
| Runtime / bit-exact | **Open** |
