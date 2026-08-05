# Annotated low-level: FUN_004bcca0 → CNDHash_FreeBuckets_009cb45c

| Field | Value |
|---|---|
| Stable ID | `aa_004bcca0` |
| VA | `0x004bcca0`–`0x004bccd4` exclusive (**52 B / `0x34`**) |
| System | container / CNDHash (object family `009cb45c`; reclaim stamp path `009cb360`) |
| Date | 2026-07-23 scaffold; 2026-07-29 W31-M dual |
| Canonical name | `CNDHash_FreeBuckets_009cb45c` |

## Machine-level notes

- Source: raw capture for `aa_004bcca0` + live re-verify (W31-M).
- Prefer bytes when decompiler conflicts (none observed).
- Ghidra shows `__fastcall` ECX; MSVC C++ method is **`__thiscall`** (same ECX this, plain `ret`).
- `free` is IAT `[0x009c6524]`; `operator_delete[]` is near-call `0x0048981c`.
- Reclaim callee `FUN_004e2bd0` walks buckets `0…mask` inclusive, virtual-deletes owned values, freelist-pushes nodes (`+0x20`), clears bucket heads — **not OWN** this dual.
- Alloc twin (not OWN body here): `FUN_004bc840` stamps sentinels `009cb350` — explains `free(*buckets)` = free contiguous sentinel slab base.

## Authoritative CF (annotated)

```c
// void __thiscall CNDHash_FreeBuckets_009cb45c(CNDHash *this)
// Body: 0x004bcca0–0x004bccd4 (52 B); plain ret
void __fastcall FUN_004bcca0(int this_hash)  // ECX = this
{
  // [ESI+0x0C] count ← 0
  *(undefined4 *)(this_hash + 0xc) = 0;

  // Reclaim all entries → freelist (+0x20); destroy owned values (node stamp path 009cb360)
  FUN_004e2bd0();  // thiscall; ECX still this via ESI/this

  // buckets (+0x10) = pointer table; *buckets = base of malloc'd sentinel slab
  if (*(undefined4 **)(this_hash + 0x10) != (undefined4 *)0x0) {
    free((void *)**(undefined4 **)(this_hash + 0x10));   // free slab
    operator_delete__(*(void **)(this_hash + 0x10));       // delete[] table
    *(undefined4 *)(this_hash + 0x10) = 0;
  }
  return;
}
```

## Byte skeleton

```text
004bcca0  PUSH ESI
004bcca1  MOV  ESI, ECX
004bcca3  MOV  dword ptr [ESI+0xC], 0
004bccaa  CALL FUN_004e2bd0          ; E8 21 5F 02 00
004bccaf  MOV  EAX, [ESI+0x10]
004bccb2  TEST EAX, EAX
004bccb4  JZ   done                  ; +0x1C → 004bccd2
004bccb6  MOV  EAX, [EAX]            ; *buckets
004bccb8  PUSH EAX
004bccb9  CALL dword ptr [free]      ; FF 15 24 65 9C 00
004bccbf  MOV  ECX, [ESI+0x10]
004bccc2  PUSH ECX
004bccc3  CALL operator_delete[]     ; E8 54 CB FC FF → 0048981c
004bccc8  ADD  ESP, 8
004bcccb  MOV  dword ptr [ESI+0x10], 0
004bccd2  POP  ESI
004bccd3  RET
004bccd4  INT3 pad…
```

## Layout mutations

| Off | Field | Mutation |
|---|---|---|
| `+0x0C` | count | ← 0 |
| `+0x10` | buckets* | free(*p) slab + delete[] table + null |
| `+0x08` | mask | unread here (reclaim uses) |
| `+0x14`/`+0x18` | list ends | untouched (Recreate zeros after) |
| `+0x20` | freelist | reclaim fills; not freed (dtor `FUN_0059c8a0`) |

## Callers / callees

| Direction | Symbol | Note |
|---|---|---|
| Caller | `CNDHash_Recreate_009cb45c` `FUN_004bcd40` @ `0x004bcd66` | W30-G sealed |
| Caller | Dtor `FUN_004bd140` @ `0x004bd18e` | installs vtbl `009cb45c` |
| Caller | Recreate-like `FUN_004e4990` @ `0x004e49b6` | parallel Free→size→Alloc `FUN_004e1980` |
| Caller | Dtor `FUN_004e66a0` @ `0x004e66ee` | installs vtbl `009cc6c0` (shares this FreeBuckets) |
| Callee | `FUN_004e2bd0` | owning reclaim |
| Callee | `free` / `operator_delete[]` | slab + table |

## Open questions

- Product / PDB English FreeBuckets name.
- Full value-type matrix inside `FUN_004e2bd0` (callee residual).
- Whether `009cc6c0` family needs a distinct FreeBuckets stamp in registry (body shared).
- Runtime / bit-exact / differential.
