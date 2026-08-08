# Annotated low-level: CNDUIWindow_CompleteDtor (`FUN_007b5be0`)

| Field | Value |
|---|---|
| Stable ID | `aa_007b5be0` |
| VA | `0x007b5be0`–`0x007b5dcc` (**493 B**) |
| System | client / ND UI base window |
| Date | 2026-08-05 (WQ9K-F dual seal) |
| Product name | `CNDUIWindow_CompleteDtor` |
| Ghidra | `FUN_007b5be0` |
| Prior scaffold alias | `Named_VOG_DEBUG_STOP_007b5be0` (string-only; superseded by RTTI) |

## Machine-level notes

- Source: raw capture + WQ9K-F re-verify (`disassemble_function` + multi-span `read_memory`).
- Ghidra marks some `operator_delete` as noreturn; **false** — free chain continues, base runs, bare `RET`.
- Role: MSVC **complete destructor** for **CNDUIWindow** (RTTI `.?AVCNDUIWindow@@`).
- ABI: ECX = this; SEH `LAB_009b325c`; bare `RET`; does **not** free host.

## Signature

```c
// ECX = this. SEH LAB_009b325c. ADD ESP,0x10; C3. void.
void __fastcall CNDUIWindow_CompleteDtor(void* self);
```

## Control flow (annotated)

```c
void __fastcall FUN_007b5be0(undefined4 *self /* ECX */)
{
  // SEH frame: LAB_009b325c; ESI=this; EDI=1; EBX=0
  *self = &PTR_FUN_00a960ac;           // CNDUIWindow primary vtbl
  // EH state = 1

  // Debug: destroying window that still has owner cookie @ +0x2B0
  if (self[0xAC] /* +0x2B0 */) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    if (self[0xA1] /* +0x284 filename */ == 0)
      FUN_007a4480(1, "Deleting an unknown window with an owner!");
    else
      FUN_007a4480(1, "Deleting a window with an owner! (filename: %s)", self[0xA1]);
  }

  _DAT_00d17954 -= 1;                  // global live window count (ctor ++)

  // Owned child interface @ +0x2B4 with flag byte @ +0xBD
  if (self[0xAD] && *(char*)((char*)self + 0xBD)) {
    (*(code**)(*(int*)self[0xAD] + 0xC))(1); // vcall +0xC with flag 1
    self[0xAD] = 0;
    *(char*)((char*)self + 0xBD) = 0;
  }

  FUN_007a8580();                      // shared UI teardown
  FUN_007aec70();
  FUN_007aff00();

  // Owned heap blocks — free then always null (order sealed by disasm):
  // +0x28C: FUN_00797d70 then operator_delete
  // +0x2B8: operator_delete (QPC/timer helper from ctor)
  // +0x274, +0x280, +0x27C, +0x278, +0x284, +0x288: operator_delete[]
  // 11 dwords starting +0x45C: operator_delete[] each, always null

  // Nested object at +0x1E8:
  //   install PTR_FUN_00a964b8; FUN_00424060();
  //   install PTR_FUN_00a964ac; FUN_00424060();
  //   DeleteCriticalSection(this+0x1EC)
  // EH state = -1
  FUN_00759de0();                      // super-base complete
  // SEH restore; return (no free of self)
}
```

## Key offsets

| Offset | Role |
|---|---|
| `+0x00` | vtbl → `PTR_FUN_00a960ac` |
| `+0xBD` | flag byte for owned child release |
| `+0x1E8` | nested object + dual vtbl teardown |
| `+0x1EC` | CRITICAL_SECTION |
| `+0x274`…`+0x288` | owned string/buffer slots (delete[]) |
| `+0x28C` | owned block (dtor + delete) |
| `+0x2B0` | owner cookie (debug path) |
| `+0x2B4` | owned child iface* |
| `+0x2B8` | QPC/timer helper* |
| `+0x45C` | 11× owned dword ptrs |

## Peers

| Peer | VA | Note |
|---|---|---|
| Scalar | `0x00423e50` | vtbl[0]; complete then `flags&1` delete |
| Ctor | `0x007b5dd0` | installs same vtbl; size class `0x488` |
| Super-base | `0x00759de0` | not OWN this wave |
| Buffered complete | `0x0078ca80` | chains into this |
| Waypoint complete | `0x00832fa0` | chains into this (WQ9J-B) |

## Open residual

- Product English for free helpers (`FUN_007a8580` / `007aec70` / `007aff00` / `00797d70` / `00424060` / `00759de0`).
- Exact layout of string slots / 11-element array English.
- Prior scaffold name `Named_VOG_DEBUG_STOP_*` should yield to product RTTI name.
- Runtime / bit-exact / differential.
