# Dual A/B report — WQ9E-C OWN-ONLY (`aa_00930f40`, `aa_0092d580`)

**Date:** 2026-08-04  
**Agent:** WQ9E-C OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00930f40`, `0x0092d580`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth-2 residual dual seal — name-color palette + level-band helpers of dualed `Ui_ResolveEntityNameColor_Inferred`.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + callers/xrefs/callees + function meta. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth2_partition_map.md` → **WQ9E-C**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00930f40` Ui_NameColorPalette_WriteArgb_Inferred | **accept** — ECX mode / EAX out / five AARRGGBB / JT leaf sealed |
| `aa_0092d580` Ui_NameColorLevelBand_CopyFloat4_Inferred | **accept** — ECX host / EDX levelDiff / eight band offsets / 16 B copy sealed; table float contents residual |

Path A (fidelity): both **accept** as above.  
Path B (adversarial): no CF rejects; not combat accuracy; not full name resolver; product symbols remain `_Inferred`.

---

## Sealed facts — `0x00930f40`

1. **Body:** Ghidra `0x00930f40`–`0x00930f9c` (**92 B** exclusive). Jump table **5×dword** @ `0x00930fa0` (modes −1..3 via `mode+1`). `CC` pad after table.

2. **ABI (custom register):**  
   - **ECX** = signed **mode**  
   - **EAX** = **out** `uint8_t[4]` (B,G,R,A)  
   - **bare `ret`** (`C3`)  
   - **EAX preserved** as out (callers `mov r32, [eax]`)  
   - Decompiler `void` / `__fastcall(param_1)` is incomplete but CF matches

3. **Algorithm:** `idx = mode + 1`; if `idx > 4` → default beige; else jump-table case writes four channel bytes.

4. **Palette (AARRGGBB):**  

   | mode | Value | Color |
   |---|---|---|
   | 0 | `0xFFC41616` | red |
   | 1 / default | `0xFFDCE0C8` | beige |
   | 2 | `0xFF66D3EA` | cyan |
   | 3 | `0xFF14D314` | green |
   | −1 | `0xFFFFFFFF` | white |

5. **Callers:** sole `Ui_ResolveEntityNameColor_Inferred` (`0x00930fc0`) — **6** sites. Live sites use modes **0, 1, 2, 2|3** (white implemented, unused by current xrefs).

6. **Role:** Fixed **UI name-color palette** writer. Not level-band, not entity relationship logic.

7. **Name:** `Ui_NameColorPalette_WriteArgb_Inferred` — role **High**; product English **Inferred**. Supersedes scaffold `FUN_00930f40`.

8. **Decompile ≡ raw CF** (live 2026-08-04 ≡ raw 2026-07-23) + bytes seal.

### Gaps — `00930f40`

1. Product/PDB symbol.  
2. Product English for mode IDs (hostile/neutral/friend, etc.).  
3. Why white mode exists with no current caller.  
4. Runtime / bit-exact open.

---

## Sealed facts — `0x0092d580`

1. **Body:** `0x0092d580`–`0x0092d5fb` (**123 B** exclusive). Leaf; `CC` after `ret`.

2. **ABI:**  
   - **ECX** = **host** with band tables  
   - **EDX** = signed **levelDiff**  
   - **EAX** = **out** 16 B (float4 / 4 dwords)  
   - bare **`ret`**; EAX = out

3. **Algorithm:** signed threshold ladder selects `host + offset`, then **four dword** copy to out.

4. **Band map (stride 0x10):**  

   | levelDiff | offset |
   |---|---|
   | ≤ −5 | `+0xBE4` |
   | −4 .. −3 | `+0xBF4` |
   | −2 .. −1 | `+0xC04` |
   | 0 | `+0xC14` |
   | 1 .. 2 | `+0xC24` |
   | 3 .. 4 | `+0xC34` |
   | 5 .. 6 | `+0xC44` |
   | ≥ 7 | `+0xC54` |

5. **Parent consumer (`0x00930fc0` @ `0x009312e2`):**  
   `levelDiff = baseLevel(def+0x4FA) - local.vtbl+0x27C() + entity.vtbl+0x27C()`;  
   floats × **`DAT_00aaa6f8` = 255.0f** → pack A=`0xFF`.

6. **Other callers:** `Client_NpcDialog_PrepareResponseOpcode` (mission dialog title color via `vtbl+0x158`), `FUN_00829b20`, `FUN_0082a050` (mission journal UI family).

7. **Name:** `Ui_NameColorLevelBand_CopyFloat4_Inferred` — role **High**; product English **Inferred**.  
   Supersedes scaffold `FUN_0092d580` and alias `Named_CalleeOf_Client_NpcDialog_PrepareResponseOpcode_0092d580`.

8. **Decompile ≡ raw CF** (live re-verify 2026-08-04) + bytes seal.

### Gaps — `0092d580`

1. Product/PDB symbol + host class RTTI.  
2. Actual float RGB values in each band (need initialized host dump).  
3. Fourth float component English (alpha vs pad).  
4. Runtime / bit-exact open.

---

## Files

### `aa_00930f40`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00930f40_Ui_NameColorPalette_WriteArgb_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00930f40_Ui_NameColorPalette_WriteArgb_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00930f40_Ui_NameColorPalette_WriteArgb_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00930f40_FUN_00930f40.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Ui_NameColorPalette_WriteArgb_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00930f40.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00930f40_FUN_00930f40.md` |
| Annotated | `docs/reconstruction/raw/aa_00930f40_FUN_00930f40.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_00930f40.md` |

### `aa_0092d580`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0092d580_Ui_NameColorLevelBand_CopyFloat4_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0092d580_Ui_NameColorLevelBand_CopyFloat4_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0092d580_Ui_NameColorLevelBand_CopyFloat4_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0092d580_FUN_0092d580.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Ui_NameColorLevelBand_CopyFloat4_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0092d580.cpp` |
| Prior alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_NpcDialog_PrepareResponseOpcode_0092d580.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0092d580_FUN_0092d580.md` |
| Annotated | `docs/reconstruction/raw/aa_0092d580_FUN_0092d580.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_0092d580.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00930f40-0092d580-wq9ec-report.md` |

---

## AutoCore impact

### `00930f40`

- Port nameplate **default palette** as five fixed AARRGGBB constants, not dynamic theme load.  
- Call ABI is **ECX=mode, EAX=out buffer** (not stack formals).  
- Parent resolver may pass modes other than 0 — do not hardcode red-only.

### `0092d580`

- Port **level-relative name colors** as 8-slot float table lookup by signed levelDiff, then ×255 pack.  
- Reuse same band helper for mission dialog title tinting if matching retail UI.  
- Do not confuse with combat accuracy / skill level-band math elsewhere in skills map.

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

Also update dualed parent `Ui_ResolveEntityNameColor_Inferred` notes: palette/band duals closed (gap item 5 from WQ9D-J).

**Terminal:** false (runtime open; dual seal complete for OWN pair).
