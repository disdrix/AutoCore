# Function record: UI_FormatObjectDifficultyTier_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e4430` |
| **Canonical name** | `UI_FormatObjectDifficultyTier_Inferred` |
| **Ghidra name** | `FUN_008e4430` |
| **Address** | `0x008e4430`–`0x008e4726` (758 B / `0x2F6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client mission / target UI difficulty |
| **Wave** | W29-J OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Given a **target object** (EAX) and the global character context `DAT_00d1b6d8`:

1. Compare player resource/level (`FUN_0052ada0` on clone `+0x4ac`) to required level at clone `+0x4b0`.
2. If player **&lt; required** → tier **"Impossible"**; pack special color via `FUN_00973590` (scale ×255 inline).
3. Else compute difficulty score `FUN_0052b080(character, object)` and map to tier label + palette:
   - **Very Hard** / **Hard** / **Moderate** / **Easy** / **Trivial** (two Trivial palettes split at 0).
4. Pack palette float4 via `Color_PackFloat4_Scale255` (`FUN_00973820`) into local u8×4.
5. If ESI ≠ null: localize tier string (`FUN_007a6de0`) and `sprintf(ESI, "%s: %d", localized, requiredLevel)`.
6. Write packed color to `*out` (stack arg).

## ABI

| Item | Value |
|---|---|
| EAX | target `object*` (entry `mov ebx, eax`) |
| ESI | optional `char* textBuf` (null → skip sprintf) |
| Stack | `uint32_t *outPackedColor` |
| ECX (nested) | dest for color pack (local u8×4; decompiler often drops) |
| Epilogue | plain **`ret`** (`C3`); cleans `sub esp, 0x18` frame |
| `*out` | packed 4-byte color (early: `0xFFFFFFFF`; success: tier pack) |

Decompiler surface `void FUN_008e4430(undefined4 *param_1)` + `in_EAX` / `unaff_ESI` is incomplete but directionally right once register args are restored.

## Score → tier (float thresholds, `read_memory`)

Score comes from non-OWN `FUN_0052b080` (at-level base **100.0f**, decreases when overleveled). This unit only consumes the float:

| Condition | Label | Palette globals (float4 base) |
|---|---|---|
| playerLevel &lt; required (`+0x4b0`) | `"Impossible"` | `DAT_00d1b484`…`+0xc` × `255.0f` via `FUN_00973590` |
| score &gt; **90.0f** (`DAT_00aaa954`) | `"Very Hard"` | `DAT_00d1b474`… |
| score &gt; **70.0f** (`DAT_00aaa950`) | `"Hard"` | `DAT_00d1b464`… |
| score &gt; **50.0f** (`DAT_00a0f524`) | `"Moderate"` | `DAT_00d1b454`… |
| score &gt; **30.0f** (`DAT_00a0f694`) | `"Easy"` | `DAT_00d1b444`… |
| score &gt; **0** (`g_flZero`) | `"Trivial"` | `DAT_00d1b434`… |
| else | `"Trivial"` | `DAT_00d1b424`… |

String literals (rdata): `Trivial` `Easy` `Moderate` `Hard` `Very Hard` `Impossible`; format `"%s: %d"` @ `0x00a3ae44`.

## Call graph

| | |
|---|---|
| Callees | `FUN_0052ada0`, `FUN_0052b080`, `FUN_007a69d0`, `FUN_007a6de0`, `FUN_00973590`, `FUN_00973820` (×5 tier paths), `sprintf` |
| Callers | `FUN_008b3670`, `FUN_008e47d0`, `FUN_008e5e00` (5 call sites; mission/UI refresh family) |

## Decompiler defects (bytes supersede)

- Final `*param_1 = 0xffffffff` is **wrong for the success path** — epilogue stores **packed color** from local into `*out`.
- `in_EAX` / `unaff_ESI` are real register parameters (object / text buffer).
- Nested `FUN_00973820` omits ECX dest (local color slot).

## Gaps

1. Product/PDB symbol; exact UI widget English.
2. Semantic of clone `+0x4ac` resource key (level vs discipline) — uses sealed `FUN_0052ada0` map.
3. Runtime palette values in `DAT_00d1b424`… (BSS zero in static image).
4. Full dual of `FUN_0052b080` score formula (context only; sibling).
5. Runtime / bit-exact.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008e4430_FUN_008e4430.md` |
| Annotated | `docs/reconstruction/raw/aa_008e4430_FUN_008e4430.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_FormatObjectDifficultyTier_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008e4430.cpp` |
| Ghidra record | `docs/reconstruction/functions/aa_008e4430_FUN_008e4430.md` |
| A | `docs/reconstruction/reviews/A_aa_008e4430_UI_FormatObjectDifficultyTier_Inferred.md` |
| B | `docs/reconstruction/reviews/B_aa_008e4430_UI_FormatObjectDifficultyTier_Inferred.md` |
| Report | `docs/agents/task-dual-ab-005e1fc0-008e4430-w29j-report.md` |
