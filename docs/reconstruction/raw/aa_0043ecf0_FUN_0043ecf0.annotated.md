# Annotated low-level: PodU32U8_CopyIfNonNull (`FUN_0043ecf0`)

| Field | Value |
|---|---|
| Stable ID | `aa_0043ecf0` |
| VA | `0x0043ecf0`–`0x0043ecfe` (**15 B**) |
| System | STL / guarded ring-deque POD store helper |
| Date | 2026-07-23 scaffold; W32-N seal 2026-07-29 |

## Machine-level notes

- **Leaf** null-checked POD store: EAX=dest, ECX=src.
- Bytes: `TEST EAX,EAX / JZ; MOV EDX,[ECX]; MOV [EAX],EDX; MOV CL,[ECX+4]; MOV [EAX+4],CL; RET`.
- Twin of `FUN_0043ece0` (u32×2): only second-field width differs (byte vs dword).
- Sole caller: `GuardedVector_PushBack_Stride2_U32U8` @ `0x0043ea3f` (slot LEA then CALL).
- Prefer bytes when decompiler shows `__fastcall` with phantom `in_EAX` — both registers are intentional formals.

## Pseudocode (annotated)

```c
// EAX = dest (nullable slot); ECX = const PodU32U8* src; RET (no stack)
void PodU32U8_CopyIfNonNull(uint8_t* dest /*EAX*/, const PodU32U8* src /*ECX*/)
{
  if (dest != nullptr) {
    *reinterpret_cast<uint32_t*>(dest) = src->key; // *src
    dest[4] = src->flag;                           // *(uint8*)(src+4)
  }
}
```

## ABI / layout

| Slot | Role |
|---|---|
| EAX | dest 8-byte slot base (null → skip write) |
| ECX | source POD `{u32 key; u8 flag}` |
| Writes | 5 bytes (u32 @0 + u8 @4); bytes 5–7 of slot untouched |

## Open questions

- Product/PDB element English for `PodU32U8`.
- Runtime / bit-exact (deferred).
