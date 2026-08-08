# Review A (reconstruction fidelity): `aa_0085ce20` Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085ce20` |
| **VA** | `0x0085ce20`–`0x0085d571` |
| **Canonical name** | `Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` |
| **Prior names** | `FUN_0085ce20`, `Skill_You_do_not_possess_the_Tinkering_skill_to_work_o_0085ce20` |
| **Review date** | `2026-08-04` (WQ8R-H dual seal) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0085ce20_Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Present local craft-mode status text on an item UI widget while `DAT_00d1d900` (`client+0x30c0`) is:

| Mode | Domain |
|-----:|--------|
| 0 | Reverse Engineer eligibility / skill / stack / recipe messages |
| 5 | Gadget attach validation (`CVOGGadget` RTTI + `FUN_00513400` codes) |
| 4 | Tinkering Kit validation (`CVOGTinkeringKit` RTTI + `FUN_00513c10` codes) |
| other | Clear text + cursor path; no final place epilogue |

Not a network inventory transfer unit — UI presenter only.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0085ce20_FUN_0085ce20.md` (+ 2026-08-04 re-verify) |
| Annotated | `docs/reconstruction/raw/aa_0085ce20_FUN_0085ce20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0085ce20.cpp` |
| Live | Ghidra `batch_decompile` + `force_decompile` + `read_memory` 128 B + `get_assembly_context` on 6 xrefs |
| Not performed | `disassemble_bytes`, Launcher, bit-exact, runtime |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EAX→ESI item, EBX widget, cdecl char | **High** | prologue bytes + `ADD ESP,4` callers |
| Mode 0/4/5 product paths | **High** | strings + RTTI |
| Broken bit `+0x17c>>19` | **High** | matches RE/tinker siblings |
| Widget vtbl +0x308 text / +0x314 pos | **High** | all terminal paths |
| `DAT_00d1d900` ≡ client+0x30c0 | **High** | prior seal + usage |
| Helper names FUN_00513400 / 00513c10 English | **Tentative** | unowned |
| strictMode semantics | **Probable** | 0 gates broken+stack; 1 skips |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null gates (char, cursor, item, widget) | Yes |
| Mode switch 0 / 5 / 4 / else | Yes |
| RE string cascade | Yes |
| Gadget RTTI + code messages | Yes |
| Tinker RTTI + code / category sprintf | Yes |
| Place epilogue | Yes (except mode-else early return) |

---

## 5. Gaps

1. Product/PDB names for widget class and vtbl slots.
2. Full contracts of `FUN_00513400`, `FUN_00513c10`, `FUN_00522950`, `FUN_0052e640` (unowned).
3. Exact buffer sizes / STOSD zeroing widths (decompiler local aliases).
4. Runtime confirmation of hover vs refresh `strictMode` UX.
5. Bit-for-bit / differential.

**Verdict:** **accept-with-gaps**
