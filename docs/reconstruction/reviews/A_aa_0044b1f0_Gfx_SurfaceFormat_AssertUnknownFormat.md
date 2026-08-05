# Review A (reconstruction fidelity): `aa_0044b1f0` Gfx_SurfaceFormat_AssertUnknownFormat

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044b1f0` |
| **VA** | `0x0044b1f0` |
| **Canonical name** | `Gfx_SurfaceFormat_AssertUnknownFormat` (scaffold / string-linked) |
| **Better role name** | `Gfx_SurfaceFormat_CalcByteSize` (Probable — primary path is size, not assert) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0044b1f0_Gfx_SurfaceFormat_AssertUnknownFormat.md` |
| **System** | `graphics` / palantir Effects |
| **Live tools** | Ghidra `batch_decompile` + `read_memory` + callers (no `disassemble_bytes`) |
| **Verdict** | **accept** (CF + size multipliers + unknown log path sealed) |

---

## 1. Purpose

Compute **texture surface byte size** from a **format enum / FourCC** plus **width** and **height**. Known formats return `width * height * bpp_factor` (or DXT block formulas). Unknown formats format a log string via `FUN_0076cec0`, call `vog_LogMessage` with source `..\\palantir/graphics/Effects/effSurfaceFormat.h` line `0x1f2`, and return **0**.

Canonical slug `AssertUnknownFormat` only names the **failure** branch; live body is a full size calculator with that assert/log tail.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0044b1f0_FUN_0044b1f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0044b1f0_FUN_0044b1f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_SurfaceFormat_AssertUnknownFormat.cpp` |
| FUN twin | `docs/reconstruction/reconstructed-exact/FUN_0044b1f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0044b1f0_Gfx_SurfaceFormat_AssertUnknownFormat.md` |
| Live decompile | Ghidra `FUN_0044b1f0` @ `0x0044b1f0` (2026-07-29) |
| Live body | Ghidra `read_memory` entry + exit region |

---

## 3. Seal: calling convention + body prologue

`read_memory` @ `0x0044b1f0` (64 bytes):

```
0044b1f0  83 EC 10     sub  esp, 0x10
0044b1f3  83 F9 4F     cmp  ecx, 0x4F        ; format in ECX
...
0044b216  0F AF C6     imul eax, esi         ; width(EAX) * height(ESI)
0044b219  83 C4 10     add  esp, 0x10
0044b21c  C3           ret                   ; plain ret (no stack args)
```

Hex (entry): `83ec1083f94f7f2d74218d51ec83fa390f87f30000000fb69290b34400ff249578b344000fafc683c410c3…`

| Claim | Evidence | Conf |
|---|---|---|
| Format formal in **ECX** | `cmp ecx, 0x4f` at entry | **High** |
| Width in **EAX**, height in **ESI** (register formals) | decompiler `in_EAX` / `unaff_ESI`; `imul eax,esi` | **High** |
| No stack formals / plain `ret` | `C3` after `add esp,10` local frame only | **High** |
| Local frame 0x10 for DXT max()/temps | `sub esp,10` | **High** |
| Clean ≡ raw ≡ live decompile CF | three-rep match | **High** |

---

## 4. Size contract (sealed multipliers)

| Format class (examples) | Return | Conf |
|---|---|---|
| 1 bpp-ish (`0x1c`, `0x32`) | `w * h * 1` | **High** |
| 2 bpp (`0x17..0x1a`, `0x33`, `0x3c`, `0x49`, `0x50`, `0x6f`, `0x75`, …) | `w * h * 2` | **High** |
| 3 bpp (`0x14`, `0x4b`, `0x4d`, `0x4f`) | `w * h * 3` | **High** |
| 4 bpp (`0x15/16/23/3f/40/47`, `0x70/72`) | `w * h * 4` | **High** |
| 8 bpp (`0x24`, `0x6e/71/73`) | `w * h * 8` | **High** |
| 16 bpp (`0x74`) | `w * h * 0x10` | **High** |
| FourCC **DXT1** `0x31545844` (`'DXT1'`) | `max(1, ceil(w/4)) * max(1, ceil(h/4)) * 8` | **High** |
| FourCC **DXT2–5** `0x32545844`…`0x35545844` | same block grid `* 0x10` | **High** |
| Unknown | log + return **0** | **High** |

DXT ceil formula sealed as signed-friendly `(x + (x>>31 & 3)) >> 2` with floor of 1 via pointer select of constant `1` vs computed blocks.

---

## 5. Unknown / assert path

```
FUN_0076cec0(&buf, "Unknown Texture format : format:%u width:%u height:%u", format);
vog_LogMessage("..\\palantir/graphics/Effects/effSurfaceFormat.h", 0x1f2, 3, msg);
return 0;
```

| Claim | Conf |
|---|---|
| String path + line `0x1f2` (= 498) | **Confirmed** (decompile + clean) |
| Level arg `3` | **High** |
| Callees only: format helper + `vog_LogMessage` | **High** (Ghidra callees) |

---

## 6. Callers

| Caller | VA | Notes |
|---|---|---|
| `FUN_0096c730` | `0x0096c730` | xref @ `0x0096c7a0` |
| `FUN_0096c810` | `0x0096c810` | xref @ `0x0096c875` |

Two static call sites only (graphics surface helpers; not dualed here).

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = surface **byte size** calculator | **High** | body returns size products |
| Name `AssertUnknownFormat` | **Probable** (partial) | only unknown branch; string from effSurfaceFormat.h |
| Register triple `(fmt=ECX, w=EAX, h=ESI)` | **High** | bytes + decomp |
| DXT1/2–5 FourCC decoding | **High** | constants `0x31..0x35545844` |
| Unknown → log + 0 | **High** | sealed |
| Full D3DFORMAT enum map English names | **Open** | case IDs sealed; product names Probable |
| Runtime / bit-exact | **Open** | deferred |

**Verdict:** **accept** — control flow, register formals, multipliers, DXT block math, and unknown log path sealed.
