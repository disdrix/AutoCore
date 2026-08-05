# Dual A/B report — WQ7R-G OWN `aa_007f5120` + `aa_007f9160`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ7R-G  
**Scope:** VAs `0x007f5120`, `0x007f9160` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**WQ:** WQ-007 residual (missions / mission-dialog call-chain UI helpers).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007f5120` Input_KeyCodeToDisplayName | **accept** — DIK/mouse/joy name LUT, DX ABI, static/snprintf buffers, empty fallback sealed |
| `aa_007f9160` ActionMap_FormatSlotBindDisplay | **accept** — lane dual-key format, RET 8 ABI, mod+key order, `+` join, GetSlot via `0x007f7240` sealed |

---

## VA `0x007f5120` — sealed facts

1. **Body:** `0x007f5120`–`0x007f5d9c` (**0xC7C** / 3196 B; worker; multi-`RET` / `ADD ESP,0x14`).
2. **ABI:** **DX** = key code (`u16` via `MOVZX EAX,DX`); no stack args; **EAX** = `const char*` display name.
3. **Semantics:** Map input code → human label for keybind UI.
   - Clears first byte of static buf `DAT_00d1f73c` then fills from tables/literals.
   - **Keyboard DIK** (std DirectInput): e.g. `1`→`ESCAPE`, `2..0xB`→`1`..`0`, letters, `SHIFT`/`CONTROL`/`SPACE`, F-keys, nav cluster, numpad, etc.
   - **Mouse:** `0xF00`→`MOUSE1` … `0xF07`→`MOUSE8`-class strings at `0x00a84ea8` family.
   - **Joystick synthetic:**  
     - `0xF000`..`0xF0FF` → `Joy_Button%03d` into `DAT_00d1f0f8` (0x104).  
     - `0xF100`..`0xF1FF` → `Joy_Axis%s%c%c` (Rot/Slider/Force + axis letter + `+`/`-`).  
     - `>0xF1FF` → `Joy_POV%d_%c` (N/E/S/W from low nibble class).
   - Unknown code `<0xF000` with empty fill → empty string `DAT_00a1419b` (`"\0"`).
4. **Buffers:** work string `DAT_00d1f73c` (~16 B region); snprintf scratch `DAT_00d1f0f8`.
5. **Callees:** `_snprintf` only.
6. **Callers (7 functions / 21 xrefs):** `FUN_007f9160`, `FUN_007f9480`, `FUN_00816170`, `FUN_008161c0`, `FUN_00816860`, `FUN_00816940`, `FUN_008aab00` (UI text expand / options / mission-journal token path).
7. **Name:** `Input_KeyCodeToDisplayName` (Ghidra `FUN_007f5120`).
8. **Decompile ≡ CF/strings**; entry bytes `0F B7 C2` seal DX formal. Single-char letter cases plant ASCII in static buf (decompiler `CONCAT22` noise).

### Gaps

- Product English for a few opaque dword string loads (numpad cluster DAT_* without Ghidra symbol).  
- Exact capacity of `DAT_00d1f73c` region beyond observed writes.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007f5120_Input_KeyCodeToDisplayName.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_007f5120_Input_KeyCodeToDisplayName.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_007f5120_FUN_007f5120.md` |
| Annotated | `docs/reconstruction/raw/aa_007f5120_FUN_007f5120.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Input_KeyCodeToDisplayName.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007f5120.cpp` |
| Function | `docs/reconstruction/functions/aa_007f5120_FUN_007f5120.md` |
| Function named | `docs/reconstruction/functions/aa_007f5120_Input_KeyCodeToDisplayName.md` |
| Scratch | `docs/reconstruction/tmp/a_007f5120.md` |

---

## VA `0x007f9160` — sealed facts

1. **Body:** `0x007f9160`–`0x007f9227` (**0xC7** / 199 B; worker; **`RET 8`**).
2. **ABI (byte-sealed):**
   - **EAX** = `ActionMap*` table base (pushed as stack arg into `FUN_007f7240`).
   - **ECX** = `char*` out buffer.
   - **EDX** = mode `0..3` (passed through to `FUN_007f7240` switch).
   - **stack0** = slot index (`u8` → AL for GetSlot).
   - **stack1** = lane: `0` = primary key/mod, nonzero = alt key/mod.
   - **AL** = success `1` / fail `0`; **`RET 8`**.
