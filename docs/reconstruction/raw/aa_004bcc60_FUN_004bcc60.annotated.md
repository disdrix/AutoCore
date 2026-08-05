# Annotated low-level: FUN_004bcc60 → CNDHash_FreeBuckets_009cb450

| Field | Value |
|---|---|
| Stable ID | `aa_004bcc60` |
| VA | `0x004bcc60`–`0x004bcc94` exclusive (**52 B / `0x34`**) |
| System | container / CNDHash (object family `009cb450` / tableC; reclaim stamp path `009cb358`) |
| Date | 2026-07-23 scaffold; 2026-07-29 W31-M dual |
| Canonical name | `CNDHash_FreeBuckets_009cb450` |

## Machine-level notes

- Source: raw capture for `aa_004bcc60` + live re-verify (W31-M).
- Ghidra `__fastcall` ECX ≡ MSVC **`__thiscall`** plain `ret`.
- **Byte twin** of `FUN_004bcca0` / `CNDHash_FreeBuckets_009cb45c`: same 52 B skeleton; only reclaim near-call reloc (`FUN_004bcae0` vs `FUN_004e2bd0`) and `operator_delete[]` PC-relative reloc (absolute target still `0x0048981c`).
- Alloc twin (not OWN body here): `FUN_004bc7a0` stamps sentinels `009cb348`.
- Sole static consumers: Recreate `FUN_004bcce0` + Dtor `FUN_004bd0b0` (vtbl `009cb450`).

## Authoritative CF (annotated)

```c
// void __thiscall CNDHash_FreeBuckets_009cb450(CNDHash *this)
// Body: 0x004bcc60–0x004bcc94 (52 B); plain ret
void __fastcall FUN_004bcc60(int this_hash)  // ECX = this
{
  *(undefined4 *)(this_hash + 0xc) = 0;   // count ← 0
  FUN_004bcae0();                         // owning reclaim (node stamp path 009cb358)
  if (*(undefined4 **)(this_hash + 0x10) != (undefined4 *)0x0) {
    free((void *)**(undefined4 **)(this_hash + 0x10));  // sentinel slab
    operator_delete__(*(void **)(this_hash + 0x10));    // delete[] pointer table
    *(undefined4 *)(this_hash + 0x10) = 0;
  }
  return;
}
```

## Byte skeleton

```text
004bcc60  PUSH ESI
004bcc61  MOV  ESI, ECX
004bcc63  MOV  dword ptr [ESI+0xC], 0
004bcc6a  CALL FUN_004bcae0          ; E8 71 FE FF FF
004bcc6f  MOV  EAX, [ESI+0x10]
004bcc72  TEST EAX, EAX
004bcc74  JZ   done
004bcc76  MOV  EAX, [EAX]            ; *buckets
004bcc78  PUSH EAX
004bcc79  CALL dword ptr [free]      ; FF 15 24 65 9C 00
004bcc7f  MOV  ECX, [ESI+0x10]
004bcc82  PUSH ECX
004bcc83  CALL operator_delete[]     ; E8 94 CB FC FF → 0048981c
004bcc88  ADD  ESP, 8
004bcc8b  MOV  dword ptr [ESI+0x10], 0
004bcc92  POP  ESI
004bcc93  RET
004bcc94  INT3 pad…
```

## Twin diff vs `0x004bcca0`

| Site | `004bcca0` | `004bcc60` |
|---|---|---|
| Reclaim target | `FUN_004e2bd0` | `FUN_004bcae0` |
| free IAT | `0x009c6524` | same |
| `operator_delete[]` | `0x0048981c` | same absolute |
| Body length | 52 B | 52 B |
| Object family (primary) | `009cb45c` | `009cb450` |
| Alloc twin | `FUN_004bc840` / `009cb350` | `FUN_004bc7a0` / `009cb348` |

## Layout mutations

Same field template as twin: zero `+0x0C`; reclaim via mask; free slab + delete[] `+0x10`; leave freelist `+0x20` and list ends for parent.

## Callers / callees

| Direction | Symbol | Note |
|---|---|---|
| Caller | `CNDHash_Recreate_009cb450` `FUN_004bcce0` @ `0x004bcd06` | W30-G sealed; host always log2=5 |
| Caller | Dtor `FUN_004bd0b0` @ `0x004bd0fe` | installs vtbl `009cb450` |
| Callee | `FUN_004bcae0` | owning reclaim |
| Callee | `free` / `operator_delete[]` | slab + table |

## Open questions

- Product / PDB English.
- Full reclaim value matrix in `FUN_004bcae0` (node value slot `+8` vs twin `+0xC` — callee residual).
- Runtime / bit-exact / differential.
