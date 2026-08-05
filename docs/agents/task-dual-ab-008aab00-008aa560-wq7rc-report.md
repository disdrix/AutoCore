# Dual A/B report — WQ7R-C OWN `aa_008aab00` + `aa_008aa560`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ7R-C  
**Scope:** VAs `0x008aab00`, `0x008aa560` only. Dual A/B + artifacts.  
**Role hint:** Mission dialog chrome helpers (WQ-007 residual partition).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs + `get_assembly_context` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008aab00` MissionDialog_ParseMarkupToRichText_Inferred | **accept-with-gaps** — markup matrix, ABI, colors, paint ordinals, body bounds sealed; product English + key helpers open |
| `aa_008aa560` MissionDialog_ClearResponseButtonSlots_Inferred | **accept-with-gaps** — EBX ABI, 8-slot clear, +0x518/+0x708, sole caller pre-rebuild sealed; product English open |

---

## VA `0x008aab00` — sealed facts

1. **Body:** `0x008aab00`–`0x008aaf58` exclusive (**1112 B** / `0x458`; pad `CC` then next).
2. **ABI:** **ECX = markup C-string**; **stack = richtext widget***; callers **`ADD ESP,4`**. Decompiler `__thiscall` label is misleading (ECX is not widget this).
3. **Semantics:** Parse mission/dialog markup and paint a richtext control:
   - Plain runs → widget **vtbl+0x250** (AppendText).
   - Color open → **vtbl+0x230**(ARGB); close → **vtbl+0x23c** (PopColor).
   - `[$pause]` → **vtbl+0x254**(0x14).
   - `[$key]…[$/key]` → Free Look / `DAT_00d1bbf5` (stride **0x34**, end **0x00d1d455**, **120** slots) / `<%s>` fallback via `FUN_007f5120` / `FUN_007f9160` / `sprintf`.
4. **Color matrix (ARGB):**

   | Tag | Color |
   |-----|-------|
   | `[$imp]` | `0xFFFF2D00` |
   | `[$npc]` | `0xFF256EC8` |
   | `[$inst]` | `0xFFC5C025` |
   | `[$loc]` | `0xFFF59623` |
   | `[$emote]` | `0xFF29B525` |

5. **Classification:** worker.
6. **Callers (6):** `FUN_008aaf60`, `FUN_008a3510` (×2), `FUN_008cc5a0`, `FUN_008cdae0`, `FUN_008dbe10`.
7. **Callees:** `FUN_007a69d0`, `__chkstk`, `FUN_007a6de0`, `FUN_007f5120`, `FUN_007f9160`, `_strnicmp`, `_stricmp`, `sprintf`.
8. **Name:** `MissionDialog_ParseMarkupToRichText_Inferred` (Ghidra `FUN_008aab00`; **Inferred**). Reject scaffold `Named_npc` / `Named_CalleeOf_*` as product.
9. **Decompile ≡ bytes** for entry frame (`mov eax,0x204c` + chkstk), epilogue (`add esp,0x204c; ret`), tag strings, color immediates.  
   Live ≡ scaffold raw (WQ7R-C re-verify append).

### Gaps

- Product/PDB English.  
- Product names for vtbl +0x230/+0x23c/+0x250/+0x254.  
- Runtime contents of key table `DAT_00d1bbf5` (static zeros).  
- Nested helpers `FUN_007f5120` / `FUN_007f9160` (WQ7R-G).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008aab00_MissionDialog_ParseMarkupToRichText_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008aab00_MissionDialog_ParseMarkupToRichText_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_008aab00_FUN_008aab00.md` |
| Annotated | `docs/reconstruction/raw/aa_008aab00_FUN_008aab00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionDialog_ParseMarkupToRichText_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008aab00.cpp` |
| Function | `docs/reconstruction/functions/aa_008aab00_FUN_008aab00.md` |
| Function named | `docs/reconstruction/functions/aa_008aab00_MissionDialog_ParseMarkupToRichText_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_008aab00.md` |

---

## VA `0x008aa560` — sealed facts

1. **Body:** `0x008aa560`–`0x008aa5a6` exclusive (**70 B** / `0x46`; pad `CC…`).
2. **ABI:** **EBX = mission dialog host***; no stack args; plain **`RET`**. Sole caller `FUN_008ac110` @ `0x008ac138`: **`MOV EBX,EDI`** then CALL.
3. **Semantics:** Fixed **8**-slot clear:
   - `dialog+0x518 + i*8` ← `(−1, −1)` TFID pairs.
   - `dialog+0x708 + i*4` widget: if non-null, host **vtbl+0xBC**(widget), then zero.
4. **Classification:** leaf (only virtual call).
5. **Callers:** `FUN_008ac110` (`Mission_i_d_npc_2d_btn_response_xml`) only — **pre-rebuild wipe** before re-creating `i_d_npc_2d_btn_response.xml` children for `i < dialog+0x510`.
6. **Callees:** none direct FUN_*; virtual **+0xBC** only.
7. **Name:** `MissionDialog_ClearResponseButtonSlots_Inferred` (Ghidra `FUN_008aa560`; **Inferred**). Scaffold `Named_CalleeOf_Mission_i_d_npc_2d_btn_response_xml_008aa560` is alias-only.
8. **Decompile ≡ bytes:** full hex sealed in raw append:

   ```
   5556578db3080700008dbb18050000bd080000008b0685c0c707ffffffff
   c74704ffffffff74118b13508bcbff92bc000000c7060000000083c708
   83c60483ed0175d15f5e5dc3
   ```

### Gaps

- Product/PDB English.  
- Product name for vtbl+0xBC.  
- Exact TFID pair semantics at +0x518 (HandleButton consumer external).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008aa560_MissionDialog_ClearResponseButtonSlots_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008aa560_MissionDialog_ClearResponseButtonSlots_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_008aa560_FUN_008aa560.md` |
| Annotated | `docs/reconstruction/raw/aa_008aa560_FUN_008aa560.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionDialog_ClearResponseButtonSlots_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008aa560.cpp` |
| Function | `docs/reconstruction/functions/aa_008aa560_FUN_008aa560.md` |
| Function named | `docs/reconstruction/functions/aa_008aa560_MissionDialog_ClearResponseButtonSlots_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_008aa560.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008aab00` | Port as **markup → richtext** painter: implement tag lexer for imp/npc/inst/loc/emote/pause/key; map ARGB colors; AppendText/SetColor/PopColor/Pause on the target control. Callers pass (string, widget). Do **not** treat as journal mutation. Keybind display can stub until `FUN_007f5120`/`FUN_007f9160` sealed. |
| `008aa560` | Port as **dialog.ClearResponseButtonSlots()**: always wipe **8** TFID pairs at +0x518 and destroy widgets at +0x708. Call from response-button rebuild path before allocate. Do **not** gate on `+0x510` inside the clear. |
| Pair with | `FUN_008ac110` (button rebuild); `FUN_008aa760` (reward chrome, different banks); `FUN_008aaf60` / mission detail panel (markup consumers); WQ7R-G `007f5120`/`007f9160` (key display). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Rejected `Named_npc` / bare caller-chain plates as product English.  
- Trio raw + annotated + reconstructed-exact + function records updated.
