# Review A (reconstruction fidelity): `aa_0052e640` Character_ComputeReverseEngineerSuccessFraction_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052e640` |
| **VA** | `0x0052e640`–`0x0052eb76` inclusive (**1335 B** / `0x537`) |
| **Canonical name** | `Character_ComputeReverseEngineerSuccessFraction_Inferred` |
| **Ghidra name** | `FUN_0052e640` |
| **Prior scaffold** | `Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_0052e640` (**retired**) |
| **Rejected misname** | `UI_ItemHover_ApplyTooltipText` (partition **hint** = parent `0x0085ce20`, not this VA) |
| **Review date** | `2026-08-05` (MEGA-117 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0052e640_Character_ComputeReverseEngineerSuccessFraction_Inferred.md` |
| **System** | `inventory-transfer` (Reverse Engineer client skill math) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `analyze_function_complete` + `get_function_callers` / `callees` + `get_xrefs_to` + `read_memory` + `batch_decompile` helpers. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Compute a **client-side Reverse Engineer success fraction** for `(character, item)`:

```text
score = Character_ComputeReverseEngineerSuccessFraction(character, item)
// 0.0  → UI "Requires At Least N Reverse Engineering" (via twin 0052e1d0 for N)
// >0   → RE allowed; overlay prints "%.01f%%" after score*100 clamp 100
// 1.0  → free path (character+0x6b4 >= 1)
// 100  → zero primary material cost (displays 100% after *100+clamp)
// cap  → 0.95 on formula path
```

Not a tooltip presenter — parent dualed `Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` (`0x0085ce20`) **consumes** this float in mode 0.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF (gates / cost loops / score switch / cap) |
| Full body | `disassemble_function` 408 lines; body end `RET 4` @ `0x0052eb74` (`C2 04 00`) |
| Prologue | `SUB ESP,A8`; `MOV ESI,[ESP+B4]`; `MOV EDI,ECX` |
| Constants | `read_memory` 4 B LE on all score floats (3.5 / 1.0 / 0 / 100 / 2.5 / 2.0 / 1.5 / 0.5 / 0.01 / 0.95) |
| Callers | `FUN_0085ce20` @ `0085ce6c`; `FUN_0084b890` @ `0084ba78`; orphan @ `0085d7df` |
| Consumer proof | `0084b890`: `score * 100`, clamp 100, `sprintf("%.01f%% %s")` |
| Twin level | `FUN_0052e1d0` required-level integer (not dualled here) |
| Dualed deps | `ItemDef_CountConfiguredModSlots_Inferred` (`00599dd0`); `GameData_LookupCloneBaseByCbid` (`00404d70`); `CVOGLootGenerator_GetOrCreate` (`004ce940`) |

---

## 3. Signature (sealed)

```c
// ECX=character*; stack item*; ST0=float fraction; RET 4
float __thiscall Character_ComputeReverseEngineerSuccessFraction_Inferred(
    void* character,
    void* item);
```

| Formal | Source | Conf |
|---|---|---|
| character (this) | ECX → EDI | **Confirmed** (prologue) |
| item | stack `[ESP+4]` → ESI | **Confirmed** (`MOV ESI,[ESP+0xB4]` after `SUB ESP,A8`+pushes) |
| return | ST0 (`FLD` / `float10`) | **Confirmed** (all exits `FLD` then `RET 4`) |
| cleanup | `RET 4` (`C2 04 00`) | **Confirmed** (early + final) |
| call sites | `PUSH item; MOV ECX,char; CALL; FSTP` | **Confirmed** @ `0085ce6c` / `0084ba78` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Null item / null lootgen / slots≤0 → 0 | Yes | **Confirmed** |
| `character+0x6b4 >= 1` → 1.0 | Yes (`CMP [EDI+0x6b4],1` / `JL` else `FLD 1.0`) | **Confirmed** |
| `FUN_00522950` false → 0 | Yes | **Confirmed** |
| Primary cost loop over def `+0x498` slots | Yes; **int** CBID ≠ −1 (asm `CMP EDI,-1`) | **Confirmed** |
| Type `0x1a` material rank `+0x4c8` | Yes | **Confirmed** |
| Budget `floor(skill_byte(+0x598)*3.5)` | Yes | **Confirmed** |
| Secondary vtbl+0x60/+0x5c + `005097b0` | Yes | **Confirmed** |
| Zero primary cost → 100.0 | Yes (`FLD [00aaa7ac]`) | **Confirmed** |
| Tier switch bases 50/50/40/30/20/10 ×0.01 | Yes (jump table `0x0052eb78`) | **Confirmed** |
| Cap 0.95 | Yes (`COMISS` vs `[00aaa6b8]`) | **Confirmed** |

Decompiler artifact corrected in annotated/clean: CBID slots are **uint32**, not `float`/`-NAN`.

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Consumer `%.01f%%` percentage UI | **Yes** (`FUN_0084b890`) |
| Parent RE mode-0 "Requires At Least … Reverse Engineering" when score≤0 | **Yes** (dualed `0085ce20`) |
| Skill byte + tier capacity twin `00520520` / required-level twin `0052e1d0` | **Yes** |
| PDB / RTTI product method name | **No** → keep **`_Inferred`** |
| Partition hint equals this VA | **No** — hint names parent tooltip |

**Name accepted:** `Character_ComputeReverseEngineerSuccessFraction_Inferred`.

---

## 6. Gaps

1. Product English for skill field `+0x598` and free flag `+0x6b4`.
2. Material rank byte `+0x4c8` product name (tier/quality).
3. Dual of sibling `0x0052e1d0` (required level) and helpers `00522950` / `00520520` / `005097b0` (unowned).
4. Orphan call site `0x0085d7df` (no owning function between `0085ce20` end and `0085d900`).
5. Whether fraction drives server RNG or is display-only (client sealed only).
6. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
