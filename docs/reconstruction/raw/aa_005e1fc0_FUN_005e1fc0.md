# Raw capture: FUN_005e1fc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e1fc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005e1fc0` |
| **Canonical name** | `FUN_005e1fc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005e1fc0(int param_1,FILE *param_2)

{
  FILE *local_8;
  FILE *local_4;
  
  thunk_FUN_005a61d0(param_2);
  fwrite((void *)(param_1 + 0x170),4,1,param_2);
  FUN_00973820(param_1 + 0x174);
  local_8 = param_2;
  FUN_00973820(param_1 + 0x184);
  local_4 = param_2;
  fwrite(&local_8,4,1,param_2);
  fwrite(&local_4,4,1,param_2);
  return;
}
```

---

## Re-verify 2026-07-29 (W29-J OWN dual) — append only

| Field | Value |
|---|---|
| **Tool** | Ghidra HTTP `decompile_function` + `get_function_by_address` + `read_memory` + callees/xrefs |
| **Live decompile** | ≡ 2026-07-23 raw CF (same pseudocode shape) |
| **Body** | `0x005e1fc0`–`0x005e203c` (124 B / `0x7C`); epilogue `C2 04 00`; pad `CC` |
| **Canonical** | `Object_FwriteColorFields_Inferred` |
| **Bytes supersede** | stack locals after pack are **u8×4 colors**, not `FILE*`; `FUN_00973820` ECX=dest |
| **ABI** | `__thiscall` + stack `FILE*` + **`ret 4`** |
| **Verdict** | **accept-with-gaps** (dual A/B filed) |
