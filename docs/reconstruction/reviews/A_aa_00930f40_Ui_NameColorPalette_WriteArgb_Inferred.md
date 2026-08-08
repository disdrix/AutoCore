# Review A (reconstruction fidelity): `aa_00930f40` Ui_NameColorPalette_WriteArgb_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00930f40` |
| **VA** | `0x00930f40`–`0x00930f9c` (+ JT `@0x00930fa0`) |
| **Canonical name (Ghidra)** | `FUN_00930f40` |
| **Proposed name** | `Ui_NameColorPalette_WriteArgb_Inferred` |
| **Review date** | `2026-08-04` (WQ9E-C OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00930f40_Ui_NameColorPalette_WriteArgb_Inferred.md` |
| **System** | client UI / entity name-label color |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf **fixed-mode ARGB palette writer** for entity name/label colors. Not the full resolver (`Ui_ResolveEntityNameColor_Inferred`), not level-band tables (`Ui_NameColorLevelBand_CopyFloat4_Inferred`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x00930f40` |
| Bytes | `read_memory` 128 B @ entry (switch + JT + `CC`) |
| Meta | body `00930f40`–`00930f9c` (**92 B**); JT 5 dwords @ `00930fa0` |
| Callers | sole: `FUN_00930fc0` (6 sites) |
| Parent dual | `aa_00930fc0` Ui_ResolveEntityNameColor_Inferred |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_00930f40` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers.

---

## 3. Signature

```c
uint32_t* Ui_NameColorPalette_WriteArgb_Inferred(int mode /*ECX*/, uint8_t* out /*EAX*/);
// bare ret; EAX = out
```

| Item | Evidence |
|---|---|
| Mode ECX | `add ecx,1` / call-site `mov ecx,imm` |
| Out EAX | byte stores `[eax]`; caller `mov r32,[eax]` |
| Leaf | no CALL |
| Colors | immediates in `mov byte` / decompile cases |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| mode+1 jump table / ja default | Yes |
| case 0 red `0xFFC41616` | Yes |
| default beige `0xFFDCE0C8` | Yes |
| case 2 cyan `0xFF66D3EA` | Yes |
| case 3 green `0xFF14D314` | Yes |
| case −1 white `0xFFFFFFFF` | Yes |
| BGRA channel order | Yes |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Palette writer role | **High** | sole parent is name-color resolver |
| Five ARGB values | **High** | bytes + decompile |
| ABI ECX/EAX / bare ret | **High** | call sites + prologue |
| Product English name | **Tentative** | `_Inferred` |
| Mode product labels (hostile/ally…) | **Open** | colors only |

---

## 6. Gaps / open

1. Product/PDB symbol.  
2. Semantic English for modes 0..3 / −1.  
3. White mode unused by current xrefs.  
4. Runtime / bit-exact.

**Verdict:** **accept** — CF/ABI/colors High; product English Inferred.
