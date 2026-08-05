# Annotated low-level: Client_InitDefaultKeybinds

| Field | Value |
|---|---|
| Stable ID | `aa_007f8720` |
| VA | `0x007f8720` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007f8720`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Writes default DIK/VK codes into action slots (stride 0x34). e.g. Inventory key 0x17 at +0x5EA,
   QB1-10 keys 2..0xB at +0xC9E.. */

void Client_InitDefaultKeybinds(void)

{
  int unaff_EDI;
  
  FUN_007f74a0();
  if (*(char *)(unaff_EDI + 0x40) == '\0') {
    *(undefined2 *)(unaff_EDI + 0x3a) = 0x35;
    *(undefined2 *)(unaff_EDI + 100) = 0;
    *(undefined1 *)(unaff_EDI + 0x3f) = 0;
    *(undefined1 *)(unaff_EDI + 0x3e) = 0;
  }
  if (*(char *)(unaff_EDI + 0x74) == '\0') {
    *(undefined2 *)(unaff_EDI + 0x6e) = 0xb7;
    *(undefined2 *)(unaff_EDI + 0x98) = 0;
    *(undefined1 *)(unaff_EDI + 0x73) = 0;
    *(undefined1 *)(unaff_EDI + 0x72) = 0;
  }
  if (*(char *)(unaff_EDI + 0xa8) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xa2) = 0xb5;
    *(undefined2 *)(unaff_EDI + 0xcc) = 0;
    *(undefined1 *)(unaff_EDI + 0xa7) = 0;
    *(undefined1 *)(unaff_EDI + 0xa6) = 0;
  }
  if (*(char *)(unaff_EDI + 0xdc) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xd6) = 0x4e;
    *(undefined2 *)(unaff_EDI + 0x100) = 0;
    *(undefined1 *)(unaff_EDI + 0xdb) = 0;
    *(undefined1 *)(unaff_EDI + 0xda) = 0;
  }
  *(undefined1 *)(unaff_EDI + 0x40) = 1;
  *(undefined1 *)(unaff_EDI + 0x74) = 1;
  *(undefined1 *)(unaff_EDI + 0xa8) = 1;
  *(undefined1 *)(unaff_EDI + 0xdc) = 1;
  *(undefined1 *)(unaff_EDI + 0x9e) = 1;
  if (*(char *)(unaff_EDI + 0x5f0) == '\0') {
    *(undefined2 *)(unaff_EDI + 0x5ea) = 0x17;
    *(undefined2 *)(unaff_EDI + 0x614) = 0;
    *(undefined1 *)(unaff_EDI + 0x5ef) = 0;
    *(undefined1 *)(unaff_EDI + 0x5ee) = 0;
  }
  if (*(char *)(unaff_EDI + 0x624) == '\0') {
    *(undefined2 *)(unaff_EDI + 0x61e) = 0x17;
    *(undefined2 *)(unaff_EDI + 0x648) = 0x2a;
    *(undefined1 *)(unaff_EDI + 0x623) = 0;
    *(undefined1 *)(unaff_EDI + 0x622) = 0;
  }
  if (*(char *)(unaff_EDI + 0x6c0) == '\0') {
    *(undefined2 *)(unaff_EDI + 0x6ba) = 0x19;
    *(undefined2 *)(unaff_EDI + 0x6e4) = 0;
    *(undefined1 *)(unaff_EDI + 0x6bf) = 0;
    *(undefined1 *)(unaff_EDI + 0x6be) = 0;
  }
  if (*(char *)(unaff_EDI + 0x7c4) == '\0') {
    *(undefined2 *)(unaff_EDI + 0x7be) = 0x21;
    *(undefined2 *)(unaff_EDI + 0x7e8) = 0;
    *(undefined1 *)(unaff_EDI + 0x7c3) = 0;
    *(undefined1 *)(unaff_EDI + 0x7c2) = 0;
  }
  if (*(char *)(unaff_EDI + 0x75c) == '\0') {
    *(undefined2 *)(unaff_EDI + 0x756) = 0x2c;
    *(undefined2 *)(unaff_EDI + 0x780) = 0;
    *(undefined1 *)(unaff_EDI + 0x75b) = 0;
    *(undefined1 *)(unaff_EDI + 0x75a) = 0;
  }
  if (*(char *)(unaff_EDI + 0x68c) == '\0') {
    *(undefined2 *)(unaff_EDI + 0x686) = 0x18;
    *(undefined2 *)(unaff_EDI + 0x6b0) = 0;
    *(undefined1 *)(unaff_EDI + 0x68b) = 0;
    *(undefined1 *)(unaff_EDI + 0x68a) = 0;
  }
  if (*(char *)(unaff_EDI + 0x6f4) == '\0') {
    *(undefined2 *)(unaff_EDI + 0x6ee) = 0x27;
    *(undefined2 *)(unaff_EDI + 0x718) = 0;
    *(undefined1 *)(unaff_EDI + 0x6f3) = 0;
    *(undefined1 *)(unaff_EDI + 0x6f2) = 0;
  }
  if (*(char *)(unaff_EDI + 0x728) == '\0') {
    *(undefined2 *)(unaff_EDI + 0x722) = 0x25;
    *(undefined2 *)(unaff_EDI + 0x74c) = 0;
    *(undefined1 *)(unaff_EDI + 0x727) = 0;
    *(undefined1 *)(unaff_EDI + 0x726) = 0;
  }
  if (*(char *)(unaff_EDI + 0x7f8) == '\0') {
    *(undefined2 *)(unaff_EDI + 0x7f2) = 0x23;
    *(undefined2 *)(unaff_EDI + 0x81c) = 0x2a;
    *(undefined1 *)(unaff_EDI + 0x7f7) = 0;
    *(undefined1 *)(unaff_EDI + 0x7f6) = 0;
  }
  if (*(char *)(unaff_EDI + 0x860) == '\0') {
    *(undefined2 *)(unaff_EDI + 0x85a) = 0x23;
    *(undefined2 *)(unaff_EDI + 0x884) = 0;
    *(undefined1 *)(unaff_EDI + 0x85f) = 0;
    *(undefined1 *)(unaff_EDI + 0x85e) = 0;
  }
  if (*(char *)(unaff_EDI + 0x82c) == '\0') {
    *(undefined2 *)(unaff_EDI + 0x826) = 0x24;
    *(undefined2 *)(unaff_EDI + 0x850) = 0;
    *(undefined1 *)(unaff_EDI + 0x82b) = 0;
    *(undefined1 *)(unaff_EDI + 0x82a) = 0;
  }
  if (*(char *)(unaff_EDI + 0x8c8) == '\0') {
    *(undefined2 *)(unaff_EDI + 0x8c2) = 0x32;
    *(undefined2 *)(unaff_EDI + 0x8ec) = 0;
    *(undefined1 *)(unaff_EDI + 0x8c7) = 0;
    *(undefined1 *)(unaff_EDI + 0x8c6) = 0;
  }
  if (*(char *)(unaff_EDI + 0xb04) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xafe) = 0x32;
    *(undefined2 *)(unaff_EDI + 0xb28) = 0x2a;
    *(undefined1 *)(unaff_EDI + 0xb03) = 0;
    *(undefined1 *)(unaff_EDI + 0xb02) = 0;
  }
  if (*(char *)(unaff_EDI + 0xc70) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xc6a) = 0x4a;
    *(undefined2 *)(unaff_EDI + 0xc94) = 0;
    *(undefined1 *)(unaff_EDI + 0xc6f) = 0;
    *(undefined1 *)(unaff_EDI + 0xc6e) = 0;
  }
  if (*(char *)(unaff_EDI + 0xca4) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xc9e) = 2;
    *(undefined2 *)(unaff_EDI + 0xcc8) = 0;
    *(undefined1 *)(unaff_EDI + 0xca3) = 0;
    *(undefined1 *)(unaff_EDI + 0xca2) = 0;
  }
  if (*(char *)(unaff_EDI + 0xcd8) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xcd2) = 3;
    *(undefined2 *)(unaff_EDI + 0xcfc) = 0;
    *(undefined1 *)(unaff_EDI + 0xcd7) = 0;
    *(undefined1 *)(unaff_EDI + 0xcd6) = 0;
  }
  if (*(char *)(unaff_EDI + 0xd0c) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xd06) = 4;
    *(undefined2 *)(unaff_EDI + 0xd30) = 0;
    *(undefined1 *)(unaff_EDI + 0xd0b) = 0;
    *(undefined1 *)(unaff_EDI + 0xd0a) = 0;
  }
  if (*(char *)(unaff_EDI + 0xd40) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xd3a) = 5;
    *(undefined2 *)(unaff_EDI + 0xd64) = 0;
    *(undefined1 *)(unaff_EDI + 0xd3f) = 0;
    *(undefined1 *)(unaff_EDI + 0xd3e) = 0;
  }
  if (*(char *)(unaff_EDI + 0xd74) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xd6e) = 6;
    *(undefined2 *)(unaff_EDI + 0xd98) = 0;
    *(undefined1 *)(unaff_EDI + 0xd73) = 0;
    *(undefined1 *)(unaff_EDI + 0xd72) = 0;
  }
  if (*(char *)(unaff_EDI + 0xda8) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xda2) = 7;
    *(undefined2 *)(unaff_EDI + 0xdcc) = 0;
    *(undefined1 *)(unaff_EDI + 0xda7) = 0;
    *(undefined1 *)(unaff_EDI + 0xda6) = 0;
  }
  if (*(char *)(unaff_EDI + 0xddc) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xdd6) = 8;
    *(undefined2 *)(unaff_EDI + 0xe00) = 0;
    *(undefined1 *)(unaff_EDI + 0xddb) = 0;
    *(undefined1 *)(unaff_EDI + 0xdda) = 0;
  }
  if (*(char *)(unaff_EDI + 0xe10) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xe0a) = 9;
    *(undefined2 *)(unaff_EDI + 0xe34) = 0;
    *(undefined1 *)(unaff_EDI + 0xe0f) = 0;
    *(undefined1 *)(unaff_EDI + 0xe0e) = 0;
  }
  if (*(char *)(unaff_EDI + 0xe44) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xe3e) = 10;
    *(undefined2 *)(unaff_EDI + 0xe68) = 0;
    *(undefined1 *)(unaff_EDI + 0xe43) = 0;
    *(undefined1 *)(unaff_EDI + 0xe42) = 0;
  }
  if (*(char *)(unaff_EDI + 0xe78) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xe72) = 0xb;
    *(undefined2 *)(unaff_EDI + 0xe9c) = 0;
    *(undefined1 *)(unaff_EDI + 0xe77) = 0;
    *(undefined1 *)(unaff_EDI + 0xe76) = 0;
  }
  if (*(char *)(unaff_EDI + 0xeac) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xea6) = 2;
    *(undefined2 *)(unaff_EDI + 0xed0) = 0x2a;
    *(undefined1 *)(unaff_EDI + 0xeab) = 0;
    *(undefined1 *)(unaff_EDI + 0xeaa) = 0;
  }
  if (*(char *)(unaff_EDI + 0xee0) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xeda) = 3;
    *(undefined2 *)(unaff_EDI + 0xf04) = 0x2a;
    *(undefined1 *)(unaff_EDI + 0xedf) = 0;
    *(undefined1 *)(unaff_EDI + 0xede) = 0;
  }
  if (*(char *)(unaff_EDI + 0xf14) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xf0e) = 4;
    *(undefined2 *)(unaff_EDI + 0xf38) = 0x2a;
    *(undefined1 *)(unaff_EDI + 0xf13) = 0;
    *(undefined1 *)(unaff_EDI + 0xf12) = 0;
  }
  if (*(char *)(unaff_EDI + 0xf48) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xf42) = 5;
    *(undefined2 *)(unaff_EDI + 0xf6c) = 0x2a;
    *(undefined1 *)(unaff_EDI + 0xf47) = 0;
    *(undefined1 *)(unaff_EDI + 0xf46) = 0;
  }
  if (*(char *)(unaff_EDI + 0xf7c) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xf76) = 6;
    *(undefined2 *)(unaff_EDI + 4000) = 0x2a;
    *(undefined1 *)(unaff_EDI + 0xf7b) = 0;
    *(undefined1 *)(unaff_EDI + 0xf7a) = 0;
  }
  if (*(char *)(unaff_EDI + 0xfb0) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xfaa) = 7;
    *(undefined2 *)(unaff_EDI + 0xfd4) = 0x2a;
    *(undefined1 *)(unaff_EDI + 0xfaf) = 0;
    *(undefined1 *)(unaff_EDI + 0xfae) = 0;
  }
  if (*(char *)(unaff_EDI + 0xfe4) == '\0') {
    *(undefined2 *)(unaff_EDI + 0xfde) = 8;
    *(undefined2 *)(unaff_EDI + 0x1008) = 0x2a;
    *(undefined1 *)(unaff_EDI + 0xfe3) = 0;
    *(undefined1 *)(unaff_EDI + 0xfe2) = 0;
  }
  if (*(char *)(unaff_EDI + 0x1018) == '\0') {
    *(undefined2 *)(unaff_EDI + 0x1012) = 9;
    *(undefined2 *)(unaff_EDI + 0x103c) = 0x2a;
    *(undefined1 *)(unaff_EDI + 0x1017) = 0;
    *(undefined1 *)(unaff_EDI + 0x1016) = 0;
  }
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  *(undefined1 *)(unaff_EDI + 0x2da) = 1;
  *(undefined1 *)(unaff_EDI + 0x30e) = 1;
  *(undefined1 *)(unaff_EDI + 0x342) = 1;
  *(undefined1 *)(unaff_EDI + 0x376) = 1;
  *(undefined1 *)(unaff_EDI + 0x3aa) = 1;
  *(undefined1 *)(unaff_EDI + 0x2a6) = 1;
  *(undefined1 *)(unaff_EDI + 0x3de) = 1;
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  FUN_007f72e0(unaff_EDI,2);
  *(undefined1 *)(unaff_EDI + 0x450) = 1;
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  FUN_007f72e0(unaff_EDI,3);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
