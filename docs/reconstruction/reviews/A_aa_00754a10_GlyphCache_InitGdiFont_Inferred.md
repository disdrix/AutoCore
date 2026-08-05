# Review A (reconstruction fidelity): `aa_00754a10` GlyphCache_InitGdiFont_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00754a10` |
| **VA** | `0x00754a10`–`0x00754edc` exclusive (**1228 B** / `0x4CC`) |
| **Canonical name** | `GlyphCache_InitGdiFont_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00754a10` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-N) |
| **Counterpart** | `reviews/B_aa_00754a10_GlyphCache_InitGdiFont_Inferred.md` |
| **System** | GlyphCache / Palantir GDI font open |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (body + epilogue + factory call site) + `analyze_function_complete` + callers/xrefs + W35-H ctor / W37-AE factory context. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Initialize GDI resources on an existing **GlyphCache** (`0xB8`):

1. Style-tagged display name (`|Bold`/`|Italic`/`|Shadow`/`|Outline` or `"Normal"`).
2. `LOGFONTA` + `CreateFontIndirectA` + compatible DC + `GetTextMetricsW`.
3. Publish metrics; pad shadow/outline cell sizes.
4. Power-of-two atlas dims (floor 0x100, cap `DAT_00d1f044+0x6C/0x70`).
5. `CreateDIBSection` 32bpp top-down; white text / transparent bk.

**ABI:** **ESI=this**, **ECX=style**, stack **face + height**, **`RET 8`**, EAX **0 / -1**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-N append) | `docs/reconstruction/raw/aa_00754a10_FUN_00754a10.md` |
| Annotated | `docs/reconstruction/raw/aa_00754a10_FUN_00754a10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GlyphCache_InitGdiFont_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00754a10.cpp` |
| Function record | `docs/reconstruction/functions/aa_00754a10_FUN_00754a10.md` |
| Named record | `docs/reconstruction/functions/aa_00754a10_GlyphCache_InitGdiFont_Inferred.md` |
| Live | decompile CF ≡ scaffold; epilogue `C2 08 00`; entry `MOV EBX,ECX` |
| Factory caller | `FUN_0073bc50` @ `0x0073bd22`/`0x0073bd33` — `MOV ESI,EDI`; face then Arial |
| Host ctor | `GlyphCache_PlacementCtor` W35-H (`0xB8`) |
| Product string | `…\graphics\gfxFontImpl.cpp` |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// ESI=GlyphCache*; ECX=style; stack face*, height; RET 8
int GlyphCache_InitGdiFont_Inferred(uint32_t style, char* face, int height);
```

| Slot | Source | Conf |
|---|---|---|
| this | **ESI** (field stores; caller `MOV ESI,EDI`) | **High** |
| style | **ECX** (`MOV EBX,ECX`; bit tests) | **High** |
| face / height | stack; snprintf/strncpy/LOGFONT | **High** |
| cleanup | **RET 8** | **High** |
| return | EAX 0 / 0xFFFFFFFF | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
maybe FUN_00754970
build style tag → display name + style dword
LOGFONT → CreateFont → DC → metrics → recreate font
publish metrics + shadow/outline pad
pow2 atlas vs device caps
CreateDIBSection → setup text attrs → return 0
fail → vog_LogMessage(gfxFontImpl.cpp, …) → return -1
```

| Stage | Match | Conf |
|---|---|---|
| Style bits 0–3 | **Yes** | **High** |
| Weight 400/700 | **Yes** | **High** |
| Quality 5 / 3 if h<14 | **Yes** | **High** |
| Metrics publish offsets | **Yes** | **High** |
| Atlas pow2 + DIB 32bpp | **Yes** | **High** |
| RET 8 / returns | **Yes** | **High** |
| Body 1228 B | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Prologue / epilogue anchors:

```text
0x00754a10: 6A FF 64 A1 00 00 00 00 68 75 DA 9A 00 …
            81 EC C8 01 00 00 … 8B D9          ; EBX=style
…
success/fail share:
            81 C4 D4 01 00 00 C2 08 00         ; add esp 0x1D4; RET 8
next:       FUN_00754ee0 GlyphCache_PlacementCtor
```

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | 1 fn × 2 sites — `FUN_0073bc50` |
| Callees | GDI + string + log + `FUN_00754970` / `FUN_0076cec0` |

---

## 7. Gaps

- Product method English beyond path.
- `DAT_00d1a548` / `FUN_00754970` one-shot (unowned).
- GfxDevice cap field English.
- Runtime / bit-exact.

---

## 8. Verdict rationale

GDI CF, ABI, host layout, product path, and factory contract sealed. Residual gaps are unowned callees/globals and product plate English — not CF/ABI. **accept-with-gaps**.
