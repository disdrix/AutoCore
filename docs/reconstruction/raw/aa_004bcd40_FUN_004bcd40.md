# Raw capture: FUN_004bcd40

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcd40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bcd40` |
| **Canonical name** | `FUN_004bcd40` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004bcd40(int param_1,byte param_2)

{
  if (*(char *)(param_1 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:Recreate, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  FUN_004bcca0();
  *(byte *)(param_1 + 0x1c) = param_2;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(int *)(param_1 + 8) = 1 << (param_2 & 0x1f);
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_004bc840();
  return;
}
```

---

## W30-G re-verify (2026-07-29) — append only

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual W30-G |
| **Tools** | `batch_decompile` / `decompile_function` + `read_memory` + function meta / callers / callees / xrefs. **No** `disassemble_bytes` |
| **Live decompile** | ≡ scaffold raw above (CF identical) |
| **Body** | `0x004bcd40`–`0x004bcd94` exclusive (**84 B / `0x54`**); last insn `C2 04 00`; pad `CC` |
| **ABI** | `__thiscall`; ECX=`this`; stack **byte log2** (4-byte slot); epilogue **`ret 4`** |
| **Role** | CNDHash **Recreate** for object vtbl family **`009cb45c`** / Alloc stamp **`009cb350`** |
| **Cal lees** | `FUN_004bcca0` (FreeBuckets twin), `FUN_004bc840` (`CNDHash_AllocBucketTable_009cb350`), `FUN_007a4480` ×2 (lock-warn only) |
| **Callers / xrefs** | **none** (zero static xrefs in this image) |
| **Named** | `CNDHash_Recreate_009cb45c` |
| **Strings @** | `0x00a64c48` `"HashError:Recreate, already locked for traversal"`; VOG string shared |

### Byte evidence (`read_memory` 128 B from entry)

```
56 8B F1 80 7E 1D 00 74 1B 68 48 4C A6 00 6A 00
E8 2B 77 2E 00 68 44 58 A1 00 6A 00 E8 1F 77 2E
00 83 C4 10 8B CE E8 35 FF FF FF 8A 4C 24 08 B8
01 00 00 00 D3 E0 88 4E 1C 8B CE C7 46 18 00 00
00 00 89 46 08 C7 46 14 00 00 00 00 E8 AF FA FF
FF 5E C2 04 00 CC …
```

| Anchor | Decode |
|---|---|
| Entry | `56 8B F1` push esi; mov esi,ecx |
| Lock | `80 7E 1D 00` / `74 1B` — skip logs if +0x1D==0; **no early ret** |
| Free | `E8 35 FF FF FF` → `FUN_004bcca0` |
| N | `8A 4C 24 08` / `B8 01…` / `D3 E0` → `1<<log2` |
| Stores | `88 4E 1C` log2; `C7 46 18 0` tail; `89 46 08` N; `C7 46 14 0` head |
| Alloc | `E8 AF FA FF FF` → `FUN_004bc840` @ call site `0x004bcd8c` |
| Exit | `5E C2 04 00` |
