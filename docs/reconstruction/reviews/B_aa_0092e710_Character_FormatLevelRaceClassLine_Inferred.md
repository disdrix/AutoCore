# Review B (skeptical / adversarial): `aa_0092e710` Character_FormatLevelRaceClassLine_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092e710` |
| **VA** | `0x0092e710` |
| **Canonical name** | `Character_FormatLevelRaceClassLine_Inferred` (**Inferred**) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0092e710_Character_FormatLevelRaceClassLine_Inferred.md` |
| **System** | missions-progression / character display UI |
| **Live tools** | Independent decompile + `read_memory` + caller site + dualed callee plates |
| **Verdict** | **accept-with-gaps** — accept CF/ABI/line shape/sole caller; reject void/thiscall-only/ring-return/scaffold-product claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Ghidra signature `void` / no useful return | **Falsified** — epilogue returns **strlen** in EAX; fail path `xor eax,eax` |
| 2 | Single stack formal only; EBX is noise (`unaff_EBX`) | **Falsified** — call site `LEA EBX, local_108`; null-test `TEST EBX,EBX` |
| 3 | `__thiscall` / ECX = character | **Falsified** — stack push of player + `ADD ESP,4`; ECX used for TLS/`this` of callees only |
| 4 | Returns TLS ring `char*` like race/class helpers | **Falsified** — writes **caller buffer**; returns **length** |
| 5 | Formats level only | **Falsified** — also race (`00521800`) + class (`00521900`) with space seps |
| 6 | `FUN_00521800(0xffffffff)` means race helper takes `-1` | **Falsified** — dualed race helper is **ECX-this**, plain RET; `-1` is ring-copy length for `007a6de0` |
| 7 | Scaffold `Named_CalleeOf_Skill_Combat_…` is product name | **Rejected** — parent-seed from skill tooltip strings in same UI refresh, not this leaf |
| 8 | Multiple independent callers | **Falsified** — single UNCONDITIONAL_CALL from `FUN_008f97c0` |
| 9 | Mission-journal only / `[$race]` path | **Falsified** — character-sheet widget set-text (`vtbl+0x1d8` on `this[0x520]`) |
| 10 | Runtime / terminal Confirmed | **Rejected** — no Launcher; Terminal false |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Output line shape `Level n Race Class` | **High** | Wrong character-sheet header text |
| ABI stack char* + EBX out + strlen | **High** | Buffer/register corruption on port |
| `"Level "` + space constants | **High** | Misread literals |
| Dualed race/class helper linkage | **High** | Wrong display names |
| vtbl+0x27c is *level* | **High** (role) | Wrong number in line |
| Product method English | **None** | Overclaim symbol |
| Full Character C++ type | **Low** | Offset port errors outside this leaf |

---

## 3. Decompiler pitfalls (must survive port)

1. Do **not** treat return as void — port as **`int` strlen**.
2. Do **not** drop **EBX out-buffer** — decompiler `unaff_EBX` is real ABI.
3. Do **not** invent `FUN_00521800(-1)` stack arg — race/class are **ECX-this**.
4. Pushes of `-1` before ring copy belong to **`FUN_007a6de0`**, not the race/class helpers.
5. Scaffold Skill_Combat alias — **ignore**.
6. Append pattern is **strcpy-to-end** (find NUL, dword copy); not `sprintf` of the whole line.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Line = Level + n + Race + Class | Official PDB `FormatLevel…` symbol |
| Sole UI caller `FUN_008f97c0` | Mission-only / multi-caller |
| cdecl stack character* + EBX buf | Pure thiscall |
| strlen return / 0 on null | Ring `char*` return |
| `_Inferred` structural name | Confirmed product method English |

---

## 5. CF challenge of Review A

- Body bounds + pad: **agree Confirmed**
- `"Level "` VA + space sep + itoa radix 10: **agree Confirmed**
- ABI stack + EBX + strlen: **agree Confirmed**
- Sole caller character-sheet: **agree Confirmed**
- accept-with-gaps (not bare accept): **agree** — product English + vtbl method name residual is real

**Verdict:** **accept-with-gaps**
