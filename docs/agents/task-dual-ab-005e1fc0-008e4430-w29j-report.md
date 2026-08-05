# Dual A/B report — W29-J OWN-ONLY (`0x005e1fc0`, `0x008e4430`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-J  
**Scope:** OWN ONLY VAs `0x005e1fc0`, `0x008e4430`. Dual A/B + artifacts.  
**Partition:** wave29  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ `get_function_by_address` / callers / callees / xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_005e1fc0` Object_FwriteColorFields_Inferred | **accept-with-gaps** — thiscall/ret4 + serialize CF + offsets sealed; class English open |
| `aa_008e4430` UI_FormatObjectDifficultyTier_Inferred | **accept-with-gaps** — register ABI + tier ladder/strings/thresholds + out-color sealed; palette runtime open |

---

## `aa_005e1fc0` — Object_FwriteColorFields_Inferred

### Sealed facts

1. **Body:** `0x005e1fc0`–`0x005e203c` exclusive (**124** B / `0x7C`). Final **`C2 04 00`** (`ret 4`); following `CC` pad.

2. **ABI:** **`__thiscall`**; ECX = object; stack `FILE *stream`; void; **`ret 4`**.

3. **Algorithm (bytes — authority):**
   ```
   base = thunk_FUN_005a61d0(this, stream)
   fwrite(this+0x170, 4, 1, stream)
   pack255(localA, this+0x174)   // FUN_00973820 ECX=dest, stack=src
   pack255(localB, this+0x184)
   fwrite(localA, 4, 1, stream)
   fwrite(localB, 4, 1, stream)
   ```

4. **Callees:** `thunk_FUN_005a61d0` (`0x005e6b50` → `FUN_005a61d0`), `fwrite` (IAT `0x009c64bc`), `FUN_00973820` ×2.

5. **Callers:** **no code xrefs**; **DATA** vtable slot `@ 0x009dc8e8` → `0x005e1fc0`.

6. **Name:** structural `Object_FwriteColorFields_Inferred`. Prior “color field write helper” shorthand is **narrow/wrong direction** (object → stream).

7. **Decompiler:** live ≡ raw 2026-07-23 CF; **rejected** typing of pack locals as `FILE*` and incomplete `FUN_00973820` surface (missing ECX dest).

8. **Twin (not OWN):** `FUN_005e2040` deserializes `+0x170` + two colors into `+0x174`/`+0x184` via `FUN_009733d0`.

### Gaps

1. Product/PDB class + method; vtable owner.  
2. Semantic of raw dword `+0x170`.  
3. Color channel English for the two float4s.  
4. Runtime / bit-exact stream golden — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005e1fc0_Object_FwriteColorFields_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005e1fc0_Object_FwriteColorFields_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005e1fc0_Object_FwriteColorFields_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005e1fc0_Object_FwriteColorFields_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_005e1fc0_Object_FwriteColorFields_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005e1fc0_FUN_005e1fc0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_FwriteColorFields_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005e1fc0.cpp` |
| Raw | `docs/reconstruction/raw/aa_005e1fc0_FUN_005e1fc0.md` |
| Annotated | `docs/reconstruction/raw/aa_005e1fc0_FUN_005e1fc0.annotated.md` |

---

## `aa_008e4430` — UI_FormatObjectDifficultyTier_Inferred

### Sealed facts

1. **Body:** `0x008e4430`–`0x008e4726` exclusive (**758** B / `0x2F6`). Final plain **`C3`** (`ret`).

2. **ABI:** **EAX** = target object; **ESI** = optional `char*` text buffer (null skips sprintf); stack **`uint32_t *outPackedColor`**; void; color via `*out`.

3. **Algorithm (authority = decompile CF + epilogue bytes):**
   ```
   if !target || !DAT_00d1b6d8: *out = 0xFFFFFFFF; return
   clone = *(*(target+0xa8)+0x3c)
   required = clone+0x4b0
   player   = FUN_0052ada0(clone+0x4ac)      // resource/level map
   score    = FUN_0052b080(DAT_00d1b6d8, target)
   locale   = FUN_007a69d0()
   if player < required:
     pack Impossible palette via FUN_00973590(…*255…); label = "Impossible"
   else pick tier by score vs {90,70,50,30,0}; pack via FUN_00973820
   if ESI: sprintf(ESI, "%s: %d", Localize(label), required)
   *out = packedColor
   ```

