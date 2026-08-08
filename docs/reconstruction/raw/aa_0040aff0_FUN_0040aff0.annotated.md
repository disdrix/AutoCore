# Annotated low-level: Object_CopyTfid16At228_Inferred (`FUN_0040aff0`)

| Field | Value |
|---|---|
| Stable ID | `aa_0040aff0` |
| VA | `0x0040aff0` |
| System | identity / TFID |
| Date | 2026-07-23 scaffold; **2026-08-04 WQ9R-B dual seal** |

---

## Machine-level notes

- **ABI:** `__thiscall`; ECX = object with TFID at `+0x228`; stack `TFID_16* out`; **`ret 4`**.
- **Body:** 38 bytes; leaf; four sequential dword copies (16 B).
- **Return:** EAX = `out` (entry load preserved).
- Prefer these bytes if decompiler invents width/return noise.

## Annotated pseudocode

```c
// Object_CopyTfid16At228_Inferred
// Copy 16-byte TFID identity blob from this+0x228 into *out.
// __thiscall; ret 4; returns out in EAX.
void __thiscall Object_CopyTfid16At228_Inferred(void *thisObj, uint32_t *out /* TFID_16 */)
{
  // thisObj += 0x228 in register; then:
  out[0] = *(uint32_t *)((char *)thisObj + 0x228); // dwCoidLo-ish
  out[1] = *(uint32_t *)((char *)thisObj + 0x22c); // dwCoidHi-ish
  out[2] = *(uint32_t *)((char *)thisObj + 0x230); // bGlobal + pads
  out[3] = *(uint32_t *)((char *)thisObj + 0x234); // pad word
}
```

## Call-site pattern

Typical: obtain identity/owner via `vtbl+0x214` / `vtbl+0x1d8`, then copy TFID and feed `TFID_EqualsObjectId` / `TFID_NotEquals` / `FUN_004bb0d0`.

## Open

- Product/PDB symbol.
- Exact formal type of `this` (identity interface vs full CVOGObject — field offset sealed either way).
- Runtime / bit-exact.
