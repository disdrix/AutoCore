# Annotated low-level: TFID_EqualsObjectId

| Field | Value |
|---|---|
| Stable ID | `aa_00404aa0` |
| VA | `0x00404aa0`–`0x00404ac6` |
| System | identity / TFID |
| Date | 2026-07-29 (dual A/B seal) |

## Machine-level notes

- Source: raw capture for `aa_00404aa0` + live re-decompile / `read_memory`.
- Prefer assembly when decompiler conflicts — **no conflict** on this unit.
- Leaf: zero callees, zero globals.
- `__cdecl`: plain `RET` (caller pops two pointer args).
- Equality is **three fields only** (`+0` dword, `+4` dword, `+8` byte). Not 16-byte `memcmp`.
- No null guards: both pointers must be valid id-block addresses.
- Sibling inverse: `TFID_NotEquals` `0x0040b150`.
- Common peer: `g_abTfidInvalid_A15870` @ `0x00a15870` (`-1,-1,0,...`).

## Pseudocode (annotated)

```c
// Returns 1 if ObjectId/TFID heads equal, else 0.
// Inferred layout names (repo TFID_16); body only uses widths shown.
int __cdecl TFID_EqualsObjectId(void *pA, void *pB)
{
  // +0: dwCoidLo
  if (*(int *)pA != *(int *)pB)
    return 0;
  // +4: dwCoidHi
  if (*(int *)((int)pA + 4) != *(int *)((int)pB + 4))
    return 0;
  // +8: bGlobal (byte); +9..+15 intentionally ignored
  if (*(char *)((int)pA + 8) != *(char *)((int)pB + 8))
    return 0;
  return 1;
}
```

## Open questions

- Product English for byte `+8` (`bGlobal` inferred).
- Whether any path stores non-zero pad that identity code elsewhere treats differently.
- PDB / product symbol confirmation.
