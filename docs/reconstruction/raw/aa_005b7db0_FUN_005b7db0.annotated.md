# Annotated low-level: FUN_005b7db0 → Elem0x28_DefaultCtor

| Field | Value |
|---|---|
| Stable ID | `aa_005b7db0` |
| VA | `0x005b7db0`–`0x005b7dee` exclusive (**62 B** / `0x3E`) |
| System | class / cookie-vector element default ctor (stride 0x28) |
| Date | 2026-07-29 (W31-L re-annotate) |
| Canonical | `Elem0x28_DefaultCtor` |

---

## Machine-level notes

- **thiscall** ECX = element; bare **`C3`**; void.
- SEH frame present (`LAB_009a6ad8`) even though body has no throw — MSVC vector-ctor registration pattern.
- Zeros dwords at **+4, +8, +0xc, +0x14, +0x18, +0x1c, +0x24** only.
- Leaves **+0, +0x10, +0x20** untouched (not freed by peer dtor either).
- Sole DATA xref: `FUN_004941b0` @ `0x004942db` as ctor for `_eh_vector_constructor_iterator_(…, 0x28, count, FUN_005b7db0, FUN_005b8000)`.
- Peer dtor: `Elem0x28_CompleteDtor` (`0x005b8000`, W29-F) frees the same slots this zeros.

## Pseudocode (annotated)

```c
// __thiscall; ECX=elem; bare RET; void
// SEH: LAB_009a6ad8 (install/teardown only)
void __thiscall Elem0x28_DefaultCtor(void* elem)
{
  // buffer triple @ +4/+8/+0xc
  *(uint32_t*)((char*)elem + 0x04) = 0;
  *(uint32_t*)((char*)elem + 0x08) = 0;
  *(uint32_t*)((char*)elem + 0x0c) = 0;
  // list-ptr vector triple @ +0x14/+0x18/+0x1c
  *(uint32_t*)((char*)elem + 0x14) = 0;
  *(uint32_t*)((char*)elem + 0x18) = 0;
  *(uint32_t*)((char*)elem + 0x1c) = 0;
  // owned @ +0x24
  *(uint32_t*)((char*)elem + 0x24) = 0;
  // +0 / +0x10 / +0x20 intentionally not written
}
```

## Open questions

- Product/PDB demangle for element type.
- Semantic meaning of untouched +0 / +0x10 / +0x20 fields.
- Runtime / bit-exact / differential.
