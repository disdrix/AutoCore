# Review B (skeptical / adversarial): `aa_005792d0` Mission_FormatDialogTokenValue_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005792d0` |
| **VA** | `0x005792d0` |
| **Canonical name** | `Mission_FormatDialogTokenValue_Inferred` (**Inferred**) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_005792d0_Mission_FormatDialogTokenValue_Inferred.md` |
| **System** | missions-progression / mission dialog token format |
| **Live tools** | Independent decompile + `read_memory` + caller site + dualed callee plates |
| **Verdict** | **accept-with-gaps** — accept CF/ABI/case table/sole caller; reject void/cdecl/multi-caller/scaffold-product/case-6-success claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Ghidra signature `void` / no useful return | **Falsified** — epilogues set **`AL=1`** (`B0 01`) or **`AL=0`** (`32 C0`) before `RET 0x14` |
| 2 | cdecl / no register this | **Falsified** — entry `MOV EDI,ECX`; case 0 uses `EDI+0x30` TFID; thiscall sealed |
| 3 | Fewer/more than 5 stack args | **Falsified** — all success/fail paths `RET 0x14` (20 bytes = 5 dwords) |
| 4 | `unaff_EBX` / `unaff_retaddr` are extra out buffers | **Falsified** — strcpy targets load `[ESP+0x10]` (outBuf after 3 pushes); register noise only |
| 5 | `param_5` is always float | **Falsified** — cases 1–3 treat slot as **object pointer**; float only in case 0 |
| 6 | Case 6 returns 1 on class write | **Falsified** — machine `XOR AL,AL` after strcpy |
| 7 | Scaffold `Named_CalleeOf_…Mission_Dialog_has_005792d0` is product name | **Rejected** — parent-seed chain name, not plate |
| 8 | Scaffold `Named_Non_Character_Faction_not_implemented_yet` is product method | **Rejected** — evidence **string** only; method is multi-case formatter |
| 9 | Multiple independent callers | **Falsified** — single `UNCONDITIONAL_CALL` from `FUN_00579fb0` |
| 10 | Same as `Mission_ExpandPlayerTokenPlaceholders` (`0x005465c0`) | **Falsified** — that unit is fixed `[$name]/[$class]/…` replace-all; this is typed token-desc switch used by dialog walker |
| 11 | Runtime / terminal Confirmed | **Rejected** — no Launcher; Terminal false |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 7-way type switch + jump table | **High** | Wrong token expansion |
| ABI thiscall + 5 stack + RET 0x14 + AL bool | **High** | Stack smash / wrong return on port |
| Case 0 float/var + sprintf | **High** | Wrong numeric tokens |
| Cases 2/3 dualed race/class helpers | **High** | Wrong English labels |
| Case 4 faction stub string | **High** | Missing fallback text |
| Case 6 returns 0 after write | **High** (bytes) | Parent may re-wrap token |
| Product method English | **None** | Overclaim name |
| vtbl +0x160 / +0x210 official names | **Low** | Wrong character API on port |
| TokenDesc full layout beyond +0/+4/+8 | **Medium** | Adjacent field misuse |

---

## 3. Decompiler pitfalls (must survive port)

1. Do **not** treat return as void — port as **`uint8`/`bool` in AL**.
2. Do **not** drop **ECX context** — TFID at `this+0x30` is load-bearing for case 0.
3. Do **not** trust `unaff_EBX` / `unaff_retaddr` as distinct destinations — single out buffer.
4. Do **not** type stack arg 4 as pure `float` — dual-use object*/float slot.
5. Do **not** “fix” case 6 to return 1 — bytes return **0** after write.
6. Pushes of `-1` before/around race/class calls belong to **`FUN_007a6de0`** ring length, not as args to the display-name helpers (those are ECX-this, plain RET).
7. Scaffold Mission_Dialog / Faction string aliases — **ignore as product symbols**.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Per-token mission-dialog value formatter | Official PDB `FormatDialogToken…` symbol |
| Types 0..6 behaviors above (structural) | Product enum names for each type |
| Sole caller `FUN_00579fb0` | Multi-caller / general UI |
| thiscall + RET 0x14 + AL bool | cdecl / void / strlen return |
| Dualed race/class helper linkage | Full Character C++ type |
| `_Inferred` structural name | Confirmed product method English |
| Case 6 write-then-fail (bytes) | Why designers wanted that |

---

## 5. CF challenge of Review A

- Body bounds + jump table + pad: **agree Confirmed**
- ABI thiscall + 5 stack + AL bool: **agree Confirmed**
- Case table 0–6 structural roles: **agree Confirmed** (product labels Inferred)
- Sole caller mission-dialog walker: **agree Confirmed**
- accept-with-gaps (not bare accept): **agree** — product English + vtbl names + case-6 intent residual is real

**Verdict:** **accept-with-gaps**
