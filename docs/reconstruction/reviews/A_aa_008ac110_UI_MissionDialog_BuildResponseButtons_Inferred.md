# Review A (reconstruction fidelity): `aa_008ac110` UI_MissionDialog_BuildResponseButtons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac110` |
| **VA** | `0x008ac110`–`0x008ac318` exclusive |
| **Body size** | **520** B (`0x208`) |
| **Canonical name** | `UI_MissionDialog_BuildResponseButtons_Inferred` |
| **Ghidra symbol** | `FUN_008ac110` |
| **Review date** | `2026-08-04` (WQ7R-B OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_008ac110_UI_MissionDialog_BuildResponseButtons_Inferred.md` |
| **System** | client UI / mission dialog (NPC 2d response strip) |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `get_function_by_address`, `read_memory`, callers (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

On mission dialog `this` (**EDI**), if chrome gate `+0x4C0` is live: run pre-layout helper `FUN_008aa560`, ensure column count `+0x640 ≥ 1`, then for each response index `0 .. count-1` (`count` at `+0x510`) allocate a `0x4CC` NDUI child, construct via `FUN_0079c860`, attach (`dialog vtbl+0xA8`), load **`i_d_npc_2d_btn_response.xml`**, assign control id **`0x9C46 + i`**, size/position on a column-major grid with optional last-alone base and mode offsets `{0,3}`, store pointer in slot array at **`+0x708`**.

UI-only construct; no mission-state mutation, no packet send.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008ac110_FUN_008ac110.md` (+ WQ7R-B append) |
| Annotated | `docs/reconstruction/raw/aa_008ac110_FUN_008ac110.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_MissionDialog_BuildResponseButtons_Inferred.cpp` |
| Scaffold | `reconstructed-exact/FUN_008ac110.cpp` |
| Function record | `docs/reconstruction/functions/aa_008ac110_UI_MissionDialog_BuildResponseButtons_Inferred.md` |
| Live decompile | CF ≡ raw for gate / loop / XML / scale |
| Live body bytes | entry gate, idiv grid, last-alone flag, pos bases, epilogue via `read_memory` |
| Constants | `DAT_00aaa67c` / `DAT_00aaa678` via `read_memory` |
| Parent context | sealed peer notes in `A_aa_008ad240_Client_BuildNpcMissionDialogWidgets` call `FUN_008ac110` after item/close chrome |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte seal (key sites)

### Prologue + gate

```
64 a1 00 00 00 00 6a ff 68 f9 63 9b 00 ...  ; SEH LAB_009b63f9
83 ec 20
83 bf c0 04 00 00 00                         ; cmp [edi+0x4C0], 0
0f 84 d5 01 00 00                             ; jz epilogue
53 8b df e8 ...                               ; push ebx; call FUN_008aa560 (EDI this)
83 bf 40 06 00 00 00                         ; cmp cols [edi+0x640]
7f 0a
c7 87 40 06 00 00 01 00 00 00                 ; cols = 1
33 db                                         ; index = 0
39 9f 10 05 00 00                             ; cmp count [edi+0x510]
```

### Grid + last-alone flag

```
8d af 08 07 00 00        ; lea ebp, [edi+0x708]  slot*
8b 8f 40 06 00 00        ; ecx = cols
8b c3 99 f7 f9           ; idiv → row=eax, edx=rem
0f af c8                 ; cols * row
89 44 24 14              ; [esp+0x14] = row
...
2b f1                    ; col = index - cols*row
...
; flag [esp+0x0F] = 1 iff last index and col==0; else 0
8a 44 24 0f              ; later reload flag (not ptr>>24)
```

### XML + id + scale

```
68 80 ac a4 00 ff 50 28  ; push "i_d_npc_2d_btn_response.xml"; vtbl+0x28
8d 83 46 9c 00 00        ; lea eax, [ebx+0x9C46]; vtbl+0x74
f3 0f 59 05 7c a6 aa 00  ; mulss DAT_00aaa67c (0.000625)
f3 0f 59 05 78 a6 aa 00  ; mulss DAT_00aaa678 (~1/1200)
```

### Y uses saved row (not EBP)

```
8b 87 d8 05 00 00        ; y_stride [edi+0x5D8]
0f af 44 24 14           ; * [esp+0x14] row
03 c2                    ; + y_base
8b 97 48 06 00 00        ; mode [edi+0x648]
85 d2 74 05 83 fa 03 75 0c
03 8f bc 05 00 00        ; +x off
03 87 c0 05 00 00        ; +y off
```

### Epilogue

```
83 c3 01 83 c5 04 3b 9f 10 05 00 00 0f 8c ...
5e 5d 5b ... 83 c4 2c c3
```

### Constants (`read_memory`)

| Addr | Bytes (LE) | f32 | Meaning |
|---|---|---|---|
| `0x00aaa67c` | `0A D7 23 3A` | **0.000625** | 1/1600 X design scale |
| `0x00aaa678` | `0E 74 5A 3A` | **≈0.000833333** | 1/1200 Y design scale |
| `0x00d1e818` / `1c` | runtime | viewport W/H | static image zero |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw gate/loop/XML | **pass** |
| Body 520 B exclusive end `0x008ac318` | **pass** |
| EDI this (no ECX mov in prologue) | **pass** |
| Gate `+0x4C0`, cols `+0x640`, count `+0x510`, slots `+0x708` | **pass** |
| Alloc `0x4CC` + `FUN_0079c860` | **pass** |
| XML string + id base `0x9C46` | **pass** |
| Last-alone flag from stack byte (not `>>24`) | **bytes win** over decompiler |
| Y = stride × **row** at `[esp+0x14]` | **bytes win** (`unaff_EBP` in decomp is slot*) |
| Mode `{0,3}` extra offset | **pass** |
| Scale 1600×1200 design pair | **pass** |
| Product method spelling | **gap** |
| Runtime / differential | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = response-button strip builder | **High** | XML + id family + BuildNpcMissionDialogWidgets parent |
| Grid layout math | **High** | idiv + row stack slot sealed |
| Last-alone origin select | **High** | flag bytes; product *why* open |
| Design scale 1600×1200 | **High** | constants exact |
| EDI custom this | **High** | all `[edi+…]` loads; callers keep EDI |
| Child vtbl semantic names | **Med** | slots 0x08/0x28/0x74/0x118 by usage |
| Product C++ name | **Inferred** | |

---

## 6. Gaps

1. Product English / exact method plate.  
2. Full dual of `FUN_008aa560` / `FUN_0079c860` (not OWN this slice).  
3. Why last-alone (`count-1 && col==0`) switches base origin.  
4. Exact meaning of mode dword `+0x648` beyond `{0,3}` offset gate (shared with list path `+0x648`).  
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
