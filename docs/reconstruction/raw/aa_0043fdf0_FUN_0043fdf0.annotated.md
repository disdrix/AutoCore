# Annotated low-level: NestedHash_Ctor_Sentinel0xC_Inferred (`FUN_0043fdf0`)

| Field | Value |
|---|---|
| Stable ID | `aa_0043fdf0` |
| VA | `0x0043fdf0`–`0x0043fe51` (**98 B** / `0x62`) |
| System | shared nested hash/map shell (list head + 9-bucket ptr table) |
| Date | 2026-07-29 (W34-F dual seal; scaffold 2026-07-23) |
| Canonical name | `NestedHash_Ctor_Sentinel0xC_Inferred` |

## Machine-level notes

- **ABI (bytes win):** stack formal `self*`; **`RET 4`**; returns `self` in EAX. Not ECX-thiscall.
  - After SEH + `push ecx` + `push esi`: `MOV ESI,[ESP+0x18]` = stack this.
  - Epilog: `MOV EAX,ESI`; restore FS:0; `ADD ESP,0x10`; `C2 04 00`.
- **SEH:** handler `LAB_009bc89b` (same plate as AssResolverCore nested twin `FUN_00469db0`).
- **Callees:**
  - `FUN_004933f0` / `StdList_AllocSentinel_0xC_Inferred` (W32-P) — `operator_new(0xC)` + circular next/prev.
  - `FUN_004646e0` / `PtrVecShell_InitFill_Inferred` (W33-B) — stdcall 3-arg, **count=9**, fill = &sentinel local.
- **Callers (3):**
  - `FUN_0074e380` @ `0x0074e3ba` — 0x40 outer; `FUN_0043fdf0(param_1+5)` float* arithmetic → **+0x14**.
  - `FUN_0096eec0` @ `0x0096eeea` — places this shell at object base, then extra fields at +0x28+.
  - `FUN_00996bc0` @ `0x00996c02` — `FUN_0043fdf0(param_1+10)` dword* → **+0x28**.
- **Family twin:** identical 98 B CF to `AssResolverA_NestedHash_Ctor_Inferred` (`0x00423cf0`); only sentinel factory differs (**0x0C** vs **0x28**).
- Prefer bytes for ABI/`RET 4`; decompiler CF matches stores.

## Pseudocode (annotated)

```c
// stdcall 1 formal; RET 4; returns self
// Ghidra: int FUN_0043fdf0(int param_1)
NestedHash* NestedHash_Ctor_Sentinel0xC_Inferred(NestedHash* self /*stack*/)
{
  // SEH: LAB_009bc89b, state -1
  void* sentinel = StdList_AllocSentinel_0xC_Inferred(); // FUN_004933f0
  self->sentinel = sentinel;             // +0x08
  self->size = 0;                        // +0x0c
  // state = 0
  void* fill = self->sentinel;
  PtrVecShell_InitFill_Inferred(&self->shell, /*count*/9, &fill); // +0x10
  self->flag20 = 1;                      // +0x20
  self->flag24 = 1;                      // +0x24
  return self;
}
```

## Layout (span 0x28)

| Off | Field | Written |
|---|---|---|
| +0x00 | pad | no |
| +0x04 | pad | no |
| +0x08 | sentinel* (0x0C node) | yes |
| +0x0c | size | 0 |
| +0x10 | shell+0 | InitFill leaves unwritten |
| +0x14..+0x1c | begin/end/end_cap | via InitFill |
| +0x20 | flag | 1 |
| +0x24 | flag | 1 |

## Open questions

- Product/PDB class English across the three hosts.
- Semantic meaning of flags +0x20/+0x24 and unwritten +0x00/+0x04.
- Why some hosts pick 0x0C sentinel vs Ass 0x28 / this dual’s 0x30 sibling.
- Runtime / bit-exact / differential.
