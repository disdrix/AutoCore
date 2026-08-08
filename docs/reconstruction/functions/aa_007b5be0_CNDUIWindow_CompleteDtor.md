# Function record: CNDUIWindow_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b5be0` |
| **Canonical name** | `CNDUIWindow_CompleteDtor` |
| **Ghidra name** | `FUN_007b5be0` |
| **Address** | `0x007b5be0` |
| **Body** | `0x007b5be0`–`0x007b5dcc` (**493 B** / `0x1ED`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | UI / CNDUIWindow complete destructor |
| **Completion status** | **Dual-reviewed** WQ9K-F — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC-style **complete destructor** for the class whose primary vtbl is `PTR_FUN_00a960ac`. RTTI seals product name **CNDUIWindow** (`.?AVCNDUIWindow@@`). Installs that vtbl; optional owner-debug (`VOG_DEBUG_STOP` / "Deleting a window with an owner!"); decrements live window counter `_DAT_00d17954`; releases owned child at `+0x2B4`, heap slots, nested CS object at `+0x1E8`; chains super-base `FUN_00759de0`. Does **not** free `this`. Bound as the body behind scalar-deleting `vtbl[0]` (`0x00423e50`). Ctor twin `FUN_007b5dd0` installs the same vtbl.

## Signature

```c
// ECX = this. SEH LAB_009b325c. Bare RET after ADD ESP,0x10. void.
void __fastcall CNDUIWindow_CompleteDtor(void* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `CNDUIWndBuffered_CompleteDtor`, `CWndWaypointIcon_CompleteDtor`, scalar `0x00423e50`, many UI complete/EH |
| Callees | debug log, shared teardown helpers, delete/delete[], nested complete, `DeleteCriticalSection`, `FUN_00759de0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007b5be0_FUN_007b5be0.md`
- Annotated: `docs/reconstruction/raw/aa_007b5be0_FUN_007b5be0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDUIWindow_CompleteDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_007b5be0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_007b5be0_CNDUIWindow_CompleteDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_007b5be0_CNDUIWindow_CompleteDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_007b5be0_FUN_007b5be0.md`
- Ctor twin: `docs/reconstruction/functions/aa_007b5dd0_*`
- Buffered pair: `aa_0078ca80_CNDUIWndBuffered_CompleteDtor.md` (OWN WQ9K-F)

## Confidence

| Claim | Level |
|---|---|
| Complete-dtor role (no free this) | **High** |
| ABI ECX + SEH + bare RET | **High** |
| Product RTTI name CNDUIWindow | **High** |
| Free-null order + nested CS | **High** |
| Helper / slot product English | **Low** |
| Runtime | **Open** |
