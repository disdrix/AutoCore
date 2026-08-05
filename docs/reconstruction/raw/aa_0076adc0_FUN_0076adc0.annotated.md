# Annotated low-level: Fs_PathIsDirectory_Stat_Inferred (`FUN_0076adc0`)

| Field | Value |
|---|---|
| Stable ID | `aa_0076adc0` |
| VA | `0x0076adc0`–`0x0076ae35` (**118 B**) |
| System | filesystem / path probe |
| Date | 2026-07-23 scaffold; **W33-C seal 2026-07-29** |
| Ghidra | `FUN_0076adc0` |
| Inferred name | `Fs_PathIsDirectory_Stat_Inferred` |

## Machine-level notes

- Source: raw capture + W33-C live re-verify (`decompile` + `read_memory` + xrefs). **No** `disassemble_bytes`.
- Prefer **bytes** when decompiler conflicts (fail path zeroing AL).
- CRT `stat` buffer: MSVC `_stat` with **`st_mode` at +6**; `S_IFDIR = 0x4000` → `(mode >> 14) & 1`.

## Sealed semantics

```
bool Fs_PathIsDirectory_Stat_Inferred(const char* path)  // cdecl; AL/EAX 0/1
{
  char buf[260];
  strcpy(buf, path);                    // byte-copy incl. NUL
  // strip one trailing separator if present
  if (last_char == '\\' || last_char == '/') last_char = 0;
  struct _stat st;
  if (stat(buf, &st) != 0) return false;  // XOR AL,AL
  return (st.st_mode >> 14) & 1;          // S_IFDIR bit
}
```

## Pseudocode (annotated)

```c
// cdecl; 1 formal; bare RET; frame SUB ESP,0x128
uint Fs_PathIsDirectory_Stat_Inferred(char *path)
{
  // local_128.. : _stat buffer at ESP; st_mode dword-load at ESP+6
  // local_104   : char path_copy[260] at ESP+0x24
  char path_copy[260];
  // strcpy-equivalent loop (src→path_copy)
  // strlen to last char; if '\\' or '/' → NUL it
  uint rc = stat(path_copy, &st);       // IAT [0x009c6504]
  if (rc != 0) {
    return 0;                           // bytes: XOR AL,AL  (not uVar4&0xffffff00)
  }
  return (st_mode_dword >> 14) & 1;     // S_IFDIR
}
```

## Callers / callees

| Role | Symbols |
|---|---|
| Callees | `stat` only |
| Callers | `FUN_0076b3f0`, `FUN_0076ba10`, `FUN_0076bc00`, `FUN_0076bc80`, `FUN_007a13e0`, `FUN_007b75b0`, `FUN_009839b0` (W32-D dir recurse), `FUN_00984340` |

## Open / residual

- Product/MSVC demangle (likely free helper, not a class method).
- Which exact CRT import name (`stat` vs `_stat` vs `_stat32`) — IAT slot only sealed.
- Runtime / bit-exact / differential open.
