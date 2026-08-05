# Annotated low-level: VOGEnvironmentLiquid_InitFilterPipeline_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004c0fe0` |
| VA | `0x004c0fe0`–`0x004c16cf` (**1776 B** / `0x6F0`) |
| Ghidra | `FUN_004c0fe0` |
| Canonical | `VOGEnvironmentLiquid_InitFilterPipeline_Inferred` |
| System | client / particle fluid / VOGEnvironmentLiquid |
| Date | 2026-08-04 (W37-F dual seal) |

## Machine-level notes

- Source: raw capture + W37-F re-verify (decompile ≡ raw; prologue/epilogue bytes).
- **thiscall**: `MOV ESI,ECX` at entry; child is the `0x40` liquid object from `FUN_004c1800`.
- Returns **0** (`XOR EAX,EAX`).
- Product file plate: all fail logs cite `VOGEnvironmentLiquid.cpp`.
- Device dims: `*(DAT_00d1f058+0x2c)+0x80/0x84` (same family as W32-R texture init).
- Texture create format **`0x15`** + flags **`0x4011`** via `FUN_0096f0e0` (W32-R peer pattern).

## ABI

| Item | Evidence | Conf |
|---|---|---|
| ECX = liquid child* | `8B F1`; sole caller passes child | **High** |
| No stack formals | bare `C3` | **High** |
| Return 0 | `33 C0` before epilogue | **High** |
| SEH | `LAB_009a1a6d` | **High** |
| Child span ≥ `0x40` | stores through `[0xf]` / `+0x3c` | **High** |

## Slot map (ESI child)

| Off | Role |
|---|---|
| `+0x00` | parent phase* |
| `+0x20` | filter 0 — UIFluidDownsample |
| `+0x24` | RT cascade 0 (quarter) |
| `+0x28` | filter 1 — UIFluidBlurHorizontal |
| `+0x2c` | RT cascade 1 |
| `+0x30` | filter 2 — UIFluidBlurVertical |
| `+0x34` | RT cascade 2 |
| `+0x38` | filter 3 — UIFluidSurfaceBlend (`+0x14` enable, `+0x15` flag) |
| `+0x3c` | full-dim RT / buffer window |

## Control-flow stages

```
dims = device width/height from DAT_00d1f058
child[+0x20,+0x28,+0x30,+0x38] = new(0x18) filter hosts (FUN_009886d0)
load UIFluidDownsample.fx → bind BackBufferTexture (*parent+0x94)
  set UIMapExtents0 = (1,1,1/w,1/h)
load UIFluidBlurHorizontal.fx
load UIFluidBlurVertical.fx
load UIFluidSurfaceBlend.fx; child[0xe]+0x15 = 0
child[+0x3c] = new(0xd4) RT; vcall(+8)(full dims)
child[+0x24] = new(0xd4) RT; vcall(+8)(dims>>2)
child[+0x2c] = new(0xd4) RT; vcall(+8)(again>>2)
child[+0x34] = new(0xd4) RT; vcall(+8)(again>>2)
FUN_0096f0e0(0x15, each cascade RT+0x80, 1, 0x4011, 0, 0)
  refcount install into RT+0xb8; RT+0xc0=0
*parent+0x98 = last tex; optional NormalMapTexture if parent+0x8c
pair FUN_007567b0 / FUN_009888b0 on filter/RT pairs
child[0xe]+0x14 = 1
cleanup local FX wrappers; return 0
```

## Call graph

| Direction | Target | Note |
|---|---|---|
| Sole caller | `0x004c1960` CreateLiquidChild | after ctor store `phase+0xc4` |
| Related ctor | `0x004c1800` | zeros filter/RT slots; sets global `DAT_00b03794` |
| Callees | FX/RT/filter helpers (unowned) | see function record |

## Open / residual

1. Product C++ class name of 0x40 child / 0x18 filter / 0xd4 RT hosts.
2. Full contracts of unowned FX helpers (`FUN_009886d0`, `FUN_009685e0`, `FUN_0096f0e0`, …).
3. Exact mapping of which RT feeds which filter pass at runtime.
4. Runtime / bit-exact / differential.
