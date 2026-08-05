# Annotated low-level: FUN_0075ceb0 → GfxView_Ctor_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0075ceb0` |
| VA | `0x0075ceb0`–`0x0075d1fc` (**0x54D B**) |
| System | graphics / client camera (GfxView) |
| Date | 2026-07-29 W31-O |
| Canonical | `GfxView_Ctor_Inferred` |

## Machine-level notes

- **Ctor worker**: ECX=`this`, returns `this`, SEH `LAB_009b25d7`, epilogue `ADD ESP,0x2C; RET`.
- Product path sealed: `C:\vog\1_code\palantir\palantir\graphics\gfxView.cpp` + `"PalViewBackground.fx"`.
- Object size **0x150** from sole factories (`FUN_004cda90`, `FUN_00968a50`).
- Layout cross-checked with `GfxView_EnsureProjection_Inferred` (`+0x48` dirty, `+0xF0/+0xF4` near/far, `+0x10C` FOV, `+0x14D` Z-gate).
- Two `FUN_0043f780` allocs seeded from **identity 4×4** `DAT_00afdf70` (64 B diagonals 1.0).
- Default near **0.5** / far **10000** at ctor; factory often re-sets near via `GfxView_SetNear` and far via twin/set path.
- Fail path: severity-3 dialog → optional `c:\VOGCRASH.txt` log → `raise(0x16)` → `ExitProcess(3)` (noreturn).

## Layout (this) — ctor-initialized highlights

| Off | Init | Role |
|---:|---|---|
| `+0x00` | `PTR_FUN_00a9edc8` | GfxView vtbl |
| `+0x04` | 0 | (cleared) |
| `+0x08` | aligned xform / `FUN_00972cc0` | 0xC0 @ 16-align block |
| `+0x0C` | `g_flOne` (1.0) | zoom (authoritative; EnsureProjection) |
| `+0x10…` | `FUN_0073f590` | embedded subobject |
| `+0x40` | self (success) | back-pointer |
| `+0x48` | 1 | proj dirty |
| `+0x49` | 1 | flag |
| `+0x50` / `+0x54` | identity mats | two 4×4 allocations |
| `+0x5C…+0xBB` | zero (0x18 dwords) | success wipe |
| `+0xCC` | 1 | aux dirty |
| `+0xDC…+0xE8` | `DAT_00d1f01c…028` | viewport-ish globals (often 0 at static) |
| `+0xEC` | 0 | mode 0=persp |
| `+0xF0` | **0.5** | near |
| `+0xF4` | **10000** | far |
| `+0x104` | **1000** | separate float (`DAT_00a0f520`) |
| `+0x10C` | **π/3** | FOV radians |
| `+0x148` | -1 | `DAT_00afdf0c` |
| `+0x14D` | 0 | Z-scale gate (EnsureProjection) |

## Pseudocode (annotated summary)

```c
// ECX = GfxView* (pre-allocated 0x150); returns this
GfxView * __fastcall GfxView_Ctor_Inferred(GfxView *this)
{
  // SEH install; vtbl; zoom=1; aligned transform; sub-ctor @ +0x10
  // dirty flags; two identity matrices; near=0.5 far=10000 FOV=pi/3
  // Create background VB (0x144 bytes, FVF-ish 4); load PalViewBackground.fx
  // on success: +0x40=this; zero middle block; return this
  // on hard fail: VOGCRASH + ExitProcess(3)
}
```

Full CF ≡ raw decompile; nested D3D helper product names open.

## Open questions

- MSVC demangled class/method beyond path evidence.
- Product roles of `+0x104`, nested `PTR_FUN_00a9db18` subobjects, `FUN_00414c20` FVF args.
- `FUN_00972cc0` return in EDX vs EAX pairing under live ABI.
- Runtime / bit-exact golden.
