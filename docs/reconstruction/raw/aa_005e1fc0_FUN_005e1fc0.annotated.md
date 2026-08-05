# Annotated low-level: FUN_005e1fc0 → Object_FwriteColorFields_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005e1fc0` |
| VA | `0x005e1fc0`–`0x005e203c` (124 B / `0x7C`) |
| System | object stream serialize (color extension) |
| Date | 2026-07-29 (W29-J dual; was scaffold 2026-07-23) |
| Canonical | `Object_FwriteColorFields_Inferred` |

## Machine-level notes

- **ABI:** `__thiscall` ECX=this; stack `FILE*`; **`ret 4`**.
- **Flow:** base serialize → fwrite `+0x170` → pack `+0x174` → pack `+0x184` → fwrite two u8×4.
- **Pack:** `FUN_00973820` ECX=stack dest, push float* src (W28-E seal).
- **Decompiler defect:** locals are packed colors, not `FILE*` copies.
- **Dispatch:** vtable `@ 0x009dc8e8` only (no code CALL xrefs).
- **Twin:** `FUN_005e2040` deserialize same offsets.

## Pseudocode (sealed reading)

```c
// thiscall; ret 4
void Object_FwriteColorFields_Inferred(Object *self, FILE *stream)
{
  uint8_t packedA[4], packedB[4];

  thunk_FUN_005a61d0(self, stream);           // base id/pose/name/children
  fwrite((char *)self + 0x170, 4, 1, stream);

  Color_PackFloat4_Scale255(packedA, (float *)((char *)self + 0x174));
  Color_PackFloat4_Scale255(packedB, (float *)((char *)self + 0x184));

  fwrite(packedA, 4, 1, stream);
  fwrite(packedB, 4, 1, stream);
}
```

## Open questions

- Product class / method name for vtable `0x009dc8e8`.
- Semantic of raw dword `+0x170`.
- Channel roles of the two float4 colors.
