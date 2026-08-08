# Review A (reconstruction fidelity): `aa_0092e710` Character_FormatLevelRaceClassLine_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092e710` |
| **VA** | `0x0092e710` |
| **Body** | `0x0092e710`–`0x0092e8a7` inclusive (**408 B** / `0x198`); pad `CC` |
| **Canonical name** | `Character_FormatLevelRaceClassLine_Inferred` (**Inferred**); Ghidra `FUN_0092e710` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0092e710_Character_FormatLevelRaceClassLine_Inferred.md` |
| **System** | missions-progression / character display UI |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `get_function_by_address`, `get_function_callers`, `get_function_xrefs`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/output shape/sole caller sealed; product English + vtbl+0x27c name open |
| **Dual status** | **Present (R10-016)** |

---

## 1. Purpose

Character **level + race + class** display-line formatter for the character-sheet UI.

```text
outBuf := "Level " + itoa(vtbl+0x27c(character)) + " " + RaceName + " " + ClassName
return strlen(outBuf)   // or 0 if character==0 || outBuf==0
```

**ABI:** stack `character*` (cdecl); **`EBX` = out `char*`**; plain **`RET`**; returns **`int` length**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `decompile_function` `0x0092e710` ≡ raw body |
| Complete analysis | `analyze_function_complete` — callers/callees/xrefs/locals |
| Body bounds | `get_function_by_address` → `0092e710`–`0092e8a7` |
| Machine | `read_memory` entry / mid / epilogue; `"Level "` @ `0x00a2d280`; `DAT_00a2a000` |
| Call site | `read_memory` @ `0x008f97e0` — push player, LEA EBX buf, CALL, ADD ESP,4 |
| Callers | `FUN_008f97c0` only (1 xref) |
| Dualed callees | `Character_GetRaceDisplayName_Inferred` `0x00521800`; `Character_GetClassDisplayName_Inferred` `0x00521900` |
| Scaffold | raw append + annotated/clean/function refresh R10-016 |

**Not performed:** Launcher, runtime golden, bit-exact image diff, parent ledger edits, dual of `FUN_008f97c0` / vtbl owner.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| Frame + stack arg | `83 ec 0c 55 8b 6c 24 14` | **Confirmed** |
| Null gates (EBP / EBX) | `85 ed 0f 84 …` then `85 db 0f 84 …` | **Confirmed** |
| `"Level "` VA | push `0x00a2d280`; bytes `4c 65 76 65 6c 20 00` | **Confirmed** |
| Level call | `ff 90 7c 02 00 00` then `_itoa` (IAT) radix 10 | **Confirmed** |
| Space sep | `DAT_00a2a000` = `20 00` stored as uint16 at string end | **Confirmed** |
| Race/class calls | `call 00521800` / `call 00521900` + ring `007a6de0` | **Confirmed** |
| Success return strlen | epilogue scan from EBX; `sub eax,edx; pop ebp; add esp,0xc; ret` | **Confirmed** |
| Fail return 0 | `xor eax,eax; pop ebp; add esp,0xc; ret` | **Confirmed** |
| Call-site cdecl + EBX | `push eax` (player `DAT_00d1b6d8`); `lea ebx,[buf]`; `call`; `add esp,4` | **Confirmed** |
| Sole xref | `get_function_xrefs` → `008f9806` only | **Confirmed** |

---

## 4. Gaps

- Product/PDB method English for this formatter.
- Official name of nested vtbl method at `+0x27c` (role sealed as level-int getter).
- Full C++ type of character / intermediate vtbl objects.
- Class English table owned by residual `FUN_0051f940` (not this VA).
- Runtime / bit-exact / differential.

---

## 5. Verdict

**accept-with-gaps** — CF, ABI (stack char* + EBX out + strlen), product prefix `"Level "`, dualed race/class helpers, and sole character-sheet caller sealed; residual is naming + deep types + runtime only.