4. **Thresholds (`read_memory`):**

   | Cut | VA | Value | Label above cut |
   |-----|-----|-------|-----------------|
   | | `0x00aaa954` | **90.0f** | Very Hard |
   | | `0x00aaa950` | **70.0f** | Hard |
   | | `0x00a0f524` | **50.0f** | Moderate |
   | | `0x00a0f694` | **30.0f** | Easy |
   | | `g_flZero` | **0.0f** | Trivial (two palettes) |

5. **Callees:** `FUN_0052ada0`, `FUN_0052b080`, `FUN_007a69d0`, `FUN_007a6de0`, `FUN_00973590`, `FUN_00973820`, `sprintf`.

6. **Callers (3 fns / 5 sites):** `FUN_008b3670`, `FUN_008e47d0`, `FUN_008e5e00` — mission/UI refresh family.

7. **Name:** structural `UI_FormatObjectDifficultyTier_Inferred`. Prior long Named_CalleeOf_* alias is **narrow**.

8. **Decompiler:** live ≡ raw tier CF; **rejected** always-`*out=0xFFFFFFFF` success tail; register params restored from entry + call sites.

### Gaps

1. Product/PDB UI symbol.  
2. Runtime palette RGB in `DAT_00d1b424`… (BSS zero in static image).  
3. Full dual of score helper `FUN_0052b080` (context only).  
4. Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_008e4430_UI_FormatObjectDifficultyTier_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_008e4430_UI_FormatObjectDifficultyTier_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_008e4430_UI_FormatObjectDifficultyTier_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_008e4430_UI_FormatObjectDifficultyTier_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_008e4430_UI_FormatObjectDifficultyTier_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_008e4430_FUN_008e4430.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_FormatObjectDifficultyTier_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_008e4430.cpp` |
| Raw | `docs/reconstruction/raw/aa_008e4430_FUN_008e4430.md` |
| Annotated | `docs/reconstruction/raw/aa_008e4430_FUN_008e4430.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Object_FwriteColorFields_Inferred (`0x005e1fc0`)

- Port as **stream serialize extension**, not an object color mutator.
- Preserve **thiscall + ret 4** and base-serialize call first.
- Stream layout after base: `u32 @+0x170`, then **two packed u8×4** (from float4 `@+0x174` / `@+0x184` via ×255 pack).
- Do **not** copy Ghidra’s fwrite-of-FILE* locals.
- Pair with deserialize twin `FUN_005e2040` when implementing load path (owned elsewhere).

### UI_FormatObjectDifficultyTier_Inferred (`0x008e4430`)

- Port as **UI tier mapper**: under-level → Impossible; else score ladder → Trivial…Very Hard.
- Preserve **EAX/ESI/stack-out** ABI; optional text buffer.
- Thresholds fixed: **90 / 70 / 50 / 30 / 0**.
- `*out` is **packed color**, not always white/`-1`.
- Do not re-implement score math here — call shared `FUN_0052b080` / resource map helpers.
- Impossible path uses direct `FUN_00973590`; other tiers use `FUN_00973820`.

### Family context (owned elsewhere)

| Helper | VA | Role |
|--------|-----|------|
| Color_PackFloat4_Scale255_Inferred | `0x00973820` | W28-E — pack float4×255 |
| FUN_00973590 | `0x00973590` | nested clamp pack |
| FUN_009733d0 | `0x009733d0` | unpack u8→float (deserialize twin) |
| CVOGCharacter_GetResourceBalanceByType | `0x0052ada0` | prior dual / missions notes |
| FUN_0052b080 | `0x0052b080` | difficulty score (not OWN) |
| FUN_005e2040 | `0x005e2040` | deserialize color fields twin |

---

## Notes

- No Launcher. No parent ledger / partition map / COVERAGE_LEDGER edits.
- OWN VAs only; did not dual callees/callers beyond peek for ABI.
- Scaffold raw decompile bodies preserved; re-verify **appended** only.
- **Critical:** for both units, bytes supersede decompiler on ABI surfaces (ret4 / register args / `*out` color).
