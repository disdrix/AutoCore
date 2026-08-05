# Annotated low-level: Pod8_CopyIfNonNull (`FUN_0043ece0`)

| Field | Value |
|---|---|
| Stable ID | `aa_0043ece0` |
| VA | `0x0043ece0`–`0x0043ecee` (**15 B**) |
| System | POD store helper (GuardedVector stride-2 family) |
| Date | 2026-07-29 (W32-M dual) |

## Machine-level notes

- **Bytes win** on ABI: **EAX=dst** (nullable), **ECX=src** (`const PodU32x2*`), bare **`RET`**.
- Decompiler `__fastcall` + `in_EAX` matches registers; return-type plate `undefined` is a Ghidra signature gap (void leaf).
- Prefer this helper only when dest may be null (lazy page alloc failed / null page base).
- Sibling null-safe 5-byte path: `FUN_0043ecf0` @ `0x0043ecf0` (W32-N).

## Pseudocode (annotated)

```c
// EAX = dest (nullable); ECX = const PodU32x2* src; bare RET
void Pod8_CopyIfNonNull(PodU32x2* dest /*EAX*/, const PodU32x2* src /*ECX*/)
{
  if (dest != nullptr) {
    dest->a = src->a;   // MOV [EAX], [ECX]
    dest->b = src->b;   // MOV [EAX+4], [ECX+4]
  }
}
```

## Byte map

```
85 C0           TEST EAX, EAX      ; null gate
74 0A           JZ   ret
8B 11           MOV  EDX, [ECX]
89 10           MOV  [EAX], EDX
8B 49 04        MOV  ECX, [ECX+4]
89 48 04        MOV  [EAX+4], ECX
C3              RET
CC              pad → 0043ecf0
```

## Call graph

| Dir | Target |
|---|---|
| Caller | `FUN_0043e970` / `GuardedVector_PushBack_Stride2_U32x2` @ call `0x0043e9cf` |
| Callees | none (leaf) |

## Open residual

- Product/PDB English.
- Runtime / bit-exact.
