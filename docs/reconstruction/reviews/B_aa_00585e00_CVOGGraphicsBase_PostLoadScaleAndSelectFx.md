# Review B (skeptical / adversarial): `aa_00585e00` CVOGGraphicsBase_PostLoadScaleAndSelectFx

| Field | Value |
|---|---|
| **Stable ID** | `aa_00585e00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-N) |
| **Counterpart** | `reviews/A_aa_00585e00_CVOGGraphicsBase_PostLoadScaleAndSelectFx.md` |
| **Scratch** | `tmp/a_00585e00.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + analyze/xrefs. **No** `disassemble_bytes`. Own VA `0x00585e00` only.

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / free function | **Falsified** — `MOV ESI,ECX`; `RET 4` |
| 2 | void return | **Falsified** — early `FLD` zero; exit `FLD` scale slot |
| 3 | Always runs FX | **Falsified** — `skipSideFx!=0` skips block; caller passes `0` |
| 4 | Distance gate is 100 / infinity | **Falsified** — `DAT_00a0f524` bytes = **50.0f** |
| 5 | LogicUI type is 0x20 (explored) | **Falsified** — immediate `0x1F` store |
| 6 | `g_flLevelUpUiBase` is level-up UI scale | **Overstated name** — value **2.0** cancels; role is reciprocal helper only |
| 7 | Product method name plate-sealed | **Overstated** — only caller class plate; method English Probable |
| 8 | Live diverges from 2026-07-23 raw | **Falsified** — identical CF |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 4 + ST0 | **High** | ABI break |
| Reciprocal scale CF | **High** | wrong world scale |
| 50.0 near gate + FX callee | **High** | wrong select VFX |
| LogicUI 0x1F + 3.5 | **High** | wrong UI notify |
| Method English | **Probable** | rename if plate found |
| Runtime | **Open** | matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if this+8 && FUN_005130e0(1):
    scale = 2.0/(s*2.0)
    vtbl+0xB8(scale); Y+=scale; transform; vtbl+0x10(3,&xyz)
    if !skipSideFx: optional PlayPickupSpecialFX; LogicUI 0x1F
    ST0 = scale
  else ST0 = 0

bytes:
  55 8B EC 83 E4 F0 81 EC 88 01 00 00 56 8B F1 …
  F3 0F 10 05 74 0E A1 00   ; 2.0
  … C2 04 00
constants: 50.0 @ a0f524; 3.5 @ 9da8a4; 0.0 @ a0f518
```

**No conflict** on owned ABI/CF/constants. Method English remains Probable.

---

## 4. Surviving contract for AutoCore

```
// CVOGGraphicsBase_PostLoadScaleAndSelectFx @ 0x00585e00
// ECX=this; stack skipSideFx; RET 4; ST0 scale (0 if gated out)

// After InitializeGraphics when (flags+0x188)&1:
//   scale = 1.0f / meshScale;
//   apply host scale + graphics mode-3 pose;
//   if !skip: near50 pickup FX + LogicUI type 0x1F (payload 3.5f)
```

Port rules:

- Do **not** hardcode level-up UI semantics from the misnamed `g_flLevelUpUiBase_Inferred` — use **2.0 cancel** or direct `1/s`.
- Keep **50.0** near gate when calling `Object_PlayPickupSpecialFX`.
- LogicUI type **0x1F** and float **3.5** must match client UI handlers.
- `skipSideFx` must remain a real gate (caller uses 0 today).

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/constants; product method English residual → **accept-with-gaps**.
