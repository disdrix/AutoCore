# Raw capture: gfxVertexBufferImpl_Serialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_009994c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x009994c0` |
| **Canonical name** | `gfxVertexBufferImpl_Serialize` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x00999615) */
/* gfxVertexBufferImpl::Serialize  [palantir\graphics\gfxVertexBufferImpl.cpp:0x319]
   Writes a VERT (file bytes "TREV") chunk, version 3: body = u32 id/hash + u16 stride + u16 count +
   nested DECL chunk (file "LCED") + u32 count2 + raw interleaved vertex data (count2 x stride).
   DECL v2 body = u32 elementCount + elementCount x 4-byte {u8 D3DDECLTYPE, u8 stream, u8
   D3DDECLUSAGE, u8 usageIndex}; attribute offsets are implicit (accumulate D3DDECLTYPE sizes in
   order). Verified against 2500+ retail .geo files.
   Spec: AutoCore-SCAR docs/geo-format.md */

int gfxVertexBufferImpl_Serialize(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009afb82;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  stoChunkWriter_BeginChunk(0x56455254,3);
  local_4 = 0;
  if ((*(int *)(unaff_EDI + 0x10) != 0) &&
     (iVar2 = FUN_00746520(*(undefined4 *)(unaff_EDI + 0x14),*(undefined4 *)(unaff_EDI + 0x18),4),
     iVar2 != 0)) {
    if (*(int *)(unaff_EDI + 0x10) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined4 *)(*(int *)(unaff_EDI + 0x10) + 8);
    }
    FUN_00734640(*(undefined4 *)(unaff_EDI + 0x18),uVar1);
  }
  FUN_0044c9e0();
  iVar2 = FUN_00746f90();
  if (iVar2 < 0) {
    FUN_00414aa0();
  }
  else {
    FUN_00439870();
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_00746d40(unaff_EDI + 0x24);
    iVar2 = FUN_00767ab0(0,*(undefined4 *)(unaff_EDI + 0x18));
    FUN_00414aa0();
    if (iVar2 < 0) {
      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferImpl.cpp",0x319,
                     3,"Error serializing vertex buffer");
      FUN_00405ef0();
      local_4 = 0xffffffff;
      stoChunkWriter_EndChunk();
      ExceptionList = local_c;
      return -1;
    }
  }
  local_4 = 0xffffffff;
  stoChunkWriter_EndChunk();
  ExceptionList = local_c;
  return iVar2;
}
```
