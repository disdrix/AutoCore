# Review A (reconstruction fidelity): `aa_005792d0` Mission_FormatDialogTokenValue_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005792d0` |
| **VA** | `0x005792d0` |
| **Body** | `0x005792d0`–`0x00579584` inclusive (**693 B** / `0x2B5`); align `8D 49 00`; jump table `0x00579588` (7×dword); pad `CC` |
| **Canonical name** | `Mission_FormatDialogTokenValue_Inferred` (**Inferred**); Ghidra `FUN_005792d0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005792d0_Mission_FormatDialogTokenValue_Inferred.md` |
| **System** | missions-progression / mission dialog token format |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `get_function_by_address`, `get_function_callers`, `get_function_xrefs`, `read_memory`, `list_strings` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/case table/string/sole caller/dualed race+class helpers sealed; product English + vtbl names + case-6 intent open |
| **Dual status** | **Present (R10-014)** |

---

## 1. Purpose

Mission-dialog **per-token value formatter**: given a token descriptor type byte (0..6), write the resolved display string into a caller buffer and return success/fail.

```text
switch (tokenDesc->type):
  0 float/var  → sprintf(out, fmt, double)
  1 object name → vtbl+0x160 strcpy
  2 class(object) → GetClassDisplayName + ring + strcpy
  3 race(object)  → GetRaceDisplayName + ring + strcpy
  4 faction       → race of character OR "!Non-Character Faction not implemented yet!"
  5 display name  → vtbl+0x160 of character OR entity string @ [0x2a]+0x40
  6 class(char)   → GetClassDisplayName strcpy then return 0
return AL ∈ {0,1}
```

**ABI:** `__thiscall` ECX=context*; 5 stack dwords; **`RET 0x14`**; returns **uint8** in **AL**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `decompile_function` `0x005792d0` ≡ raw body CF |
| Complete analysis | `analyze_function_complete` — callers/callees/xrefs/locals |
| Body bounds | `get_function_by_address` → `005792d0`–`00579584` |
| Machine | `read_memory` entry / case0 / case2 / case4 / case6 / epilogue / jump table |
| String | `list_strings` + `read_memory` @ `0x009d4104` |
| Call site | `read_memory` @ `0x0057a050`–`0x0057a090` in `FUN_00579fb0` |
| Callers | `FUN_00579fb0` only (1 xref) |
| Dualed callees | `Character_GetRaceDisplayName_Inferred` `0x00521800`; `Character_GetClassDisplayName_Inferred` `0x00521900` |
| Scaffold | raw append + annotated/clean/function refresh R10-014 |

**Not performed:** Launcher, runtime golden, bit-exact image diff, parent ledger edits, dual of `FUN_00579fb0` / `FUN_00578f80`.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| Prolog thiscall | `53 56 57 8B F9` (push EBX/ESI/EDI; EDI←ECX) | **Confirmed** |
| Type switch 0..6 | `0F BE 03 83 F8 06 0F 87 … FF 24 85 88 95 57 00` | **Confirmed** |
| Jump table 7 entries | dwords @ `0x00579588` → `f3/73/ab/e6/1b/96/26` of `0x00579xxx` | **Confirmed** |
| Stack cleanup | epilogues `C2 14 00` (`RET 0x14`) | **Confirmed** |
| Success return | `B0 01 5B C2 14 00` (case 0/1/2/3/4/5 arms) | **Confirmed** |
| Fail return | `32 C0 5B C2 14 00` | **Confirmed** |
| Case 0 TFID path | `LEA EAX,[EDI+0x30]`; compare vs `ESI+0x160`; `CVOGMap_LookupVariable`; `sprintf` IAT | **Confirmed** |
| Case 2/3 dualed helpers | `CALL 00521900` / `CALL 00521800` + `007a6de0` + strcpy to `[ESP+0x10]` | **Confirmed** |
| Case 4 stub string | push/path to `0x009d4104` bytes `21 4e 6f 6e-…` | **Confirmed** |
| Case 6 write-then-0 | strcpy then `5F 5E 32 C0 5B C2 14 00` | **Confirmed** |
| Sole xref | `get_function_xrefs` → `0057a080` only | **Confirmed** |
| Decompile ≡ raw | live decompile matches raw switch/callees/string | **Confirmed** |

---

## 4. Gaps

- Product/PDB method English for this formatter and for token type enum.
- Official names of vtbl `+0x160` (name getter) and `+0x210` (character gate/self).
- Full C++ types of context / map / character / TokenDesc.
- Intent of case **6** returning 0 after write (bug vs “do not advance token”).
- Runtime / bit-exact / differential.
- Parent walker `FUN_00579fb0` and parser `FUN_00578f80` not dualled here (OWN-ONLY).

---

## 5. Verdict

**accept-with-gaps** — CF, ABI (thiscall + 5 stack + RET 0x14 + AL bool), 7-way case table, faction stub string, dualed race/class helpers, and sole mission-dialog caller sealed; residual is naming + deep types + case-6 product intent + runtime only.
