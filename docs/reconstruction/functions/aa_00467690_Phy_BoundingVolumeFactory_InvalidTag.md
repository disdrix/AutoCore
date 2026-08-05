# Function record: Phy_BoundingVolumeFactory_InvalidTag

| Field | Value |
|---|---|
| **Stable ID** | `aa_00467690` |
| **Canonical name** | `Phy_BoundingVolumeFactory_InvalidTag` |
| **Address** | `0x00467690` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | physics / phyBoundingVolumeFactory |
| **Completion status** | **Dual-reviewed 2026-07-29** — accept-with-gaps; fourcc factory map sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00467690`
- Prior auto-slug names (if any): leave on disk; canonical is `Phy_BoundingVolumeFactory_InvalidTag`
- Role alias (not registry): CreateFromFourCC / CreateByChunkTag

## Purpose

**FOURCC-tag → bounding-volume factory** for `phyBoundingVolumeFactory`. Canonical name is from the null-tag error string; success paths construct Sphere (via CreateFromTag(1)), Box, Capsule, type-4 (BVSF), or WalkableSurface.

| Tag | FOURCC | Result |
|---|---|---|
| `0x42565350` | BVSP | `CreateFromTag(1)` sphere |
| `0x42564258` | BVBX | `new(0x20)` + box ctor `0x00467440` |
| `0x42564350` | BVCP | `new(0x28)` + capsule ctor `0x004674e0` |
| `0x42565346` | BVSF | `new(8)` + `PTR_FUN_00aa5c6c`, `+4=0` |
| `0x42565753` | BVWS | `new(0x100)` + `0x00467600` |
| `0` | — | log `"Invalid tag [ %s ] for phyBoundingVolume"` @ `phyBoundingVolumeFactory.h:0x45` → null |
| other | — | silent null |

## String evidence

`"Invalid tag [ %s ] for phyBoundingVolume"` / `"..\\palantir/physics/phyBoundingVolumeFactory.h"` line `0x45`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ * Phy_BoundingVolumeFactory_InvalidTag(void *param_1 /* fourcc tag */)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00467690_FUN_00467690.md`
- Annotated: `docs/reconstruction/raw/aa_00467690_FUN_00467690.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Phy_BoundingVolumeFactory_InvalidTag.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00467690.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00467690_Phy_BoundingVolumeFactory_InvalidTag.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00467690_Phy_BoundingVolumeFactory_InvalidTag.md`

## Callers / callees

**Callers (Ghidra xrefs 2026-07-29):**

- `phyBoneSharedData_unserialize` @ `0x00997540` (sites `0x009976bf`, `0x00997768`)
- `FUN_0095dc70` @ `0x0095dc70` (site `0x0095e044`)

**Callees:**

- `Phy_BoundingVolumeFactory_CreateFromTag` (`0x00467820`) — BVSP only, ECX=1
- `operator_new`
- `FUN_00467440` (box), `FUN_004674e0` (capsule), `FUN_00467600` (walkable)
- `FUN_00436190` (string helper on null-tag log path)
- `FUN_0076cec0` (format), `vog_LogMessage`
- `std::basic_string` dtor

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler / body bytes | **Confirmed** |
| Naming from string literals (canonical) | **High** (name understates factory role) |
| FOURCC → type map (SP/BX/CP/WS) | **High** |
| BVSF product class name | **Medium** / open |
| Parameter semantic names | **High** (tag dword) |
| Types of returned BV objects | **Probable** (vtbl/size sealed; full layouts open) |
