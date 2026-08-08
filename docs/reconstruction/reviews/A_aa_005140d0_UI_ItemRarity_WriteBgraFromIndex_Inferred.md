# Review A (reconstruction fidelity): `aa_005140d0` UI_ItemRarity_WriteBgraFromIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005140d0` |
| **VA** | `0x005140d0` |
| **Canonical name** | `UI_ItemRarity_WriteBgraFromIndex_Inferred` (proposed; was `FUN_005140d0`) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live re-decompile + bytes) |
| **Counterpart** | `reviews/B_aa_005140d0_UI_ItemRarity_WriteBgraFromIndex_Inferred.md` |
| **System** | `inventory-transfer` |
| **Work item** | R12-016 OWN-ONLY dual seal (parent dual `0x00847240`) |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold + Named_CalleeOf mis-seed) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Leaf rarity-index → BGRA color writer.** Given a signed 16-bit rarity index (item clone-base `blob+0x4b8`), store one of six fixed palette entries (plus cyan default) into a caller-provided 4-byte buffer. Used by item tooltip / detail UI to color the rarity name line. Does **not** load the rarity string table, does **not** append text, and has **no** side effects beyond the four byte stores.

**Calling convention:** **cdecl** — stack `out*`, stack `int16 index`; bare **`RET`**; **EAX = out**.

| Slot | Role | Evidence |
|------|------|----------|
| stack arg0 | `uint8_t out[4]` BGRA | every case `MOV EAX,[ESP+4]` then `[EAX+n]` stores |
| stack arg1 | `int16` rarity index | entry `MOVSX EAX, word [ESP+8]`; parent passes `*(short*)(blob+0x4b8)` |
| EAX | `out` pointer | parent: `puVar9 = FUN_005140d0(...); (*vtbl+0x22c)(name, *puVar9)` |
| stack cleanup | caller | bare `C3` |

**Side effects:** four stores to `out` only.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005140d0_FUN_005140d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005140d0_FUN_005140d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_ItemRarity_WriteBgraFromIndex_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005140d0.cpp` |
| Function records | `docs/reconstruction/functions/aa_005140d0_FUN_005140d0.md` + named |
| Live re-decompile | Ghidra `decompile_function` @ `0x005140d0` — **≡ raw body** |
| Complete analyze | `analyze_function_complete` (callers/xrefs/callees/disasm) |
| Bytes | `read_memory` 200 B @ `0x005140d0` — code + JT + `CC` |
| Disassembly | `disassemble_function` full body (**no** `disassemble_bytes`) |
| Parent dual | `UI_ItemTooltip_AppendTypeMetaLines_Inferred` `0x00847240` (R11-029) |
| Sibling palette | `Ui_NameColorPalette_WriteArgb_Inferred` `0x00930f40` (different ABI/palette) |

**Not performed:** `disassemble_bytes` primary, Launcher, live CE, bit-exact image diff, parent ledger edits.

---

## 3. Control flow: live ≡ raw

| Stage | Match |
|---|---|
| `MOVSX` index from `[ESP+8]` | **Yes** |
| `CMP 5` / `JA` default | **Yes** |
| Jump table `@0x0051416c` ×6 | **Yes** (targets sealed by disasm + bytes) |
| case 0 gray `91 91 91 FF` | **Yes** |
| case 1 white `FF FF FF FF` | **Yes** |
| case 2 blue `FF 28 28 FF` | **Yes** |
| case 3 purple `F0 14 F0 FF` | **Yes** |
| case 4 orange `23 0A FF FF` | **Yes** |
| case 5 gold `0A 8A FF FF` | **Yes** |
| default cyan `3C E4 F0 FF` | **Yes** |
| bare `RET` each arm | **Yes** |
| no callees | **Yes** (leaf) |

### Closed form (sealed)

```text
i = (int16)index
if i < 0 || i > 5: write default cyan
else: write palette[i]
return out   // EAX
```

### Palette (AARRGGBB via LE dword load of BGRA bytes)

| Index | BGRA memory | AARRGGBB | UI role (inferred) |
|------:|-------------|----------|--------------------|
| 0 | `91 91 91 FF` | `0xFF919191` | common / gray |
| 1 | `FF FF FF FF` | `0xFFFFFFFF` | white |
| 2 | `FF 28 28 FF` | `0xFF2828FF` | blue |
| 3 | `F0 14 F0 FF` | `0xFFF014F0` | purple |
| 4 | `23 0A FF FF` | `0xFFFF0A23` | orange-red |
| 5 | `0A 8A FF FF` | `0xFFFF8A0A` | gold |
| default | `3C E4 F0 FF` | `0xFFF0E43C` | cyan fallback |

---

## 4. Role vs siblings

| Related unit | VA | Role vs this function |
|---|---|---|
| `UI_ItemTooltip_AppendTypeMetaLines_Inferred` | `0x00847240` | **Caller** — rarity name + this color when type ≠ 4 |
| `EnsureLootRarityTableLoaded_Inferred` | `0x005129b0` | Loads name table `DAT_00b04214`; **not** colors |
| `UI_ItemDetailPanel_Refresh_Inferred` | `0x0084b890` | **Caller** — detail panel rarity color |
| `Ui_NameColorPalette_WriteArgb_Inferred` | `0x00930f40` | Entity name palette; **different** ABI + colors |
| This unit | `0x005140d0` | **Only** index → BGRA write |

Parent skip note: item **type** 4 skips rarity coloring entirely — that gate is in the caller, not this leaf.

---

## 5. Confidence

| Dimension | Level |
|---|---|
| Function boundary / size (`005140d0`–`0051416a`, 0x9A + JT) | **High / Sealed** |
| cdecl stack out + int16 index, bare RET, EAX=out | **High / Sealed** |
| Six palette + default immediates | **High / Sealed** |
| BGRA memory / AARRGGBB dword | **High / Sealed** |
| Role = item rarity UI color from index | **High / Sealed** (parent `blob+0x4b8` + tooltip color path) |
| Product English rarity tier names | Tentative / Open (strings in table, not body) |
| Original PDB symbol | Open |
| Overall | **Probable / accept-with-gaps** |

---

## 6. Verdict

### **accept-with-gaps**

**Accept:** Live body matches raw; asm seals cdecl ABI and jump table; seven callers including dualed tooltip parent; palette bytes sealed; Named_CalleeOf scaffold retired; name `_Inferred` (no RTTI/PDB).

**Gaps:** product tier English labels, PDB symbol, runtime/diff/bit-exact.

**Runtime Confirmed:** **not claimed**.
