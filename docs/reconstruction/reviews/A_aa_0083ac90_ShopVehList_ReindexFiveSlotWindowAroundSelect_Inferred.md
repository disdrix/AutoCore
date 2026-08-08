# Review A (reconstruction fidelity): `aa_0083ac90` ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083ac90` |
| **VA** | `0x0083ac90`–`0x0083aeb4` inclusive (**549 B** / `0x225`) |
| **Canonical name** | `ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred` |
| **Ghidra name** | `FUN_0083ac90` |
| **Review date** | `2026-08-05` (WQ9K-H dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9K-H) |
| **Counterpart** | `reviews/B_aa_0083ac90_ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred.md` |
| **System** | shopveh list five-slot window reindex |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory (+ analyze/xrefs/disassemble_function/assembly_context). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Reindex the shopveh list host's five visible slot objects around a new select index. Window = `[select-2, select+2]` mapped into `host+0x50c[0..4]`. Control ids use base **`0x9ca4`**. When occupancy is wrong, swaps two slot objects via dualed `FUN_00833160` (sole CALL @ `0x0083ad72`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9K-H append) | `docs/reconstruction/raw/aa_0083ac90_FUN_0083ac90.md` |
| Annotated | `docs/reconstruction/raw/aa_0083ac90_FUN_0083ac90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0083ac90.cpp` |
| Function record | `docs/reconstruction/functions/aa_0083ac90_ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred.md` |
| Nested swap (dualed) | `aa_00833160` WQ9J-D |
| Live | full disasm listing; entry/exit hex; 4 CALL xrefs |

---

## 3. Signature (sealed)

```c
// EAX = select_index; stack host*; RET 4; void
void ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred(void *host);
```

| Formal | Source | Conf |
|---|---|---|
| select_index | **EAX** (`TEST EAX` / `JL` early; callers `MOV EAX,[…+0x558]` etc.) | **High** |
| host | stack (`MOV EBP,[ESP+0x10]` after `PUSH EBP`) | **High** |
| return | void | **High** |
| cleanup | **`RET 4`** (`C2 04 00`) | **High** |

---

## 4. Control flow (authority)

```text
if select < 0 || select > host.count(+0x4fc): return
host.select(+0x500) = select
for list_i in [select-2 .. select+2]:
  slot = list_i - select + 2
  if in-range and slots[slot]:
    if GetId(slots[slot]) - 0x9ca4 == list_i:
      refresh path (a860 → abf0 | a880(0))
    else:
      scan j≠slot for donor with id encoding list_i
      if donor: ESI=donor EDI=target CALL 00833160; fix ids; a880(0)
      else: abf0
    SetId(slots[slot], list_i + 0x9ca4)
clear leading slots when select < 2
clear trailing slots when (count - select + 2) < 5
```

| Stage | Match | Conf |
|---|---|---|
| Bounds + write +0x500 | disasm `0083ac93`–`0083acb2` | **High** |
| Window loop ±2 / slot map | `LEA EDI,[EAX-2]` … `ADD ECX,2` / `CMP ESI,5` | **High** |
| Id base 0x9ca4 | `SUB EAX,0x9ca4` / `LEA EAX,[EDI+0x9ca4]` | **High** |
| Sole swap call | `CALL 00833160` @ `0083ad72` after ESI/EDI load | **High** |
| Clear id -1 | `PUSH -1; CALL [vtbl+0x74]` | **High** |
| RET 4 | epilogue `C2 04 00` | **High** |

---

## 5. Machine bytes (entry / exit)

Prologue: `83 EC 08 85 C0 55 8B 6C 24 10 0F 8C …`  
Epilogue: `5F 5E 5B 5D 83 C4 08 C2 04 00`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | 4 UNCONDITIONAL_CALL (see function record) |
| Callees | `00833160`, `0083a860`, `0083a880`, `0083abf0`, `00833d50`, vtbl+0x74/0x78 |

---

## 7. Gaps

1. Product demangle for host / slot class.  
2. Full dual of `0083a860` / `0083a880` / `0083abf0` / `00833d50` (not OWN).  
3. Dead `CMP EBX,5` post-swap branch (always false for j&lt;5).  
4. Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path seals ABI, host offsets, five-slot window math, id base, sole-swap-caller role, and clear paths. Residual product English + helper duals → **accept-with-gaps**.
