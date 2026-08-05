# Raw capture: StatusFlag_GetDisplayName

| Field | Value |
|---|---|
| **Stable ID** | `aa_00580a20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00580a20` |
| **Body** | `0x00580a20`–`0x00580ac0` |
| **Canonical name** | `StatusFlag_GetDisplayName` |
| **Ghidra name** | `FUN_00580a20` |
| **System** | `skills-abilities` / status UI |
| **Capture timestamp** | `2026-07-29` (W19-T dual re-seal) |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Integrity** | Authoritative live decompile for dual seal; scaffold raw retained at `aa_00580a20_FUN_00580a20.md` |

---

## Raw pseudocode (authoritative decompile 2026-07-29)

```c
char * FUN_00580a20(int param_1)

{
  if (param_1 < 0x41) {
    if (param_1 == 0x40) {
      return "Afraid";
    }
    switch(param_1) {
    case 1:
      return "GM Frozen";
    case 2:
      return "Stunned";
    case 4:
      return "Locked Down";
    case 8:
      return "Silenced";
    case 0x10:
      return "Weapons Disabled";
    case 0x20:
      return "GM Chat Banned";
    }
  }
  else if (param_1 < 0x2001) {
    if (param_1 == 0x2000) {
      return "Immune to death";
    }
    if (param_1 == 0x80) {
      return "Confused";
    }
    if (param_1 == 0x200) {
      return "Blind";
    }
    if (param_1 == 0x1000) {
      return "Slowed";
    }
  }
  else {
    if (param_1 == 0x4000) {
      return "Speeding";
    }
    if (param_1 == 0x10000) {
      return "Zombied";
    }
  }
  return "in a world of hurt";
}
```

---

## Entry bytes (`read_memory` @ `0x00580a20`, 160 B)

```
8b442404 83f840 7f42 743a 83c0ff 83f81f 777c
0fb680e00a5800 ff2485c40a5800
b86c459d00 c3   ; "Afraid" path immediate when == 0x40 handled before table
...
c3              ; terminal RET @ 0x00580ac0
```

Prologue: `mov eax,[esp+4]; cmp eax,0x40` — **cdecl/stdcall single stack arg**, plain `RET` (`C3`). No this/ECX.

Jump-table base @ `0x00580ac4`; index-byte table @ `0x00580ae0` (body ends `0x00580ac0`).

---

## String pool (`read_memory` cluster near `0x009d44c8`)

Contiguous English status names including: `Speeding`, `Zombied`, `in a world of hurt`, `Immune to death`, `Confused`, `Blind`, `Slowed`, `Afraid`, `GM Chat Banned`, `GM Frozen`, `Silenced`, `Weapons Disabled`, `Locked Down`, `Stunned`.

Live decompile **≡** 2026-07-23 scaffold raw (no CF delta).