3. **Semantics:** Format one ActionMap slot’s bind as display text:
   - `slot = ActionMap_GetSlotPtr(base, mode, index)` via `FUN_007f7240` (returns pointer **at primary key field**, stride `0x34`, mode bases `+6 / +0x10A / +0x242 / +0x1AA2`).
   - Null slot or null out → fail (`AL=0`).
   - Clear `*out = 0`.
   - Lane 0: `key = *(u16*)slot`, `mod = *(u16*)(slot+0x2A)`.  
     Lane ≠0: `key = *(u16*)(slot+2)`, `mod = *(u16*)(slot+0x2C)`.  
     (Matches `ActionMap_TrySetSlotBind` key0/mod0/key1/mod1 relative to primary-key pointer.)
   - Both key and mod zero → fail.
   - **Display order:** if both set → `name(mod) + "+" + name(key)` (e.g. `SHIFT+A`); if only key → `name(key)`; if only mod → formats mod then `+` then empty key name (edge).
   - Separator: `DAT_00a2e620` = `u16` `'+'\0'` (`0x002B`).
   - Names via **`FUN_007f5120`** (EDX=code).
4. **Callees:** `FUN_007f7240` (GetSlotPtr — not owned), `FUN_007f5120` (owned peer).
5. **Callers (5):** `UI_BuildItemTooltipStats`, `FUN_00825380` (Primary/Secondary Attack HUD), `FUN_00891480`, `FUN_008aab00` (`[$…]` token expand — mission journal / UI strings), `FUN_008a81a0` (interact prompt “Press \<bind\> to talk/…”, tip ids `0xC` / `0x1E`).
6. **Name:** `ActionMap_FormatSlotBindDisplay` (Ghidra `FUN_007f9160`).
7. **Decompile lost** EAX base / EDX mode / RET 8 / which register feeds each `FUN_007f5120`; **bytes seal** all of the above. Decompiler `param_3` lane is correct; `in_EAX` tip phantom is wrong — tip is stack0.

### Gaps

- Call-site convention for which global/ActionMap* is loaded into EAX (consumer residual).  
- Mode product English (same Tentative set as `ActionMap_TrySetSlotBind`).  
- Live UI string differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007f9160_ActionMap_FormatSlotBindDisplay.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_007f9160_ActionMap_FormatSlotBindDisplay.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_007f9160_FUN_007f9160.md` |
| Annotated | `docs/reconstruction/raw/aa_007f9160_FUN_007f9160.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ActionMap_FormatSlotBindDisplay.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007f9160.cpp` |
| Function | `docs/reconstruction/functions/aa_007f9160_FUN_007f9160.md` |
| Function named | `docs/reconstruction/functions/aa_007f9160_ActionMap_FormatSlotBindDisplay.md` |
| Scratch | `docs/reconstruction/tmp/a_007f9160.md` |

---

## Relationship (trio)

```
ActionMap_FormatSlotBindDisplay (0x007f9160)
  → ActionMap_GetSlotPtr        (0x007f7240)   [not owned]
  → Input_KeyCodeToDisplayName  (0x007f5120)   ×1 or ×2
```

Both sit on the **client keybind display** path used by mission-journal string expansion (`FUN_008aab00`), interact prompts, and options/HUD — residual callees under WQ-007 mission UI, not server mission logic.

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `007f5120` | Client-only label LUT. Preserve DIK indices, mouse `0xF00+`, joy ranges, empty fallback. Do not invent server key names. |
| `007f9160` | Client ActionMap display. Preserve **mod+key** order and `+` join; lane 0 vs alt offsets `0/0x2A` vs `+2/+0x2C` relative to GetSlot primary-key pointer; `RET 8`; fail when both codes zero. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers / body bounds).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Trio: raw (append) + annotated + clean named (+ twin).
