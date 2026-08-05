# Reconstruction review: `aa_00571620` InventoryGrid_PlaceItemFootprint

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571620` |
| **VA** | `0x00571620` |
| **Canonical name** | `InventoryGrid_PlaceItemFootprint` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role |
|---|---|---|
| Raw | `raw/aa_00571620_InventoryGrid_PlaceItemFootprint.md` | Authoritative decompile (`FUN_00571620`) |
| Annotated | `…annotated.md` | Scaffold copy |
| Exact C++ | `reconstructed-exact/InventoryGrid_PlaceItemFootprint.cpp` | Clean still named `FUN_00571620` |
| Function record | `functions/aa_00571620_….md` | Status |
| System map / wire RE | inventory-transfer; inventory-cargo-wire-re | Multi-cell COID stamp narrative |
| Related | FindFreeSlot, AllocateCellArray units | Cell size 8 / empty -1 / occupancy |

**Primary claims under review:**

1. Reject certain item class ids at clonebase `+0x38` (0x12/14/16/36/38/3a)
2. Special class `4`: light attach path, return 1 without grid stamp loop
3. Normal path: footprint dims from clonebase `+0x406/+0x407`; store-type grid forces min 2×2 if zero
4. `FUN_00570840` can-place gate; fail → 0
5. Item setup vcalls; optional render scale path when flag bit 6
6. Nested loop stamps COID halves `param_2[0x58]/[0x59]` into cells at `grid+0x28` with stride `grid+0xc`
7. Post: `FUN_00566f00`, set item flag `\|0x10`, helpers, return 1

**Not re-authored.** Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw pseudocode | Raw | Full body |
| Clean C++ | reconstructed-exact | Fidelity |
| Wire RE / system map | docs | Multi-cell stamp interpretation |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Class reject list | **Yes** |
| Class 4 early path | **Yes** |
| Dim load `+0x406/+0x407` | **Yes** |
| Type==4 min dims | **Yes** |
| CanPlace `FUN_00570840` | **Yes** |
| Vcall sequence + flag bit6 | **Yes** |
| Nested stamp loop structure | **Yes** |
| Flag `\|0x10` + post helpers | **Yes** |

### 3.2 Naming surface

Canonical file name is `InventoryGrid_PlaceItemFootprint.cpp` but exported symbol remains `FUN_00571620` — matches raw symbol, not modernized rename inside the function identifier. Acceptable scaffold fidelity.

### 3.3 Cell write shape

Each iteration writes two dwords at `cellBase + index*8` and `+4` from `param_2[0x58]` / `[0x59]` — consistent with 8-byte COID pair cells used by allocate/find units.

### 3.4 Function record honesty

Partial scaffold — appropriate given decompiler `unaff_*` residuals.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| `unaff_SI`, `unaff_retaddr`, `bStack_8` | **High (semantic)** | Decompiler failed to bind true parameters (likely height/X origin / size args). Clean preserves unaff — **faithful to raw, not a correct finished port** |
| Index expression `height * (local_c + iVar4) + …` | **High** | Looks corrupted relative to a normal rect stamp (`y*width+x` or `height*x+y`). Clean mirrors raw (correct review outcome: do not “fix” without asm) |
| Inner loop overwrites `uVar8 = uVar9` (`grid+0x24`) | Suspicious | May be decompiler var reuse artifact |
| Annotated empty | Meta | Should document unaff risks |

**No clean-vs-raw edit required** for scaffold acceptance; **needs human refine** for any production port (tracked as gap, not “needs-revision” fidelity fail).

---

## 5. What remains uncertain

1. True parameter list (grid, item, x, y, …) beyond thiscall `param_1/2/3/4`.
2. Correct footprint loop bounds (which register is InvSizeX vs Y vs origin).
3. Meaning of class 4 special path.
4. Identity of rejected class ids.
5. Whether index formula in decompile is retail-correct.
6. Runtime multi-cell stamp observation.
7. Live re-decompile / asm not done.

---

## 6. Verdict

### **accept-with-gaps**

Clean faithfully reproduces the decompiler body, including its dangerous `unaff_*` residues. That is correct for a scaffold layer. It is **not** a sealed, production-ready place algorithm — gaps are severe for porting but are honesty gaps, not clean/raw drift.

**Not reject:** clean matches raw.  
**Not needs-revision (fidelity):** rewriting loop without asm would be invention.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| COID pair cell writes preserved | **Pass** |
| CanPlace gate preserved | **Pass** |
| No silent “fix” of unaff vars | **Pass** |
| Algorithm production-ready | **Open / No** |
| Verdict | **accept-with-gaps** |
