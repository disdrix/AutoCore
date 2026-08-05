# Function record: Client_InitRenderEngine

| Field | Value |
|---|---|
| **Stable ID** | `aa_00948530` |
| **Canonical name** | `Client_InitRenderEngine` |
| **Ghidra name** | `FUN_00948530` |
| **Address** | `0x00948530` |
| **Body** | `0x00948530`–`0x00948ba7` (**1656 B** / `0x678`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client boot / window + render + Palantir |
| **Completion status** | **Dual-reviewed** W31-Q — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Bring up the client main window (`"XutoAssault"` / `"Auto Assault"`), initialize the RenderEngine (`FUN_007a3e90` + `"aa.bmp"`), optionally rewrite a global table when `DAT_00d1f050`, install Palantir desktop into sector-map parent and run `Client_InitPalantirViewBundle` (`FUN_004cda90`), then fire success-path subsystem hooks. Returns **0** or **`0x80004005`**.

## Signature

```c
// ECX = client app*; bare RET; 0 success / E_FAIL
uint32_t __fastcall Client_InitRenderEngine(void* app);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | sole static `Client_InitInstance` (`FUN_0094a6a0`) @ `0x0094ab16` — banners `@@InitRenderEngine` / `InitRenderEngine`; nonzero → `_exit(1)` |
| Nested (sample) | `FUN_007a3e90`, `FUN_004cda90`, `FUN_0043c5f0`, `FUN_0040af40`, `FUN_0040d9c0`, `FUN_007fb0a0`, Win32 window APIs, success helpers `FUN_007a2fd0`…`FUN_00935fe0`, `FUN_007a4480` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00948530_FUN_00948530.md`
- Annotated: `docs/reconstruction/raw/aa_00948530_FUN_00948530.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_InitRenderEngine.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00948530.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00948530_Client_InitRenderEngine.md`
- Review B: `docs/reconstruction/reviews/B_aa_00948530_Client_InitRenderEngine.md`
- Scaffold record: `docs/reconstruction/functions/aa_00948530_FUN_00948530.md`
- Scratch: `docs/reconstruction/tmp/a_00948530.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow stages + fail codes | **High** |
| ABI ECX + bare RET + 0 / E_FAIL | **High** |
| Product name from InitInstance banners | **High** |
| Window/class strings | **High** |
| Nested helper English | **Low–Med** |
| Flag field product labels | **Low** |
