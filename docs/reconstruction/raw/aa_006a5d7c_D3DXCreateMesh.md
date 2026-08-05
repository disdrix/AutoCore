# Raw capture: D3DXCreateMesh

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a5d7c` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a5d7c` |
| **Canonical name** | `D3DXCreateMesh` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void D3DXCreateMesh(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a5d7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  D3DXCreateMesh();
  return;
}
```
