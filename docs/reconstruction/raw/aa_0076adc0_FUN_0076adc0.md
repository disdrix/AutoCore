# Raw capture: FUN_0076adc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076adc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0076adc0` |
| **Canonical name** | `FUN_0076adc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint FUN_0076adc0(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  undefined1 local_128 [6];
  uint local_122;
  char local_104 [260];
  
  iVar2 = -(int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)(local_104 + iVar2)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  pcVar3 = local_104;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if ((pcVar3[(int)(local_104 + (-1 - (int)(local_104 + 1)))] == '\\') ||
     (pcVar3[(int)(local_104 + (-1 - (int)(local_104 + 1)))] == '/')) {
    pcVar3[(int)(local_104 + (-1 - (int)(local_104 + 1)))] = '\0';
  }
  uVar4 = stat(local_104,local_128);
  if (uVar4 != 0) {
    return uVar4 & 0xffffff00;
  }
  return local_122 >> 0xe & 1;
}
```
---

## W33-C re-verify append (2026-07-29)

**Tooling:** live `decompile_function` + `analyze_function_complete` (no disasm) + `read_memory` full body + xrefs. **No** `disassemble_bytes`. **No** Launcher.

### Body / ABI (bytes)

| Field | Value |
|-------|-------|
| Range | `0x0076adc0`–`0x0076ae35` |
| Size | **118 B** / `0x76` |
| Pad | `CC` ×10+ then next unit |
| Conv | **cdecl** 1 stack formal (`const char* path` @ `[esp+4]`) |
| Epilogue | both exits: `ADD ESP,0x128; RET` (bare `C3`) |
| Frame | `SUB ESP,0x128` (`0x128` = 296) |

### Live decompile (2026-07-29) ≡ scaffold raw CF

Same control flow as 2026-07-23 raw: strcpy into 260-byte stack buf → strip trailing `\`/`/` → `stat` → fail→0 / success→`(st_mode>>14)&1`.

### Bytes authority notes

1. **Fail return:** `32 C0` (`XOR AL,AL`) then `ADD ESP,0x128; RET` — decompiler `return uVar4 & 0xffffff00` is a false widening of zeroing AL; effective bool **0**.
2. **Success:** `MOV EAX,[ESP+6]` (st_mode at **+6** in MSVC `_stat` buffer at ESP) ; `SHR EAX,0xE` ; `AND EAX,1` — **S_IFDIR** (`0x4000`) bit.
3. **IAT:** `CALL DWORD PTR [0x009c6504]` = `stat` / `_stat`.
4. Path work buffer at `[ESP+0x24]` after frame (260 B incl. NUL); strip last char if `\` (`0x5C`) or `/` (`0x2F`).

### Classification / graph

- **Class:** worker
- **Callees:** `stat` only
- **Callers (8):** `FUN_0076b3f0`, `FUN_0076ba10`, `FUN_0076bc00`, `FUN_0076bc80`, `FUN_007a13e0`, `FUN_007b75b0`, `FUN_009839b0`, `FUN_00984340`
- **Xrefs:** 11 call sites (includes mid-function sites inside callers)

### Name (inferred)

`Fs_PathIsDirectory_Stat_Inferred` — path is-directory via CRT `stat` + `S_IFDIR`.

### Full body hex (118 B)

```
8b4424048d9424fcfeffff81ec280100002bd08a08880c0283c00184c975f48d4424248d50018a0883c00184c975f72bc28a4c042380f95c8d440423740580f92f7503c600008d0424508d4c242851ff1504659c0083c40885c0740932c081c428010000c38b442406c1e80e83e00181c428010000c3
```
