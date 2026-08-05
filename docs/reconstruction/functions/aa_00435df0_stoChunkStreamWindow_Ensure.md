# Function record: stoChunkStreamWindow_Ensure

| Field | Value |
|---|---|
| **Stable ID** | `aa_00435df0` |
| **Canonical name** | `stoChunkStreamWindow_Ensure` |
| **Ghidra name** | `FUN_00435df0` |
| **Address** | `0x00435df0` |
| **Body range** | `0x00435df0`–`0x00435f24` (Ghidra); epilogues `ret 4` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | storage / arda2 stoChunk |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + window map sealed; product English / streamEnd open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00435df0_stoChunkStreamWindow_Ensure.md`, `reviews/B_aa_00435df0_stoChunkStreamWindow_Ensure.md` |
| **Last reviewed** | `2026-07-29` (W18-A) |

## Alias

- `FUN_00435df0` (Ghidra)
- `Named_CalleeOf_Named_gfxBody_00435df0` (auto parent-seed — incomplete; multi-caller ensure)
- Prior scaffold system `unknown`

## Purpose

Sliding-window **ensure / reposition**: given absolute stream position `absPos`, re-anchor `StoStreamWindow` so `base = absPos`, `cursor = 0`, clamp `available = min(capacity, streamEnd - absPos)`, and fill via source **Seek** (`vtbl+4`) + **Read** (`vtbl+0x14`). Three arms: forward slide inside window, backward slide within capacity, full reposition.

## Signature

```c
// Machine: __thiscall, one stack arg, ret 4; EAX = last Read status (signed)
int32_t __thiscall stoChunkStreamWindow_Ensure(StoStreamWindow* this, int32_t absPos);
```

## Layout (this unit)

| Offset | Field | Role |
|---:|---|---|
| `+0x00` | `pSource*` | stream object; `*pSource` = vtbl |
| `+0x04` | `cursor` | set to **0** on ensure |
| `+0x08` | `base` | abs position of `buffer[0]`; set to `absPos` |
| `+0x0c` | `available` | valid bytes; recomputed |
| `+0x10` | `capacity` | max window size (clamp) |
| `+0x14` | `streamEnd` | abs limit for available clamp (INFERRED English) |
| `+0x18` | `buffer[]` | inline data |

## Algorithm

1. If `base <= absPos < base+available` → Arm A (forward memmove keep-suffix; Seek past keep; Read tail).
2. Else if `absPos < base` and `base <= capacity+absPos` → Arm B (backward memmove; Seek absPos; Read front gap).
3. Else → Arm C full Seek(absPos)+Read(full available).
4. Return last Read status in EAX.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00435df0_FUN_00435df0.md`
- Annotated: `docs/reconstruction/raw/aa_00435df0_FUN_00435df0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/stoChunkStreamWindow_Ensure.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00435df0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00435df0-005081f0-w18a-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `memmove` (IAT); virtual Seek `*pSource.vtbl+4`; virtual Read `*pSource.vtbl+0x14` |
| **Callers (sample)** | `stoChunkStreamWindow_ReadHeader16` (`0x004368b0`), `stoChunkReader_OpenChunk` (`0x0076a2c0`), `stoChunkReader_readF32Array` (`0x00436090`), typed stoChunk readers `0x00767*`–`0x00769*`, bulk path `FUN_00435f30`, gfx/body loaders |

## Confidence

| Claim | Level |
|---|---|
| Control flow three arms + LAB full reposition | **High** |
| `__thiscall` + `ret 4` + absPos stack arg | **High** |
| Window +4/+8/+c/+10/+14/+18 map | **High** (+14 English Probable) |
| Source vtbl+4 Seek / +0x14 Read roles | **High** (use); English **Inferred** |
| EAX = Read status for callers | **High** (caller sites); decomp void is surface |
| Product/PDB symbol | Open |
| Runtime / bit-exact | Open |

## Related

- `aa_004368b0` stoChunkStreamWindow_ReadHeader16 (ensure gate)
- `aa_00436090` stoChunkReader_readF32Array
- `aa_00435f30` bulk window read (calls Ensure when needed)
- OpenChunk dual `aa_0076a2c0`
