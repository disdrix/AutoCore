# Function record: GfxVBHolder_ReplaceAndAllocate

| Field | Value |
|---|---|
| **Stable ID** | `aa_00414c20` |
| **Canonical name** | `GfxVBHolder_ReplaceAndAllocate` |
| **Ghidra name** | `FUN_00414c20` |
| **Address** | `0x00414c20` |
| **Body range** | `0x00414c20`–`0x00414cc0` (161 bytes through `ret 0x10`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `graphics` / gfxVertexBufferImpl |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + pool/ctor/allocate sealed; formal product names + runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00414c20_GfxVBHolder_ReplaceAndAllocate.md`, `reviews/B_aa_00414c20_GfxVBHolder_ReplaceAndAllocate.md` (2026-07-29 W21-L) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00414c20`
- `Named_CalleeOf_CVOGTacArc_InitializeMesh_00414c20` (legacy parent-seed)
- Role: holder VB slot replace + gfxVertexBufferImpl allocate

## Purpose

**Replace** the vertex-buffer implementation stored at **`holder+4`**:

1. Pop a node from global freelist **`DAT_00d218e0`** (`FUN_00414cd0`).
2. Construct as **gfxVertexBufferImpl** (`FUN_00999960`, vtbl `PTR_FUN_00aa161c`).
3. Refcount++ on new (`+4`); if first ref, call **vtbl+4**.
4. Refcount−− on previous slot; if zero, call **vtbl+8**.
5. Store new pointer at `holder+4`.
6. Call **`FUN_0099a8e0`** (allocate; plate `gfxVertexBufferImpl.cpp` / `"Failed to Allocate Vertex Buffer"`).
7. Return allocate status in **EAX** (`ret 0x10`).

## Signature

```c
// __thiscall; ret 0x10 (4 stack dwords)
int __thiscall GfxVBHolder_ReplaceAndAllocate(
    void *holder,
    uint32_t arg0,   /* INFERRED: vertex count (terrain/tacarc) */
    uint32_t arg1,   /* INFERRED: format / decl object */
    uint32_t arg2,   /* INFERRED: stride or usage (terrain uses 0x20) */
    uint32_t arg3);  /* INFERRED: flags / callback (often 0) */
```

## Algorithm

See clean `GfxVBHolder_ReplaceAndAllocate.cpp` and raw re-verify byte section.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00414c20_FUN_00414c20.md`
- Annotated: `docs/reconstruction/raw/aa_00414c20_FUN_00414c20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GfxVBHolder_ReplaceAndAllocate.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00414c20.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00414c20_FUN_00414c20.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00414c20-007a41f0-w21l-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00414cd0` (pool), `FUN_00999960` (ctor), `FUN_0099a8e0` (allocate) |
| **Callers** | 40+: `CVOGTerrainChunk_BuildVertexBuffer`, `CVOGTacArc_InitializeMesh`, `gfxGeometryPiece_Serialize`/`Unserialize`, mesh setup `FUN_007*` / `FUN_0099*` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| `ret 0x10` / 4 stack args / thiscall holder | **High** |
| `holder+4` VB slot + refcount dance | **High** |
| Pool global `DAT_00d218e0` | **High** (imm in body) |
| Ctor/allocate identity via plate + vtbl | **High** |
| Return = allocate EAX | **High** (bytes leave EAX; callers test `<0`) |
| Stack formal English names | **Inferred** |
| Runtime / differential | Open |

## Related

- `FUN_00414bc0` — nearby holder/setup helper used by terrain before allocate
- `FUN_00414cd0` — freelist pop (32000-byte slab, 0x40 stride nodes)
- `FUN_0099a8e0` / `gfxVertexBufferImpl_Serialize` family
