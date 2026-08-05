# Function record: gfxVertexBufferImpl_Allocate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099a8e0` |
| **Canonical name** | `gfxVertexBufferImpl_Allocate` |
| **Ghidra name** | `FUN_0099a8e0` |
| **Address** | `0x0099a8e0` |
| **Body range** | `0x0099a8e0`–`0x0099a9a4` (196 bytes through `ret 0x10`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `graphics` / gfxVertexBufferImpl |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + plate + field stores sealed; formal product arg names + runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0099a8e0_gfxVertexBufferImpl_Allocate.md`, `reviews/B_aa_0099a8e0_gfxVertexBufferImpl_Allocate.md` (2026-07-29 W22-L) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_0099a8e0`
- `Named_gfxVertexBufferImpl_0099a8e0` (legacy string-seed)
- Role: gfxVertexBufferImpl device allocate after construct

## Purpose

**Allocate** vertex-buffer resources on a constructed **gfxVertexBufferImpl**:

1. Free prior resources (`FUN_0099a820`).
2. Store count @ `+0x18`, callback @ `+0x1c`; init `+0x24` subobject (`FUN_00447ea0`).
3. Copy format fields `fmt+0x10`/`+0x14` → `this+0x34`/`+0x38`.
4. Device allocate via `FUN_00986a60(DAT_00d1f634, this, arg2)`.
5. On fail: zero fields, `FUN_0044c3c0(0,0)`, plate log line `0x66`, return `-1`.
6. On success: optional callback vtbl[0]; bump `DAT_00d1f614` stats (`+0x388`, `+0x338`, `+0x334`).
7. Return status in **EAX** (`ret 0x10`).

## Signature

```c
// __thiscall; ret 0x10 (4 stack dwords)
int __thiscall gfxVertexBufferImpl_Allocate(
    void *self,
    uint32_t vertexCount,     /* INFERRED: stored at this+0x18 */
    void *formatDesc,         /* INFERRED: +0x10/+0x14 copied */
    uint32_t strideOrUsage,   /* INFERRED: third arg to device allocate */
    void *callback);          /* INFERRED: optional; this+0x1c; vtbl[0] */
```

## Algorithm

See clean `gfxVertexBufferImpl_Allocate.cpp` and raw re-verify byte section.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0099a8e0_FUN_0099a8e0.md`
- Annotated: `docs/reconstruction/raw/aa_0099a8e0_FUN_0099a8e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/gfxVertexBufferImpl_Allocate.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0099a8e0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0099a8e0_FUN_0099a8e0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0099a8e0-00419e20-w22l-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_0099a820`, `FUN_00447ea0`, `FUN_00986a60`, `FUN_0044c3c0`, `vog_LogMessage` |
| **Callers** | `GfxVBHolder_ReplaceAndAllocate` @ `0x00414c20`; `gfxVertexBufferImpl_Unserialize` @ `0x0099aa20` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| `ret 0x10` / 4 stack args / thiscall | **High** |
| Plate path + fail message | **High** (string bytes) |
| Field offsets 0x18/0x1c/0x34/0x38 | **High** |
| Return EAX status / fail −1 | **High** |
| Stats offsets on `DAT_00d1f614` | **High** (imm in body) |
| Stack formal English names | **Inferred** |
| Runtime / differential | Open |

## Related

- `aa_00414c20` GfxVBHolder_ReplaceAndAllocate — primary caller
- `FUN_00999960` — gfxVertexBufferImpl ctor
- `FUN_0099a820` — free-prior prep
- `FUN_00986a60` — device allocate
