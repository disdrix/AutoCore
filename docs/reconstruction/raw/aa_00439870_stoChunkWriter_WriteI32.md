# Raw capture: stoChunkWriter_WriteI32

| Field | Value |
|---|---|
| **Stable ID** | `aa_00439870` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00439870` |
| **Canonical name** | `stoChunkWriter_WriteI32` |
| **Prior scaffold** | `FUN_00439870` / `Named_CalleeOf_Named_effEffect_00439870` |
| **System** | storage / arda2.stoChunk |
| **Capture timestamp** | `2026-07-23` (scaffold); live re-verify `2026-07-29` W19-Q |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Integrity** | Do not overwrite the original raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile — 2026-07-23; live ≡ 2026-07-29)

```c
undefined4 FUN_00439870(void)

{
  undefined4 *in_EAX;
  uint uVar1;
  undefined4 *unaff_ESI;
  undefined4 local_4;
  
  local_4 = *in_EAX;
  if (unaff_ESI[7] == 0) {
    uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(&local_4,4);
    unaff_ESI[1] = unaff_ESI[1] | uVar1;
    return unaff_ESI[1];
  }
  uVar1 = FUN_00767160(&DAT_00a37c64,local_4);
  unaff_ESI[1] = unaff_ESI[1] | uVar1;
  unaff_ESI[8] = 0;
  uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(&DAT_00a97b84,2);
  unaff_ESI[1] = unaff_ESI[1] | uVar1;
  return unaff_ESI[1];
}
```

---

## Live re-verify — 2026-07-29 (W19-Q dual seal)

| Check | Result |
|---|---|
| `decompile_function` @ `0x00439870` | **Identical body** to raw |
| `read_memory` full body through dual `ret` | ends `59 c3` / `59 c3`; tail `cc` pad — length through `0x004398cf` |
| `read_memory` @ `0x00a37c64` | `"%i\0"` (signed decimal format) |
| `read_memory` @ `0x00a97b84` | `"\r\n"` (2 bytes) |
| Sibling `0x00439810` | Same CF; format `DAT_00a9d718` = `"%u"` |
| Mode field | `unaff_ESI[7]` ≡ writer `+0x1c` (sealed in Begin/EndChunk duals: 0 binary, nonzero text) |
| Text column | `unaff_ESI[8]` ≡ `+0x20` cleared after formatted write before CRLF |
| ABI (call sites) | **ESI** = writer; **EAX** = `int32_t*` value pointer (`lea eax,[ebx+…]` / `mov eax,ebp` then `call`) |
| Xrefs (sample) | `gfxIndexBufferImpl_Serialize`, `gfxVertexBufferImpl_Serialize`, `gfxGeometryPiece_Serialize`, `FUN_00989350` (CPDF chunk), `FUN_0073ee70` (MWGT), many others |
| Formatted helper | `FUN_00767160` = dual-sealed `stoChunkWriter_WriteFormatted` |
