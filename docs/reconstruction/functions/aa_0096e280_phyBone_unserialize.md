# Function record: phyBone_unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096e280` |
| **Canonical name** | `phyBone_unserialize` |
| **Address** | `0x0096e280` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `physics / phy` |
| **Completion status** | **Dual A/B sealed 2026-07-29** — CF/tag/version/offsets High; field English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

PBON (`0x50424f4e` / file `NOBP`) **version 1** bone record: three int32 + one float32 at `this+0x148..+0x154`, then nested **BDAT/TADB** via `phyBoneSharedData_unserialize(*(this+0xf4))`, then copy transform into bone locals (`FUN_0096de80`). Binary vs text dual path on `reader+0x4044`.

## Signature (decompiler-derived)

```c
// ESI = phyBone* this; param_1 = stoChunkReader*
uint __fastcall phyBone_unserialize(int param_1);
// returns OR of read statuses, or 0xffffffff on bad tag/version
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0096e280_phyBone_unserialize.md`
- Annotated: `docs/reconstruction/raw/aa_0096e280_phyBone_unserialize.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/phyBone_unserialize.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0096e280_phyBone_unserialize.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0096e280_phyBone_unserialize.md`

## Callers / callees

| | VA | Role |
|---|---|---|
| Caller | `0x0096b930` @ `0x0096ba29` | phySkeleton unserialize — bone loop; sets `bone+0x144 = index` after call |
| Callee | EnterChunkScope / Leave (`FUN_00769e40`) | Chunk scope |
| Callee | `0x00437050` / `0x00768760` | Binary / text int32 |
| Callee | `0x00435fe0` / `0x00767fd0` | Binary / text float32 (4 bytes) |
| Callee | `0x00449dc0` | Install default shared-like 0x90 object |
| Callee | `0x00997540` | `phyBoneSharedData_unserialize` |
| Callee | `0x0096de80` | Copy shared transform → bone; `+0x140 = -1` |
| Callee | `vog_LogMessage` / `FUN_0076cec0` | Error paths |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler (≡ raw 2026-07-29) | **High** |
| Tag PBON + version 1 only | **High** |
| Offsets `+0x148..+0x154`, nested `+0xf4` | **High** |
| Binary vs text via `reader+0x4044` | **High** |
| Field semantic names | **Tentative** |
| Types of three ints | **Tentative** (width High) |
