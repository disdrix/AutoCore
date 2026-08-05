# Review A (reconstruction fidelity): `aa_00556b10` Weather_NfxListFillOrActivate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00556b10` |
| **VA** | `0x00556b10`–`0x00556ce2` exclusive (**466 B**) |
| **Canonical name** | `Weather_NfxListFillOrActivate_Inferred` |
| **Ghidra name** | `FUN_00556b10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-I) |
| **Counterpart** | `reviews/B_aa_00556b10_Weather_NfxListFillOrActivate_Inferred.md` |
| **System** | client weather / NDSpecialFX nfx |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (entry/exit/call sites + `DAT_009ca184`) + callers/callees; sole parent `FUN_005575c0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Clear a GuardedVector out-list, then either resolve weather/TOD script names into `_nfx.xml` resource ids (mode 0) or activate/load weather FX (mode ≠ 0).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00556b10_FUN_00556b10.md` (+ 2026-07-29 W32-I append) |
| Annotated | `docs/reconstruction/raw/aa_00556b10_FUN_00556b10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Weather_NfxListFillOrActivate_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00556b10.cpp` |
| Function record | `docs/reconstruction/functions/aa_00556b10_FUN_00556b10.md` |
| Named record | `docs/reconstruction/functions/aa_00556b10_Weather_NfxListFillOrActivate_Inferred.md` |
| Live | decompile ≡ raw CF; `RET 0xC`; `_nfx.xml` constant; 2 call sites |

---

## 3. Signature (sealed)

```c
// ECX = weather host; stack (outList*, weatherObj*, mode); RET 0xC
void Weather_NfxListFillOrActivate_Inferred(
    void* weatherHost /*ECX*/,
    GuardedVectorHeader* outList,
    void* weatherObj,
    char mode);
```

| Slot | Source | Conf |
|---|---|---|
| weather host | **ECX** (`MOV EDI,ECX`; caller `MOV ECX,ESI`) | **High** |
| outList | stack0 (cleared via `FUN_0043d650`) | **High** |
| weatherObj | stack1 (null early-out) | **High** |
| mode | stack2 | **High** |
| cleanup | `RET 0xC` | **High** |

---

## 4. Control flow (clean ≡ raw)

```
FUN_0043d650(outList, 0)
if weatherObj == 0: return

if mode == 0:
  resolve weather name (weather+0x558 path) → optional append "_nfx.xml"
    → if resource open: resolve id + PushBack_Thiscall
  resolve TOD name (host +0x150 family) → same gate/push
else:
  if FUN_00555600(weather+0x558): FUN_004b88e0(...,1,0,0)
  if TOD index in [0,4) and FUN_00553d20 loads FX: FUN_004b88e0; return
```

| Stage | Match | Conf |
|---|---|---|
| Clear list first | **Yes** | **High** |
| mode 0 / ≠0 split | **Yes** | **High** |
| `_nfx.xml` strstr gate + DAT append | **Yes** (`read_memory` `009ca184`) | **High** |
| PushBack_Thiscall on resolve hit | **Yes** (`0043d670`) | **High** |
| Activate via `004b88e0` / `00553d20` | **Yes** | **High** |
| Caller lists +0x190 / +0x1a4 | **Yes** (2 xrefs) | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry: `81 EC 08 01 00 00 55 8B AC 24 10 01 00 00 56 57 8B F9 6A 00 8B CD … E8 …` — frame 0x108; clear list; save host.  
Exit: `5F 5E 5D 81 C4 08 01 00 00 C2 0C 00 CC` — **`RET 0xC`**.  
`DAT_009ca184`: `5f 6e 66 78 2e 78 6d 6c 00` = `"_nfx.xml"`.

---

## 6. Gaps

- Product English for weather host / list fields.
- Full semantics of unowned `FUN_004b88e0` apply collector.
- `FUN_00989e00` product name.
- Runtime / bit-exact.

---

## 7. Verdict

ABI/mode split/`_nfx.xml`/clear+push sealed. Residuals product English + unowned apply helper → **accept-with-gaps**.
